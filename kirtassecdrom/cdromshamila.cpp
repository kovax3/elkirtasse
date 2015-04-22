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
#include "cdromshamila.h"
#include "dialogcdrom.h"
<<<<<<< HEAD
#include "ui_Dialogcdrom.h"
=======
#include "ui_dialog.h"
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
#include <QMessageBox>
#ifdef   Q_WS_WIN
#include <QtSql>
#endif
QString cdromShamila::execPlugin()
{
    ///dosier temp

    QDir dir;
    QString h=dir.homePath();

    if (!dir.exists(h+"/.kirtasse/temp")) //التاكد من وجود مجلد المكتبة
    {
        dir.mkdir( h+"/.kirtasse/temp");
    }
    m_tempDir=QDir::homePath()+"/.kirtasse/temp";
//    QProcess prosses;
//    prosses.execute(QString("mkdir -p %1").arg("\""+m_tempDir+"\""));

    ///dialog pour les path
    Dialogcdrom *dlg =new Dialogcdrom();
    if ( dlg->exec() == QDialog::Accepted ){
        if (dlg->acceptedPath==false)
            return "";

        m_pathMain=dlg->pathMain;
        m_pathBooks=dlg->pathBooks;
        m_pathBooksNew=dlg->pathBooksNew;

        ///execution

#ifdef   Q_WS_WIN
        if (creatShamellaWin()==true){
            if(QFile::exists(QDir::homePath()+"/.kirtasse/data/group.xml.old"))
                QFile::remove(QDir::homePath()+"/.kirtasse/data/group.xml.old") ;

            QFile::rename(QDir::homePath()+"/.kirtasse/data/group.xml",QDir::homePath()+"/.kirtasse/data/group.xml.old");
            QFile::copy(m_tempDir+"/0cat.xml",QDir::homePath()+"/.kirtasse/data/group.xml");
            return m_pathBooksNew;

        }
#else


        if (creatShamellaX()==true){
            if(QFile::exists(QDir::homePath()+"/.kirtasse/data/group.xml.old"))
                QFile::remove(QDir::homePath()+"/.kirtasse/data/group.xml.old") ;

            QFile::rename(QDir::homePath()+"/.kirtasse/data/group.xml",QDir::homePath()+"/.kirtasse/data/group.xml.old");
            QFile::copy(m_tempDir+"/0cat.xml",QDir::homePath()+"/.kirtasse/data/group.xml");
            return m_pathBooksNew;

        }
#endif

        // return dlg->mypath;
    }
    return "";
}

//************************win************************//
#ifdef   Q_WS_WIN
bool cdromShamila:: creatShamellaWin()
{

    if   ( QSqlDatabase::addDatabase("QODBC").isValid())
      {
         m_db= QSqlDatabase::addDatabase("QODBC");
    }else{
         QMessageBox::information(0, "conection", "QODBC driver not loaded");
        return false;
   }
if (winCreatgroupXml()==true)
  winCreatBooks();

return true;

}

bool cdromShamila::winCreatgroupXml()
{

    m_db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+m_pathMain);

    if (!m_db.open())
         return false;

    QSqlQuery  *modelCat;
    modelCat=new QSqlQuery;
    modelCat->exec("SELECT * FROM 0cat");
    QFile file(m_tempDir+"/0cat.xml");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        return false;
    }

    QXmlStreamWriter stream;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec *codec = QTextCodec::codecForName("Windows-1256");
    stream.setCodec(QTextCodec::codecForName("UTF-8"));
    stream.setDevice(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("setting");
    stream.writeStartElement("root");
    stream.writeAttribute("Name",trUtf8("كتب الشاملة"));
    stream.writeAttribute("id", "0");
    QProgressDialog progress(trUtf8("الرجاء الانتظار..جاري انشاءقائمة للكتب"), trUtf8("الغاء"), 0,0, 0);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();
     qApp->processEvents();
    while (modelCat->next())
    {
         stream.writeStartElement("Item");//
         QByteArray string;

         string=modelCat->record().field("name").value().toByteArray();
          QString catName=codec->toUnicode(string);

          string=modelCat->record().field("id").value().toByteArray();
          QString catId=codec->toUnicode(string);

          stream.writeAttribute("id", catId);
          stream.writeAttribute("Name", catName);
          stream.writeEndElement();
    }
    stream.writeEndElement(); // root
    stream.writeEndElement(); // setting
    stream.writeEndDocument();
   //**********************
    QSqlQuery  *modelBk;
    modelBk=new QSqlQuery;
    modelBk->exec("SELECT * FROM 0bok");
 file.close();
    if (!m_doc.setContent(&file)){
         QMessageBox::information(0,"","nodoc");
        return false;
    }
    file.close();

    tbcount=0;
    while (modelBk->next())
    {
        tbcount++;
        progress.setValue(tbcount);
         qApp->processEvents();
        QByteArray string;
        string=modelBk->record().field("betaka").value().toByteArray();
        QString bkBetaka=codec->toUnicode(string);
        string=modelBk->record().field("bkid").value().toByteArray();
        QString bkId=codec->toUnicode(string);
        string=modelBk->record().field("auth").value().toByteArray();
        QString bkAut=codec->toUnicode(string);
        string=modelBk->record().field("bk").value().toByteArray();
        QString bkName=codec->toUnicode(string);
        string=modelBk->record().field("cat").value().toByteArray();
        QString bkCat=codec->toUnicode(string);

         addNewBook(bkId,bkName,bkAut,bkBetaka,bkCat);
    }
    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
    QTextStream out(&file);                        //الكتابة
    const int IndentSize = 1;
    m_doc.save(out,IndentSize);                      //حفظ الملف
    file.close();
   m_db.close();
  //QMessageBox::information(0,"","fin");

   return true;

}

