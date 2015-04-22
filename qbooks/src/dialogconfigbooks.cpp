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

#include "dialogconfigbooks.h"
#include "ui_dialogconfigbooks.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
DialogConfigBooks::DialogConfigBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigBooks)
{
    ui->setupUi(this);
    imgChanged=false;
    if(qApp->layoutDirection()==Qt::LeftToRight){
        ui->toolButtonBookToGroup->setArrowType(Qt::RightArrow);
        ui->toolButtonGroupTosection->setArrowType(Qt::RightArrow);
    }else{

       ui->toolButtonBookToGroup->setArrowType(Qt::LeftArrow);
      ui->toolButtonGroupTosection->setArrowType(Qt::LeftArrow);
    }
ui->toolButtonUpdatBk->setIcon(QIcon(style()->standardPixmap(QStyle::SP_BrowserReload)));
ui->toolButtonGroupUpdat->setIcon(QIcon(style()->standardPixmap(QStyle::SP_BrowserReload)));
ui->toolButtonReloadAll->setIcon(QIcon(style()->standardPixmap(QStyle::SP_BrowserReload)));

        Messages = new messages();
  Messages->treeChargeGroupe( ui->treeWidgetBooks,0,true);
  int count= ui->treeWidgetBooks->topLevelItemCount();
    for(int i=0;i<count;i++){

         QTreeWidgetItem *itemTop=ui->treeWidgetBooks->topLevelItem(i);
        ui->comboBoxSection->addItem(itemTop->icon(0),itemTop->text(0));
         //ui->comboBoxGroupTosection->addItem(itemTop->icon(0),itemTop->text(0));


    }
    ui->comboBoxSection->setCurrentIndex(-1);
         ui->lineEditGroup->setText(QDir::homePath()+"/.kirtasse/data/group.xml");
}

DialogConfigBooks::~DialogConfigBooks()
{
    delete ui;
}
//عند تفعيل القسم من القائمة المنسدلة
void DialogConfigBooks::on_comboBoxSection_activated(int index)
{
    ui->treeWidgetCurGroup->clear();
    QTreeWidgetItem *itemTop=ui->treeWidgetBooks->topLevelItem(index);
    ui->treeWidgetBooks->setCurrentItem(itemTop);

    int count=itemTop->childCount();


    for(int i=0;i<count;i++){
        QTreeWidgetItem *item= new QTreeWidgetItem(  ui->treeWidgetCurGroup);
        item->setText(0,itemTop->child(i)->text(0));
        item->setData(2,1,itemTop->child(i)->data(2,1));
        item->setData(1,0,index);//data fo index
        item->setIcon(0,itemTop->child(i)->icon(0));
    }
    if (count>0)
           ui->treeWidgetCurGroup->topLevelItem(0)->setSelected(true);
ui->treeWidgetCurBooks->clear();
}



//نقل عناصر الكتاب الى مجموعة اخرى
void DialogConfigBooks::on_toolButtonBookToGroup_clicked()
{
    //نسخ العناصر المحددة الى قائمة
    QList<QTreeWidgetItem *> items;
    items.append(ui->treeWidgetCurBooks->selectedItems());
    //معرفة موقع المجموعة من الشجرة الاصلية
    int indexSection=ui->comboBoxSection->currentIndex();
    QTreeWidgetItem *itemGroup=ui->treeWidgetBooks->topLevelItem(indexSection)->child(indexGroup);

    //معرفة المجموعة الوجهة اذا كانت محددة
    QTreeWidgetItem *itemBookToGroupDist=ui->treeWidgetBooks->currentItem();
    if(!itemBookToGroupDist)
        return;
    if(!itemBookToGroupDist->parent())
        return;
    if(itemBookToGroupDist->parent()->parent())
        itemBookToGroupDist=itemBookToGroupDist->parent();


    //عدد العناصر
    int count=items.count();

    for(int i=0;i<count;i++){
        QTreeWidgetItem *item= items.at(i);
        int index=ui->treeWidgetCurBooks->indexOfTopLevelItem(item);
        ui->treeWidgetCurBooks->takeTopLevelItem(index);//مسح العنصر من المحدد
        itemGroup->takeChild(index);//مسح العنصر من الاصل
        itemBookToGroupDist->addChild(item);//اضافة العنصر الى الوجهة القادمة
    }



}


