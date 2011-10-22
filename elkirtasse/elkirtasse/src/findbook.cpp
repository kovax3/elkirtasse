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

#include "findbook.h"
#include <QtGui>

#include <QMessageBox>
findbook::findbook()
{

    m_pathUser=QDir::homePath()+"/.kirtasse";

    resultCount=0;
    isFindRuned=false;
    findToList=false;
    findFirst=false;
    findSawabik=true;
    findMultiFind=false;
    isNassToFind=true;
}
findbook::~findbook()
{
    stopFind=true;
}
//******************bigen find *************************************************


void findbook::findOneBook(QString bookpath)  //بحث في كتاب الحالي
{
    QFile file(bookpath+"/book.xml");

    if (!file.open(QFile::ReadOnly | QFile::Text)) {

        return ;
    }


    xml.setDevice(&file);

    m_progresseValue=0;
    stopFind=false;
    isFindRuned=true;

    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" || xml.name() == "root"){

            readXml();
        }

    }

    xml.skipCurrentElement();

    isFindRuned=false;
    buttonStop->setVisible(false);
    progressBar1->setVisible(false);
    // label_progressImg->setText(QString::number(m_progresseValue));
    xml.clear();
    file.close();


}
void findbook::findInAllBook(bool inbooks)  //بحث في مجموعة كتب
{

    QFile file(m_pathUser+"/data/find.xml");
    file.open(QIODevice::ReadOnly);

    if (!m_docBKfindlist.setContent(&file)){return;}

    m_listbkfind=0;
    stopFind= false;
    isFindRuned=true;
    QDomElement racine = m_docBKfindlist.documentElement(); //renvoie la balise racine
    QDomElement mesures;
    int ir = racine.childNodes().count();
    for (int r=0;r<ir;r++){
        if(stopFind==true){
            break;
        }
        isFindRuned=true;
        buttonStop->setVisible(true);
        // progressBar1->setVisible(true);
        QDomNode noeud = racine.childNodes().item(r);
        mesures=noeud.toElement();
        findTitle=mesures.attribute("text");
        findName=mesures.attribute("name");
        findAuthor=mesures.attribute("aut");
        QVariant tfsr=mesures.attribute("isTefsir");
        isTefsir=tfsr.toBool();
        QString path=mesures.attribute("path");
        QVariant ss=r+1;
        QVariant cc=ir;
        labelProgress->setText(trUtf8("جاري البحث في :")+ findTitle+ " "+ss.toString()+"/"+cc.toString());

        m_progresseValue=0;
        QString bookpath;
        if (path=="user"){
            bookpath=pathCostum+"/"  + findName;
        }else{
            bookpath=QApplication::applicationDirPath()+"/books/"+ findName;
        }
        if( inbooks==true){
             findOneBook(bookpath);
         }else{
             findInAllFahariss(bookpath);
         }

    }
    isFindRuned=false;
    m_docBKfindlist.clear();
    label_progressImg->setVisible(false);
    labelProgress->setVisible(false);
    buttonStop->setVisible(false);
    progressBar1->setVisible(false);

    xml.clear();
    file.close();
}


