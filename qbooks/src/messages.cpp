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
#include "messages.h"
#include <QtGui>
#include <QXmlStreamReader>
#include <QProgressDialog>
#include <QMessageBox>
messages::messages()
{
    //m_path=QCoreApplication::applicationDirPath ();
    m_pathUser=QDir::homePath()+"/.kirtasse";
    // m_pathCostum=QDir::homePath()+"/.kirtasse/books";
    recentLoad();
<<<<<<< HEAD
=======

>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}
messages::~messages()
{

}
//*********************chargement*******************************
void messages::treeChargeJozaa(QTreeWidget *view)
{
    QTreeWidgetItem *item=new QTreeWidgetItem(view) ;
    QTreeWidgetItem *osloItem=new QTreeWidgetItem(item) ;
    QTreeWidgetItem *osloItem2 ;
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
    QFile file(pathApp +"/data/ajzaa.xml");
    file.open(QIODevice::ReadOnly);
    view->clear();
    QXmlStreamReader xml;
    xml.setDevice(&file);
    while (!xml.atEnd()) {

        xml.readNext();
        if (xml.name() == "root"){
            QString idjoza= xml.attributes().value("id").toString();
            QString textjoza=xml.attributes().value("Name").toString();
            if(!textjoza.isNull()){
                item= new QTreeWidgetItem(view);
                item->setText(0,textjoza );
                item->setData(1,1,idjoza);
            }
        }else if (xml.name() == "Item"){
            QString idhizb= xml.attributes().value("id").toString();
            QString texthizb= xml.attributes().value("Name").toString();
            if(!texthizb.isNull()){
                osloItem= new QTreeWidgetItem(item);
                osloItem->setText(0,texthizb );
                osloItem->setData(1,1,idhizb);
            }
        }else if (xml.name() == "bk"){
            QString idhrobaa= xml.attributes().value("id").toString();
            QString textrobaa= xml.attributes().value("name").toString();
            if(!textrobaa.isNull()){
                osloItem2= new QTreeWidgetItem(osloItem);
                osloItem2->setText(0,textrobaa );
                osloItem2->setData(1,1,idhrobaa);
            }
        }

    }
    xml.clear();
    file.close();
}
void messages::treeChargeSoura(QTreeWidget *view)
{

    QTreeWidgetItem *itemsora=new QTreeWidgetItem(view);
    QTreeWidgetItem *itemaya ;
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
    QFile file(pathApp +"/data/curan.xml");
    file.open(QIODevice::ReadOnly);

    view->clear();
    QXmlStreamReader xml;
    xml.setDevice(&file);
    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.name() == "Department"){
            QString idSora= xml.attributes().value("id").toString();
            QString textSora=xml.attributes().value("Name").toString();
            if(!textSora.isNull()){
                itemsora= new QTreeWidgetItem(view);
                itemsora->setText(0,textSora );
                itemsora->setData(1,1,idSora);
            }
        }
        if (xml.name() == "Item"){
            QString idAya= xml.attributes().value("ID").toString();
            QString textAya=xml.readElementText();
            if(!textAya.isNull()){
                itemaya= new QTreeWidgetItem(itemsora);
                itemaya->setText(0,textAya );
                itemaya->setData(1,1,idAya);
            }
        }
    }
    xml.clear();
    file.close();
}

void messages::treeChargeGroupe(QTreeWidget *view,int checked,bool asCombobox)
{

    QString path=QDir::homePath()+"/.kirtasse";

    QTreeWidgetItem *itemRoot= new QTreeWidgetItem(view);
    QTreeWidgetItem *itemGroup= new QTreeWidgetItem(itemRoot);
    QTreeWidgetItem *itemBook;
    QFile file(path+"/data/group.xml");
    file.open(QIODevice::ReadOnly);

    view->clear();
    if (asCombobox==false){comboGroup->clear(); }

    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/image/booki.png")), QIcon::Normal, QIcon::Off);
    QPixmap pixmap = icon.pixmap(QSize(22, 22),QIcon::Disabled,QIcon::Off);
    QIcon icon1;
    icon1.addPixmap(pixmap);
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/image/groupb.png")), QIcon::Normal, QIcon::Off);
    QXmlStreamReader xml;
    xml.setDevice(&file);
    while (!xml.atEnd()) {
        xml.readNext();
<<<<<<< HEAD
        QString drbox;
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        if (xml.name() == "root"){ //niveau 1
            QString textRoot=xml.attributes().value("Name").toString();
            if(!textRoot.isNull()){
                itemRoot= new QTreeWidgetItem(view);
                itemRoot->setText(0,textRoot );
                itemRoot->setIcon(0,icon2);

            }
        }else if (xml.name() == "Item"){ //niveau 2
            QString idGroup= xml.attributes().value("id").toString();
            QString textGroup= xml.attributes().value("Name").toString();
            if(!textGroup.isNull()){
                itemGroup= new QTreeWidgetItem( itemRoot);
                itemGroup->setText(0,textGroup );
                itemGroup->setIcon(0,icon2);
                itemGroup->setData(2,1,idGroup);
                if (checked==1){
                    itemGroup->setCheckState(0,Qt::Unchecked);
                }
<<<<<<< HEAD

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
            }

        }else if (xml.name() == "bk"){ //niveau 3

            QString idBook= xml.attributes().value("id").toString();
            QString textBook=xml.attributes().value("name").toString();
            QString AutBook= xml.attributes().value("aut").toString();
            QString BetakaBook= xml.attributes().value("betaka").toString();
            QString curanBook= xml.attributes().value("tfsr").toString();
<<<<<<< HEAD

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
            if(!textBook.isNull()){
                itemBook= new QTreeWidgetItem( itemGroup);
                itemBook->setText(0,textBook);
                itemBook->setText(1,AutBook);
                itemBook->setText(2,BetakaBook);
                itemBook->setData(1,1,idBook);
                itemBook->setIcon(0,icon);
                itemBook->setData(2,1,curanBook);
<<<<<<< HEAD

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
                if (checked==1){
                    itemBook->setCheckState(0,Qt::Unchecked);
                }
                if (asCombobox==false){

                    if (curanBook=="1")
                    {
                        // itemBook->setData(2,1,"1");
                        comboGroup->addItem(textBook,idBook+"/"+AutBook);
                    }
                }
            }
        }
    }
    if (xml.hasError()) {

        QMessageBox::information(0,"",xml.errorString());
      }

    xml.clear();
    file.close();
}

