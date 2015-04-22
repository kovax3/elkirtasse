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
#include "rowat.h"
#include <QtGui>

#include <QMessageBox>

 void rowat::clearData()
 {
     docRowat.clear();
 }

 void rowat::treeChargeRowtName(QTreeWidget *view)
 {

      QTreeWidgetItem *item=new QTreeWidgetItem(view) ;

QString textRowat;
  //   QFile file(QCoreApplication::applicationDirPath() +"/data/rowaInfo.xml");

     QDir appDir(qApp->applicationDirPath());
     appDir.cdUp();
     QFile file ( appDir.absolutePath()+"/share/elkirtasse/data/rowaInfo.xml");

     if(!file.open(QIODevice::ReadOnly)) return;
     view->clear();
     QXmlStreamReader xml;
int counter=0;
     xml.setDevice(&file);

     if (xml.readNextStartElement()) {
         if (xml.name() == "dataroot" ){
              Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
               while (xml.readNextStartElement()) {

                   if (xml.name() == "rowa"){
                     counter++;


                     while (xml.readNextStartElement()) {

                         if (xml.name() == "name"){
                             textRowat=xml.readElementText();
textRowat.remove(trUtf8("\330\214 "));
textRowat.remove(":");
textRowat.replace("W",trUtf8("صلى الله عليه وسلم"));
//                         }else if (xml.name() == "AQUAL"){
//                             AQUAL= xml.readElementText();
//                         }else if (xml.name() == "sheok"){
//                             sheok= xml.readElementText();
//                         }else if (xml.name() == "telmez"){
//                             telmez= xml.readElementText();
//                         }else if (xml.name() == "TABAQA"){
//                             TABAQA= xml.readElementText();
//                         }else if (xml.name() == "WHO"){
//                             WHO= xml.readElementText();
//
//                         }else if (xml.name() == "ROTBA"){
//                             ROTBA= xml.readElementText();
//                         }else if (xml.name() == "R_ZAHBI"){
//                             R_ZAHBI= xml.readElementText();
//
//                         }else if (xml.name() == "birth"){
//                             birth= xml.readElementText();
//                         }else if (xml.name() == "death"){
//                             death= xml.readElementText();
                         }else{
                             xml.skipCurrentElement();
                         }

                     }
                     item= new QTreeWidgetItem(view);
                     item->setData(1,1,QString::number(counter));
                     item->setText(0,textRowat.trimmed() );
//                      item->setText(1,sheok );
//                      item->setText(2,telmez );
//                       item->setText(3,AQUAL );
//                        item->setText(4,TABAQA+"*"+WHO+"*"+ROTBA+"*"+R_ZAHBI+"*"+ birth+"*"+death);


                 }else{
                     xml.skipCurrentElement();
                 }
             }
         }
     }
     xml.clear();
     file.close();
 }
 bool rowat::chargeRowat()
 {
     if(!docRowat.isNull()) return false;

     //QFile file(QCoreApplication::applicationDirPath() +"/data/rowaInfo.xml");
     QDir appDir(qApp->applicationDirPath());
     appDir.cdUp();
     QFile file ( appDir.absolutePath()+"/share/elkirtasse/data/rowaInfo.xml");
     if(!file.open(QIODevice::ReadOnly)) return false;

     if (!docRowat.setContent(&file)) {
         return false;
     }else{
          return true;
     }

 }

 QString rowat::moveToPosition(int position)
 {

     int pos=position-1;
     QDomElement racine = docRowat.documentElement(); //renvoie la balise racine
     QDomNode noeud = racine.childNodes().item(pos);

    name=   noeud.firstChildElement("name").firstChild().toText().data();

   TABAQA=   noeud.firstChildElement("TABAQA").firstChild().toText().data();
  WHO=   noeud.firstChildElement("WHO").firstChild().toText().data();
    AQUAL=   noeud.firstChildElement("AQUAL").firstChild().toText().data();
   ROTBA=   noeud.firstChildElement("ROTBA").firstChild().toText().data();
    R_ZAHBI=   noeud.firstChildElement("R_ZAHBI").firstChild().toText().data();
    sheok=   noeud.firstChildElement("sheok").firstChild().toText().data();
    telmez=   noeud.firstChildElement("telmez").firstChild().toText().data();
     birth=   noeud.firstChildElement("birth").firstChild().toText().data();
     death=   noeud.firstChildElement("death").firstChild().toText().data();

   return creatHtml() ;

 }