//نقل جموعة الى قسم جديد
void DialogConfigBooks::on_toolButtonGroupTosection_clicked()
{
    QTreeWidgetItem *itemSectionDist=ui->treeWidgetBooks->currentItem();
    if(!itemSectionDist){
        return;
    }else if(!itemSectionDist->parent()){
        itemSectionDist=itemSectionDist;
    }else if(itemSectionDist->parent()->parent()){
       itemSectionDist=itemSectionDist->parent()->parent();
    }else if(itemSectionDist->parent()){
       itemSectionDist=itemSectionDist->parent();
    }

int indexSection=ui->comboBoxSection->currentIndex();
int i=ui->treeWidgetBooks->indexOfTopLevelItem(itemSectionDist);
if(indexSection==i)
    return;

int index=ui->treeWidgetCurGroup->indexOfTopLevelItem(ui->treeWidgetCurGroup->currentItem());

QTreeWidgetItem *itemGroup=ui->treeWidgetBooks->topLevelItem(indexSection)->child(index);

QTreeWidgetItem *itemNew=new QTreeWidgetItem;
 itemNew= itemGroup->clone();

  ui->treeWidgetCurGroup->takeTopLevelItem(index);
 ui->treeWidgetBooks->topLevelItem(indexSection)->takeChild(index);
 itemSectionDist->addChild(itemNew);

}

void DialogConfigBooks::on_treeWidgetCurGroup_itemSelectionChanged()
{
QTreeWidgetItem *item=ui->treeWidgetCurGroup->currentItem();
if(!item)return;
    ui->treeWidgetCurBooks->clear();
    int index=item->data(1,0).toInt();
    QTreeWidgetItem *itemTop=ui->treeWidgetBooks->topLevelItem(index);
    int curIndex=ui->treeWidgetCurGroup->indexOfTopLevelItem(item);
QTreeWidgetItem *itemBk=itemTop->child(curIndex);
    int count=itemBk->childCount();

        for(int i=0;i<count;i++){
             QTreeWidgetItem *itemBook=itemBk->child(i)->clone();
              ui->treeWidgetCurBooks->addTopLevelItem(itemBook);
          itemBook->setIcon(0,itemBk->child(i)->icon(0));
        }
      //اضافة عنصر غير مرئي حتى لا يحدث خطأ عند حذف جميع العناصر
        QTreeWidgetItem *itemL=new QTreeWidgetItem;
         ui->treeWidgetCurBooks->addTopLevelItem(itemL);
         itemL->setHidden(true);
                 indexGroup=curIndex;
}
//اعادة تسمية القسم
void DialogConfigBooks::on_toolButtonSectionAdd_clicked()
{
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));

        dff->setLabelText(trUtf8("ادخل اسما للقسم الجديدة"));
        dff->setWindowTitle(trUtf8("قسم جديد"));
dff->setTextValue(trUtf8("قسم جديد"));

    QString text;
    if (dff->exec()==QInputDialog::Accepted )
    {

        text=dff->textValue();
        if (text.isEmpty()){ return;}
        //***********
          QIcon icon(":/images/image/groupb.png");
           QTreeWidgetItem *itemNew=new QTreeWidgetItem;

        itemNew->setText(0,text);
        itemNew->setIcon(0,icon);
        ui->comboBoxSection->addItem(icon,text);
        ui->treeWidgetBooks->addTopLevelItem(itemNew);
    }
}
//اغادة تسمية المجموعة
void DialogConfigBooks::on_toolButtonGroupAdd_clicked()
{
    if(ui->comboBoxSection->currentIndex()<0)return;
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));

        dff->setLabelText(trUtf8("ادخل اسما للمجموعة الجديدة"));
        dff->setWindowTitle(trUtf8("مجموعة جديدة"));