void messages::treeUpdateGroupe(QTreeWidget *view,bool remove)
{
    QString path=QDir::homePath()+"/.kirtasse";

    QTreeWidgetItem *itemRoot= new QTreeWidgetItem(view);
    QTreeWidgetItem *itemGroup= new QTreeWidgetItem(itemRoot);
    QTreeWidgetItem *itemBook;
    QFile file(path+"/data/group.xml");
    file.open(QIODevice::ReadOnly);

    view->clear();


    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/image/booki.png")), QIcon::Normal, QIcon::Off);
    QPixmap pixmap = icon.pixmap(QSize(22, 22),QIcon::Disabled,QIcon::Off);
    QIcon icon1;
    icon1.addPixmap(pixmap);
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/image/groupb.png")), QIcon::Normal, QIcon::Off);
    QXmlStreamReader xml;
    xml.setDevice(&file);
    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.name() == "root"){ //niveau 1
            QString textRoot=xml.attributes().value("Name").toString();
            if(!textRoot.isNull()){
                itemRoot= new QTreeWidgetItem(view);
                itemRoot->setText(0,textRoot );
                itemRoot->setIcon(0,icon2);

            }
        }else if (xml.name() == "Item"){ //niveau 2
            QString idGroup= xml.attributes().value("id").toString();
            QString textGroup= xml.attributes().value("Name").toString();
            if(!textGroup.isNull()){
                itemGroup= new QTreeWidgetItem( itemRoot);
                itemGroup->setText(0,textGroup );
                itemGroup->setIcon(0,icon2);
                itemGroup->setData(2,1,idGroup);

            }

        }else if (xml.name() == "bk"){ //niveau 3

            QString idBook= xml.attributes().value("id").toString();
            QString textBook=xml.attributes().value("name").toString();
            QString AutBook= xml.attributes().value("aut").toString();
            QString BetakaBook= xml.attributes().value("betaka").toString();
            QString curanBook= xml.attributes().value("tfsr").toString();
            QString path=m_pathCostum+"/"+idBook+"/book.xml";
            bool exist=false;

            QFile file(path);
            if (file.exists()){
                exist=true;
            }
            if(!textBook.isNull()){
                if(remove==false){
                    itemBook= new QTreeWidgetItem( itemGroup);
                    itemBook->setText(0,textBook);
                    itemBook->setText(1,AutBook);
                    itemBook->setText(2,BetakaBook);
                    itemBook->setData(1,1,idBook);
                    itemBook->setData(2,1,curanBook);
                    if(exist==true){
                        itemBook->setIcon(0,icon);
                    }else{
                        itemBook->setIcon(0,icon1);
                    }
                }else{
                    if(exist==true){
                        itemBook= new QTreeWidgetItem( itemGroup);
                        itemBook->setText(0,textBook);
                        itemBook->setText(1,AutBook);
                        itemBook->setText(2,BetakaBook);
                        itemBook->setData(1,1,idBook);
                        itemBook->setData(2,1,curanBook);
                        itemBook->setIcon(0,icon);
                    }
                }

            }
        }
    }


    xml.clear();
    file.close();
}

