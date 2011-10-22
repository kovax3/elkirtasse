/****************************************************************************/
// 
// #
// All rights reserved.
// Contact: abouzakaria (yahia67@live.com)
// 
//   elkirtasse Copyright (C) 2010  yahia abouzakaria  <yahiaui@gmail.com>
// 
//      This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
//      This is free software, and you are welcome to redistribute it
//      under certain conditions; type `show c' for details.
//  
//  The hypothetical commands `show w' and `show c' should show the appropriate
//  parts of the General Public License.  Of course, your program's commands
//  might be different; for a GUI interface, you would use an "about box".
//  
//    You should also get your employer (if you work as a programmer) or school,
//  if any, to sign a "copyright disclaimer" for the program, if necessary.
//  For more information on this, and how to apply and follow the GNU GPL, see
//  <http://www.gnu.org/licenses/>.
//  
//    The GNU General Public License does not permit incorporating your program
//  into proprietary programs.  If your program is a subroutine library, you
//  may consider it more useful to permit linking proprietary applications with
//  the library.  If this is what you want to do, use the GNU Lesser General
//  Public License instead of this License.  But first, please read
//  <http://www.gnu.org/philosophy/why-not-lgpl.html>.
// ----------------------------------------------------------
//If you have questions regarding the use of this file, please contact
// abouzakaria (yahia67@live.com)
// $elkirtasse_END_LICENSE$
/****************************************************************************/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include  "dialog.h"
#include  "about.h"
#include  "dialogfind.h"
#include  "dialogconvert.h"
#include  "dialogupdat.h"
#include  "dialogfavo.h"
#ifdef   Q_WS_WIN
#include  "dialogmdb.h"
#else
#include  "mdbexport.h"
#endif
#include  "dialoggoto.h"
#include  "dialogoption.h"
#include  "print.h"

//تحميل البرنامج
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    Messages = new messages();
    Findbook=new findbook();
    DataBook=new databook();
    Rowat=new rowat();
#if QT_VERSION >= 0x040600
    view= new View(this);
#endif

    m_pathUser=QDir::homePath()+"/.kirtasse";
    m_pathApp=QApplication::applicationDirPath();
    m_currentIndex=0;
    for(int r=0;r<10;++r)
    {
        m_isTefsir[r]=false;
        m_treeFahrasIsModified[r]=false;
        m_bookIsModified[r]=false;
        m_toolEditFahrass[r]=false;
    }

    m_treeGroupIsModified=false;
    
    ui->lineEdit->setVisible(false);
    m_listTab.append("0");
    m_findIsTitle=true;
    txtBrowserBook = ui->tabWidget->currentWidget()->findChild<QTextBrowser *>();
    //*****
    // Create a "new tab" button
    QToolButton * newButton = new QToolButton( this );
    newButton->setCursor( Qt::ArrowCursor );
    newButton->setAutoRaise( true );
    newButton->setIcon( QIcon( ":/images/image/tab-new.png" ) );
    newButton->setToolTip(trUtf8("لسان جديد") );
    connect( newButton, SIGNAL( clicked() ), this, SLOT( tabCreatTabNew() ) );

    // Put it there
    ui->tabWidget->setCornerWidget( newButton, Qt::TopLeftCorner );
    //***********
    updateIconEndAction();
    tabCreatFahrass();
    //تحميل ملف السمة وبيانات الطول و العرض ووو
    //**********************عمليات التحميل*******
    loadLayout();
    //   Messages->m_pathCostum=m_pathCostm;
    Messages->favorite_charge(ui->treeWidget_fav,m_icondir,m_icondfile);
    Messages->treeChargeJozaa(ui->treeWidget_curaan);       //تحميل اجزاء القرءان
    Messages->recentCharge();               //تحميل قائمة الكتب السابقة
    chargeGroupe();
    emit bookAvailable(false);
    on_actionPageIntro_triggered();

}
//عند خروج البرنامج
MainWindow::~MainWindow()
{
    Messages->recentSave(); //حفظ الكتب السابقة
    if(!this->isFullScreen()){
        saveLayou();
    }

    Messages->favorite_save(ui->treeWidget_fav);
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *e)
{
    Findbook ->stopFind=true;
    if (m_treeGroupIsModified==true){
        int reponse = QMessageBox::warning(this, trUtf8("تنبيه"), trUtf8("هل تريد حفظ التغييرات المدخلة على مجموعة الكتب ") ,QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (reponse == QMessageBox::Save){
            if ( Messages->treeSaveGroupe(ui->treeWidget_books)){
                QMessageBox::information(this,trUtf8("معلومات"), trUtf8("تمت عملية حفظ مجموعة الكتب بنجاح"));
                m_treeGroupIsModified=false;
            }
        }else if (reponse == QMessageBox::Cancel){
            e->ignore();
            return;
        }
    }

    int  tabcount=ui->tabWidget->count();
    //حفظ السمة والبيانات عند الخروج
    for(int r=0;r<tabcount;++r)
    {
        QTextBrowser *txtBrowser = ui->tabWidget->widget(r)->findChild<QTextBrowser *>();
        QString name=txtBrowser->objectName();
        QString  str = name.section('_', -1);
        QVariant indx=str;
        if (!m_bookName[indx.toInt()].isEmpty()){                              //حفظ قائمة الكتب السابقة
            if(txtBrowser->document()->isModified()){
                DataBook->boocNumIndex=indx.toInt();
                DataBook->updatPage("",txtBrowser->document()->toPlainText(),true);
                m_bookIsModified[indx.toInt()]=true;
            }
            if (closeMessages(m_bookTitle[indx.toInt()],indx.toInt())==false){
                e->ignore();
                return;
            }
            QVariant idbk=DataBook->currentPosition[indx.toInt()];
            Messages->recentChange(m_bookName[indx.toInt()],m_bookTitle[indx.toInt()],m_bookAuthor[indx.toInt()],idbk.toString(),m_recentNbr,m_isTefsir[indx.toInt()]);
        }
    }
    e->accept();
}
bool MainWindow::closeMessages(QString title,int index)
{
    if (m_treeFahrasIsModified[index]==true){
        int reponse = QMessageBox::warning(this, trUtf8("تنبيه"), trUtf8("هل تريد حفظ فهرسة : ") +title, QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (reponse == QMessageBox::Save){
            saveFahrass(index);


        }else if (reponse == QMessageBox::Cancel){

            return false;
        }
    }
    if (m_bookIsModified[index]==true){
        int reponse = QMessageBox::warning(this, trUtf8("تنبيه"), trUtf8("هل تريد حفظ التغييرات على كتاب : ")+title+ " ؟" , QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (reponse == QMessageBox::Save){
            saveCurrentBook(index);

        }else if (reponse == QMessageBox::Cancel){
            return false;
        }
    }
    return true;
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
 {

int b=listLineEditName.indexOf(obj->objectName());

     if (obj->objectName() == listLineEditName.at(b)) {

         if (event->type() == QEvent::FocusIn && obj->property("text")==trUtf8("بحث")) {
             obj->setProperty("text","");
             obj->setProperty("styleSheet","");
             return true;
         }else if (event->type() == QEvent::FocusOut && obj->property("text").toString().isEmpty()){
               obj->setProperty("text",trUtf8("بحث"));
               obj->setProperty("styleSheet","QLineEdit {font: italic;color: rgb(115, 115, 115);}");
               return true;
         }

     }
 return QMainWindow::eventFilter(obj, event);
 }
void MainWindow::updateIconEndAction()
{


    //*******************menu tool**************
    ui->menuDockTooBar->addAction(ui->dockWidget_books->toggleViewAction());
    ui->dockWidget_books->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+b")));
    ui->menuDockTooBar->addAction(ui->dockWidget_curaan->toggleViewAction());
    ui->dockWidget_curaan->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+c")));
    ui->menuDockTooBar->addAction(ui->dockWidget_fahras->toggleViewAction());
    ui->dockWidget_fahras->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+l")));
    ui->menuDockTooBar->addAction(ui->dockWidget_favorite->toggleViewAction());
    ui->dockWidget_favorite->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+v")));
    ui->menuDockTooBar->addAction(ui->dockWidget_find->toggleViewAction());
    ui->dockWidget_find->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+f")));
    ui->menuDockTooBar->addSeparator();
    ui->menuDockTooBar->addAction(ui->mainToolBar->toggleViewAction());
    ui->mainToolBar->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+t")));
    ui->menuDockTooBar->addAction(ui->toolBar_navegator->toggleViewAction());
    ui->toolBar_navegator->toggleViewAction()->setShortcut(QKeySequence(tr("Ctrl+Shift+n")));
    //*******************icons******************
    m_icondir=style()->standardIcon(QStyle::SP_DirIcon);
    m_icondfile=style()->standardIcon(QStyle::SP_FileIcon);
    m_iconGroup.addPixmap(QPixmap(QString::fromUtf8(":/images/image/groupb.png")), QIcon::Normal, QIcon::Off);
    QIcon iconRen(QPixmap(QString::fromUtf8(":/images/image/edit-rename.png")));
    m_iconbook.addPixmap(QPixmap(QString::fromUtf8(":/images/image/FIN_book.png")), QIcon::Normal, QIcon::Off);
    m_iconaut.addPixmap(QPixmap(QString::fromUtf8(":/images/image/edit-find-user.png")), QIcon::Normal, QIcon::Off);
    QIcon iconGo(QPixmap(QString::fromUtf8(":/images/image/arrow-left.png")));
    QIcon iconUndo(QPixmap(QString::fromUtf8(":/images/image/undo-back.png")));
    QIcon iconRedo(QPixmap(QString::fromUtf8(":/images/image/undo-next.png")));
    ui->btnRowaInfo->setIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    //********انشاء شجرة البحوث*************
    ui->treeWidget_books->setColumnHidden(2,true);
    ui->treeWidget_books->setColumnWidth(0,200);
    ui->treeWidget_books->header()->setVisible(true);
    ui->  treeWidget_fav->setColumnWidth(0,300);
    ui->treeWidget_fav->header()->setVisible(true);
    //******اضافات الى شريط المعلومات*******
//    BtnStopFind=new QPushButton(style()->standardIcon(QStyle::SP_MediaStop), trUtf8("توقيف البحث"), this);
//    BtnStopFind->setToolTip(trUtf8("توقيف عملية البحث"));
//    BtnStopFind->setFlat(true);
// //   BtnStopFind->setMaximumWidth(25);
//    ui->statusBar->addWidget(BtnStopFind);
   ui->action_stopFind->setVisible(false);
   ui->action_stopFind->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
      ui->action_stopFind->setIconText( trUtf8("توقيف البحث"));
    connect(ui->action_stopFind, SIGNAL(triggered()), this, SLOT(stopFind()));
    labelProgress=new QLabel;
    ui->statusBar->addWidget(labelProgress);
    progressBarFind=new QProgressBar();
    labelProgressImg=new QLabel;
    ui->statusBar->addWidget(labelProgressImg);
    ui->statusBar->addWidget(progressBarFind);

    labelProgressInfo=new QLabel;
    ui->statusBar->addWidget(labelProgressInfo);
    labelProgress->setVisible(false);
    labelProgressImg->setVisible(false);
  //  BtnStopFind->setVisible(false);
    progressBarFind->setVisible(false);
    ui->frameEdit->setVisible(false);
    ui->pushButtonEditClose->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
    ui->actionBookInfo->setIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    //************favotite شريط ادوات المفضلة**********
    QLineEdit *lineEditFindFavo = new QLineEdit(this) ;
    lineEditFindFavo->setMaximumWidth(200);
    ui->toolBarFavo->insertWidget(ui->actionFavSave,lineEditFindFavo);
    ui->toolBarFavo->insertSeparator(ui->actionFavSave);
    ui->actionFavItemDown->setIcon(style()->standardIcon(QStyle::SP_ArrowDown));
    ui->actionFavItemUp->setIcon(style()->standardIcon(QStyle::SP_ArrowUp));
    ui->horizontalLayoutFavo->addWidget(ui->toolBarFavo);
    //*******شريط ادوات شجرة نتائج البحث
    ui->actionFindItemDown->setIcon(style()->standardIcon(QStyle::SP_ArrowDown));
    ui->actionFindItemUp->setIcon(style()->standardIcon(QStyle::SP_ArrowUp));
    ui->actionFindLoad->setIcon(style()->standardIcon(QStyle::SP_DirOpenIcon));
    labelTextFind=new QLabel();
    ui->toolBarFind->insertWidget(ui->actionFindItemUp,labelTextFind);
    ui->toolBarFind->insertSeparator(ui->actionFindItemUp);
    ui->  horizontalLayoutFind->addWidget(ui->toolBarFind);
    //******* اضافة القوائم الى شجرة الكتب menu************
    AC_bookOpenInNewTab=new QAction(style()->standardIcon(QStyle::SP_FileDialogNewFolder),trUtf8("فتح في لسان جديد"), this);
    AC_bookOpen = new QAction(style()->standardIcon(QStyle::SP_DirOpenIcon),trUtf8("فتح الكتاب المحدد"), this);
    AC_bookRemove = new QAction(style()->standardIcon(QStyle::SP_DialogCancelButton),trUtf8("حذف الكتاب المحدد"), this);
    AC_bookUpdat= new QAction(trUtf8("تحرير بيانات الكتاب المحدد"), this);
    AC_bookPath= new QAction(trUtf8("مسار الكتاب المحدد"), this);
    AC_bookRename= new QAction(trUtf8("اعادة تسمية دليل الكتاب"), this);
    AC_groupeRemove = new QAction(style()->standardIcon(QStyle::SP_DialogCancelButton),trUtf8("حذف العنصر المحدد"), this);
    AC_groupeAdd = new QAction(style()->standardIcon(QStyle::SP_FileDialogNewFolder),trUtf8("إظافة مجموعةالى القسم المحدد"), this);
    AC_categorieAdd = new QAction(style()->standardIcon(QStyle::SP_FileDialogNewFolder),trUtf8("إظافة قسم جديد"), this);
    AC_groupeRename= new QAction(iconRen,trUtf8("اعادة تسمية العنصر المحدد"), this);
    //****اضافات الى شريط الادواتت المؤثرات toolbar****
    labelAnim=new QLabel(ui->toolBarAnim);
    labelAnim->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->toolBarAnim->addSeparator();
    ui->toolBarAnim->addWidget(labelAnim);
    ui->frame_5->layout()->addWidget(ui->toolBarAnim);
    //*******شريط ادوات الرئيسي
    lineEditSearchInDoc=new QLineEdit(this);
    AC_GoSearchInDoc=new QAction(iconGo,trUtf8("البحث في الصفحة"), this);
    AC_GoSearchInCurBook=new QAction(m_iconbook,trUtf8("البحث في الكتاب الحالي"), this);
    ui->mainToolBar->addWidget(lineEditSearchInDoc);
    ui->mainToolBar->addAction(AC_GoSearchInDoc);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(AC_GoSearchInCurBook);
    //**القوائم المنسدلة للكتب السابقة combobox recent**
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),this, SLOT(openRecentFile()));
        ui->menuRecent->addAction(recentFileActs[i]);
        Messages->recentFileActs[i]=recentFileActs[i];
    }
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->menuRecent->menuAction());
    //**********شريط ادوات التنقل بين الصفحات
    labelPagePart = new QLabel("");
    ui->toolBar_navegator->addWidget(labelPagePart);
    AC_nextHistorie= new QAction(iconRedo,trUtf8("التنقل التالي"), this);
    AC_prevHistorie=new QAction(iconUndo,trUtf8("التنقل السابق"), this);
    AC_prevHistorie->setEnabled(false);
    AC_nextHistorie->setEnabled(false);
    ui->toolBar_navegator->addAction(AC_prevHistorie);
    ui->toolBar_navegator->addAction(AC_nextHistorie);
    //***********************الممؤثرات الحركيةanimation*****************************
    labelBetaka=new QLabel();
    labelBetaka->setLayoutDirection(Qt::RightToLeft);
    labelBetaka->setPixmap(QPixmap(QString::fromUtf8(":/images/image/groupbook.png")));
    m_scene.addWidget(labelBetaka);
    m_scene.setBackgroundBrush(labelBetaka->palette().base());
    labelBetaka->setBackgroundRole(QPalette::Base);
    ui->graphicsView->setScene(&m_scene);
    labelBetaka->setFixedWidth(400);
    labelBetaka->setFixedHeight(400);
    labelBetaka->setAlignment(Qt::AlignTop);
    labelBetaka->setAutoFillBackground(true);
    startAnimationPixmap();
#if QT_VERSION >= 0x040600
    view->treeView=ui->treeWidget_books;
    view->lineEdit=ui->lineEdit;
    view->label=labelAnim;
    view->chargePixmap();
    ui->horizontalLayout_7->addWidget(view);
#endif
    //---------------------------عناصر تحرير الكتاب
    ui->horizontalLayout_5->addWidget(ui->toolBarEditBook);
    ui->actionItemFahUp->setIcon(style()->standardIcon(QStyle::SP_ArrowUp));
    ui->actionItemDown->setIcon(style()->standardIcon(QStyle::SP_ArrowDown));
    /////////////////عناصر شجرة الكتب
    QLineEdit *lineEditFind = new QLineEdit(this);
    ui->toolBarBooks->insertWidget(ui->actionFindBkOrHt,lineEditFind);
    ui->horizontalLayoutBook->addWidget(ui->toolBarBooks);
    //--------------عناصر الفهرسة
    QToolBar *barFahras = new QToolBar;
    barFahras->setIconSize(QSize(18,18));
    lineEditFindFah = new QLineEdit(this);
    AC_expandTreeFah = new QAction(QPixmap(QString::fromUtf8(":/images/image/btnfolder.png")),trUtf8("توسيع الكل"), this);
    AC_colapsTreeFah = new QAction(QPixmap(QString::fromUtf8(":/images/image/colapse.png")),trUtf8("غلق الكل"), this);
    barFahras->addWidget(lineEditFindFah);
    barFahras->addSeparator();
    barFahras->addAction(AC_expandTreeFah);
    barFahras->addAction(AC_colapsTreeFah);
    ui->horizontalLayoutFahras->addWidget(barFahras);
    //**************whatsthis**************
#ifndef QT_NO_WHATSTHIS
    AC_prevHistorie ->setWhatsThis(trUtf8("الرجوع الى التنقلات التي قمت بها سابقا وليس الى الصفحة السابقة"));
    AC_nextHistorie->setWhatsThis(trUtf8("الرجوع الى التنقلات التالية وليس الى الصفحة التالية"));
    AC_GoSearchInDoc->setWhatsThis(trUtf8("انقر على الزر للبحث في الصفحة الحالية عن النص المدخل في مربع النص"));
    AC_GoSearchInCurBook->setWhatsThis(trUtf8("انقر على الزر للبحث في الكتاب الحالي عن النص المدخل في مربع النص"));
    lineEditFindFah->setWhatsThis(trUtf8("ادخل نص البحث هنا ليتم فلترة الفهرسة كلما ادخلت حرفا جديدا"));
    lineEditFind->setWhatsThis(trUtf8("ادخل نص البحث هنا ليتم فلترة الفهرسة كلما ادخلت حرفا جديدا"));

#endif // QT_NO_WHATSTHIS
    //***********الاشارات signal end slot****
    connect(AC_bookOpen, SIGNAL(triggered()), this, SLOT(menuOpenBook()));
    connect(AC_bookOpenInNewTab, SIGNAL(triggered()), this, SLOT(tabOpenInNewTab()));
    connect(AC_bookRemove, SIGNAL(triggered()), this, SLOT(menu_BookRemove()));
    connect(AC_bookUpdat, SIGNAL(triggered()), this, SLOT(menu_BookUpdat()));
    connect(AC_bookPath, SIGNAL(triggered()), this, SLOT(menu_BookPath()));
    connect(AC_bookRename, SIGNAL(triggered()), this, SLOT(menu_renameBook()));
    connect(AC_groupeRemove, SIGNAL(triggered()), this, SLOT(menu_GroupeRemove()));
    connect(AC_groupeAdd, SIGNAL(triggered()), this, SLOT(menu_GroupeAdd()));
    connect(AC_categorieAdd, SIGNAL(triggered()), this, SLOT(menu_CategorieAdd()));
    connect(AC_groupeRename, SIGNAL(triggered()), this, SLOT(menu_GroupeRename()));
    connect(AC_GoSearchInDoc, SIGNAL(triggered()), this, SLOT(searchIndoc()));
    connect(AC_GoSearchInCurBook, SIGNAL(triggered()), this, SLOT(findInCurrentBook()));
    connect(lineEditSearchInDoc, SIGNAL(returnPressed()), this, SLOT(searchIndoc()));
    connect(txtBrowserBook, SIGNAL(highlighted(const QUrl)), this, SLOT(textBookHighlighted(QUrl)));
    connect(txtBrowserBook, SIGNAL(anchorClicked(const QUrl)), this, SLOT(textBookAnchorClicked(QUrl)));
    connect(AC_nextHistorie, SIGNAL(triggered()), this, SLOT(historieNext ()));
    connect(AC_prevHistorie, SIGNAL(triggered()), this, SLOT(historiePrev()));
    connect(ui->actionItemDown, SIGNAL(triggered()), this, SLOT(itemFahrasMoveDown()));
    connect(ui->actionItemFahUp, SIGNAL(triggered()), this, SLOT(itemFahrasMoveUp()));
    connect(ui->actionItemFahRen, SIGNAL(triggered()), this, SLOT(itemFahrasRename()));
    connect(ui->actionItemFahDelet, SIGNAL(triggered()), this, SLOT(itemFahrasRemove()));
    connect(ui->actionFahAddItem, SIGNAL(triggered()), this, SLOT( itemFahrasAdd()));
    connect(ui->actionFahAddChild, SIGNAL(triggered()), this, SLOT( itemFahrasAddChild()));
    connect(ui->actionSaveEdit, SIGNAL(triggered()), this, SLOT( saveBookEndFahras()));
    connect(lineEditFind, SIGNAL(textChanged(QString)), this, SLOT(searchInTreeBook(QString)));
    connect(ui->actionBookExpAll, SIGNAL(triggered()), ui->treeWidget_books, SLOT(expandAll()));
    connect(ui->actionBookColpAll, SIGNAL(triggered()), ui->treeWidget_books, SLOT(collapseAll()));
    connect(ui->actionFindBkOrHt, SIGNAL(triggered()), this, SLOT(findBookOrHautor()));
    connect(ui->treeWidgetFind, SIGNAL(itemActivated(QTreeWidgetItem* ,int)), this, SLOT(showResultFind(QTreeWidgetItem* )));
    connect(lineEditFindFavo, SIGNAL(textChanged(QString)), this, SLOT(find_favo_textChanged(QString)));
    //****************

    connect(this, SIGNAL(bookAvailable(bool)),ui->action_next, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->action_prev, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->action_first, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->action_last, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->action_edit, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->action_favorit, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->actionGotoPage, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->actionOrganizeFahrasse, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->actionBookInfo, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),ui->actionHiperlink, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(bookAvailable(bool)),AC_GoSearchInCurBook, SLOT(setEnabled(bool)));
   // connect(this, SIGNAL(bookAvailable(bool)),AC_GoSearchInDoc, SLOT(setEnabled(bool)));
    listLineEditName <<lineEditSearchInDoc->objectName() << ui->lineEdit_find_cur->objectName()<< ui->lineEdit_FindRowat->objectName()
            << lineEditFindFah->objectName()<< lineEditFindFavo->objectName()<< lineEditFind->objectName();
    lineEditSearchInDoc->installEventFilter(this);
    lineEditSearchInDoc->setText(trUtf8("بحث"));
    lineEditSearchInDoc->setStyleSheet("QLineEdit {font: italic;color: rgb(115, 115, 115);}");

    ui->lineEdit_find_cur->installEventFilter(this);
    ui->lineEdit_find_cur->setText(trUtf8("بحث"));
    ui->lineEdit_find_cur->setStyleSheet("QLineEdit {font: italic;color: rgb(115, 115, 115);}");

    ui->lineEdit_FindRowat->installEventFilter(this);
    ui->lineEdit_FindRowat->setText(trUtf8("بحث"));
    ui->lineEdit_FindRowat->setStyleSheet("QLineEdit {font: italic;color: rgb(115, 115, 115);}");

    lineEditFindFah->installEventFilter(this);
    lineEditFindFah->setText(trUtf8("بحث"));
    lineEditFindFah->setStyleSheet("QLineEdit {font: italic;color: rgb(115, 115, 115);}");

    lineEditFindFavo->installEventFilter(this);
    lineEditFindFavo->setText(trUtf8("بحث"));
    lineEditFindFavo->setStyleSheet("QLineEdit {font: italic;color: rgb(115, 115, 115);}");

    lineEditFind->installEventFilter(this);
    lineEditFind->setText(trUtf8("بحث"));
    lineEditFind->setStyleSheet("QLineEdit {font: italic;color: rgb(115, 115, 115);}");
    //***********
