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
#include "dialognet.h"
#include "ui_dialognet.h"
#include <QXmlStreamReader>
#include <QtGui>
#include <QDomDocument>
class QSslError;
class QHttp;
class QHttpResponseHeader;
Dialognet::Dialognet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialognet)
{
    ui->setupUi(this);
treeChargeGroupe(ui->treeWidget,0);

//    Messages=new messages;
//    Messages->treeChargeGroupe(ui->treeWidget,0,false);

}

Dialognet::~Dialognet()
{
    delete ui;
}

void Dialognet::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void Dialognet::treeChargeGroupe(QTreeWidget *view,int checked)
{

    QString path=QDir::homePath()+"/.kirtasse";


    QFile file(path+"/data/bookslist.xml");
    if(!file.exists())
    return;

    QTreeWidgetItem *itemRoot= new QTreeWidgetItem(view);
    QTreeWidgetItem *itemGroup= new QTreeWidgetItem(itemRoot);
    QTreeWidgetItem *itemBook;
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
                if (checked==1){
                    itemGroup->setCheckState(0,Qt::Unchecked);
                }
            }

        }else if (xml.name() == "bk"){ //niveau 3

            QString idBook= xml.attributes().value("id").toString();
            QString textBook=xml.attributes().value("name").toString();
            QString AutBook= xml.attributes().value("aut").toString();
           // QString BetakaBook= xml.attributes().value("betaka").toString();
            //QString curanBook= xml.attributes().value("tfsr").toString();
            if(!textBook.isNull()){
                itemBook= new QTreeWidgetItem( itemGroup);
                itemBook->setText(0,textBook);
                itemBook->setText(1,AutBook);
               // itemBook->setText(2,BetakaBook);
                itemBook->setData(1,1,idBook);
                itemBook->setIcon(0,icon);
                //itemBook->setData(2,1,curanBook);
                if (checked==1){
                    itemBook->setCheckState(0,Qt::Unchecked);
                }

            }
        }
    }


    xml.clear();
    file.close();
}

void Dialognet::on_toolButton_clicked()
{
    if (downloadFile(ui->lineEdit->text(),QDir::homePath()+"/.kirtasse/data/")==true) {

      treeChargeGroupe(ui->treeWidget,0);
    }

}
//-****************
//! [0]


bool Dialognet::downloadFile(QString urlPath,QString distPath)
{
    //***************
    progressDialog = new QProgressDialog(0);
isloaded=false;
    http = new QHttp(this);


    connect(http, SIGNAL(requestFinished(int,bool)),
            this, SLOT(httpRequestFinished(int,bool)));
    connect(http, SIGNAL(dataReadProgress(int,int)),
            this, SLOT(updateDataReadProgress(int,int)));
    connect(http, SIGNAL(responseHeaderReceived(QHttpResponseHeader)),
            this, SLOT(readResponseHeader(QHttpResponseHeader)));

#ifndef QT_NO_OPENSSL
    connect(http, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(sslErrors(QList<QSslError>)));
#endif
    connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));

    //******************************
m_urlPath=urlPath;
    QUrl url(m_urlPath);
    QFileInfo fileInfo(url.path());
    QString fileName =distPath+ fileInfo.fileName();

    if (fileName.isEmpty())
        fileName = "index.html";

    if (QFile::exists(fileName)) {
        if (QMessageBox::question(0, tr("HTTP"),
                                  tr("There already exists a file called %1 in "
                                     "the current directory. Overwrite?").arg(fileName),
                                  QMessageBox::Yes|QMessageBox::No, QMessageBox::No)
            == QMessageBox::No)
            return false;
        QFile::remove(fileName);
    }

    fileHttp = new QFile(fileName);
    if (!fileHttp->open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, tr("HTTP"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(fileName).arg(fileHttp->errorString()));
        delete fileHttp;
        fileHttp = 0;
        return false;
    }

    QHttp::ConnectionMode mode = url.scheme().toLower() == "https" ? QHttp::ConnectionModeHttps : QHttp::ConnectionModeHttp;
    http->setHost(url.host(), mode, url.port() == -1 ? 0 : url.port());

    if (!url.userName().isEmpty())
        http->setUser(url.userName(), url.password());

    httpRequestAborted = false;
    QByteArray path = QUrl::toPercentEncoding(url.path(), "!$&'()*+,;=:@/");
    if (path.isEmpty())
        path = "/";
    httpGetId = http->get(path, fileHttp);

    progressDialog->setWindowTitle(tr("HTTP"));
    progressDialog->setLabelText(tr("Downloading %1.").arg(fileName));
 qApp->processEvents();
    while( httpRequestAborted == false){
qApp->processEvents();
    }
//    QVariant dd=isloaded;
//
//       QMessageBox::information(0, tr("HTTP"),("is finish \n"+dd.toString()));

       if (isloaded==false){
           return false;
       }

