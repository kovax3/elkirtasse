#include "dialogimportdvd.h"
#include "ui_dialogimportdvd.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QProcess>
#include <QDebug>
#include <QProgressDialog>
#include"messages.h"
DialogImportDvd::DialogImportDvd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogImportDvd)
{
    ui->setupUi(this);
<<<<<<< HEAD

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}

DialogImportDvd::~DialogImportDvd()
{
    delete ui;
}

void DialogImportDvd::on_buttonBox_accepted()
{

}

bool DialogImportDvd::unzipFile(QString fileGz,QString file)
{
<<<<<<< HEAD


=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    process=new QProcess;
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(readstdout()));
    connect(process,SIGNAL(readyReadStandardError()),this,SLOT(readsteror()));

<<<<<<< HEAD
#ifdef   Q_WS_WIN
    QString tempfile=QDir::homePath()+"/.kirtasse/temp";
    process->setWorkingDirectory(QApplication::applicationDirPath());
    QString extar="7z e \""+fileGz + "\" -o\""+tempfile+"\" *.tar -y ";
    process->start(extar);
    process->waitForFinished();
    process->start("7z x \""+tempfile+"\"/*.tar  -o\""+m_booksPath+"\" -r -y");
    qDebug()<< "7z x "+tempfile+"/*.tar  -o"+m_booksPath+" -r -y";
#else
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QString argument=QString("tar -xvf  %1 -C  %2  %3").arg(fileGz).arg(m_booksPath).arg(file);
    qDebug()<<argument;
    process->start(argument);

<<<<<<< HEAD
#endif


=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    if (!process->waitForStarted())
        return false;

    if (!process->waitForFinished())
        return false;
<<<<<<< HEAD
    QString tempDir=QDir::homePath()+"/.kirtasse/temp";
           QDir dirS(tempDir);
           QString subfile;
           QFile filetemp;
           foreach ( subfile, dirS.entryList(QDir::AllEntries)){

               filetemp.remove(tempDir+"/"+subfile);
           }
    return true;







=======

    return true;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}
void DialogImportDvd::readstdout()
{
    QString  stdoutdata = process->readAllStandardOutput();

    ui->textEditConsole->insertPlainText("\n"+stdoutdata);
    int index= ui->textEditConsole->toPlainText().length();
    QTextCursor cursor(ui->textEditConsole->document());
    cursor.setPosition(index,QTextCursor::MoveAnchor);
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
    ui->textEditConsole->setTextCursor(cursor);
    qApp->processEvents();
    qDebug() <<  stdoutdata;

}
void DialogImportDvd::readsteror()
{

    QString  stdouterror = process->readAllStandardError();
    ui->textEditConsole->insertPlainText("\n"+stdouterror);
    int index= ui->textEditConsole->toPlainText().length();
    QTextCursor cursor(ui->textEditConsole->document());
    cursor.setPosition(index,QTextCursor::MoveAnchor);
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
    ui->textEditConsole->setTextCursor(cursor);
    qApp->processEvents();

    qDebug() <<  stdouterror;
}
void DialogImportDvd::setBooksPath(QString path)
{
    m_booksPath=path;
    ui->lineEditBooksPath->setText(path);
}
<<<<<<< HEAD
    void DialogImportDvd::setAppPath(QString path)
    {
        m_pathApp=path;
            treeChargeGroupe();
    }
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

QString DialogImportDvd::getBooksPath()
{
    return   ui->lineEditBooksPath->text();
}

void DialogImportDvd::on_toolButton_clicked()
{
    QString homeDir=QDir::homePath () ;
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
<<<<<<< HEAD
    if(!dirName.isEmpty()){

     m_groupPath=dirName;
     ui->lineEditDvdPath->setText(dirName);
}
=======
    if(QFile::exists(dirName+"/group.xml")){

     m_groupPath=dirName;
     ui->lineEditDvdPath->setText(dirName);
     treeChargeGroupe( );

}else{
        QMessageBox::information(this,"","group.xml no exist");
    }
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}