bool messages::treeSaveGroupe(QTreeWidget *view)
{
    QString myxmlgroup="<?xml version='1.0' encoding='UTF-8'?>"
                       "<setting>"
                       "</setting>";
    m_doc.setContent(myxmlgroup);
    QTreeWidgetItem *item;
    QTreeWidgetItem *itemols;
    QTreeWidgetItem *itemols2;
    QString grouptext;
    QDomElement racine = m_doc.documentElement();
    for(int i=0;i<view->topLevelItemCount();++i)
    {
        item= view->topLevelItem(i);
        grouptext=item->text(0);
        QDomElement groupe=m_doc.createElement("root");     //انشاء عنصر جديد
        racine.appendChild(groupe);                    //اظافته في اخر القائمة
        groupe.setAttribute("Name",grouptext);      //اسم الكتاب
        groupe.setAttribute("id",i);
        for(int r=0;r<item->childCount();++r)
        {
            itemols=item->child(r);
            QString id= itemols->data(2,1).toString();
            QString title=itemols->text(0);
            QDomElement items=m_doc.createElement("Item");
            groupe.appendChild(items);
            items.setAttribute("id",id);
            items.setAttribute("Name",title);
            for(int r=0;r<itemols->childCount();++r)
            {
                itemols2=itemols->child(r);
                QString id= itemols2->data(1,1).toString();
                QString betaka=itemols2->text(2);
                QString aut  =itemols2->text(1);
                QString name =itemols2->text(0);
                QDomElement itemsbk=m_doc.createElement("bk");
                items.appendChild(itemsbk);
                itemsbk.setAttribute("id",id);
                itemsbk.setAttribute("betaka",betaka);
                itemsbk.setAttribute("aut",aut);
                itemsbk.setAttribute("name",name);
                if (itemols2->data(2,1)=="1")
                {
                    itemsbk.setAttribute("tfsr","1");
                }
            }
        }
    }
    QFile file(m_pathUser +"/data/group.xml");
    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة
    QTextStream out(&file);                       //الكتابة
    m_doc.save(out,1);                      //حفظ الملف
    file.close();
    m_doc.clear();
    return true;
}
void messages::treeChargeFahrass(QTreeWidget *view,QString Bname)
{

    QString titlepath= Bname +"/title.xml";
   // QString titlepath= Bname;
    QFile file(titlepath);
    file.open(QIODevice::ReadOnly);
    view->clear();
    int d=1;
<<<<<<< HEAD
 //   enum  { NumIndex = 10};
    QTreeWidgetItem *item;

=======
    QTreeWidgetItem *item[d];
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QString tit;
    QString id;
    QString lvl;

<<<<<<< HEAD
    item= new QTreeWidgetItem(view);
    item->setText(0,trUtf8("بسم الله الرحمن الرحيم") );
    item->setData(1,1,1);

=======
    item[1]= new QTreeWidgetItem(view);
    item[1]->setText(0,trUtf8("بسم الله الرحمن الرحيم") );
    item[1]->setData(1,1,1);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QXmlStreamReader xml;
    xml.setDevice(&file);
    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" ){
            Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
            while (xml.readNextStartElement()) {
                if (xml.name() == "title"){

                    //   Q_ASSERT(xml.isStartElement() && xml.name() == "book");
                    while (xml.readNextStartElement()) {
                        if (xml.name() == "id"){
                            id=xml.readElementText();


                        }else if (xml.name() == "tit"){

                            tit= xml.readElementText();
                        }else if (xml.name() == "lvl"){

                            lvl= xml.readElementText().trimmed();
                        }else{
                            xml.skipCurrentElement();
                        }


                    }
                    bool ok;
                    d=lvl.toInt(&ok,0);

<<<<<<< HEAD
                 if (ok==true){
                        if (d<1){d=1;}
                        if (d==1){

                            item= new QTreeWidgetItem(view);
                            item->setText(0,tit );
                            item->setText(1,id );
                            item->setData(1,1,id);



                        }else{
                            int index=view->topLevelItemCount()-1;
                            QTreeWidgetItem *itemParent=(view->topLevelItem(index));

                            for(int i=0;i<d-2;i++){
                                if(itemParent)
                                  itemParent= getItem(itemParent) ;
                            }

                           item= new QTreeWidgetItem(itemParent);
                           item->setText(0,tit );
                           item->setText(1,id );
                           item->setData(1,1,id);

                        }
                    }else{
                        item= new QTreeWidgetItem(view);
                        item->setText(0,tit );
                        item->setText(1,id );
                        item->setData(1,1,id);
=======
                    if (ok==true){
                        if (d<1){d=1;}
                        if (d==1){
                            item[1]= new QTreeWidgetItem(view);
                            item[1]->setText(0,tit );
                            item[1]->setText(1,id );
                            item[1]->setData(1,1,id);
                        }else{
                            if (item[d-1]){
                                item[d]= new QTreeWidgetItem( item[d-1]);
                                item[d]->setText(0,tit );
                                item[d]->setText(1,id );
                                item[d]->setData(1,1,id);
                            }

                        }
                    }else{
                        item[1]= new QTreeWidgetItem(view);
                        item[1]->setText(0,tit );
                        item[1]->setText(1,id );
                        item[1]->setData(1,1,id);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
                    }
                }
            }
        }


    }
    file.close();
    //listId.clear();
    xml.clear();
}
<<<<<<< HEAD

QTreeWidgetItem* messages::getItem(QTreeWidgetItem *item)
{



    int index=item->childCount()-1;
 //   QTreeWidgetItem *itemParent=(item->child(index));
    return item->child(index);
}


