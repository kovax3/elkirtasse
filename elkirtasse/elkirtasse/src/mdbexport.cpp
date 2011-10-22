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

#include "mdbexport.h"
#include<QtGui>
#include <QTextStream>
#include  "ui_mdbexport.h"
mdbexport::mdbexport(QWidget *parent)
    : QDialog(parent), ui(new Ui::mdbexport)
{
    ui->setupUi(this);

     Messages = new messages();
 Messages->comboCharge(ui->comboBox);
 ui->progressBar->setVisible(false);
 QDir dir;
 QString h=dir.homePath()+"/.kirtasse";
 QFile filetemp;
 if (filetemp.exists(h+"/tempbk.csv")){
     filetemp.remove(h+"/tempbk.csv");
 }
 if (filetemp.exists(h+"/temptitle.csv")){
     filetemp.remove(h+"/temptitle.csv");
 }
 if (filetemp.exists(h+"/out")){
     filetemp.remove(h+"/out");
 }
 if (filetemp.exists(h+"/main.csv")){
     filetemp.remove(h+"/main.csv");
 }

}
mdbexport::~mdbexport()
{
    QDir dir;
    QString h=dir.homePath()+"/.kirtasse";
    QFile filetemp;
    if (filetemp.exists(h+"/tempbk.csv")){
        filetemp.remove(h+"/tempbk.csv");
    }
    if (filetemp.exists(h+"/temptitle.csv")){
        filetemp.remove(h+"/temptitle.csv");
    }
    if (filetemp.exists(h+"/out")){
        filetemp.remove(h+"/out");
    }
    if (filetemp.exists(h+"/main.csv")){
        filetemp.remove(h+"/main.csv");
    }
}

void mdbexport::on_toolButton_fileNam_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), trUtf8("ملفات الشاملة (*.mdb *.bok);;كل الملفات (*)"));
    if (!fn.isEmpty())
    {
//        if (fn.contains(" ")){
//            QMessageBox::information(this,trUtf8("خطأ"),trUtf8("يجب ان لايحتوي اسم الملف او الدليل على فراغات"));
//            return;
//        }
        if (fn.contains(".bok")){
            if (creatBash(fn,true)==true){
                if(creatCsvFile()==true) {
                    QDir dir;
                    QString h=dir.homePath()+"/.kirtasse";
                    enum  { NumIndex = 40};
                    QString strHeaderName[NumIndex];
                    //*********************************
                    QFile fileCsv(h+"/main.csv");

                    if (!fileCsv.open(QFile::ReadOnly)){
                        return;
                    }

                    QTextStream textStream(&fileCsv);
                    textStream.setCodec(QTextCodec::codecForName("Windows-1256"));

                    QString line;


                    line = textStream.readLine();//premier line
                    // QMessageBox::information(this,trUtf8("خطأ"),line);


                    int tab=  line.count("|*|");//nombre col
                    if (tab>=38){
                        tab=38;
                    }

                    //QMessageBox::information(this,trUtf8("خطأ"),QString::number(tab));
                    for (int i=1;i<tab+2;i++){
                        if (i==tab+1){
                            strHeaderName[i]=line.section("|*|",-1);
                        }else{
                            strHeaderName[i]=line.section("|*|",i-1,i-1);
                        }
                    }

                    line = textStream.readAll();//2 line

                    for (int i=1;i<tab+2;i++){
                        QString strValue;
                        if (i==tab+1){
                            strValue=line.section("|*|",-1);
                        }else{
                            strValue=line.section("|*|",i-1,i-1);
                        }
                        //   QMessageBox::information(this,trUtf8("خطأ"),strHeaderName[i]+"  : "+strValue);
                        if (strHeaderName[i]=="Bk"){ui->lineEdit_booknam->setText(strValue);}
                        if (strHeaderName[i]=="Auth"){ ui->lineEdit_autor->setText(strValue);}
                        if (strHeaderName[i]=="Betaka"){ ui->textEdit->setText(strValue);}
                        if (strHeaderName[i]=="BkId"){
                            tableBook="b"+strValue;
                            tableTitle="t"+strValue;
                        }

                    }

                }
            }

            }

        }else if(fn.contains(".mdb")){
            tableBook="book";
            tableTitle="title";
        }
        ui->lineEdit_fileNam->setText(fn);
    }


