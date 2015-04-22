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
#include "dialogmdb.h"
#include <QMessageBox>
#include  "ui_dialogmdb.h"
#include <QtSql>   //for linux
//#include <QtSQL>   //for windows
//#include  "qsql_odbc.cpp"
//#include  "qsql_odbc.h"

#include <QtGui>
Dialogmdb::Dialogmdb(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialogmdb)
{

    ui->setupUi(this);

    ui->toolButtonInfo->setIcon(style()->standardPixmap(QStyle::SP_MessageBoxInformation));
    ui->toolButton_fileNam->setIcon(style()->standardPixmap(QStyle::SP_DirOpenIcon));
  ui->progressBar->setVisible(false);
    Messages = new messages();
//    m_path=QCoreApplication::applicationDirPath ();
 m_path=QDir::homePath()+"/.kirtasse";
    Messages->comboCharge(ui->comboBox);

  if   ( QSqlDatabase::addDatabase("QODBC").isValid())
    {

       m_db= QSqlDatabase::addDatabase("QODBC");
  }else{
       QMessageBox::information(this, "conection", "QODBC driver not loaded");
       this->close();
 }

}
Dialogmdb::~Dialogmdb()
{

}

void Dialogmdb::on_toolButton_fileNam_clicked()
{
    QStringList fn = QFileDialog::getOpenFileNames(this, tr("Open File..."),
                                              QString(), trUtf8("ملفات الشاملة (*.mdb *.bok);;كل الملفات (*)"));
    if (!fn.isEmpty())
    {
       ui->listWidget->addItems(fn);

    }
}


