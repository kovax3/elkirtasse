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
#include "dialog.h"
#include "classepub.h"
#include  "ui_dialog.h"
#include <QtXml>
#include <QDomDocument>
#include <QMessageBox>
#include<QtGui>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->toolButtonInfo->setIcon(style()->standardPixmap(QStyle::SP_MessageBoxInformation));
    ui->toolButton_fileNam->setIcon(style()->standardPixmap(QStyle::SP_DirOpenIcon));
  //  ui->toolButton_zipFileNam->setIcon( QIcon::fromTheme("tgz", QIcon(":/images/image/tar-gz.png")));
    ui->progressBar->setVisible(false);
    Messages = new messages();
// m_path=QCoreApplication::applicationDirPath ();



 Messages->comboCharge(ui->comboBox_group);
Messages->removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
}

Dialog::~Dialog()
{
Messages->removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
}


void Dialog::on_comboBox_group_currentIndexChanged(int index)
{

    QVariant idx;
    idx=ui->comboBox_group->itemData(index);
    m_addGroupeId=idx.toString();
    m_addGroupeName= ui->comboBox_group->itemText(index);


    if (idx.toString()=="28")
    {
        ui->checkBox_curan->setVisible(true);
    }
    else{
        ui->checkBox_curan->setVisible(false);
        ui->checkBox_curan->setChecked(false);
    }
}


void Dialog::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok){
        int countItem=ui->listWidget->count();
        if (countItem<1)
            this->reject();

        ui->progressBar->setMaximum(countItem-1);
        ui->progressBar->setVisible(true);
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        for(int i=0;i<countItem;i++){
            ui->progressBar->setValue(i);
            QString filname= ui->listWidget->item(i)->text();
            QFileInfo fi(filname);
            QString ext = fi.completeSuffix();
            if (ext.toLower()=="tar.gz"||ext.toLower()=="krts"){
                Messages->removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
                if(Messages->loadTarGz(filname)==true){

                    QString tempFile=QDir::homePath()+"/.kirtasse/download/";
                    loadBookInfo(tempFile);
                    if (copyDir(tempFile,countItem)==true)
                        msgTitle=msgTitle+"\n"+Add_Book_Name+"\n"+m_newPathDir;
                    //  archiveDir="";
                }
            } else if(ext.toLower()==("epub")){
                  Messages->removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
              classepub  *Classepub=new classepub;
                  if  (Classepub->ebubUnzip(filname)==true) {
                      Add_Book_Name=Classepub->infoBookTitle;
                      Add_Autor_Name=Classepub->infoBookAutor;
                      Add_Betaka=Classepub->infoBookBetaka;
                    QString tempFile=QDir::homePath()+"/.kirtasse/download/";
                      if (copyDir(tempFile,countItem)==true)
                          msgTitle=msgTitle+"\n"+Add_Book_Name+"\n"+m_newPathDir;
                 }
            }else{

                loadBookInfo(filname);
                if (copyDir(filname,countItem)==true)
                    msgTitle=msgTitle+"\n"+Add_Book_Name+"\n"+m_newPathDir;
            }
            qApp->processEvents();
            QApplication::restoreOverrideCursor();
        }  //for

        if(!msgTitle.isEmpty()){

            QMessageBox msgBox;
            msgBox.setText(trUtf8(" لقد تم انشاء الكتب التالية بنجاح داخل المجموعة :  ")+m_addGroupeName );
            msgBox.setInformativeText(trUtf8("انقر على اظهار التفاصيل لمعرفة قائمة الكتب "));
            msgBox.setDetailedText(msgTitle);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setLayoutDirection(Qt::RightToLeft);
            msgBox.setWindowTitle(trUtf8("تعليمات"));
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            Messages-> removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
            qApp->processEvents();

            this->accept();
        } //msg
    } //ok
 this->accept();
}


bool Dialog::copyDir(QString filname,int )
{
    if ( creat_dir()==false){
            QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء المجلد"));

        return false;
    }
//m_newPathDir=m_path+"/"+archiveDir;
//QMessageBox::information(this,trUtf8("خطأ"), m_newPathDir);

    QFile file;      //نسخ الملفات الى وجهة المكتبة
    if(file.copy(filname+"/title.xml",m_newPathDir+"/title.xml")==false){
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء الملف title.xml"));
   // return false;
    }
    if(file.copy(filname+"/book.xml",m_newPathDir+"/book.xml")==false){
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء الملف book.xml"));
    return false;
    }

//    if(items==1){
//    Add_Book_Name=ui->lineEdit_booknam->text();
//    Add_Autor_Name =ui->lineEdit_autor->text()  ;
//    Add_Betaka=ui->textEdit_betaka->textCursor().document()->toPlainText();
//    }
    bool checked=false;
     Messages->m_pathCostum=m_path;
    if (ui->checkBox_curan->checkState()==Qt::Checked) {
        checked=true;
    }
    if (Messages->addNewBook(m_bookDir,Add_Book_Name,Add_Autor_Name,Add_Betaka,m_addGroupeId,checked)==false)
    {
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما نسيت ملأ احد اخانات الضرورية أو ان بيانات الكتاب خاطئة"));
         return false;
    }else{

        Messages->saveBookInfo(m_bookDir,Add_Book_Name,Add_Autor_Name,Add_Betaka);


    }
     return true;
}

