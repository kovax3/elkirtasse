/****************************************************************************
**
** ---------------------
** All rights reserved.
** Contact: abouzakaria (yahia67@live.com)
**
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
** If you have questions regarding the use of this file, please contact
** abouzakaria (yahia67@live.com)
** $elkirtasse_END_LICENSE$
**
****************************************************************************/


#include "animation.h"
View::View()
{

    mscene=new QGraphicsScene(QRectF (0,0,200,400));
    this->setScene(mscene);
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(time_run()));
}
View::~View()
{

}
void View::chargePixmap()
{

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(time_run()));
    mscene=new QGraphicsScene(QRectF (0,0,400,400));
    this->setScene(mscene);
    // threeD=false;

}

void View::chargeLevelOne()
{
    isBook=false;
    if (threeD==false){
        mscene->setBackgroundBrush(Qt::NoBrush);
        isThreeD=false;
        animChargePixmape(1,0,0);
    }else{
        isThreeD=true;
        ThreeDChargePixmape(1,0,0);
    }

}

void View::animChargeLevelTow()
{
    isBook=true;
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    int index=currentItem->data(0).toInt();
    int indexParent=currentItem->data(1).toInt();


    if (threeD==false){
        mscene->setBackgroundBrush(Qt::NoBrush);
        isThreeD=false;
        animChargePixmape(2,index,indexParent);
    }else{

        isThreeD=true;
        ThreeDChargePixmape(2,index,indexParent);

    }
    label->setText(currentItem->toolTip());
}

void View::threedChargeLevelTow()
{
    isBook=true;
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    int index=currentItem->data(0).toInt();
    int indexParent=currentItem->data(1).toInt();

    int i=  items.indexOf(currentItem);
    if (threeD==false){
        label->setText(currentItem->toolTip());

        animChargePixmape(2,index,indexParent);
    }else{
        if(i>itemCurant)
        {
            moveThreeD(false);
        }else if(i<itemCurant){
            moveThreeD(true);
        }else{
            label->setText(currentItem->toolTip());

            ThreeDChargePixmape(2,index,indexParent);
        }
    }

}