bool cdromShamila::winCreatBooks()
{

    QDomElement racine = m_doc.documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.firstChild();


    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0,tbcount, 0);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();
    int vp=0;
    while(!noeud.isNull())
    {
        QDomNodeList tab;
        QDomNodeList tab2;
        QDomElement Root;
        Root=noeud.toElement();                   // تحديد اول عنصر من ابناء العنصر الاصلي
        if (Root.tagName()== "root")
        {
            tab = Root.childNodes();
            for(int i=0;i<(int)tab.length();++i)
            {

                QDomNode noeud2=tab.item(i);
                QDomElement Group=noeud2.toElement();
                tab2 = Group.childNodes();
                for(int r=0;r<(int)tab2.length();r++)
                {

                    vp++;
                   progress.setValue(vp);
                    QDomNode noeud3=tab2.item(r);
                    QDomElement Book=noeud3.toElement();

                    QString bookname=Book.attribute("id");
                    QString title=Book.attribute("name");
                    QString author=Book.attribute("aut");
                    QString betaka=Book.attribute("betaka");

                    QString id=bookname.section("_",-1);
                    QString dirName=id.right(1);
                    QString fileMdb=m_pathBooks+"/"+dirName+"/"+id+".mdb";
                    if (progress.wasCanceled())
                                 break;

                    progress.setLabelText(trUtf8("الرجاء الانتظار..جاري انشاء :")+title);
                   qApp->processEvents();
                    if (winWriteBooks(fileMdb,bookname)==true)
                        saveBookInfo( bookname, title, author, betaka);

                    //      QMessageBox::information(0,"",fileMdb+"\n"+m_pathBooksNew+"/"+bookname);

                }
            }
        }

        noeud = noeud.nextSibling();
    }
    progress.cancel();
    m_doc.clear();


     return true;
}
bool cdromShamila::winWriteBooks(QString fn,QString bookname)
{
    listId.clear();
    m_db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+fn);
      if (!m_db.open())
         return false;

       QDir dir(m_pathBooksNew );
      if (dir.mkdir(bookname)==false)
           return false;
      //********************************
      QSqlQuery  *models;
      models=new QSqlQuery;


      models->exec("SELECT * FROM book ORDER BY id ASC");




      //بداية الكتابة في الوثيقة*************************************************
      //ملف النصوص****************************************
      QXmlStreamWriter stream;
      QFile filx(m_pathBooksNew +"/"+bookname+"/book.xml");
      if (!filx.open(QFile::WriteOnly | QFile::Text)) {
          QApplication::restoreOverrideCursor();
          return false;
      }
      stream.setDevice(&filx);
      stream.setAutoFormatting(true);
      stream.writeStartDocument();
      stream.writeStartElement("dataroot");


      QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
      QTextCodec *codec = QTextCodec::codecForName("Windows-1256");
      stream.setCodec(QTextCodec::codecForName("UTF-8"));

      while (models->next())
      {
         qApp->processEvents();
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
      modeltitle->exec("SELECT * FROM title ORDER BY id ASC");
      QFile filt(m_pathBooksNew +"/"+bookname+"/title.xml");
      if (!filt.open(QFile::WriteOnly | QFile::Text)) {
          QApplication::restoreOverrideCursor();
          m_db.close();
          return true;
      }
      stream.setDevice(&filt);
      stream.setAutoFormatting(true);
      stream.writeStartDocument();
      stream.writeStartElement("dataroot");
      while (modeltitle->next())
      {
         qApp->processEvents();


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

  m_db.close();
 //QMessageBox::information(0,"",m_pathBooksNew+"/"+bookname);

  return true;

}
 #endif
//************************XXXX**********************//
bool cdromShamila::creatShamellaX()
{
    if (creatBashMain(m_pathMain)==false)
        return false;

    QProcess prosses;
    prosses.execute(m_tempDir+"/out");
    prosses.waitForFinished();

    if(creatCatigorie()==false)
           return false;
     if(  creatBooksInfo()==false)
           return false;

 return true;
}
//! [0]

bool cdromShamila::creatCatigorie()
{

    enum  { NumIndex = 5};
    QXmlStreamWriter stream;

    QString strHeaderName[NumIndex];
    //*********************************
    QFile fileCsv(m_tempDir+"/0cat.csv");

    if (!fileCsv.open(QFile::ReadOnly)){
        return false;
    }

    QTextStream textStream(&fileCsv);
    textStream.setCodec(QTextCodec::codecForName("Windows-1256"));


    QString line;
    line = textStream.readLine();//premier line

    int tab=  line.count("RRR");//nombre col
    for (int i=1;i<tab+2;i++){
        if (i==tab+1){
            strHeaderName[i]=line.section("RRR",-1);
        }else{
            strHeaderName[i]=line.section("RRR",i-1,i-1);
        }

    }
    //*********************ecrir
    QFile file(m_tempDir+"/0cat.xml");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        return false;
    }

    stream.setDevice(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("setting");
     stream.writeStartElement("root");
     stream.writeAttribute("Name",trUtf8("كتب الشاملة"));
      stream.writeAttribute("id", "0");
     while (!line.isNull()) {

        qApp->processEvents();

        line = textStream.readLine();

        if(!line.isEmpty()){
   //**************************************start cat
        stream.writeStartElement("Item");//


        for (int i=1;i<tab+2;i++){
            QString strValue;
            if (i==tab+1){
                strValue=line.section("RRR",-1);
            }else{
                strValue=line.section("RRR",i-1,i-1);
            }
             //if (strValue.isEmpty() || strValue==0){strValue="1";}

            if(strHeaderName[i]=="id"){
                stream.writeAttribute(strHeaderName[i], strValue);
            }else if(strHeaderName[i]=="name"){

                stream.writeAttribute("Name", strValue);
            }

        }
        stream.writeEndElement(); // book table
        //***************************************    end book
}
     }

    stream.writeEndElement(); // root
    stream.writeEndElement(); // setting
    stream.writeEndDocument();

    return true;
    //*******************************


}

bool cdromShamila::creatBashMain(QString fn)
{

    QFile file(m_tempDir+"/out");
    file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
    QTextStream out(&file);
    fn.replace(" ","\\ ");

    out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
        <<  "mdb-export -d 'RRR' -Q    -R  'BL'  "+fn+ " 0bok >> "+m_tempDir+"/0bok.csv"  <<"\n"
         <<  "mdb-export -d 'RRR'  -Q  "+fn+ " 0cat >> "+m_tempDir+"/0cat.csv";

    return true;

}

//! [0]
//! [1]
bool cdromShamila::creatBooksInfo()
{

    QFile file(m_tempDir+"/0cat.xml");

    //  if (!filepath.exists()){return false;}

    file.open(QIODevice::ReadOnly);
    if (!m_doc.setContent(&file)){return false;}
    file.close();

 QList<QString> listHeader;

    //*********************************
    QFile fileCsv(m_tempDir+"/0bok.csv");

    if (!fileCsv.open(QFile::ReadOnly)){
        return false;
    }

    QTextStream textStream(&fileCsv);
    textStream.setCodec(QTextCodec::codecForName("Windows-1256"));


    QString line;
    line = textStream.readLine();//premier line

    int tab=  line.count("RRR");//nombre col
    for (int i=1;i<tab+2;i++){
        if (i==tab+1){
          listHeader.append(line.section("RRR",-1));
        }else{
           listHeader.append(line.section("RRR",i-1,i-1));

        }

    }

    QString textcsv=textStream.readAll();
    int tb=  textcsv.count("BL");

    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0,tb, 0);

    progress.setWindowModality(Qt::WindowModal);


    progress.show();

    QString linecsv;
    for (int i=1;i<tb+2;i++){
        progress.setValue(i);
        if (i==tb+1){
            linecsv=textcsv.section("BL",-1);
        }else{
            linecsv=textcsv.section("BL",i-1,i-1);

        }


        QString bkBetaka;
        QString bkId;
        QString bkAut;
        QString bkName;
        QString bkCat;
        for (int i=1;i<tab+2;i++){
            QString strValue;

            if (i==tab+1){
                strValue=linecsv.section("RRR",-1);
            }else{
                strValue=linecsv.section("RRR",i-1,i-1);
            }
 QString headerName=listHeader.at(i-1);
            if(headerName=="id"){
                bkId=strValue;

            }else if(headerName=="bk"){

                bkName=strValue;

            }else if(headerName=="auth"){

                bkAut=strValue;


            }else if(headerName=="betaka"){

                bkBetaka=strValue;
            }else if(headerName=="cat"){

                bkCat=strValue;
            }else if(headerName=="bkid"){

                bkId=strValue;
            }



        }
        if (progress.wasCanceled())
                     break;

        QString dirName=bkId.right(1);
        QString fileMdb=m_pathBooks+"/"+dirName+"/"+bkId+".mdb";


        progress.setLabelText(bkName);
        qApp->processEvents();
        if(file.exists(fileMdb)){
             progress.setLabelText(trUtf8("الرجاء الانتظار..جاري انشاء :")+bkName);
        if( creatBook(bkId,bkCat)==true){

            addNewBook(bkId,bkName,bkAut,bkBetaka,bkCat);
            saveBookInfo("bk"+bkCat+"_"+ bkId,bkName,bkAut,bkBetaka);

        }
         }

        // line = textStream.readLine();

    }



progress.cancel();

    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
    QTextStream out(&file);                        //الكتابة
    const int IndentSize = 1;
    m_doc.save(out,IndentSize);                      //حفظ الملف
    file.close();
    m_doc.clear();
   // QMessageBox::information(0,"","fin");
    return true;
}