#ifdef   Q_WS_WIN
    ui->actionArchive->setVisible(false);
#endif


}

//open book****فتح الكتب*****************
void MainWindow:: open_dataBase(QString name,QString title,QString Autor,int position)       //فتح الكتاب
{ 

    //اذا كان نفس الكتاب مفتوحا
    int  tabcount=ui->tabWidget->count();
    for(int r=0;r<tabcount;++r){
        QTextBrowser *txtBrowser = ui->tabWidget->widget(r)->findChild<QTextBrowser *>();
        QString txtname=txtBrowser->objectName();
        QString  str = txtname.section('_', -1);
        QVariant indx=str;
        if (m_bookName[indx.toInt()]==name){

            ui->tabWidget->setCurrentIndex(r);
            return;
        }
    }
    //حفظ التغييرات اذا كان هناك تغيير
    if(txtBrowserBook->document()->isModified()){
        DataBook->updatPage("",txtBrowserBook->document()->toPlainText(),true);
        m_bookIsModified[m_currentIndex]=true;
    }

    if (closeMessages(m_bookTitle[m_currentIndex],m_currentIndex)==false){

        return;
    }
    //التأكد من وجود الكتاب في المسار
    QString bkpath;           //مسار الكتاب    
    QFile file;
    if( file.exists( m_pathCostm + "/" + name +"/book.xml")){
        if (m_currentIndex==0){tabCreatTabNew();}
        bkpath=m_pathCostm + "/" + name +"/book.xml";
        m_bookPath[m_currentIndex]=m_pathCostm + "/" + name;
    }else if(file.exists( m_pathApp + "/books/" + name +"/book.xml")){
        if (m_currentIndex==0){tabCreatTabNew();}
        bkpath=m_pathApp + "/books/" + name +"/book.xml";
        m_bookPath[m_currentIndex]=m_pathApp + "/books/" + name;

    }else{
        QMessageBox::information(this,trUtf8("خطأ"),m_pathCostm + "/" + name +trUtf8( "غير موجود ") );
        return;
    }
    //***********************************
    file.close();


    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    //حفظ الكتاب السابق
    if (!m_bookName[m_currentIndex].isEmpty()){
        QVariant idbk=DataBook->currentPosition[DataBook->boocNumIndex];
        Messages->recentChange(m_bookName[m_currentIndex],m_bookTitle[m_currentIndex],m_bookAuthor[m_currentIndex],idbk.toString(),m_recentNbr,m_isTefsir[m_currentIndex]);
        Messages->recentCharge();
    }
    //فتح الكتاب
    if ( DataBook->openBook(name,position,bkpath)==true)
    {        
        m_bookName[m_currentIndex]=name;
        m_bookTitle[m_currentIndex]=title;
        m_bookAuthor[m_currentIndex]=Autor;
        bookValueChanged(position);
        m_isTefsir[m_currentIndex]=DataBook->isTefsir ;
        emit bookAvailable(true);
    }else{
        QMessageBox::information(this,trUtf8("خطأ"),bkpath + trUtf8("التنسيق غير صحيح ") );
        QApplication::restoreOverrideCursor();     
        return;
    }
    //تحميل الشجرة الكتاب
    Messages->treeChargeFahrass(treeViewFahras[m_currentIndex],m_bookPath[m_currentIndex]);
    //استعادة اصل المتغيرات
    m_listHistoriePrev[m_currentIndex].clear();
    m_listHistorieNext[m_currentIndex].clear();
    m_listHistoriePrev[m_currentIndex].append(position);
    AC_prevHistorie->setEnabled(false);
    AC_nextHistorie->setEnabled(false);
    ui->dockWidget_fahras->setShown(true);
    treeViewFahras[m_currentIndex]->headerItem()->setText(0,m_bookTitle[m_currentIndex]);
    treeViewFahras[m_currentIndex]->setColumnCount(2);
    treeViewFahras[m_currentIndex]->setColumnHidden(1,true);
    treeViewFahras[m_currentIndex]->setDragDropMode(QAbstractItemView::NoDragDrop);
    treeViewFahras[m_currentIndex]->setSelectionMode(QAbstractItemView::SingleSelection);
    m_treeFahrasIsModified[m_currentIndex]=false;
    m_bookIsModified[m_currentIndex]=false;
    ui->frameEdit->setVisible(false);
    m_toolEditFahrass[m_currentIndex]=false;
    txtBrowserBook->setReadOnly(true);
    txtBrowserBook->setUndoRedoEnabled(false);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),m_bookTitle[m_currentIndex]);
    this->tabifyDockWidget(ui->dockWidget_books,ui->dockWidget_fahras);
    if(Messages->loadBookInfo(m_bookPath[m_currentIndex])==true){
        m_bookBetaka[m_currentIndex]=Messages->infoBookBetaka;
        ui->actionBookInfo->setVisible(true);
    }

    QApplication::restoreOverrideCursor();
}