dff->setTextValue(trUtf8("مجموعة جديدة"));

    QString text;
    if (dff->exec()==QInputDialog::Accepted )
    {

        text=dff->textValue();
  if (text.isEmpty()){ return;}
        //***********
      QIcon icon(":/images/image/groupb.png");
           QTreeWidgetItem *itemNew=new QTreeWidgetItem;
    QTreeWidgetItem *itembk=new QTreeWidgetItem;
    QVariant newId;
    newId=Messages->genirateId(ui->treeWidgetBooks);
qDebug()<<newId;
    itemNew->setText(0,text);
        itemNew->setIcon(0,icon);
           itemNew->setData(2,1,newId.toString());
itembk->setText(0,text);
   itembk->setData(2,1,newId.toString());
        itembk->setIcon(0,icon);
   int index=ui->comboBoxSection->currentIndex();
        ui->treeWidgetBooks->topLevelItem(index)->addChild(itemNew);

         ui->treeWidgetCurGroup->addTopLevelItem(itembk);
    }
}

void DialogConfigBooks::on_toolButtonGrouprename_clicked()
{
    QTreeWidgetItem *item=ui->treeWidgetCurGroup->currentItem();
    int index=ui->comboBoxSection->currentIndex();
    QTreeWidgetItem *item2=  ui->treeWidgetBooks->topLevelItem(index)->child(indexGroup);
    if(!item){ return;}
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("ادخل اسما جديدا"));
    dff->setWindowTitle(trUtf8("اعادة تسمية العنصر"));
    dff->setTextValue(item->text(0));
    if (dff->exec()==QInputDialog::Accepted ){
        QString  newtext = dff->textValue();
        if (newtext.isEmpty()){ return;}
        item->setText(0,newtext);
          item2->setText(0,newtext);
    }
}

void DialogConfigBooks::on_toolButtonSectionRname_clicked()
{

    int index=ui->comboBoxSection->currentIndex();
    QTreeWidgetItem *item=  ui->treeWidgetBooks->topLevelItem(index);
    if(!item) return;
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("ادخل اسما جديدا"));
    dff->setWindowTitle(trUtf8("اعادة تسمية القسم"));
    dff->setTextValue(ui->comboBoxSection->currentText());
    if (dff->exec()==QInputDialog::Accepted ){
        QString  newtext = dff->textValue();
        if (newtext.isEmpty()){ return;}
        item->setText(0,newtext);
    ui->comboBoxSection->setItemText(index,newtext);
    }
}