void DialogImportDvd::treeChargeGroupe( )
{

    QTreeWidgetItem *itemRoot= new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *itemGroup= new QTreeWidgetItem(itemRoot);
    QTreeWidgetItem *itemBook= new QTreeWidgetItem(itemGroup);
<<<<<<< HEAD
    QFile file(m_pathApp+"/data/group.xml");
  qDebug()<<m_pathApp+"/data/group.xml";
=======
    QFile file(m_groupPath+"/group.xml");
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    file.open(QIODevice::ReadOnly);

    ui->treeWidget->clear();

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
                itemRoot= new QTreeWidgetItem(ui->treeWidget);
                itemRoot->setText(0,textRoot );
                itemRoot->setIcon(0,icon2);
                itemRoot->setCheckState(0,Qt::Unchecked);
            }
        }else if (xml.name() == "Item"){ //niveau 2
            QString idGroup= xml.attributes().value("id").toString();
            QString textGroup= xml.attributes().value("Name").toString();
            if(!textGroup.isNull()){
                itemGroup= new QTreeWidgetItem( itemRoot);
                itemGroup->setText(0,textGroup );
                itemGroup->setIcon(0,icon2);
                itemGroup->setData(2,1,idGroup);

                itemGroup->setCheckState(0,Qt::Unchecked);

            }

<<<<<<< HEAD
        }else if (xml.name() == "bk"){ //
=======
        }else if (xml.name() == "bk"){ //niveau 3
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

            QString idBook= xml.attributes().value("id").toString();
            QString textBook=xml.attributes().value("name").toString();
            QString AutBook= xml.attributes().value("aut").toString();
            QString BetakaBook= xml.attributes().value("betaka").toString();
            //       QString curanBook= xml.attributes().value("tfsr").toString();
            if(!textBook.isNull()){
                itemBook= new QTreeWidgetItem( itemGroup);
                itemBook->setText(0,textBook);
                itemBook->setText(1,AutBook);
                itemBook->setText(2,BetakaBook);
                itemBook->setData(1,1,idBook);
                itemBook->setIcon(0,icon);
                //    itemBook->setData(2,1,curanBook);

                itemBook->setCheckState(0,Qt::Unchecked);

            }
        }
    }
    if (xml.hasError()) {

        QMessageBox::information(0,"",xml.errorString());
    }

    xml.clear();
    file.close();

}

void DialogImportDvd::on_treeWidget_itemChanged(QTreeWidgetItem *item, int )
{
    if (item->checkState(0)==Qt::Checked){
        for(int i=0;i<item->childCount();++i){
            item->child(i)->setCheckState(0,Qt::Checked);
        }
    }else{
        for(int i=0;i<item->childCount();++i){
            item->child(i)->setCheckState(0,Qt::Unchecked);
        }
    }
}

void DialogImportDvd::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok){
        int count=ui->treeWidget->topLevelItemCount();
        button->setEnabled(false);
        qApp->processEvents();
        ui->stackedWidget->setCurrentIndex(1);
        for (int i= 0;i<count;i++){

            QTreeWidgetItem *itemTop=ui->treeWidget->topLevelItem(i);
            int countGroup=itemTop->childCount();
            for(int r=0;r<countGroup;r++){

                QTreeWidgetItem *itemGroup=itemTop->child(r);
                QString idGroup=itemGroup->data(2,1).toString();

                if(QFile::exists(m_groupPath+"/"+idGroup+".tar.gz")){
                    if(itemGroup->checkState(0)==Qt::Checked){
                        ui->textEditConsole->insertPlainText(trUtf8("\n جاري استخراج : ")+itemGroup->text(0));

                        if(unzipFile(m_groupPath+"/"+idGroup+".tar.gz",QString::null)==true)
                            qApp->processEvents();

                    }else{
                        int countBk=itemGroup->childCount();
                        for(int r=0;r<countBk;r++){

                            QTreeWidgetItem *item=itemGroup->child(r);
                            if(item->checkState(0)==Qt::Checked){
                                QString id=item->data(1,1).toString();
                                ui->textEditConsole->insertPlainText(trUtf8("\n جاري استخراج : ")+item->text(0));

                                if(unzipFile(m_groupPath+"/"+idGroup+".tar.gz",id)==true)
                                    qApp->processEvents();
                            }
                        }
                    }
                }

            }
            if(ui->checkBoxGroup->isChecked()){
<<<<<<< HEAD
                QString gPathGroupAllbook=m_pathApp +"/data/group.xml";
=======
                QString gPathGroupAllbook=m_groupPath +"./group.xml";
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
                QString groupPath=QDir::homePath()+"/.kirtasse/data/group.xml";
                QString groupPathNew=QDir::homePath()+"/.kirtasse/data/group.xml.old";
                QFile file;
                if(file.exists(groupPathNew))
                    file.remove(groupPathNew);

                if(file.rename(groupPath,groupPathNew)) {
                    file.copy(gPathGroupAllbook,groupPath);

                }
            }
        }

        QMessageBox::information(this,"",trUtf8("تمت العملية"));
        ui->textEditConsole->insertPlainText(trUtf8("\n انقر على زر الغاء لغلق النافذة "));
        this->accept();
    }

}
<<<<<<< HEAD
void DialogImportDvd::on_toolButtonBooksPath_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks);
if (dirName.isEmpty()||dirName.isNull())
return;

     ui->lineEditBooksPath->setText(dirName);
}
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
