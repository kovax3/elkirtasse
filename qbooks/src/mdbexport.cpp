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
#include "mdbexport.h"
#include<QtGui>
#include <QTextStream>
#include  "ui_mdbexport.h"
mdbexport::mdbexport(QWidget *parent)
    : QDialog(parent), ui(new Ui::mdbexport)
{
    ui->setupUi(this);
    ui->toolButtonInfo->setIcon(style()->standardPixmap(QStyle::SP_MessageBoxInformation));
    ui->toolButton_fileNam->setIcon(style()->standardPixmap(QStyle::SP_DirOpenIcon));

    Messages = new messages();
    Messages->comboCharge(ui->comboBox);
    ui->progressBar->setVisible(false);
    m_tempDir=QDir::homePath()+"/.kirtasse/temp";
    QProcess prosses;
    prosses.execute(QString("mkdir -p %1").arg("\""+m_tempDir+"\""));
}
mdbexport::~mdbexport()
{
    QProcess prosses;

    prosses.execute(QString("rm -r  %1").arg("\""+m_tempDir+"\""));
    prosses.waitForFinished();
}
void mdbexport::criatBooks()
{

    int listCount=ui->listWidget->count();
    if (listCount==0)
        return;
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    for (int i=0;i<listCount;i++){
        ui->label_Info->setText(QString::number(i+1)+" / "+QString::number(listCount));
        QString mdbSource=ui->listWidget->item(i)->text();
        QProcess prosses;
        prosses.execute(QString("mkdir -p %1").arg("\""+m_tempDir+"\""));
        prosses.waitForFinished();

        if (mdbSource.contains(".bok")){
            if(creatBash(mdbSource,"bok")==true){
                QProcess prosses;
                prosses.execute(m_tempDir+"/out");
                prosses.waitForFinished();
            }
        }
        readMain(mdbSource);
        creatmdbTempFiles(mdbSource);
        prosses.execute(QString("rm -r  %1").arg("\""+m_tempDir+"\""));
        prosses.waitForFinished();

    }
    ui->progressBar->setVisible(false);
    QApplication::restoreOverrideCursor();
}
bool mdbexport::readMain(QString mdbSource)
{
    if (mdbSource.contains(".bok")){

<<<<<<< HEAD
        QList<QString> listHeader;
        //        enum  { NumIndex = 40};
        //        QString strHeaderName[NumIndex];
=======
 QList<QString> listHeader;
//        enum  { NumIndex = 40};
//        QString strHeaderName[NumIndex];
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        //*********************************
        QFile fileCsv(m_tempDir+"/main.csv");

        if (!fileCsv.open(QFile::ReadOnly)){
            return false;
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
<<<<<<< HEAD
                listHeader.append(line.section("|*|",-1));
=======
               listHeader.append(line.section("|*|",-1));
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
            }else{
                listHeader.append(line.section("|*|",i-1,i-1));
            }
        }

        line = textStream.readAll();//2 line

        for (int i=1;i<tab+2;i++){

            QString headerName=listHeader.at(i-1);
            QString strValue;
            if (i==tab+1){
                strValue=line.section("|*|",-1);
            }else{
                strValue=line.section("|*|",i-1,i-1);
            }
            //   QMessageBox::information(this,trUtf8("خطأ"),strHeaderName[i]+"  : "+strValue);
            if (headerName=="Bk"){
                //   ui->lineEdit_booknam->setText(strValue);
                m_bookTitle=strValue;
            }
            if (headerName=="Auth"){
                //                        ui->lineEdit_autor->setText(strValue);
                m_bookAuthor=strValue;
            }
            if (headerName=="Betaka"){
                //                        ui->textEdit->setText(strValue);
                m_bookBitaka=strValue;
            }
            if (headerName=="BkId"){
                tableBook="b"+strValue;
                tableTitle="t"+strValue;
            }

        }

        ui->label_Info->setText(ui->label_Info->text()+"..."+m_bookTitle);

    }else if(mdbSource.contains(".mdb")){
        QFileInfo fi=mdbSource;
        m_bookTitle=fi.fileName();
        tableBook="book";
        tableTitle="title";
    }
    return true;
}
bool mdbexport::creatmdbTempFiles(QString mdbSource)
{

<<<<<<< HEAD
    listId.clear();
=======
listId.clear();
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QDir dir;
    if (!dir.exists(m_tempDir)) //التاكد من وجود مجلد temp
        return false;



    if(creatBash(mdbSource,"mdb")==true){
        QProcess prosses;
        prosses.execute(m_tempDir+"/out");
        prosses.waitForFinished();
    }
    qApp->processEvents();
<<<<<<< HEAD
    QFile file;
    if(!file.exists(m_tempDir+"/tempbk.csv"))
        return false;
=======
QFile file;
    if(!file.exists(m_tempDir+"/tempbk.csv"))
    return false;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QString bookDir=creatBooKDir();


    if ( creatXmlFile(m_path+"/"+bookDir+"/book.xml","book","/tempbk.csv")==false){
        QMessageBox::information(this,trUtf8("خطأ"),trUtf8("لم استطع انشاء ملف الكتاب ربما لا تملك صلاحيات الكتابة"));
        return false;
    }

    creatXmlFile(m_path+"/"+bookDir+"/title.xml","title","/temptitle.csv");
    if (creatInfo(bookDir)==false){

        QMessageBox::information(this,trUtf8("معلومات"),trUtf8("no set"));
<<<<<<< HEAD
        return false;
    }
    //  QMessageBox::information(this,trUtf8("معلومات"),trUtf8("تمت عملية اظافة الكتاب بنجاح"));
=======
      return false;
    }
   //  QMessageBox::information(this,trUtf8("معلومات"),trUtf8("تمت عملية اظافة الكتاب بنجاح"));
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    return true;

}

