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

#include "dialogfavo.h"

#include  "ui_dialogfavo.h"

#include <QtGui>
dialogfavo::dialogfavo(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialogfavo)
{
    ui->setupUi(this);

}
dialogfavo::~dialogfavo()
{

}
void dialogfavo::charge_combo()
{
 QTreeWidgetItem *item;
  for(int i=0;i<view->topLevelItemCount();++i)
    {
        item= view->topLevelItem(i);
     QString   grouptext=item->text(0);
        ui->comboBox->addItem(iconFolder,grouptext);
    }
  reowcount=ui->comboBox->count();
}

void dialogfavo::on_pushButton_clicked()
{
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("ادخل اسما للمجلد الجديد"));
    dff->setWindowTitle(trUtf8("انشاء مجلد جديد"));

    //استرجاع نص البحث
    if (dff->exec()==QInputDialog::Accepted ){
        QString  newtext = dff->textValue();
        if (newtext.isEmpty()){
            return;
        }
         ui->comboBox->addItem(iconFolder,newtext);
         int itmcount=ui->comboBox->count();
         ui->comboBox->setCurrentIndex(itmcount-1);

    }

}

void dialogfavo::on_buttonBox_accepted()
{

    if (ui->lineEdit->text().isEmpty()){
        return;
    }
    int index=ui->comboBox->currentIndex();
    QTreeWidgetItem *itemtop;
    QTreeWidgetItem *item;
    if (index>reowcount-1) {
        itemtop=new QTreeWidgetItem(view);
        itemtop->setText(0,ui->comboBox->currentText());
        itemtop->setIcon(0,iconFolder);
    }

    item=new QTreeWidgetItem(view->topLevelItem(index));
    item->setText(0,ui->lineEdit->text());
    item->setText(1,bookTitle);
    item->setText(2,bookAut);
    item->setData(2,1,bookId);
    item->setData(1,1,bookName);
    item->setIcon(0,iconFile);
}