void View::animChargePixmape(int level,int index,int indexParent)
{

    for (int i = 0; i <items.count(); ++i) {
        mscene->removeItem(items.at(i));
    }
    items.clear();
    mscene->clear();

    QPainter p;

    if(level==1){

        label->setText(trUtf8("قائمة المجموعات"));

        int topItemCount=treeView->topLevelItemCount();
        int itemCount=0;
        for (int i=0;i<topItemCount;i++){
            itemCount=itemCount+  treeView->topLevelItem(i)->childCount();
        }
        int rew=(itemCount/7)+1;
        int h=rew*128;
        mscene->setSceneRect(0,0,896,h+30);

        for (int i = 0; i <topItemCount; ++i) {
            int nbr=treeView->topLevelItem(i)->childCount();
            for (int r=0;r<nbr;r++){
                QTreeWidgetItem *osloItem=treeView->topLevelItem(i)->child(r);
                QPixmap   pixmapG(":/images/image/group2.png") ;
                QPixmap pixgren(":/images/image/mask.png");
                QPixmap   mypixmap(128,128);
                mypixmap.fill(Qt::transparent);
                p.begin(&mypixmap);
                p.drawPixmap(0,0,128,187,pixmapG);
                p.setFont(QFont("Arial", 14));
                p.drawText(8,8,112,52, Qt::AlignCenter | Qt::TextWordWrap, osloItem->text(0));
                p.drawPixmap(7,7,116,56,pixgren);
                p.end();
                Pixmap *item = new Pixmap(mypixmap);
                items << item;
                //
                item->setGeometry( QRectF(0, 0, 128.0, 128.0));
                mscene->addItem(item);
                item->setFlag(QGraphicsItem::ItemIsFocusable);
                item->setToolTip( osloItem->text(0));
                item->setCursor(Qt::PointingHandCursor);
                item->setData(0,r);
                item->setData(1,i);
                connect(item, SIGNAL(release()), this, SLOT(animChargeLevelTow()));
                connect(item, SIGNAL(enter()), this, SLOT(animEnterItem()));
                connect(item, SIGNAL(leave()), this, SLOT(animLeaveItem()));
            }
        }
    }else if (level==2){

        this->setAlignment(Qt::AlignTop|Qt::AlignHCenter);
        int nbr= treeView->topLevelItem(indexParent)->child(index)->childCount();
        int rew=(nbr/7)+1;
        int h=rew*128;
        mscene->setSceneRect(0,0,896,h+30);
#if QT_VERSION >= 0x040600



#endif
        for (int i=0;i<nbr;i++){
            QTreeWidgetItem *osloItem=treeView->topLevelItem(indexParent)->child(index)->child(i);
            QPixmap   mypixmap(QPixmap(":/images/image/bkg.png")) ;

            p.begin(&mypixmap);

            p.setPen(Qt::white);
            p.setFont(QFont("Arial", 14));
            p.drawText(5,15,100,100, Qt::AlignCenter | Qt::TextWordWrap, osloItem->text(0));
            p.end();


            Pixmap *item = new Pixmap(mypixmap);

            items << item;

            item->setGeometry(
                    QRectF(0,
                           0,128.0, 128.0));


            mscene->addItem(item);
            item->setToolTip( osloItem->text(0));
            item->setCursor(Qt::PointingHandCursor);
            item->setData(0,osloItem->data(1,1));
            item->setData(1,"0");
            item->setData(2,osloItem->text(1));


            connect(item, SIGNAL(release()), this, SLOT(animItemOpenBook()));
            connect(item, SIGNAL(enter()), this, SLOT(animEnterItem()));
            connect(item, SIGNAL(leave()), this, SLOT(animLeaveItem()));
        }
    }

    // animCenter();
    animTeled();
    //        QTimer::singleShot(100 +  items.count() , this, SLOT(animTeled()));


}
void View::ThreeDChargePixmape(int level,int index,int indexParent)
{
    for (int i = 0; i <items.count(); ++i) {
        mscene->removeItem(items.at(i));
    }
    items.clear();
    mscene->clear();
    QPainter p;
    mscene->setSceneRect(0,0,500,500);
    QLinearGradient gradient(0, 0, 0, 500);
    gradient.setColorAt(0.47, QColor::fromRgb(255,255,255,200));
    gradient.setColorAt(0.5, QColor::fromRgb(204, 204, 204, 200));
    gradient.setColorAt(0.55, QColor::fromRgb(204, 204, 204, 150));
    gradient.setColorAt(1, QColor::fromRgbF(1, 1, 1, 1));


    mscene->setBackgroundBrush(gradient);
    int leftCentre=(mscene->width()/2)-(128);
    int topCentre=(mscene->height()/2)-128;
    this->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    chargeMaskItem();
    //--------------------------------------
    if(level==1){

        label->setText(trUtf8("قائمة المجموعات"));
        int topItemCount=treeView->topLevelItemCount();
        int itemCount=0;
        for (int i=0;i<topItemCount;i++){
            itemCount=itemCount+  treeView->topLevelItem(i)->childCount();
        }

        for (int i = 0; i <topItemCount; ++i) {
            int nbr=treeView->topLevelItem(i)->childCount();
            for (int r=0;r<nbr;r++){
                QTreeWidgetItem *osloItem=treeView->topLevelItem(i)->child(r);
                QPixmap   mypixmap(QPixmap(":/images/image/group2.png")) ;
                QPixmap pixgren(":/images/image/mask.png");
                p.begin(&mypixmap);
                p.setFont(QFont("Arial", 18));
                p.drawText(15,16,228,80, Qt::AlignCenter | Qt::TextWordWrap, osloItem->text(0));
                QVariant chd= osloItem->childCount();
                p.setFont(QFont("Arial", 10));
                p.drawText(15,85,228,20, Qt::AlignCenter | Qt::TextWordWrap,chd.toString()+trUtf8(":عدد الكتب "));
                p.drawPixmap(14,15,231,112,pixgren);
                p.end();
                Pixmap *item = new Pixmap(mypixmap);
                //                 QGraphicsColorizeEffect *efet=new QGraphicsColorizeEffect;
                //                efet->setColor(QColor(0, 0, 255, 50));
                //                 item->setGraphicsEffect(efet);
                item->setOpacity(0);
                items << item;
                mscene->addItem(item);
                item->setGeometry(QRectF(leftCentre,topCentre,256,374));

                item->setToolTip(osloItem->text(0));
                item->setCursor(Qt::PointingHandCursor);
                item->setData(0,r);
                item->setData(1,i);
                connect(item, SIGNAL(release()), this, SLOT(threedChargeLevelTow()));
                //                connect(item, SIGNAL(enter()), this, SLOT(ThreeDEnterItem()));
                //                connect(item, SIGNAL(leave()), this, SLOT(ThreeDLeaveItem()));
            }
        }
        //--------------------------------------------------------
    }else if (level==2){

        int nbr= treeView->topLevelItem(indexParent)->child(index)->childCount();

        for (int i=0;i<nbr;i++){
            QTreeWidgetItem *osloItem=treeView->topLevelItem(indexParent)->child(index)->child(i);
            QPixmap   mypixmap(QPixmap(":/images/image/groupbak.png")) ;
            QPixmap pixgren(":/images/image/Green.png");
            p.begin(&mypixmap);
            // p.setPen(Qt::white);
            p.setFont(QFont("Arial", 14));
            p.drawText(24,18,190,100, Qt::AlignCenter | Qt::TextWordWrap, osloItem->text(0));
            p.setFont(QFont("Arial", 10));
            p.drawText(24,100,190,178, Qt::AlignTop| Qt::AlignHCenter | Qt::TextWordWrap, osloItem->text(2));

            p.drawPixmap(0,0,256,374,pixgren);
            p.end();
            Pixmap *item = new Pixmap(mypixmap);
            item->setOpacity(0);
            items << item;
            mscene->addItem(item);
            item->setGeometry(QRectF(leftCentre,topCentre,256,374));
            item->setToolTip( osloItem->text(0));
            item->setCursor(Qt::PointingHandCursor);
            item->setData(0,osloItem->data(1,1));
            item->setData(1,"0");
            item->setData(2,osloItem->text(1));
            connect(item, SIGNAL(release()), this, SLOT(ThreeDItemOpenBook()));
            //            connect(item, SIGNAL(enter()), this, SLOT(ThreeDEnterItem()));
            //            connect(item, SIGNAL(leave()), this, SLOT(ThreeDLeaveItem()));
        }
    }
    chargeMaskItem();
    chargeNavigator();
    itemCurant=(items.count()/2)-1;
    moveThreeD(false);
}