void mdbexport::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok){
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        QFile mdbFile(ui->lineEdit_fileNam->text());
        if(ui->lineEdit_fileNam->text().isEmpty()){
            QMessageBox::information(this,trUtf8("خطأ"),trUtf8("ادخل اسم الملف في مربع النص"));
             return;
        }
        if(!mdbFile.exists()){
            QMessageBox::information(this,trUtf8("خطأ"),trUtf8("تحقق من كتابة اسم الملف بشكل صحيح"));
            return;
        }
        QDir dir;
        QString h=dir.homePath()+"/.kirtasse";
        if (!dir.exists(h)) //التاكد من وجود مجلد المكتبة
        {
            return;
        }
        QFile filetemp;
        if (filetemp.exists(h+"/tempbk.csv")){
            filetemp.remove(h+"/tempbk.csv");
        }
        if (filetemp.exists(h+"/temptitle.csv")){
            filetemp.remove(h+"/temptitle.csv");
        }
        if (filetemp.exists(h+"/out")){
            filetemp.remove(h+"/out");
        }
        if  (creatBash(ui->lineEdit_fileNam->text(),false)==true){
            qApp->processEvents();
            ui->label_Info->setText("bash");
            qApp->processEvents();
            if (creatCsvFile()==true){
                qApp->processEvents();
                ui->label_Info->setText(trUtf8("جاري التحويل الى صيغة csv"));
                qApp->processEvents();
                QString bookDir=creatBooKDir();
                    if ( creatXmlFile(m_path+"/"+bookDir+"/book.xml","book","/tempbk.csv")==true){
                            creatXmlFile(m_path+"/"+bookDir+"/title.xml","title","/temptitle.csv");
                        if (creatInfo(bookDir)==true){
                                     QApplication::restoreOverrideCursor();
                                    QMessageBox::information(this,trUtf8("معلومات"),trUtf8("تمت عملية اظافة الكتاب بنجاح"));
                                    this->accept();
                                }
                    }else{ QMessageBox::information(this,trUtf8("خطأ"),trUtf8("لم استطع انشاء ملف الكتاب ربما لا تملك صلاحيات الكتابة"));}
            }else{ QMessageBox::information(this,trUtf8("خطأ"),trUtf8("ربما ملف الكتب غير صحيح او فاسد"));}
        }else{ QMessageBox::information(this,trUtf8("خطأ"),trUtf8("ربما لا تملك صلاحيات الكتابة"));}
        QApplication::restoreOverrideCursor();
    }
}
bool mdbexport::creatBash(QString fn,bool bok)
{
   QDir dir;
   QString h=dir.homePath()+"/.kirtasse";
   QFile file(h+"/out");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
    QTextStream out(&file);
 fn.replace(" ","\\ ");
    if (bok==true){
        out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
            <<  "mdb-export -d'|*|' -Q  "+fn+ " Main >> "+h+"/main.csv";

    }else{
        out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
                   <<  "mdb-export -d'|*|' -Q  "+fn+ " "+tableBook+" >> "+h+"/tempbk.csv"  <<"\n"
                 <<  "mdb-export -d'|*|'  -Q  "+fn+ " "+tableTitle+" >> "+h+"/temptitle.csv";
    }


    return true;

}
bool mdbexport::creatCsvFile()
{
     QDir dir;
    QString h=dir.homePath()+"/.kirtasse";
    QProcess prosses;
  prosses.execute(h+"/out");


return true;

}