bool cdromShamila::addNewBook(QString bkpath,QString bktitle,QString bkauth,QString bkbetaka,QString groupid)
{

if (groupid.isEmpty())return false;
if (bkpath.isEmpty())return false;
if (bktitle.isEmpty())return false;
bool ok= bkpath.toInt();
if (ok==false)return false;


    QDomElement racine = m_doc.documentElement();                  //عنصر الشجرة الاصلي
    QDomNode noeud = racine.firstChild();                       // تحديد اول عنصر من ابناء العنصر الاصلي
    while(!noeud.isNull())                                       //كلما كان العنصر غير فارغا
    {
        QDomNodeList tab;

        QDomElement groupPer;
        groupPer=noeud.toElement();
        if (groupPer.tagName()== "root")                         //اذا كان اسم العنصر "root"
        {
            tab = groupPer.childNodes();                          //قائمة الابناء
            for(int i=0;i<(int)tab.length();++i)                        //عدد الابناء
            {
                QDomNode noeud2=tab.item(i);
                QDomElement mygroup=noeud2.toElement();
                if  (mygroup.attribute("id")==groupid)     //التوقف عند العنصر الذي اخترناه من المجموعة مثلا "التفاسير
                {
                    QDomElement myel=m_doc.createElement("bk");     //انشاء عنصر جديد
                    mygroup.appendChild(myel);                    //اظافته في اخر القائمة
                    myel.setAttribute("id","bk"+groupid+"_"+bkpath);        //اسم مجلد الكتاب
                    myel.setAttribute("name",bktitle);      //اسم الكتاب
                    myel.setAttribute("aut",bkauth);      //اسم المؤلف
                    myel.setAttribute("betaka", bkbetaka);      //بطاقة عن الكتاب




                    return true;                                         //انهاء العملية
                }
            }
        }
        noeud = noeud.nextSibling();
    }

    return true;
}