void View::animTeled()
{
#if QT_VERSION >= 0x040600
    int rnd=9;
    int rndX=rand() % ++rnd;
    int rndY=rand() % ++rnd;
    int ind=41;
    int index=rand() % ++ind;
    if (index<20){
        index=index+20;
    }
    curveType = (QEasingCurve::Type)index;
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    QPropertyAnimation *anim ;
    for (int i = 0; i < items.count(); ++i) {
        anim = new QPropertyAnimation(items[i], "pos");
        anim->setDuration(550 + i * 25);
        anim->setEasingCurve(curveType);
        group->addAnimation(anim);
        anim->setStartValue( QPointF(cos((i / 63.0) * rndX) * this->width()/2,
                                     sin((i / 63.0) *  rndY) * this->height()/2));
        anim->setEndValue( QPointF(((i % 7)) * 128,
                                   ((i / 7)) * 128+20));
    }
    group->start();
    itemCurant=0;
#else
    for (int i = 0; i < items.count(); ++i) {
        items[i]->setPos( QPointF(((i % 7)) * 128,
                                  ((i / 7)) * 128+20));

    }
#endif
}

void View::moveThreeD(bool right)
{
#if QT_VERSION >= 0x040600
    if (right==true){
        itemCurant=itemCurant-1;
        if(itemCurant-2<=0){
            itemCurant=3;
            return;
        }
    }else{
        itemCurant=itemCurant+1;
        if(itemCurant+3>=items.count()){
            itemCurant=items.count()-3;
            return;
        }
    }
    int leftCentre=(mscene->width()/2)-(128);
    int topCentre=(mscene->height()/2)-185;

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    QPropertyAnimation *anim=new QPropertyAnimation ;
    QPropertyAnimation *anim1=new QPropertyAnimation ;

    //------------------------------------------------------
    for (int i = 0; i<7; ++i) {
        int d=i-3;
        items[itemCurant+d]->setOpacity(100);
        float f=d;
        if (f<0){f=-f;}
        float percent=1-(f/4);
        if (percent==0){percent=1;}

        anim = new QPropertyAnimation(items[itemCurant+d], "scale");
        anim1 = new QPropertyAnimation(items[itemCurant+d], "pos");

        int s=(d*20);

        int posLleft=(128*d);
        if (d<0){d=-d; s=(20*d*d);}

        anim->setEndValue(percent);
        anim1->setEndValue(QPointF(leftCentre+(posLleft+s),topCentre+(d*30)));
        items[itemCurant+d]->setZValue(items.count()-d);
        anim->setDuration(500);
        anim1->setDuration(500);
        anim->setEasingCurve(QEasingCurve::OutBack);
        anim1->setEasingCurve(QEasingCurve::OutBack);
        group->addAnimation(anim);
        group->addAnimation(anim1);

    }
    //--------------------------------------------------------

    QPropertyAnimation *anim2=new QPropertyAnimation ;
    if (right==true){
        items[itemCurant-3]->setOpacity(0);
        if (itemCurant<items.count()-6){
            anim2 = new QPropertyAnimation(items[itemCurant+3], "opacity");

        }
    }else{
        items[itemCurant+3]->setOpacity(0);
        if (itemCurant>4){
            anim2 = new QPropertyAnimation(items[itemCurant-3], "opacity");
        }
    }
   anim2->setDuration(150);
    anim2->setEndValue(0);
    group->addAnimation(anim2);
    group->start();

#endif

}
void View::moveThreeDright()
{
    m_right=true;
    moveThreeD(true);
    m_timer->start(250);
}
void View::moveThreeDleft()
{
    m_right=false;
    moveThreeD(false);
    m_timer->start(250);

}