=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
//حذف الكتاب المحدد
bool messages::treeMenuRemoveBook(QString BKname,bool removall)
{
    QFile file(m_pathUser +"/data/group.xml");
    file.open(QIODevice::ReadOnly);
    if (!m_doc.setContent(&file)){return false;}
    file.close();
    QDomElement racine = m_doc.documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.firstChild();
    while(!noeud.isNull())
    {
        QDomNodeList tab;
        QDomNodeList tab2;
        QDomElement Root;
        Root=noeud.toElement();                   // تحديد اول عنصر من ابناء العنصر الاصلي
        if (Root.tagName()== "root")
        {
            tab = Root.childNodes();
            for (int i=0;i< (int)tab.length();++i)
            {
                QDomNode noeud2=tab.item(i);
                QDomElement Group=noeud2.toElement();
                tab2 = Group.childNodes();
                for(int r=0;r<(int)tab2.length();r++)
                {
                    QDomNode noeud3=tab2.item(r);
                    QDomElement Book=noeud3.toElement();
                    QString idBook =Book.attribute("id");
                    if (BKname==idBook){
                        Group.removeChild(Book);
                        file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
                        QTextStream out(&file);                       //الكتابة
                        const int IndentSize = 1;
                        m_doc.save(out,IndentSize);                      //حفظ الملف
                        file.close();
                        m_doc.clear();                                   //مسح المحتويات من الذاكرة
                        if (removall==true){                     //الحذف من الجهاز
                            QString    pathbook=m_pathCostum;
                            QDir dir(m_pathCostum+"/" +BKname);
                            if (!dir.exists()){
                                return false;
                            }
                            dir.setFilter(QDir::Files | QDir::Hidden );
                            QFileInfoList list = dir.entryInfoList();
                            for (int i = 0; i < list.size(); ++i) {
                                QFileInfo fileInfo = list.at(i);
                                if(dir.remove(fileInfo.fileName())==false){
                                    return false;
                                }
                            }
                            QDir dirm(pathbook );
                            if(dirm.rmdir(BKname)==false){
                                return false;
                            }
                        }
                        return true;
                    }
                }
            }
        }
        noeud = noeud.nextSibling();
    }
    m_doc.clear();
    file.close();
    return true;
}
//***end chargement***
//****************************bigen recent****************************
void messages::recentLoad()
{
    QString myxmlgroup="<?xml version='1.0' encoding='UTF-8'?>"
                       "<setting>"
                       "</setting>";
    QFile file(m_pathUser +"/data/recent.xml");
    file.open(QIODevice::ReadOnly);
    if (!m_docR.setContent(&file))
    {
        m_docR.setContent(myxmlgroup);
    }
    file.close();
}
void messages::recentCharge()
{


    QDomElement racine = m_docR.documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.lastChild();
    QDomElement Root;
    int i=0;
    while(!noeud.isNull())
    {
        i++;
        Root=noeud.toElement();
        QString texttitle=Root.attribute("title");
        QString textid=Root.attribute("id");
        QString textname=Root.attribute("name");
        QString textaut=Root.attribute("aut");
        QString isTefsir=Root.attribute("isTefsir");

        recentFileActs[i]->setText(texttitle);
        recentFileActs[i]->setData(textid + "/" + textname + "/" + textaut+"/" + isTefsir);
        recentFileActs[i]->setVisible(true);

        noeud = noeud.previousSibling();

    }
}
void messages::recentChange(QString Bname,QString Btitle,QString Baut,QString Bid,int nbr,bool isTefsir)
{
    QDomElement racine = m_docR.documentElement(); //renvoie la balise racine
    QDomNodeList tab;
    QDomElement Root;
    QDomNode noeud = racine.firstChild();
    while(!noeud.isNull())
    {
        Root=noeud.toElement();
        QString textname=Root.attribute("name");
        if (textname==Bname){
            racine.removeChild(Root);
        }
        noeud = noeud.nextSibling();
    }
    tab=racine.childNodes();
    while ((int)tab.length()>=nbr)
    {
        QDomNode noeud_f = racine.firstChild();
        QDomElement Root_f;
        Root_f=noeud_f.toElement();
        racine.removeChild(Root_f);
    }
    QDomElement myel=m_docR.createElement("book");     //انشاء عنصر جديد
    racine.appendChild(myel);                    //اظافته في اخر القائمة
    myel.setAttribute("id",Bid);        //اسم مجلد الكتاب
    myel.setAttribute("name",Bname);      //اسم الكتاب
    myel.setAttribute("title",Btitle);      //اسم المؤلف
    myel.setAttribute("aut",Baut);

    myel.setAttribute("isTefsir",isTefsir);
}
void messages::recentSave()
{
    QFile file(m_pathUser +"/data/recent.xml");
    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
    QTextStream out(&file);                       //الكتابة
    const int IndentSize = 1;
    m_docR.save(out,IndentSize);                      //حفظ الملف
    file.close();
    m_docR.clear();
}
//***end recent***
bool messages::fahrasSave(QTreeWidget *view,QString bkname)
{
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
    QFile file;
    QString path;
    if(file.exists(m_pathCostum+"/" +bkname+"/title.xml")){
        path=m_pathCostum+"/" +bkname+"/title.xml";
    }else if (file.exists(pathApp+"/books/" +bkname+"/title.xml")){
        path=pathApp+"/books/" +bkname+"/title.xml";
    }else{
        return false;
    }
    file.setFileName(path);
    if(!file.open(QIODevice::WriteOnly) )  {            //فتح الملف للكتابة عليها
        return false;
    }
    QString myxmltitle="<?xml version='1.0' encoding='UTF-8'?>"
                       "<dataroot>"
                       "</dataroot>";
    m_doc.setContent(myxmltitle);
    QTreeWidgetItem *itemr;
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            view->findItems(
                    "",Qt::MatchContains | Qt::MatchRecursive,0);//تنشاء قائمة بكل العناصر
    if (found.count()>0) {
        int lvl=1;
        foreach (item, found){
            itemr= item;
            if (!item->parent()){//اذا كان العنصر جذرا
                writeInDoc(item->text(0),item->data(1,1).toString(),"1");
                lvl=1;
            }else{//اذا كان له اباء
                while(itemr->parent()){//معرفة عدد الاباء
                    itemr=itemr->parent();
                    lvl=lvl+1;
                }
                QVariant lvlstr=lvl;
                writeInDoc(item->text(0),item->data(1,1).toString(),lvlstr.toString());
                lvl=1;
            }

        }
    }


    QTextStream out(&file);                       //الكتابة
    const int IndentSize = 1;
    m_doc.save(out,IndentSize);                      //حفظ الملف
    file.close();
    m_doc.clear();

    return true;
}


