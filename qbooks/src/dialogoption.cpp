#include "dialogoption.h"
#include "ui_dialogoption.h"
#include<QtGui>
Dialogoption::Dialogoption(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialogoption)
{
    ui->setupUi(this);
    m_btnStyleUp= "QPushButton {background-color:";
    m_btnStyleDown=" ;\n    border: 2px solid rgb(0, 170, 127);\n"
            "     border-radius: 4px;\n"
            "min-width: 64px;"
            " ;}\n"
            "QPushButton:hover {\n"
            "      border: 3px solid rgba(85, 170, 255, 200);\n"
            "     border-radius: 4px;\n"
            " }\n"
            " QPushButton:pressed {\n"
            "    border: 3px solid rgba(147, 147, 147, 247)\n"
            "     border-radius: 4px;\n"
            " }";
    QLocale Arabic(QLocale::Arabic);
    Arabic.setNumberOptions(QLocale::OmitGroupSeparator);
    QString txt="1234567890";
    QString s2 = Arabic.toString(txt.toInt());
    ui->comboBoxNumber->addItem(trUtf8("system"));
    ui->comboBoxNumber->addItem(trUtf8("Arabic")+" ("+txt+")");
    ui->comboBoxNumber->addItem(trUtf8("Arabic India")+" ("+s2+")");
    //------------
    ui->comboBoxLng->addItem(trUtf8("النظام"));
    ui->comboBoxLng->addItem(QString::fromUtf8("العربية"));
    ui->comboBoxLng->addItem(QString::fromUtf8("اوردو  باكستان"));
    ui->comboBoxLng->addItem(QString::fromUtf8("english"));
    ui->comboBoxLng->addItem(QString::fromUtf8("francais"));
    //------------
<<<<<<< HEAD
    ui->comboBoxCadre->addItem(QIcon(":/images/image/top.png"),trUtf8("الافتراضي"));
=======
    ui->comboBoxCadre->addItem(trUtf8("الافتراضي"));
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
    QDir dirImage(pathApp+"/data/images");
    QString subdir;
    foreach ( subdir, dirImage.entryList(QDir::AllDirs | QDir::NoDotAndDotDot |
                                         QDir::Hidden )){
<<<<<<< HEAD
        ui->comboBoxCadre->addItem(QIcon(pathApp+"/data/images/"+subdir+"/top.png"),subdir);
=======
        ui->comboBoxCadre->addItem(subdir);
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    }
}
Dialogoption::~Dialogoption()
{

}

void Dialogoption::setArabicNumber(int arg)
{
    ui->comboBoxNumber->setCurrentIndex(arg);
}

int Dialogoption::getArabicNumber()
{
    qDebug()<<"index  "<<ui->comboBoxNumber->currentIndex();
    return  ui->comboBoxNumber->currentIndex();
}


//-------------set------------
void Dialogoption::setFontName(QFont f)
{
    fontName=f;
    //  ui->label_font->setText(  fontName.family()+" "+fontTitleSize);

    QVariant fs=fontName.pointSize();
    ui->label_font->setText(  fontName.family()+" "+ fs.toString());
}
QFont  Dialogoption::getFontName()
{
    return fontName;
}

void Dialogoption::setFontTitleName(QString arg)
{
    fontTitleName=arg;
    ui->label_fontTitle->setText(  fontTitleName+" "+fontTitleSize);

}
QString Dialogoption::getFontTitleName()
{
    return  fontTitleName;
}

void Dialogoption::setLayouDir(bool arg)
{
    ui->checkBoxLngLayou->setChecked(arg);
}
bool Dialogoption::getLayouDir()
{
    return   ui->checkBoxLngLayou->isChecked();
}

void Dialogoption::setColorBack(QString arg)
{
    colorBack=arg;
    ui->pushButton_backcolor->setStyleSheet(m_btnStyleUp+colorBack+m_btnStyleDown);
}
QString Dialogoption::getColorBack()
{
    return colorBack;
}

void Dialogoption::setColorFont(QString arg)
{
    colorFont=arg;
    ui->pushButton_fontcolor->setStyleSheet(m_btnStyleUp+colorFont+m_btnStyleDown);
}
QString Dialogoption::getColorFont()
{
    return colorFont;
}
void Dialogoption::setFontTitleSize(QString arg)
{
    fontTitleSize=arg;
}
QString Dialogoption::getFontTitleSize()
{
    return fontTitleSize;
}

void Dialogoption::setFontHachiaName(QString arg)
{
    fontHachiaName=arg;
    ui->label_fontHachia->setText(fontHachiaName);
}
QString Dialogoption::getFontHachiaName()
{
    return fontHachiaName;
}

void Dialogoption::setFontKhasse(QString arg)
{
    fontKhasse=arg;
    ui->label_fontKhasse->setText(fontKhasse);
}

QString Dialogoption::getFontKhasse()
{
    return fontKhasse;
}
void Dialogoption::setcolorTitle(QString arg)
{
    colorTitle=arg;
    ui->pushButton_titlecolor->setStyleSheet(m_btnStyleUp+colorTitle+m_btnStyleDown);
}
QString Dialogoption::getcolorTitle()
{
    return colorTitle;
}