void mdbexport::on_toolButton_fileNam_clicked()
{
    QStringList fn = QFileDialog::getOpenFileNames(this, tr("Open File..."),
<<<<<<< HEAD
                                                   QString(), trUtf8("ملفات الشاملة (*.mdb *.bok);;كل الملفات (*)"));
=======
                 QString(), trUtf8("ملفات الشاملة (*.mdb *.bok);;كل الملفات (*)"));
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    if (!fn.isEmpty())
    {
        ui->listWidget->addItems(fn);
    }

}
void mdbexport::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok){
        criatBooks();

        if(!msgTitle.isEmpty()){

            QMessageBox msgBox;
            msgBox.setText(trUtf8("لقد تم انشاء الكتب التالية بنجاح داخل المجموعة :  ")+m_addGroupeName );
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
bool mdbexport::creatBash(QString fn,QString asbok)
{

    QFile file(m_tempDir+"/out");
    file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
<<<<<<< HEAD
    file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
=======
 file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QTextStream out(&file);
    fn.replace(" ","\\ ");
    if (asbok=="bok"){
        out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
<<<<<<< HEAD
            <<  "mdb-export -d'|*|' -Q  "+fn+ " Main >> "+m_tempDir+"/main.csv";

    }else if(asbok=="mdb"){
        out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
            <<  "mdb-export -d'|*|' -Q  "+fn+ " "+tableBook+" >> "+m_tempDir+"/tempbk.csv"  <<"\n"
             <<  "mdb-export -d'|*|'  -Q  "+fn+ " "+tableTitle+" >> "+m_tempDir+"/temptitle.csv";
=======
                <<  "mdb-export -d'|*|' -Q  "+fn+ " Main >> "+m_tempDir+"/main.csv";

    }else if(asbok=="mdb"){
        out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
                <<  "mdb-export -d'|*|' -Q  "+fn+ " "+tableBook+" >> "+m_tempDir+"/tempbk.csv"  <<"\n"
                <<  "mdb-export -d'|*|'  -Q  "+fn+ " "+tableTitle+" >> "+m_tempDir+"/temptitle.csv";
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

    }


    return true;

}




bool mdbexport::creatXmlFile(QString f,QString table,QString csv)
{


<<<<<<< HEAD
    QList<QString> listHeader;
    QXmlStreamWriter stream;
    //    enum  { NumIndex = 10};
    //    QString strHeaderName[NumIndex];
=======
     QList<QString> listHeader;
    QXmlStreamWriter stream;
//    enum  { NumIndex = 10};
//    QString strHeaderName[NumIndex];
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    //*********************************
    QFile fileCsv(m_tempDir+csv);

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
<<<<<<< HEAD
            listHeader.append(line.section("|*|",-1));
        }else{
            listHeader.append(line.section("|*|",i-1,i-1));
=======
          listHeader.append(line.section("|*|",-1));
        }else{
           listHeader.append(line.section("|*|",i-1,i-1));
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        }

    }
    //*********************ecrir
    QFile file(f);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        return false;
    }

    stream.setDevice(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("dataroot");
    ui->progressBar->setVisible(true);
<<<<<<< HEAD
    ui->progressBar->setMaximum(0);

    while (!line.isNull()) {
=======
     ui->progressBar->setMaximum(0);

     while (!line.isNull()) {
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

        qApp->processEvents();
        ui->progressBar->setValue(1);
        line = textStream.readLine();
<<<<<<< HEAD
        if(!line.isEmpty()){
            //   QMessageBox::information(this,trUtf8("خطأ"),line);
            stream.writeStartElement(table);//"book" or "title"
            //**************************************start book

            for (int i=1;i<tab+2;i++){
                QString headerName=listHeader.at(i-1);
                QString strValue;
                if (i==tab+1){
                    strValue=line.section("|*|",-1);
                }else{
                    strValue=line.section("|*|",i-1,i-1);
                }
                if (strValue.isEmpty() || strValue==0){strValue="1";}
                if (headerName=="hno" || headerName=="na" || headerName=="sub"){
                    //*--
                }else if(headerName=="id"){
                    if (table=="book"){
                        listId.append(strValue);
                    }else{
                        int newid=listId.indexOf(strValue);
                        if (newid==-1){newid=0;}
                        QVariant dd= newid+1;
                        strValue=dd.toString();
                    }

                    stream.writeTextElement(headerName, strValue);
                }else{

                    stream.writeTextElement(headerName, strValue);
                }
            }
            stream.writeEndElement(); // book table
            //***************************************    end book
        }
    }
=======
if(!line.isEmpty()){
     //   QMessageBox::information(this,trUtf8("خطأ"),line);
        stream.writeStartElement(table);//"book" or "title"
        //**************************************start book

        for (int i=1;i<tab+2;i++){
            QString headerName=listHeader.at(i-1);
            QString strValue;
            if (i==tab+1){
                strValue=line.section("|*|",-1);
            }else{
                strValue=line.section("|*|",i-1,i-1);
            }
             if (strValue.isEmpty() || strValue==0){strValue="1";}
            if (headerName=="hno" || headerName=="na" || headerName=="sub"){
                //*--
            }else if(headerName=="id"){
                if (table=="book"){
                    listId.append(strValue);
                }else{
                    int newid=listId.indexOf(strValue);
                    if (newid==-1){newid=0;}
                    QVariant dd= newid+1;
                    strValue=dd.toString();
                }

                stream.writeTextElement(headerName, strValue);
            }else{

                stream.writeTextElement(headerName, strValue);
            }
        }
        stream.writeEndElement(); // book table
        //***************************************    end book
    }
 }
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    stream.writeEndElement(); // dataroot
    stream.writeEndDocument();

    return true;
    //*******************************



}QString mdbexport::creatBooKDir()
{
    QVariant idx;
    int index=ui->comboBox->currentIndex();
    idx=ui->comboBox->itemData(index);
<<<<<<< HEAD
    QString  groupeId=idx.toString();
=======
  QString  groupeId=idx.toString();
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    //انشاء مجلد الكتاب******************************************
    QString mbookDir;
    QString newBooName=  Messages->geniratNewBookName(groupeId);
    QDir newdir= m_path+"/"+ newBooName;
    if (!newdir.exists()){
        QDir dir(m_path );
        dir.mkdir( newBooName);
        mbookDir=newBooName;
<<<<<<< HEAD
        // m_newPath=m_path+"/"+ newBooName;
=======
       // m_newPath=m_path+"/"+ newBooName;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
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
<<<<<<< HEAD
                //  m_newPath=path+"/"+ newBooName+"_"+ m.toString();
=======
              //  m_newPath=path+"/"+ newBooName+"_"+ m.toString();
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
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
<<<<<<< HEAD
    QString  groupeId=idx.toString();
=======
  QString  groupeId=idx.toString();
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    //اظافة معلومات الى المكتبة
    QString Add_Book_Name=m_bookTitle;
    QString Add_Autor_Name =m_bookAuthor;
    QString Add_Betaka=m_bookBitaka;

    bool checked=false;
    if (ui->checkBox_curan->checkState()==Qt::Checked) {
        checked=true;
    }
<<<<<<< HEAD
    Messages->m_pathCostum=m_path;
    if (Messages->addNewBook(bookdir,Add_Book_Name,Add_Autor_Name,Add_Betaka,groupeId,checked)==false)
    {
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما احد بيانات الكتاب خاطئة ") );
        return false;
=======
     Messages->m_pathCostum=m_path;
    if (Messages->addNewBook(bookdir,Add_Book_Name,Add_Autor_Name,Add_Betaka,groupeId,checked)==false)
    {
        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("ربما احد بيانات الكتاب خاطئة ") );
       return false;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

    } else{


<<<<<<< HEAD
        Messages->saveBookInfo(bookdir,Add_Book_Name,Add_Autor_Name,Add_Betaka);

    }
    msgTitle=msgTitle+Add_Book_Name+"\n"+
            trUtf8("المسار :")+m_path+"/"+bookdir+"\n";
    return true;
=======
       Messages->saveBookInfo(bookdir,Add_Book_Name,Add_Autor_Name,Add_Betaka);

          }
     msgTitle=msgTitle+Add_Book_Name+"\n"+
              trUtf8("المسار :")+m_path+"/"+bookdir+"\n";
      return true;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}