//menufile----------------------------
void MainWindow::on_action_import_triggered()//استراد ملفات نصية
{
    dialogconvert *dlgc=new dialogconvert(this);
    dlgc->m_pathCostum=m_pathCostm;
    if ( dlgc->exec() == QDialog::Accepted ){
        chargeGroupe();
    }
}

void MainWindow::on_actionMdb_triggered()
{

#ifdef   Q_WS_WIN
    Dialogmdb *dlg=new Dialogmdb(this);
    dlg->m_path=m_pathCostm;
    if ( dlg->exec() == QDialog::Accepted ){
        chargeGroupe();
    }
#else
    mdbexport *dlg=new mdbexport(this);
    dlg->m_path=m_pathCostm;
    if ( dlg->exec() == QDialog::Accepted ){
        chargeGroupe();
    }
#endif
}

void MainWindow::on_action_addBoook_triggered()//اظافة كتاب
{
    Dialog* dlg=new Dialog(this);
    dlg->m_path=m_pathCostm;
    if ( dlg->exec() == QDialog::Accepted ){
        chargeGroupe();
    }
}

void MainWindow::on_actionExport_triggered()//تصدير الكتاب
{
    if (m_bookName[m_currentIndex].isEmpty()){
        return;
    }
    Print* dlg=new Print(this);
    dlg->treeviw=treeViewFahras[m_currentIndex];
    dlg->curentPath=m_bookPath[m_currentIndex];
    dlg->m_WebColorBack=m_WebColorBack;                           //لون خلفية النص
    dlg->m_WebFontTitle=m_WebFontTitle;
    dlg-> m_WebFont=m_WebFont;                            //نوع النص
    dlg-> m_WebFontColor=m_WebFontColor;
    dlg-> m_WebFontTitleColor=m_WebFontTitleColor;
    dlg-> m_WebFontPrefertColor=m_WebFontPrefertColor;
    dlg-> m_bookTitle=m_bookTitle[m_currentIndex];
    dlg-> m_bookAuthor=m_bookAuthor[m_currentIndex];
    dlg->exec();
}

void MainWindow::on_actionArchive_triggered()
{
    if (m_bookName[m_currentIndex].isEmpty())
        return;

    QString fileName=m_bookPath[m_currentIndex];
    QDir dirF(fileName);
    if (!dirF.exists()){
        QMessageBox::information(this,trUtf8("معلومات"),trUtf8("لا يوجد كتاب لارشفته"));
        return ;
    }
    QString dirParent=fileName;
    QString dirName=dirF.dirName();
    dirParent.replace(dirName,QString::null);
    dirParent.replace("//",QString::null);

    QDir::setCurrent(dirParent);

    QString title=m_bookTitle[m_currentIndex];
    title.replace(" ","_");
    QProcess prosses;
    prosses.execute("tar -cvzf "+ QDir::homePath()+"/"+title+".krts "+ dirName);

    QMessageBox::information(this,trUtf8("معلومات"),trUtf8("لقد تم انشاء الارشيف بنجاح")+"\n"+QDir::homePath()+"/"+title+".krts");
}

void MainWindow::on_actionBookInfo_triggered()
{
    if (m_bookName[m_currentIndex].isEmpty())
        return;

    QString imgScreenPath= m_pathCostm + "/" +m_bookName[m_currentIndex]+"/screenshot.png";
    if(!QFile::exists(imgScreenPath)){
       imgScreenPath=":/images/image/groupbook.png";
    }
    QPixmap   pixmapG(imgScreenPath) ;
    QMessageBox msgBox(this);
    msgBox.setLayoutDirection(Qt::RightToLeft);
    msgBox.setIconPixmap(pixmapG);
    msgBox.setWindowTitle(trUtf8("معلومات عن الكتاب"));
    QString tit=" <span style='font-family:"+m_WebFontTitle+";  font-size:14pt; color:"+m_WebFontTitleColor+";'>"+m_bookTitle[m_currentIndex]+"</span>";
    msgBox.setText(tit);
    msgBox.setInformativeText(trUtf8("المؤلف : ")+m_bookAuthor[m_currentIndex]+"\n"+m_bookBetaka[m_currentIndex]
                              +"\n المسار : "+m_bookPath[m_currentIndex] );
    msgBox.exec();


}

void MainWindow::on_actionNewTab_triggered()
{
    tabCreatTabNew();
}

void MainWindow::on_actionPrint_triggered()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (txtBrowserBook->textCursor().hasSelection())
        dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    dlg->setWindowTitle(tr("Print Document"));
    if (dlg->exec() == QDialog::Accepted) {
     txtBrowserBook->print(&printer);

    }
    delete dlg;
#endif
}

void MainWindow::on_actionPrintPreview_triggered()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreview(QPrinter*)));
    preview.exec();
#endif
}

void MainWindow::on_action_close_triggered()
{
    // qApp->quit();
    if(this->close()==true)
        qApp->quit();
}

//menuEdit----------------------------

void MainWindow::on_action_first_triggered()//السجل الاول
{
    bookValueChanged(0);
}
void MainWindow::on_action_next_triggered()//السجل التالي
{
    if (DataBook->currentPosition[m_currentIndex]==DataBook->rowsCount[m_currentIndex]){return;}
    bookValueChanged(DataBook->currentPosition[m_currentIndex]+1);
}
void MainWindow::on_action_prev_triggered()//السجل السابق
{
    if (DataBook->currentPosition[m_currentIndex]==0){return;}
    bookValueChanged(DataBook->currentPosition[m_currentIndex]-1);
}
void MainWindow::on_action_last_triggered()//السجل الاخير
{
    bookValueChanged(DataBook->rowsCount[m_currentIndex]);
}
void MainWindow::on_actionGotoPage_triggered()
{
    if (m_bookName[m_currentIndex].isEmpty()){  return; }
    dialoggoto *dlggo=new dialoggoto(this);
    dlggo->pathBook= m_bookPath[m_currentIndex]+"/book.xml";
    dlggo->rowCount=DataBook->rowsCount[m_currentIndex];
    dlggo->counter=DataBook->currentPosition[m_currentIndex];
    dlggo->updateValue();
    if (dlggo->exec() == QDialog::Accepted) {
        int id=dlggo->counter-1;
        bookValueChanged(id);
    }
}

void MainWindow::on_actionFind_all_triggered()  // تنفيذ البحث في مجموعة الكتب
{
    if (Findbook->isFindRuned==true){ return;}
    Dialogfind* dlg=new Dialogfind(this);
    dlg->bookPath=m_pathCostm;
    if ( dlg->exec() == QDialog::Accepted ){
        m_textfind=dlg->findString;
        if ( m_textfind.length()<3){ return;}

         showfind(false);

        labelTextFind->setText(trUtf8("نص البحث  : ")+m_textfind);
        labelProgress->setVisible(true);
        labelProgressImg->setVisible(true);
      //  BtnStopFind->setVisible(true);
ui->action_stopFind->setVisible(true);
        Findbook->pathCostum=m_pathCostm;
        Findbook->findFirst=dlg->findFirst;
        Findbook->findToList=dlg->findList;
        Findbook->findMultiFind=dlg->MultiFind;
        Findbook->findAnd=dlg->findAnd;
        Findbook->findSawabik=dlg->findSawabik;
        Findbook->findText= m_textfind;
        Findbook->resultCount=0;
        Findbook->progressBar1=  progressBarFind;
      //  Findbook->pushButtonStop=BtnStopFind;
        Findbook->buttonStop= ui->action_stopFind;
        Findbook->treeView=ui->treeWidgetFind;
        Findbook->labelProgress=labelProgress;
        Findbook->label_progressImg=labelProgressImg;
       Findbook->isNassToFind=dlg->findIsNass;
       this->isNassToFind=dlg->findIsNass;
//m_isRawiToFind=false;
ui->treeWidgetFind->clear();
        Findbook->findInAllBook(dlg->findIsNass);


    }
}

void MainWindow::on_action_edit_triggered()  //تحرير الفهرسة
{
    if (!m_bookName[m_currentIndex].isEmpty()){
        txtBrowserBook->setReadOnly(false);
        txtBrowserBook->setUndoRedoEnabled(true);
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),trUtf8("تحرير : ")+m_bookTitle[m_currentIndex]);
        ui->frameEdit->setVisible(true);//اظهار ادوات التحرير
        treeViewFahras[m_currentIndex]->setDragDropMode(QAbstractItemView::InternalMove);//تفعيل عملية النقل بالفأرة
        treeViewFahras[m_currentIndex]->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_toolEditFahrass[m_currentIndex]=true;
    }
}

void MainWindow::on_action_favorit_triggered()
{
    if (m_bookName[m_currentIndex].isEmpty()){ return;}
    dialogfavo *dlg=new dialogfavo(this);
    dlg->iconFolder=m_icondir;
    dlg->iconFile=m_icondfile;
    dlg->view=ui->treeWidget_fav;
    dlg->bookTitle=m_bookTitle[m_currentIndex];
    dlg->bookName=m_bookName[m_currentIndex];
    dlg->bookAut=m_bookAuthor[m_currentIndex];
    QVariant idbk=DataBook->currentPosition[DataBook->boocNumIndex];
    dlg->bookId=idbk.toString();
    dlg->charge_combo();
    dlg->exec() ;
}

void MainWindow::on_actionHiperlink_triggered()
{
    if (txtBrowserBook->textCursor().selectedText().isEmpty()){ return;}
    QString oldtxt=txtBrowserBook->textCursor().selectedText();

    Wizard=new ClassWizard(this);
    Wizard->setWizardStyle(QWizard::ModernStyle);
    if (Wizard->exec()==QDialog::Accepted) {
        // QMessageBox::information(this,"", Wizard->urlTexte);
        QString urltext="<a href='" +Wizard->urlTexte+"'>"+oldtxt+"</a>";
        txtBrowserBook->textCursor().insertHtml(urltext);
        DataBook->updatPage(oldtxt,urltext,false);
        m_bookIsModified[m_currentIndex]=true;
        txtBrowserBook->document()->setModified(false);
    }
}

void MainWindow::on_actionOrganizeFahrasse_triggered()
{
    DataBook->treeOrganizFahrass(treeViewFahras[m_currentIndex],m_bookPath[m_currentIndex]);
    m_treeFahrasIsModified[m_currentIndex]=true;
}

void MainWindow::on_actionUpdatGroupRemove_triggered()
{
    Messages->m_pathCostum=m_pathCostm;
    Messages->treeUpdateGroupe(ui->treeWidget_books,true);
    m_treeGroupIsModified=true;
}

void MainWindow::on_actionUpdatGroup_triggered()
{
    Messages->m_pathCostum=m_pathCostm;
    Messages->treeUpdateGroupe(ui->treeWidget_books,false);
}

//menuView-----------------------------



void MainWindow::on_action_fulscreen_triggered()//ملأ الشاشة
{
    if (this->windowState()==Qt::WindowFullScreen){
        ui->statusBar->setVisible(true);
        ui->menuBar->setParent(this);
        this->setMenuBar(ui->menuBar);
        ui->menuBar->setStyleSheet("");
        ui->menuBar->setVisible(true);
        loadLayout();

        this->showNormal();
    } else {
        saveLayou();
        ui->dockWidget_books->setVisible(false);
        ui->dockWidget_curaan->setVisible(false);
        ui->dockWidget_fahras->setVisible(false);
        ui->dockWidget_favorite->setVisible(false);
        ui->dockWidget_find->setVisible(false);
        ui->toolBar_navegator->setVisible(false);
        ui->mainToolBar->setVisible(false);
        ui->statusBar->setVisible(false);

  ui->menuBar->setParent(ui->tabWidget);
ui->menuBar->setVisible(true);
ui->menuBar->setStyleSheet("QMenuBar {background-color: rgba(255, 255, 255, 0);}");
 ui->menuBar->setGeometry(0,0,23,23);


        this->showFullScreen();
    }
}

