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
#include "databook.h"

databook::databook()
{
    boocNumIndex=0;
    currentPosition[boocNumIndex]=0;
    //prevPosition[boocNumIndex]=0;
    newPosition[boocNumIndex]=0;
    removeTechkile=false;
}
databook::~databook()
{

}
bool  databook::openBook(QString bookName,int position,QString bkpath)
{


    QFile file(bkpath);
    if( !file.open(QIODevice::ReadOnly))                            //فتح الملف
    {

        return false;
    }

    claerBook(boocNumIndex);                                                    //تفريغ الذاكرة
    if (!m_docBooK[boocNumIndex].setContent(&file))                                      //اذا كانت البيانات صحيحة
    {

        return false;
    }
    m_currentBookName[boocNumIndex]=bookName;
    m_currentBookPath[boocNumIndex]=bkpath;
    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    QVariant i = racine.childNodes().count();
    rowsCount[boocNumIndex]=i.toInt()-1;
    file.close();

    moveToPosition(position);
    isTefsir=getIfTefsir();
    return true;
}
void databook::claerBook(int num)
{
    m_docBooK[num].clear();
    bookNass[num].clear();
    listId.clear();

}
bool databook::getIfTefsir()
{

    for(int i=0;i<100;i++){
        QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
        QDomNode noeud = racine.childNodes().item(i);

        QVariant aya=   noeud.firstChildElement("aya").firstChild().toText().data();
        QVariant sora=  noeud.firstChildElement("sora").firstChild().toText().data();
        if(aya.toString().isEmpty()){
            return false;
        }

        if(aya.toInt()>0 && sora.toInt()>0){
            return true;
        }
    }
    return false;

}

void databook::moveToPosition(int position)
{
    int pos=position;
    //prevPosition[boocNumIndex]=currentPosition[boocNumIndex];

    //  if (position==currentPosition[boocNumIndex]){return;}
    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.childNodes().item(pos);


    if (removeTechkile==false){
        bookNass[boocNumIndex]=   noeud.firstChildElement("nass").firstChild().toText().data();
    }else{
        bookNass[boocNumIndex]=noTechkile(noeud.firstChildElement("nass").firstChild().toText().data()) ;
    }
    bookCurentId[boocNumIndex]=  noeud.firstChildElement("id").firstChild().toText().data();
    bookPage[boocNumIndex]=  noeud.firstChildElement("page").firstChild().toText().data();
    bookPart[boocNumIndex]=  noeud.firstChildElement("part").firstChild().toText().data();
    //convert_text(text);
    currentPosition[boocNumIndex]=pos;
    //m_label_page->setText(trUtf8("الصفحة :")+page +"  "+trUtf8("الجزء :")+jozaa);
    // m_label_progress_info->setText(trUtf8(" كتاب : ")+m_Book_title +trUtf8(".  المؤلف : ")+m_Book_Autors+". " +m_label_page->text());
}
QString databook::noTechkile(QString text) const
{
    QString str=text;
    str.replace(trUtf8("\331\213"),QString::null);
    str.replace(trUtf8("\331\214"),QString::null);
    str.replace(trUtf8("\331\215"),QString::null);
    str.replace(trUtf8("\331\216"),QString::null);
    str.replace(trUtf8("\331\217"),QString::null);
    str.replace(trUtf8("\331\220"),QString::null);
    str.replace(trUtf8("\331\221"),QString::null);
    str.replace(trUtf8("\331\222"),QString::null);
    return str;
}

bool databook::findAya(QString soura,QString aya)
{
    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    QString textsora;
    QString textaya;
    //    QString id;
    int r;
    for(r=rowsCount[boocNumIndex];r>0;r--){
        QDomNode noeud = racine.childNodes().item(r);
        textsora=   noeud.firstChildElement("sora").firstChild().toText().data();

        if(textsora==soura){
            textaya=  noeud.firstChildElement("aya").firstChild().toText().data();
            if( textaya.toInt()<=aya.toInt()){
                //    id=  noeud.firstChildElement("id").firstChild().toText().data();
                moveToPosition(r);
                return true;
            }
        }
    }
    return false;
}
void databook::updatPage(QString oldText,QString newText,bool fullText)
{
    if (fullText==true){
        bookNass[boocNumIndex]=newText;
    }else{
        bookNass[boocNumIndex].replace(oldText,newText.trimmed());
    }

    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    QDomNode noeud = racine.childNodes().item(currentPosition[boocNumIndex]);
    noeud.firstChildElement("nass").firstChild().setNodeValue(bookNass[boocNumIndex]);
}
bool databook::saveBook()
{
    // QString path=QCoreApplication::applicationDirPath ();
    //مسار الكتاب
    QFile file( m_currentBookPath[boocNumIndex]);
    if ( !file.open(QIODevice::WriteOnly)){
        return false;
    }//فتح الملف للكتابة
    QTextStream out(&file);                       //الكتابة
    m_docBooK[boocNumIndex].save(out,1);                      //حفظ الملف
    file.close();
  //  m_docBooK[boocNumIndex].clear(); QString str,id;
    return true;
}