void Dialogoption::setColorPrefer(QString arg)
{
    colorPrefer=arg;
    ui->pushButton_prefercolor->setStyleSheet(m_btnStyleUp+colorPrefer+m_btnStyleDown);
}

QString Dialogoption::getColorPrefer()
{
    return colorPrefer;
}

void Dialogoption::setColorFind(QString arg)
{
    colorFind=arg;
    ui->pushButton_findcolor->setStyleSheet(m_btnStyleUp+colorFind+m_btnStyleDown);
}
QString Dialogoption::getColorFind()
{
    return colorFind;
}
void Dialogoption::setThemesStyle(QString arg)
{
    themesStyle=arg;
    QStringList styles;
    styles << trUtf8("النظام") <<QStyleFactory::keys() ;
    int df=   styles.indexOf(themesStyle);
    ui->comboBox->addItems(styles);
    ui->comboBox->setCurrentIndex(df);
}

QString Dialogoption::getThemesStyle()
{
    return themesStyle;
}
void Dialogoption:: setPathCostm(QString arg)
{
    pathCostm=arg;
    ui->lineEdit_costmPath->setText(pathCostm);
}
QString Dialogoption::getPathCostm()
{
<<<<<<< HEAD
    return ui->lineEdit_costmPath->text();
=======
    return pathCostm;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
}
void Dialogoption::setCadreFolder(QString arg)
{
    cadreFolder=arg;
    int fg=  ui->comboBoxCadre->findText(cadreFolder,Qt::MatchExactly);
    ui->comboBoxCadre->setCurrentIndex(fg);
}
QString Dialogoption::getCadreFolder()
{
    return cadreFolder;
}

void Dialogoption::setWebCadre(bool arg)
{
    ui->checkBoxCadre->setChecked(arg);
}
bool Dialogoption::getWebCadre()
{
    return ui->checkBoxCadre->isChecked();
}

void Dialogoption::setIconsThemes(bool arg)
{
    ui->checkBoxThemes->setChecked(arg);
}
bool Dialogoption::getIconsThemes()
{
    return ui->checkBoxThemes->isChecked();
}
void Dialogoption::setRecentNbr(int arg)
{
    ui->spinBox_3->setValue(arg);
}
int Dialogoption::getRecentNbr()
{
    return ui->spinBox_3->value();
}
void Dialogoption::setLng(int arg)
{
    ui->comboBoxLng->setCurrentIndex(arg);
}
int Dialogoption::getLng()
{
    return ui->comboBoxLng->currentIndex();
}
<<<<<<< HEAD
void Dialogoption::setStandardTool(bool st)
{
    ui->checkBoxStandardTool->setChecked(st);
}
 bool Dialogoption::getsetStandardTool()
 {
     return ui->checkBoxStandardTool->isChecked();
 }
 void Dialogoption::setTxtUnderIcon(bool istxt)
 {
     ui->checkBoxTxtUnderIcon->setChecked(istxt);
 }

 bool Dialogoption::getTxtUnderIcon()
 {
     return  ui->checkBoxTxtUnderIcon->isChecked();
 }

 void Dialogoption::setIconSize(int s)
 {
     ui->spinBoxIconSize->setValue(s);
 }

 int Dialogoption::getIconSize()
 {
     return ui->spinBoxIconSize->value();
 }

 void Dialogoption::setStyleType(bool arg)
 {
     ui->checkBoxStyleCostum->setChecked(arg);
 }

 bool Dialogoption::getStyleType()
 {
     return ui->checkBoxStyleCostum->isChecked();
 }

 void Dialogoption::setStyleSheetName(QString arg)
 {
     ui->lineEditStyleCostum->setText(arg);
 }

 QString Dialogoption::getStyleSheetName()
 {
     return ui->lineEditStyleCostum->text();
 }
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

//----------------end set get variable---------------------------------------------------------
void Dialogoption::on_pushButton_fontcolor_clicked()
{
    QColor couleur = QColorDialog::getColor(colorFont, this,trUtf8("اختيار لون خط النص"),QColorDialog::DontUseNativeDialog);
    if( couleur.isValid()){
        colorFont= couleur.name();
        ui->pushButton_fontcolor->setStyleSheet(m_btnStyleUp+ couleur.name()+m_btnStyleDown);
    }
}

void Dialogoption::on_pushButton_titlecolor_clicked()
{
    QColor couleur = QColorDialog::getColor(colorTitle, this,trUtf8("اختيار لون العناوين"),QColorDialog::DontUseNativeDialog);
    if( couleur.isValid()){
        colorTitle= couleur.name();
        ui->pushButton_titlecolor->setStyleSheet(m_btnStyleUp+ couleur.name()+m_btnStyleDown);
    }
}

void Dialogoption::on_pushButton_prefercolor_clicked()
{
    QColor couleur = QColorDialog::getColor(colorPrefer, this,trUtf8("اختيار لون الترميز"),QColorDialog::DontUseNativeDialog);
    if( couleur.isValid()){
        colorPrefer= couleur.name();
        ui->pushButton_prefercolor->setStyleSheet(m_btnStyleUp+ couleur.name()+m_btnStyleDown);
    }
}

