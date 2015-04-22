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
#include "dialogupdat.h"

#include  "ui_dialogupdat.h"
#include <QMessageBox>
#include <QtGui>

dialogupdat::dialogupdat(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialogupdat)
{
    ui->setupUi(this);
<<<<<<< HEAD
    Messages = new messages();

    Messages->comboCharge(ui->comboBox_group);

    connect( ui->lineEdit_autor, SIGNAL(textEdited(QString)),this, SLOT(okEnabled()));
    connect( ui->lineEdit_booknam, SIGNAL(textEdited(QString)),this, SLOT(okEnabled()));
    connect( ui->textBrowser, SIGNAL(undoAvailable(bool)),this, SLOT(okEnabled()));
    connect(ui->comboBox_group, SIGNAL(currentIndexChanged(int)),this, SLOT(okEnabled()));
}
dialogupdat::~dialogupdat()
{
    //TextEdit=new QTextEdit(this);
=======
     Messages = new messages();

 Messages->comboCharge(ui->comboBox_group);

 connect( ui->lineEdit_autor, SIGNAL(textEdited(QString)),this, SLOT(okEnabled()));
 connect( ui->lineEdit_booknam, SIGNAL(textEdited(QString)),this, SLOT(okEnabled()));
connect( ui->textBrowser, SIGNAL(undoAvailable(bool)),this, SLOT(okEnabled()));
 connect(ui->comboBox_group, SIGNAL(currentIndexChanged(int)),this, SLOT(okEnabled()));
}
dialogupdat::~dialogupdat()
{
//TextEdit=new QTextEdit(this);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}
void dialogupdat::okEnabled()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

}

void dialogupdat::on_buttonBox_accepted()
{

    bookTitle=ui->lineEdit_booknam->text();
    bookAutor =ui->lineEdit_autor->text()  ;
    bookBetaka=ui->textBrowser->textCursor().document()->toPlainText();
    Messages->m_pathCostum=m_pathCostum;
    if (creatNewBook=="creat"){
        if (creat_dir()==false)
<<<<<<< HEAD
            return;
        if (creat_xmlfile(m_newPathDir)==false)
            return;
        updateBook();
        QMessageBox::information(this,trUtf8("معلومات"),m_newPathDir);
=======
           return;
        if (creat_xmlfile(m_newPathDir)==false)
            return;
        updateBook();
         QMessageBox::information(this,trUtf8("معلومات"),m_newPathDir);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    }else if (creatNewBook=="update"){
        Messages->treeMenuRemoveBook(BookName,false);
        updateBook();

    }else if (creatNewBook=="add"){
        if (copyDir(QDir::homePath()+"/.kirtasse/download")==false)
<<<<<<< HEAD
            return;
=======
           return;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        updateBook();

    }

}
bool  dialogupdat::creat_dir()
<<<<<<< HEAD
{


    QString newBooName=  Messages->geniratNewBookName(addGroupId);
    QDir newdir= m_pathCostum+"/"+ newBooName;
    if (!newdir.exists()){
        QDir dir(m_pathCostum );
        dir.mkdir( newBooName);
        BookName  =newBooName;
        m_newPathDir=m_pathCostum+"/"+ newBooName;
        return true;
    }

    bool exit=false;
    int i=0;
    while(exit==false)
    {
        i=i+1;
        QVariant m=i;
        QString path=m_pathCostum;
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
            BookName  =newBooName+"_"+ m.toString();
            m_newPathDir=path+"/"+ newBooName+"_"+ m.toString();
            exit=true;
        }
    }
    return true;
}
bool dialogupdat::creat_xmlfile(QString path)
{
    QString myxmlbook="<?xml version='1.0' encoding='UTF-8'?>"
            "<dataroot>"
            "<book>"
            "<nass>"+trUtf8("صفحة فارغة")+"</nass>"
            "<id>1</id>"
            "<part>1</part>"
            "<page>0</page>"
            "</book>"
            "</dataroot>";
    QString myxmltitle="<?xml version='1.0' encoding='UTF-8'?>"
            "<dataroot>"
            "</dataroot>";

    QFile file(path+"/title.xml");
    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
    QTextStream out(&file);                       //الكتابة
    out << myxmltitle;                  //حفظ الملف
=======
 {


    QString newBooName=  Messages->geniratNewBookName(addGroupId);
       QDir newdir= m_pathCostum+"/"+ newBooName;
       if (!newdir.exists()){
           QDir dir(m_pathCostum );
           dir.mkdir( newBooName);
         BookName  =newBooName;
         m_newPathDir=m_pathCostum+"/"+ newBooName;
           return true;
          }

     bool exit=false;
     int i=0;
    while(exit==false)
     {
         i=i+1;
         QVariant m=i;
         QString path=m_pathCostum;
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
            BookName  =newBooName+"_"+ m.toString();
            m_newPathDir=path+"/"+ newBooName+"_"+ m.toString();
             exit=true;
         }
     }
    return true;
 }
