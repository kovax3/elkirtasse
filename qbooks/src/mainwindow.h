<<<<<<< HEAD
/****************************************************************************
//   elkirtasse Copyright (C) 2010 yahia abouzakaria <yahiaui@gmail.com>
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
** If you have questions regarding the use of this file, please contact
** abouzakaria (yahiaui@gmail.com)
** $elkirtasse_END_LICENSE$
**
****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "messages.h"
#include "findbook.h"
#include "databook.h"
#include "classwizard.h"
//#include "rowat.h"
#include "booksInterface.h"
#include "toolrubon.h"
#if QT_VERSION >= 0x040600
    #include "animation.h"
#endif

#include <QTextBrowser>
#include <QtGui/QMainWindow>
#include <QTreeWidgetItem>
#include <QDomDocument>
 #include <QStandardItem>
class QLabel;
class QTreeWidget;
class QLabel;
class QProgressBar;
class QComboBox;
class QPushButton;
class QLineEdit;


namespace Ui
{
    class MainWindowClass;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    messages *Messages;
    findbook *Findbook;
    ClassWizard *Wizard;
    //rowat *Rowat;
    NetInterface *netInterface;
    RowatInterface *rowatInterface;
    ShamilaInterface *shamilaInterface;
#if QT_VERSION >= 0x040600
    View *view;
#endif
public:
    MainWindow(QWidget *parent=0);
    ~MainWindow();
    databook *DataBook;

protected:
    virtual void closeEvent(QCloseEvent *e);
     bool eventFilter(QObject *obj, QEvent *ev);
         void changeEvent(QEvent *e);
signals:
    void bookAvailable(bool );
private:
    Ui::MainWindowClass *ui;
    //BooksInterface *booksInterface;
    //QGraphicsScene m_scene;
    toolrubon *toolRubon;

    int m_currentIndex  ;
   // enum  { NumIndex = 10};
  // enum { MaxRecentFiles = 15 };
    static const int NumIndex=10 ;
    static const int MaxRecentFiles=16 ;
    int m_recentNbr;
    QTextBrowser *txtBrowserBook;

    QIcon m_icondir;
    QIcon m_icondfile;
    QIcon m_iconbook;
    QIcon m_iconaut;
    QIcon m_iconGroup;

    QTreeWidget *treeViewFahras[NumIndex];

    QLineEdit *lineEditSearchInDoc;
    QLineEdit *lineEditFindFah;


    QAction *AC_nextHistorie;
    QAction *AC_prevHistorie;
    QAction *recentFileActs[MaxRecentFiles];
    QAction *AC_GoSearchInDoc;
    QAction *AC_GoSearchInCurBook;
    QAction *AC_bookRemove;                    //قائمة حذف الكتاب
    QAction *AC_bookOpenInNewTab;
    QAction *AC_bookRename;
      QAction *AC_bookDownload;
    QAction *AC_bookOpen;                      //قائمة فتح كتاب
    QAction *AC_bookUpdat;                     //قائمة تعديل معلومات الكتاب
    QAction *AC_bookPath;
    QAction *AC_groupeRemove;
    QAction *AC_groupeAdd;
    QAction *AC_categorieAdd;
    QAction *AC_groupeRename;
    QAction *AC_colapsTreeFah;
    QAction *AC_expandTreeFah;

    QPushButton *BtnStopFind;

    QLabel *labelPagePart;                         //عنوان الصفحة
    QLabel *labelProgressInfo;                //معلومات عن الكتاب المفتوح
    QLabel *labelProgress;                     //عنوان شريط المعلومات
    QLabel *labelProgressImg;
   // QLabel *labelBetaka;
    QLabel *labelAnim;
    QLabel *labelTextFind;

    QProgressBar *progressBarFind;                   //شريط الحالة للبحث

    QString m_textfind;                           //النص الذي يتم البحث عنه
    QString m_pathUser;                               //مسار البرنامج
    QString m_pathApp;
    QString m_pathCostm;
    QString m_bookName[NumIndex];                          //اسم مسار الكتاب الحالي
    QString m_bookTitle[NumIndex];                         //اسم الكتاب الحالي
    QString m_bookAuthor[NumIndex];                        //اسم المؤلف
    QString m_bookBetaka[NumIndex];
    QString m_bookPath[NumIndex];
    QString m_myStyleName;                            //السمة الحالية
bool m_isStyleCostum;
QString m_styleCostum;
    QString m_WebColorBack;                           //لون خلفية النص
    QString m_WebFont;                            //نوع النص
    QString m_WebFontTitle;
    QString m_WebFontTitleSize;
    QString m_WebFontHachia;
    QString m_WebFontKhase;
    QString m_WebFontColor;
    QString m_WebFontTitleColor;
    QString m_WebFontFindColor;
    QString m_WebFontPrefertColor;
    QString m_netBooklist;
    QString m_netBooklistVer;
QString m_CadrFolder;
QList<QString > listLineEditName;
    QList<QString> m_listTab;
    QList<int> m_listHistorieNext[NumIndex];
    QList<int> m_listHistoriePrev[NumIndex];
    bool isNassToFind;
    bool m_isTefsir[NumIndex];                                //هل كتاب التفسير يحتوي على فهرسة الايات والسور
    bool m_treeFahrasIsModified[NumIndex];
    bool m_toolEditFahrass[NumIndex];
    bool m_bookIsModified[NumIndex];
    bool m_treeGroupIsModified;
    bool m_findIsTitle;
bool m_iconsThemes;
    bool m_isCadre;
int m_lng;
bool     m_layouDir;
int m_arabicNmber;
 bool  m_isStandardToolBar;
 int m_toolIconSize;
 bool m_textUnderIcon;

 QList<QAction *>*m_listActions;
 QList<QVariant >m_listActToAdd;
public slots:

private slots:

//**menuFile**




    void on_actionDownloadBooks_triggered();
    void on_actionCreatNewBook_triggered();
    void on_actionFontCostum_triggered();
    void on_actionRemovePage_triggered();
    void on_actionNewPageBefor_triggered();
    void on_actionNewPageAfter_triggered();

    void on_btnGoFindFah_clicked();
    void on_action_import_triggered();        //استراد ملفات نصية
    void on_actionMdb_triggered();            //كتب الشاملة
    void on_action_addBoook_triggered();      //تنفيذ نافذة اظافة كتاب
    void on_actionExport_triggered();         //تصدير الكتب
    void on_actionArchive_triggered();        //ضغط الكتاب
    void on_actionBookInfo_triggered();       //معلومات الكتاب الحالي
    void on_actionNewTab_triggered();         //لسان جديد
    void on_actionPrint_triggered();          //الطباعة
    void on_actionPrintPreview_triggered();   //معاينة قبل الطباعة
    void on_action_close_triggered();         //خروج
 //**menuEdit**
    void on_action_first_triggered();            //الصفحة الاولى
    void on_action_next_triggered();             //الصفحة التالية
    void on_action_prev_triggered();             //الصفحة السابقة
    void on_action_last_triggered();             //اخر صفحة
    void on_actionGotoPage_triggered();          //التنقل الى صفحة معينة
    //--------
    void on_actionFind_all_triggered();        //تنفيذ البحث في مجموعة كتب
    //----------
    void on_action_edit_triggered();          //زر وقائمة تفعيل التحرير
    void on_action_favorit_triggered();       //اضف للمفضلة
    void on_actionHiperlink_triggered();      //ارتباط تشعبي
    //---------
    void on_actionOrganizeFahrasse_triggered(); //ضبط روابط الفهرسة
    //---------
    void on_actionUpdatGroupRemove_triggered(); //حذف الكتب الغير متوفرة
    void on_actionUpdatGroup_triggered();       //تمييز الكتب الغير متوفرة
//**menuView**

    void on_action_fulscreen_triggered();       //ملأ الشاشة
    void on_actionOption_triggered();           //خيارات
    void on_actionRemoveTechkil_triggered();    //التشكيل
    void on_actionZoomOut_triggered();
    void on_actionZoumIn_triggered();
    //------------
    void on_actionPageIntro_triggered();        //صفحة البداية
//**menuHelp**
    void on_action_about_triggered();           //حول البرنامج
    void on_actionHelp_triggered();             //التعليمات
//void on_actionHtmlFile_triggered();          //تحميل الكتب
 void on_actionWhatsThis_triggered();
//**treeViewBook**
    void on_treeWidget_books_itemSelectionChanged();                    //عند تغير التحديد في شجرة الكتب
    void on_treeWidget_books_itemActivated(QTreeWidgetItem* item);      //تفعيل عنصر شجرة  الكتب
    void on_treeWidget_books_customContextMenuRequested();       //انشاء قائمة لشجرة الكتب
    void menuOpenBook();                           //تنفيذ قائمة فتح الكتاب
    void menu_BookRemove();                   //تنفيذ عملية حذف الكتاب
    void menu_BookUpdat();                    //تحرير بيانات الكتاب
    void menu_BookPath();                    //معرفة مسار الكتاب
    void menu_renameBook();                  //اعادة تسمية دليل الكتاب
    void menu_GroupeAdd();                   //اضافة مجموعة جديدة
    void menu_CategorieAdd();                //اضافة قسم جديد
    void menu_Add(bool categorie);           //
    void menu_GroupeRemove();                //حذف المجموعة
    void menu_GroupeRename();                //تسمية المجموعة
    void menu_downloadBook();
    //**treeViewFahras**
    void fahras_itemActivated(QTreeWidgetItem* item);    //تفعيل عنصر شجرة الفهرسة
    void fahras_itemClicked(QTreeWidgetItem* item);       //النقر على عنوان الفهرسة
    void on_pushButtonEditClose_clicked();
    void itemFahrasAddChild();
    void itemFahrasAdd();
    void itemFahrasRename();
    void itemFahrasMoveUp();          //نقل عنصر للاعلى في الفهرسة
    void itemFahrasMoveDown();        //للاسفل
    void itemFahrasRemove();      //حذف العنصر

//**treeViewFavorit**
    void on_treeWidget_fav_itemActivated(QTreeWidgetItem* item);
    void on_actionFavItemRen_triggered();
    void on_actionFavItemDown_triggered();
    void on_actionFavItemUp_triggered();
    void on_actionFavDelete_triggered();
    void on_actionFavSave_triggered();
    void find_favo_textChanged(QString );  //البحث في شجرة المفضلة

//**treeVeiwCuran**
    void on_treeWidget_curaan_itemActivated(QTreeWidgetItem* item);     //تفعيل عنصر شجرة القرءان الكريم
    void on_pushButton_gofind_clicked();
    void on_lineEdit_find_cur_textChanged(QString );
    void on_comboBox_currentIndexChanged(int index);             //تحميل الاجزاء او السور
    void on_pushButton_gotafsir_clicked();          //تحمبل كتاب التفسير

//**treeViewFind**
    void showResultFind(QTreeWidgetItem* item);         //النقر على عنصر شجرة نتائج البحث
    void on_actionFindDelete_triggered();
    void on_actionFindItemDown_triggered();
    void on_actionFindItemUp_triggered();
    void on_actionFindLoad_triggered();
    void on_actionFindSave_triggered();

//**Animation**
    void on_actionTreeD_toggled(bool );
    void on_actionAnimHistorie_triggered();
    void on_actionAnimGroup_triggered();
    void on_lineEdit_textChanged(QString );
  //  void startAnimationBitaka();
    //void startAnimationPixmap();

//**tabs**
    void on_tabWidget_tabCloseRequested(int index);
    void on_tabWidget_currentChanged(int );

     void tabCreatFahrass();
     void tabCreatTabNew();
     void tabOpenInNewTab();
void tabCreatCadre(QGridLayout *gridLayout);

//rowat
void on_btnRowaInfo_clicked();
void on_treeWidget_rowatFind_itemActivated(QTreeWidgetItem* item, int );
void showfind(bool isrowat);
void on_treeWidget_rowatTabia_itemActivated(QTreeWidgetItem* item, int );
void openRawi(QTreeWidgetItem* item,bool addToTataboa);
void on_treeWidget_rowat_itemActivated(QTreeWidgetItem* item, int );
void on_lineEdit_FindRowat_textChanged(QString searchString);
void on_comboBox_rowat_currentIndexChanged(int index);

//-********functions**************

void historieNext();
void historiePrev();
void openRecentFile();
void findInCurrentBook();              //البحث في الكتاب الحالي
void addToolRubonBar(bool rubon);
void chargeIconsThemes();
bool loadPlugin();
bool loadPluginRowat();
bool loadPluginCdrom();
    void printPreview(QPrinter *printer);
    void saveFahrass(int index);
   // bool loadPlugin();

    void open_dataBase(QString name,QString title,QString Autor,int position);  //فتح الكتاب المحدد

    bool closeMessages(QString title,int index);

    void findBookOrHautor();                    // مؤلف البحث عن كتاب
    void searchInTreeFah(QString );//البحث في شجرة الفهرسة
    void searchInTreeBook(QString );        //البحث في شجرة الكتب

    void stopFind();                  //توقيف عملية البحث
    void searchIndoc();                 //البحث في الصفحة الحالية
    //عمليات التحميل
    void chargeGroupe();                //تحميل مجموعة الكتب
    void updateIconEndAction();
    //عمليات السمات والموضع والاحجام
    void saveLayou();                     //حفظ البيانات للموضع والسمة
    void loadLayout();                    //تحميل بيانات
    void creatStyle();

    void bookValueChanged(int pos);          //تغير رقم السبين للتنقل بين الصفحات

    void saveCurrentBook(int index);
    // fahrasse عمليات تحرير الفهرسة

    void addItemInTreeFahras(bool child);              //اظافة عنصر الى الفهرسة
      //******
    void saveBookEndFahras();//حفظ الفهرسة
    //عملية تحويل النصوص
    void convertTextToHtml(QString txt);           //عملية تحويل النص
    void textBookHighlighted(QUrl );
    void textBookAnchorClicked(QUrl );
    void textBrewserCustomMenu();


    void on_actionShamilaCdrom_triggered();

    void on_actionControle_triggered();
    void on_actionDvd_triggered();
    void on_actionCostumActions_triggered();
};

#endif // MAINWINDOW_H
=======
/****************************************************************************
//   elkirtasse Copyright (C) 2010 yahia abouzakaria <yahiaui@gmail.com>
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
** If you have questions regarding the use of this file, please contact
** abouzakaria (yahiaui@gmail.com)
** $elkirtasse_END_LICENSE$
**
****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "messages.h"
#include "findbook.h"
#include "databook.h"
#include "classwizard.h"
//#include "rowat.h"
#include "booksInterface.h"

#if QT_VERSION >= 0x040600
    #include "animation.h"
#endif

#include <QTextBrowser>
#include <QtGui/QMainWindow>
#include <QTreeWidgetItem>
#include <QDomDocument>
 #include <QStandardItem>
class QLabel;
class QTreeWidget;
class QLabel;
class QProgressBar;
class QComboBox;
class QPushButton;
class QLineEdit;


namespace Ui
{
    class MainWindowClass;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    messages *Messages;
    findbook *Findbook;
    ClassWizard *Wizard;
    //rowat *Rowat;
    NetInterface *netInterface;
    RowatInterface *rowatInterface;
    ShamilaInterface *shamilaInterface;
#if QT_VERSION >= 0x040600
    View *view;
#endif
public:
    MainWindow(QWidget *parent=0);
    ~MainWindow();
    databook *DataBook;

protected:
    virtual void closeEvent(QCloseEvent *e);
     bool eventFilter(QObject *obj, QEvent *ev);
         void changeEvent(QEvent *e);
signals:
    void bookAvailable(bool );
private:
    Ui::MainWindowClass *ui;
    //BooksInterface *booksInterface;
    //QGraphicsScene m_scene;

    int m_currentIndex  ;
   // enum  { NumIndex = 10};
  // enum { MaxRecentFiles = 15 };
    static const int NumIndex=10 ;
    static const int MaxRecentFiles=16 ;
    int m_recentNbr;
    QTextBrowser *txtBrowserBook;

    QIcon m_icondir;
    QIcon m_icondfile;
    QIcon m_iconbook;
    QIcon m_iconaut;
    QIcon m_iconGroup;

    QTreeWidget *treeViewFahras[NumIndex];

    QLineEdit *lineEditSearchInDoc;
    QLineEdit *lineEditFindFah;


    QAction *AC_nextHistorie;
    QAction *AC_prevHistorie;
    QAction *recentFileActs[MaxRecentFiles];
    QAction *AC_GoSearchInDoc;
    QAction *AC_GoSearchInCurBook;
    QAction *AC_bookRemove;                    //قائمة حذف الكتاب
    QAction *AC_bookOpenInNewTab;
    QAction *AC_bookRename;
    QAction *AC_bookOpen;                      //قائمة فتح كتاب
    QAction *AC_bookUpdat;                     //قائمة تعديل معلومات الكتاب
    QAction *AC_bookPath;
    QAction *AC_groupeRemove;
    QAction *AC_groupeAdd;
    QAction *AC_categorieAdd;
    QAction *AC_groupeRename;
    QAction *AC_colapsTreeFah;
    QAction *AC_expandTreeFah;

    QPushButton *BtnStopFind;

    QLabel *labelPagePart;                         //عنوان الصفحة
    QLabel *labelProgressInfo;                //معلومات عن الكتاب المفتوح
    QLabel *labelProgress;                     //عنوان شريط المعلومات
    QLabel *labelProgressImg;
   // QLabel *labelBetaka;
    QLabel *labelAnim;
    QLabel *labelTextFind;

    QProgressBar *progressBarFind;                   //شريط الحالة للبحث

    QString m_textfind;                           //النص الذي يتم البحث عنه
    QString m_pathUser;                               //مسار البرنامج
    QString m_pathApp;
    QString m_pathCostm;
    QString m_bookName[NumIndex];                          //اسم مسار الكتاب الحالي
    QString m_bookTitle[NumIndex];                         //اسم الكتاب الحالي
    QString m_bookAuthor[NumIndex];                        //اسم المؤلف
    QString m_bookBetaka[NumIndex];
    QString m_bookPath[NumIndex];
    QString m_myStyleName;                            //السمة الحالية
    QString m_WebColorBack;                           //لون خلفية النص
    QString m_WebFont;                            //نوع النص
    QString m_WebFontTitle;
    QString m_WebFontTitleSize;
    QString m_WebFontHachia;
    QString m_WebFontKhase;
    QString m_WebFontColor;
    QString m_WebFontTitleColor;
    QString m_WebFontFindColor;
    QString m_WebFontPrefertColor;
    QString m_netBooklist;
    QString m_netBooklistVer;
QString m_CadrFolder;
QList<QString > listLineEditName;
    QList<QString> m_listTab;
    QList<int> m_listHistorieNext[NumIndex];
    QList<int> m_listHistoriePrev[NumIndex];
    bool isNassToFind;
    bool m_isTefsir[NumIndex];                                //هل كتاب التفسير يحتوي على فهرسة الايات والسور
    bool m_treeFahrasIsModified[NumIndex];
    bool m_toolEditFahrass[NumIndex];
    bool m_bookIsModified[NumIndex];
    bool m_treeGroupIsModified;
    bool m_findIsTitle;
bool m_iconsThemes;
    bool m_isCadre;
int m_lng;
bool     m_layouDir;
int m_arabicNmber;
public slots:

private slots:

//**menuFile**




    void on_actionDownloadBooks_triggered();
    void on_actionCreatNewBook_triggered();
    void on_actionFontCostum_triggered();
    void on_actionRemovePage_triggered();
    void on_actionNewPageBefor_triggered();
    void on_actionNewPageAfter_triggered();

    void on_btnGoFindFah_clicked();
    void on_action_import_triggered();        //استراد ملفات نصية
    void on_actionMdb_triggered();            //كتب الشاملة
    void on_action_addBoook_triggered();      //تنفيذ نافذة اظافة كتاب
    void on_actionExport_triggered();         //تصدير الكتب
    void on_actionArchive_triggered();        //ضغط الكتاب
    void on_actionBookInfo_triggered();       //معلومات الكتاب الحالي
    void on_actionNewTab_triggered();         //لسان جديد
    void on_actionPrint_triggered();          //الطباعة
    void on_actionPrintPreview_triggered();   //معاينة قبل الطباعة
    void on_action_close_triggered();         //خروج
 //**menuEdit**
    void on_action_first_triggered();            //الصفحة الاولى
    void on_action_next_triggered();             //الصفحة التالية
    void on_action_prev_triggered();             //الصفحة السابقة
    void on_action_last_triggered();             //اخر صفحة
    void on_actionGotoPage_triggered();          //التنقل الى صفحة معينة
    //--------
    void on_actionFind_all_triggered();        //تنفيذ البحث في مجموعة كتب
    //----------
    void on_action_edit_triggered();          //زر وقائمة تفعيل التحرير
    void on_action_favorit_triggered();       //اضف للمفضلة
    void on_actionHiperlink_triggered();      //ارتباط تشعبي
    //---------
    void on_actionOrganizeFahrasse_triggered(); //ضبط روابط الفهرسة
    //---------
    void on_actionUpdatGroupRemove_triggered(); //حذف الكتب الغير متوفرة
    void on_actionUpdatGroup_triggered();       //تمييز الكتب الغير متوفرة
//**menuView**

    void on_action_fulscreen_triggered();       //ملأ الشاشة
    void on_actionOption_triggered();           //خيارات
    void on_actionRemoveTechkil_triggered();    //التشكيل
    void on_actionZoomOut_triggered();
    void on_actionZoumIn_triggered();
    //------------
    void on_actionPageIntro_triggered();        //صفحة البداية
//**menuHelp**
    void on_action_about_triggered();           //حول البرنامج
    void on_actionHelp_triggered();             //التعليمات
//void on_actionHtmlFile_triggered();          //تحميل الكتب
 void on_actionWhatsThis_triggered();
//**treeViewBook**
    void on_treeWidget_books_itemSelectionChanged();                    //عند تغير التحديد في شجرة الكتب
    void on_treeWidget_books_itemActivated(QTreeWidgetItem* item);      //تفعيل عنصر شجرة  الكتب
    void on_treeWidget_books_customContextMenuRequested();       //انشاء قائمة لشجرة الكتب
    void menuOpenBook();                           //تنفيذ قائمة فتح الكتاب
    void menu_BookRemove();                   //تنفيذ عملية حذف الكتاب
    void menu_BookUpdat();                    //تحرير بيانات الكتاب
    void menu_BookPath();                    //معرفة مسار الكتاب
    void menu_renameBook();                  //اعادة تسمية دليل الكتاب
    void menu_GroupeAdd();                   //اضافة مجموعة جديدة
    void menu_CategorieAdd();                //اضافة قسم جديد
    void menu_Add(bool categorie);           //
    void menu_GroupeRemove();                //حذف المجموعة
    void menu_GroupeRename();                //تسمية المجموعة
//**treeViewFahras**
    void fahras_itemActivated(QTreeWidgetItem* item);    //تفعيل عنصر شجرة الفهرسة
    void fahras_itemClicked(QTreeWidgetItem* item);       //النقر على عنوان الفهرسة
    void on_pushButtonEditClose_clicked();
    void itemFahrasAddChild();
    void itemFahrasAdd();
    void itemFahrasRename();
    void itemFahrasMoveUp();          //نقل عنصر للاعلى في الفهرسة
    void itemFahrasMoveDown();        //للاسفل
    void itemFahrasRemove();      //حذف العنصر

//**treeViewFavorit**
    void on_treeWidget_fav_itemActivated(QTreeWidgetItem* item);
    void on_actionFavItemRen_triggered();
    void on_actionFavItemDown_triggered();
    void on_actionFavItemUp_triggered();
    void on_actionFavDelete_triggered();
    void on_actionFavSave_triggered();
    void find_favo_textChanged(QString );  //البحث في شجرة المفضلة

//**treeVeiwCuran**
    void on_treeWidget_curaan_itemActivated(QTreeWidgetItem* item);     //تفعيل عنصر شجرة القرءان الكريم
    void on_pushButton_gofind_clicked();
    void on_lineEdit_find_cur_textChanged(QString );
    void on_comboBox_currentIndexChanged(int index);             //تحميل الاجزاء او السور
    void on_pushButton_gotafsir_clicked();          //تحمبل كتاب التفسير

//**treeViewFind**
    void showResultFind(QTreeWidgetItem* item);         //النقر على عنصر شجرة نتائج البحث
    void on_actionFindDelete_triggered();
    void on_actionFindItemDown_triggered();
    void on_actionFindItemUp_triggered();
    void on_actionFindLoad_triggered();
    void on_actionFindSave_triggered();

//**Animation**
    void on_actionTreeD_toggled(bool );
    void on_actionAnimHistorie_triggered();
    void on_actionAnimGroup_triggered();
    void on_lineEdit_textChanged(QString );
  //  void startAnimationBitaka();
    //void startAnimationPixmap();

//**tabs**
    void on_tabWidget_tabCloseRequested(int index);
    void on_tabWidget_currentChanged(int );

     void tabCreatFahrass();
     void tabCreatTabNew();
     void tabOpenInNewTab();
void tabCreatCadre(QGridLayout *gridLayout);

//rowat
void on_btnRowaInfo_clicked();
void on_treeWidget_rowatFind_itemActivated(QTreeWidgetItem* item, int );
void showfind(bool isrowat);
void on_treeWidget_rowatTabia_itemActivated(QTreeWidgetItem* item, int );
void openRawi(QTreeWidgetItem* item,bool addToTataboa);
void on_treeWidget_rowat_itemActivated(QTreeWidgetItem* item, int );
void on_lineEdit_FindRowat_textChanged(QString searchString);
void on_comboBox_rowat_currentIndexChanged(int index);

//-********functions**************

void historieNext();
void historiePrev();
void openRecentFile();
void findInCurrentBook();              //البحث في الكتاب الحالي
void chargeIconsThemes();
bool loadPlugin();
bool loadPluginRowat();
bool loadPluginCdrom();
    void printPreview(QPrinter *printer);
    void saveFahrass(int index);
   // bool loadPlugin();

    void open_dataBase(QString name,QString title,QString Autor,int position);  //فتح الكتاب المحدد

    bool closeMessages(QString title,int index);

    void findBookOrHautor();                    // مؤلف البحث عن كتاب
    void searchInTreeFah(QString );//البحث في شجرة الفهرسة
    void searchInTreeBook(QString );        //البحث في شجرة الكتب

    void stopFind();                  //توقيف عملية البحث
    void searchIndoc();                 //البحث في الصفحة الحالية
    //عمليات التحميل
    void chargeGroupe();                //تحميل مجموعة الكتب
    void updateIconEndAction();
    //عمليات السمات والموضع والاحجام
    void saveLayou();                     //حفظ البيانات للموضع والسمة
    void loadLayout();                    //تحميل بيانات

    void bookValueChanged(int pos);          //تغير رقم السبين للتنقل بين الصفحات

    void saveCurrentBook(int index);
    // fahrasse عمليات تحرير الفهرسة

    void addItemInTreeFahras(bool child);              //اظافة عنصر الى الفهرسة
      //******
    void saveBookEndFahras();//حفظ الفهرسة
    //عملية تحويل النصوص
    void convertTextToHtml(QString txt);           //عملية تحويل النص
    void textBookHighlighted(QUrl );
    void textBookAnchorClicked(QUrl );
    void textBrewserCustomMenu();


    void on_actionShamilaCdrom_triggered();

    void on_actionControle_triggered();
    void on_actionDvd_triggered();
};

#endif // MAINWINDOW_H
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
