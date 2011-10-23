//  -------------------------------------------------
//  Project created by QtCreator 2011-04-30T21:17:32
// -----------------------------------------------------
// 
//   elboukhari Copyright (C) 2011  <abouzakaria  yahiaui@gmail.com>
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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_settings.h"
#include <QGraphicsProxyWidget>
#include <QParallelAnimationGroup>
#include <QGraphicsLinearLayout>
#include <QMessageBox>
#include <QFile>
#include <QXmlStreamReader>
#include <QTextCodec>
#include <QFontDialog>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),settingsDialog(0), UI(0)
{
    ui->setupUi(this);

    loadSettings();
    mscene=new QGraphicsScene;
  mscene->setSceneRect(0,0,584,519);

    creatFahrasa();

    chargePages();

    animRuned=false;

    playIcon=(QPixmap(QString::fromUtf8(":/images/media-playback-start.png")));
    pauseIcon=(QPixmap(QString::fromUtf8(":/images/media-playback-pause.png")));
    connect(&m_MediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    connect(&m_MediaObject, SIGNAL(finished()), this, SLOT(mediaFinished()));
    Phonon::createPath(&m_MediaObject, &m_AudioOutput);

    QString style=("QSlider::groove:horizontal {"
                   "border: 1px;"

                   "border-radius: 3px;"
                   "height: 6px;"
                   "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 120), stop:1 rgba(255, 255, 255,80));"
                   "margin: 2px 0;}"
                   "QSlider::handle:horizontal {"
                   "border-image: url(:/images/slider-n.png);"
                   " width: 17px;"
                   "margin: -2px 0;"
                   "border-radius: 3px;}"
                   "QSlider::handle:horizontal:hover {"
                   "border-image: url(:/images/slider-h.png);"
                   " width: 17px;"
                   "margin: -2px 0;"
                   "border-radius: 3px;}" );
    slider = new Phonon::SeekSlider(this);
    slider->setFixedWidth(150);
    slider->setMediaObject(&m_MediaObject);
    slider->setStyleSheet(style);
    volume = new Phonon::VolumeSlider(&m_AudioOutput);
    volume->setStyleSheet(style);
    volume->setFixedWidth(100);
    ui->mainToolBar->addWidget(slider);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(volume);
    ui->frameFind->setVisible(false);
    treeChargeFahrassa();
  qApp->processEvents();


}

MainWindow::~MainWindow()
{
    delete ui;
    saveSettings();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {

    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;

    default:
        break;
    }
}


void MainWindow::on_actionPrevBab_triggered()
{

    animPagesRight();
}

void MainWindow::on_actionNextBab_triggered()
{
    animPagesLeft();


}

void MainWindow::on_actionTreeList_toggled(bool isopened )
{
    animFahrasa(isopened);

}

void MainWindow::fahrasItemActivated(QTreeWidgetItem * item)
{

    int id=item->data(0,1).toInt();
    if (!id){
        return;
    }

    setCurentPage(id-1);
    on_actionTreeList_toggled(false);
    ui->actionTreeList->setChecked(false);

}

void MainWindow::on_actionPlayPause_triggered()
{

    if (m_MediaObject.state() == Phonon::PlayingState)
        m_MediaObject.pause();
    else {
        if (m_MediaObject.currentTime() == m_MediaObject.totalTime())
            m_MediaObject.seek(0);
        m_MediaObject.play();
    }
}

void MainWindow::on_actionStop_triggered()
{
    m_MediaObject.stop();
}

void MainWindow::on_actionOption_triggered()
{
    if (!settingsDialog)
        initSettingsDialog();
    settingsDialog->exec();

    if (settingsDialog->result() == QDialog::Accepted){
        m_font=UI->labelFont->text();
        m_autoPlay=UI->checkBoxAutoPlay->checkState();
        m_autoPlayNext=UI->radioButtonPlayNext->isChecked();
        m_autoStop=UI->radioButtonPlayOne->isChecked();
        m_autoRepeat=UI->radioButtonPlayRepeat->isChecked();
        QFont font;
        font.fromString(m_font);
        for (int i=0;i<4 ;i++){
            txtBrewser[i]->setFont(font);
        }
        m_mediaFolder=UI->lineEdit->text();
    }

}

void MainWindow::on_actionNextKitab_triggered()
{
    QTreeWidgetItem *item=treeWidgetFahrasa->currentItem();

    if(!item->parent()){
        int i=treeWidgetFahrasa->indexOfTopLevelItem(item);
        if(!treeWidgetFahrasa->topLevelItem(i+1))return;
        treeWidgetFahrasa->setCurrentItem(treeWidgetFahrasa->topLevelItem(i+1)->child(0));
    }else{
        int i=treeWidgetFahrasa->indexOfTopLevelItem(item->parent());
        if(!treeWidgetFahrasa->topLevelItem(i+1))return;
        treeWidgetFahrasa->setCurrentItem(treeWidgetFahrasa->topLevelItem(i+1)->child(0));
    }

    int index=   treeWidgetFahrasa->currentItem()->data(0,1).toInt()-1;
    setCurentPage(index);

}

void MainWindow::on_actionPrevKitab_triggered()
{
    QTreeWidgetItem *item=treeWidgetFahrasa->currentItem();

    if(!item->parent()){
        int i=treeWidgetFahrasa->indexOfTopLevelItem(item);
        if(!treeWidgetFahrasa->topLevelItem(i-1))return;
        treeWidgetFahrasa->setCurrentItem(treeWidgetFahrasa->topLevelItem(i-1)->child(0));
    }else{
        int i=treeWidgetFahrasa->indexOfTopLevelItem(item->parent());
        if(!treeWidgetFahrasa->topLevelItem(i-1))return;
        treeWidgetFahrasa->setCurrentItem(treeWidgetFahrasa->topLevelItem(i-1)->child(0));
    }
    int index=   treeWidgetFahrasa->currentItem()->data(0,1).toInt()-1;
    setCurentPage(index);
}

void MainWindow::on_actionFind_toggled(bool v)
{
    ui->frameFind->setVisible(v);
}
void MainWindow::on_pushButtonFind_clicked()
{
    searchInDoc(txtBrewser[m_curText]->document(),ui->lineEditFind->text());
}
void MainWindow::on_pushButtonFindNext_clicked()
{
    if (ui->lineEditFind->text().isEmpty()){
        return;
    }
    findNext(txtBrewser[m_curText]->document(),ui->lineEditFind->text());
}

////
//chargement

void MainWindow::chargePages()
{


    QBrush b;
    b.setTexture(QPixmap(":/images/menu.png"));
    mscene->setBackgroundBrush(b);

    QFont font;
    font.fromString(m_font);
    int d=mscene->width();
    for (int i=0;i<4;i++){
        QGraphicsGridLayout *gridLayout = new QGraphicsGridLayout();
        if (i==0)d=-mscene->width();
        if (i==1)d=0;
        if (i==2)d=(mscene->width());
        if (i==3)d=(mscene->width()*2);
        widget[i] = new QGraphicsWidget;
        widget[i]->setGeometry(d,0,mscene->width(),mscene->height());


        txtBrewser[i]=new QTextBrowser();
        txtBrewser[i]->setFont(font);
      txtBrewser[i]->setStyleSheet( "QTextBrowser{background-color: rgb(249, 249, 185);}");
       // txtBrewser[i]->setText( "QTextBrowser{background-color: rgb(249, 249, 185);}");
        txtBrewser[i]->setLayoutDirection(Qt::RightToLeft);
        txtBrewser[i]->setFrameShape(QFrame::NoFrame);
//
//        QFrame *frame =new QFrame;
//      frame->setPalette(QPalette(QColor(249, 249, 185,0)));
//        frame->setFrameStyle(QFrame::NoFrame);
//        frame->setLayoutDirection(Qt::RightToLeft);
//
//        frame->setStyleSheet("QFrame{border-image: url(:/images/page.png);}" );
//
//        QVBoxLayout  *verticalLayout = new QVBoxLayout(frame);
//        verticalLayout->addWidget(txtBrewser[i]);
//verticalLayout->setContentsMargins(26, 26, 34, 30);
        QGraphicsProxyWidget *txtProxy = new QGraphicsProxyWidget;
        txtProxy->setPalette(QPalette(QColor(249, 249, 185)));
        txtProxy->setWidget(txtBrewser[i]);
      creatCadre(gridLayout);
        qApp->processEvents();
        gridLayout->addItem(txtProxy,1,1,Qt::AlignCenter);   //center
        widget[i]->setLayout(gridLayout);

        mscene->addItem(widget[i]);
        //widget[i]->setVisible(false);
    }
    m_prevText=2;
    m_curText=1;
    m_nextText=0;
    m_curWidget=3;

    ui->graphicsView->setScene(mscene);
}

void MainWindow:: creatCadre(QGraphicsGridLayout *gLayout)
{

    gLayout->setSpacing(0);
    //  buttonProxy->setZValue(8);
    QString imgPath=":/images/";
    QPixmap pix(imgPath+"/top_right.png");
    QSize size(pix.width(),pix.height());
    enum {Indx =8 };
    QWidget *frame[Indx];
    QGraphicsProxyWidget *gframe[Indx];
    for (int i=0;i<8;i++){
        frame[i] = new QWidget();
        frame[i]->setPalette(QPalette(QColor(249, 249, 185,0)));
        gframe[i] = new QGraphicsProxyWidget;
        gframe[i]->setWidget(frame[i]);
        frame[i]->setMinimumSize(size);
    }
    frame[0]->setStyleSheet("background-image: url("+imgPath+"/top_left.png);");
    frame[1]->setStyleSheet("background-image: url("+imgPath+"/top.png);");
    frame[2]->setStyleSheet("background-image: url("+imgPath+"/top_right.png);");
    frame[3]->setStyleSheet("background-image: url("+imgPath+"/left.png);");
    frame[4]->setStyleSheet("background-image: url("+imgPath+"/right.png);");
    frame[5]->setStyleSheet("background-image: url("+imgPath+"/bot_left.png);");
    frame[6]->setStyleSheet("background-image: url("+imgPath+"/bot.png);");
    frame[7]->setStyleSheet("background-image: url("+imgPath+"/bot_right.png);");

    gLayout->addItem(gframe[0], 0, 0);//topRight
    gLayout->addItem(gframe[1], 0, 1);//top
    gLayout->addItem(gframe[2], 0, 2);//topLeft
    gLayout->addItem(gframe[3], 1, 0);//right

    gLayout->addItem(gframe[4], 1, 2);//left
    gLayout->addItem(gframe[5], 2, 0);//botRight
    gLayout->addItem(gframe[6], 2, 1);//bot
    gLayout->addItem(gframe[7], 2, 2);//botLeft

gLayout->setSpacing(0.0);


}

void MainWindow::creatFahrasa()
{

    widgetFahrasa=new QGraphicsWidget;
    widgetFahrasa->setGeometry(0,0,414,446);
    // widgetFahrasa->setPalette(QPalette(QPalette::Window));
    treeWidgetFahrasa=new QTreeWidget;
    lineEditSearch=new QLineEdit;
    connect(lineEditSearch, SIGNAL(textChanged(QString)), this, SLOT(searchInTreeview()));

    QFrame *frame =new QFrame;
    frame->setPalette(QPalette(QColor(249, 249, 185,0)));
    frame->setLayoutDirection(Qt::RightToLeft);
    frame->setStyleSheet("QFrame{border-image: url(:/images/boukhari.jpg);}" );

    treeWidgetFahrasa->setStyleSheet("QTreeWidget{border-image: url(:/images/treeBg.jpg);}"
                                     "QTreeWidget::item{color: black;}");
    treeWidgetFahrasa->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    treeWidgetFahrasa->setColumnCount(2);
    treeWidgetFahrasa->setColumnHidden(1,true);
    treeWidgetFahrasa->headerItem()->setText(0,trUtf8("فهرسة صحيح البخاري"));
    treeWidgetFahrasa->headerItem()->setTextAlignment(0,Qt::AlignHCenter);
    treeWidgetFahrasa->header()->setStyleSheet("QHeaderView::section {"
                                               "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
                                               "stop:0 #AE7F54, stop: 0.5 #704F31,"
                                               "stop: 0.6 #493421, stop:1 #8D6745);"
                                               "color: white;"
                                               "padding: 4px;"
                                               " border-radius: 2px;"
                                               "border: 1px solid #2C1F12;}"
                                               );
    connect(treeWidgetFahrasa, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(fahrasItemActivated(QTreeWidgetItem*)));

    //treeWidgetFahrasa->header()->setVisible(false);
    QVBoxLayout  *verticalLayout = new QVBoxLayout(frame);
    verticalLayout->setContentsMargins(26, 66, 28, 31);
    verticalLayout->addWidget(lineEditSearch);
    verticalLayout->addWidget(treeWidgetFahrasa);
    QGraphicsProxyWidget *lineProxy = new QGraphicsProxyWidget;
    lineProxy->setWidget(frame);
    QGraphicsGridLayout *gridLayout2 = new QGraphicsGridLayout();

    widgetFahrasa->setLayout(gridLayout2);
    qApp->processEvents();
    //creatCadre(gridLayout2);
    gridLayout2->addItem(lineProxy,1,1,Qt::AlignCenter);

    mscene->addItem(widgetFahrasa);
    widgetFahrasa->setVisible(false);
    widgetFahrasa->setZValue(4);
}

void MainWindow::treeChargeFahrassa()
{


    QString title;
    QString level;
    QString file;
    QString nass;
    QFile fileXml(QCoreApplication::applicationDirPath() +"/main.xml");
    if(!fileXml.open(QIODevice::ReadOnly)) return;

    QXmlStreamReader xml;

    xml.setDevice(&fileXml);
    QTreeWidgetItem *itemtop=new QTreeWidgetItem;
    QTreeWidgetItem *item;
    int counter=0;
    if (xml.readNextStartElement()) {
        if (xml.name() == "dataroot" ){
            Q_ASSERT(xml.isStartElement() && xml.name() == "dataroot");
            while (xml.readNextStartElement()) {

                if (xml.name() == "Tree1"){



                    while (xml.readNextStartElement()) {

                        if (xml.name() == "title"){
                            title=xml.readElementText();
                        }else if (xml.name() == "level"){
                            level= xml.readElementText();
                        }else if (xml.name() == "file"){
                            file= xml.readElementText();
                        }else if (xml.name() == "nass"){
                            nass= xml.readElementText();
                        }else{
                            xml.skipCurrentElement();
                        }

                    }

                    if (level=="1"){
                        itemtop= new QTreeWidgetItem(treeWidgetFahrasa);
                        itemtop->setText(0,title );
                        // itemtop->setData(0,1,file);
                    }else{
                        counter++;
                        item= new QTreeWidgetItem(itemtop);
                        item->setText(0,title );
                        item->setText(1,QString::number(counter) );
                        item->setData(0,1,counter);
                        m_listNass.append(nass);
                        m_listFile.append(file);
                        item->setToolTip(0,title);
                    }

                }else{
                    xml.skipCurrentElement();
                }
            }
        }
    }
    m_rowCount=counter-1;
    xml.clear();
    fileXml.close();
    setCurentPage(m_curIndex);
    m_MediaObject.stop();
}

// animation
void MainWindow::animPagesLeft()
{
    if (animRuned==true)return;
    // txtBrewser[curWidget] ->clear();
    // if (txtBrewser[nextText]->toPlainText().isEmpty())return;
    if (m_curIndex==m_rowCount)return;

    animRuned=true;

    txtBrewser[m_curWidget]->clear();
    if(m_curIndex<m_rowCount-2){
        //   txtBrewser[curWidget]->setText(listNass.at(curIndex+2));
        txtBrewser[m_curWidget]->setHtml(convertText(m_listNass.at(m_curIndex+2)));
    }
    m_curIndex=m_curIndex+1;
    widget[m_curWidget]->setPos(- widget[m_curWidget]->geometry().width()*2,0);

    widget[m_curWidget]->setVisible(true);
    QParallelAnimationGroup *group = new QParallelAnimationGroup();
    connect( group, SIGNAL(finished()), this, SLOT(setCurWidgetLeft()));
    for(int i=0;i<4;i++){
        int x=widget[i]->pos().x();
        int w=widget[i]->geometry().width();
        QPropertyAnimation * anim = new QPropertyAnimation(widget[i], "pos");
        anim->setDuration(750);
        anim->setEndValue(QPointF(x+w, 0));
        anim->setEasingCurve(QEasingCurve::InOutQuad);
        group->addAnimation(anim);
    }

    group->start();
}
void MainWindow::setCurWidgetLeft()
{
    int cur=m_curText;
    int next=m_nextText;
    int prev=m_prevText;
    int last=m_curWidget;
    m_nextText=last;
    m_curText=next;
    m_prevText=cur;
    m_curWidget=prev;
    widget[m_curWidget]->setVisible(false);
    //msceneBook->setActiveWindow(widget[curText]);
    //widget[curText]->grabKeyboard();
    animRuned=false;
    txtBrewser[m_curWidget]->setFocus();
    playCurentMedia();
}

void MainWindow::animPagesRight()
{
    if (animRuned==true)return;
    //  txtBrewser[curWidget] ->clear();
    // if (txtBrewser[prevText]->toPlainText().isEmpty())return;
    if (m_curIndex==0)return;

    animRuned=true;
    txtBrewser[m_curWidget]->clear();
    if(m_curIndex>1){
        //  txtBrewser[curWidget]->setText(listNass.at(curIndex-2));
        txtBrewser[m_curWidget]->setHtml(convertText(m_listNass.at(m_curIndex-2)));
    }

    m_curIndex=m_curIndex-1;
    widget[m_curWidget]->setPos( widget[m_curWidget]->geometry().width()*2,0);

    widget[m_curWidget]->setVisible(true);
    QParallelAnimationGroup *group = new QParallelAnimationGroup();
    connect( group, SIGNAL(finished()), this, SLOT(setCurWidgetRight()));
    for(int i=0;i<4;i++){
        int x=widget[i]->pos().x();
        int w=widget[i]->geometry().width();
        QPropertyAnimation * anim = new QPropertyAnimation(widget[i], "pos");
        anim->setDuration(750);
        anim->setEndValue(QPointF(x-w, 0));
        anim->setEasingCurve(QEasingCurve::OutBack);
        group->addAnimation(anim);
    }
    group->start();
}
void MainWindow::setCurWidgetRight()
{
    int cur=m_curText;
    int next=m_nextText;
    int prev=m_prevText;
    int last=m_curWidget;
    m_nextText=cur;
    m_curText=prev;
    m_prevText=last;
    m_curWidget=next;
    widget[m_curWidget]->setVisible(false);
    animRuned=false;
      txtBrewser[m_curWidget]->setFocus();
    playCurentMedia();
}

void MainWindow::animFahrasa(bool open)
{
    widgetFahrasa->setVisible(true);
    int y=(ui->graphicsView->height()-mscene->height())/2;
    int x=(mscene->width()/2)-210;
    QPropertyAnimation * anim = new QPropertyAnimation(widgetFahrasa, "pos");
    connect( anim, SIGNAL(finished()), this, SLOT(animFahrasaFinished()));
    if (open==true){
        anim->setDirection(QAbstractAnimation::Forward);
        anim->setEasingCurve(QEasingCurve::OutBounce);
    }else{
        anim->setDirection(QAbstractAnimation::Backward);
        anim->setEasingCurve(QEasingCurve::InCubic);
    }
    anim->setDuration(750);
    anim->setStartValue(QPointF(x, -(y+mscene->height())));
    anim->setEndValue(QPointF(x, 28));

    anim->start();

}
void MainWindow::animFahrasaFinished()
{

    if (widgetFahrasa->pos().y()<0){
        widgetFahrasa->setVisible(false);
        lineEditSearch->clear();
    }
}

//media
void MainWindow::mediaFinished()
{

    // if (m_autoPlay==false)return;
    if (m_autoStop==true)return;
    if (m_autoRepeat==true){
        m_MediaObject.setCurrentSource(m_MediaObject.currentSource());
        m_MediaObject.seek(0);
        m_MediaObject.play();

        return;
    }
    if (m_autoPlayNext) animPagesLeft();

}

void MainWindow::stateChanged(Phonon::State newstate, Phonon::State oldstate)
{
    Q_UNUSED(oldstate);

   switch (newstate) {
    case Phonon::ErrorState:
        if (m_MediaObject.errorType() == Phonon::FatalError) {
            ui->actionPlayPause->setEnabled(false);
            // rewindButton->setEnabled(false);
        } else {
            m_MediaObject.pause();
        }
        ui->statusBar->showMessage("Phonon Mediaplayer :"+ m_MediaObject.errorString());
        // QMessageBox::warning(this, "Phonon Mediaplayer", m_MediaObject.errorString(), QMessageBox::Close);
        break;

   case Phonon::StoppedState:
        ui->actionPlayPause->setIcon(playIcon);
        break;

  case Phonon::LoadingState:
        break;

  case Phonon::BufferingState:
        break;

  case Phonon::PausedState:
        ui->actionPlayPause->setIcon(playIcon);
        if (m_MediaObject.currentSource().type() != Phonon::MediaSource::Invalid){
            ui->actionPlayPause->setEnabled(true);
            // rewindButton->setEnabled(true);
        } else {
            ui->actionPlayPause->setEnabled(false);
            //rewindButton->setEnabled(false);
        }
        break;

  case Phonon::PlayingState:
        ui->actionPlayPause->setEnabled(true);
        ui->actionPlayPause->setIcon(pauseIcon);
        break;
        // Fall through


    }


}

void MainWindow::playCurentMedia()
{
    QVariant dd=m_curIndex+1;
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            treeWidgetFahrasa->findItems(
                    dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);

    foreach (item, found){
        treeWidgetFahrasa->setCurrentItem(item);
        QString kitab;
        QString bab;
        if (item->parent())
            kitab=item->parent()->text(0);
        bab=item->text(0);
        ui->statusBar->showMessage(kitab+" / "+bab);
    }

    m_curFile=m_listFile.at(m_curIndex);
    //QRegExp rx("/home/abouzakaria/MainMenu/"+curFile+".[Mm][Pp]3");
    QString fileName;

    QFile file;
    if (file.exists(m_mediaFolder+"/"+m_curFile.toUpper()+".OGG")){
        fileName=m_mediaFolder+"/"+m_curFile.toUpper()+".Ogg";
    }else if(file.exists(m_mediaFolder+"/"+m_curFile+".ogg")){
        fileName=m_mediaFolder+"/"+m_curFile+".ogg";
    }else if (file.exists(m_mediaFolder+"/"+m_curFile.toUpper()+".MP3")){
        fileName=m_mediaFolder+"/"+m_curFile.toUpper()+".MP3";
    }else if(file.exists(m_mediaFolder+"/"+m_curFile+".mp3")){
        fileName=m_mediaFolder+"/"+m_curFile+".mp3";
    }else{
        m_MediaObject.clear();
        return;
    }

    m_MediaObject.setCurrentSource(fileName);
    if (m_autoPlay==false)return;
    m_MediaObject.play();

}
//text
void MainWindow::setCurentPage(int index)
{
    //UpdatScenPages();
    m_curIndex=index;

    txtBrewser[m_curText]->setHtml(convertText(m_listNass.at(index)));


    if (index>0){
        txtBrewser[m_prevText]->setHtml(convertText(m_listNass.at(index-1)));
    }else if (index==0){
        txtBrewser[m_prevText]->clear();
    }
    if (index<m_listFile.count()-1){
        txtBrewser[m_nextText]->setHtml(convertText(m_listNass.at(index+1)));
    }else if (index==m_listFile.count()-1){
        txtBrewser[m_nextText]->clear();
    }
    txtBrewser[m_curWidget]->clear();
    playCurentMedia();
    //  convertText(txtBrewser[curText]->document());
}

QString MainWindow::convertText(QString txt)
{

    QRegExp rx("(\\d+)( -)");

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextDocument *document=new QTextDocument;
    document->setPlainText(txt);
    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);
    cursor.beginEditBlock();

    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
        highlightCursor.movePosition(QTextCursor::EndOfLine,QTextCursor::KeepAnchor);

        QString text=highlightCursor.selectedText();


        int pos2 = text.indexOf(trUtf8("بسم الله الرحمن الرحيم"));
        int pos3 = text.indexOf(trUtf8("كتاب"));
        int pos = text.indexOf(trUtf8("باب"));
        int pos4=text.indexOf(rx);
        if ((pos<=3&&pos!=-1)||(pos2<=3&&pos2!=-1)||(pos3<=3&&pos3!=-1)){
            txt.replace(text,"< font color='red' >"+text+"</font><br>");
        }
        if(pos4<=3&&pos4!=-1){
            QString newtext=text;
            newtext.replace(rx,"< font color='#07206E' >"+rx.cap(1)+rx.cap(2)+"</font>");
            txt.replace(text,newtext);
        }
        highlightCursor.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor);

    }

    cursor.endEditBlock();
    txt.replace(QByteArray("\n"), QByteArray("<br>"));
    txt.replace(QByteArray("\r"), QByteArray("<br>"));
    txt.replace("صلى الله عليه وسلم","< font color='#1A4721' >صلى الله عليه وسلم</font> ");
    return txt;
}
//settings
void MainWindow::initSettingsDialog()
{
    settingsDialog = new QDialog(this);
    UI = new Ui_settings();
    UI->setupUi(settingsDialog);

    connect(UI->toolButtonFont, SIGNAL(clicked()), this, SLOT(openFont()));
    connect(UI->toolButtonFileName, SIGNAL(clicked()), this, SLOT(openDialogFolder()));
    UI->lineEdit->setText(m_mediaFolder);
    UI->labelFont->setText(m_font);
    UI->checkBoxAutoPlay->setChecked( m_autoPlay);
    UI->radioButtonPlayNext->setChecked(m_autoPlayNext);
    UI->radioButtonPlayOne->setChecked(m_autoStop);
    UI->radioButtonPlayRepeat->setChecked(m_autoRepeat);
}