QString rowat::readxml(int pos)
{
    QXmlStreamReader xml;
//    QFile filex(QCoreApplication::applicationDirPath() +"/data/rowaInfo.xml");
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QFile filex ( appDir.absolutePath()+"/share/elkirtasse/data/rowaInfo.xml");

    int counter=0;

     if(!filex.open(QIODevice::ReadOnly)) return "" ;
 xml.setDevice(&filex);


    //**********
//    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0, pos, 0);
//    progress.setWindowModality(Qt::WindowModal);
//    progress.setEnabled(false);
//    progress.show();
    //progress->setVisible(true);
    //progress->setMaximum(pos);
    //************
   // qApp->processEvents();
    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" ){
             Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
              while (xml.readNextStartElement()) {

                  if (xml.name() == "rowa"){
                      //QMessageBox::information(0,"",QString::number(counter));
                      counter++;
                   //   progress->setValue(counter);
                //       qApp->processEvents();
                       while (xml.readNextStartElement()) {

                           if(counter==pos){
                               if (xml.name() == "name"){
                                   name= xml.readElementText();
                               }else if (xml.name() == "TABAQA"){
                                   TABAQA= xml.readElementText();
                               }else if (xml.name() == "WHO"){
                                   WHO= xml.readElementText();
                               }else if (xml.name() == "AQUAL"){
                                   AQUAL= xml.readElementText();
                               }else if (xml.name() == "ROTBA"){
                                   ROTBA= xml.readElementText();
                               }else if (xml.name() == "R_ZAHBI"){
                                   R_ZAHBI= xml.readElementText();
                               }else if (xml.name() == "sheok"){
                                   sheok= xml.readElementText();

                               }else if (xml.name() == "telmez"){
                                   telmez= xml.readElementText();
                               }else if (xml.name() == "birth"){
                                   birth= xml.readElementText();
                               }else if (xml.name() == "death"){
                                   death= xml.readElementText();
                               }else{

                                   xml.skipCurrentElement();

                               }

                           }else{
                               xml.skipCurrentElement();

                           }

                       }
 if(counter==pos){break;}
                  }


              }

        }
    }
  //  progress->setVisible(false);
   return creatHtml() ;
}
/*QString rowat::creatHtml()
{
    // return name+"\n"+TABAQA+"\n"+WHO+"\n"+AQUAL+"\n"+ROTBA+"\n"+R_ZAHBI+"\n"+sheok+"\n"+telmez+"\n"+birth+"\n"+death;


    TABAQA.replace("1 : F",trUtf8("1 : صحابى"));
    TABAQA.replace("G",trUtf8("2  : من كبار التابعين"));
    TABAQA.replace("H",trUtf8("3  : من الوسطى من التابعين"));
    TABAQA.replace("I",trUtf8("4  : طبقة تلى الوسطى من التابعين"));
    TABAQA.replace("J",trUtf8("5  : من صغار التابعين"));
    TABAQA.replace("K",trUtf8("6  : من الذين عاصروا صغارالتابعين"));
    TABAQA.replace("L",trUtf8("7  : من كبار أتباع التابعين"));
    TABAQA.replace("M",trUtf8("8  : من الوسطى من أتباع التابعين"));
    TABAQA.replace("N",trUtf8("9  : من صغار أتباع التابعين"));
    TABAQA.replace("O",trUtf8("10 : كبارالآخذين عن تبع الأتباع"));
    TABAQA.replace("P",trUtf8("11 : أوساط الآخذين عن تبع الأتباع"));
    TABAQA.replace("Q",trUtf8("12 : صغارالآخذين عن تبع الأتباع"));

    AQUAL.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
    AQUAL.replace("E",trUtf8("قال الحافظ في تهذيب التهذيب"));
    AQUAL.replace("A",trUtf8("قال المزي في تهذيب الكمال : روى عن"));
    AQUAL.replace("B",trUtf8("قال المزي في تهذيب الكمال : روى عنه"));
    AQUAL.replace("D",trUtf8("ذكر المزي في تهذيب الكمال"));
    AQUAL.replace("W",trUtf8("صلى الله عليه وسلم"));

    sheok.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
    sheok.replace("E",trUtf8("قال الحافظ في تهذيب التهذيب"));
    sheok.replace("A",trUtf8("قال المزي في تهذيب الكمال : روى عن"));
    sheok.replace("B",trUtf8("قال المزي في تهذيب الكمال : روى عنه"));
    sheok.replace("D",trUtf8("ذكر المزي في تهذيب الكمال"));
    sheok.replace("W",trUtf8("صلى الله عليه وسلم"));

    telmez.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
    telmez.replace("E",trUtf8("قال الحافظ في تهذيب التهذيب"));
    telmez.replace("A",trUtf8("قال المزي في تهذيب الكمال : روى عن"));
    telmez.replace("B",trUtf8("قال المزي في تهذيب الكمال : روى عنه"));
    telmez.replace("D",trUtf8("ذكر المزي في تهذيب الكمال"));
    telmez.replace("W",trUtf8("صلى الله عليه وسلم"));

sheok.remove(".");
telmez.remove(".");
sheok.replace("# #","#");
telmez.replace("# #","#");


    QString tableName= "<table align='center' width='100%' border='0'>"

                       "<COL WIDTH=100%>"
                               "<TR bgcolor='#1E3564'>"
                                       "<TD WIDTH=100% VALIGN=TOP STYLE=\"border: 0px solid #000000; padding: 0.04in\">"
                                               "<P ALIGN=CENTER><span style=\"color:#ffffff;\">"+ name+"</span></P>"
                                       "</TD>"
                               "</TR>"
                               "<TR bgcolor='#87AD6F'>"

"<TD WIDTH=100% VALIGN=TOP STYLE=\"border-top: none; border-bottom: none solid #000000; border-left: none solid #000000; border-right: none solid #000000; padding-top: 0in; padding-bottom: 0.04in; padding-left: 0.04in; padding-right: 0.04in\">"
;

    QString molakhasse=trUtf8("الطبقة :")+TABAQA+"<br>"+trUtf8("روى له :")+WHO+"<br>"+
                      trUtf8("رتبته عند ابن حجر :")+ROTBA+"<br>"+trUtf8("رتبته عند الذهبي :")+R_ZAHBI+"<br>"+
                      trUtf8("ولد :")+birth+"<br>"+trUtf8("توفي :")+death;

    QString tableMolakhass="<table align='center' width='100%' border='0'>"
                        "<tr bgcolor='#366833'>"
                        "<th width='100%' scope='col'><span style=\"  color:#ffffff;\">"+ trUtf8("ملخص")+"</span></th>"
                        "</tr>"

                        "<tr bgcolor='#EDF5DC'><td><div align='right'><span style=\"color:#000000;\">"+molakhasse+"</span></div></td></tr>"

                        "</table>";
    AQUAL=AQUAL.replace("#","<br>");
    QString tableAQUAL="<table align='center' width='100%' border='0'>"
                       "<tr bgcolor='#366833'>"
                       "<th width='100%' scope='col'><span style=\"  color:#ffffff;\">"+ trUtf8("أقوال")+"</span></th>"
                       "</tr>"

                       "<tr bgcolor='#EDF5DC'><td><div align='right'><span style=\" color:#000000;\">"+AQUAL+"</span></div></td></tr>"

                       "</table>";

    //-***********************sheok*******************************************
    
    QStringList listsheok = sheok.split("#", QString::SkipEmptyParts);
    QString itemsheok;
    for (int i=0;i<listsheok.count();i=i+2){
        QString item=listsheok.at(i);

        itemsheok=itemsheok+"<tr bgcolor='#EDF5DC'>";
       if (item.contains(trUtf8("تهذيب"))){
           itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\">"+item+"</span></div></td>";
       }else{
           itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item+"'>"+item+"</a></span></div></td>";

       }
       if (i<listsheok.count()-1){
           QString item2=listsheok.at(i+1);
           if (item2.contains(trUtf8("تهذيب"))){
               itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\">"+item2+"</span></div></td>";
           }else{
               itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item2+"'>"+item2+"</a></span></div></td>";

           }
       }
    }

    QString tablesheok="<table align='center' width='100%' border='0'>"
                       "<tr bgcolor='#366833'>"
                       "<th width='100%' scope='col'><span style=\"   color:#ffffff;\">"+ trUtf8("شيوخ")+"</span></th>"
                       "</tr></table>"

                       "<table align='center' width='100%' border='0'>"
                       "<COL ><COL >" + itemsheok+
                       "</tr></table>";
      //-************************sheok*******************************************


    //-************************telmez*******************************************
    QStringList listtelmez = telmez.split("#", QString::SkipEmptyParts);
    QString itemtelmez;
    for (int i=0;i<listtelmez.count();i=i+2){
        QString item=listtelmez.at(i);
        itemtelmez=itemtelmez+"<tr bgcolor='#EDF5DC'>";
        QString tt=item.trimmed().left(1);

        if (item.contains(trUtf8("تهذيب"))||tt=="("){
            itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\">"+item+"</span></div></td>";
        }else{
            itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item+"'>"+item+"</a></span></div></td>";

        }
        if (i<listtelmez.count()-1){
            QString item2=listtelmez.at(i+1);
            QString t=item2.trimmed().left(1);

            if (item2.contains(trUtf8("تهذيب"))||t=="("){
                itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\">"+item2+"</span></div></td>";
            }else{
                itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item2+"'>"+item2+"</a></span></div></td>";

            }
        }
    }

    QString tabletelmez="<table align='center' width='100%' border='0'>"
                       "<tr bgcolor='#366833'>"
                       "<th width='100%' scope='col'><span style=\" color:#ffffff;\">"+ trUtf8("تلاميذ")+"</span></th>"
                       "</tr></table>"

                       "<table align='center' width='97%' border='0'>"
                       "<COL ><COL >" + itemtelmez+
                       "</tr></table></TD></tr></table>";
      //-************************sheok*******************************************
QString htm=tableName+tableMolakhass+tableAQUAL+tablesheok+tabletelmez;

    return htm;

}*/