//حذف قسم
void DialogConfigBooks::on_toolButtonSectionRemove_clicked()
{
    int index=ui->comboBoxSection->currentIndex();
     QTreeWidgetItem *item=  ui->treeWidgetBooks->topLevelItem(index);
     if (item->childCount()>0){
         int reponse = QMessageBox::warning(this, trUtf8("معلومات"), trUtf8("القسم يحتوي على عناصر وكتب  تحته \n هل تريد بالفعل حذف القسم المحدد؟") , QMessageBox::Yes | QMessageBox::No);
         if (reponse == QMessageBox::Yes){
           ui->comboBoxSection->removeItem(index);
           ui->treeWidgetBooks->takeTopLevelItem(index);
           ui->treeWidgetCurGroup->clear();
           ui->treeWidgetCurBooks->clear();
         }
     }else{
         int reponse = QMessageBox::question(this, trUtf8("معلومات"), trUtf8("هل تريد بالفعل حذف القسم المحدد؟") , QMessageBox::Yes | QMessageBox::No);
         if (reponse == QMessageBox::Yes){
           ui->comboBoxSection->removeItem(index);
           ui->treeWidgetBooks->takeTopLevelItem(index);
           ui->treeWidgetCurGroup->clear();
           ui->treeWidgetCurBooks->clear();
     }
}

}
//حذف مجموعة
void DialogConfigBooks::on_toolButtonGroupRemove_clicked()
{
    int index=ui->comboBoxSection->currentIndex();
    QTreeWidgetItem *item2=  ui->treeWidgetCurGroup->currentItem();
int curIndex=ui->treeWidgetCurGroup->indexOfTopLevelItem(item2);
qDebug()<<curIndex;
    QTreeWidgetItem *item=  ui->treeWidgetBooks->topLevelItem(index)->child(curIndex);
    if (!item)return;
    if (!item2)return;
    if (item->childCount()>0){
        int reponse = QMessageBox::warning(this, trUtf8("معلومات"), trUtf8("المجموعة تحتوي على عناصر وكتب  تحتها  \n سيتم حذف الكتب من الجهاز نهائيا \n هل تريد بالفعل حذف المجموعة المحددة؟") , QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes){
     curIndex=     ui->treeWidgetCurGroup->currentIndex().row();
                if (curIndex==-1)return;
     int count= ui->treeWidgetCurBooks->topLevelItemCount();
                 for(int i=0;i<count;i++){  //الحف من الجهاز
                     QTreeWidgetItem *item=ui->treeWidgetCurBooks->topLevelItem(i);

                       QString BKname=item->data(1,1).toString();
                       qDebug()<<BKname;
                       QString    pathbook=pathCostm;
                       QDir dir(pathCostm+"/" +BKname);
                        qDebug()<<pathCostm+"/" +BKname;
                        if (dir.exists()){
                            dir.setFilter(QDir::Files | QDir::Hidden );
                            QFileInfoList list = dir.entryInfoList();
                            for (int i = 0; i < list.size(); ++i) {
                                QFileInfo fileInfo = list.at(i);
                                if(dir.remove(fileInfo.fileName())==false){
                                    qDebug()<<fileInfo.fileName();
                                }
                            }
                            QDir dirm(pathbook );
                            if(dirm.rmdir(BKname)==false){
                                qDebug()<<BKname;
                            }
                        }
             }

     ui->treeWidgetCurGroup->takeTopLevelItem(curIndex);
            ui->treeWidgetBooks->topLevelItem(index)->takeChild(curIndex);
                   ui->treeWidgetCurBooks->clear();
       //   on_comboBoxSection_activated(index);
        }
    }else{
        int reponse = QMessageBox::question(this, trUtf8("معلومات"), trUtf8("هل تريد بالفعل حذف المجموعة المحددة؟") , QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes){
    if (indexGroup==-1)return;
            ui->treeWidgetBooks->topLevelItem(index)->takeChild(indexGroup);
            qDebug()<<"BKname"<<indexGroup;
            ui->treeWidgetCurGroup->takeTopLevelItem(indexGroup);

            ui->treeWidgetCurBooks->clear();
        }
    }
}

//حذف كتب
void DialogConfigBooks::on_toolButtonRemoveBooks_clicked()
{
    //نسخ العناصر المحددة الى قائمة
    QList<QTreeWidgetItem *> items;
    items.append(ui->treeWidgetCurBooks->selectedItems());
    //معرفة موقع المجموعة من الشجرة الاصلية
    if (items.count()==0)return;
        int reponse = QMessageBox::warning(this, trUtf8("معلومات"), trUtf8(" هل تريد بالفعل حذف الكنب المحددة؟ \n سيتم حذفهم نهائيا من الجهاز") , QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::No){
            return;
        }

    int indexSection=ui->comboBoxSection->currentIndex();
    QTreeWidgetItem *itemGroup=ui->treeWidgetBooks->topLevelItem(indexSection)->child(indexGroup);
    //عدد العناصر
    int count=items.count();
    for(int i=0;i<count;i++){
        QTreeWidgetItem *item= items.at(i);
        int index=ui->treeWidgetCurBooks->indexOfTopLevelItem(item);
        ui->treeWidgetCurBooks->takeTopLevelItem(index);//مسح العنصر من المحدد
        itemGroup->takeChild(index);//مسح العنصر من الاصل
      //الحف من الجهاز
        QString BKname=item->data(1,1).toString();
        qDebug()<<BKname;
        QString    pathbook=pathCostm;
        QDir dir(pathCostm+"/" +BKname);
         qDebug()<<pathCostm+"/" +BKname;
        if (dir.exists()){


        dir.setFilter(QDir::Files | QDir::Hidden );
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if(dir.remove(fileInfo.fileName())==false){
               qDebug()<<fileInfo.fileName();
            }
        }
        QDir dirm(pathbook );
        if(dirm.rmdir(BKname)==false){
             qDebug()<<BKname;
       }
        }
}
}