bool dialogupdat::creat_xmlfile(QString path)
{



    QString myxmlbook="<?xml version='1.0' encoding='UTF-8'?>"
                      "<dataroot>"
                          "<book>"
                             "<nass>"+trUtf8("صفحة فارغة")+"</nass>"
                             "<id>1</id>"
                             "<part>1</part>"
                             "<page>0</page>"
                          "</book>"
                      "</dataroot>";
    QString myxmltitle="<?xml version='1.0' encoding='UTF-8'?>"
                      "<dataroot>"
                      "</dataroot>";

   QFile file(path+"/title.xml");
   file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
    QTextStream out(&file);                       //الكتابة
        out << myxmltitle;                  //حفظ الملف
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    file.close();

    QFile files(path+"/book.xml");
    files.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
    QTextStream out2(&files);                       //الكتابة
<<<<<<< HEAD
    out2 << myxmlbook;                  //حفظ الملف
=======
        out2 << myxmlbook;                  //حفظ الملف
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    files.close();

    return true;
}
void dialogupdat::updateBook()
{
<<<<<<< HEAD
    bool checked=ui->checkBox_curan->isChecked();
    if (Messages->addNewBook(BookName,bookTitle,bookAutor,bookBetaka,addGroupId,checked)==false)
    {
        QMessageBox::information(this,trUtf8("خطأ"),trUtf8("ربما نسيت ملأ احد اخانات الضرورية أو ان بيانات الكتاب خاطئة"));
    }
    else
    {
        if(Messages->saveBookInfo(BookName,bookTitle,bookAutor,bookBetaka)){
            if( imgChanged==true){
                QPixmap pix(ui->pushButtonImg->icon().pixmap(128,128));
                QString imgScreenPath= m_pathCostum + "/" +BookName+"/screenshot.png";
                pix.save(imgScreenPath,"PNG");
            }
            QMessageBox::information(this,trUtf8("معلومات"),trUtf8("تمت عملية تحديث بيانات الكتاب بنجاح"));
        }else{
            QMessageBox::information(this,trUtf8("خطأ"),trUtf8("لا يمكن كتابة الملف تحقق من وجود الكتاب"));
        }

    }
=======


     bool checked=ui->checkBox_curan->isChecked();
     if (Messages->addNewBook(BookName,bookTitle,bookAutor,bookBetaka,addGroupId,checked)==false)
     {
         QMessageBox::information(this,trUtf8("خطأ"),trUtf8("ربما نسيت ملأ احد اخانات الضرورية أو ان بيانات الكتاب خاطئة"));
     }
     else
     {
         if(Messages->saveBookInfo(BookName,bookTitle,bookAutor,bookBetaka)){
             if( imgChanged==true){
                 QPixmap pix(ui->pushButtonImg->icon().pixmap(128,128));
                   QString imgScreenPath= m_pathCostum + "/" +BookName+"/screenshot.png";
                   pix.save(imgScreenPath,"PNG");
             }
             QMessageBox::information(this,trUtf8("معلومات"),trUtf8("تمت عملية تحديث بيانات الكتاب بنجاح"));
         }else{
             QMessageBox::information(this,trUtf8("خطأ"),trUtf8("لا يمكن كتابة الملف تحقق من وجود الكتاب"));
         }

     }
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}