QString rowat::creatHtml()
{
    // return name+"\n"+TABAQA+"\n"+WHO+"\n"+AQUAL+"\n"+ROTBA+"\n"+R_ZAHBI+"\n"+sheok+"\n"+telmez+"\n"+birth+"\n"+death;
   // خ م د ت س ق  ( البخاري - مسلم - أبو داود - الترمذي - النسائي - ابن ماجه )

TABAQA.replace("O",trUtf8("10 : كبارالآخذين عن تبع الأتباع"));
TABAQA.replace("Q",trUtf8("12 : صغارالآخذين عن تبع الأتباع"));
TABAQA.replace("P",trUtf8(" 11 : أوساط الآخذين عن تبع الأتباع"));
TABAQA.replace("N",trUtf8("9  : من صغار أتباع التابعين"));
TABAQA.replace("H",trUtf8("3  : من الوسطى من التابعين"));
TABAQA.replace("1 : F",trUtf8("1 : صحابى"));
TABAQA.replace("I",trUtf8("4  : طبقة تلى الوسطى من التابعين"));
TABAQA.replace("K",trUtf8(" 6  : من الذين عاصروا صغارالتابعين"));
TABAQA.replace("L",trUtf8("7  : من كبار أتباع التابعين"));
TABAQA.replace("M",trUtf8("8  : من الوسطى من أتباع التابعين"));
TABAQA.replace("G",trUtf8(" 2  : من كبار التابعين"));
TABAQA.replace("J",trUtf8(" 5  : من صغار التابعين "));

AQUAL.replace(": #",":<br>");

  AQUAL.replace("#","");
AQUAL.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
AQUAL.replace("E",trUtf8(". قال الحافظ في تهذيب التهذيب"));
 AQUAL.replace(".",".<br>");
sheok.replace("A",trUtf8("#قال المزي في تهذيب الكمال : روى عن"));
sheok.replace("C",trUtf8("#قال المزي في تهذيب الكمال  :"));
sheok.replace("E",trUtf8("#قال الحافظ في تهذيب التهذيب"));
sheok.replace("D",trUtf8("#ذكر المزي في تهذيب الكمال"));
//telmez=telmez.replace("A",trUtf8("***قال المزي في تهذيب الكمال : روى عن"));
telmez.replace("B",trUtf8("#قال المزي في تهذيب الكمال : روى عنه"));
telmez.replace("C",trUtf8(" #قال المزي في تهذيب الكمال  :"));
telmez.replace("E",trUtf8(" #قال الحافظ في تهذيب التهذيب"));
telmez.replace("D",trUtf8(" #ذكر المزي في تهذيب الكمال"));
//----------------------molakhes------------------
QString molakhasse=trUtf8("المولد : ")+birth+"<br>"+trUtf8("الوفاة : ")+death+"<br>"+trUtf8("الطبقة : ")+TABAQA+"<br>"+
                  trUtf8("روى له : ")+WHO+"<br>"+ trUtf8("رتبته عند ابن حجر : ")+ROTBA+"<br>" +
                 trUtf8("رتبته عند الذهبي : ")+R_ZAHBI;
//----------------------choyohk------------------
sheok.replace("# #", "#");
sheok.remove(".");
QStringList listsheok = sheok.split("#", QString::SkipEmptyParts);
QString itemsheok;
for (int i=0;i<listsheok.count();i=i+2){
    QString item=listsheok.at(i);
    QString t1=item.trimmed().left(1);
    QString ismnabi=item.trimmed().section(" ",0,0);
    itemsheok=itemsheok+"<tr>";
    if (item.contains(trUtf8("تهذيب"))||t1=="("||ismnabi==trUtf8("النبى")){
        itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+item+"</div></td>";
    }else{
        itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+item+"'>"+item+"</a></div></td>";
    }
    if (i<listsheok.count()-1){
        QString item2=listsheok.at(i+1);
QString t2=item2.trimmed().left(1);
QString ismnabi2=item2.trimmed().section(" ",0,0);
        if (item2.contains(trUtf8("تهذيب"))||t2=="("||ismnabi2==trUtf8("النبى")){
            itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+item2+"</div></td>";
        }else{
            itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+item2+"'>"+item2+"</a></div></td>";
        }
    }else if(i==listsheok.count()-1){
        itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\">""</td>";
    }
    itemsheok=itemsheok+"</tr>";
}
//----------------------telmez------------------
telmez.replace("# #", "#");
telmez.remove(".");
QStringList listtelmiz = telmez.split("#", QString::SkipEmptyParts);
QString itemtelmiz;
for (int i=0;i<listtelmiz.count();i=i+2){
    QString itemT=listtelmiz.at(i);
    QString t1=itemT.trimmed().left(1);


    itemtelmiz=itemtelmiz+"<tr>";
    if (itemT.contains(trUtf8("تهذيب"))||t1=="("){
        itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+itemT+"</div></td>";
    }else{
        itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+itemT+"'>"+itemT+"</a></div></td>";
    }
    if (i<listtelmiz.count()-1){
        QString itemT2=listtelmiz.at(i+1);
QString t2=itemT2.trimmed().left(1);

        if (itemT2.contains(trUtf8("تهذيب"))||t2=="("){
            itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+itemT2+"</div></td</div>";
        }else{
            itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+itemT2+"'>"+itemT2+"</a></div></td>";
        }
    }else if(i==listtelmiz.count()-1){
        itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"></td>";
    }
    itemtelmiz=itemtelmiz+"</tr>";
}
//-----------------------html---------------------

  QString htm= "<title>"+name+"</title>"
               "<style type=\"text/css\">"
               "th {color: #FFF;text-align: center;}"
"tr {color: #000;}"

               "a:link {color: #069;}"
               "a:visited {color: #63F;}"
               "a:hover {color: #03F;}"
               "a:active {color: #33F;}"
               "</style></head><body>"

               "<table width=\"100%\" border=\"0\">"
                 "<tr><th bgcolor=\"#1E3564\" class=\"titl\" scope=\"col\">"+name+"</th></tr>"
                 "<tr><td bgcolor=\"#87AD6F\"><table width=\"100%\" border=\"0\">"

                     "<tr><th width=\"100%\" bgcolor=\"#366833\" scope=\"col\">"+trUtf8("ملخص")+"</th></tr>"

                    "<tr><td bgcolor=\"#FFFFE6\" ><div align='right'>"+molakhasse+"</div></td></tr></table>"

                    "<table width=\"100%\" border=\"0\"><tr> <th bgcolor=\"#366833\" scope=\"col\">"+trUtf8("الجرح والتعديل")+"</th></tr>"

                        "<tr><td bgcolor=\"#FFFFE6\"><div align='right'>"+AQUAL+"</div></td></tr></table>"

                        "<table width=\"100%\" border=\"0\"><tr><th bgcolor=\"#366833\" scope=\"col\">"+trUtf8("شيوخ")+"</th></tr>"

                                "<tr><td><table width=\"100%\" border=\"0\" align=\"right\">"
                               +  itemsheok+

                                "</table></td></tr>"
                                "</table>"

                              "<table width=\"100%\" border=\"0\"><tr><th bgcolor=\"#366833\" scope=\"col\">"+trUtf8("تلاميذ")+"</th></tr>"

                                "<tr><td><table width=\"100%\" border=\"0\" align=\"right\">"
                                   +itemtelmiz+
                                "</table></td></tr>"
                              "</table>"
               "</td></tr></table></body>" ;

htm.replace("W",trUtf8("صلى الله عليه وسلم"));

  return htm;
}