void MainWindow::openDialogFolder()
{
    QString homeDir=QDir::homePath () ;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    homeDir,
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
    UI->lineEdit->setText(dir);
}

void MainWindow::openFont()
{
    QFont font;
    font.fromString(m_font);
    bool ok = false;
    QFont police =QFontDialog::getFont(&ok, font, this,trUtf8("اختيار خط الصفحة"));
    if (ok)
    {
        //fontName=(police);
        QVariant fs=police.pointSize();
        UI->labelFont->setText(police.toString());
    }
}

void MainWindow::loadSettings()//load
{

    QSettings settings(QDir::homePath()+"/.boukhari",QSettings::IniFormat);
    settings.beginGroup("MainWindow");
#ifdef  Q_WS_X11
    m_font=settings.value("font","KacstBook,16,-1,5,50,0,0,0,0,0").toString();
#else
    m_font=settings.value("font","Traditional Arabic,16,-1,5,50,0,0,0,0,0").toString();
#endif
    m_mediaFolder=settings.value("mediaFolder",QCoreApplication::applicationDirPath()+"/sound").toString();
    m_autoPlay=  settings.value("autoPlay",true).toBool();
    m_autoPlayNext=  settings.value("autoPlayNext",true).toBool();
    m_autoStop=  settings.value("autoStop",false).toBool();
    m_autoRepeat=  settings.value("autoRepeat",false).toBool();
    m_curIndex=settings.value("curIndex",0).toInt();
    settings.endGroup();

}
void MainWindow::saveSettings()//حفظ البيانات الى ملف
{
    QSettings settings(QDir::homePath()+"/.boukhari",
                       QSettings::IniFormat);

    settings.beginGroup("MainWindow");

    settings.setValue("font", m_font);
    settings.setValue("mediaFolder",  m_mediaFolder);
    settings.setValue("autoPlay", m_autoPlay);
    settings.setValue("autoPlayNext", m_autoPlayNext);
    settings.setValue("autoStop", m_autoStop);
    settings.setValue("autoRepeat",m_autoRepeat);
    settings.setValue("curIndex",m_curIndex);
    settings.endGroup();
}