void View::animEnterItem()
{
    Pixmap *currentItem = qobject_cast<Pixmap *>(sender());
    //  currentItem->setGeometry(QRect(currentItem->pos().x()-5, currentItem->pos().y()-5, 138, 138));
    currentItem->setTransform(QTransform().translate(0,0).scale(1.07,1.07).translate(-4,-4));
}
void View::animLeaveItem()
{
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    // currentItem->setGeometry(QRect(currentItem->pos().x()+5, currentItem->pos().y()+5, 128, 128));
    currentItem->setTransform(QTransform().translate(0,0).scale(1,1).translate(0, 0));
}

void View::time_run()
{

    if ( m_right==false){
        moveThreeD(false);
    }else{
        moveThreeD(true);
    }
}
void View::stop_time()
{
    m_timer->stop();
}

void View::ThreeDItemOpenBook()
{
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    int i=  items.indexOf(currentItem);
    if(i>itemCurant)
    {
        moveThreeD(false);
    }else if(i<itemCurant){
        moveThreeD(true);
    }else{
        if (!currentItem->data(0).isNull()){
            lineEdit->setText( currentItem->data(0).toString()+"/"+ currentItem->toolTip()+"/"+currentItem->data(2).toString()+"/"+"0");
        }
    }

}
void View::animItemOpenBook()
{
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    if (!currentItem->data(0).isNull()){
        lineEdit->setText( currentItem->data(0).toString()+"/"+ currentItem->toolTip()+"/"+currentItem->data(2).toString()+"/"+"0");
    }
}