bool messages::writeInDoc(QString tit,QString data,QString lvl)
{
    if(data.isEmpty()||data.isNull())data="1";
    QDomElement racine = m_doc.documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.firstChild();
    QDomElement myel=m_doc.createElement("title");     //انشاء عنصر جديد
    racine.appendChild(myel);
    QDomElement myid=m_doc.createElement("id");     //انشاء عنصر جديد
    myel.appendChild(myid);
    QDomText t1 = m_doc.createTextNode(data);
    myid.appendChild(t1);
    QDomElement mynass=m_doc.createElement("tit");     //انشاء عنصر جديد
    myel.appendChild(mynass);
    QDomText t2 = m_doc.createTextNode(tit);
    mynass.appendChild(t2);
    QDomElement mylvl=m_doc.createElement("lvl");     //انشاء عنصر جديد
    myel.appendChild(mylvl);
    QDomText t3 = m_doc.createTextNode(lvl);
    mylvl.appendChild(t3);
    return true;
}
//******************bigen find *************************************************




//***end find***************************************************
void messages::comboCharge(QComboBox *combo)
{
    QDomDocument docCombo;
    QFile file(m_pathUser +"/data/group.xml");

    file.open(QIODevice::ReadOnly);
    if (!docCombo.setContent(&file)){return;}
    QDomElement racine = docCombo.documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.firstChild();
    while(!noeud.isNull())
    {
        QDomNodeList tab;
        QDomNodeList tab2;
        QDomElement groupPer;
        groupPer=noeud.toElement();
        if (groupPer.tagName()== "root")
        {
            tab = groupPer.childNodes();
            for(int i=0;i<(int)tab.length();++i)
            {
                QDomNode noeud2=tab.item(i);
                QDomElement mygroup=noeud2.toElement();
                QString mygroupname= mygroup.attribute("Name");
                QString mygroupid= mygroup.attribute("id");
                combo->addItem(mygroupname,mygroupid);
            }
        }
        noeud = noeud.nextSibling();
    }
    docCombo.clear();
    file.close();
}
bool messages::addNewBook(QString bkpath,QString bktitle,QString bkauth,QString bkbetaka,QString groupid ,bool cheked)
{
    // QFile filepath(m_pathCostum+"/" +bkpath);
    QFile file(m_pathUser +"/data/group.xml");
    if (bkpath.isEmpty()){return false;}
    //  if (!filepath.exists()){return false;}
    if (bktitle.isEmpty()){bktitle=trUtf8("بدون اسم");}
    if (bkauth.isEmpty()){ bkauth=trUtf8("غير معروف");}
    file.open(QIODevice::ReadOnly);
    if (!m_doc.setContent(&file)){return false;}
    file.close();
    QDomElement racine = m_doc.documentElement();                  //عنصر الشجرة الاصلي
    QDomNode noeud = racine.firstChild();                       // تحديد اول عنصر من ابناء العنصر الاصلي
    while(!noeud.isNull())                                       //كلما كان العنصر غير فارغا
    {
        QDomNodeList tab;
        QDomNodeList tab2;
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
                    myel.setAttribute("id",bkpath);        //اسم مجلد الكتاب
                    myel.setAttribute("name",bktitle);      //اسم الكتاب
                    myel.setAttribute("aut",bkauth);      //اسم المؤلف
                    myel.setAttribute("betaka", bkbetaka);      //بطاقة عن الكتاب
                    if (cheked==true) {
                        myel.setAttribute("tfsr", "1");
                    }
                    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة عليها
                    QTextStream out(&file);                       //الكتابة
                    const int IndentSize = 1;
                    m_doc.save(out,IndentSize);                      //حفظ الملف
                    file.close();
                    m_doc.clear();                                   //مسح المحتويات من الذاكرة
                    return true;                                         //انهاء العملية
                }
            }
        }
        noeud = noeud.nextSibling();
    }
    m_doc.clear();
    file.close();
    return true;
}