//find
bool  MainWindow::searchInDoc(QTextDocument *document,QString searchString)
{

    bool found = false;
    document->undo();
    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);
    cursor.beginEditBlock();
    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    colorFormat.setForeground(QColor::fromRgb(255,255,255));
    colorFormat.setBackground(QColor::fromRgb(255,83,0));
    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
        highlightCursor = document->find(searchString, highlightCursor, QTextDocument::FindCaseSensitively);

        if (!highlightCursor.isNull()) {
            found = true;
            highlightCursor.movePosition(QTextCursor::Right,
                                         QTextCursor::KeepAnchor);

            highlightCursor.mergeCharFormat(colorFormat);

        }
    }
    cursor.endEditBlock();

    if (found == false) {
        return false;
    }

    return true;
}



void MainWindow::findNext(QTextDocument *document,QString searchString)
{

    for(int pos=m_curIndex+1;pos<m_rowCount;pos++){

        QString  Nass=m_listNass.at(pos) ;
        if (Nass.contains(searchString)){
            setCurentPage(pos);
            searchInDoc(document,searchString);
            break;
        }
    }
}
//-******************


void MainWindow::searchInTreeview()
{
    for( int i = 0; i <treeWidgetFahrasa->topLevelItemCount(); i++ ) {
        treeWidgetFahrasa->topLevelItem(i)->setHidden(false );
        showAllItems(treeWidgetFahrasa->topLevelItem(i),treeWidgetFahrasa);
    }
    if (!lineEditSearch->text().isEmpty()){
        for( int i = 0; i <treeWidgetFahrasa->topLevelItemCount(); i++ ) {
            searchTreeForString(lineEditSearch->text(),treeWidgetFahrasa->topLevelItem(i),true,i,treeWidgetFahrasa,0) ;
        }
    }
}