bool  Dialog::creat_dir()
 {
    QString newBooName=  Messages->geniratNewBookName(m_addGroupeId);
       QDir newdir= m_path+"/"+ newBooName;
       if (!newdir.exists()){
           QDir dir(m_path );
           dir.mkdir( newBooName);
         m_bookDir  =newBooName;
            m_newPathDir=m_path+"/"+ newBooName;
           return true;
          }

     bool exit=false;
     int i=0;
    while(exit==false)
     {
         i=i+1;
         QVariant m=i;
         QString path=m_path;
          QDir newdir =path+"/"+ newBooName+"_"+m.toString();
         if (newdir.exists())
         {
             exit=false;
         }
         else{
             QDir dir(path );
             if(dir.mkdir( newBooName+"_"+ m.toString())==false) {
                 return false;
             }
            m_bookDir  =newBooName+"_"+ m.toString();
             m_newPathDir=path+"/"+ newBooName+"_"+ m.toString();
             exit=true;
         }
     }
    return true;
 }
void Dialog::on_toolButton_fileNam_clicked()
{

    QString homeDir=QDir::homePath () ;
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
    if(QFile::exists(dirName+"/book.xml")){
     ui->listWidget->addItem(dirName);
     return;
     }

   QString subdir;
    QDir dir(dirName);
    foreach ( subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot |
                                    QDir::Hidden )){
        if(QFile::exists(dirName+"/"+subdir+"/book.xml"))
        ui->listWidget->addItem(dirName+"/"+subdir);

    }

}
void Dialog::loadBookInfo(QString path)
{
    //    ui->lineEdit_fileNam->setText(path);
    if (  Messages->loadBookInfo(path)==false) {
        Messages->removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
        QMessageBox::information(this,"info.xml","this info.xml no valid");
        return;
    }
    Add_Book_Name=Messages->infoBookTitle;
    Add_Autor_Name=Messages->infoBookAutor;
    Add_Betaka=Messages->infoBookBetaka;
//    ui->lineEdit_booknam->setText(Messages->infoBookTitle);
//    ui->lineEdit_autor->setText(Messages->infoBookAutor);
//    ui->textEdit_betaka->setText(Messages->infoBookBetaka);

}
// --***************tar.gz
void Dialog::on_toolButton_zipFileNam_clicked()
{
 // removeTempDirs(QDir::homePath()+"/.kirtasse/download/");
    QFileDialog dlg;

    QStringList fn = dlg.getOpenFileNames(this, tr("Open Archive Files..."),
                                                 QString(), trUtf8("ملفات ارشفة (*tar.gz *.krts *.epub);;krts (*.krts);;tar.gz (*.tar.gz);;epub (*.epub) ;;كل الملفات (*)"));
    if (!fn.isEmpty())
    {
      ui->listWidget->addItems(fn);
      //  loadTarGz(fn);

    }
}




void Dialog::on_toolButton_delete_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()){

        int x=ui->listWidget->currentRow();
        ui->listWidget->takeItem(x);
    }
}

void Dialog::on_toolButtonInfo_clicked()
{
     if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (!item->isSelected())
       return;

    QString path=ui->listWidget->currentItem()->text();

   if (path.contains(".tar.gz")||path.contains(".Krts")){

       #ifdef   Q_WS_WIN
       QMessageBox::information(this,trUtf8("معلومات الكتاب"),
                                trUtf8("الكتاب حزمة مضغوطة"));
        return ;
       #endif
       QProcess prosses;
       prosses.start("tar -tf  "+path);
       prosses.waitForFinished();
       QByteArray result = prosses.readAll();
       QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QString string = codec->toUnicode(result);
        if (!string.contains("book.xml") && !string.contains("bookinfo.info")){
           QMessageBox::critical(this,trUtf8("خطأ"),trUtf8("الارشيف لا يحتوي على كتاب\n"));
            return ;
        }else{
             QString titles=string.section( "/",0,0);
            QMessageBox::information(this,trUtf8("معلومات الكتاب"),titles+"\n"+
                                     trUtf8("الكتاب حزمة مضغوطة"));

        }

   }
    if (  Messages->loadBookInfo(path)==false) {

        return;
    }
    QString title=Messages->infoBookTitle;
    QString autor=Messages->infoBookAutor;
    QString betaka=Messages->infoBookBetaka;
    QMessageBox::information(this,trUtf8("معلومات الكتاب"),title+"\n"+
                             autor+"\n"+
                             betaka);
}
