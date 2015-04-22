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
#include "dialogconvert.h"
#include  "ui_dialogconvert.h"
#include <QMessageBox>
#include <QtGui>

dialogconvert::dialogconvert(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialogconvert)
{
    ui->setupUi(this);
    ui->toolButton_down->setIcon(style()->standardPixmap(QStyle::SP_ArrowDown));
      ui->toolButton_up->setIcon(style()->standardPixmap(QStyle::SP_ArrowUp));

     Messages = new messages();
     Messages->comboCharge(ui->comboBox_group);
creatId=0;

}
dialogconvert::~dialogconvert()
{
//m_textEdit=new QTextEdit(this);
}

void dialogconvert::on_pushButton_clicked()
{

    if (ui->listWidget->count()==0){return;}
    this->setCursor(QCursor(Qt::WaitCursor));



    if ( creat_dir()==false)
    {

        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("خطأ لم استطع انشاء المجلد"));
        this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }
    if ( creat_xmlfile(m_newPath)==true)
    {
        //  QString Add_Path_Name=ui->lineEdit_fileNam->text();
        QString Add_Book_Name=ui->lineEdit_booknam->text();
        QString Add_Autor_Name =ui->lineEdit_autor->text()  ;
        QString Add_Betaka=ui->textBrowser->textCursor().document()->toPlainText();

        bool checked=false;
        Messages->m_pathCostum=m_pathCostum;
        if (Messages->addNewBook(m_newPathDir,Add_Book_Name,Add_Autor_Name,Add_Betaka,m_addGroupeId,checked)==false)
        {

            QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما نسيت ملأ احد اخانات الضرورية أو ان بيانات الكتاب خاطئة"));
        }
        else
        {
                Messages->saveBookInfo(m_newPathDir,Add_Book_Name,Add_Autor_Name,Add_Betaka);

            QMessageBox::information(this,trUtf8("معلومات"), trUtf8("تمت عملية اظافة الكتاب بنجاح"));

        }
    }
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->accept();
}

 bool dialogconvert::load(const QString &f)
 {
     if (!QFile::exists(f))
         return false;
     QFile file(f);
     if (!file.open(QFile::ReadOnly))
         return false;
     QByteArray data = file.readAll();
     QTextCodec *codec = Qt::codecForHtml(data);
     QString str = codec->toUnicode(data);
     if (Qt::mightBeRichText(str)) {
     m_textEdit.setHtml(str);

     } else {
         str = QString::fromUtf8(data);
      m_textEdit. setPlainText(str);
    //  m_textEdit.insertPlainText(str);
     }
     return true;
 }
bool  dialogconvert::creat_dir()
 {
    QString newBooName=  Messages->geniratNewBookName(m_addGroupeId);
       QDir newdir= m_pathCostum+"/"+ newBooName;
       if (!newdir.exists()){
           QDir dir(m_pathCostum );
           dir.mkdir( newBooName);
           m_newPathDir=newBooName;
           m_newPath=m_pathCostum+"/"+ newBooName;
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
             dir.mkdir( newBooName+"_"+ m.toString());
             m_newPathDir=newBooName+"_"+ m.toString();
             m_newPath=path+"/"+ newBooName+"_"+ m.toString();
             exit=true;
         }
     }
    return true;
 }
  bool dialogconvert::creat_xmlfile(QString path)
  {
      QString myxmlbook="<?xml version='1.0' encoding='UTF-8'?>"
                        "<dataroot>"
                        "</root>";
      m_docBook.setContent(myxmlbook);
      QFile file(path+"/title.xml");
      file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
      QTextStream out(&file);                       //الكتابة
      m_docBook.save(out,1);                      //حفظ الملف
      file.close();
      int rr=ui->listWidget->count();

      for (int i=0;i<rr;i++){
          if  (load(ui->listWidget->item(i)->text())==false){   //open document
              QMessageBox::information(this,   trUtf8("خطأ"),trUtf8(" خطأ في القراءة من الملف"));
              this->setCursor(QCursor(Qt::ArrowCursor));
              return false;
          }
          //هنا يكتب في الوثيقة
          ecrirexml(i+1);
      }
      QFile files(path+"/book.xml");
      files.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
      QTextStream out2(&files);                       //الكتابة
      m_docBook.save(out2,1);                      //حفظ الملف
      files.close();
      m_docBook.clear();
      return true;
  }