void DialogConfigBooks::on_pushButtonImg_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), trUtf8("ملفات الصور (*.png *.jpg);;كل الملفات (*)"));
    if (!fn.isEmpty())
    {
        ui->pushButtonImg->setIcon(QIcon(fn));
        imgChanged=true;
        //okEnabled();
    }
}
//تحديد كتاب لتحريره
void DialogConfigBooks::on_treeWidgetBooks_itemSelectionChanged()
{
    QTreeWidgetItem *item=ui->treeWidgetBooks->currentItem();
    if(!item)
        return;
    if (!item->data(1,1).isNull()){
        ui->lineEditBooknam->setText(item->text(0));
        ui->lineEditAautor->setText(item->text(1));
        ui->textBrowserBetaka->setText(item->text(2));
        ui->lineEditBkPath->setText(item->data(1,1).toString());
        ui->toolButtonUpdatBk->setEnabled(true);
        ui->pushButtonImg->setEnabled(true);

    }else{
        ui->lineEditBooknam->setText("");
        ui->lineEditAautor->setText("");
        ui->textBrowserBetaka->setText("");
        ui->lineEditBkPath->setText("");
         ui->toolButtonUpdatBk->setEnabled(false);
         ui->pushButtonImg->setEnabled(false);
    }
 imgChanged=false;
}
//حفظ بيانات الكتاب
void DialogConfigBooks::on_toolButtonUpdatBk_clicked()
{
    QTreeWidgetItem *item=ui->treeWidgetBooks->currentItem();
    if(!item)
        return;
    if (!item->data(1,1).isNull()){
        QString title=ui->lineEditBooknam->text();
        QString authur=ui->lineEditAautor->text();
        QString betaka= ui->textBrowserBetaka->toPlainText();
        QString BookName=item->data(1,1).toString();
         Messages->m_pathCostum= pathCostm;
        if( Messages->saveBookInfo(BookName,title,authur,betaka)==true)
        {
            item->setText(0, title);
            item->setText(1,authur );
            item->setText(2,betaka);
            if( imgChanged==true){
                QPixmap pix(ui->pushButtonImg->icon().pixmap(128,128));
                  QString imgScreenPath= pathCostm + "/" +BookName+"/screenshot.png";
                  pix.save(imgScreenPath,"PNG");
            }
        }

    }
}
void DialogConfigBooks::setPathCostum(QString path)
{
    pathCostm=path;
    ui->lineEditPath->setText(path);
}

void DialogConfigBooks::on_toolButtonOPenGroup_clicked()
{
    QFileDialog dlg;
QString homeDir=QDir::homePath () ;
    QString fn = dlg.getOpenFileName(0, tr("Open xml Files..."),
                                              homeDir   , trUtf8("ملف قائمة الكتب (group.xml );;xml (group.xml)"));
   qDebug()<<fn;
    if(!dlg.AcceptOpen)
     //   return;

    if (!fn.isEmpty())
    {

        QString groupPath=QDir::homePath()+"/.kirtasse/data/group.xml";
        QString groupPathNew=QDir::homePath()+"/.kirtasse/data/group.xml.old";
        QFile file;
        if(file.exists(groupPathNew))
            file.remove(groupPathNew);

        if(file.rename(groupPath,groupPathNew)) {
            if(file.copy(fn,groupPath)){
                Messages->treeChargeGroupe( ui->treeWidgetBooks,0,true);
                     ui->lineEditGroup->setText(fn);
                     ui->toolButtonGroupUpdat->setEnabled(true);
            }
        }
        if(ui->treeWidgetBooks->topLevelItemCount()<1)
           on_toolButtonGroupUpdat_clicked();
    }
}