void MainWindow::on_actionOption_triggered()
{
    Dialogoption *dlgop=new Dialogoption(this);
    dlgop->colorBack=m_WebColorBack;
    dlgop->colorFont=m_WebFontColor;
    dlgop->colorFind=m_WebFontFindColor;
    dlgop->colorPrefer=m_WebFontPrefertColor;
    dlgop->colorTitle=m_WebFontTitleColor;
    dlgop->recentNbr=m_recentNbr;
    dlgop->pathCostm=m_pathCostm;
    dlgop->webCadre=m_isCadre;
    QFont font;
    font.fromString(m_WebFont);
    dlgop->fontName=font;
    dlgop->fontTitleName=m_WebFontTitle;
    dlgop->fontTitleSize=m_WebFontTitleSize;
    dlgop->fontHachiaName=m_WebFontHachia;
    dlgop->themesStyle=m_myStyleName;
    dlgop->cadreFolder=m_CadrFolder;
    dlgop->recharge();
    if ( dlgop->exec() == QDialog::Accepted ){
        m_WebColorBack=   dlgop->colorBack;
        m_WebFontColor=  dlgop->colorFont;
        m_WebFontFindColor=dlgop->colorFind;
        m_WebFontPrefertColor= dlgop->colorPrefer;
        m_WebFontTitleColor = dlgop->colorTitle;
        txtBrowserBook->setFont(dlgop->fontName);
        m_WebFont= dlgop->fontName.toString();
        m_isCadre=dlgop->webCadre;
        m_myStyleName=  dlgop->themesStyle;
        m_recentNbr= dlgop->recentNbr;
        m_pathCostm=dlgop->pathCostm;
        m_WebFontTitle=dlgop->fontTitleName;
        m_WebFontTitleSize=dlgop->fontTitleSize;
        m_WebFontHachia=   dlgop->fontHachiaName;
        m_CadrFolder=dlgop->cadreFolder;
        QApplication::setStyle(QStyleFactory::create( m_myStyleName));
        if (m_currentIndex>0){
            convertTextToHtml(DataBook->bookNass[m_currentIndex]);
        }
    }
}

void MainWindow::on_actionRemoveTechkil_triggered()
{
    if(ui->actionRemoveTechkil->isChecked()){
        DataBook->removeTechkile=true;
    }else{
        DataBook->removeTechkile=false;
    }
    bookValueChanged(DataBook->currentPosition[m_currentIndex]);
}

void MainWindow::on_actionPageIntro_triggered()
{
    if( ui->tabIntro->isHidden())  {

        ui->tabWidget->insertTab(0,ui->tabIntro,trUtf8("مكتبة القرطاس"));
        ui->stackedWidget->insertWidget(0,ui->pageIntro);
        ui->tabWidget->setCurrentWidget(ui->tabIntro);
    }
    ui->stackedWidget_intro->setCurrentWidget(ui->page_anim);
    labelAnim->setText(trUtf8(""));
    view->chargeEnrto();
}

void MainWindow::on_actionZoumIn_triggered()
{
    txtBrowserBook->zoomIn();
}

void MainWindow::on_actionZoomOut_triggered()
{
    txtBrowserBook->zoomOut();
}

//menuHelp-----------------------------------
void MainWindow::on_action_about_triggered()//حول البرنامج
{
    About *dlg=new About(this);

    if ( dlg->exec() == QDialog::Accepted|| QDialog::Rejected){
    }
}

void MainWindow::on_actionHelp_triggered()
{
    if( ui->tabIntro->isHidden())  {

        ui->tabWidget->insertTab(0,ui->tabIntro,trUtf8("مكتبة القرطاس"));
        ui->stackedWidget->insertWidget(0,ui->pageIntro);
    }
    ui->stackedWidget_intro->setCurrentWidget(ui->page_text);
     ui->treeWidget_rowatFind->setVisible(false);

    ui->tabWidget->setCurrentWidget(ui->tabIntro);
    labelAnim->setText(trUtf8("التعليمات"));
    QFile file(m_pathApp+"/data/help.html");
    if (!file.exists()){
        ui->textBrowser_0->setText(trUtf8("ملف التعليمات  : ")+m_pathApp+"/data/help.html\n"+trUtf8("غير موجود"));
        return;
    }
    if (file.open(QIODevice::ReadOnly)){
        QByteArray data = file.readAll();
        QTextCodec *codec = Qt::codecForHtml(data);
        QString str = codec->toUnicode(data);
        str.replace("<img src=\"","<img src=\""+m_pathApp+"/data/");
        if (Qt::mightBeRichText(str)) {
            ui->textBrowser_0->setHtml(str);
            ui->textBrowser_0->setOpenLinks(true);
        }
        file.close();
    }
}

/*void MainWindow::on_actionHtmlFile_triggered()
{

    QFile file(QDir::homePath()+"/.kirtasse/data/html/bookindex.html");
    ui->textBrowser_0->setVisible(true);
    ui->frame_anim->setVisible(false);
    ui->tabWidget->setCurrentWidget(ui->tabIntro);
    labelAnim->setText("");
    ui->textBrowser_0->setOpenLinks(true);
    if( ui->tabIntro->isHidden())  {
        ui->tabWidget->insertTab(0,ui->tabIntro,trUtf8("مكتبة القرطاس"));
        ui->stackedWidget->insertWidget(0,ui->pageIntro);
    }
    if (!file.exists()){
        booksInterface->creatHtmlFile();

    }else{

        int reponse = QMessageBox::information(this, trUtf8("تنبيه"), trUtf8("هل تريد تحديث بيانات الكتب المتفورة من الانترنت ") ,QMessageBox::Yes | QMessageBox::No );
        if (reponse == QMessageBox::Yes){
            booksInterface->creatHtmlFile();
        }
    }
    QUrl url;
    url= QUrl::fromLocalFile(QDir::homePath()+"/.kirtasse/data/html/bookindex.html");
    ui->textBrowser_0->setSource(url);
}*/

void MainWindow::on_actionWhatsThis_triggered()
{
    QWhatsThis::enterWhatsThisMode();
}

//**treeViewBook-----------------------------------
void MainWindow::on_treeWidget_books_itemSelectionChanged()//تحديد عنصر الكتاب في الشجرة
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    if (!item->data(1,1).isNull()){
        QString imgScreenPath= m_pathCostm + "/" +item->data(1,1).toString()+"/screenshot.png";
        if(!QFile::exists(imgScreenPath)){
           imgScreenPath=":/images/image/booki.png";
        }
        QString imgScreen=QString("<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src= %1 /></p>").arg(imgScreenPath);

        QString   m_txtAnim=imgScreen
              +  trUtf8("الكتاب :") +  item->text(0) +"<br>"
                            + trUtf8("المؤلف :") +  item->text(1) +"<br>"
                            +   item->text(2);
        labelBetaka->setText(m_txtAnim);
        startAnimationBitaka();
    }else{
        startAnimationPixmap();
    }
}

void MainWindow::on_treeWidget_books_itemActivated(QTreeWidgetItem* item)//تفعيل عنصر شجرة الكتب
{
    QString x = item->data(1,1).toString();
    if (!x.isEmpty())
    {
        open_dataBase(x,item->text(0),item->text(1),0);
        QVariant tf = item->data(2,1).toString();
        m_isTefsir[m_currentIndex]=tf.toBool();
    }
}

void MainWindow::on_treeWidget_books_customContextMenuRequested()//قائمة منسدلة فرعية لشجرة الكتب
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    if (!item->data(1,1).isNull()){
        QMenu menu(this);
        menu.setLayoutDirection(Qt::RightToLeft);
        menu.addAction(AC_bookOpen);
        menu.addAction(AC_bookOpenInNewTab);
        menu.addAction(AC_bookUpdat);
        menu.addSeparator();
        menu.addAction(AC_bookRemove);
        menu.addSeparator();
        menu.addAction(AC_bookPath);
        menu.addAction(AC_bookRename);
        menu.exec(QCursor::pos());
    }else {
        QMenu menu(this);
        menu.setLayoutDirection(Qt::RightToLeft);
        menu.addAction(AC_categorieAdd);
        menu.addAction(AC_groupeAdd);
        menu.addAction(AC_groupeRename);
        menu.addSeparator();
        menu.addAction(AC_groupeRemove);
        menu.exec(QCursor::pos());
    }
}

void MainWindow::menuOpenBook()//النقر على قائمة فتح كتاب
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    if (!item->data(1,1).isNull()){
        open_dataBase(item->data(1,1).toString(),item->text(0),item->text(1),0);
    }
}

void MainWindow::menu_BookRemove()//حذف الكتاب
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    if (!item->data(1,1).isNull()){
        QString myiddata=item->data(1,1).toString();
        QMessageBox msgBox;
        msgBox.setText(trUtf8("هل تريد حذف : ") + item->text(0)+trUtf8(" ؟"));
        msgBox.setInformativeText(trUtf8("انقر على نعم لحذفه من المكتبة فقط \n")+trUtf8("او نعم للكل لحذفه من المكتبة ومن جهازك"));
        msgBox.setDetailedText(trUtf8("اذا نقرت على نعم للكل سيتم حذف الكتاب من الدليل التالي ومن المكتبة\n")+m_pathCostm+myiddata);
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setLayoutDirection(Qt::RightToLeft);
        msgBox.setWindowTitle(trUtf8("تأكيد الحذف"));
        msgBox.setStandardButtons(QMessageBox::YesAll | QMessageBox::Yes | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::YesAll);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::YesAll:
            Messages->treeMenuRemoveBook(myiddata,true);
            chargeGroupe();
            break;
        case QMessageBox::Yes:
            Messages->treeMenuRemoveBook(myiddata,false);
            chargeGroupe();
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
        }
    }
}

void MainWindow::menu_BookUpdat()  //تغيير بيانات الكتاب
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    dialogupdat *dlgc=new dialogupdat(this);
    dlgc->m_pathCostum=m_pathCostm;
    dlgc->BookName=item->data(1,1).toString();
    dlgc->addGroupId=item->parent()->data(2,1).toString();
    dlgc->bookTitle=item->text(0);
    dlgc->bookAutor=item->text(1);
    dlgc->bookBetaka=item->text(2);


    dlgc->recharge();
    if ( dlgc->exec() == QDialog::Accepted ){
        chargeGroupe();
    }
}
void MainWindow::menu_BookPath()//معرفة مسار الكتاب
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    if (!item->data(1,1).isNull()){
        QString name=item->data(1,1).toString();
        QString path;
        QFile file;
        if(file.exists(m_pathCostm + "/" + name)){
            path=m_pathCostm + "/" + name;
        }else if(file.exists(m_pathApp + "/books/" + name)){
            path=m_pathApp + "/books/" + name;
        }else{
            path=name + trUtf8(" : غير موجود في الجهاز");
        }
        QMessageBox::information(this,trUtf8("مسار الكتاب"),path);
    }
}

void MainWindow:: menu_renameBook()
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    QString name=item->data(1,1).toString();
    QString path;
    QFile file;
    if(file.exists(m_pathCostm + "/" + name)){
        path=m_pathCostm;
    }else if(file.exists(m_pathApp + "/books/" + name)){
        path=m_pathApp + "/books/";
    }

    QDir dir(path);
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("الاسم القديم : ")+name+"\n"+trUtf8("يحبذ ان لا يحتوي الاسم على فراغات"));
    dff->setWindowTitle(trUtf8("اعادة تسمية دليل الكتاب"));
    dff->setTextValue(item->text(0).replace(" ","_"));
    if (dff->exec()==QInputDialog::Accepted ){
        if (dff->textValue().isEmpty()){
            return;
        }
        if(file.exists(path + "/" + dff->textValue())){
            QMessageBox::critical(this,trUtf8("خطأ"),trUtf8("يوجد مجلد بنفس الاسم"));
            return;
        }
        if(dir.rename(name,dff->textValue())==true){
            item->setData(1,1,dff->textValue());
            Messages->treeSaveGroupe(ui->treeWidget_books);

            QMessageBox::information(this,trUtf8("معلومات"),trUtf8("تمت عملية اعادة تسمية دليل الكتاب بنجاح"));
        }
    }
}

void MainWindow:: menu_Add(bool categorie)
{
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    if (categorie==true){
        dff->setLabelText(trUtf8("ادخل اسما للقسم الجديد"));
        dff->setWindowTitle(trUtf8("قسم جديد"));
    }else{
        dff->setLabelText(trUtf8("ادخل اسما للمجموعة الجديدة"));
        dff->setWindowTitle(trUtf8("مجموعة جديدة"));
    }

    QString text;
    if (dff->exec()==QInputDialog::Accepted )
    {
        text=dff->textValue();
        //***********
        QVariant newId;
        newId=Messages->genirateId(ui->treeWidget_books);
        //*************
        QTreeWidgetItem *curentitem;//العنصر المحدد
        QTreeWidgetItem *item;//العنصر الذي سنظيفه
        curentitem= ui->treeWidget_books->currentItem();
        if (categorie==true){                   //اذا لم يكن هناك تحديد سيظاف الى الجذر
            item= new QTreeWidgetItem(ui->treeWidget_books);

        }else{
            if (!curentitem->parent()){                   //اذا لم يكن هناك تحديد سيظاف الى الجذر
                item= new QTreeWidgetItem(curentitem);
            }else{        // اما ان كان هناك عنصر محدد سيظاف بعده
                item= new QTreeWidgetItem(curentitem->parent());
            }
        }
        item->setText(0,text );
        item->setData(2,1,newId.toString());
        item->setIcon(0,m_iconGroup);
        item->setSelected(true);
        //  curentitem->setSelected(false);
        ui->treeWidget_books->setCurrentItem(item);//تفعيل العنصر المظاف
        m_treeGroupIsModified=true;
        if (m_treeGroupIsModified==true){
            int reponse = QMessageBox::warning(this, trUtf8("تنبيه"), trUtf8("هل تريد حفظ التغييرات المدخلة على مجموعة الكتب ") , QMessageBox::Yes | QMessageBox::No);
            if (reponse == QMessageBox::Yes){
                if ( Messages->treeSaveGroupe(ui->treeWidget_books)){
                    QMessageBox::information(this,trUtf8("معلومات"), trUtf8("تمت عملية حفظ مجموعة الكتب بنجاح"));
                    m_treeGroupIsModified=false;
                }
            }
        }
    }
}

void MainWindow::menu_CategorieAdd()
{
    menu_Add(true);
}