void dialogconvert::on_toolButton_fileNam_clicked()
{


    QStringList fn = QFileDialog::getOpenFileNames(this, tr("Open File..."),
                                              QString(), tr("HTML-Files (*.htm *.html);;All Files (*)"));


    if (!fn.isEmpty())
        //  ui->lineEdit_fileNam->setText(fn);
        ui->listWidget->addItems(fn);
}

void dialogconvert::on_comboBox_group_currentIndexChanged(int index)
{
    QVariant idx;
   idx=ui->comboBox_group->itemData(index);
   m_addGroupeId=idx.toString();
}

  bool dialogconvert::ecrirexml(int jozaa)
  {
      QVariant part=jozaa;
         QDomElement racine = m_docBook.documentElement();
      int of;
      int i=0;
       QString str=m_textEdit.textCursor().document()->toPlainText();
          while(str.length()>0)
       {
              if (ui->radioButton_NB->isChecked()){
                  of=str.indexOf(QByteArray("\n"),ui->spinBox->value());
              }else if(ui->radioButtonFull->isChecked()){
                  of=str.length();
              } else{
                  if (!ui->lineEdit->text().isEmpty()){
                      of=str.indexOf( ui->lineEdit->text(),1);

                  }else{
                      of=str.indexOf(QByteArray("\n"),ui->spinBox->value());
                  }
              }
              QString find=str.mid(0,of);
              i=i+1;
              creatId=creatId+1;
              QVariant id=i;
              QVariant newCreatId=creatId;
              QDomElement myel=m_docBook.createElement("book");     //انشاء عنصر جديد
              racine.appendChild(myel);
              QDomElement myid=m_docBook.createElement("id");     //انشاء عنصر جديد
              myel.appendChild(myid);
              QDomText t1 = m_docBook.createTextNode(newCreatId.toString());
              myid.appendChild(t1);
              QDomElement mynass=m_docBook.createElement("nass");     //انشاء عنصر جديد
              myel.appendChild(mynass);
              QDomText t2 = m_docBook.createTextNode(find);
              mynass.appendChild(t2);
              QDomElement mypart=m_docBook.createElement("part");     //انشاء عنصر جديد
              myel.appendChild(mypart);
              QDomText t3 = m_docBook.createTextNode(part.toString());

              mypart.appendChild(t3);
              QDomElement mypage=m_docBook.createElement("page");     //انشاء عنصر جديد
              myel.appendChild(mypage);
              QDomText t4 = m_docBook.createTextNode(id.toString());
              mypage.appendChild(t4);
              //*********************
              str.remove(0,of);
              if (of==-1){
                  break;
              }
          }
          return true;
  }

void dialogconvert::on_toolButton_delete_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()){

        int x=ui->listWidget->currentRow();
        ui->listWidget->takeItem(x);
    }
}

void dialogconvert::on_toolButton_up_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()) {
        int x=ui->listWidget->currentRow();
        if (x==0){return;}
        QListWidgetItem *itemprev=ui->listWidget->item(x-1);
        QString text_prev=itemprev->text();
        QString text_curent=item->text();
        itemprev->setText(text_curent);
        item->setText(text_prev);
        ui->listWidget->setCurrentItem(itemprev);
    }
}

void dialogconvert::on_toolButton_down_clicked()
{
if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()) {
        int x=ui->listWidget->currentRow();
        int cnt=ui->listWidget->count()-1;
        if (x==cnt){return;}
        QListWidgetItem *itemnext=ui->listWidget->item(x+1);
        QString text_prev=itemnext->text();
        QString text_curent=item->text();
        itemnext->setText(text_curent);
        item->setText(text_prev);
        ui->listWidget->setCurrentItem(itemnext);
    }
}