bool mdbexport::creatXmlFile(QString f,QString table,QString csv)
{
    QDir dir;
    QString h=dir.homePath()+"/.kirtasse";
    enum  { NumIndex = 10};
    QXmlStreamWriter stream;

    QString strHeaderName[NumIndex];
    //*********************************
    QFile fileCsv(h+csv);

    if (!fileCsv.open(QFile::ReadOnly)){
        return false;
    }

    QTextStream textStream(&fileCsv);
    textStream.setCodec(QTextCodec::codecForName("Windows-1256"));


    QString line;
    line = textStream.readLine();//premier line

    int tab=  line.count("|*|");//nombre col
    for (int i=1;i<tab+2;i++){
        if (i==tab+1){
            strHeaderName[i]=line.section("|*|",-1);
        }else{
            strHeaderName[i]=line.section("|*|",i-1,i-1);
        }

    }
    //*********************ecrir
    QFile file(f);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        return false;
    }
    ui->label_Info->setText(trUtf8("جاري حفظ ملف :")+f);
    stream.setDevice(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("dataroot");
ui->progressBar->setVisible(true);
     ui->progressBar->setMaximum(1000);
      int r=0;
     while (!line.isNull()) {
        r++;
        if (r==1000){r=0;}
        qApp->processEvents();
        ui->progressBar->setValue(r);
        line = textStream.readLine();

     //   QMessageBox::information(this,trUtf8("خطأ"),line);
        stream.writeStartElement(table);//"book" or "title"
        //**************************************start book

        for (int i=1;i<tab+2;i++){
            QString strValue;
            if (i==tab+1){
                strValue=line.section("|*|",-1);
            }else{
                strValue=line.section("|*|",i-1,i-1);
            }
              if (strValue.isEmpty() || strValue==0){strValue="1";}
            if (strHeaderName[i]=="hno" || strHeaderName[i]=="na" || strHeaderName[i]=="sub"){
                //*--
            }else if(strHeaderName[i]=="id"){
                if (table=="book"){
                    listId.append(strValue);
                }else{
                    int newid=listId.indexOf(strValue);
                    if (newid==-1){newid=0;}
                    QVariant dd= newid+1;
                    strValue=dd.toString();
                }

                stream.writeTextElement(strHeaderName[i], strValue);
            }else{

                stream.writeTextElement(strHeaderName[i], strValue);
            }
        }
        stream.writeEndElement(); // book table
        //***************************************    end book
    }
    ui->progressBar->setValue(1000);
    stream.writeEndElement(); // dataroot
    stream.writeEndDocument();

    return true;
    //*******************************



}QString mdbexport::creatBooKDir()
{
    QVariant idx;
    int index=ui->comboBox->currentIndex();
    idx=ui->comboBox->itemData(index);
  QString  groupeId=idx.toString();
    //انشاء مجلد الكتاب******************************************
    QString mbookDir;
    QString newBooName=  Messages->geniratNewBookName(groupeId);
    QDir newdir= m_path+"/"+ newBooName;
    if (!newdir.exists()){
        QDir dir(m_path );
        dir.mkdir( newBooName);
        mbookDir=newBooName;
       // m_newPath=m_path+"/"+ newBooName;
    }else{
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
                dir.mkdir( newBooName+"_"+ m.toString());
                mbookDir=newBooName+"_"+ m.toString();
              //  m_newPath=path+"/"+ newBooName+"_"+ m.toString();
                exit=true;
            }
        }
    }
    return mbookDir;
    //******************************************************************
}
bool mdbexport::creatInfo(QString bookdir)
{
    QVariant idx;
    int index=ui->comboBox->currentIndex();
    idx=ui->comboBox->itemData(index);
  QString  groupeId=idx.toString();
    //اظافة معلومات الى المكتبة
    QString Add_Book_Name=ui->lineEdit_booknam->text();
    QString Add_Autor_Name =ui->lineEdit_autor->text()  ;
    QString Add_Betaka=ui->textEdit->toPlainText();

    bool checked=false;
    if (ui->checkBox_curan->checkState()==Qt::Checked) {
        checked=true;
    }
     Messages->m_pathCostum=m_path;
    if (Messages->addNewBook(bookdir,Add_Book_Name,Add_Autor_Name,Add_Betaka,groupeId,checked)==false)
    {
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما احد بيانات الكتاب خاطئة ") );
       return false;

    } else{


       Messages->saveBookInfo(bookdir,Add_Book_Name,Add_Autor_Name,Add_Betaka);
return true;
          }
      return true;
}

void mdbexport::on_comboBox_currentIndexChanged(int index)
{
    QVariant idx;
//int index=ui->comboBox->currentIndex();
    idx=ui->comboBox->itemData(index);
 //  m_addGroupeId=idx.toString();
//    m_addGroupeName= ui->comboBox->itemText(index);
    if (idx.toString()=="28")
    {
        ui->checkBox_curan->setVisible(true);
    }
    else{
        ui->checkBox_curan->setVisible(false);
        ui->checkBox_curan->setChecked(false);
    }
}