bool cdromShamila::creatBook(QString id,QString cat){
  listId.clear();
    QFile file;
    QProcess prosses;

    if(file.exists(m_tempDir+"/tempbk.csv")){
        prosses.execute("rm "+m_tempDir+"/tempbk.csv");
        prosses.waitForFinished();
        prosses.execute("rm "+m_tempDir+"/temptitle.csv");
        prosses.waitForFinished();
    }

    QString dirName=id.right(1);
    QString fileMdb=m_pathBooks+"/"+dirName+"/"+id+".mdb";

    //QMessageBox::information(0,"",fileMdb);

    if(file.exists(fileMdb)){
        creatBashMdb(fileMdb);
        prosses.execute(m_tempDir+"/out");
        prosses.waitForFinished();
        QDir dir;
        QString newBookPath=m_pathBooksNew+"/bk"+cat+"_"+id;
       //QMessageBox::information(0,"",newBookPath);
        dir.mkdir(newBookPath);
        qApp->processEvents();
        if(  creatXmlFile(newBookPath+"/book.xml","book",m_tempDir+"/tempbk.csv")==false)
            return false;

         creatXmlFile(newBookPath+"/title.xml","title",m_tempDir+"/temptitle.csv");



    }else{
   return false;
    }
     return true;
}

bool cdromShamila::creatBashMdb(QString fn)
{

    QFile file(m_tempDir+"/out");
    file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
 file.setPermissions(QFile::ExeUser | QFile::WriteUser | QFile::ReadUser);
    QTextStream out(&file);
    fn.replace(" ","\\ ");

        out << "#!/bin/sh" << "\n"<< "export MDB_ICONV='ISO8859-1'" <<"\n"
                <<  "mdb-export -d'RRR' -Q "+fn+ " book >> "+m_tempDir+"/tempbk.csv"  <<"\n"
                <<  "mdb-export -d'RRR'  -Q  "+fn+ " title >> "+m_tempDir+"/temptitle.csv";

    return true;

}