void Dialogmdb::creatBook(QString fn)
{
    listId.clear();
    QFile file;
    if (!file.exists( fn)) //التاكد من وجود مجلد الكتاب
    {
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("غير موجود")+fn);
        return;
    }

    //***********************************************بدأ عملية الفتح والتحويل



    m_db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+fn);


    if (m_db.open())

    {
        if (fn.contains(".bok")){

            QSqlQuery  *modelsInfo;
            modelsInfo=new QSqlQuery;
            modelsInfo->exec("SELECT * FROM Main");
            while (modelsInfo->next())
            {
                tableBook="b"+modelsInfo->record().field("BkId").value().toString();
                tableTitle="t"+modelsInfo->record().field("BkId").value().toString();
                Add_Book_Name=(modelsInfo->record().field("Bk").value().toString());
                Add_Autor_Name=(modelsInfo->record().field("Auth").value().toString());
                Add_Betaka=(modelsInfo->record().field("Betaka").value().toString());
                // QMessageBox::information(this,trUtf8("خطأ"),tableTitle);
            }
        }else if(fn.contains(".mdb")){
            tableBook="book";
            tableTitle="title";
            QFileInfo fi=fn;
            Add_Book_Name=fi.fileName();
        }
        // QMessageBox::information(this, "conection", "succided");
        QSqlQuery  *models;
        models=new QSqlQuery;


        models->exec("SELECT * FROM "+tableBook+" ORDER BY id ASC");
        if (!models->record().field("nass").isValid() || !models->record().field("id").isValid()
            || !models->record().field("page").isValid()){
            QMessageBox::information(this, "conection", "mdb non valid");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        //انشاء مجلد الكتاب******************************************
        if (creatDir()==false){
            return;
        }
        //******************************************************************

        //بداية الكتابة في الوثيقة*************************************************
        //ملف النصوص****************************************
        QXmlStreamWriter stream;
        QFile filx(m_path +"/"+m_bookDir+"/book.xml");
        if (!filx.open(QFile::WriteOnly | QFile::Text)) {
            QApplication::restoreOverrideCursor();
            return ;
        }
        stream.setDevice(&filx);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("dataroot");

        ui->progressBar->setVisible(true);
       ui->progressBar->setMaximum(0);
        QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
        QTextCodec *codec = QTextCodec::codecForName("Windows-1256");
        stream.setCodec(QTextCodec::codecForName("UTF-8"));

        while (models->next())
        {
qApp->processEvents();
            ui->progressBar->setValue(1);

            QByteArray string;

            string=models->record().field("nass").value().toByteArray();

            QString nass = codec->toUnicode(string);
            string=models->record().field("id").value().toByteArray();
            QString id=codec->toUnicode(string);
            string=models->record().field("part").value().toByteArray();
            QString part=codec->toUnicode(string);
            string=models->record().field("page").value().toByteArray();
            QString page=codec->toUnicode(string);


            stream.writeStartElement("book");//"book" or "title"
            stream.writeTextElement("nass", nass);
            stream.writeTextElement("id", id);
            listId.append(id);
            stream.writeTextElement("part", part);
            stream.writeTextElement("page", page);
            stream.writeEndElement(); // book table
        }
        stream.writeEndElement(); // dataroot
        stream.writeEndDocument();
        filx.close();
        //ملف الفهرسة****************************************
        QSqlQuery  *modeltitle;
        modeltitle=new QSqlQuery;
        modeltitle->exec("SELECT * FROM "+tableTitle+" ORDER BY id ASC");
        QFile filt(m_path +"/"+m_bookDir+"/title.xml");
        if (!filt.open(QFile::WriteOnly | QFile::Text)) {
            QApplication::restoreOverrideCursor();
            return ;
        }
        stream.setDevice(&filt);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("dataroot");
        while (modeltitle->next())
        {
qApp->processEvents();
            ui->progressBar->setValue(1);

            QByteArray string;
            string=modeltitle->record().field("tit").value().toByteArray();
            QString tit = codec->toUnicode(string);

            string=modeltitle->record().field("lvl").value().toByteArray();
            QString lvl = codec->toUnicode(string);

            string=modeltitle->record().field("id").value().toByteArray();
            QString id = codec->toUnicode(string);
            int newid=listId.indexOf(id);
            if (newid==-1){newid=0;}
            QVariant dd= newid+1;
            id=dd.toString();



            stream.writeStartElement("title");//"book" or "title"
            stream.writeTextElement("tit", tit);
            stream.writeTextElement("id", id);
            stream.writeTextElement("lvl", lvl);
            stream.writeEndElement(); // title table
        }
        stream.writeEndElement(); // dataroot
        stream.writeEndDocument();
        filt.close();

    }
    //اظافة معلومات الى المكتبة


    bool checked=false;
    if (ui->checkBox_curan->checkState()==Qt::Checked) {
        checked=true;
    }
    Messages->m_pathCostum=m_path;
    if (Messages->addNewBook(m_bookDir,Add_Book_Name,Add_Autor_Name,Add_Betaka,m_addGroupeId,checked)==false)
    {

        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما احد بيانات الكتاب خاطئة ") );

        return;
    }
    else
    {
        Messages->saveBookInfo(m_bookDir,Add_Book_Name,Add_Autor_Name,Add_Betaka);



       // QMessageBox::information(this,trUtf8("معلومات"),Add_Book_Name +"\n"+m_bookDir);

    }
    msgTitle=msgTitle+trUtf8("الكتاب :")+Add_Book_Name+trUtf8(" المسار :")+m_bookDir+"\n";
    Add_Book_Name="";
    Add_Autor_Name ="";
    Add_Betaka="";

    m_db.close();
}

void Dialogmdb::on_comboBox_currentIndexChanged(int index)
{
    QVariant idx;
    idx=ui->comboBox->itemData(index);
    m_addGroupeId=idx.toString();
    m_addGroupeName= ui->comboBox->itemText(index);
    if (idx.toString()=="1")
    {
        ui->checkBox_curan->setVisible(true);
    }
    else{
        ui->checkBox_curan->setVisible(false);
        ui->checkBox_curan->setChecked(false);
    }

}