void View::chargeRecent()
{
    isBook=true;
    this->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    for (int i = 0; i <items.count(); ++i) {
        mscene->removeItem(items.at(i));
    }
    items.clear();
    mscene->clear();
    QPainter p;

    label->setText(trUtf8("قائمة الكتب السابقة"));
    if (threeD==false){
        isThreeD=false;
        int rew=(recentNbr/7)+1;
        int h=rew*128;
        mscene->setSceneRect(0,0,896,h+30);
        mscene->setBackgroundBrush(Qt::NoBrush);
        for (int i=1;i<recentNbr;i++){
            QPixmap   mypixmap(QPixmap(":/images/image/bkg.png")) ;

            p.begin(&mypixmap);

            p.setPen(Qt::white);
            p.setFont(QFont("Arial", 14));
            p.drawText(5,15,100,100, Qt::AlignCenter | Qt::TextWordWrap, recentFileActs[i]->text());

            p.end();
            Pixmap *item = new Pixmap(mypixmap);
            items << item;

            item->setGeometry(
                    QRectF(0,
                           0,128.0, 128.0));
            mscene->addItem(item);
            item->setToolTip( recentFileActs[i]->text());
            item->setCursor(Qt::PointingHandCursor);
            QVariant comboR_data=recentFileActs[i]->data();
            QString myid = comboR_data.toString().section('/', 0, 0);
            QString myaut= comboR_data.toString().section('/', -1);
            QString  myname=comboR_data.toString().section('/', 1, 1);
            item->setData(0,myname);
            item->setData(1,myid);
            item->setData(2, myaut);
            connect(item, SIGNAL(release()), this, SLOT(comboItemOpenBook()));
            connect(item, SIGNAL(enter()), this, SLOT(animEnterItem()));
            connect(item, SIGNAL(leave()), this, SLOT(animLeaveItem()));
            animTeled();
        }

    }else{
        isThreeD=true;
        mscene->setSceneRect(0,0,500,500);
        QLinearGradient gradient(0, 0, 0, 500);
        gradient.setColorAt(0.47, QColor::fromRgb(255,255,255,200));
        gradient.setColorAt(0.5, QColor::fromRgb(204, 204, 204, 200));
        gradient.setColorAt(0.55, QColor::fromRgb(204, 204, 204, 150));
        gradient.setColorAt(1, QColor::fromRgbF(1, 1, 1, 1));

        mscene->setBackgroundBrush(gradient);
        int leftCentre=(mscene->width()/2)-(128);
        int topCentre=(mscene->height()/2)-128;
        this->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
        chargeMaskItem();
        //--------------------------------------
        for (int i=1;i<recentNbr;i++){
            QPixmap   mypixmap(QPixmap(":/images/image/groupbak.png")) ;
            QPixmap pixgren(":/images/image/Green.png");
            p.begin(&mypixmap);
            p.setFont(QFont("Arial", 18));
            p.drawText(24,18,190,178, Qt::AlignCenter | Qt::TextWordWrap,recentFileActs[i]->text());

            p.drawPixmap(0,0,256,374,pixgren);
            p.end();
            Pixmap *item = new Pixmap(mypixmap);
            item->setOpacity(0);
            items << item;
            mscene->addItem(item);
            item->setGeometry(QRectF(leftCentre,topCentre,256,374));
            item->setToolTip( recentFileActs[i]->text());
            item->setCursor(Qt::PointingHandCursor);
            QVariant comboR_data=recentFileActs[i]->data();
            QString myid = comboR_data.toString().section('/', 0, 0);
            QString myaut= comboR_data.toString().section('/', -1);
            QString  myname=comboR_data.toString().section('/', 1, 1);
            item->setData(0,myname);
            item->setData(1,myid);
            item->setData(2, myaut);
            connect(item, SIGNAL(release()), this, SLOT(ThreeDcomboItemOpenBook()));

        }
        chargeMaskItem();
        chargeNavigator();
        itemCurant=2;
        moveThreeD(false);
    }
}
void View::comboItemOpenBook()
{
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    if (!currentItem->data(0).isNull()){
        lineEdit->setText( currentItem->data(0).toString()+"/"+ currentItem->toolTip()+"/"+currentItem->data(2).toString()+"/"+currentItem->data(1).toString());
    }
}
void View::ThreeDcomboItemOpenBook()
{
    Pixmap *currentItem= qobject_cast<Pixmap *>(sender());
    int i=  items.indexOf(currentItem);
    if(i>itemCurant)
    {
        moveThreeD(false);
    }else if(i<itemCurant){
        moveThreeD(true);
    }else{
        if (!currentItem->data(0).isNull()){
            lineEdit->setText( currentItem->data(0).toString()+"/"+ currentItem->toolTip()+"/"+currentItem->data(2).toString()+"/"+currentItem->data(1).toString());
        }
    }

}
void View:: chargeNavigator()
{
    int leftCentre=(mscene->width()/2)-(128);
    int topCentre=(mscene->height()/2)-128;
    QPixmap   pixmapleft(":/images/image/left3d.png");
    QPixmap   pixmapright(":/images/image/right3d.png");
    Pixmap *left3d = new Pixmap(pixmapleft);
    Pixmap *right3d = new Pixmap(pixmapright);
    left3d->setGeometry(QRect(leftCentre-220,topCentre+86,48,48));
    right3d->setGeometry(QRect(leftCentre+420,topCentre+86,48,48));
    left3d->setCursor(Qt::PointingHandCursor);
    right3d->setCursor(Qt::PointingHandCursor);
    mscene->addItem(left3d);
    mscene->addItem(right3d);
    left3d->setZValue(items.count()+1);
    right3d->setZValue(items.count()+2);
    connect(left3d, SIGNAL(pressed()), this, SLOT(moveThreeDleft()));
    connect(left3d, SIGNAL(release()), this, SLOT(stop_time()));

    connect(right3d, SIGNAL(pressed()), this, SLOT(moveThreeDright()));
    connect(right3d, SIGNAL(release()), this, SLOT(stop_time()));
}
void View::chargeMaskItem()
{
    for (int i = 0; i <3; ++i) {
        QPixmap kineticPix(256,374);
        Pixmap *item = new Pixmap(kineticPix);
        item->setVisible(false);
        items << item;
        mscene->addItem(item);
    }
}
void  View::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()){
        return;
    }
    if (isThreeD==true){
        if (event->key() ==Qt::Key_Left){
            m_timer->stop();
            m_right=false;
            moveThreeD(false);
            m_timer->start(250);
        }
        if (event->key() == Qt::Key_Right){
            m_timer->stop();
            m_right=true;
            moveThreeD(true);
            m_timer->start(250);
        }
        if (event->key() ==Qt::Key_Enter){
            Pixmap *currentItem=items[itemCurant];
            if (!currentItem->data(0).isNull()){
                if(  isBook==true){
                    lineEdit->setText( currentItem->data(0).toString()+"/"+ currentItem->toolTip()+"/"+currentItem->data(2).toString()+"/"+currentItem->data(1).toString());
                }else{
                    int index=currentItem->data(0).toInt();
                    int indexParent=currentItem->data(1).toInt();
                    label->setText(currentItem->toolTip());
                    isBook=true;
                    ThreeDChargePixmape(2,index,indexParent);
                }


            }
        }
    }else{
        //        items[itemCurant]->setTransform(QTransform().translate(0,0).scale(1,1).translate(0, 0));
        //         if (event->key() == Qt::Key_Right ||event->key() == Qt::Key_Down ){
        //            itemCurant=itemCurant+1;
        //            if (itemCurant>items.count()){ itemCurant=items.count()-1; }
        //         }else if(event->key() == Qt::Key_Left ||event->key() == Qt::Key_Up){
        //             itemCurant=itemCurant-1;
        //             if (itemCurant<0){ itemCurant=0; }
        //        }
        //        items[itemCurant]->setTransform(QTransform().translate(0,0).scale(1.07,1.07).translate(-4,-4));
        //        items[itemCurant]->setFocus();
        //        items[itemCurant]->setActive(true);

    }

}
void View::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() ==Qt::Key_Left ||event->key() == Qt::Key_Right )
        m_timer->stop();
}