void MainWindow::menu_GroupeAdd() //اضافة مجمعة جديدة الى الشجرة
{
    menu_Add(false);
}
void MainWindow::menu_GroupeRemove()//حذف المجموعة
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    if (item->childCount()>0){
        QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("المحموعة تحتوي على عناصر تحتهاقم بحذف هذه العناصر أولا"));
    }else{
        int reponse = QMessageBox::question(this, trUtf8("معلومات"), trUtf8("هل تريد حذف المجموعة المحددة؟ ") , QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes){
            if (Messages->treeviewItemRemove(ui->treeWidget_books)==true){
                m_treeGroupIsModified=true;}
        }
    }
}
void MainWindow::menu_GroupeRename()  //اعادة تسمية المجموعة
{
    QTreeWidgetItem *item=ui->treeWidget_books->currentItem();
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("ادخل النص الجديد"));
    dff->setWindowTitle(trUtf8("اعادة تسمية المجموعة"));
    dff->setTextValue(item->text(0));
    if (dff->exec()==QInputDialog::Accepted ){
        if (dff->textValue().isEmpty()){return;}
        item->setText(0,dff->textValue());
        m_treeGroupIsModified=true;
    }
}

//**treeViewFahras---------------------------------------
void MainWindow::fahras_itemClicked(QTreeWidgetItem* item)//النقر على عنصر شجرة الفهرسة
{
    if ( m_toolEditFahrass[m_currentIndex]==false){
        bookValueChanged(item->data(1,1).toInt()-1);
        int index=txtBrowserBook->toPlainText().indexOf(item->text(0));
        if (index>0){
            QTextCursor cursor(txtBrowserBook->document());
            cursor.setPosition(index,QTextCursor::MoveAnchor);
            cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
            txtBrowserBook->setTextCursor(cursor);
        }
        treeViewFahras[m_currentIndex]->setCurrentItem(item);
    }
    //
}

void MainWindow::fahras_itemActivated(QTreeWidgetItem* item)
{
    DataBook->newPosition[m_currentIndex]=item->data(1,1).toInt()-1;
    bookValueChanged(item->data(1,1).toInt()-1);
    int index=txtBrowserBook->toPlainText().indexOf(item->text(0));
    if (index>0){
        QTextCursor cursor(txtBrowserBook->document());
        cursor.setPosition(index,QTextCursor::MoveAnchor);
        cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
        txtBrowserBook->setTextCursor(cursor);

    }
    treeViewFahras[m_currentIndex]->setCurrentItem(item);
}

void MainWindow::on_pushButtonEditClose_clicked()
{
    txtBrowserBook->setReadOnly(true);
    txtBrowserBook->setUndoRedoEnabled(false);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),m_bookTitle[m_currentIndex]);
    ui->frameEdit->setVisible(false);
    m_toolEditFahrass[m_currentIndex]=false;
    treeViewFahras[m_currentIndex]->setDragDropMode(QAbstractItemView::NoDragDrop);
    treeViewFahras[m_currentIndex]->setSelectionMode(QAbstractItemView::SingleSelection);

}
void MainWindow::itemFahrasAdd()
{
    addItemInTreeFahras(false);
}

void MainWindow::itemFahrasAddChild()
{
    addItemInTreeFahras(true);
}
void MainWindow::itemFahrasRename()
{
    QTreeWidgetItem *item=treeViewFahras[m_currentIndex]->currentItem();
    if(!item){ return;}
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("ادخل اسما جديدا"));
    dff->setWindowTitle(trUtf8("اعادة تسمية العنصر"));
    dff->setTextValue(item->text(0));
    if (dff->exec()==QInputDialog::Accepted ){
        QString  newtext = dff->textValue();
        if (newtext.isEmpty()){ return;}
        item->setText(0,newtext);
        m_treeFahrasIsModified[m_currentIndex]=true;
    }
}
void MainWindow::itemFahrasRemove()//حذف عنصر من الفهرسة
{
    if (Messages->treeviewItemRemove(treeViewFahras[m_currentIndex])==true){
        m_treeFahrasIsModified[m_currentIndex]=true;}
}

void MainWindow::itemFahrasMoveDown()//نقل عنصر للاسفل في الفهرسة
{
    if (Messages->treeviewItemDown(treeViewFahras[m_currentIndex])==true){
        m_treeFahrasIsModified[m_currentIndex]=true;}
}

void MainWindow::itemFahrasMoveUp()//نقل عنصر للاعلى في الفهرسة
{
    if (Messages->treeviewItemUp(treeViewFahras[m_currentIndex])==true){
        m_treeFahrasIsModified[m_currentIndex]=true;}
}

void MainWindow::on_btnGoFindFah_clicked()//انشاء فهارس
{
    QRegExp rx;
    QRegExp rx2;
    if (ui->checkBoxNumber->isChecked()){
        rx.setPattern("(\\d+)("+ui->lineEditNiveau1->text()+")");
    }else{
        if (ui->lineEditNiveau1->text().isEmpty())
            return;
        rx.setPattern(ui->lineEditNiveau1->text());
    }
    if (ui->checkBoxNumber2->isChecked()){
        rx2.setPattern("(\\d+)("+ui->lineEditNiveau2->text()+")");
    }else{

        rx2.setPattern(ui->lineEditNiveau2->text());
    }

    Findbook->findFahariss(treeViewFahras[m_currentIndex],m_bookPath[m_currentIndex],rx
                           ,rx2, DataBook->rowsCount[m_currentIndex]  );
    m_treeFahrasIsModified[m_currentIndex]=true;

}

//**treeViewFavorit--------------------------------
void MainWindow::on_treeWidget_fav_itemActivated(QTreeWidgetItem* item)
{
    if (item->data(1,1).toString().isEmpty()){return;}
    QVariant bkpage=item->data(2,1);
    QVariant bknam=item->data(1,1);
    if (bknam.toString()==m_bookName[m_currentIndex]){
        DataBook->newPosition[m_currentIndex]=bkpage.toInt();
        bookValueChanged(bkpage.toInt());
    }else{
        open_dataBase(item->data(1,1).toString(),item->text(1),item->text(2),bkpage.toInt());
    }
}

void MainWindow::on_actionFavSave_triggered()
{
    Messages->favorite_save(ui->treeWidget_fav);
}

void MainWindow::on_actionFavItemRen_triggered()
{
    QTreeWidgetItem *item=ui->treeWidget_fav->currentItem();
    if(!item){ return;}
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("ادخل اسما جديدا"));
    dff->setWindowTitle(trUtf8("اعادة تسمية العنصر"));
    dff->setTextValue(item->text(0));
    if (dff->exec()==QInputDialog::Accepted ){
        QString  newtext = dff->textValue();
        if (newtext.isEmpty()){ return;}
        item->setText(0,newtext);
    }
}

void MainWindow::on_actionFavItemUp_triggered()
{
    QTreeWidgetItem *item=ui->treeWidget_fav->currentItem();
    if(!item){ return;}
    Messages->treeviewItemUp(ui->treeWidget_fav);
}

void MainWindow::on_actionFavItemDown_triggered()
{
    QTreeWidgetItem *item=ui->treeWidget_fav->currentItem();
    if(!item){ return;}
    Messages->treeviewItemDown(ui->treeWidget_fav);
}

void MainWindow::on_actionFavDelete_triggered()
{
    QTreeWidgetItem* item=ui->treeWidget_fav->currentItem();
    if(!item){ return;}
    QString text;
    if (item->childCount()>0){
        text= trUtf8("العنصر الذي تريد حذفه يحتوي على عناصر اخرى هل تريد حذفه رغم ذلك ؟");
    }else{
        text= trUtf8("هل تريد حذف العنصر المحدد");
    }
    int reponse = QMessageBox::warning(this, trUtf8("تنبيه"),text , QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::No){return;}
    Messages->treeviewItemRemove(ui->treeWidget_fav);
}

//**treeVeiwCuran-----------------------------
void MainWindow::on_treeWidget_curaan_itemActivated(QTreeWidgetItem* item)//تفعيل عنصر شجرة القرءان
{
    if (m_isTefsir[m_currentIndex]==true){
        ui->treeWidget_curaan->setCursor(QCursor(Qt::WaitCursor));
        QString mysora = item->data(1,1).toString().section('_', 0, 0);
        QString myaya = item->data(1,1).toString().section('_', -1);
        if (DataBook->findAya(mysora,myaya)==true)  {
            bookValueChanged(DataBook->currentPosition[m_currentIndex]);
            ui->treeWidget_curaan->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
    }
    ui->treeWidget_curaan->setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::on_pushButton_gofind_clicked()
{
    if (ui->lineEdit_find_cur->text()!=trUtf8("بحث")){
    ui->pushButton_gofind->setCursor(QCursor(Qt::WaitCursor));
    Findbook->searchInTreeview(ui->treeWidget_curaan,ui->lineEdit_find_cur->text(),0);
    ui->pushButton_gofind->setCursor(QCursor(Qt::ArrowCursor));
}
}

void MainWindow::on_lineEdit_find_cur_textChanged(QString searchString)
{
    if (searchString.isEmpty()){
        Findbook->searchInTreeview(ui->treeWidget_curaan,ui->lineEdit_find_cur->text(),0);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)//codexml souara  //فتح السور فتح الاجزاء
{
    ui->treeWidget_curaan->clear();
    if (index==0){
        Messages->treeChargeJozaa(ui->treeWidget_curaan);
    }else {
        Messages->treeChargeSoura(ui->treeWidget_curaan);
    }
}

void MainWindow::on_pushButton_gotafsir_clicked()//فتح كتاب التفسير
{
    int index=ui->comboBox_tafasir->currentIndex();
    QVariant comboR_data=ui->comboBox_tafasir->itemData(index);
    QString myname = comboR_data.toString().section('/', 0, 0);
    QString myaut = comboR_data.toString().section('/', -1);
    if (!myname.isEmpty())
    {

        open_dataBase(myname,ui->comboBox_tafasir->currentText(),myaut,0);
        m_isTefsir[m_currentIndex]=true;
    }
}

//**treeViewFind---------------------------

void MainWindow::on_actionFindItemUp_triggered()
{
    QTreeWidgetItem *item=ui->treeWidgetFind->currentItem();
    if(!item){ return;}
    Messages->treeviewItemUp(ui->treeWidgetFind);
}

void MainWindow::on_actionFindItemDown_triggered()
{
    QTreeWidgetItem *item=ui->treeWidgetFind->currentItem();
    if(!item){ return;}
    Messages->treeviewItemDown(ui->treeWidgetFind);
}

void MainWindow::on_actionFindDelete_triggered()
{
    QTreeWidgetItem* item=ui->treeWidgetFind->currentItem();
    if(!item){ return;}
    QString text= trUtf8("هل تريد حذف العنصر المحدد");

    int reponse = QMessageBox::warning(this, trUtf8("تنبيه"),text , QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::No){return;}
    Messages->treeviewItemRemove(ui->treeWidgetFind);
}

void MainWindow::on_actionFindSave_triggered()
{

    if (ui->treeWidgetFind->topLevelItemCount()>0){
        QString homeDir=QDir::homePath () ;
        QString fn = QFileDialog::getSaveFileName(this, tr("Save File..."),
                                                  homeDir, trUtf8("xml files (*.xml );"));
        Findbook->findText=m_textfind;
        Findbook->isNassToFind=isNassToFind;
        if( Findbook->saveResultFind(ui->treeWidgetFind,fn)==true){
            QMessageBox::information(this,trUtf8("معلومات"), trUtf8("تمت العملية الحفظ بنجاح"));
        }else{
            QMessageBox::information(this,trUtf8("خطأ"), trUtf8("لا يمكن كتابة الملف"));
        }
    }
}

void MainWindow::on_actionFindLoad_triggered()
{

    QString homeDir=QDir::homePath () ;
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              homeDir, tr("XML files (*.xml);;All files(*)"));
    QFile file(fn);
    if (file.exists()){
        ui->treeWidgetFind->setColumnWidth(0,500);
        ui->treeWidgetFind->setColumnWidth(1,30);
        ui->treeWidgetFind->setColumnWidth(2,50);
        ui->treeWidgetFind->clear();
        Findbook->loadResultFind(ui->treeWidgetFind,fn);
        m_textfind=  Findbook->findText;
        isNassToFind=Findbook->isNassToFind;
        labelTextFind->setText(trUtf8("نص البحث  : ")+m_textfind);
    }
}

//**Animation----------------------------------------

void MainWindow::on_actionAnimGroup_triggered()
{
    ui->stackedWidget_intro->setCurrentWidget(ui->page_anim);

    view->chargeLevelOne();
    view->setFocus();
}

void MainWindow::on_actionAnimHistorie_triggered()
{
     ui->stackedWidget_intro->setCurrentWidget(ui->page_anim);
    int count=0;
    for (int i=0;i<16;i++){
        if (recentFileActs[i]->isVisible()){
            count++;
            view->recentFileActs[i]= recentFileActs[i];
        }
    }
    view->recentNbr=count+1;
    view->chargeRecent();
    view->setFocus();
}

void MainWindow::on_actionTreeD_toggled(bool checked)
{
    view->threeD=checked;
    view->setFocus();
}

void MainWindow::on_lineEdit_textChanged(QString )
{
    if (!ui->lineEdit->text().isNull()|!ui->lineEdit->text().isEmpty()){
        QString myid = ui->lineEdit->text().section('/', 0, 0);
        QString  myname=ui->lineEdit->text().section('/', 1, 1);
        QString myaut= ui->lineEdit->text().section('/',2,2);
        QString mypage= ui->lineEdit->text().section('/', -1);
        open_dataBase(myid, myname,myaut,mypage.toInt());
    }
}

void MainWindow::startAnimationBitaka()
{
#if QT_VERSION >= 0x040600
    QPropertyAnimation *anim = new QPropertyAnimation(labelBetaka, "pos");
    anim->setEasingCurve(QEasingCurve::OutCirc);
    labelBetaka->setWordWrap(true);

    anim->setStartValue(QPointF(0, 0));
    anim->setEndValue(QPointF(300, 0));
    anim->setDuration(500);
    anim->setLoopCount(1); // forever
    anim->start();
#endif
}

void MainWindow::startAnimationPixmap()
{
#if QT_VERSION >= 0x040600
    QPropertyAnimation *anim = new QPropertyAnimation(labelBetaka, "pos");
    anim->setEasingCurve(QEasingCurve::OutBounce);
    labelBetaka->setPixmap(QPixmap(QString::fromUtf8(":/images/image/groupbook.png")));
    anim->setStartValue(QPointF(300,300));
    anim->setEndValue(QPointF(300,0));
    anim->setDuration(1000);
    anim->setLoopCount(1);
    anim->start();
#endif
}

//tabs---------------------------
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QTextBrowser *txtBrowser = ui->tabWidget->widget(index)->findChild<QTextBrowser *>();
    QString name=txtBrowser->objectName();
    QString  str = name.section('_', -1);
    if (!m_bookName[str.toInt()].isEmpty()){                              //حفظ قائمة الكتب السابقة

        if (txtBrowser->document()->isModified()){
            DataBook->updatPage("",txtBrowser->document()->toPlainText(),true);
            m_bookIsModified[str.toInt()]=true;
        }

        if (closeMessages(m_bookTitle[str.toInt()],str.toInt())==false){

            return;
        }

        QVariant idbk=DataBook->currentPosition[DataBook->boocNumIndex];
        Messages->recentChange(m_bookName[str.toInt()],m_bookTitle[str.toInt()],m_bookAuthor[str.toInt()],idbk.toString(),m_recentNbr,m_isTefsir[str.toInt()]);
        Messages->recentCharge();

    }
    m_bookName[str.toInt()]="";
    m_listTab.removeOne(str);
    ui->tabWidget->removeTab(index);
    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(index));
    ui->stackedWidget->setCurrentIndex(ui->tabWidget->currentIndex());
    DataBook->claerBook(str.toInt());
    m_listHistoriePrev[str.toInt()].clear();
    m_listHistorieNext[str.toInt()].clear();
    if (ui->tabWidget->count()>1)
    {
        ui->tabWidget->setTabsClosable(true);
    }else{
        ui->tabWidget->setTabsClosable(false);
    }
}