void  findbook::readXml()
{
    if (findMultiFind==true){
        chargelistStrMultiFind(findText);
    }else if (findToList==true){
        findSawabik=true;
        chargelistStrToFind(findText);
    }else if(findFirst==true){
        findSawabik=true;
        //---------------
    }else{
        chargelistStrToFind(findText);
    }



    Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot" || xml.isStartElement() && xml.name() == "root");

    while ( xml.readNextStartElement()) {
        if (xml.name() == "book"){
            // counter++;
            while (xml.readNextStartElement()) {
                if (xml.name() == "nass"){
                    str=xml.readElementText();
                }else if (xml.name() == "id"){
                    id= xml.readElementText();
                }else if (xml.name() == "part"){
                    part= xml.readElementText();
                }else if (xml.name() == "page"){
                    page= xml.readElementText();
                }else{

                    xml.skipCurrentElement();
                }
            }
            progressBar1->setValue(m_progresseValue);
            m_progresseValue=m_progresseValue+1;

            // label_progressImg->setText(trUtf8("الصفحة : ")+page+trUtf8(" / الجزء : ")+part);
            QApplication::processEvents();
            if ( stopFind==true){ return;}
            //نزع التشكيل
            str.replace(trUtf8("\331\213"),"");
            str.replace(trUtf8("\331\214"),"");
            str.replace(trUtf8("\331\215"),"");
            str.replace(trUtf8("\331\216"),"");
            str.replace(trUtf8("\331\217"),"");
            str.replace(trUtf8("\331\220"),"");
            str.replace(trUtf8("\331\221"),"");
            str.replace(trUtf8("\331\222"),"");
            if (findMultiFind==true){
                readStrMultiFind();
            }else if (findFirst==true){
                readStrFirst();
            }else{
                readStr();
            }


        } else{

            xml.skipCurrentElement();
        }


    }


}
void findbook::readStrMultiFind()
{
    if (findAnd==false){

        readStr();
    }else{

        int counter=0;

        if (findSawabik==false){
            for (int pos=0;pos<m_listStrToFind.count();pos++){
                QRegExp textToFind("\\s("+m_listStrToFind.at(pos)+")\\s");
                if (str.contains(textToFind)) {
                    counter++;
                }
            }
            if(counter==m_listStrToFind.count()){
                readStr();
            }
        }else{
            for (int pos=0;pos<m_listStrToFind.count();pos++){
                QString textToFind=m_listStrToFind.at(pos);
                if (str.contains(textToFind)) {
                    counter++;
                }
            }
            if(counter==m_listStrToFind.count()){
                readStr();
            }
        }


    }
}
void  findbook::readStr()
{
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QString str1=str;

    for (int pos=0;pos<m_listStrToFind.count();pos++)
    {
        if (findSawabik==false){
            QRegExp rx("\\s("+m_listStrToFind.at(pos)+")\\s");
            if(!str1.contains(rx))
                break;
        }
        QString textToFind=m_listStrToFind.at(pos);

        if (str1.contains(textToFind))
        {

            str1.replace(QByteArray("\n"), QByteArray(" "));
            str1.replace(QByteArray("\r"), QByteArray(" "));
            int tab=  str1.count(QRegExp(textToFind));
            int txtl=textToFind.length();
            //البحث في الصفحة الواحدة
            for(int i=0;i<tab;++i)
            {
                resultCount++;
                int of=str1.indexOf(textToFind);
                QString find=str1.mid(of-45,txtl+90);
                item= new QTreeWidgetItem(treeView);
                item->setText(0,find );
                item->setText(1,part);
                item->setText(2,page);
                item->setText(3,findTitle);


                item->setText(4,findAuthor);
                item->setText(5,QString::number(resultCount));
                QVariant newId=m_progresseValue;

                item->setData(0,1,newId.toString());
                item->setData(3,1,findName);
                item->setData(2,1,isTefsir);
                //item->setData(0,1,id);
                str1.remove(0,of+txtl);
                label_progressImg->setText(trUtf8("عدد النتائج : ")+QString::number(resultCount));
            }
        }
    }
    //*******listString************************



}
void findbook::readStrFirst()
{
    QRegExp rx(findText+"*");
    rx.setPatternSyntax(QRegExp::Wildcard);
    if(rx.exactMatch(str)==true){
        QTreeWidgetItem *item=new QTreeWidgetItem;
        resultCount++;

        QString find=str.mid(0,120);
        item= new QTreeWidgetItem(treeView);
        item->setText(0,find );
        item->setText(1,part);
        item->setText(2,page);
        item->setText(3,findTitle);
        item->setText(4,findAuthor);
        item->setText(5,QString::number(resultCount));
        QVariant newId=m_progresseValue;
        item->setData(0,1,newId.toString());
        item->setData(3,1,findName);
        label_progressImg->setText(trUtf8("عدد النتائج : ")+QString::number(resultCount));
    }

}