void View::chargeEnrto()
{
    for (int i = 0; i <items.count(); ++i) {
        mscene->removeItem(items.at(i));
    }
    items.clear();
    mscene->clear();
    this->setAlignment(Qt::AlignHCenter|Qt::AlignHCenter);
    mscene->setSceneRect(0,0,500,500);
    mscene->setBackgroundBrush(Qt::white);

    QLabel *labBasmala=new QLabel;
    QLabel *labHadith=new QLabel;
    labBasmala->setAlignment(Qt::AlignCenter);
    labBasmala->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    labBasmala->setGeometry(0,0,500,36);
    labBasmala->setText("<span style=\" font-family:'arial,KacstLetter,DejaVu Serif'; font-size:18pt; font-weight:600; color:#ff5500;\">"+trUtf8("بسم الله الرحمن الرحيم")+"</span>");

    QString text="<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,KacstLetter,DejaVu Serif'; font-size:16pt; color:#000000;\">"+trUtf8("أخرج البخاري في صحيحه")+"</span><span style=\" font-family:'KacstLetter'; font-size:10pt;\"> </span></p>"
                 "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,KacstLetter,DejaVu Serif'; font-size:16pt; color:#0000ff;\">"+trUtf8("في كتاب بدء الوحي")+"</span><span style=\" font-family:'KacstLetter'; font-size:16pt;\"> </span></p>"
                 "<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,KacstLetter,DejaVu Serif'; font-size:16pt; color:#008000;\">"+trUtf8("باب: كيف كان بدء الوحي")+"</span></p>"
                 "<p dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,KacstLetter,DejaVu Serif'; font-size:14pt; color:#000000;\">"
                 +trUtf8("حدثنا الحميدي عبد الله بن الزبير قال: حدثنا سفيان قال: حدثنا يحيى بن سعيد الأنصاري قال : أخبرني محمد بن إبراهيم التيمي: أنه سمع علقمة بن وقاص الليثي يقول: سمعت عمر بن الخطاب رضي الله عنه على المنبر قال: سمعت رسول الله صلى الله عليه وسلم يقول: إنما الأعمال بالنيات، وإنما لكل امرىء ما نوى، فمن كانت هجرته إلى دنيا يصيبها، أو إلى امرأة ينكحها، فهجرته إلى ما هاجر إليه")+"</span></p></td></tr></table></body></html>";
    //  labHadith->setAlignment(Qt::AlignCenter);
    labHadith->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    labHadith->setGeometry(0,500,500,300);
    labHadith->setWordWrap(true);
    labHadith->setText(text);

    mscene->addWidget(labBasmala);
    mscene->addWidget(labHadith);

    QParallelAnimationGroup *groupRotate = new QParallelAnimationGroup;
    QParallelAnimationGroup *groupTransform = new QParallelAnimationGroup;
    QParallelAnimationGroup *groupCercle = new QParallelAnimationGroup;
    QParallelAnimationGroup *groupOpacity = new QParallelAnimationGroup;

    QParallelAnimationGroup *paralleGroup=new QParallelAnimationGroup;

    QSequentialAnimationGroup *sequentGroup=new QSequentialAnimationGroup;

    QPixmap   mypixmap(QPixmap(":/images/image/groupbook.png")) ;
    QPixmap   pixtitle(QPixmap(":/images/image/titlekirtasse.png")) ;


    qreal real=0.0;
    for(int i=0;i <10; ++i){
        real=real+0.05;
        Pixmap *item = new Pixmap(mypixmap);
        item->setGeometry(QRect(190,200,128.0,128.0));
        item->setOpacity(real);
        mscene->addItem(item);
        items << item;
    }
    items[9]->setOpacity(1.0);
    //! [0]
    int r=-360;
    for (int i = 0; i < items.count(); ++i) {
        r=r+36;
        QPropertyAnimation * anim = new QPropertyAnimation(items[i], "rotation");
        anim->setStartValue(-r);
        anim->setEndValue(-360);
        anim->setDuration(1000);
        groupCercle->addAnimation(anim);
    }
    //! [1]
    for (int i = 0; i < items.count(); ++i) {

        QPropertyAnimation * anim = new QPropertyAnimation(items[i], "transformOriginPoint");
        anim->setEndValue(QPointF(64,64));
        groupTransform->addAnimation(anim);
    }
    //! [2]
    //r=0;
    for (int i = 0; i < items.count(); ++i) {
        r=r-36;
        QPropertyAnimation * anim = new QPropertyAnimation(items[i], "rotation");
        anim->setStartValue(r);
        anim->setEndValue(360);
        anim->setDuration(500);
        groupRotate->addAnimation(anim);
    }

    //! [3]
    for (int i = 0; i < items.count()-1; ++i) {
        QPropertyAnimation * anim = new QPropertyAnimation(items[i], "opacity");
        anim->setEndValue(0.0);
        groupOpacity->addAnimation(anim);
    }
    //! [4]
    QPropertyAnimation * animBook = new QPropertyAnimation(items[9], "pos");
    animBook->setDuration(1000);
    animBook->setStartValue(QPointF(200,200));
    animBook->setEndValue(QPointF(200,30));
    animBook->setEasingCurve(QEasingCurve::OutBounce);

    Pixmap *itemTitle = new Pixmap(pixtitle);
    itemTitle->setGeometry(QRect(130,150,266,1117));
    itemTitle->setOpacity(0.0);
    mscene->addItem(itemTitle);
    //! [5]
    QPropertyAnimation * animTitle = new QPropertyAnimation(itemTitle, "opacity");
    animTitle->setDuration(1000);
    animTitle->setStartValue(0.0);
    animTitle->setEndValue(1.0);
    animTitle->setEasingCurve(QEasingCurve::InCirc);
     connect( animTitle, SIGNAL(finished()), this, SLOT(animEtoileTitle()));
    //! [6]
    QPropertyAnimation * animHadith = new QPropertyAnimation(labHadith, "pos");
    animHadith->setDuration(800);
    animHadith->setStartValue(QPointF(0,500));
    animHadith->setEndValue(QPointF(0,200));
    animHadith->setEasingCurve(QEasingCurve::Linear);

    paralleGroup->addAnimation(animTitle);
    paralleGroup->addAnimation(animHadith);

    sequentGroup->addPause(300);
    sequentGroup->addAnimation(groupCercle);
    sequentGroup->addAnimation(groupTransform);
    sequentGroup->addAnimation(groupRotate);
    sequentGroup->addAnimation(groupOpacity);
    sequentGroup->addAnimation(animBook);
    sequentGroup->addAnimation(paralleGroup);
    sequentGroup->addPause(700);
    connect( sequentGroup, SIGNAL(finished()), this, SLOT(animEtoileBook()));
 //   sequentGroup->addAnimation(groupReflet);

     sequentGroup->start();
    items[9]->setCursor(Qt::PointingHandCursor);
    connect( items[9], SIGNAL(release()), this, SLOT(chargeLevelOne()));
    QGraphicsDropShadowEffect *efet=new QGraphicsDropShadowEffect;
    efet->setOffset(8,8);
   efet->setColor(QColor(0, 0, 0, 80));
   efet->setBlurRadius(12);
    itemTitle->setGraphicsEffect(efet);

    //          anim->start();
}
void  View::animEtoileTitle()
{
   animEtoile(QRect(155,190,32,32))  ;
}
 void  View::animEtoileBook()
 {
 animEtoile(QRect(265,60,32,32))  ;
 }