void MainWindow::on_tabWidget_currentChanged(int )
{
    
    txtBrowserBook = ui->tabWidget->currentWidget()->findChild<QTextBrowser *>();
    QString name=txtBrowserBook->objectName();
    QString  str = name.section('_', -1);
    m_currentIndex=str.toInt();;
    DataBook->boocNumIndex=str.toInt();

    if (ui->tabWidget->count()>1)
    {
        ui->tabWidget->setTabsClosable(true);
    }else{
        ui->tabWidget->setTabsClosable(false);
    }


    if (m_toolEditFahrass[m_currentIndex]==true){
        ui->frameEdit->setVisible(true);//اظهار ادوات التحرير
    }else{
        ui->frameEdit->setVisible(false);
    }
    ui->stackedWidget->setCurrentIndex(ui->tabWidget->currentIndex());

    emit bookAvailable(!m_bookName[m_currentIndex].isEmpty());

    QFont font;
    font.fromString(m_WebFont);
  if (txtBrowserBook->objectName()!="textBrowser_0"){
    //  QMessageBox::information(this,"",txtBrowserBook->objectName());
    txtBrowserBook->setFont(font);

}






}


void MainWindow::tabCreatTabNew()
{ txtBrowserBook = ui->tabWidget->currentWidget()->findChild<QTextBrowser *>();
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/image/booki.png")), QIcon::Normal, QIcon::Off);
    if (ui->tabWidget->count()==10) {
        QMessageBox::information(this,trUtf8("معلومات"),trUtf8("لايمكن فتح اكثر من عشرة السنة"));
        return;
    }
    //*****************************
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;

   // QTextBrowser *textBrowser;
    tab = new QWidget();

    horizontalLayout = new QHBoxLayout(tab);
    horizontalLayout->setSpacing(3);
    horizontalLayout->setContentsMargins(3, 3, 3, 3);
    gridLayout = new QGridLayout();
    gridLayout->setSpacing(0);
 txtBrowserBook = new QTextBrowser(tab);
    if (m_isCadre==true){
        txtBrowserBook->setFrameShape(QFrame::NoFrame);
       tabCreatCadre(gridLayout);
    }


    gridLayout->addWidget(txtBrowserBook, 1, 1, 1, 1);
    horizontalLayout->addLayout(gridLayout);
    ui->tabWidget->addTab(tab,icon,trUtf8("مكتبة القرطاس"));

    //*******************************
    QVariant d;
    for(int r=1;r<10;r++)    //تعريف وحيد للسان الجديد
    {
        d=r;
        if  ( m_listTab.lastIndexOf(d.toString())==-1)
        {
            m_listTab.append(d.toString());
            txtBrowserBook->setObjectName("textBrowser_"+d.toString());
            m_currentIndex=d.toInt();
            break;
        }
    }
    QWidget *firstPageWidget = new QWidget;
    ui->stackedWidget->addWidget(firstPageWidget);
    ui->stackedWidget->setCurrentWidget(firstPageWidget);
    ui->tabWidget->setCurrentWidget(tab);
    //معرفة مربع النص في اللسان النشط
    txtBrowserBook = ui->tabWidget->currentWidget()->findChild<QTextBrowser *>();

    txtBrowserBook->setContextMenuPolicy(Qt::CustomContextMenu);

connect(txtBrowserBook, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(textBrewserCustomMenu()));

connect(txtBrowserBook, SIGNAL(highlighted(const QUrl)), this, SLOT(textBookHighlighted(QUrl)));
    connect(txtBrowserBook, SIGNAL(anchorClicked(const QUrl)), this, SLOT(textBookAnchorClicked(QUrl)));

    connect(txtBrowserBook, SIGNAL(copyAvailable(bool)), ui->actionFahAddChild, SLOT(setEnabled(bool)));
    connect(txtBrowserBook, SIGNAL(copyAvailable(bool)), ui->actionFahAddItem, SLOT(setEnabled(bool)));

    emit bookAvailable(false);
    tabCreatFahrass();
}


void MainWindow::tabCreatFahrass()
{
    QGridLayout *gridLayout;
    gridLayout = new QGridLayout(ui->stackedWidget->currentWidget());
    gridLayout->setSpacing(3);
    gridLayout->setMargin(3);
    treeViewFahras[m_currentIndex] =new QTreeWidget(ui->stackedWidget->currentWidget());
    treeViewFahras[m_currentIndex]->headerItem()->setText(0,"");
    gridLayout->addWidget(treeViewFahras[m_currentIndex],0,0, 1, 1);
    treeViewFahras[m_currentIndex]->show();
    connect(treeViewFahras[m_currentIndex], SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(fahras_itemActivated(QTreeWidgetItem*)));
    connect(treeViewFahras[m_currentIndex], SIGNAL(itemClicked (QTreeWidgetItem* , int )), this, SLOT(fahras_itemClicked(QTreeWidgetItem*)));
    connect(lineEditFindFah, SIGNAL(textChanged(QString)), this, SLOT(searchInTreeFah(QString)));
    connect(AC_expandTreeFah, SIGNAL(triggered()), treeViewFahras[m_currentIndex], SLOT(expandAll()));
    connect(AC_colapsTreeFah, SIGNAL(triggered()),treeViewFahras[m_currentIndex], SLOT(collapseAll()));
}
void MainWindow:: tabCreatCadre(QGridLayout *gridLayout)
{
    QString imgPath=m_pathApp+"/data/images/"+m_CadrFolder;
    if(m_CadrFolder==trUtf8("الافتراضي")){
        imgPath=":/images/image";
    }else{
        QFile file;
        if (!file.exists(imgPath+"/top.png") || !file.exists(imgPath+"/top_right.png")||!file.exists(imgPath+"/left.png")||
            !file.exists(imgPath+"/right.png")||!file.exists(imgPath+"/bot.png")||!file.exists(imgPath+"/bot_right.png")||
            !file.exists(imgPath+"/top_left.png")||!file.exists(imgPath+"/bot_left.png"))
        {  m_CadrFolder=trUtf8("الافتراضي"); imgPath=":/images/image";}

    }

    QPixmap pix(imgPath+"/top_right.png");
    QSize size(pix.width(),pix.height());

    QWidget *frame_top,*frame_topRight,*frame_left, *frame_right,*frame_bot,*frame_botRight,*frame_topLeft,*frame_botLeft;

    frame_top = new QWidget();
    frame_top->setStyleSheet("background-image: url("+imgPath+"/top.png);");

    gridLayout->addWidget(frame_top, 0, 1, 1, 1);

    frame_topRight = new QWidget();
    frame_topRight->setMinimumSize(size);
    frame_topRight->setStyleSheet("background-image: url("+imgPath+"/top_right.png);");

    gridLayout->addWidget(frame_topRight, 0, 0, 1, 1);

    frame_left = new QWidget();
    frame_left->setStyleSheet("background-image: url("+imgPath+"/left.png);");

    gridLayout->addWidget(frame_left, 1, 2, 1, 1);

    frame_right = new QWidget();
    frame_right->setStyleSheet("background-image: url("+imgPath+"/right.png);");

    gridLayout->addWidget(frame_right, 1, 0, 1, 1);

    frame_bot = new QWidget();
    frame_bot->setStyleSheet("background-image: url("+imgPath+"/bot.png);");


    gridLayout->addWidget(frame_bot, 2, 1, 1, 1);

    frame_botRight = new QWidget();
    frame_botRight->setMinimumSize(size);
    frame_botRight->setStyleSheet("background-image: url("+imgPath+"/bot_right.png);");

    gridLayout->addWidget(frame_botRight, 2, 0, 1, 1);

    frame_topLeft = new QWidget();
    frame_topLeft->setMinimumSize(size);
    frame_topLeft->setStyleSheet("background-image: url("+imgPath+"/top_left.png);");

    gridLayout->addWidget(frame_topLeft, 0, 2, 1, 1);

    frame_botLeft = new QWidget();
    frame_botLeft->setMinimumSize(size);
    frame_botLeft->setStyleSheet("background-image: url("+imgPath+"/bot_left.png);");

    gridLayout->addWidget(frame_botLeft, 2, 2, 1, 1);
}

void MainWindow::tabOpenInNewTab()
{
    tabCreatTabNew();
    menuOpenBook();
}

void MainWindow::chargeGroupe()//تحميل شجرة الكتب
{
    Messages->comboGroup=ui->comboBox_tafasir;
    Messages->treeChargeGroupe(ui->treeWidget_books,0,false);
}


//save load other************************************************************


void MainWindow::saveLayou()//حفظ البيانات الى ملف
{
    QSettings settings(m_pathUser+"/data/setting.ini",
                       QSettings::IniFormat);
    // QSettings settings("Kirtasse", "setting");
    settings.beginGroup("MainWindow");
    settings.setValue("style", m_myStyleName);
    settings.setValue("font",  m_WebFont);
    settings.setValue("fontTitle", m_WebFontTitle);
    settings.setValue("fontTitleSize", m_WebFontTitleSize);

    settings.setValue("fontHachia", m_WebFontHachia);
    settings.setValue("bcolor",m_WebColorBack);
    settings.setValue("WebFontColor",m_WebFontColor);
    settings.setValue("WebFontFindColor",m_WebFontFindColor);
    settings.setValue("WebFontPrefertColor",m_WebFontPrefertColor);
    settings.setValue("WebFontTitleColor",m_WebFontTitleColor);
    settings.setValue("recentNbr",m_recentNbr);
    settings.setValue("pathCostm",m_pathCostm);
    settings.setValue("isThreeD",ui->actionTreeD->isChecked());
    settings.setValue("WebCadre",m_isCadre);
    settings.setValue("CadrFolder",m_CadrFolder);
    settings.setValue("geo_data", saveGeometry());
    settings.setValue("layout_data", saveState());
    settings.endGroup();
}

void MainWindow::loadLayout()//load layou
{

    QByteArray layo_data=QByteArray::fromHex("(000000ff00000000fd00000002000000010000010600000276fc0200000001fc0000004000000276000001330007"
                                             "fffffa000000020100000003fb000000220064006f0063006b005700690064006700650074005f0063007500720061006100"
                                             "6e0100000000ffffffff000000b600fffffffb000000220064006f0063006b005700690064006700650074005f00660061006"
                                             "80072006100730100000000ffffffff000000970007fffffb000000200064006f0063006b005700690064006700650074005f0"
                                             "062006f006f006b0073010000045200000106000000780000058c0000000300000558000000c7fc0100000001fc0000000000000"
                                             "5580000000000fffffffaffffffff0200000002fb000000260064006f0063006b005700690064006700650074005f0066006100760"
                                             "06f00720069007400650000000000ffffffff000000aa00fffffffb0000001e0064006f0063006b005700690064006700650074005"
                                             "f00660069006e006400000002490000006d0000006d00ffffff0000044c0000027600000004000000040000000800000008fc000000"
                                             "01000000020000000300000016006d00610069006e0054006f006f006c0042006100720100000000ffffffff00000000000000000000"
                                             "00220074006f006f006c004200610072005f006e006100760065006700610074006f00720100000203ffffffff000000000000000000"
                                             "00001a0074006f006f006c0042006100720072006500630065006e007401000002a9ffffffff0000000000000000)");
      QSettings settings(m_pathUser+"/data/setting.ini",QSettings::IniFormat);

    //****************************
    // QSettings settings("Kirtasse", "setting");
    settings.beginGroup("MainWindow");
    m_myStyleName=settings.value("style","").toString();
#ifdef  Q_WS_X11
    m_WebFont=settings.value("font","KacstBook,20,-1,5,50,0,0,0,0,0").toString();
    m_WebFontTitle=settings.value("fontTitle","KacstTitle").toString();

    m_WebFontHachia=settings.value("fontHachia","KacstBook").toString();
#else
    m_WebFont=settings.value("font","Traditional Arabic,20,-1,5,50,0,0,0,0,0").toString();
    m_WebFontTitle=settings.value("fontTitle","Andalus").toString();
    m_WebFontHachia=settings.value("fontHachia","Traditional Arabic").toString();
#endif
    m_WebFontTitleSize=settings.value("fontTitleSize","20").toString();

    m_WebColorBack=settings.value("bcolor","#F9F9B9").toString();
    m_WebFontColor=  settings.value("WebFontColor","#000000").toString();
    m_WebFontFindColor=settings.value("WebFontFindColor","#aa5500").toString();
    m_WebFontPrefertColor=settings.value("WebFontPrefertColor","#264c00").toString();
    m_WebFontTitleColor=settings.value("WebFontTitleColor","#ff0000").toString();
    m_recentNbr=settings.value("recentNbr",7).toInt();
    m_pathCostm=settings.value("pathCostm",m_pathUser+"/books").toString();
    Messages->m_pathCostum=settings.value("pathCostm",m_pathUser+"/books").toString();

    ui->actionTreeD->setChecked(settings.value("isThreeD",false).toBool())   ;
    m_isCadre=settings.value("WebCadre",true).toBool();
    m_CadrFolder=settings.value("CadrFolder","default").toString();
#if QT_VERSION >= 0x040600
    view->threeD=settings.value("isThreeD",false).toBool();
#endif
    this->restoreGeometry(settings.value("geo_data").toByteArray());
    this->restoreState( settings.value("layout_data",layo_data).toByteArray());
    settings.endGroup();
    QFont font;
    font.fromString(m_WebFont);
  if (txtBrowserBook->objectName()!="textBrowser_0"){
    txtBrowserBook->setFont(font);
}else{
    ui->textBrowser_0->setFontFamily(font.family());
}
    settings.beginGroup("MainWindow");
    QApplication::setStyle(QStyleFactory::create( m_myStyleName));
}

