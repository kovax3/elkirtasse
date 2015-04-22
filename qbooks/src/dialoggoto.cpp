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
#include "dialoggoto.h"

#include  "ui_dialoggoto.h"
#include <QMessageBox>
#include <QtGui>

dialoggoto::dialoggoto(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialoggoto)
{
    ui->setupUi(this);

}
dialoggoto::~dialoggoto()
{

}
void dialoggoto::updateValue()
{
    ui->spinBoxValue->setMaximum(rowCount+1);
    ui->horizontalSlider->setMaximum(rowCount+1);
    ui->spinBoxValue->setValue(counter);
    ui->horizontalSlider->setValue(counter+1);
}

void dialoggoto::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok){


        if (ui->checkBoxValue->isChecked()){

            counter=ui->spinBoxValue->value();
             this->accept();
             return ;
        }

        counter=0;
        QVariant spinPart=ui->spinBoxPart->value();
        QVariant spinPage=ui->spinBoxPage->value();
        QFile filx(pathBook);//فتح الكتاب
        if (!filx.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("خطأ في قراءة الملف"));
            return ;
        }
        xml.setDevice(&filx);
        if (xml.readNextStartElement()) {
            if (xml.name() == "dataroot" ){
                if(  readXmlBook(spinPart.toString(),spinPage.toString())==true){
                    xml.clear();
                    filx.close();
                    this->accept();
                }else{
                    QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("الجزء أو الصفحة غير موجودين"));
                    filx.close();
                }

            }else{
                QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("خطأ غير محدد"));
            }

        }
  xml.clear();
        filx.close();

    }

}

bool dialoggoto::readXmlBook(QString spinPart,QString spinPage)
{

    Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
    QString part="0";
    QString page="0";

    while (xml.readNextStartElement()) {
        if (xml.name() == "book"){
            counter++;
           // Q_ASSERT(xml.isStartElement() && xml.name() == "book");
            while (xml.readNextStartElement()) {
                if (xml.name() == "page"){
                 //   Q_ASSERT(xml.isStartElement() && xml.name() == "page");
                    page=xml.readElementText();
                }else if (xml.name() == "part"){
                 //   Q_ASSERT(xml.isStartElement() && xml.name() == "part");
                    part= xml.readElementText();

                }else{

                    xml.skipCurrentElement();
                }
            }

        } else{

            xml.skipCurrentElement();
        }
        if (part+"_"+page==spinPart+"_"+spinPage){
             xml.skipCurrentElement();
            xml.clear();
             return true;
        }

    }

    return false;
}



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
#include "dialoggoto.h"

#include  "ui_dialoggoto.h"
#include <QMessageBox>
#include <QtGui>

dialoggoto::dialoggoto(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialoggoto)
{
    ui->setupUi(this);



}
dialoggoto::~dialoggoto()
{

}
void dialoggoto::updateValue()
{
    ui->spinBoxValue->setMaximum(rowCount+1);
    ui->horizontalSlider->setMaximum(rowCount+1);
    ui->spinBoxValue->setValue(counter);
    ui->horizontalSlider->setValue(counter+1);
}

void dialoggoto::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok){


        if (ui->checkBoxValue->isChecked()){

            counter=ui->spinBoxValue->value();
             this->accept();
             return ;
        }

        counter=0;
        QVariant spinPart=ui->spinBoxPart->value();
        QVariant spinPage=ui->spinBoxPage->value();
        QFile filx(pathBook);//فتح الكتاب
        if (!filx.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("خطأ في قراءة الملف"));
            return ;
        }
        xml.setDevice(&filx);
        if (xml.readNextStartElement()) {
            if (xml.name() == "dataroot" ){
                if(  readXmlBook(spinPart.toString(),spinPage.toString())==true){
                    xml.clear();
                    filx.close();
                    this->accept();
                }else{
                    QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("الجزء أو الصفحة غير موجودين"));
                    filx.close();
                }

            }else{
                QMessageBox::information(this,trUtf8("تنبيه"),trUtf8("خطأ غير محدد"));
            }

        }
  xml.clear();
        filx.close();

    }

}

bool dialoggoto::readXmlBook(QString spinPart,QString spinPage)
{

    Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
    QString part="0";
    QString page="0";

    while (xml.readNextStartElement()) {
        if (xml.name() == "book"){
            counter++;
           // Q_ASSERT(xml.isStartElement() && xml.name() == "book");
            while (xml.readNextStartElement()) {
                if (xml.name() == "page"){
                 //   Q_ASSERT(xml.isStartElement() && xml.name() == "page");
                    page=xml.readElementText();
                }else if (xml.name() == "part"){
                 //   Q_ASSERT(xml.isStartElement() && xml.name() == "part");
                    part= xml.readElementText();

                }else{

                    xml.skipCurrentElement();
                }
            }

        } else{

            xml.skipCurrentElement();
        }
        if (part+"_"+page==spinPart+"_"+spinPage){
             xml.skipCurrentElement();
            xml.clear();
             return true;
        }

    }

    return false;
}



>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
