#include "classepub.h"
#include "messages.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDomDocument>
#include <QTextCharFormat>
#include <QProcess>
#include <QTextStream>
#include <QSettings>
 #include <QApplication>
#include <QDebug>
classepub::classepub()
{
}
//---------------------EBOOK-----------------------------------

bool classepub::ebubUnzip(QString fileName)
{
  //  QDir::homePath()+"/.kirtasse/download"
    QDir dir;

               QString pathToExtract=QDir::homePath()+"/.kirtasse/download/epub";
   dir.mkdir(pathToExtract);
  QProcess prosses;

    if (dir.exists(pathToExtract)) //التاكد من وجود مجلد المؤقت
    {
        prosses.execute("rm -r  "+pathToExtract);
       prosses.waitForFinished();

    }

   //dir.mkdir(pathToExtract);

//     prosses.execute("unzip  \""+fileName+"\" -d  "+pathToExtract);
    if(QFile::exists("/usr/bin/7z")){
         prosses.execute("7z x  \""+fileName+"\" -o"+pathToExtract);
    }else if(QFile::exists("/usr/bin/unzip")){
       prosses.execute("unzip  \""+fileName+"\" -d  "+pathToExtract);
    }else{
        QMessageBox::information(0,"","please install 7z or unzip ");
    }



    prosses.waitForFinished();
    ebubOpenContainer(QDir::homePath()+"/.kirtasse/download/epub");
    curentPage=1;

    return true;
}

 QString classepub::setPage(int page)
 {
     int count=m_listContent.count()-1;
     if(count<1)return "";
     if(page<0)return "";
     if(page>count)return "";
           curentPage=page;
      return m_listContent.at(page);

 }
 void classepub::setCurentPage(QString page)
 {
     int count=m_listContent.count();
     if(count<1)return ;
     int indexof=m_listContent.indexOf(page);
             if(indexof>-1)
             curentPage=indexof;
   qDebug()<<indexof;
 }

void classepub::ebubOpenContainer(QString fileName)
{
    QString pathDir=fileName;
    QString path=fileName+"/META-INF/container.xml";

    QFile file(path);
    QString fullPath;
    QDomDocument m_doc;
    if (!file.open(QIODevice::ReadOnly)){
        qDebug()<<"no open";
        return ;
    }
    if (!m_doc.setContent(&file)){
        qDebug()<<"m_doc no Content";
        return ;
    }

    file.close();
    QDomElement racine = m_doc.documentElement(); //
    QDomNode rootfiles= racine.firstChild();
    QDomNode rootfile = rootfiles.firstChild();
    QDomElement element=rootfile.toElement();

    fullPath= element.attribute("full-path");
   // qDebug()<< "pathfuul= "+pathDir+"/"+fullPath;

    ebubOpenContent(pathDir+"/"+fullPath,true);
    m_doc.clear();

}

void classepub::chargeTreeIndex(QTreeWidget *view)
{
    QFile file(m_tocPath);

    QDomDocument m_doc;
    if (!file.open(QIODevice::ReadOnly)){
        qDebug()<<m_tocPath+"   no open";
        return ;
    }
    if (!m_doc.setContent(&file)){
        qDebug()<<m_tocPath+"   no Content";
        return ;
    }
view->clear();
    QDomElement racine2 = m_doc.documentElement(); //

    int count=racine2.childNodes().count();
    for(int i=0;i< count;i++){

        QDomNode metadata= racine2.childNodes().item(i);
        if (metadata.nodeName()=="navMap"){
            QDomElement metadataElement=metadata.toElement();
            int counts=metadataElement.childNodes().count();
            for(int r=0;r< counts;r++){
                QDomNode itemMeta=metadataElement.childNodes().item(r);
                if  (  itemMeta.nodeName()=="navPoint"){
                    QDomElement itemElement=itemMeta.toElement();
                    int i=itemElement.childNodes().count();
                    QString titleE;
                    QString idE;
                    QTreeWidgetItem *itemV=new QTreeWidgetItem(view);
                    for(int r=0;r< i;r++){

                        QDomNode item=itemElement.childNodes().item(r);

                        if( item.toElement().nodeName()=="navLabel"){

                            titleE=(item.toElement().text());

                        }
                        if( item.toElement().nodeName()=="content"){
                              idE=item.toElement().attribute("src").section("#",0,0);

                        }
                        if( item.toElement().nodeName()=="navPoint"){
                       QDomNode itemCild=item.toElement();
                       getChild(itemCild,itemV);
                        }


//----------------------
                    }
                    QFileInfo fi(m_tocPath);

itemV->setText(0,titleE);
itemV->setData(0,1,fi.path()+"/"+idE);

                }
            }
        }
    }

}
void classepub::getChild(QDomNode node,QTreeWidgetItem *item)
{
    int count=    node.childNodes().count();
     if(count<1)return;

      QDomElement itemElement=node.toElement();
     int i=itemElement.childNodes().count();
    QTreeWidgetItem *itemChild=new QTreeWidgetItem(item);
        QString titleE;
        QString idE;
        for(int r=0;r< i;r++){

            QDomNode item=itemElement.childNodes().item(r);

            if( item.toElement().nodeName()=="navLabel"){

                     titleE=(item.toElement().text());

            }
            if( item.toElement().nodeName()=="content"){

                      idE=item.toElement().attribute("src").section("#",0,0);
            }
            if( item.toElement().nodeName()=="navPoint"){
           QDomNode itemCild=item.toElement();
                getChild(  itemCild,itemChild);
            }
        }
          //  m_listEpub.append(titleE+"|"+idE+"|"+QString::number(lvl));
   QFileInfo fi(m_tocPath);
        itemChild->setText(0,titleE);
        itemChild->setData(0,1,fi.path()+"/"+idE);
}