//fahrrase ***  تحرير الفهرسةوالكتاب**********************************
void MainWindow::addItemInTreeFahras(bool child)//اظافة عنصر الى الفهرسة
{
    QString text=txtBrowserBook->textCursor().selectedText();
    if (text.isEmpty()){ return;}
    QTreeWidgetItem *curentitem;//العنصر المحدد
    QTreeWidgetItem *item;//العنصر الذي سنظيفه
    curentitem= treeViewFahras[m_currentIndex]->currentItem();
    if (child==false){ //اظافة عنصر جديد بعد المحدد
        if (!curentitem){                   //اذا لم يكن هناك تحديد سيظاف الى الجذر
            item= new QTreeWidgetItem(treeViewFahras[m_currentIndex]);
        }else{        // اما ان كان هناك عنصر محدد سيظاف بعده
            item= new QTreeWidgetItem(curentitem->parent(),curentitem);
            if (!curentitem->parent()){    //اذا لم يكن له اب سيضاف الى الجذر بعد المحدد
                item= new QTreeWidgetItem(treeViewFahras[m_currentIndex],curentitem);
            }
        }
    }
    if (child==true){             //اظافة ابن الى المحدد
        if (!curentitem){ return;}                   //اذا لم يكن هناك تحديد سيخرج
        item= new QTreeWidgetItem(curentitem);
        if ( item->parent()){
            item->parent()->setExpanded(true);
        }
    }
    item->setText(0,text );

    item->setData(1,1,DataBook->currentPosition[m_currentIndex]+1);
    item->setSelected(true);
    treeViewFahras[m_currentIndex]->setCurrentItem(item);//تفعيل العنصر المظاف
    m_treeFahrasIsModified[m_currentIndex]=true;
}

void MainWindow::saveBookEndFahras()//زر حفظ الفهرسة المحررة
{
    if (m_treeFahrasIsModified[m_currentIndex]==true){
        saveFahrass(m_currentIndex);
    }
    if (m_bookIsModified[m_currentIndex]==true){
        saveCurrentBook(m_currentIndex);
    }
}

void  MainWindow::saveFahrass(int index)
{
    Messages->m_pathCostum=m_pathCostm;
    if ( Messages->fahrasSave(treeViewFahras[index],m_bookName[index])==true){
        QMessageBox::information(this,trUtf8("معلومات"), trUtf8("تمت عملية حفظ الفهرسة بنجاح"));

    }else{
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ في كتابة الملف"));
    }
    m_treeFahrasIsModified[index]=false;
}

//text browser***عمليات على النص**********************************
void MainWindow::textBookAnchorClicked(QUrl txtUrl)
{
    ui->textBrowser_0->setOpenExternalLinks(false);
    ui->textBrowser_0->setOpenLinks(false);
    QString textCode=txtUrl.toString();
    if (textCode.isEmpty()) {return;}
    if (textCode.contains("javascript")){
        ui->textBrowser_0->setOpenLinks(true);
return;
    }
    if (textCode.contains("#*")){
        textCode.remove("#*");
        if (textCode.contains("(")||textCode.contains(":")){
            int t=textCode.indexOf("(",0);
            textCode.remove(t,textCode.length());
            int d=textCode.indexOf(":",0);
            textCode.remove(d,textCode.length());
        }

    Rowat->rawiFind(textCode.trimmed(),ui->treeWidget_rowat,ui->treeWidget_rowatFind);
    showfind(true);

//    m_isRawiToFind=true;

        return;
    }
    if (textCode.contains("http://")){
        ui->textBrowser_0->setOpenLinks(false);
        ui->textBrowser_0->setOpenExternalLinks(false);
        QString nameBk= ui->textBrowser_0->textCursor().block().text();
        QMessageBox::information(this,"name",nameBk +"\n"+ textCode);
        //booksInterface->downloadFile(textCode);

    }else if(textCode.contains("file://")||textCode.contains("javascript")){

        ui->textBrowser_0->setOpenLinks(true);
    }else{

        // QString nameTexte=textCode.section('/', 0,0);
        QString bookTexte=textCode.section('/', 1,1);
        QString authorTexte=textCode.section('/', 2,2);
        QString idBookTexte=textCode.section('/', 3,3);
        QString pageTexte=textCode.section('/', -1);
        QVariant pos=pageTexte;
        if (m_bookName[m_currentIndex]==idBookTexte){
            bookValueChanged(pos.toInt());
        }else{
            open_dataBase(idBookTexte,bookTexte,authorTexte,0);
            bookValueChanged(pos.toInt());
        }
    }
}

void MainWindow::textBookHighlighted(QUrl txtUrl)
{
    QString textCode=txtUrl.toString();
    if (textCode.isEmpty()|| textCode.contains("www.intro")) {
        ui->statusBar->showMessage("");
        return;
    }  
     if (textCode.contains("#*")){
         ui->statusBar->showMessage(textCode.remove("#*"));
         return;
     }
    if (textCode.contains("http://")){     
        ui->textBrowser_0->setOpenExternalLinks(false);
        ui->textBrowser_0->setOpenLinks(false);
        ui->statusBar->showMessage(txtUrl.toString());


    }else if(textCode.contains("file://")){

        ui->textBrowser_0->setOpenLinks(true);
    }else{
        QString nameTexte=textCode.section('/', 0,0);
        QString bookTexte=textCode.section('/', 1,1);
        QString authorTexte=textCode.section('/', 2,2);
        ui->statusBar->showMessage(nameTexte +trUtf8(" كتاب :")+bookTexte+trUtf8(" المؤلف :")+authorTexte);
    }
}

void MainWindow::convertTextToHtml(QString txt)//تحويل بيانات النص
{
    QLocale::setDefault(QLocale(QLocale::Arabic, QLocale::Egypt));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    txtBrowserBook->setLocale(QLocale(QLocale::Arabic, QLocale::Egypt));

    txt.replace(QByteArray("\n"), QByteArray("<br>"));
    txt.replace(QByteArray("\r"), QByteArray("<br>"));
    txt.insert(txt.length(),"</font></body>");
    //*******************************************
    txt.replace("$", "");
    int id=DataBook->currentPosition[m_currentIndex]+1;
    QVariant dd=id;
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            treeViewFahras[m_currentIndex]->findItems(
                    dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);//تنشاء قائمة بكل العناصر

    foreach (item, found){
        treeViewFahras[m_currentIndex]->setCurrentItem(item);
        QString title= " <span style='font-family:"+m_WebFontTitle+";  font-size:"+m_WebFontTitleSize+"pt; color:"+m_WebFontTitleColor+";'>"+item->text(0)+"</span>";
        QString txtItem=item->text(0).trimmed();

        txt.replace( txtItem+"<br>","<br>"+ title+"<br>");
        txt.replace("  "+ txtItem,"<br>"+ title+"<br>");
        // txt.replace("<br> "+ txtItem,"<br>"+title);
        txt.replace("<br>"+ txtItem+"</font>","<br>"+title+"</font>");
        txt.replace( txtItem+" <br>","<br>"+ title+"<br>");
        txt.replace( txtItem+" :","<br>"+ title+":<br>");
        txt.replace( txtItem+":","<br>"+ title+":<br>");
        //  txt.replace( txtItem+".","<br>"+ title+"txt.<br>");
        txt.replace( txtItem+" ؟","<br>"+title+" ؟<br>");
        txt.replace("[ "+ txtItem+" ]","<br>"+title+"<br>");
        txt.replace("["+ txtItem+"]","<br>"+title+"<br>");

        if(txt.trimmed()== txtItem){ //
            txt=title;
        }
    }
    //********************************************xtToHtml
    QRegExp rxi("_____+");
    QRegExp rxd("ـــــ+");
    txt.replace(rxi," < font face='"+m_WebFontHachia+"' size='1'><br>__________");
    txt.replace(rxd," < font  face='"+m_WebFontHachia+"' size='1'><br>__________");
    txt.replace("صلى الله عليه وسلم","< font color='"+m_WebFontPrefertColor+"' >صلى الله عليه وسلم</font> ");
    txt.replace("C تعالى","< font color='"+m_WebFontPrefertColor+"' >رحمه الله تعالى</font> ");
    txt.replace("{","< font color='"+m_WebFontPrefertColor+"' >﴿</font> ");
    txt.replace("}","< font color='"+m_WebFontPrefertColor+"' >﴾</font> ");
    txt.replace("رضي الله عنهم ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنهم </font> "));
    txt.replace("رضي الله عنه ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
    txt.replace("رضي الله عنهما ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("' >رضي الله عنهما </font> "));
    txt.replace(" A ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'> صلى الله عليه سلم </font> "));
    txt.replace("Bه",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
    txt.replace(" D ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>  تعالى </font> "));
    txt.replace(" E ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'> عليه السلام </font> "));
    txt.replace("النبي e",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'> النبي صلى الله عليه سلم </font> "));

    if (txt.contains("**")){
        QRegExp rx("(\\d\\d? )[(]");
        txt.replace(rx,"<br>(");
        QRegExp rx1("(\\d\\d?)[(]");
        txt.replace(rx1,"<br>(");
        txt.replace(") (",")<br>(");
        txt.replace(")(",")<br>(");
    }
    txt.replace("<br><br>","<br>");
    txt.replace("<br> <br>","<br>");
    txt.replace("<br>  <br>","<br>");
    QString bgrcolor = "<body bgcolor='"+m_WebColorBack+"'>< font color='"+m_WebFontColor+"' >";

    if (txtBrowserBook->objectName()!="textBrowser_0"){
       txtBrowserBook->setHtml(bgrcolor+ txt.trimmed() );
  }
}

void MainWindow::saveCurrentBook(int index)
{
    DataBook->boocNumIndex=index;
    if (DataBook->saveBook()==true){
        QMessageBox::information(this,trUtf8("معلومات"), trUtf8("تمت عملية حفظ الكتاب بنجاح"));     
    }
    m_bookIsModified[index]=false;
}

//navigation***التقل بين السجلات*******************************
void MainWindow::bookValueChanged(int pos)//التنقل بين السجلات حسب قيمة
{
    if (m_bookName[m_currentIndex].isEmpty()){
        AC_prevHistorie->setEnabled(false);
        AC_nextHistorie->setEnabled(false);
        return; }
    if(txtBrowserBook->document()->isModified()){
        DataBook->updatPage("",txtBrowserBook->document()->toPlainText().trimmed(),true);
        m_bookIsModified[m_currentIndex]=true;
    }
    DataBook->moveToPosition(pos);
    if (m_listHistoriePrev[m_currentIndex].isEmpty()){
        m_listHistoriePrev[m_currentIndex].append(DataBook->currentPosition[m_currentIndex]);
    }else if( m_listHistoriePrev[m_currentIndex].last()!=DataBook->currentPosition[m_currentIndex]){

        m_listHistoriePrev[m_currentIndex].append(DataBook->currentPosition[m_currentIndex]);
    }
    if ( m_listHistoriePrev[m_currentIndex].count()>1){
        AC_prevHistorie->setEnabled(true);
    }else{
        AC_prevHistorie->setEnabled(false);
    }
    if ( m_listHistorieNext[m_currentIndex].count()>1){
        AC_nextHistorie->setEnabled(true);
    }else{
        AC_nextHistorie->setEnabled(false);
    }
    convertTextToHtml(DataBook->bookNass[m_currentIndex]);
    QString page=DataBook->bookPage[m_currentIndex];
    QString part=DataBook->bookPart[m_currentIndex];

    labelPagePart->setText(trUtf8("الصفحة :")+page +"  "+trUtf8("الجزء :")+part);
    labelProgressInfo->setText(trUtf8(" كتاب : ")+ui->tabWidget->tabText(ui->tabWidget->currentIndex()) +trUtf8(".  المؤلف : ")+m_bookAuthor[m_currentIndex]+". " +labelPagePart->text());
}


void MainWindow::historieNext()
{
    if (m_bookName[m_currentIndex].isEmpty()){  return; }
    if ( m_listHistorieNext[m_currentIndex].isEmpty() ||  m_listHistorieNext[m_currentIndex].count()<1){
        AC_nextHistorie->setEnabled(false);
        return; }
    int p= m_listHistorieNext[m_currentIndex].last();
    m_listHistorieNext[m_currentIndex].removeLast();
    if ( m_listHistorieNext[m_currentIndex].count()<1 ){
        AC_nextHistorie->setEnabled(false);
    }
    m_listHistoriePrev[m_currentIndex].append(p);
    AC_prevHistorie->setEnabled(true);
    DataBook->moveToPosition(p);
    convertTextToHtml(DataBook->bookNass[m_currentIndex]);
    QString page=DataBook->bookPage[m_currentIndex];
    QString part=DataBook->bookPart[m_currentIndex];
    labelPagePart->setText(trUtf8("الصفحة :")+page +"  "+trUtf8("الجزء :")+part);
    labelProgressInfo->setText(trUtf8(" كتاب : ")+ui->tabWidget->tabText(ui->tabWidget->currentIndex()) +trUtf8(".  المؤلف : ")+m_bookAuthor[m_currentIndex]+". " +labelPagePart->text());

}