void mdbexport::on_comboBox_currentIndexChanged(int index)
{


    QVariant idx;
<<<<<<< HEAD
    //int index=ui->comboBox->currentIndex();
    idx=ui->comboBox->itemData(index);

    m_addGroupeName= ui->comboBox->itemText(index);
=======
   //int index=ui->comboBox->currentIndex();
       idx=ui->comboBox->itemData(index);

  m_addGroupeName= ui->comboBox->itemText(index);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    if (idx.toString()=="28")
    {
        ui->checkBox_curan->setVisible(true);
    }
    else{
        ui->checkBox_curan->setVisible(false);
        ui->checkBox_curan->setChecked(false);
    }
}



void mdbexport::on_toolButtonInfo_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (!item->isSelected())
<<<<<<< HEAD
        return;
=======
       return;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

    QString itemtxt=ui->listWidget->currentItem()->text();

    if (itemtxt.contains(".mdb")){
        QMessageBox::information(this,trUtf8("معلومات الكتاب"),trUtf8("مالفات من نوع mdb لاتحمل معلومات عن الكتاب \n يمكنك اضافتها يدويا بعد اضافة الكتاب"));
<<<<<<< HEAD
        return;
    }

    if(creatBash(itemtxt,"bok")==true){
        QProcess prosses;
        prosses.execute(m_tempDir+"/out");
        prosses.waitForFinished();
        if(readMain(itemtxt)==true){
            QMessageBox::information(this,trUtf8("معلومات الكتاب"),m_bookTitle+"\n"+
                                     m_bookAuthor+"\n"+
                                     m_bookBitaka+"\n");

        }
        prosses.execute("rm "+m_tempDir+"/out");
        prosses.execute("rm "+m_tempDir+"/main.csv");
=======
    return;
    }

    if(creatBash(itemtxt,"bok")==true){
    QProcess prosses;
    prosses.execute(m_tempDir+"/out");
    prosses.waitForFinished();
    if(readMain(itemtxt)==true){
         QMessageBox::information(this,trUtf8("معلومات الكتاب"),m_bookTitle+"\n"+
                                  m_bookAuthor+"\n"+
                                  m_bookBitaka+"\n");

    }
     prosses.execute("rm "+m_tempDir+"/out");
     prosses.execute("rm "+m_tempDir+"/main.csv");
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    }
}