//----------------create book -----------KIrtasse-----------
void classepub::ebubOpenContent(QString fileName,bool write)
{
    QDomDocument m_doc;
    QFileInfo fi(fileName);
    QString   pathHtml= fi.path();
QString  tocName;
    //---------------
   m_listContent.clear();
    //---------------
    QFile    file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        //qDebug()<<"no open  : "+pathDir+"/"+fullPath;
        return ;
    }
    if (!m_doc.setContent(&file)){
        qDebug()<<"doc no Content";
        return ;
    }
    file.close();
    QDomElement racine2 = m_doc.documentElement(); //
    int count=racine2.childNodes().count();
//---------------------------------
    QFile fileX(QDir::homePath()+"/.kirtasse/download/book.xml");
    if (!fileX.open(QFile::WriteOnly | QFile::Text)) {
        return ;
    }
     QXmlStreamWriter stream;
     int page=0;
     if(write==true){
     stream.setDevice(&fileX);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("dataroot");
     m_listId.clear();
     }



    //-------------------------------
     for(int i=0;i< count;i++){
         QDomNode metadata= racine2.childNodes().item(i);
         //-------جلب معلومات عن الكتاب والمؤبف
         if (metadata.nodeName()=="metadata"){
             QDomElement metadataElement=metadata.toElement();
             //QDomNode item= metadataElement.childNodes();
             int counts=metadataElement.childNodes().count();
             for(int r=0;r< counts;r++){
                 QDomNode item=metadataElement.childNodes().item(r);
                 if  (  item.nodeName()=="dc:title"){
                     QDomElement itemElement=item.toElement();

                     QString txt=itemElement.text();
                infoBookTitle=txt;

                 }
                 if  (  item.nodeName()=="dc:creator"){
                     QDomElement itemElement=item.toElement();

                     QString txt=itemElement.text();
                 infoBookAutor=txt;

                 }
                 if  (  item.nodeName()=="dc:description"){
                     QDomElement itemElement=item.toElement();

                     QString txt=itemElement.text();

                     infoBookBetaka=txt;

                 }
             }
         }


    //     saveBookInfo();
         //---------------جلب الصفحات-------------------------
         if (metadata.nodeName()=="manifest"){
             QDomElement metadataElement=metadata.toElement();
             //QDomNode item= metadataElement.childNodes();
             int counts=metadataElement.childNodes().count();
             for(int r=0;r< counts;r++){
                 QDomNode item=metadataElement.childNodes().item(r);
                 if  (  item.nodeName()=="item"){

                     QDomElement itemElement=item.toElement();
                       if(itemElement.attribute("media-type")=="application/x-dtbncx+xml"){
                           tocName=itemElement.attribute("href");
                       }
                       if(write==false){
                           if(itemElement.attribute("media-type")=="application/xhtml+xml"){
                          QString  href=itemElement.attribute("href");
                               m_listContent.append(pathHtml+"/"+href);
                    //           qDebug()<<pathHtml+"/"+itemElement.attribute("href");;
                           }
                       }
                       if(write==true){
                           if(itemElement.attribute("media-type")=="application/xhtml+xml"){
                               page++;
                               QString txt=itemElement.attribute("href");
                               //          qDebug()<<"item ="+txt;
                               //         qDebug()<<"path ="+pathHtml+"/"+txt;
                               m_listId.append(txt);
                               stream.writeStartElement("book");
                               stream.writeTextElement("id", txt);
                               stream.writeTextElement("part", "1");
                               stream.writeTextElement("page",QString::number( page));
                               stream.writeTextElement("nass",  ebubSetPage(pathHtml+"/"+txt));
                               stream.writeEndElement();
                           }
                       }

                 }

             }

         }

     }
   m_doc.clear();
     if(write==true){
    stream.writeEndElement(); // dataroot
     stream.writeEndDocument();


    epubOpenToc(pathHtml+"/"+tocName);
    return;
    }
    m_tocPath=pathHtml+"/"+tocName;
 pageCount=m_listContent.count()-1;

}