void MainWindow::historiePrev()
{
    if (m_bookName[m_currentIndex].isEmpty()){  return; }
    if ( m_listHistoriePrev[m_currentIndex].isEmpty() || m_listHistoriePrev[m_currentIndex].count()<2){
        AC_prevHistorie->setEnabled(false);
        return; }

    int p=  m_listHistoriePrev[m_currentIndex].last();
    m_listHistoriePrev[m_currentIndex].removeLast();
    if ( m_listHistoriePrev[m_currentIndex].count()<2)
    {
        AC_prevHistorie->setEnabled(false);
    }
    m_listHistorieNext[m_currentIndex].append(p);
    AC_nextHistorie->setEnabled(true);

    int i=  m_listHistoriePrev[m_currentIndex].last();
    DataBook->moveToPosition(i);
    convertTextToHtml(DataBook->bookNass[m_currentIndex]);
    QString page=DataBook->bookPage[m_currentIndex];
    QString part=DataBook->bookPart[m_currentIndex];
    labelPagePart->setText(trUtf8("الصفحة :")+page +"  "+trUtf8("الجزء :")+part);
    labelProgressInfo->setText(trUtf8(" كتاب : ")+ui->tabWidget->tabText(ui->tabWidget->currentIndex()) +trUtf8(".  المؤلف : ")+m_bookAuthor[m_currentIndex]+". " +labelPagePart->text());
}
//find***عمليات البحث***********************************


void MainWindow::find_favo_textChanged(QString searchString)//البحث في شجرة المفضلة
{
    if (searchString!=trUtf8("بحث"))
    Findbook->searchInTreeview(ui->treeWidget_fav,searchString,0);
}
void MainWindow::searchInTreeFah(QString searchString)//البحث في شجرة الفهرسة
{
    if (searchString!=trUtf8("بحث"))
    Findbook->searchInTreeview(treeViewFahras[m_currentIndex],searchString,0);
}
void MainWindow::searchInTreeBook(QString searchString)//البحث في شجرة الكتب
{
    int colum=0;
    if (m_findIsTitle==false){
        colum=1;
    }
    if (searchString!=trUtf8("بحث"))
    Findbook->searchInTreeview(ui->treeWidget_books,searchString,colum);
}
void MainWindow::showResultFind(QTreeWidgetItem* item)//تفعيل عناصر شجرة البحث
{

    QVariant bkpage=item->data(0,1);

    QString x = item->data(3,1).toString();
    open_dataBase(x,item->text(3),item->text(4),bkpage.toInt()-1);
     bookValueChanged(bkpage.toInt()-1);
    m_isTefsir[m_currentIndex]=item->data(2,1).toBool();

    if(isNassToFind==true){
        Findbook->searchInDoc( txtBrowserBook->document(),m_textfind,QColor(m_WebFontFindColor));
    }else{
        QTreeWidgetItem *itemF=new QTreeWidgetItem;
        QList<QTreeWidgetItem *> found = treeViewFahras[m_currentIndex]->findItems(  item->text(0),Qt::MatchExactly | Qt::MatchRecursive,0);
        foreach (itemF, found){ treeViewFahras[m_currentIndex]->setCurrentItem(itemF); }
    }
}
void MainWindow::findInCurrentBook()//البحث في الكتاب الحالي
{
    Findbook->pathCostum= m_bookPath[m_currentIndex] ;
    if (Findbook->isFindRuned==true){ return;}
    if (m_bookName[m_currentIndex].isEmpty())  { return;}
    if (lineEditSearchInDoc->text().isEmpty()){ return;}
    m_textfind=lineEditSearchInDoc->text();

     showfind(false);

    labelTextFind->setText(trUtf8("نص البحث  : ")+m_textfind);
    progressBarFind->setMaximum(DataBook->rowsCount[m_currentIndex]);
    progressBarFind->setVisible(true);
  //  BtnStopFind->setVisible(true);
     ui->action_stopFind->setVisible(true);
    Findbook->findMultiFind=false;
    Findbook->findSawabik=true;
    Findbook->findToList=false;
    Findbook->resultCount=0;
    Findbook->isTefsir=m_isTefsir[m_currentIndex];
    Findbook-> findTitle=m_bookTitle[m_currentIndex];
    Findbook-> findAuthor=m_bookAuthor[m_currentIndex];
    Findbook-> findName=m_bookName[m_currentIndex];
    Findbook->findText=m_textfind;
    Findbook->progressBar1=progressBarFind;
    Findbook->label_progressImg=labelProgressImg;
   // Findbook->pushButtonStop=BtnStopFind;
    Findbook->buttonStop= ui->action_stopFind;
    Findbook->treeView=ui->treeWidgetFind;
   Findbook->isNassToFind=true;
   isNassToFind=true;

ui->treeWidgetFind->clear();
   // QToolTip::showText(QPoint (ui->statusBar->width(),ui->statusBar->pos().y()),trUtf8("يمكنك ايقاف عملية البحث هنا"),BtnStopFind);
//  m_isRawiToFind=false;
   Findbook->findOneBook(m_bookPath[m_currentIndex]);
  
}
void MainWindow::findBookOrHautor()//البحث عن كتاب
{
    if (ui->actionFindBkOrHt->isChecked()){
        ui->actionFindBkOrHt->setToolTip(trUtf8("البحث عن مؤلف"));
        m_findIsTitle=false;
    }else{
        ui->actionFindBkOrHt->setToolTip(trUtf8("البحث عن كتاب"));
        m_findIsTitle=true;
    }
}

void MainWindow::stopFind()//توقيف عملية البحث
{
    Findbook ->stopFind=true;
}

void MainWindow::searchIndoc()
{
    if (!lineEditSearchInDoc->text().isEmpty())
    {
        Findbook->findToList=false;
        if (Findbook->searchInDoc( txtBrowserBook->document(),lineEditSearchInDoc->text(),QColor(m_WebFontFindColor))==false)
        {
            QMessageBox::information(this,trUtf8("معلومات"), trUtf8("النص غير موجود في الصفحة"));
        }
    }
}

void MainWindow::printPreview(QPrinter *printer)
{
#ifdef QT_NO_PRINTER
    Q_UNUSED(printer);
#else
    txtBrowserBook->print(printer);
#endif
}

void MainWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action){

        QVariant txtdata=action->data();
        QString myid = txtdata.toString().section('/', 0, 0);
        QString myaut= txtdata.toString().section('/', 2,2);
        QString  myname=txtdata.toString().section('/', 1, 1);
        QVariant  mytefsir=txtdata.toString().section('/', -1);
        open_dataBase(myname,action->text(),myaut,myid.toInt());
        m_isTefsir[m_currentIndex]=mytefsir.toBool();
    }
}
///*********************plugins********************
/*bool MainWindow::loadPlugin()
{
    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
          booksInterface = qobject_cast<BooksInterface *>(plugin);
            if (booksInterface)
                return true;
        }
    }
    return false;
}*/






void MainWindow::on_comboBox_rowat_currentIndexChanged(int index)
{
    ui->stackedWidget_books->setCurrentIndex(index);
    if (index==1){
        if(ui->treeWidget_rowat->topLevelItemCount()<1)
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            Rowat->treeChargeRowtName(ui->treeWidget_rowat);
           // Rowat->chargeRowat();
            // Rowat->openXml();
             QApplication::restoreOverrideCursor();
         }else{
       on_actionPageIntro_triggered();
         }


}

void MainWindow::on_lineEdit_FindRowat_textChanged(QString searchString)
{
    if (searchString!=trUtf8("بحث"))
    Findbook->searchInTreeview(ui->treeWidget_rowat,searchString,0);
}


void MainWindow::on_treeWidget_rowat_itemActivated(QTreeWidgetItem* item, int )
{
     ui->treeWidget_rowatFind->setVisible(false);
     openRawi(item,true);

}
void MainWindow::openRawi(QTreeWidgetItem* item,bool addToTataboa)
{
    int pos=item->data(1,1).toInt();

    if( ui->tabIntro->isHidden())  {

        ui->tabWidget->insertTab(0,ui->tabIntro,trUtf8("مكتبة القرطاس"));
        ui->stackedWidget->insertWidget(0,ui->pageIntro);
        ui->tabWidget->setCurrentWidget(ui->tabIntro);
    }
    ui->stackedWidget_intro->setCurrentWidget(ui->page_text);
    
    labelAnim->setText(trUtf8("تراجم الرواة"));
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    ui->textBrowser_0->setHtml(Rowat->readxml(pos));
    //    ui->textBrowser_0->setHtml(Rowat->moveToPosition(pos));

    QApplication::restoreOverrideCursor();
    if (addToTataboa==true){

        QTreeWidgetItem *itemR=new QTreeWidgetItem;
        QList<QTreeWidgetItem *> foundR =
                ui->treeWidget_rowatTabia->findItems(
                        item->text(0),Qt::MatchExactly,0);//تنشاء قائمة بكل العناصر

        foreach (itemR, foundR){
            ui->treeWidget_rowatTabia->setCurrentItem(itemR);
            return;
        }
        QTreeWidgetItem *itemF=new QTreeWidgetItem(ui->treeWidget_rowatTabia);
        itemF->setText(0,item->text(0));
        itemF->setData(1,1,ui->textBrowser_0->toHtml());
       ui->treeWidget_rowatTabia->setCurrentItem(itemF);

    }
}

void MainWindow::on_treeWidget_rowatTabia_itemActivated(QTreeWidgetItem* item, int )
{
    ui->treeWidget_rowatFind->setVisible(false);
    ui->textBrowser_0->setHtml(item->data(1,1).toString());
}
void MainWindow::showfind(bool isrowat)
{
      //  ui->treeWidgetFind->clear();
    if (isrowat==true){
        if (ui->treeWidget_rowatFind->topLevelItemCount()==1){
             openRawi(ui->treeWidget_rowatFind->topLevelItem(0),true);
             ui->treeWidget_rowatFind->setVisible(false);
              ui->treeWidget_rowatFind->clear();
         }else if  (ui->treeWidget_rowatFind->topLevelItemCount()>1){
             ui->treeWidget_rowatFind->setVisible(true);
         }else{
              ui->treeWidget_rowatFind->setVisible(false);
              ui->treeWidget_rowatFind->clear();
//              سعيد بن أبى هلال الليثى مولاهم//
              QMessageBox::information(this,trUtf8("تراجم"),trUtf8("ربما لم يترجم له في التهذيبين \n حاول البحث عنه في مربع البحث اعلى قائمة الرواة"));
         }
    }else{
        ui->treeWidgetFind->setColumnWidth(0,500);
        ui->treeWidgetFind->setColumnWidth(1,30);
        ui->treeWidgetFind->setColumnWidth(2,50);
ui->toolBarFind->setVisible(true);
 ui->dockWidget_find->setShown(true);
    }

}

void MainWindow::on_treeWidget_rowatFind_itemActivated(QTreeWidgetItem* item, int )
{

        openRawi(item,true);

}



void MainWindow::on_btnRowaInfo_clicked()
{
    QString romoz=trUtf8(
                         "<span style=\"color:#ff0000;\">خ</span>=البخاري , <span style=\"color:#ff0000;\">م</span>=مسلم , <span style=\"color:#ff0000;\">د</span>=أبو داود , <span style=\"color:#ff0000;\">ت</span>=الترمذي , <span style=\"color:#ff0000;\">س</span> =النسائي , <span style=\"color:#ff0000;\"><span style=\"color:#ff0000;\">ق</span></span>=ابن ماجه<br>"
                         "<span style=\"color:#ff0000;\">بخ</span> =البخاري في الأدب المفرد , <span style=\"color:#ff0000;\">عخ</span> =البخاري في خلق أفعال العباد<br>"
                         "<span style=\"color:#ff0000;\">سي</span>=النسائي في عمل اليوم والليلة, <span style=\"color:#ff0000;\">ي</span> =البخاري في جزء رفع اليدين<br>"
                         "<span style=\"color:#ff0000;\">عس</span>= النسائي في مسند علي                      , <span style=\"color:#ff0000;\">مد</span>=أبو داود في المراسيل<br>"
                         "<span style=\"color:#ff0000;\">تمييز</span>=لم يخرج له أحد من الستة                 , <span style=\"color:#ff0000;\">فق</span>=ابن ماجه في التفسير<br>"
                         "<span style=\"color:#ff0000;\">خت</span> = البخاري تعليقا                     ,  <span style=\"color:#ff0000;\">صد</span>=أبو داود في فضائل الأنصار<br>"
                         "<span style=\"color:#ff0000;\">خد</span>=أبو داود في الناسخ والمنسوخ                ,  <span style=\"color:#ff0000;\">ل</span>=أبو داود في المسائل<br>"
                         "<span style=\"color:#ff0000;\">ص</span>=النسائي في خصائص علي            , <span style=\"color:#ff0000;\">ر</span>=البخاري في جزء القراءة خلف الإمام<br>"
                         "<span style=\"color:#ff0000;\">كن</span>=النسائي في مسند مالك , <span style=\"color:#ff0000;\">تم</span>=الترمذي في الشمائل , <span style=\"color:#ff0000;\">قد</span>=أبو داود في القدر"
);
    QMessageBox::information(this,trUtf8("رموز كتب السنة"),romoz);
}

void MainWindow::textBrewserCustomMenu()
{

    QMenu *menu=txtBrowserBook->createStandardContextMenu();
    menu->setLayoutDirection(Qt::RightToLeft);
    menu->addSeparator();

    menu->addAction(ui->action_next);
    menu->addAction(ui->action_prev);
    menu->addAction(ui->action_first);
    menu->addAction(ui->action_last);

    menu->exec(QCursor::pos());
}
