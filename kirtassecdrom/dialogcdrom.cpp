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
#include "dialogcdrom.h"
#include "ui_Dialogcdrom.h"
#include <QFile>
#include <QFileDialog>

Dialogcdrom::Dialogcdrom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogcdrom)
{
    ui->setupUi(this);
}

Dialogcdrom::~Dialogcdrom()
{
    delete ui;
}

void Dialogcdrom::on_lineEditPathMain_textChanged(const QString &arg1)
{
    QFile file(arg1);
    if(file.exists()){
        ui->labelPathMain->setPixmap(style()->standardPixmap(QStyle::SP_DialogApplyButton));
         pathMain=arg1;
    } else {
        ui->labelPathMain->setPixmap(style()->standardPixmap(QStyle::SP_DialogCancelButton));
        pathMain="";
    }
}

void Dialogcdrom::on_lineEditBooks_textChanged(const QString &arg1)
{
    QFile file(arg1);
    if(file.exists()){
        ui->labelPathBooks->setPixmap(style()->standardPixmap(QStyle::SP_DialogApplyButton));
         pathBooks=arg1;
    } else {
        ui->labelPathBooks->setPixmap(style()->standardPixmap(QStyle::SP_DialogCancelButton));
        pathBooks="";
    }
}

void Dialogcdrom::on_lineEditPathBooksNew_textChanged(const QString &arg1)
{
    QFile file(arg1);
    if(file.exists()){
        ui->labelPathBooksNew->setPixmap(style()->standardPixmap(QStyle::SP_DialogApplyButton));
        pathBooksNew=arg1;
    } else {
        ui->labelPathBooksNew->setPixmap(style()->standardPixmap(QStyle::SP_DialogCancelButton));
        pathBooksNew="";
    }
}

void Dialogcdrom::on_toolButtonMain_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), tr("main.mdb (*.mdb *.MDB)"));


    if (!fn.isEmpty())

        ui->lineEditPathMain->setText(fn);
}

void Dialogcdrom::on_toolButtonBooks_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
    if(QFile::exists(dirName)){
     ui->lineEditBooks->setText(dirName);

     }
}

void Dialogcdrom::on_toolButtonBooksNew_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
    if(QFile::exists(dirName)){
     ui->lineEditPathBooksNew->setText(dirName);

     }
}

void Dialogcdrom::on_buttonBox_accepted()
{
    if(pathMain.isEmpty() || pathBooks.isEmpty() || pathBooksNew.isEmpty()){
        acceptedPath=false;
    }else {
        acceptedPath=true;
    }
}