bool findbook::chargelistStrToFind(QString search)
{
    m_listStrToFind.clear();
    if (findToList==false){
        m_listStrToFind.append(search);
        return true;
    }
    QString str;
    //1 فعل
    m_listStrToFind.append(search);
    //2 فاعل
    str =search;
    str.insert(1, trUtf8("ا"));
    m_listStrToFind.append(str);
    //3 فوعل
    str =search;
    str.insert(1, trUtf8("و"));
    m_listStrToFind.append(str);
    //4 فيعل
    str =search;
    str.insert(1, trUtf8("ي"));
    m_listStrToFind.append(str);
    //5 فعول
    str =search;
    str.insert(2, trUtf8("و"));
    m_listStrToFind.append(str);
    //6 فعيل
    str =search;
    str.insert(2, trUtf8("ي"));
    m_listStrToFind.append(str);
    //7 فعال
    str =search;
    str.insert(2, trUtf8("ا"));
    m_listStrToFind.append(str);
    //8 فتعال
    str =search;
    str.insert(1, trUtf8("ت"));
    str.insert(3, trUtf8("ا"));
    m_listStrToFind.append(str);
    // 9 فاعال
    str =search;
    str.insert(1, trUtf8("ا"));
    str.insert(3, trUtf8("ا"));
    m_listStrToFind.append(str);
    // 10 فاعيل
    str =search;
    str.insert(1, trUtf8("ا"));
    str.insert(3, trUtf8("ي"));
    m_listStrToFind.append(str);
    // 11 فاعول
    str =search;
    str.insert(1, trUtf8("ا"));
    str.insert(3, trUtf8("و"));
    m_listStrToFind.append(str);

    return true;
}
bool findbook::chargelistStrMultiFind(QString search)
{

    m_listStrToFind.clear();
    // m_listStrToFind.append(search);
    int tab=  search.count(" ");//nombre col
    for (int i=1;i<tab+2;i++){
        QString   text;
        if (i==tab+1){
            text=search.section(" ",-1);
        }else{
            text=search.section(" ",i-1,i-1);
        }
        if (text.length()>2){
            m_listStrToFind.append(text);
        }
    }


    return true;
}

bool  findbook::searchInDoc(QTextDocument *document,QString searchString,QColor color)
{

    bool firstModified=false;
    if (document->isModified()){
        firstModified=true;
    }
    bool found = false;
    if (findMultiFind==false){
        chargelistStrToFind(searchString);
    }else{
        chargelistStrMultiFind(searchString);
    }



    for (int i=0;i<m_listStrToFind.count();i++)   {
        QString findText=m_listStrToFind.at(i);

        document->undo();
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);
        cursor.beginEditBlock();
        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(color);
        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(findText, highlightCursor, QTextDocument::FindCaseSensitively);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::Right,
                                             QTextCursor::KeepAnchor);

                highlightCursor.mergeCharFormat(colorFormat);

            }
        }
        cursor.endEditBlock();
    }


    if (found == false) {
        return false;
    }
    document->setModified(firstModified);
    return true;
}


//***end find***************************************************
void findbook::searchInTreeview(QTreeWidget *view,QString searchString,int colum)
{
    for( int i = 0; i <view->topLevelItemCount(); i++ ) {
        view->topLevelItem(i)->setHidden(false );
        showAllItems(view->topLevelItem(i),view);
    }
    if (!searchString.isEmpty()){
        for( int i = 0; i <view->topLevelItemCount(); i++ ) {
            searchTreeForString(searchString,view->topLevelItem(i),true,i,view,colum) ;
        }
    }
}

bool findbook::searchTreeForString( const QString &searchString, QTreeWidgetItem* parent,bool itemtop,int  topindex,QTreeWidget *view,int colum) {
    int hiddenCount = 0;
    int hiddenparent=0;
    if (parent->childCount()==0 && !parent->text(colum).contains( searchString, Qt::CaseInsensitive )) {
        parent->setHidden(true);
    }
    for( int i = 0; i < parent->childCount(); ++i) {
        QTreeWidgetItem *child = parent->child(i);
        if( parent->isHidden() )
            hiddenCount++;
        else if(child->childCount()>0
                && !child->text(colum).contains( searchString, Qt::CaseInsensitive ) ) {//لا يحمل النص وله ابناء
            if( !searchTreeForString( searchString, child ,false,topindex,view,colum)) {
                child->setHidden(true);
                hiddenCount++;
            }
        } else if(child->childCount()>0// يحمل النص  له ابناء
                  && ( child->text(colum).contains( searchString, Qt::CaseInsensitive ) ) ){
            searchTreeForString( searchString, child ,false,topindex,view,colum);
        } else if(child->childCount()==0//لا يحمل النص وليس له ابناء
                  && ( !child->text(colum).contains( searchString, Qt::CaseInsensitive ) ) ) {
            child->setHidden(true);
            hiddenCount++;
        }
        if (itemtop==true){
            if(child->isHidden()){hiddenparent++;}
        }
    }
    QTreeWidgetItem *toplevel=view->topLevelItem(topindex);
    int topc=toplevel->childCount();
    if( hiddenparent == topc  && !toplevel->text(colum).contains( searchString, Qt::CaseInsensitive )){
        toplevel->setHidden(true);
    }
    if( hiddenCount == parent->childCount() )
        return false;
    return true;
}