//***********************favorite***********************************************
void messages::favorite_charge(QTreeWidget *view,QIcon icong,QIcon iconf)
{
    //    QString path=QCoreApplication::applicationDirPath ();
    QString path=QDir::homePath()+"/.kirtasse";

    QDomDocument doc;
    QString myxmlfavorite="<?xml version='1.0' encoding='UTF-8'?>"
                          "<dataroot>"
                          " <groupe name='عام' />"
                          "</dataroot>";
    QFile file(path +"/data/favorite.xml");
    file.open(QIODevice::ReadOnly);
    if (file.exists() ){
        if (!doc.setContent(&file))
            doc.setContent(myxmlfavorite);
    }
    file.close();
    QTreeWidgetItem *item;
    QTreeWidgetItem *osloItem ;
    view->clear();
    QDomElement racine = doc.documentElement(); //
    QDomNode noeud = racine.firstChild();
    while(!noeud.isNull())
    {
        QDomNodeList tab;
        QDomElement mesures;
        mesures=noeud.toElement();
        QString text1=mesures.attribute("Department");
        // QMessageBox::information(this, "conection", id1 + text1);
        item= new QTreeWidgetItem(view);
        item->setText(0,text1 );
        item->setIcon(0,icong);
        tab = mesures.childNodes();
        for(int i=0;i<(int)tab.length();i++)
        {
            QDomNode noeud2=tab.item(i);
            QDomElement mesures2=noeud2.toElement();
            QString id= mesures2.attribute("id");
            QString title= mesures2.attribute("title");
            QString bkname= mesures2.attribute("bkname");
            QString bktitle= mesures2.attribute("bktitle");
            QString autname= mesures2.attribute("autname");
            osloItem= new QTreeWidgetItem(item);
            osloItem->setText(0,title );
            osloItem->setData(2,1,id);
            osloItem->setText(1,bktitle );
            osloItem->setData(1,1,bkname);
            osloItem->setText(2,autname );
            osloItem->setIcon(0,iconf);
        }
        noeud = noeud.nextSibling();
    }
    doc.clear();
}