void dialogupdat::on_comboBox_group_currentIndexChanged(int index)
{
<<<<<<< HEAD
    QVariant idx;
    idx=ui->comboBox_group->itemData(index);
    addGroupId=idx.toString();
    //  Add_Groupe_Name= ui->comboBox_group->itemText(index);
    if (idx.toString()=="28")
    {
        ui->checkBox_curan->setVisible(true);
    }
    else{
        ui->checkBox_curan->setVisible(false);
        ui->checkBox_curan->setChecked(false);
    }
}
void dialogupdat:: recharge()
{
    QString imgScreenPath= m_pathCostum + "/" +BookName+"/screenshot.png";
    if(!QFile::exists(imgScreenPath)){
        imgScreenPath=":/images/image/booki.png";
    }
    imgChanged=false;
    ui->pushButtonImg->setIcon(QIcon(imgScreenPath));
    ui->lineEdit_autor->setText(bookAutor);
    ui->lineEdit_booknam->setText(bookTitle);
    ui->textBrowser->setPlainText(bookBetaka);
    QVariant id=addGroupId;
    //  ui->comboBox_group->setCurrentIndex(id.toInt()-1);
    int fg=  ui->comboBox_group->findData(id,Qt::UserRole,Qt::MatchExactly);
    ui->comboBox_group->setCurrentIndex(fg);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}
=======
     QVariant idx;
   idx=ui->comboBox_group->itemData(index);
   addGroupId=idx.toString();
 //  Add_Groupe_Name= ui->comboBox_group->itemText(index);
   if (idx.toString()=="28")
   {
       ui->checkBox_curan->setVisible(true);
   }
   else{
          ui->checkBox_curan->setVisible(false);
           ui->checkBox_curan->setChecked(false);
   }
}
void dialogupdat:: recharge()
    {
        QString imgScreenPath= m_pathCostum + "/" +BookName+"/screenshot.png";
        if(!QFile::exists(imgScreenPath)){
           imgScreenPath=":/images/image/booki.png";
        }
        imgChanged=false;
        ui->pushButtonImg->setIcon(QIcon(imgScreenPath));
        ui->lineEdit_autor->setText(bookAutor);
        ui->lineEdit_booknam->setText(bookTitle);
        ui->textBrowser->setPlainText(bookBetaka);
        QVariant id=addGroupId;
      //  ui->comboBox_group->setCurrentIndex(id.toInt()-1);
 int fg=  ui->comboBox_group->findData(id,Qt::UserRole,Qt::MatchExactly);
  ui->comboBox_group->setCurrentIndex(fg);
   ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

void dialogupdat::on_pushButtonImg_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), trUtf8("ملفات الصور (*.png *.jpg);;كل الملفات (*)"));
    if (!fn.isEmpty())
    {
        ui->pushButtonImg->setIcon(QIcon(fn));
        imgChanged=true;
        okEnabled();
    }
}
bool dialogupdat::copyDir(QString filname )
{
    if ( creat_dir()==false){
<<<<<<< HEAD
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء المجلد"));
=======
            QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء المجلد"));
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

        return false;
    }

    QFile file;      //نسخ الملفات الى وجهة المكتبة
    if(file.copy(filname+"/title.xml",m_newPathDir+"/title.xml")==false){
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء الملف title.xml"));
<<<<<<< HEAD
        // return false;
    }
    if(file.copy(filname+"/book.xml",m_newPathDir+"/book.xml")==false){
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء الملف book.xml"));
        return false;
=======
   // return false;
    }
    if(file.copy(filname+"/book.xml",m_newPathDir+"/book.xml")==false){
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء الملف book.xml"));
    return false;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    }



<<<<<<< HEAD
    return true;
=======
     return true;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}