return true;

}
void Dialognet::httpRequestFinished(int requestId, bool error)
{
    if (requestId != httpGetId)
        return;
    if (httpRequestAborted) {
        if (fileHttp) {
            fileHttp->close();
            fileHttp->remove();
            delete fileHttp;
            fileHttp = 0;
        }

        progressDialog->hide();
        return;
    }

    if (requestId != httpGetId)
        return;

    progressDialog->hide();
    fileHttp->close();

    if (error) {
        fileHttp->remove();
        QMessageBox::information(0, tr("HTTP"),
                                 tr("Download failed: %1.")
                                 .arg(http->errorString()));
         httpRequestAborted=true;
    } else {
        QString fileName = QFileInfo(QUrl(m_urlPath).path()).fileName();
     //    QMessageBox::information(0, tr("HTTP"),tr("Downloaded %1  to %2").arg(fileName).arg(QDir::homePath())+"/.kirtasse/data/");
         mypath=fileName;
         isloaded=true;
         httpRequestAborted=true;
    }


    delete fileHttp;
    fileHttp = 0;
}
void Dialognet::readResponseHeader(const QHttpResponseHeader &responseHeader)
{
    switch (responseHeader.statusCode()) {
    case 200:                   // Ok
    case 301:                   // Moved Permanently
    case 302:                   // Found
    case 303:                   // See Other
    case 307:                   // Temporary Redirect
        // these are not error conditions
        break;

    default:

        QMessageBox::information(0, tr("HTTP"),
                                 tr("Download failed: %1.")
                                 .arg(responseHeader.reasonPhrase()));

        progressDialog->hide();
        http->abort();

    }

}
void Dialognet::updateDataReadProgress(int bytesRead, int totalBytes)
{
    if (httpRequestAborted)
        return;

    progressDialog->setMaximum(totalBytes);
    progressDialog->setValue(bytesRead);
}
void Dialognet::cancelDownload()
{
     QMessageBox::information(0, tr("HTTP"),tr("Download canceled."));
    httpRequestAborted = true;
    http->abort();

}


#ifndef QT_NO_OPENSSL
void Dialognet::sslErrors(const QList<QSslError> &errors)
{
    QString errorString;
    foreach (const QSslError &error, errors) {
        if (!errorString.isEmpty())
            errorString += ", ";
        errorString += error.errorString();
    }

    if (QMessageBox::warning(0, tr("HTTP "),
                             tr("One or more SSL errors has occurred: %1").arg(errorString),
                             QMessageBox::Ignore | QMessageBox::Abort) == QMessageBox::Ignore) {
        http->ignoreSslErrors();
    }
}
#endif
//! [1]

void Dialognet::on_buttonBox_accepted()
{
    QString h=QDir::homePath()+"/.kirtasse/download/";
    QDir dir;
    if (!dir.exists(h))
    dir.mkdir( h);


    if (m_bkUrlPath.isEmpty())
        return;

    downloadFile(m_bkUrlPath,h);

}
////***********remove
bool Dialognet::treeSaveGroupe(QTreeWidget *view)
{
     QDomDocument m_doc;
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
            QString drbox;
            for(int b=1;b<36;b++){
<<<<<<< HEAD
=======

>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
                if (id==QString::number(b))
                    drbox= "http://dl.dropbox.com/u/7206075/"+id+"/";
                if (id=="27")
                    drbox= "http://dl.dropbox.com/u/13013844/"+id+"/";
<<<<<<< HEAD
            }
            for(int c=36;c<100;c++){
                if (id==QString::number(c))
                    drbox= "http://dl.dropbox.com/u/13013844/"+id+"/";
=======

            }
            for(int c=36;c<100;c++){

                if (id==QString::number(c))
                    drbox= "http://dl.dropbox.com/u/13013844/"+id+"/";


>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
            }

            for(int r=0;r<itemols->childCount();++r)
            {
                itemols2=itemols->child(r);
                QString idbk= drbox+itemols2->data(1,1).toString()+".tar.gz";
               // QString betaka=itemols2->text(2);
                QString aut  =itemols2->text(1);
                QString name =itemols2->text(0);
                QDomElement itemsbk=m_doc.createElement("bk");
                items.appendChild(itemsbk);
                itemsbk.setAttribute("id",idbk);
               // itemsbk.setAttribute("betaka",betaka);
                itemsbk.setAttribute("aut",aut);
                itemsbk.setAttribute("name",name);
                if (itemols2->data(2,1)=="1")
                {
                    itemsbk.setAttribute("tfsr","1");
                }
            }
        }
    }
    QFile file(QDir::homePath()+"/.kirtasse/data/bookslist.xml");
    file.open(QIODevice::WriteOnly);              //فتح الملف للكتابة
    QTextStream out(&file);                       //الكتابة
    m_doc.save(out,1);                      //حفظ الملف
    file.close();
    m_doc.clear();
    return true;
}
//void Dialognet::on_pushButton_clicked()
//{
//    treeSaveGroupe(ui->treeWidget);
//}
////***********remove
void Dialognet::on_treeWidget_itemSelectionChanged()
{
    QTreeWidgetItem *item=ui->treeWidget->currentItem();
    if (!item->data(1,1).isNull()){
        QString PathUrl= item->data(1,1).toString();


     // QString dd=PathUrl.replace("dl.dropbox.com","localhost");
        m_bkUrlPath=PathUrl;
         ui->lineEditUrl->setText(PathUrl);
    }else{
        ui->lineEditUrl->setText("");
        m_bkUrlPath=QString::null;
    }
}
////--------------------------
void Dialognet::searchInTreeview(QTreeWidget *view,QString searchString,int colum)
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

bool Dialognet::searchTreeForString( const QString &searchString, QTreeWidgetItem* parent,bool itemtop,int  topindex,QTreeWidget *view,int colum)
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

bool Dialognet::showAllItems( QTreeWidgetItem* parent,QTreeWidget *view )
{
    for( int i = 0; i < parent->childCount(); i++ ) {
        view->setItemHidden(parent->child(i),false);
        showAllItems( parent->child( i) ,view);
    }
    return true;
}


void Dialognet::on_lineEdit_2_textChanged(QString searchString )
{

////    Findbook->searchInTreeview(ui->treeWidget,searchString,0);
searchInTreeview(ui->treeWidget,searchString,0);

}
//**********************