void databook::treeOrganizFahrass(QTreeWidget *view,QString Bname)
{

    if( chargeList()==true){

        QDomDocument m_doc;
        QString titlepath= Bname +"/title.xml";
        QFile file(titlepath);
        file.open(QIODevice::ReadOnly);
        if (!m_doc.setContent(&file)){return;}
        view->clear();
        int d=0;
<<<<<<< HEAD
        QTreeWidgetItem *item;
=======
        QTreeWidgetItem *item[d];
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        QString tit;
        QString id;
        QString lvl;
        QDomElement racine = m_doc.documentElement(); //renvoie la balise racine
        QDomNode noeud = racine.firstChild();

        QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0, racine.childNodes().count(), 0);
        progress.setWindowModality(Qt::WindowModal);
        progress.setEnabled(false);
        progress.show();
        qApp->processEvents();

<<<<<<< HEAD
        item= new QTreeWidgetItem(view);
        item->setText(0,trUtf8("بسم الله الرحمن الرحيم") );
        item->setData(1,1,1);
=======
        item[1]= new QTreeWidgetItem(view);
        item[1]->setText(0,trUtf8("بسم الله الرحمن الرحيم") );
        item[1]->setData(1,1,1);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        int r=0;
        while(!noeud.isNull())
        {
            ++r;

            progress.setValue(r);
            qApp->processEvents();
            QDomNodeList tab;
            QDomElement mesures;
            mesures=noeud.toElement();
            if (mesures.tagName()== "title")
            {
                tab = mesures.childNodes();
                for(int i=0;i<(int)tab.length();++i)
                {
                    QDomNode noeud2=tab.item(i);
                    QDomElement mesures2=noeud2.toElement();
                    QString text=noeud2.firstChild().toText().data();
                    if (mesures2.tagName()=="lvl"){lvl=text.trimmed() ;}
                    if (mesures2.tagName()=="tit"){tit=text ;}
                    if (mesures2.tagName()=="id"){

                        int dd=getPositionID(text) ;
                        QVariant ddv=dd;
                        id= ddv.toString();
                        // QMessageBox::information(this,trUtf8("معلومات"),id);
                    }

                }
                bool ok;
                d=lvl.toInt(&ok,0);
                if (ok==true){
<<<<<<< HEAD
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
                   }
=======
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
                }
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
            }
            noeud = noeud.nextSibling();
        }
        m_doc.clear();
        file.close();
    }
}
<<<<<<< HEAD
QTreeWidgetItem* databook::getItem(QTreeWidgetItem *item)
{



    int index=item->childCount()-1;
 //   QTreeWidgetItem *itemParent=(item->child(index));
    return item->child(index);
}
=======

>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
bool  databook::chargeList()
{
    listId.clear();
    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    int count = racine.childNodes().count();

    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0, count, 0);
    progress.setWindowModality(Qt::WindowModal);
    progress.setEnabled(false);
    progress.show();
    qApp->processEvents();

    for (int i=1;i<count;++i){
        progress.setValue(i);
        qApp->processEvents();
        QDomNode noeud = racine.childNodes().item(i);
        listId.append( noeud.firstChildElement("id").firstChild().toText().data());
    }
    return true;
}

int  databook::getPositionID(QString id)
{

    int newid=listId.indexOf(id);
    if (newid==-1){newid=1;}
    if (newid==0){newid=1;}
    return newid+2;
}

void databook::insertPage(bool after)
{
     int i=currentPosition[boocNumIndex];
    QString newPage="0";
    if(after==true){
        if(rowsCount[boocNumIndex]==i){

            newPage=QString::number(i+1);
        }
     }

<<<<<<< HEAD
=======


>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    QDomNode curNoeud = racine.childNodes().item(currentPosition[boocNumIndex]);
   // QDomNode newNooeud=m_docBooK[boocNumIndex].createElement("book");

    QDomElement myel=m_docBooK[boocNumIndex].createElement("book");     //انشاء عنصر جديد
  //  racine.appendChild(myel);
    QDomElement myid=m_docBooK[boocNumIndex].createElement("id");     //انشاء عنصر جديد
    myel.appendChild(myid);
    QDomText t1 = m_docBooK[boocNumIndex].createTextNode("0");
    myid.appendChild(t1);
    QDomElement mynass=m_docBooK[boocNumIndex].createElement("nass");     //انشاء عنصر جديد
    myel.appendChild(mynass);
    QDomText t2 = m_docBooK[boocNumIndex].createTextNode(trUtf8("صفحة فارغة")+QString::number(rowsCount[boocNumIndex]));
    mynass.appendChild(t2);
    QDomElement mypart=m_docBooK[boocNumIndex].createElement("part");     //انشاء عنصر جديد
    myel.appendChild(mypart);
    QDomText t3 = m_docBooK[boocNumIndex].createTextNode(bookPart[boocNumIndex]);
    mypart.appendChild(t3);
    QDomElement mypage=m_docBooK[boocNumIndex].createElement("page");     //انشاء عنصر جديد
    myel.appendChild(mypage);
    QDomText t4 = m_docBooK[boocNumIndex].createTextNode(newPage);
    mypage.appendChild(t4);
     rowsCount[boocNumIndex]++;
    if (after==true){
       racine.insertAfter(myel,curNoeud);
       moveToPosition(currentPosition[boocNumIndex]+1);
   }else{
        racine.insertBefore(myel,curNoeud);
        moveToPosition(currentPosition[boocNumIndex]);
   }


   // saveBook();
}
void databook::removeCurPage()
{
    QDomElement racine = m_docBooK[boocNumIndex].documentElement(); //renvoie la balise racine
    QDomNode curNoeud = racine.childNodes().item(currentPosition[boocNumIndex]);
    racine.removeChild(curNoeud);
    rowsCount[boocNumIndex]--;
}