void Dialogoption::on_pushButton_findcolor_clicked()
{
    QColor couleur = QColorDialog::getColor(colorFind, this,trUtf8("اختيار لون ترميز البحث"),QColorDialog::DontUseNativeDialog);
    if( couleur.isValid()){
        colorFind= couleur.name();
        ui->pushButton_findcolor->setStyleSheet(m_btnStyleUp+ couleur.name()+m_btnStyleDown);
    }
}

void Dialogoption::on_pushButton_backcolor_clicked()
{
    QColor couleur = QColorDialog::getColor(colorBack, this,trUtf8("اختيار لون خلفية النص"),QColorDialog::DontUseNativeDialog);
    if( couleur.isValid()){
        colorBack= couleur.name();
        ui->pushButton_backcolor->setStyleSheet(m_btnStyleUp+ couleur.name()+m_btnStyleDown);
    }
}

void Dialogoption::on_toolButton_clicked()
{
    bool ok = false;
    QFont police =QFontDialog::getFont(&ok, fontName, this,trUtf8("اختيار خط الصفحة"));
    if (ok)
    {
        fontName=(police);
        QVariant fs=police.pointSize();
        ui->label_font->setText(police.family()+" "+fs.toString());
    }
}

void Dialogoption::on_buttonBox_accepted()
{

<<<<<<< HEAD
    themesStyle=ui->comboBox->currentText();

     pathCostm= ui->lineEdit_costmPath->text();

    cadreFolder=ui->comboBoxCadre->currentText();

=======
  themesStyle=ui->comboBox->currentText();

    //    pathCostm= ui->lineEdit_costmPath->text();

    cadreFolder=ui->comboBoxCadre->currentText();


>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    //layouDir=ui->checkBoxLngLayou->checkState();
}

void Dialogoption::on_toolButton_costmPath_clicked()
{
    QFileDialog dlg;
    QString homeDir=QDir::homePath () ;
    QString dir = dlg.getExistingDirectory(this, tr("Open Directory"),
                                           homeDir,
                                           QFileDialog::ShowDirsOnly
                                           |QFileDialog::DontResolveSymlinks);
<<<<<<< HEAD
   if(!dir.isEmpty())
=======
    if(dlg.AcceptOpen)
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
        ui->lineEdit_costmPath->setText(dir);

}

void Dialogoption::on_toolButton_2_clicked()
{
    bool ok = false;
    QVariant fs=fontTitleSize;
    QFont police =QFontDialog::getFont(&ok, QFont(fontTitleName, fs.toInt()), this,trUtf8("اختيار خط عنوان الصفحة"));
    if (ok)
    {

        fs=police.pointSize();
        fontTitleSize=fs.toString();
        fontTitleName=(police.family());
        ui->label_fontTitle->setText(police.family()+" "+fs.toString());
    }
}

void Dialogoption::on_toolButton_3_clicked()
{
    bool ok = false;
    QFont police =QFontDialog::getFont(&ok, fontHachiaName, this,trUtf8("اختيار خط حاشية الصفحة"));
    if (ok)
    {
        fontHachiaName=(police.family());
        ui->label_fontHachia->setText(police.family());
    }
}

<<<<<<< HEAD
//void Dialogoption::on_comboBoxCadre_currentIndexChanged(QString img )
//{
//    QDir appDir(qApp->applicationDirPath());
//    appDir.cdUp();
//    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
//    QString image=pathApp+"/data/images/"+img+"/preview.png";
//    QFile file(image);
//    if (file.exists()){
//        ui->labelCadre->setPixmap(image);
//    }else{
//        ui->labelCadre->setText(trUtf8("المعاينة غير متوفرة"));
//    }

//}
=======
void Dialogoption::on_comboBoxCadre_currentIndexChanged(QString img )
{
    QDir appDir(qApp->applicationDirPath());
    appDir.cdUp();
    QString pathApp=  appDir.absolutePath()+"/share/elkirtasse";
    QString image=pathApp+"/data/images/"+img+"/preview.png";
    QFile file(image);
    if (file.exists()){
        ui->labelCadre->setPixmap(image);
    }else{
        ui->labelCadre->setText(trUtf8("المعاينة غير متوفرة"));
    }

}
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

void Dialogoption::on_toolButton_10_clicked()
{
    bool ok = false;
    QFont police =QFontDialog::getFont(&ok, fontHachiaName, this,trUtf8("اختيار خط حاشية الصفحة"));
    if (ok)
    {
        fontKhasse=(police.family());
        ui->label_fontKhasse->setText(police.family());
    }
}
<<<<<<< HEAD



void Dialogoption::on_checkBoxStandardTool_clicked()
{
       QMessageBox::information(0,"",trUtf8("سيتم تطبيق التغيير بعد اعادة تشغيل التطبيق"));
}

void Dialogoption::on_toolButtonStyleCostum_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    ui->lineEditStyleCostum->text(),
                                                    tr("Style (*.qss  );;All files (*.*)"));
    if(!fileName.isEmpty())
        ui->lineEditStyleCostum->setText(fileName);
}
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