void Dialogmdb::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok)
    {
        int countItem=ui->listWidget->count();
        if (countItem<1)
            this->reject();


        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        for(int i=0;i<countItem;i++){
            ui->label_6->setText(trUtf8(" الرجاء الانتظار جاري انشاء الكتاب")+QString::number(i)+" / "+ QString::number(countItem));
            QString filname= ui->listWidget->item(i)->text();
            creatBook(filname);
qApp->processEvents();

        }
         QApplication::restoreOverrideCursor();
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

         } //msg
         this->accept();
    }
}
bool Dialogmdb::creatDir()
{
    QString newBooName=  Messages->geniratNewBookName(m_addGroupeId);
       QDir newdir= m_path+"/"+ newBooName;
       if (!newdir.exists()){
           QDir dir(m_path );
           dir.mkdir( newBooName);
           m_bookDir=newBooName;
           m_newPath=m_path+"/"+ newBooName;
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
                   m_bookDir=newBooName+"_"+ m.toString();
                   m_newPath=path+"/"+ newBooName+"_"+ m.toString();
                   exit=true;
               }
           }
       }
       return true;
}

void Dialogmdb::on_toolButtonDelete_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()){

        int x=ui->listWidget->currentRow();
        ui->listWidget->takeItem(x);
    }
}

void Dialogmdb::on_toolButtonInfo_clicked()
{

    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (!item->isSelected())
       return;

    QString fn=ui->listWidget->currentItem()->text();

    if (fn.contains(".bok")){
        m_db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+fn);
        if (m_db.open()){
            QSqlQuery  *modelsInfo;
            modelsInfo=new QSqlQuery;
            modelsInfo->exec("SELECT * FROM Main");
            while (modelsInfo->next())
            {

                QString titleName=(modelsInfo->record().field("Bk").value().toString());
                QString AutorName=(modelsInfo->record().field("Auth").value().toString());
                QString BetakaName=(modelsInfo->record().field("Betaka").value().toString());
                QMessageBox::information(this,trUtf8("معلومات الكتاب"),titleName+"\n"+
                                         AutorName+"\n"+
                                         BetakaName+"\n");
            }
        }
    }else if(fn.contains(".mdb")){
        QMessageBox::information(this,trUtf8("معلومات الكتاب"),trUtf8("مالفات من نوع mdb لاتحمل معلومات عن الكتاب \n يمكنك اضافتها يدويا بعد اضافة الكتاب"));

    }
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
#include "dialogmdb.h"
#include <QMessageBox>
#include  "ui_dialogmdb.h"
#include <QtSql>   //for linux
//#include <QtSQL>   //for windows
//#include  "qsql_odbc.cpp"
//#include  "qsql_odbc.h"

#include <QtGui>
Dialogmdb::Dialogmdb(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialogmdb)
{

    ui->setupUi(this);

    ui->toolButtonInfo->setIcon(style()->standardPixmap(QStyle::SP_MessageBoxInformation));
    ui->toolButton_fileNam->setIcon(style()->standardPixmap(QStyle::SP_DirOpenIcon));
  ui->progressBar->setVisible(false);
    Messages = new messages();
//    m_path=QCoreApplication::applicationDirPath ();
 m_path=QDir::homePath()+"/.kirtasse";
    Messages->comboCharge(ui->comboBox);

  if   ( QSqlDatabase::addDatabase("QODBC").isValid())
    {

       m_db= QSqlDatabase::addDatabase("QODBC");
  }else{
       QMessageBox::information(this, "conection", "QODBC driver not loaded");
       this->close();
 }

}
Dialogmdb::~Dialogmdb()
{

}

void Dialogmdb::on_toolButton_fileNam_clicked()
{
    QStringList fn = QFileDialog::getOpenFileNames(this, tr("Open File..."),
                                              QString(), trUtf8("ملفات الشاملة (*.mdb *.bok);;كل الملفات (*)"));
    if (!fn.isEmpty())
    {
       ui->listWidget->addItems(fn);

    }
}