void messages::favorite_save(QTreeWidget *view)
{
    QString myxmlfavorite="<?xml version='1.0' encoding='UTF-8'?>"
                          "<dataroot>"
                          "</dataroot>";
    m_doc.setContent(myxmlfavorite);
    QTreeWidgetItem *item;
    QTreeWidgetItem *itemols;
    QString grouptext;
    QDomElement racine = m_doc.documentElement();
    for(int i=0;i<view->topLevelItemCount();++i)
    {
        item= view->topLevelItem(i);
        grouptext=item->text(0);
        QDomElement groupe=m_doc.createElement("groupe");     //انشاء عنصر جديد
        racine.appendChild(groupe);                    //اظافته في اخر القائمة
        groupe.setAttribute("Department",grouptext);      //اسم الكتاب
        for(int r=0;r<item->childCount();++r)
        {
            itemols=item->child(r);
            QString id= itemols->data(2,1).toString();
            QString title=itemols->text(0);
            QString bkname=  itemols->data(1,1).toString();
            QString bktitle =itemols->text(1);
            QString autname=itemols->text(2);
            QDomElement items=m_doc.createElement("item");
            groupe.appendChild(items);
            items.setAttribute("id",id);
            items.setAttribute("title",title);
            items.setAttribute("bkname",bkname);
            items.setAttribute("bktitle",bktitle);
            items.setAttribute("autname",autname);
        }
    }
    QFile file(m_pathUser +"/data/favorite.xml");
    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة
    QTextStream out(&file);                       //الكتابة
    m_doc.save(out,1);                      //حفظ الملف
    file.close();
    m_doc.clear();
}
//************************************
bool messages::treeviewItemRemove(QTreeWidget *view)
{
    QTreeWidgetItem *item= view->currentItem();
    if (!item){
        return false;
    }
    int t;
    if (item->parent()){
        t= item->parent()->indexOfChild(item);
        item->parent()->takeChild(t);
    } else{
        t=view->indexOfTopLevelItem(item);
        view->takeTopLevelItem(t);
    }
    return true;
}
bool messages::treeviewItemUp(QTreeWidget *view)
{
    int t;
    QTreeWidgetItem *new_item;           //العنصر الجديد
    QTreeWidgetItem *curent_item=view->currentItem();      //العنصر المحدد
    QTreeWidgetItem *old_item = view->itemAbove(curent_item);   //العنصر السابق
    if (!curent_item || !old_item){ //اذا لم يوجد عنصرا محددا او السابق موجودا يخرج
        return false;;
    }
    new_item=curent_item->clone(); //نسخ العنصر المحدد مع ابنائه ان كان يحمل ابناء
    if (!curent_item->parent()){  //اذا كان في قمة الشجرة اي ليس له ابناء
        t=view->indexOfTopLevelItem(curent_item);//معرفة ترقيم العنصر
        view->takeTopLevelItem(t);//حذف العنصر المحدد
        view->insertTopLevelItem(t-1,new_item); //اظافة العنصر المنسوخ في الذاكرة بعد العنصر التالي
    }    else{     //اذا كان العنصر ابنا
        QTreeWidgetItem *parent=curent_item->parent();
        t= parent->indexOfChild(curent_item);
        if(t==0){    //اذا كان العنصر اول عنصر ابن
            return false;;
        }
        parent->takeChild(t);
        parent->insertChild(t-1,new_item);
    }
    view->setCurrentItem(new_item); //
    return true;
}
bool messages::treeviewItemDown(QTreeWidget *view)
{
    int t;
    int r;
    QTreeWidgetItem *new_item;
    QTreeWidgetItem *curent_item=view->currentItem();//العنصر المحدد
    QTreeWidgetItem *old_item =view->itemBelow(curent_item);//العنصر التالي
    if (!curent_item || !old_item){  return false; } //اذا لم يوجد عنصرا محددا او التالي يخرج
    new_item=curent_item->clone(); //نسخ العنصر المحدد مع ابنائه ان كان يحمل ابناء
    if (!curent_item->parent()){  //اذا كان في قمة الشجرة اي ليس له ابناء
        t=view->indexOfTopLevelItem(curent_item);//معرفة ترقيم العنصر
        r=view->topLevelItemCount()-1;
        if(t==r){ return false; }
        view->takeTopLevelItem(t);//حذف العنصر المحدد
        view->insertTopLevelItem(t+1,new_item); //اظافة العنصر المنسوخ في الذاكرة بعد العنصر التالي
    } else{//اذا كان العنصر ابنا
        QTreeWidgetItem *parent=curent_item->parent();

        t= parent->indexOfChild(curent_item);
        r=parent->childCount()-1;
        if(t==r){return false;  }//اذا كان العنصر اخر عنصر ابن
        parent->takeChild(t);

        parent->insertChild(t+1,new_item);

    }
    view->setCurrentItem(new_item); //تحديد العنصر الجديد
    return true;
}
//**************************************************************************