void rowat::rawiFind(QString rawi,QTreeWidget *viewS,QTreeWidget *viewD)
 {

     viewD->clear();
  //1--النص يساويه تماما
     QTreeWidgetItem *itemR=new QTreeWidgetItem;
     QList<QTreeWidgetItem *> foundR =
             viewS->findItems(
                     rawi,Qt::MatchExactly,0);

     foreach (itemR, foundR){

             QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
             itemF->setText(0,itemR->text(0));
             itemF->setData(1,1,itemR->data(1,1));

             if (viewD->topLevelItemCount()>0){
                // QMessageBox::information(0,"hg","ful 1");
                 return;
             }
         }
     rawi=   fullRawi(rawi);
//1--النص موجودا في اوله
     QTreeWidgetItem *itemB=new QTreeWidgetItem;
     QList<QTreeWidgetItem *> foundB =
             viewS->findItems(
                     rawi,Qt::MatchStartsWith,0);

     foreach (itemB, foundB){

             QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
             itemF->setText(0,itemB->text(0));
             itemF->setData(1,1,itemB->data(1,1));


     }

 if (viewD->topLevelItemCount()>0){
  //   QMessageBox::information(0,"hg","debu 2");
     return;
 }

//--انشاء قائمة
  QList<QString> list;
     QString lastTxt;
     QString firstTxt=rawi;
     int iC=rawi.count(" ");


         QString tt=rawi.trimmed().section(" ",0,1);
          QString td=rawi.trimmed().section(" ",0,0);

         if (tt==(trUtf8("أبو عبد"))||tt==(trUtf8("أبى عبد"))){

             if (rawiFindAbou(rawi,viewS,viewD)==true){
                 return;
              }else{

                  rawi.remove(rawi.section(" ",0,2));
                  lastTxt=rawi.section(" ",-1);
                  //lastTxt.replace(trUtf8("أبى"),trUtf8("أبو"));

              }

         }else if (td==(trUtf8("أبو"))||td==(trUtf8("أبى"))){
             if (rawiFindAbou(rawi,viewS,viewD)==true){
                 return;
              }else{

                   rawi.remove(rawi.section(" ",0,1));
                   lastTxt=rawi.section(" ",-1);
                  //lastTxt.replace(trUtf8("أبى"),trUtf8("أبو"));
              }


          }else{
              lastTxt=rawi.section(" ",-1);

              rawi.remove(lastTxt);
          }


         iC=rawi.trimmed().count(" ");
         int loop=0;
         if (iC<=2)
             loop=-1;
         for (int i=iC;i>loop ;i-- ){
             QString txt=rawi.trimmed().section(" ",0,i);
             if (txt.section(" ",-1)!=trUtf8("بن")&& txt.section(" ",-1)!=trUtf8("أبى")&& txt.section(" ",-1)!=trUtf8("عبد")){
                 list.append(txt);
               //  QMessageBox::information(0,"",txt);
             }

         }
     //}
 //3--البحث عن النص الصرف
     QTreeWidgetItem *item=new QTreeWidgetItem;
     QList<QTreeWidgetItem *> found =
             viewS->findItems(
                     firstTxt,Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

     foreach (item, found){
         if (item->text(0).contains(lastTxt)){
             QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
             itemF->setText(0,item->text(0));
             itemF->setData(1,1,item->data(1,1));
         }
     }


 if (viewD->topLevelItemCount()>0){
  //    QMessageBox::information(0,"","firstTxt contain lasttext MatchStartsWith 3");
     return;
 }
//4- البحث عن القائمة بشروط

     for (int i=0;i<list.count();i++){
         QTreeWidgetItem *item=new QTreeWidgetItem;
         QList<QTreeWidgetItem *> found =
                 viewS->findItems(
                         list.at(i),Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

         foreach (item, found){
             if (item->text(0).contains(lastTxt)){
                 QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                 itemF->setText(0,item->text(0));
                  itemF->setData(1,1,item->data(1,1));

             }

         }

         if (viewD->topLevelItemCount()>0){
           //   QMessageBox::information(0,"","list.at(i)  contain lasttext MatchStartsWith 4");
             return;
         }
     }

     //5-في اي موضع البحث عن القائمة بشروط
     for (int i=0;i<list.count();i++){
         QTreeWidgetItem *item=new QTreeWidgetItem;
         QList<QTreeWidgetItem *> found =
                 viewS->findItems(
                         list.at(i),Qt::MatchContains,0);//تنشاء قائمة بكل العناصر

         foreach (item, found){
             if (item->text(0).contains(lastTxt)){
                 QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                 itemF->setText(0,item->text(0));
                  itemF->setData(1,1,item->data(1,1));
                // break;
             }

         }

         if (viewD->topLevelItemCount()>0){
        //        QMessageBox::information(0,"","list.at(i)  contain lasttext MatchContains 5");
             return;
         }
     }

//6- البحث عن القائمة بدون شروط

     for (int i=0;i<list.count();i++){
         int cout=list.at(i).count(" ");
         if (cout>1){
             QTreeWidgetItem *item=new QTreeWidgetItem;
             QList<QTreeWidgetItem *> found =
                     viewS->findItems(
                             list.at(i),Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

             foreach (item, found){

                 QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                 itemF->setText(0,item->text(0));
                 itemF->setData(1,1,item->data(1,1));


             }
         }
     if (viewD->topLevelItemCount()>0){
      //   QMessageBox::information(0,"","list.at(i)  MatchStartsWith 6");
         return;
     }
 }



}
  QString rowat::fullRawi(QString rawi)
  {
      if (rawi==trUtf8("البخارى"))return(trUtf8("محمد بن إسماعيل بن إبراهيم بن المغيرة الجعفى مولاهم"));
      if (rawi==trUtf8("النسائى"))return(trUtf8("أحمد بن شعيب بن على بن سنان بن بحر بن دينار"));
      if (rawi==trUtf8("ابن ماجة"))return(trUtf8("محمد بن يزيد الربعى مولاهم"));
      if (rawi==trUtf8("الترمذى"))return(trUtf8("محمد بن عيسى بن سورة بن موسى بن الضحاك السلمى"));
      if (rawi==trUtf8("أبو داود"))return(trUtf8("سليمان بن الأشعث بن إسحاق بن بشير بن شداد"));
      if (rawi==trUtf8("مسلم"))return(trUtf8("مسلم بن الحجاج بن مسلم القشيرى"));
      if (rawi==trUtf8("أحمد بن حنبل"))return(trUtf8("أحمد بن محمد بن حنبل بن هلال بن أسد الشيبانى"));
      if (rawi==trUtf8("الزهرى"))return(trUtf8("محمد بن مسلم بن عبيد الله بن عبد الله بن شهاب"));

      if (rawi==trUtf8("أبو بكر الصديق")||rawi==trUtf8("أبى بكر الصديق"))return(trUtf8("عبد الله بن أبى قحافة"));

      if (rawi==trUtf8("عمر بن الخطاب"))return(trUtf8("عمر بن الخطاب بن نفيل بن عبد العزى"));

      if (rawi==trUtf8("أبى هريرة")||rawi==trUtf8("أبو هريرة"))return(trUtf8("أبو هريرة الدوسى اليمانى"));
      if (rawi==trUtf8("عائشة"))return(trUtf8("عائشة بنت أبى بكر"));
     if (rawi==trUtf8("الشعبى"))return(trUtf8("عامر بن شراحيل"));

      if (rawi==trUtf8("أم سلمة"))return(trUtf8("هند بنت أبى أمية"));
      return rawi;
  }
//abou
bool rowat::rawiFindAbou(QString rawi,QTreeWidget *viewS,QTreeWidget *viewD)
{
    viewD->clear();
    QString abou= rawi.section(" ",0,0);
    rawi.remove(abou);
    rawi=trUtf8("أبو")+rawi;
   // QMessageBox::information(0,"",rawi);
    QTreeWidgetItem *itemB=new QTreeWidgetItem;
    //1--كل النص في بدايته
    QList<QTreeWidgetItem *> foundB =
            viewS->findItems(
                    rawi,Qt::MatchStartsWith,0);

    foreach (itemB, foundB){

        QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
        itemF->setText(0,itemB->text(0));
        itemF->setData(1,1,itemB->data(1,1));


    }
    if (viewD->topLevelItemCount()>0) {
     //   QMessageBox::information(0,"","abou MatchStartsWith");
        return true;
    }
    //2--كل النص اينما وجد

    QList<QTreeWidgetItem *> foundC =
            viewS->findItems(
                    rawi,Qt::MatchContains,0);

    foreach (itemB, foundC){

        QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
        itemF->setText(0,itemB->text(0));
        itemF->setData(1,1,itemB->data(1,1));


    }
    if (viewD->topLevelItemCount()>0) {
      //  QMessageBox::information(0,"","abou MatchContains");
        return true;
    }



    QList<QString> list;

    QString firstTxt;
    int iC;
    //lastTxt=rawi.section(" ",-1);
    //rawi.remove(lastTxt);

    QString tt=rawi.trimmed().section(" ",0,1);
    QString td=rawi.trimmed().section(" ",0,0);
    if (tt==(trUtf8("أبو عبد"))){
        firstTxt=rawi.section(" ",0,2);
        rawi.remove(firstTxt);
    }else if (td==trUtf8("أبو")){
        firstTxt=rawi.section(" ",0,1);
        rawi.remove(firstTxt);
    }

 //   QMessageBox::information(0,"",rawi +"\n"+firstTxt);
    iC=rawi.trimmed().count(" ");
    for (int i=iC;i>0 ;i-- ){
        QString txt=rawi.trimmed().section(" ",0,i);
        if (txt.section(" ",-1)!=trUtf8("بن")&& txt.section(" ",-1)!=trUtf8("أبى")&& txt.section(" ",-1)!=trUtf8("عبد")){
            list.append(txt);
            // QMessageBox::information(0,"",txt);
        }

    }


    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            viewS->findItems(
                    rawi,Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر
    //1--البحث عن النص الصرف
    foreach (item, found){
        if (item->text(0).contains(firstTxt)){
            QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
            itemF->setText(0,item->text(0));
            itemF->setData(1,1,item->data(1,1));
        }
    }
    if (viewD->topLevelItemCount()>0) {
   //     QMessageBox::information(0,"","abou true1 MatchStartsWith");
        return true;
    }
    //    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> foundD =
            viewS->findItems(
                    rawi,Qt::MatchContains,0);//تنشاء قائمة بكل العناصر
    //1--البحث عن النص الصرف
    foreach (item, foundD){
        if (item->text(0).contains(firstTxt)){
            QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
            itemF->setText(0,item->text(0));
            itemF->setData(1,1,item->data(1,1));
        }
    }


    if (viewD->topLevelItemCount()>0) {
     //   QMessageBox::information(0,"","abou true1 MatchContains");
        return true;
    }
    //2- البحث عن القائمة بشروط

    for (int i=0;i<list.count();i++){
        QString ab=list.at(i);

        //QMessageBox::information(0,"",ab);
       // QTreeWidgetItem *item=new QTreeWidgetItem;
        QList<QTreeWidgetItem *> found =
                viewS->findItems(
                        ab,Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

        foreach (item, found){
            if (item->text(0).contains(firstTxt)){
                QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                itemF->setText(0,item->text(0));
                itemF->setData(1,1,item->data(1,1));

            }
            if (viewD->topLevelItemCount()>0){
            //    QMessageBox::information(0,"","abou true2");
                return true;
            }
        }

    }
    for (int i=0;i<list.count();i++){
        QString ab=list.at(i);

        // QMessageBox::information(0,"",ab);
       // QTreeWidgetItem *item=new QTreeWidgetItem;
        QList<QTreeWidgetItem *> found =
                viewS->findItems(
                        ab,Qt::MatchContains,0);//تنشاء قائمة بكل العناصر

        foreach (item, found){
            if (item->text(0).contains(firstTxt)){
                QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                itemF->setText(0,item->text(0));
                itemF->setData(1,1,item->data(1,1));

            }
            if (viewD->topLevelItemCount()>0){
            //    QMessageBox::information(0,"","abou true3");
                return true;
            }
        }

    }

    if (viewD->topLevelItemCount()==0){
        //  QMessageBox::information(0,"","false");
        return false;
    }
   return false;
}
Q_EXPORT_PLUGIN2(kirtasserowat, rowat);
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
#include "rowat.h"
#include <QtGui>

#include <QMessageBox>

 void rowat::clearData()
 {
     docRowat.clear();
 }

 void rowat::treeChargeRowtName(QTreeWidget *view)
 {

      QTreeWidgetItem *item=new QTreeWidgetItem(view) ;

QString textRowat;
  //   QFile file(QCoreApplication::applicationDirPath() +"/data/rowaInfo.xml");

     QDir appDir(qApp->applicationDirPath());
     appDir.cdUp();
     QFile file ( appDir.absolutePath()+"/share/elkirtasse/data/rowaInfo.xml");

     if(!file.open(QIODevice::ReadOnly)) return;
     view->clear();
     QXmlStreamReader xml;
int counter=0;
     xml.setDevice(&file);

     if (xml.readNextStartElement()) {
         if (xml.name() == "dataroot" ){
              Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
               while (xml.readNextStartElement()) {

                   if (xml.name() == "rowa"){
                     counter++;


                     while (xml.readNextStartElement()) {

                         if (xml.name() == "name"){
                             textRowat=xml.readElementText();
textRowat.remove(trUtf8("\330\214 "));
textRowat.remove(":");
textRowat.replace("W",trUtf8("صلى الله عليه وسلم"));
//                         }else if (xml.name() == "AQUAL"){
//                             AQUAL= xml.readElementText();
//                         }else if (xml.name() == "sheok"){
//                             sheok= xml.readElementText();
//                         }else if (xml.name() == "telmez"){
//                             telmez= xml.readElementText();
//                         }else if (xml.name() == "TABAQA"){
//                             TABAQA= xml.readElementText();
//                         }else if (xml.name() == "WHO"){
//                             WHO= xml.readElementText();
//
//                         }else if (xml.name() == "ROTBA"){
//                             ROTBA= xml.readElementText();
//                         }else if (xml.name() == "R_ZAHBI"){
//                             R_ZAHBI= xml.readElementText();
//
//                         }else if (xml.name() == "birth"){
//                             birth= xml.readElementText();
//                         }else if (xml.name() == "death"){
//                             death= xml.readElementText();
                         }else{
                             xml.skipCurrentElement();
                         }

                     }
                     item= new QTreeWidgetItem(view);
                     item->setData(1,1,QString::number(counter));
                     item->setText(0,textRowat.trimmed() );
//                      item->setText(1,sheok );
//                      item->setText(2,telmez );
//                       item->setText(3,AQUAL );
//                        item->setText(4,TABAQA+"*"+WHO+"*"+ROTBA+"*"+R_ZAHBI+"*"+ birth+"*"+death);


                 }else{
                     xml.skipCurrentElement();
                 }
             }
         }
     }
     xml.clear();
     file.close();
 }
 bool rowat::chargeRowat()
 {
     if(!docRowat.isNull()) return false;

     //QFile file(QCoreApplication::applicationDirPath() +"/data/rowaInfo.xml");
     QDir appDir(qApp->applicationDirPath());
     appDir.cdUp();
     QFile file ( appDir.absolutePath()+"/share/elkirtasse/data/rowaInfo.xml");
     if(!file.open(QIODevice::ReadOnly)) return false;

     if (!docRowat.setContent(&file)) {
         return false;
     }else{
          return true;
     }

 }

 QString rowat::moveToPosition(int position)
 {

     int pos=position-1;
     QDomElement racine = docRowat.documentElement(); //renvoie la balise racine
     QDomNode noeud = racine.childNodes().item(pos);

    name=   noeud.firstChildElement("name").firstChild().toText().data();

   TABAQA=   noeud.firstChildElement("TABAQA").firstChild().toText().data();
  WHO=   noeud.firstChildElement("WHO").firstChild().toText().data();
    AQUAL=   noeud.firstChildElement("AQUAL").firstChild().toText().data();
   ROTBA=   noeud.firstChildElement("ROTBA").firstChild().toText().data();
    R_ZAHBI=   noeud.firstChildElement("R_ZAHBI").firstChild().toText().data();
    sheok=   noeud.firstChildElement("sheok").firstChild().toText().data();
    telmez=   noeud.firstChildElement("telmez").firstChild().toText().data();
     birth=   noeud.firstChildElement("birth").firstChild().toText().data();
     death=   noeud.firstChildElement("death").firstChild().toText().data();

   return creatHtml() ;

 }


QString rowat::readxml(int pos)
{
    QXmlStreamReader xml;
//    QFile filex(QCoreApplication::applicationDirPath() +"/data/rowaInfo.xml");
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QFile filex ( appDir.absolutePath()+"/share/elkirtasse/data/rowaInfo.xml");

    int counter=0;

     if(!filex.open(QIODevice::ReadOnly)) return "" ;
 xml.setDevice(&filex);


    //**********
//    QProgressDialog progress(trUtf8("الرجاء الانتظار...."), trUtf8("الغاء"), 0, pos, 0);
//    progress.setWindowModality(Qt::WindowModal);
//    progress.setEnabled(false);
//    progress.show();
    //progress->setVisible(true);
    //progress->setMaximum(pos);
    //************
   // qApp->processEvents();
    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" ){
             Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
              while (xml.readNextStartElement()) {

                  if (xml.name() == "rowa"){
                      //QMessageBox::information(0,"",QString::number(counter));
                      counter++;
                   //   progress->setValue(counter);
                //       qApp->processEvents();
                       while (xml.readNextStartElement()) {

                           if(counter==pos){
                               if (xml.name() == "name"){
                                   name= xml.readElementText();
                               }else if (xml.name() == "TABAQA"){
                                   TABAQA= xml.readElementText();
                               }else if (xml.name() == "WHO"){
                                   WHO= xml.readElementText();
                               }else if (xml.name() == "AQUAL"){
                                   AQUAL= xml.readElementText();
                               }else if (xml.name() == "ROTBA"){
                                   ROTBA= xml.readElementText();
                               }else if (xml.name() == "R_ZAHBI"){
                                   R_ZAHBI= xml.readElementText();
                               }else if (xml.name() == "sheok"){
                                   sheok= xml.readElementText();

                               }else if (xml.name() == "telmez"){
                                   telmez= xml.readElementText();
                               }else if (xml.name() == "birth"){
                                   birth= xml.readElementText();
                               }else if (xml.name() == "death"){
                                   death= xml.readElementText();
                               }else{

                                   xml.skipCurrentElement();

                               }

                           }else{
                               xml.skipCurrentElement();

                           }

                       }
 if(counter==pos){break;}
                  }


              }

        }
    }
  //  progress->setVisible(false);
   return creatHtml() ;
}
/*QString rowat::creatHtml()
{
    // return name+"\n"+TABAQA+"\n"+WHO+"\n"+AQUAL+"\n"+ROTBA+"\n"+R_ZAHBI+"\n"+sheok+"\n"+telmez+"\n"+birth+"\n"+death;


    TABAQA.replace("1 : F",trUtf8("1 : صحابى"));
    TABAQA.replace("G",trUtf8("2  : من كبار التابعين"));
    TABAQA.replace("H",trUtf8("3  : من الوسطى من التابعين"));
    TABAQA.replace("I",trUtf8("4  : طبقة تلى الوسطى من التابعين"));
    TABAQA.replace("J",trUtf8("5  : من صغار التابعين"));
    TABAQA.replace("K",trUtf8("6  : من الذين عاصروا صغارالتابعين"));
    TABAQA.replace("L",trUtf8("7  : من كبار أتباع التابعين"));
    TABAQA.replace("M",trUtf8("8  : من الوسطى من أتباع التابعين"));
    TABAQA.replace("N",trUtf8("9  : من صغار أتباع التابعين"));
    TABAQA.replace("O",trUtf8("10 : كبارالآخذين عن تبع الأتباع"));
    TABAQA.replace("P",trUtf8("11 : أوساط الآخذين عن تبع الأتباع"));
    TABAQA.replace("Q",trUtf8("12 : صغارالآخذين عن تبع الأتباع"));

    AQUAL.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
    AQUAL.replace("E",trUtf8("قال الحافظ في تهذيب التهذيب"));
    AQUAL.replace("A",trUtf8("قال المزي في تهذيب الكمال : روى عن"));
    AQUAL.replace("B",trUtf8("قال المزي في تهذيب الكمال : روى عنه"));
    AQUAL.replace("D",trUtf8("ذكر المزي في تهذيب الكمال"));
    AQUAL.replace("W",trUtf8("صلى الله عليه وسلم"));

    sheok.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
    sheok.replace("E",trUtf8("قال الحافظ في تهذيب التهذيب"));
    sheok.replace("A",trUtf8("قال المزي في تهذيب الكمال : روى عن"));
    sheok.replace("B",trUtf8("قال المزي في تهذيب الكمال : روى عنه"));
    sheok.replace("D",trUtf8("ذكر المزي في تهذيب الكمال"));
    sheok.replace("W",trUtf8("صلى الله عليه وسلم"));

    telmez.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
    telmez.replace("E",trUtf8("قال الحافظ في تهذيب التهذيب"));
    telmez.replace("A",trUtf8("قال المزي في تهذيب الكمال : روى عن"));
    telmez.replace("B",trUtf8("قال المزي في تهذيب الكمال : روى عنه"));
    telmez.replace("D",trUtf8("ذكر المزي في تهذيب الكمال"));
    telmez.replace("W",trUtf8("صلى الله عليه وسلم"));

sheok.remove(".");
telmez.remove(".");
sheok.replace("# #","#");
telmez.replace("# #","#");


    QString tableName= "<table align='center' width='100%' border='0'>"

                       "<COL WIDTH=100%>"
                               "<TR bgcolor='#1E3564'>"
                                       "<TD WIDTH=100% VALIGN=TOP STYLE=\"border: 0px solid #000000; padding: 0.04in\">"
                                               "<P ALIGN=CENTER><span style=\"color:#ffffff;\">"+ name+"</span></P>"
                                       "</TD>"
                               "</TR>"
                               "<TR bgcolor='#87AD6F'>"

"<TD WIDTH=100% VALIGN=TOP STYLE=\"border-top: none; border-bottom: none solid #000000; border-left: none solid #000000; border-right: none solid #000000; padding-top: 0in; padding-bottom: 0.04in; padding-left: 0.04in; padding-right: 0.04in\">"
;

    QString molakhasse=trUtf8("الطبقة :")+TABAQA+"<br>"+trUtf8("روى له :")+WHO+"<br>"+
                      trUtf8("رتبته عند ابن حجر :")+ROTBA+"<br>"+trUtf8("رتبته عند الذهبي :")+R_ZAHBI+"<br>"+
                      trUtf8("ولد :")+birth+"<br>"+trUtf8("توفي :")+death;

    QString tableMolakhass="<table align='center' width='100%' border='0'>"
                        "<tr bgcolor='#366833'>"
                        "<th width='100%' scope='col'><span style=\"  color:#ffffff;\">"+ trUtf8("ملخص")+"</span></th>"
                        "</tr>"

                        "<tr bgcolor='#EDF5DC'><td><div align='right'><span style=\"color:#000000;\">"+molakhasse+"</span></div></td></tr>"

                        "</table>";
    AQUAL=AQUAL.replace("#","<br>");
    QString tableAQUAL="<table align='center' width='100%' border='0'>"
                       "<tr bgcolor='#366833'>"
                       "<th width='100%' scope='col'><span style=\"  color:#ffffff;\">"+ trUtf8("أقوال")+"</span></th>"
                       "</tr>"

                       "<tr bgcolor='#EDF5DC'><td><div align='right'><span style=\" color:#000000;\">"+AQUAL+"</span></div></td></tr>"

                       "</table>";

    //-***********************sheok*******************************************
    
    QStringList listsheok = sheok.split("#", QString::SkipEmptyParts);
    QString itemsheok;
    for (int i=0;i<listsheok.count();i=i+2){
        QString item=listsheok.at(i);

        itemsheok=itemsheok+"<tr bgcolor='#EDF5DC'>";
       if (item.contains(trUtf8("تهذيب"))){
           itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\">"+item+"</span></div></td>";
       }else{
           itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item+"'>"+item+"</a></span></div></td>";

       }
       if (i<listsheok.count()-1){
           QString item2=listsheok.at(i+1);
           if (item2.contains(trUtf8("تهذيب"))){
               itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\">"+item2+"</span></div></td>";
           }else{
               itemsheok=itemsheok+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item2+"'>"+item2+"</a></span></div></td>";

           }
       }
    }

    QString tablesheok="<table align='center' width='100%' border='0'>"
                       "<tr bgcolor='#366833'>"
                       "<th width='100%' scope='col'><span style=\"   color:#ffffff;\">"+ trUtf8("شيوخ")+"</span></th>"
                       "</tr></table>"

                       "<table align='center' width='100%' border='0'>"
                       "<COL ><COL >" + itemsheok+
                       "</tr></table>";
      //-************************sheok*******************************************


    //-************************telmez*******************************************
    QStringList listtelmez = telmez.split("#", QString::SkipEmptyParts);
    QString itemtelmez;
    for (int i=0;i<listtelmez.count();i=i+2){
        QString item=listtelmez.at(i);
        itemtelmez=itemtelmez+"<tr bgcolor='#EDF5DC'>";
        QString tt=item.trimmed().left(1);

        if (item.contains(trUtf8("تهذيب"))||tt=="("){
            itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\">"+item+"</span></div></td>";
        }else{
            itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item+"'>"+item+"</a></span></div></td>";

        }
        if (i<listtelmez.count()-1){
            QString item2=listtelmez.at(i+1);
            QString t=item2.trimmed().left(1);

            if (item2.contains(trUtf8("تهذيب"))||t=="("){
                itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\">"+item2+"</span></div></td>";
            }else{
                itemtelmez=itemtelmez+"<td><div align='right'><span style=\"color:#000000;\"><a href='#*"+item2+"'>"+item2+"</a></span></div></td>";

            }
        }
    }

    QString tabletelmez="<table align='center' width='100%' border='0'>"
                       "<tr bgcolor='#366833'>"
                       "<th width='100%' scope='col'><span style=\" color:#ffffff;\">"+ trUtf8("تلاميذ")+"</span></th>"
                       "</tr></table>"

                       "<table align='center' width='97%' border='0'>"
                       "<COL ><COL >" + itemtelmez+
                       "</tr></table></TD></tr></table>";
      //-************************sheok*******************************************
QString htm=tableName+tableMolakhass+tableAQUAL+tablesheok+tabletelmez;

    return htm;

}*/

QString rowat::creatHtml()
{
    // return name+"\n"+TABAQA+"\n"+WHO+"\n"+AQUAL+"\n"+ROTBA+"\n"+R_ZAHBI+"\n"+sheok+"\n"+telmez+"\n"+birth+"\n"+death;
   // خ م د ت س ق  ( البخاري - مسلم - أبو داود - الترمذي - النسائي - ابن ماجه )

TABAQA.replace("O",trUtf8("10 : كبارالآخذين عن تبع الأتباع"));
TABAQA.replace("Q",trUtf8("12 : صغارالآخذين عن تبع الأتباع"));
TABAQA.replace("P",trUtf8(" 11 : أوساط الآخذين عن تبع الأتباع"));
TABAQA.replace("N",trUtf8("9  : من صغار أتباع التابعين"));
TABAQA.replace("H",trUtf8("3  : من الوسطى من التابعين"));
TABAQA.replace("1 : F",trUtf8("1 : صحابى"));
TABAQA.replace("I",trUtf8("4  : طبقة تلى الوسطى من التابعين"));
TABAQA.replace("K",trUtf8(" 6  : من الذين عاصروا صغارالتابعين"));
TABAQA.replace("L",trUtf8("7  : من كبار أتباع التابعين"));
TABAQA.replace("M",trUtf8("8  : من الوسطى من أتباع التابعين"));
TABAQA.replace("G",trUtf8(" 2  : من كبار التابعين"));
TABAQA.replace("J",trUtf8(" 5  : من صغار التابعين "));

AQUAL.replace(": #",":<br>");

  AQUAL.replace("#","");
AQUAL.replace("C",trUtf8("قال المزي في تهذيب الكمال"));
AQUAL.replace("E",trUtf8(". قال الحافظ في تهذيب التهذيب"));
 AQUAL.replace(".",".<br>");
sheok.replace("A",trUtf8("#قال المزي في تهذيب الكمال : روى عن"));
sheok.replace("C",trUtf8("#قال المزي في تهذيب الكمال  :"));
sheok.replace("E",trUtf8("#قال الحافظ في تهذيب التهذيب"));
sheok.replace("D",trUtf8("#ذكر المزي في تهذيب الكمال"));
//telmez=telmez.replace("A",trUtf8("***قال المزي في تهذيب الكمال : روى عن"));
telmez.replace("B",trUtf8("#قال المزي في تهذيب الكمال : روى عنه"));
telmez.replace("C",trUtf8(" #قال المزي في تهذيب الكمال  :"));
telmez.replace("E",trUtf8(" #قال الحافظ في تهذيب التهذيب"));
telmez.replace("D",trUtf8(" #ذكر المزي في تهذيب الكمال"));
//----------------------molakhes------------------
QString molakhasse=trUtf8("المولد : ")+birth+"<br>"+trUtf8("الوفاة : ")+death+"<br>"+trUtf8("الطبقة : ")+TABAQA+"<br>"+
                  trUtf8("روى له : ")+WHO+"<br>"+ trUtf8("رتبته عند ابن حجر : ")+ROTBA+"<br>" +
                 trUtf8("رتبته عند الذهبي : ")+R_ZAHBI;
//----------------------choyohk------------------
sheok.replace("# #", "#");
sheok.remove(".");
QStringList listsheok = sheok.split("#", QString::SkipEmptyParts);
QString itemsheok;
for (int i=0;i<listsheok.count();i=i+2){
    QString item=listsheok.at(i);
    QString t1=item.trimmed().left(1);
    QString ismnabi=item.trimmed().section(" ",0,0);
    itemsheok=itemsheok+"<tr>";
    if (item.contains(trUtf8("تهذيب"))||t1=="("||ismnabi==trUtf8("النبى")){
        itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+item+"</div></td>";
    }else{
        itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+item+"'>"+item+"</a></div></td>";
    }
    if (i<listsheok.count()-1){
        QString item2=listsheok.at(i+1);
QString t2=item2.trimmed().left(1);
QString ismnabi2=item2.trimmed().section(" ",0,0);
        if (item2.contains(trUtf8("تهذيب"))||t2=="("||ismnabi2==trUtf8("النبى")){
            itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+item2+"</div></td>";
        }else{
            itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+item2+"'>"+item2+"</a></div></td>";
        }
    }else if(i==listsheok.count()-1){
        itemsheok=itemsheok+  "<td bgcolor=\"#FFFFE6\" scope=\"col\">""</td>";
    }
    itemsheok=itemsheok+"</tr>";
}
//----------------------telmez------------------
telmez.replace("# #", "#");
telmez.remove(".");
QStringList listtelmiz = telmez.split("#", QString::SkipEmptyParts);
QString itemtelmiz;
for (int i=0;i<listtelmiz.count();i=i+2){
    QString itemT=listtelmiz.at(i);
    QString t1=itemT.trimmed().left(1);


    itemtelmiz=itemtelmiz+"<tr>";
    if (itemT.contains(trUtf8("تهذيب"))||t1=="("){
        itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+itemT+"</div></td>";
    }else{
        itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+itemT+"'>"+itemT+"</a></div></td>";
    }
    if (i<listtelmiz.count()-1){
        QString itemT2=listtelmiz.at(i+1);
QString t2=itemT2.trimmed().left(1);

        if (itemT2.contains(trUtf8("تهذيب"))||t2=="("){
            itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'>"+itemT2+"</div></td</div>";
        }else{
            itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"><div align='right'><a href='#*"+itemT2+"'>"+itemT2+"</a></div></td>";
        }
    }else if(i==listtelmiz.count()-1){
        itemtelmiz=itemtelmiz+  "<td bgcolor=\"#FFFFE6\" scope=\"col\"></td>";
    }
    itemtelmiz=itemtelmiz+"</tr>";
}
//-----------------------html---------------------

  QString htm= "<title>"+name+"</title>"
               "<style type=\"text/css\">"
               "th {color: #FFF;text-align: center;}"
"tr {color: #000;}"

               "a:link {color: #069;}"
               "a:visited {color: #63F;}"
               "a:hover {color: #03F;}"
               "a:active {color: #33F;}"
               "</style></head><body>"

               "<table width=\"100%\" border=\"0\">"
                 "<tr><th bgcolor=\"#1E3564\" class=\"titl\" scope=\"col\">"+name+"</th></tr>"
                 "<tr><td bgcolor=\"#87AD6F\"><table width=\"100%\" border=\"0\">"

                     "<tr><th width=\"100%\" bgcolor=\"#366833\" scope=\"col\">"+trUtf8("ملخص")+"</th></tr>"

                    "<tr><td bgcolor=\"#FFFFE6\" ><div align='right'>"+molakhasse+"</div></td></tr></table>"

                    "<table width=\"100%\" border=\"0\"><tr> <th bgcolor=\"#366833\" scope=\"col\">"+trUtf8("الجرح والتعديل")+"</th></tr>"

                        "<tr><td bgcolor=\"#FFFFE6\"><div align='right'>"+AQUAL+"</div></td></tr></table>"

                        "<table width=\"100%\" border=\"0\"><tr><th bgcolor=\"#366833\" scope=\"col\">"+trUtf8("شيوخ")+"</th></tr>"

                                "<tr><td><table width=\"100%\" border=\"0\" align=\"right\">"
                               +  itemsheok+

                                "</table></td></tr>"
                                "</table>"

                              "<table width=\"100%\" border=\"0\"><tr><th bgcolor=\"#366833\" scope=\"col\">"+trUtf8("تلاميذ")+"</th></tr>"

                                "<tr><td><table width=\"100%\" border=\"0\" align=\"right\">"
                                   +itemtelmiz+
                                "</table></td></tr>"
                              "</table>"
               "</td></tr></table></body>" ;

htm.replace("W",trUtf8("صلى الله عليه وسلم"));

  return htm;
}

void rowat::rawiFind(QString rawi,QTreeWidget *viewS,QTreeWidget *viewD)
 {

     viewD->clear();
  //1--النص يساويه تماما
     QTreeWidgetItem *itemR=new QTreeWidgetItem;
     QList<QTreeWidgetItem *> foundR =
             viewS->findItems(
                     rawi,Qt::MatchExactly,0);

     foreach (itemR, foundR){

             QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
             itemF->setText(0,itemR->text(0));
             itemF->setData(1,1,itemR->data(1,1));

             if (viewD->topLevelItemCount()>0){
                // QMessageBox::information(0,"hg","ful 1");
                 return;
             }
         }
     rawi=   fullRawi(rawi);
//1--النص موجودا في اوله
     QTreeWidgetItem *itemB=new QTreeWidgetItem;
     QList<QTreeWidgetItem *> foundB =
             viewS->findItems(
                     rawi,Qt::MatchStartsWith,0);

     foreach (itemB, foundB){

             QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
             itemF->setText(0,itemB->text(0));
             itemF->setData(1,1,itemB->data(1,1));


     }

 if (viewD->topLevelItemCount()>0){
  //   QMessageBox::information(0,"hg","debu 2");
     return;
 }

//--انشاء قائمة
  QList<QString> list;
     QString lastTxt;
     QString firstTxt=rawi;
     int iC=rawi.count(" ");


         QString tt=rawi.trimmed().section(" ",0,1);
          QString td=rawi.trimmed().section(" ",0,0);

         if (tt==(trUtf8("أبو عبد"))||tt==(trUtf8("أبى عبد"))){

             if (rawiFindAbou(rawi,viewS,viewD)==true){
                 return;
              }else{

                  rawi.remove(rawi.section(" ",0,2));
                  lastTxt=rawi.section(" ",-1);
                  //lastTxt.replace(trUtf8("أبى"),trUtf8("أبو"));

              }

         }else if (td==(trUtf8("أبو"))||td==(trUtf8("أبى"))){
             if (rawiFindAbou(rawi,viewS,viewD)==true){
                 return;
              }else{

                   rawi.remove(rawi.section(" ",0,1));
                   lastTxt=rawi.section(" ",-1);
                  //lastTxt.replace(trUtf8("أبى"),trUtf8("أبو"));
              }


          }else{
              lastTxt=rawi.section(" ",-1);

              rawi.remove(lastTxt);
          }


         iC=rawi.trimmed().count(" ");
         int loop=0;
         if (iC<=2)
             loop=-1;
         for (int i=iC;i>loop ;i-- ){
             QString txt=rawi.trimmed().section(" ",0,i);
             if (txt.section(" ",-1)!=trUtf8("بن")&& txt.section(" ",-1)!=trUtf8("أبى")&& txt.section(" ",-1)!=trUtf8("عبد")){
                 list.append(txt);
               //  QMessageBox::information(0,"",txt);
             }

         }
     //}
 //3--البحث عن النص الصرف
     QTreeWidgetItem *item=new QTreeWidgetItem;
     QList<QTreeWidgetItem *> found =
             viewS->findItems(
                     firstTxt,Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

     foreach (item, found){
         if (item->text(0).contains(lastTxt)){
             QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
             itemF->setText(0,item->text(0));
             itemF->setData(1,1,item->data(1,1));
         }
     }


 if (viewD->topLevelItemCount()>0){
  //    QMessageBox::information(0,"","firstTxt contain lasttext MatchStartsWith 3");
     return;
 }
//4- البحث عن القائمة بشروط

     for (int i=0;i<list.count();i++){
         QTreeWidgetItem *item=new QTreeWidgetItem;
         QList<QTreeWidgetItem *> found =
                 viewS->findItems(
                         list.at(i),Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

         foreach (item, found){
             if (item->text(0).contains(lastTxt)){
                 QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                 itemF->setText(0,item->text(0));
                  itemF->setData(1,1,item->data(1,1));

             }

         }

         if (viewD->topLevelItemCount()>0){
           //   QMessageBox::information(0,"","list.at(i)  contain lasttext MatchStartsWith 4");
             return;
         }
     }

     //5-في اي موضع البحث عن القائمة بشروط
     for (int i=0;i<list.count();i++){
         QTreeWidgetItem *item=new QTreeWidgetItem;
         QList<QTreeWidgetItem *> found =
                 viewS->findItems(
                         list.at(i),Qt::MatchContains,0);//تنشاء قائمة بكل العناصر

         foreach (item, found){
             if (item->text(0).contains(lastTxt)){
                 QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                 itemF->setText(0,item->text(0));
                  itemF->setData(1,1,item->data(1,1));
                // break;
             }

         }

         if (viewD->topLevelItemCount()>0){
        //        QMessageBox::information(0,"","list.at(i)  contain lasttext MatchContains 5");
             return;
         }
     }

//6- البحث عن القائمة بدون شروط

     for (int i=0;i<list.count();i++){
         int cout=list.at(i).count(" ");
         if (cout>1){
             QTreeWidgetItem *item=new QTreeWidgetItem;
             QList<QTreeWidgetItem *> found =
                     viewS->findItems(
                             list.at(i),Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

             foreach (item, found){

                 QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                 itemF->setText(0,item->text(0));
                 itemF->setData(1,1,item->data(1,1));


             }
         }
     if (viewD->topLevelItemCount()>0){
      //   QMessageBox::information(0,"","list.at(i)  MatchStartsWith 6");
         return;
     }
 }



}
  QString rowat::fullRawi(QString rawi)
  {
      if (rawi==trUtf8("البخارى"))return(trUtf8("محمد بن إسماعيل بن إبراهيم بن المغيرة الجعفى مولاهم"));
      if (rawi==trUtf8("النسائى"))return(trUtf8("أحمد بن شعيب بن على بن سنان بن بحر بن دينار"));
      if (rawi==trUtf8("ابن ماجة"))return(trUtf8("محمد بن يزيد الربعى مولاهم"));
      if (rawi==trUtf8("الترمذى"))return(trUtf8("محمد بن عيسى بن سورة بن موسى بن الضحاك السلمى"));
      if (rawi==trUtf8("أبو داود"))return(trUtf8("سليمان بن الأشعث بن إسحاق بن بشير بن شداد"));
      if (rawi==trUtf8("مسلم"))return(trUtf8("مسلم بن الحجاج بن مسلم القشيرى"));
      if (rawi==trUtf8("أحمد بن حنبل"))return(trUtf8("أحمد بن محمد بن حنبل بن هلال بن أسد الشيبانى"));
      if (rawi==trUtf8("الزهرى"))return(trUtf8("محمد بن مسلم بن عبيد الله بن عبد الله بن شهاب"));

      if (rawi==trUtf8("أبو بكر الصديق")||rawi==trUtf8("أبى بكر الصديق"))return(trUtf8("عبد الله بن أبى قحافة"));

      if (rawi==trUtf8("عمر بن الخطاب"))return(trUtf8("عمر بن الخطاب بن نفيل بن عبد العزى"));

      if (rawi==trUtf8("أبى هريرة")||rawi==trUtf8("أبو هريرة"))return(trUtf8("أبو هريرة الدوسى اليمانى"));
      if (rawi==trUtf8("عائشة"))return(trUtf8("عائشة بنت أبى بكر"));
     if (rawi==trUtf8("الشعبى"))return(trUtf8("عامر بن شراحيل"));

      if (rawi==trUtf8("أم سلمة"))return(trUtf8("هند بنت أبى أمية"));
      return rawi;
  }
//abou
bool rowat::rawiFindAbou(QString rawi,QTreeWidget *viewS,QTreeWidget *viewD)
{
    viewD->clear();
    QString abou= rawi.section(" ",0,0);
    rawi.remove(abou);
    rawi=trUtf8("أبو")+rawi;
   // QMessageBox::information(0,"",rawi);
    QTreeWidgetItem *itemB=new QTreeWidgetItem;
    //1--كل النص في بدايته
    QList<QTreeWidgetItem *> foundB =
            viewS->findItems(
                    rawi,Qt::MatchStartsWith,0);

    foreach (itemB, foundB){

        QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
        itemF->setText(0,itemB->text(0));
        itemF->setData(1,1,itemB->data(1,1));


    }
    if (viewD->topLevelItemCount()>0) {
     //   QMessageBox::information(0,"","abou MatchStartsWith");
        return true;
    }
    //2--كل النص اينما وجد

    QList<QTreeWidgetItem *> foundC =
            viewS->findItems(
                    rawi,Qt::MatchContains,0);

    foreach (itemB, foundC){

        QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
        itemF->setText(0,itemB->text(0));
        itemF->setData(1,1,itemB->data(1,1));


    }
    if (viewD->topLevelItemCount()>0) {
      //  QMessageBox::information(0,"","abou MatchContains");
        return true;
    }



    QList<QString> list;

    QString firstTxt;
    int iC;
    //lastTxt=rawi.section(" ",-1);
    //rawi.remove(lastTxt);

    QString tt=rawi.trimmed().section(" ",0,1);
    QString td=rawi.trimmed().section(" ",0,0);
    if (tt==(trUtf8("أبو عبد"))){
        firstTxt=rawi.section(" ",0,2);
        rawi.remove(firstTxt);
    }else if (td==trUtf8("أبو")){
        firstTxt=rawi.section(" ",0,1);
        rawi.remove(firstTxt);
    }

 //   QMessageBox::information(0,"",rawi +"\n"+firstTxt);
    iC=rawi.trimmed().count(" ");
    for (int i=iC;i>0 ;i-- ){
        QString txt=rawi.trimmed().section(" ",0,i);
        if (txt.section(" ",-1)!=trUtf8("بن")&& txt.section(" ",-1)!=trUtf8("أبى")&& txt.section(" ",-1)!=trUtf8("عبد")){
            list.append(txt);
            // QMessageBox::information(0,"",txt);
        }

    }


    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            viewS->findItems(
                    rawi,Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر
    //1--البحث عن النص الصرف
    foreach (item, found){
        if (item->text(0).contains(firstTxt)){
            QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
            itemF->setText(0,item->text(0));
            itemF->setData(1,1,item->data(1,1));
        }
    }
    if (viewD->topLevelItemCount()>0) {
   //     QMessageBox::information(0,"","abou true1 MatchStartsWith");
        return true;
    }
    //    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> foundD =
            viewS->findItems(
                    rawi,Qt::MatchContains,0);//تنشاء قائمة بكل العناصر
    //1--البحث عن النص الصرف
    foreach (item, foundD){
        if (item->text(0).contains(firstTxt)){
            QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
            itemF->setText(0,item->text(0));
            itemF->setData(1,1,item->data(1,1));
        }
    }


    if (viewD->topLevelItemCount()>0) {
     //   QMessageBox::information(0,"","abou true1 MatchContains");
        return true;
    }
    //2- البحث عن القائمة بشروط

    for (int i=0;i<list.count();i++){
        QString ab=list.at(i);

        //QMessageBox::information(0,"",ab);
       // QTreeWidgetItem *item=new QTreeWidgetItem;
        QList<QTreeWidgetItem *> found =
                viewS->findItems(
                        ab,Qt::MatchStartsWith,0);//تنشاء قائمة بكل العناصر

        foreach (item, found){
            if (item->text(0).contains(firstTxt)){
                QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                itemF->setText(0,item->text(0));
                itemF->setData(1,1,item->data(1,1));

            }
            if (viewD->topLevelItemCount()>0){
            //    QMessageBox::information(0,"","abou true2");
                return true;
            }
        }

    }
    for (int i=0;i<list.count();i++){
        QString ab=list.at(i);

        // QMessageBox::information(0,"",ab);
       // QTreeWidgetItem *item=new QTreeWidgetItem;
        QList<QTreeWidgetItem *> found =
                viewS->findItems(
                        ab,Qt::MatchContains,0);//تنشاء قائمة بكل العناصر

        foreach (item, found){
            if (item->text(0).contains(firstTxt)){
                QTreeWidgetItem *itemF=new QTreeWidgetItem(viewD);
                itemF->setText(0,item->text(0));
                itemF->setData(1,1,item->data(1,1));

            }
            if (viewD->topLevelItemCount()>0){
            //    QMessageBox::information(0,"","abou true3");
                return true;
            }
        }

    }

    if (viewD->topLevelItemCount()==0){
        //  QMessageBox::information(0,"","false");
        return false;
    }
   return false;
}
Q_EXPORT_PLUGIN2(kirtasserowat, rowat);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