bool MainWindow::searchTreeForString( const QString &searchString, QTreeWidgetItem* parent,bool itemtop,int  topindex,QTreeWidget *view,int colum)
{
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

bool MainWindow::showAllItems( QTreeWidgetItem* parent,QTreeWidget *view )
{
    for( int i = 0; i < parent->childCount(); i++ ) {
        view->setItemHidden(parent->child(i),false);
        showAllItems( parent->child( i) ,view);
    }
    return true;
}
//**********************

void MainWindow::on_actionAbout_triggered()
{


    QMessageBox msgBox(this);
    QPixmap   pixmapG(":/images/sahih.png") ;
    msgBox.setLayoutDirection(Qt::RightToLeft);
    msgBox.setWindowTitle(trUtf8("حول برنامج صحيح البخاري"));
    msgBox.setText(trUtf8("برنامج صحيح البخاري"));
    msgBox.setIconPixmap(pixmapG);
    msgBox.setInformativeText(trUtf8("المؤلف : أبو زكريا")+"\n"+trUtf8("الاصدار : 0.1 تجريبي")
                              +"\n"+trUtf8("الرخصة :  gpl3")
                              +"\n"+trUtf8("برنامج صحيح البخاري بالصوت والنص يمكنك مطالعته حتى بغياب الصوت كما يمكن اجراء بحث تسلسلي على مستوى النص او على مستوى الفهارس ") );

    msgBox.exec();
}
void MainWindow:: resizeEvent(QResizeEvent *event)
{

//ui->graphicsView->fitInView(mscene->sceneRect(),Qt::KeepAspectRatio);

}

void MainWindow::on_actionFullScreen_triggered()
{
  if (!this->isFullScreen()){

        this->showFullScreen();
//
  }else{

        this->showNormal();

    }
}