int messages::genirateId(QTreeWidget *view)
{
    int newid=0;
    QList<QString> list;
    QTreeWidgetItem *itemtop;
    QTreeWidgetItem *itemgroup;
    for(int i=0;i<view->topLevelItemCount();++i){
        itemtop=view->topLevelItem(i);
        for(int r=0;r<itemtop->childCount();++r)
        {
            itemgroup=itemtop->child(r);
            QVariant data=itemgroup->data(2,1);
            list.append(data.toString());
        }
    }
    bool exist=false;

    while(exist==false)
    {
        newid=newid+1;
        QVariant dd=newid;
        if  ( !list.contains(dd.toString())){
            exist=true;
        }
    }
    list.clear();
    return newid;
}
QString messages::geniratNewBookName(QString groupParent)
{

    QList<QString> list;
    QFile file(m_pathUser +"/data/group.xml");
    file.open(QIODevice::ReadOnly);
    if (!m_doc.setContent(&file)){return "bk"+groupParent;}
    file.close();
    QDomElement racine = m_doc.documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.firstChild();
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
                    QDomNode noeud3=tab2.item(r);
                    QDomElement Book=noeud3.toElement();
                    QString idBook =Book.attribute("id");
                    list.append(idBook);
                }
            }
        }
        noeud = noeud.nextSibling();
    }
    m_doc.clear();
    file.close();
    int newid=0;
    bool exist=false;
    QString newBookName;
    while(exist==false)
    {
        newid=newid+1;

        QVariant dd=newid;
        newBookName="bk"+groupParent+"_"+dd.toString();
        if  ( !list.contains(newBookName)){
            exist=true;
        }
    }
    list.clear();
    return newBookName;
}
bool messages::saveBookInfo(QString bookname,QString title,QString author,QString betaka)
{
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
    QFile file;
    QString path;
    if(file.exists(m_pathCostum+"/" +bookname+"/bookinfo.info")){
        path=m_pathCostum+"/" +bookname+"/bookinfo.info";
    }else if (file.exists(pathApp+"/books/" +bookname+"/bookinfo.info")){
        path=pathApp+"/books/" +bookname+"/bookinfo.info";
    }else{
        path=m_pathCostum+"/" +bookname+"/bookinfo.info";
    }
    file.setFileName(path);

    if(! file.open(QIODevice::WriteOnly)) {
        return false;
    }
    //فتح الملف للكتابة

    QString myxmltitle="<?xml version='1.0' encoding='UTF-8'?>"
                       "<dataroot>"
                       "</dataroot>";
    m_doc.setContent(myxmltitle);
    // QString grouptext;
    QDomElement racine = m_doc.documentElement();
    QDomElement groupe=m_doc.createElement("groupe");     //انشاء عنصر جديد
    racine.appendChild(groupe);                       //الكتابة
    //اظافته في اخر القائمة
    groupe.setAttribute("title",title);
    groupe.setAttribute("author",author);
    groupe.setAttribute("betaka",betaka);

    QTextStream out(&file);                  //حفظ الملف
    m_doc.save(out,1);
    file.close();
    m_doc.clear();
    return true;
}
bool messages::loadBookInfo(QString bookname)
{

    QFile file(bookname+"/bookinfo.info");

    if (!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (!m_doc.setContent(&file)){
        return false;
    }
    file.close();
    QDomElement racine = m_doc.documentElement(); //
    QDomNode noeud = racine.firstChild();
    QDomElement myper=noeud.toElement();

    //   mesures=noeud.toElement();
    infoBookTitle= myper.attribute("title");
    infoBookAutor= myper.attribute("author");
    infoBookBetaka= myper.attribute("betaka");

    m_doc.clear();
    return true;

}

//**********************


bool messages::loadTarGz(QString path)
{
    //verifier
    QProcess prosses;
    QString pathToExtract=QDir::homePath()+"/.kirtasse/download";
    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0, 0, 0);
    progress.setWindowModality(Qt::WindowModal);
    progress.setEnabled(false);
    progress.show();
    qApp->processEvents();
#ifdef   Q_WS_WIN


    //removeTempDirs(pathToExtract);


    prosses.setWorkingDirectory(QApplication::applicationDirPath());
    QString extar="7z e \""+path + "\" -o\""+pathToExtract+"\" *.tar -y ";
    prosses.start(extar);
    prosses.waitForFinished();
    //info

    prosses.start("7z l \""+pathToExtract+"\"");
    while(prosses.state()==QProcess::Running){
        qApp->processEvents();
        progress.setValue(progress.value()+1);
    }

    //extract
    QByteArray result = prosses.readAll();
    //  QMessageBox::critical(this,trUtf8("خطأ"),result);
    if (!result.contains("book.xml")&&!result.contains("bookinfo.info")){
        QMessageBox::critical(0,trUtf8("خطأ"),trUtf8("الارشيف لا يحتوي على كتاب\n")+path);
        return false;
    }
    prosses.start("7z e \""+pathToExtract+"\"/*.tar -o\""+pathToExtract+"\" -y");
    while(prosses.state()==QProcess::Running){
        qApp->processEvents();
        progress.setValue(progress.value()+1);
    }
    //  archiveDir="";
    return true;


#else
    prosses.start("tar -tf  \""+path+"\"");
    prosses.waitForFinished();
    QByteArray result = prosses.readAll();
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString string = codec->toUnicode(result);
    if ( !string.contains("book.xml") && !string.contains("bookinfo.info")){
        QMessageBox::critical(0,trUtf8("خطأ"),trUtf8("الارشيف لا يحتوي على كتاب\n")+path);
        return false;
    }
    QString archiveDir=string.section( "/",0,0);
    // QMessageBox::critical(0,trUtf8("خطأ"),archiveDir);




    prosses.execute("mkdir -p "+pathToExtract);
    prosses.waitForFinished();
    prosses.start(QString("tar -xvf  %1 -C  %2").arg("\""+path+"\"").arg("\""+pathToExtract+"\""));
    while(prosses.state()==QProcess::Running){
        qApp->processEvents();
        progress.setValue(progress.value()+1);
    }
    prosses.waitForFinished();
    prosses.start(QString("mv   %1   %2").arg("\""+pathToExtract+"/"+archiveDir+"/book.xml\"").arg("\""+pathToExtract+"\""));
    prosses.waitForFinished();
    prosses.start(QString("mv   %1   %2").arg("\""+pathToExtract+"/"+archiveDir+"/bookinfo.info\"").arg("\""+pathToExtract+"\""));
    prosses.waitForFinished();
    prosses.start(QString("mv   %1   %2").arg("\""+pathToExtract+"/"+archiveDir+"/title.xml\"").arg("\""+pathToExtract+"\""));
    prosses.waitForFinished();
    return true;
#endif

}



void messages::removeTempDirs(QString dirName)
{
    removeTempFiles(dirName);
    QString subdir;

    QDir dir(dirName);
    foreach ( subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot |
                                    QDir::Hidden )){

        if ( removeTempFiles(dirName+subdir)==true){
            // QMessageBox::information(0,trUtf8("خطأ"),dirName+"/"+subdir);
            removeTempDirs(dirName+"/"+subdir);
            dir.rmdir(subdir);

        }

    }
}

bool  messages::removeTempFiles(QString tempDir)
{

        QDir dirS(tempDir);
        QString subfile;
        QFile filetemp;
        foreach ( subfile, dirS.entryList(QDir::AllEntries)){

            filetemp.remove(tempDir+"/"+subfile);
        }

return true;


}