QString classepub:: ebubSetPage(QString fileName)
{
 //    qDebug()<<fileName;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)){
 //      qDebug()<<"no open";
       return "" ;
    }
    QByteArray data = file.readAll();
    QTextCodec *codec = Qt::codecForHtml(data);
    QString str = codec->toUnicode(data);


    if (Qt::mightBeRichText(str)) {
//        str=  str.replace("<img src=\"","EE&");
//        str=  str.replace("alt=","<p class=""alt=");
                QTextDocument doctxt;
        doctxt.setHtml(str);
        return doctxt.toPlainText();
    }
 return "" ;
}
//--------------------epub title------------------------

void classepub::epubOpenToc(QString fileName)
{
    QFile file(fileName);

    QDomDocument m_doc;
    if (!file.open(QIODevice::ReadOnly)){
        qDebug()<<fileName+"   no open";
        return ;
    }
    if (!m_doc.setContent(&file)){
        qDebug()<<fileName+"   no Content";
        return ;
    }



m_listEpub.clear();

    QDomElement racine2 = m_doc.documentElement(); //

    int count=racine2.childNodes().count();
    for(int i=0;i< count;i++){

        QDomNode metadata= racine2.childNodes().item(i);
        if (metadata.nodeName()=="navMap"){
            QDomElement metadataElement=metadata.toElement();
            int counts=metadataElement.childNodes().count();
            for(int r=0;r< counts;r++){
                QDomNode itemMeta=metadataElement.childNodes().item(r);
                if  (  itemMeta.nodeName()=="navPoint"){
                    QDomElement itemElement=itemMeta.toElement();
                    int i=itemElement.childNodes().count();

                    QString titleE;
                    QString idE;
                    for(int r=0;r< i;r++){

                        QDomNode item=itemElement.childNodes().item(r);

                        if( item.toElement().nodeName()=="navLabel"){

                            titleE=(item.toElement().text());
                         //   listlvl.append("1");
                        }
                        if( item.toElement().nodeName()=="content"){
                              idE=item.toElement().attribute("src").section("#",0,0);
                           // listid.append(id.section("#",0,0));
                        }
                        if( item.toElement().nodeName()=="navPoint"){
                       QDomNode itemCild=item.toElement();
                            epubGetChild(  itemCild,1);
                        }


//----------------------
                    }
                          m_listEpub.append(titleE+"|"+idE+"|1");


                }
            }
        }
    }
epubCreatIndex();
}

void classepub::epubGetChild( QDomNode item,int lvl)
{

int count=    item.childNodes().count();
 if(count<1)return;
 lvl++;
  QDomElement itemElement=item.toElement();
 int i=itemElement.childNodes().count();

    QString titleE;
    QString idE;
    for(int r=0;r< i;r++){

        QDomNode item=itemElement.childNodes().item(r);

        if( item.toElement().nodeName()=="navLabel"){

                 titleE=(item.toElement().text());

        }
        if( item.toElement().nodeName()=="content"){

                  idE=item.toElement().attribute("src").section("#",0,0);
        }
        if( item.toElement().nodeName()=="navPoint"){
       QDomNode itemCild=item.toElement();
            epubGetChild(  itemCild,lvl);
        }
    }
        m_listEpub.append(titleE+"|"+idE+"|"+QString::number(lvl));
}

void classepub::epubCreatIndex()
{

    QFile fileX(QDir::homePath()+"/.kirtasse/download/title.xml");
    if (!fileX.open(QFile::WriteOnly | QFile::Text)) {
        return ;
    }
    QXmlStreamWriter stream;
    stream.setDevice(&fileX);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("dataroot");
    int cnt=m_listEpub.count();
    for (int i=0;i<cnt ;i++){
    QString line=    m_listEpub.at(i);
    QString tit=line.section("|",0,0);
        QString id=line.section("|",1,1);
 QString lvl=line.section("|",2,2);
        int newid=m_listId.indexOf(id);
        if (newid==-1){newid=0;}
        QVariant dd= newid+1;
        id=dd.toString();
//qDebug()<<id;
      stream.writeStartElement("title");
      stream.writeTextElement("tit", tit);
       stream.writeTextElement("lvl", lvl);
        stream.writeTextElement("id", id);
          stream.writeEndElement();
    }
    stream.writeEndElement(); // dataroot
    stream.writeEndDocument();
QDir dir;
//QProcess prosses;
//    QString pathToExtract=QDir::homePath()+"/.kirtasse/xbook/epub";
//   if (dir.exists(pathToExtract)) //التاكد من وجود مجلد المؤقت
//   {
//       prosses.execute("rm -r  "+pathToExtract);

//      prosses.waitForFinished();

//   }
   m_listEpub.clear();
}
//-------------------------chm-----------------------------