void DialogConfigBooks::on_toolButtonGroupUpdat_clicked()
{
    QString groupPath=QDir::homePath()+"/.kirtasse/data/group.xml";
    QString groupPathOld=QDir::homePath()+"/.kirtasse/data/group.xml.old";
    QFile file;
    if(file.exists(groupPathOld)){
        if(file.exists(groupPath))
            file.remove(groupPath);

        file.rename(groupPathOld,groupPath);
            Messages->treeChargeGroupe( ui->treeWidgetBooks,0,true);
               ui->lineEditGroup->setText(groupPath);
    }else{
        QDir appDir(QCoreApplication::applicationDirPath() );
        appDir.cdUp();
        QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
          file.copy(pathApp+"/data/group.xml",groupPath);
    }
ui->toolButtonGroupUpdat->setEnabled(false);
}

void DialogConfigBooks::on_toolButtonBkPath_clicked()
{
     QFileDialog dlg;

    QString dir = dlg.getExistingDirectory(this, tr("Open Directory"),
                                                    ui->lineEditPath->text(),
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
<<<<<<< HEAD
    if(!dir.isEmpty()){
=======
    if(dlg.AcceptOpen){
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
     setPathCostum(dir);
    }
}

void DialogConfigBooks::on_toolButtonRenBkPath_clicked()
{
   QTreeWidgetItem *item=ui->treeWidgetBooks->currentItem();
    QString name=ui->lineEditBkPath->text();
    QString path=pathCostm + "/" + name;
    QFile file;

    QDir dir(path);
    QInputDialog *dff=new QInputDialog(this);
    dff->setOkButtonText(trUtf8("موافق"));
//    dff->setLayoutDirection(Qt::RightToLeft);
    dff->setCancelButtonText(trUtf8("الغاء"));
    dff->setLabelText(trUtf8("الاسم القديم : ")+name+"\n"+trUtf8("يحبذ ان لا يحتوي الاسم على فراغات"));
    dff->setWindowTitle(trUtf8("اعادة تسمية دليل الكتاب"));
    dff->setTextValue(ui->lineEditBooknam->text().replace(" ","_"));
    if (dff->exec()==QInputDialog::Accepted ){
        if (dff->textValue().isEmpty()){
            return;
        }
        QString newName=dff->textValue().replace("|",QString::Null());
        if(file.exists(pathCostm + "/" +newName)){
            QMessageBox::critical(this,trUtf8("خطأ"),trUtf8("يوجد مجلد بنفس الاسم"));
            return;
        }

            item->setData(1,1,newName);
         ui->lineEditBkPath->setText(newName);
         listRenameBk.append(name+"|"+newName);

}

}



void DialogConfigBooks::on_buttonBox_accepted()
{

    QDir dir(pathCostm);
  if (Messages->treeSaveGroupe(ui->treeWidgetBooks)==true){
   int count=listRenameBk.count();
      if (count>0){
          for(int i=0;i<count;i++){
            QString line=  listRenameBk.at(i);
            QString oldName=line.section("|",0,0);
             QString newName=line.section("|",1,1);
              dir.rename(oldName,newName);
              qDebug()<<line;
          }
      }
  }
}

void DialogConfigBooks::on_toolButtonFindBKOld_clicked()
{
    QFileDialog dlg;

   QString dir = dlg.getExistingDirectory(0, tr("Open Directory"),
                                                   ui->lineEditPath->text(),
                                                   QFileDialog::ShowDirsOnly
                                                   |QFileDialog::DontResolveSymlinks);
   if(dir.isEmpty())return;


    QString newBkPath=dir;
    qDebug()<<newBkPath;
    //انشاء قائمة فارغة اصلية
    QString groupPath=QDir::homePath()+"/.kirtasse/data/group.xml";
    QString groupPathOld=QDir::homePath()+"/.kirtasse/data/group.xml.old";
    QFile file;
    if(file.exists(groupPathOld))
                 file.remove(groupPathOld);
//حفظ الحالية لاسترجاعها فيما بعد عند الضرورة
        file.rename(groupPath,groupPathOld);
//نسخ الاصلية الى دليل المنزل
        QDir appDir(QCoreApplication::applicationDirPath() );
        appDir.cdUp();
        QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
          file.copy(pathApp+"/data/group.xml",groupPath);
//تحميل القائمة الى الشجرة
            Messages->treeChargeGroupe( ui->treeWidgetBooks,0,true);
 //اضافة قسم جديد فارغ
            QIcon icon(":/images/image/groupb.png");
             QTreeWidgetItem *sectionNew=new QTreeWidgetItem;
             sectionNew->setText(0,trUtf8("قسم غير مصنف"));
            sectionNew->setIcon(0,icon);
           ui->treeWidgetBooks->addTopLevelItem(sectionNew);
   //اضافة مجموعة جديدة فارغة
           QTreeWidgetItem *groupNew=new QTreeWidgetItem;
           groupNew->setText(0,trUtf8("مجموعة غير مصنفة"));
          groupNew->setIcon(0,icon);
       QVariant   newId=Messages->genirateId(ui->treeWidgetBooks);
          groupNew->setData(2,1,newId.toString());
         sectionNew->addChild(groupNew);

         //الدخول الى الديل المشار اليه
       QString subdir;
         QDir dirImage(newBkPath);
         foreach ( subdir, dirImage.entryList(QDir::AllDirs | QDir::NoDotAndDotDot |
                                         QDir::Hidden )){
                         if(file.exists(newBkPath+"/"+subdir+"/bookinfo.info")){
                 Messages->loadBookInfo(newBkPath+"/"+subdir);
                     QString title=Messages->infoBookTitle;
                QString author=Messages->infoBookAutor;
              QString bitka=Messages->infoBookBetaka;
                   QTreeWidgetItem *item=new QTreeWidgetItem;
                   item->setText(0,title);
                   item->setText(1,author);
                    item->setText(2,bitka);
                   item->setData(1,1,subdir);
                 addbook(groupNew,item,subdir);
             }
     //            qDebug()<< newBkPath+"/"+subdir+"/bookinfo.info";

         }
         pathCostmOld=pathCostm;
     setPathCostum(dir);
 ui->toolButtonReloadAll->setEnabled(true);
}

void DialogConfigBooks::addbook(QTreeWidgetItem *itemNew,QTreeWidgetItem *item,QString name)
{
    bool exist=false;
    QString idName=name.section("_",0,0);
    idName.replace("bk",QString::Null());

    int topCount=ui->treeWidgetBooks->topLevelItemCount();
    for(int i=0;i<topCount;i++){ //section
        int count=ui->treeWidgetBooks->topLevelItem(i)->childCount();
        for(int r=0;r<count;r++){//groups
            QTreeWidgetItem *itemGroup=ui->treeWidgetBooks->topLevelItem(i)->child(r);
            QString id=itemGroup->data(2,1).toString();
            if(idName.trimmed()==id.trimmed()){
           itemGroup->addChild(item);
            exist=true;
            }
        }
    }
    if(exist==false)
     itemNew->addChild(item);
}


void DialogConfigBooks::on_treeWidgetCurGroup_itemActivated(QTreeWidgetItem , int )
{
    on_treeWidgetCurGroup_itemSelectionChanged();
}

void DialogConfigBooks::on_treeWidgetCurGroup_itemClicked(QTreeWidgetItem , int )
{
    on_treeWidgetCurGroup_itemSelectionChanged();
}

void DialogConfigBooks::on_toolButtonReloadAll_clicked()
{
    on_toolButtonGroupUpdat_clicked();
    setPathCostum(pathCostmOld);
     Messages->treeChargeGroupe( ui->treeWidgetBooks,0,true);
     ui->toolButtonReloadAll->setEnabled(false);
}