bool cdromShamila::creatXmlFile(QString f,QString table,QString csv)
{


 QList<QString> listHeader;

    QXmlStreamWriter stream;
//   enum  { NumIndex = 10};
 //QString strHeaderName[NumIndex];
    //*********************************
    QFile fileCsv(csv);

    if (!fileCsv.open(QFile::ReadOnly)){
        return false;
    }

    QTextStream textStream(&fileCsv);
    textStream.setCodec(QTextCodec::codecForName("Windows-1256"));


    QString line;
    line = textStream.readLine();//premier line

    int tab=  line.count("RRR");//nombre col
    for (int i=1;i<tab+2;i++){
        if (i==tab+1){
          listHeader.append(line.section("RRR",-1));
        }else{
        listHeader.append(line.section("RRR",i-1,i-1));
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



    while (!line.isNull()) {

        qApp->processEvents();

        line = textStream.readLine();
        if(!line.isEmpty()){
            //   QMessageBox::information(this,trUtf8("خطأ"),line);
            stream.writeStartElement(table);//"book" or "title"
            //**************************************start book

            for (int i=1;i<tab+2;i++){
                QString strValue;
                if (i==tab+1){
                    strValue=line.section("RRR",-1);
                }else{
                    strValue=line.section("RRR",i-1,i-1);
                }
                if (strValue.isEmpty() || strValue==0){strValue="1";}
       QString headerName=      listHeader.at(i-1);
                if( headerName=="hno" || headerName=="na" || headerName=="sub"){
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
                     if(headerName=="Sora"){
                         stream.writeTextElement("sora", strValue);
                     }else if(headerName=="Aya"){
                          stream.writeTextElement("aya", strValue);
                     }else{
                          stream.writeTextElement(headerName, strValue);
                     }

                }
            }
            stream.writeEndElement(); // book table
            //***************************************    end book
        }
    }

    stream.writeEndElement(); // dataroot
    stream.writeEndDocument();

    return true;
    //*******************************



}

bool cdromShamila::saveBookInfo(QString bookname,QString title,QString author,QString betaka)
{
    QFile file;
    QString path=m_pathBooksNew+"/"+bookname+"/bookinfo.info";

    file.setFileName(path);

    if(! file.open(QIODevice::WriteOnly)) {
        return false;
    }
    //فتح الملف للكتابة

    QString myxmltitle="<?xml version='1.0' encoding='UTF-8'?>"
                       "<dataroot>"
                       "</dataroot>";
    QDomDocument m_docInfo;
    m_docInfo.setContent(myxmltitle);
    // QString grouptext;
    QDomElement racine = m_docInfo.documentElement();
    QDomElement groupe=m_docInfo.createElement("groupe");     //انشاء عنصر جديد
    racine.appendChild(groupe);                       //الكتابة
    //اظافته في اخر القائمة
    groupe.setAttribute("title",title);
    groupe.setAttribute("author",author);
    groupe.setAttribute("betaka",betaka);

    QTextStream out(&file);                  //حفظ الملف
    m_docInfo.save(out,1);
    file.close();
    m_docInfo.clear();
    return true;
}
//! [1]
Q_EXPORT_PLUGIN2(kirtassecdrom, cdromShamila)