void mdbexport::on_toolButton_delet_clicked()
{
    if (ui->listWidget->count()==0){return;}
    QListWidgetItem *item=ui->listWidget->currentItem();
    if (item->isSelected()){

        int x=ui->listWidget->currentRow();
        ui->listWidget->takeItem(x);
    }
}

//-------------------EBOOK--------------------------------------

void mdbexport::criateEbookContent()
{
    QString title;
    QString author;
    QString textConten=QString(
<<<<<<< HEAD
                " <?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                "<package xmlns=\"http://www.idpf.org/2007/opf\" unique-identifier=\"BookID\" version=\"2.0\">"
                " <metadata xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:opf=\"http://www.idpf.org/2007/opf\">"
                "<dc:title> 1% </dc:title>"
                "  <dc:creator opf:role=\"aut\"> 2% </dc:creator>"
                "<dc:publisher>http://elkirtasse.ws</dc:publisher>"
                "<dc:language>ar</dc:language>"
                "<dc:identifier id=\"BookID\" opf:scheme=\"UUID\">urn:uuid:52c0ee2aaf4ca262c96145e220f0cf67</dc:identifier>"
                "</metadata>"
                "<manifest>"
                "<item id=\"ncx\" href=\"toc.ncx\" media-type=\"application/x-dtbncx+xml\"/>"
                "<item id=\"stylesheet\" href=\"style.css\" media-type=\"text/css\"/>"
                " <item id=\"logo\" href=\"img/logo.png\" media-type=\"image/png\"/>"
                "<item id=\"info\" href=\"xhtml/info.xhtml\" media-type=\"application/xhtml+xml\"/>"
                " <item id=\"P2\" href=\"xhtml/P2.xhtml\" media-type=\"application/xhtml+xml\"/>"
                "</manifest>"
                "<spine toc=\"ncx\">"
                "<itemref idref=\"info\"/>"
                "<itemref idref=\"P2\"/>"
                "</spine>"
                "</package>"    ).arg(title).arg(author);
=======
" <?xml version=\"1.0\" encoding=\"UTF-8\"?>"
  "<package xmlns=\"http://www.idpf.org/2007/opf\" unique-identifier=\"BookID\" version=\"2.0\">"
                         " <metadata xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:opf=\"http://www.idpf.org/2007/opf\">"
                                    "<dc:title> 1% </dc:title>"
                                    "  <dc:creator opf:role=\"aut\"> 2% </dc:creator>"
                                    "<dc:publisher>http://elkirtasse.ws</dc:publisher>"
                                    "<dc:language>ar</dc:language>"
                                   "<dc:identifier id=\"BookID\" opf:scheme=\"UUID\">urn:uuid:52c0ee2aaf4ca262c96145e220f0cf67</dc:identifier>"
                "</metadata>"
                "<manifest>"
                                 "<item id=\"ncx\" href=\"toc.ncx\" media-type=\"application/x-dtbncx+xml\"/>"
                                  "<item id=\"stylesheet\" href=\"style.css\" media-type=\"text/css\"/>"
                                 " <item id=\"logo\" href=\"img/logo.png\" media-type=\"image/png\"/>"
                                  "<item id=\"info\" href=\"xhtml/info.xhtml\" media-type=\"application/xhtml+xml\"/>"
                                  " <item id=\"P2\" href=\"xhtml/P2.xhtml\" media-type=\"application/xhtml+xml\"/>"
                    "</manifest>"
                   "<spine toc=\"ncx\">"
                                    "<itemref idref=\"info\"/>"
                                   "<itemref idref=\"P2\"/>"
                "</spine>"
 "</package>"    ).arg(title).arg(author);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e


}

<<<<<<< HEAD
void mdbexport::criateEbookToc()
{

}
=======
 void mdbexport::criateEbookToc()
 {

 }
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