bool findbook::showAllItems( QTreeWidgetItem* parent,QTreeWidget *view ) {
    for( int i = 0; i < parent->childCount(); i++ ) {
        view->setItemHidden(parent->child(i),false);
        showAllItems( parent->child( i) ,view);
    }
    return true;
}
//**********************
void findbook::loadResultFind(QTreeWidget *view,QString fn)
{

    QFile file(fn);
    QTreeWidgetItem *itemRoot;

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return;
    }
    QXmlStreamReader xml;
    xml.setDevice(&file);
    int i=0;
    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.name() == "dataroot"){
            QString title= xml.attributes().value("title").toString();
            QVariant multi=xml.attributes().value("multi").toString();
             QVariant   isnasstofind= xml.attributes().value("isnasstofind").toString();
            if (!title.isNull()){
                findText=title;
                findMultiFind=multi.toBool();
               isNassToFind=isnasstofind.toBool();
            }

        }
        if (xml.name() == "item"){ //niveau 1
            QString txt= xml.attributes().value("txt").toString();
            QString part= xml.attributes().value("part").toString();
            QString page= xml.attributes().value("page").toString();
            QString bktitle= xml.attributes().value("bktitle").toString();
            QString author= xml.attributes().value("author").toString();
            QString id= xml.attributes().value("id").toString();
            QString idBk= xml.attributes().value("idBk").toString();
            QString isTefsir= xml.attributes().value("isTefsir").toString();
            if (!txt.isNull()){
                i++;
                itemRoot= new QTreeWidgetItem(view);
                itemRoot->setText(0,txt);
                itemRoot->setText(1,part);
                itemRoot->setText(2,page);
                itemRoot->setText(3,bktitle);
                itemRoot->setText(4,author);
                itemRoot->setText(5,QString::number(i));
                itemRoot->setData(0,1,id);
                itemRoot->setData(3,1,idBk);
                itemRoot->setData(2,1,isTefsir);

            }
        }
    }
    xml.clear();
    file.close();
}
bool findbook::saveResultFind(QTreeWidget *view,QString fn )
{
    if(!fn.contains(".xml")) fn=fn+".xml";
    QFile file(fn);
    QTreeWidgetItem *item;
    QXmlStreamWriter stream;

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return false;
    }
    stream.setCodec(QTextCodec::codecForName("UTF-8"));
    stream.setDevice(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("dataroot");
    QVariant multi=findMultiFind;
    QVariant isnasstofind=isNassToFind;
    stream.writeAttribute("title",findText);
    stream.writeAttribute("multi",multi.toString());
     stream.writeAttribute("isnasstofind",isnasstofind.toString());
    for(int i=0;i<view->topLevelItemCount();++i)
    {
        item= view->topLevelItem(i);
        QString txt= item->text(0);
        QString part=  item->text(1);
        QString page= item->text(2);
        QString bktitle= item->text(3);
        QString author= item->text(4);
        QString id= item->data(0,1).toString();
        QString idBk= item->data(3,1).toString();
        QVariant isTefsir= item->data(2,1).toInt();
        stream.writeStartElement("item");
        stream.writeAttribute("txt",txt);
        stream.writeAttribute("part",part);
        stream.writeAttribute("page",page);
        stream.writeAttribute("bktitle",bktitle);
        stream.writeAttribute("author",author);
        stream.writeAttribute("id",id);
        stream.writeAttribute("idBk",idBk);
        stream.writeAttribute("isTefsir",isTefsir.toString());
        stream.writeEndElement();
    }
    stream.writeEndElement(); // dataroot
    stream.writeEndDocument();

    file.close();

    return true;
}
void findbook::findFahariss(QTreeWidget *view,QString bookpath,QRegExp rx,QRegExp rx2,int rowcount)
{
    QFile file(bookpath+"/book.xml");

    QTreeWidgetItem *item ;
    QTreeWidgetItem *osloItem;

    int conter=0;
    QTextDocument *document=new QTextDocument;
    if (!file.open(QFile::ReadOnly | QFile::Text)) {

        return ;
    }

    xml.setDevice(&file);

    view->clear();
    item=new QTreeWidgetItem(view) ;
    item->setText(0,trUtf8("بسم الله الرحمن الريم"));
    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0, rowcount, 0);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();
    qApp->processEvents();
    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" || xml.name() == "root"){

            Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot" || xml.isStartElement() && xml.name() == "root");

            while ( xml.readNextStartElement()) {
                if (xml.name() == "book"){
                    conter++;
                    progress.setValue(conter);
                    while (xml.readNextStartElement()) {
                        if (xml.name() == "nass"){
                            //  nass=xml.readElementText();
                            document->setPlainText(xml.readElementText());

                        }else{

                            xml.skipCurrentElement();
                        }
                    }
                    //*************************

                    QApplication::processEvents();
                    if (progress.wasCanceled())
                        break;
                    QTextCursor highlightCursor(document);
                    QTextCursor cursor(document);
                    cursor.beginEditBlock();
                    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                        highlightCursor.movePosition(QTextCursor::EndOfLine,QTextCursor::KeepAnchor);

                        QString text=highlightCursor.selectedText().trimmed();
                        if(text.length()>=150)
                            text= text.mid(0,150);
                        int pos = rx.indexIn(text);
                        int pos2=rx2.indexIn(text);
                        if (pos<=3&&pos!=-1){
                            item=new QTreeWidgetItem(view) ;
                            item->setText(0,text.trimmed());
                            item->setData(1,1,conter);
                            item->setText(1,QString::number(conter) );
                        }
                        if (!rx2.isEmpty())
                            if (pos2<=3&&pos2!=-1){
                            osloItem=new QTreeWidgetItem(item) ;
                            osloItem->setText(0,text.trimmed());
                            osloItem->setData(1,1,conter);
                            osloItem->setText(1,QString::number(conter) );
                        }

                        highlightCursor.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor);

                    }
                    cursor.endEditBlock();

                    //*********************************
                } else{

                    xml.skipCurrentElement();
                }


            }
            progress.cancel();
        }

    }

    xml.clear();
    file.close();
}
void findbook::findInAllFahariss(QString bookpath)
{
    QString titlepath= bookpath +"/title.xml";
    QFile file(titlepath);
    file.open(QIODevice::ReadOnly);



    QTreeWidgetItem *item;
    QString tit;
    QString id;

    QXmlStreamReader xml;
    xml.setDevice(&file);
    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" ){
            Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
            while (xml.readNextStartElement()) {
                if(stopFind==true){
                    break;
                }
                if (xml.name() == "title"){

                    while (xml.readNextStartElement()) {

                        if (xml.name() == "id"){
                            id=xml.readElementText();
                        }else if (xml.name() == "tit"){
                            tit= xml.readElementText();
                        }else{
                            xml.skipCurrentElement();
                        }

                    }
                    qApp->processEvents();
                    if (tit.contains(findText)){
                    item=new QTreeWidgetItem(treeView);

                         resultCount++;

                         item->setText(0,tit );
                         item->setText(3,findTitle);
                         item->setText(4,findAuthor);
                         item->setText(5,QString::number(resultCount));
                         item->setData(0,1,id);
                         item->setData(3,1,findName);
                         label_progressImg->setText(trUtf8("عدد النتائج : ")+QString::number(resultCount));
                     }
                }
            }
        }
    }
    file.close();

    xml.clear();
}