void Dialogmdb::creatBook(QString fn)
{
    listId.clear();
    QFile file;
    if (!file.exists( fn)) //التاكد من وجود مجلد الكتاب
    {
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("غير موجود")+fn);
        return;
    }

    //***********************************************بدأ عملية الفتح والتحويل



    m_db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+fn);


    if (m_db.open())

    {
        if (fn.contains(".bok")){

            QSqlQuery  *modelsInfo;
            modelsInfo=new QSqlQuery;
            modelsInfo->exec("SELECT * FROM Main");
            while (modelsInfo->next())
            {
                tableBook="b"+modelsInfo->record().field("BkId").value().toString();
                tableTitle="t"+modelsInfo->record().field("BkId").value().toString();
                Add_Book_Name=(modelsInfo->record().field("Bk").value().toString());
                Add_Autor_Name=(modelsInfo->record().field("Auth").value().toString());
                Add_Betaka=(modelsInfo->record().field("Betaka").value().toString());
                // QMessageBox::information(this,trUtf8("خطأ"),tableTitle);
            }
        }else if(fn.contains(".mdb")){
            tableBook="book";
            tableTitle="title";
            QFileInfo fi=fn;
            Add_Book_Name=fi.fileName();
        }
        // QMessageBox::information(this, "conection", "succided");
        QSqlQuery  *models;
        models=new QSqlQuery;


        models->exec("SELECT * FROM "+tableBook+" ORDER BY id ASC");
        if (!models->record().field("nass").isValid() || !models->record().field("id").isValid()
            || !models->record().field("page").isValid()){
            QMessageBox::information(this, "conection", "mdb non valid");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        //انشاء مجلد الكتاب******************************************
        if (creatDir()==false){
            return;
        }
        //******************************************************************

        //بداية الكتابة في الوثيقة*************************************************
        //ملف النصوص****************************************
        QXmlStreamWriter stream;
        QFile filx(m_path +"/"+m_bookDir+"/book.xml");
        if (!filx.open(QFile::WriteOnly | QFile::Text)) {
            QApplication::restoreOverrideCursor();
            return ;
        }
        stream.setDevice(&filx);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("dataroot");

        ui->progressBar->setVisible(true);
       ui->progressBar->setMaximum(0);
        QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
        QTextCodec *codec = QTextCodec::codecForName("Windows-1256");
        stream.setCodec(QTextCodec::codecForName("UTF-8"));

        while (models->next())
        {
qApp->processEvents();
            ui->progressBar->setValue(1);

            QByteArray string;

            string=models->record().field("nass").value().toByteArray();

            QString nass = codec->toUnicode(string);
            string=models->record().field("id").value().toByteArray();
            QString id=codec->toUnicode(string);
            string=models->record().field("part").value().toByteArray();
            QString part=codec->toUnicode(string);
            string=models->record().field("page").value().toByteArray();
            QString page=codec->toUnicode(string);


            stream.writeStartElement("book");//"book" or "title"
            stream.writeTextElement("nass", nass);
            stream.writeTextElement("id", id);
            listId.append(id);
            stream.writeTextElement("part", part);
            stream.writeTextElement("page", page);
            stream.writeEndElement(); // book table
        }
        stream.writeEndElement(); // dataroot
        stream.writeEndDocument();
        filx.close();
        //ملف الفهرسة****************************************
        QSqlQuery  *modeltitle;
        modeltitle=new QSqlQuery;
        modeltitle->exec("SELECT * FROM "+tableTitle+" ORDER BY id ASC");
        QFile filt(m_path +"/"+m_bookDir+"/title.xml");
        if (!filt.open(QFile::WriteOnly | QFile::Text)) {
            QApplication::restoreOverrideCursor();
            return ;
        }
        stream.setDevice(&filt);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("dataroot");
        while (modeltitle->next())
        {
qApp->processEvents();
            ui->progressBar->setValue(1);

            QByteArray string;
            string=modeltitle->record().field("tit").value().toByteArray();
            QString tit = codec->toUnicode(string);

            string=modeltitle->record().field("lvl").value().toByteArray();
            QString lvl = codec->toUnicode(string);

            string=modeltitle->record().field("id").value().toByteArray();
            QString id = codec->toUnicode(string);
            int newid=listId.indexOf(id);
            if (newid==-1){newid=0;}
            QVariant dd= newid+1;
            id=dd.toString();



            stream.writeStartElement("title");//"book" or "title"
            stream.writeTextElement("tit", tit);
            stream.writeTextElement("id", id);
            stream.writeTextElement("lvl", lvl);
            stream.writeEndElement(); // title table
        }
        stream.writeEndElement(); // dataroot
        stream.writeEndDocument();
        filt.close();

    }
    //اظافة معلومات الى المكتبة


    bool checked=false;
    if (ui->checkBox_curan->checkState()==Qt::Checked) {
        checked=true;
    }
    Messages->m_pathCostum=m_path;
    if (Messages->addNewBook(m_bookDir,Add_Book_Name,Add_Autor_Name,Add_Betaka,m_addGroupeId,checked)==false)
    {

        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما احد بيانات الكتاب خاطئة ") );

        return;
    }
    else
    {
        Messages->saveBookInfo(m_bookDir,Add_Book_Name,Add_Autor_Name,Add_Betaka);



       // QMessageBox::information(this,trUtf8("معلومات"),Add_Book_Name +"\n"+m_bookDir);

    }
    msgTitle=msgTitle+trUtf8("الكتاب :")+Add_Book_Name+trUtf8(" المسار :")+m_bookDir+"\n";
    Add_Book_Name="";
    Add_Autor_Name ="";
    Add_Betaka="";

    m_db.close();
}