void View:: animEtoile(QRect rect)
{
    QParallelAnimationGroup *groupReflet = new QParallelAnimationGroup();
    QSequentialAnimationGroup *sequentGroup=new QSequentialAnimationGroup;

    QPixmap   pixRefle(QPixmap(":/images/image/reflet.png")) ;
    Pixmap *itemReflet = new Pixmap(pixRefle);
    //  itemReflet->setGeometry(QRect(155,190,32,32));
  //  itemReflet->setGeometry(QRect(265,60,32,32));
     itemReflet->setGeometry(rect);
    itemReflet->setOpacity(0.0);
    itemReflet->setTransformOriginPoint(16,16);
    mscene->addItem(itemReflet);
    //! [7]
    QPropertyAnimation * animRefletOp = new QPropertyAnimation(itemReflet, "opacity");
    animRefletOp->setDuration(1200);
    if (animRefletOp->currentLoop()==1){
        animRefletOp->setStartValue(0.0);
        animRefletOp->setEndValue(1.0);
    }else{
        animRefletOp->setStartValue(1.0);
        animRefletOp->setEndValue(0.0);
    }//
    animRefletOp->setLoopCount(2);
    //! [8]
    QPropertyAnimation * animRefletRot = new QPropertyAnimation(itemReflet, "rotation");
    animRefletRot->setDuration(1000);
    animRefletRot->setStartValue(0);
    animRefletRot->setEndValue(360);
    animRefletOp->setLoopCount(2);

    groupReflet->addAnimation(animRefletOp);
    groupReflet->addAnimation(animRefletRot);
    sequentGroup->addAnimation(groupReflet);
//groupReflet->setLoopCount(-1);
    groupReflet->start();

}
