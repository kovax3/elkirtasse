#include "dialogactions.h"
#include "ui_dialogactions.h"
#include <QDebug>

DialogActions::DialogActions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogActions)
{
    ui->setupUi(this);
    if(this->layoutDirection()==Qt::RightToLeft){
        ui->toolButtonRemove->setArrowType(Qt::RightArrow);
   ui->toolButtonAdd->setArrowType(Qt::LeftArrow);


    }
}

DialogActions::~DialogActions()
{
    delete ui;
}


void DialogActions::on_toolButtonAdd_clicked()
{
    QTreeWidgetItem *curItem=ui->treeWidgetOrig->currentItem();
      QTreeWidgetItem *curItemDest=ui->treeWidgetDest->currentItem();
    if(!curItem)return;

    QTreeWidgetItem *item=new QTreeWidgetItem;
    item=curItem->clone();
      if(curItemDest){
           ui->treeWidgetDest->insertTopLevelItem( ui->treeWidgetDest->indexOfTopLevelItem(curItemDest)+1,item);
      }else{
            ui->treeWidgetDest->addTopLevelItem(item);
      }
  ui->treeWidgetDest->setCurrentItem(item);
    if(curItem->data(1,1).toInt()==1000){

    return;
    }

    int index= ui->treeWidgetOrig->indexOfTopLevelItem(curItem);
    ui->treeWidgetOrig->takeTopLevelItem(index);

}

void DialogActions::on_toolButtonRemove_clicked()
{
    QTreeWidgetItem *curItem=ui->treeWidgetDest->currentItem();
    if(!curItem)return;
     int index= ui->treeWidgetDest->indexOfTopLevelItem(curItem);
    if(curItem->data(1,1).toInt()==1000){
        ui->treeWidgetDest->takeTopLevelItem(index);

    return;
    }

    QTreeWidgetItem *item=new QTreeWidgetItem;
    item=curItem->clone();
    ui->treeWidgetOrig->addTopLevelItem(item);

    ui->treeWidgetDest->takeTopLevelItem(index);
}

void DialogActions::on_buttonBox_accepted()
{
    for(int i=0;i<ui->treeWidgetDest->topLevelItemCount();i++){

        listActToAdd.append(ui->treeWidgetDest->topLevelItem(i)->data(1,1));
    }
}

void DialogActions::setListActions(QList<QAction *>*listActions,QList<QVariant >listToAdd)
{



    QTreeWidgetItem *itemSep=new QTreeWidgetItem;
    itemSep->setText(0,trUtf8("ـــــــــ فاصل ـــــــــ"));
    itemSep->setData(1,1,1000);
    ui->treeWidgetOrig->addTopLevelItem(itemSep);


    for(int i=0;i<listActions->count();i++){
     //   qDebug()<<i<<  listActions->at(i)->objectName();


        if(!listToAdd.contains(i)){
            if(!listActions->at(i)->isSeparator()){
            QTreeWidgetItem *item=new QTreeWidgetItem;
            item->setText( 0,listActions->at(i)->text());
              item->setIcon(0,listActions->at(i)->icon());
              item->setData(1,1,i);
            ui->treeWidgetOrig->addTopLevelItem(item);
            }
        }

    }

  if(!listToAdd.contains(2000)){
      QTreeWidgetItem *item=new QTreeWidgetItem;
      item->setText( 0,trUtf8("ادوات البحث"));
       item->setIcon(0,QIcon(":/images/image/findbook.png"));
      item->setData(1,1,2000);
      ui->treeWidgetOrig->addTopLevelItem(item);
  }


    int count=  listToAdd.count();

    for(int i=0;i<count;i++){
         QTreeWidgetItem *item=new QTreeWidgetItem;

       int indx=listToAdd.at(i).toInt();
        if(indx==1000){
            item->setText(0,trUtf8("ـــــــــ فاصل ـــــــــ"));
              item->setData(1,1,1000);
        }else if (indx==2000){
         item->setText( 0,trUtf8("ادوات البحث"));
          item->setIcon(0,QIcon(":/images/image/findbook.png"));
         item->setData(1,1,2000);
        }else{
         item->setText( 0,listActions->at(indx)->text());
          item->setIcon(0,listActions->at(indx)->icon());
         item->setData(1,1,indx);
        }
          ui->treeWidgetDest->addTopLevelItem(item);
    }


}

void DialogActions::on_treeWidgetDest_itemSelectionChanged()
{
    QTreeWidgetItem *item=ui->treeWidgetDest->currentItem();
    if(item){
        ui->toolButtonRemove->setEnabled(true);
        ui->toolButtonDown->setEnabled(true);
        ui->toolButtonUp->setEnabled(true);
    }else{
          ui->toolButtonRemove->setEnabled(false);
          ui->toolButtonDown->setEnabled(false);
          ui->toolButtonUp->setEnabled(false);
    }
}

void DialogActions::on_treeWidgetOrig_itemSelectionChanged()
{
    QTreeWidgetItem *item=ui->treeWidgetOrig->currentItem();
    if(item){
        ui->toolButtonAdd->setEnabled(true);
           }else{
          ui->toolButtonAdd->setEnabled(false);

    }
}

void DialogActions::on_toolButtonUp_clicked()
{
    QTreeWidgetItem *curItem=ui->treeWidgetDest->currentItem();
    if(!curItem)return;

      int index= ui->treeWidgetDest->indexOfTopLevelItem(curItem);
      if(index==0)return;
      QTreeWidgetItem *item=new QTreeWidgetItem;
      item=curItem->clone();

   ui->treeWidgetDest->takeTopLevelItem(index);
    ui->treeWidgetDest->insertTopLevelItem(index-1,item);
    ui->treeWidgetDest->setCurrentItem(item);
}

void DialogActions::on_toolButtonDown_clicked()
{
    QTreeWidgetItem *curItem=ui->treeWidgetDest->currentItem();
    if(!curItem)return;

      int index= ui->treeWidgetDest->indexOfTopLevelItem(curItem);
      if(index== ui->treeWidgetDest->topLevelItemCount()-1)return;
      QTreeWidgetItem *item=new QTreeWidgetItem;
      item=curItem->clone();

   ui->treeWidgetDest->takeTopLevelItem(index);
    ui->treeWidgetDest->insertTopLevelItem(index+1,item);
    ui->treeWidgetDest->setCurrentItem(item);
}
