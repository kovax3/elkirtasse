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

#include "dialogupdat.h"

#include  "ui_dialogupdat.h"
#include <QMessageBox>
#include <QtGui>

dialogupdat::dialogupdat(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialogupdat)
{
    ui->setupUi(this);
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
}
void dialogupdat::okEnabled()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

}

void dialogupdat::on_buttonBox_accepted()
{
    Messages->treeMenuRemoveBook(BookName,false);
    QString Add_Book_Name=ui->lineEdit_booknam->text();
    QString Add_Autor_Name =ui->lineEdit_autor->text()  ;
    QString Add_Betaka=ui->textBrowser->textCursor().document()->toPlainText();

    //    bool checked=false;
    Messages->m_pathCostum=m_pathCostum;
    //    if (ui->checkBox_curan->checkState()==Qt::Checked) {
    //        checked=true;
    //    }
    bool checked=ui->checkBox_curan->isChecked();
    if (Messages->addNewBook(BookName,Add_Book_Name,Add_Autor_Name,Add_Betaka,addGroupId,checked)==false)
    {
        QMessageBox::information(this,trUtf8("خطأ"),trUtf8("ربما نسيت ملأ احد اخانات الضرورية أو ان بيانات الكتاب خاطئة"));
    }
    else
    {
        if(Messages->saveBookInfo(BookName,Add_Book_Name,Add_Autor_Name,Add_Betaka)){
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
}

void dialogupdat::on_comboBox_group_currentIndexChanged(int index)
{
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