void Dialogmdb::on_comboBox_currentIndexChanged(int index)
{
    QVariant idx;
    idx=ui->comboBox->itemData(index);
    m_addGroupeId=idx.toString();
    m_addGroupeName= ui->comboBox->itemText(index);
    if (idx.toString()=="1")
    {
        ui->checkBox_curan->setVisible(true);
    }
    else{
        ui->checkBox_curan->setVisible(false);
        ui->checkBox_curan->setChecked(false);
    }

}




void Dialogmdb::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok)
    {
        int countItem=ui->listWidget->count();
        if (countItem<1)
            this->reject();


        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        for(int i=0;i<countItem;i++){
            ui->label_6->setText(trUtf8(" الرجاء الانتظار جاري انشاء الكتاب")+QString::number(i)+" / "+ QString::number(countItem));
            QString filname= ui->listWidget->item(i)->text();
            creatBook(filname);
qApp->processEvents();

        }
         QApplication::restoreOverrideCursor();
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

         } //msg
         this->accept();
    }
}
bool Dialogmdb::creatDir()
{
    QString newBooName=  Messages->geniratNewBookName(m_addGroupeId);
       QDir newdir= m_path+"/"+ newBooName;
       if (!newdir.exists()){
           QDir dir(m_path );
           dir.mkdir( newBooName);
           m_bookDir=newBooName;
           m_newPath=m_path+"/"+ newBooName;
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
                   m_bookDir=newBooName+"_"+ m.toString();
                   m_newPath=path+"/"+ newBooName+"_"+ m.toString();
                   exit=true;
               }
           }
       }
       return true;
}

void Dialogmdb::on_toolButtonDelete_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()){

        int x=ui->listWidget->currentRow();
        ui->listWidget->takeItem(x);
    }
}

void Dialogmdb::on_toolButtonInfo_clicked()
{

    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (!item->isSelected())
       return;

    QString fn=ui->listWidget->currentItem()->text();

    if (fn.contains(".bok")){
        m_db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+fn);
        if (m_db.open()){
            QSqlQuery  *modelsInfo;
            modelsInfo=new QSqlQuery;
            modelsInfo->exec("SELECT * FROM Main");
            while (modelsInfo->next())
            {

                QString titleName=(modelsInfo->record().field("Bk").value().toString());
                QString AutorName=(modelsInfo->record().field("Auth").value().toString());
                QString BetakaName=(modelsInfo->record().field("Betaka").value().toString());
                QMessageBox::information(this,trUtf8("معلومات الكتاب"),titleName+"\n"+
                                         AutorName+"\n"+
                                         BetakaName+"\n");
            }
        }
    }else if(fn.contains(".mdb")){
        QMessageBox::information(this,trUtf8("معلومات الكتاب"),trUtf8("مالفات من نوع mdb لاتحمل معلومات عن الكتاب \n يمكنك اضافتها يدويا بعد اضافة الكتاب"));

    }
}
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
