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
#include "print.h"
#include  "ui_print.h"
#include <QtGui>
#include <QMessageBox>
Print::Print(QWidget *parent)
    : QDialog(parent), ui(new Ui::Print)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    mCurPart=1;
    QLocale Arabic(QLocale::Arabic);
    Arabic.setNumberOptions(QLocale::OmitGroupSeparator);
    QString txt="1234567890";
    QString s2 = Arabic.toString(txt.toInt());
    ui->comboBoxNumber->addItem(trUtf8("system"));
    ui->comboBoxNumber->addItem(trUtf8("Arabic")+" ("+txt+")");
    ui->comboBoxNumber->addItem(trUtf8("Arabic India")+" ("+s2+")");
    ui->checkBox->setVisible(false);
    ui->radioButton_part->setVisible(false);
    ui->radioButton_nbr->setVisible(false);
    ui->spinBox->setVisible(false);

}
Print::~Print()
{

}
void Print::setpathApp(QString path)
{
    m_pathApp=path;
}

void Print::setBookTitle(QString name)
{
    m_bookTitle=name;
}

void Print::setBookAuthor(QString name)
{
    m_bookAuthor=name;
}

void Print::setBookBetaka(QString name)
{
    m_bookBetaka=name;
}

void Print::setBookColorBack(QString name)
{
    m_WebColorBack=name;
}

void Print::setBookFont(QString name)
{
    m_WebFont=name;
}

void Print::setBookFontColor(QString name)
{
    m_WebFontColor=name;
}

void Print::setBookFontTitleColor(QString name)
{
    m_WebFontTitleColor=name;
}

void Print::setBookFontPrefertColor(QString name)
{
    m_WebFontPrefertColor=name;
}

void Print::setBookCurentPath(QString name)
{
    m_curentPath=name;
}

void Print::setBookFontTitle(QString name)
{
    m_WebFontTitle=name;
}

void Print::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->comboBoxNumber->currentIndex()==1){
        this->setLocale(QLocale(QLocale::Latin));
    } else if(ui->comboBoxNumber->currentIndex()==2) {
        this->setLocale(QLocale(QLocale::Arabic));
    }

    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok)
    {
        if (ui->comboBox->currentIndex()==2)
        {
            int reponse = QMessageBox::information(this, trUtf8("تنبيه"), trUtf8("ان حفظ الكتاب بهذه الصيغة يأخذ وقتا أطول سيما اذا كان الكتاب كبيرا \n هل تريد المتابعة؟") , QMessageBox::Yes | QMessageBox::Cancel);
            if (reponse == QMessageBox::Cancel){
                return;
            }
        }
        QDir dir(ui->lineEdit->text());
        if (!dir.exists())
        {
            return;
        }
        if( dir.mkdir(m_bookTitle)==false)
        {
            QMessageBox::critical(this,trUtf8("خطأ"), trUtf8(" لا يمكن انشاء الملف في هذا الدليل اختر دليلا اخر"));
            return;
        }

        m_fileName=ui->lineEdit->text()+"/"+m_bookTitle+"/"+m_bookTitle+"_";
        ui->frame->setVisible(true);
        button->setEnabled(false);
        ui->frame_2->setEnabled(false);
        if (openBook()==true){
            if (ui->comboBox->currentIndex()==0){

                creatHtmlDocument(false);
            }else if (ui->comboBox->currentIndex()==3){
                creatEpubDocument();
            }else if (ui->comboBox->currentIndex()==4){
                creatHtmlDocument(true);
            }else{
                creatDocument();
            }

        }
    }
}
bool Print::openBook()
{
    // QString path=QCoreApplication::applicationDirPath ();
    //  QString path=curentPath;
    QString bkpath=m_curentPath +"/book.xml";           //مسار الكتاب
    QFile file(bkpath);
    if( !file.open(QIODevice::ReadOnly))                            //فتح الملف
    {
        return false;
    }

    m_docBooK.clear();                                                    //تفريغ الذاكرة
    if (!m_docBooK.setContent(&file))                                      //اذا كانت البيانات صحيحة
    {
        return false;
    }

    QDomElement racine = m_docBooK.documentElement(); //renvoie la balise racine
    QVariant i = racine.childNodes().count();
    rowsCount=i.toInt();
    file.close();

    return true;
}

void Print::creatDocument()
{
    int counter=0;
    QString bgr="<body";
    if (ui->checkBox_bgr->isChecked())
    {
        bgr=bgr="<body  bgcolor='"+m_WebColorBack+"'";
    }
    QString bgrcolor = "<html dir=rtl ><head><title>مكتبة القرطاس :"+m_bookTitle+"</title></head>"+bgr+">< font color='"+m_WebFontColor+"' >";
    QString image="<p align=\"center\"><img src=\":/images/image/groupbook.png\" /></p>";
    QString title="<font size='6'color='"+m_WebFontTitleColor+"' ><p align=\"center\">"+m_bookTitle+"</p></font>";
    QString hothor="<font size='3' ><p align=\"center\">"+m_bookAuthor+"</p></font><p align=\"right\"></p>";

    QFont font;
    font.fromString(m_WebFont);

    m_textEdit=new QTextEdit(this);
    m_textEdit->setLayoutDirection(Qt::RightToLeft);
    m_textEdit->setAlignment(Qt::AlignRight);
    m_textEdit->setFont(font);
    m_textEdit->setHtml(bgrcolor);
    m_textEdit->insertHtml(image+title+hothor);

    ui->progressBar->setMaximum(rowsCount);

    QDomElement racine = m_docBooK.documentElement();
    for (int i=0;i<rowsCount;i++)
    {
        counter=counter+1;
        ui->progressBar->setValue(i);
        QDomNode noeud = racine.childNodes().item(i);
        QString  bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString  bookPage= noeud.firstChildElement("page").firstChild().toText().data();
        QString  bookPart=  noeud.firstChildElement("part").firstChild().toText().data();

        if (ui->radioButton_part->isChecked())
        {
            if (!(bookPart.isNull()) || !(bookPart.isEmpty()) || !(bookPart=="0"))
            {

                if (bookPart.toInt()>mCurPart)
                {
                    if (fileSave()==false)
                    {
                        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
                        return;
                    }
                    mCurPart=mCurPart+1;
                    m_textEdit->clear();
                    m_textEdit->setHtml(bgrcolor);
                    m_textEdit->insertHtml(image+title+hothor);
                }
            }
        } else{
            if (counter==ui->spinBox->value())
            {
                if (fileSave()==false)
                {
                    QMessageBox::information(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
                    return;
                }
                counter=0;
                mCurPart=mCurPart+1;
                m_textEdit->clear();
                m_textEdit->setHtml(bgrcolor);
                m_textEdit->insertHtml(image+title+hothor);
            }

        }
        m_textEdit->insertHtml( convertText("<br>"+bookNass,bookPart,bookPage,i+1));
    }

    if (fileSave()==false)
    {
        QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن حفظ الملف"));
        return;
    }
    QMessageBox::information(this,trUtf8("حفظ"), trUtf8("تمت عملية الحفظ بنجاح"));
    this->reject();
}
QString Print::convertTextBetaka(QString txt)
{
    txt.replace(QByteArray("\n"), QByteArray("<br>"));
    txt.replace(QByteArray("\r"), QByteArray("<br>"));
    return txt;
}

QString Print::convertText(QString txt,QString part,QString page, int id)
{

    txt.replace(QByteArray("\n"), QByteArray("<br>"));
    txt.replace(QByteArray("\r"), QByteArray("<br>"));
    //*******************************************
    // QString id=DataBook->bookCurentId[m_currentBookIndex];
    if (txt.contains("$")){
        txt.replace("$", "");
    }

    QLocale lc(this->locale().name());
    lc.setNumberOptions(QLocale::OmitGroupSeparator);
    //      qDebug()<<this->locale().name();
    QRegExp rxD("(\\d+)");
    int pos = 0;
    while ((pos = rxD.indexIn(txt, pos)) != -1) {
        txt.remove(pos,rxD.matchedLength());
        txt.insert(pos,lc.toString(rxD.cap(1).toInt()));
        pos += rxD.matchedLength();
    }
    QVariant dd=id;
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            treeviw->findItems(
                dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);//تنشاء قائمة بكل العناصر

    foreach (item, found){

        //    QMessageBox::information(this,trUtf8("llop"),item->text(0));
        txt.replace( item->text(0)+"<br>","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
        txt.replace("  "+ item->text(0),"<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'><br> "+item->text(0)+"</font><br>");
        txt.replace("<br>"+ item->text(0),"<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'><br> "+item->text(0)+"</font><br>");
        txt.replace( item->text(0)+"<br>","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
        txt.replace( item->text(0)+" <br>","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
        txt.replace( item->text(0)+" :","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+" :</font><br>");
        txt.replace( item->text(0)+".","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+". </font><br>");

        if(txt.trimmed()== item->text(0).trimmed()){
            txt="< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"' > "+item->text(0)+" </font>";
        }
    }

    //********************************************

    txt.replace("صلى الله عليه وسلم","<font color='"+m_WebFontPrefertColor+"' >صلى الله عليه وسلم</font> ");
    txt.replace("C تعالى","<font color='"+m_WebFontPrefertColor+"' >رحمه الله تعالى</font> ");
    txt.replace("{","<font color='"+m_WebFontPrefertColor+"' >﴿</font> ");
    txt.replace("}","<font color='"+m_WebFontPrefertColor+"' >﴾</font> ");
    txt.replace("رضي الله عنهم ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنهم </font> "));
    txt.replace("رضي الله عنه ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
    txt.replace("رضي الله عنهما ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("' >رضي الله عنهما </font> "));
    txt.replace(" A ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'> صلى الله عليه سلم </font> "));
    txt.replace("Bه",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
    txt.replace(" D ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>  تعالى </font> "));
    txt.replace(" E ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'> عليه السلام </font> "));

    if (txt.contains("**")){
        QRegExp rx("(\\d\\d? )[(]");
        txt.replace(rx,"<br>(");
        QRegExp rx1("(\\d\\d?)[(]");
        txt.replace(rx1,"<br>(");
        txt.replace(") (",")<br>(");
        txt.replace(")(",")<br>(");
    }
    txt.replace("<br><br>","<br>");
    txt.replace("<br> <br>","<br>");
    txt.replace("<br>  <br>","<br>");

    QRegExp rxi("_____+");
    QRegExp rxd("ـــــ+");
    txt.replace(rxi," <font size='1'><br>__________");
    txt.replace(rxd," <font size='1'><br>__________");

    if (ui->checkBox->isChecked())
    {
        txt.insert(txt.length(),"<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
        //   m_textEdit->insertHtml("<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
    }

    return txt;

}

void Print::on_toolButton_clicked()
{
    QString homeDir=QDir::homePath () ;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    homeDir,
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks
                                                    |QFileDialog::ReadOnly);
    ui->lineEdit->setText(dir);
}



bool Print::fileSave()
{
    QVariant d=mCurPart;
    QString fileName;
    if (ui->comboBox->currentIndex()==2)
    {
        fileName=m_fileName+d.toString()+".pdf";
#ifndef QT_NO_PRINTER
        QPrinter printer(QPrinter::ScreenResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

        m_textEdit->document()->print(&printer);

        QApplication::restoreOverrideCursor();
#endif
        return true;
    }else if(ui->comboBox->currentIndex()==1){
        fileName=m_fileName+d.toString()+".odf";
        QTextDocumentWriter writer(fileName);
        bool success = writer.write(m_textEdit->document());
        if (success)
            return success;
    }else{
        fileName=m_fileName+d.toString()+".html";
        QTextDocumentWriter writer(fileName);
        bool success = writer.write(m_textEdit->document());
        if (success)
            return success;
    }
    return true;

}
///----------------------------------------epub-------------------------------------------------------
void Print::creatEpubDocument()
{


    //! [0]
    if(creatEpubDIrectory()==false){
        QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
        return;
    }
    //! [1]
    if(creatEpubContent()==false){
        QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
        return;
    }
    //! [2]
    if(creatEpubToc()==false){
        QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
        return;
    }
    //! [3]
    if(creatEpubInfo()==false){
        QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
        return;
    }
    //! [4]
    if(creatEpubPages()==true){
        zipUpubDocument();
    }
    QString epubFile=ui->lineEdit->text()+"/"+m_bookTitle+".epub";
    QFile file(epubFile);
    if(file.exists()){
        QMessageBox::information(this,"",trUtf8("تم انشاء : ")+epubFile);
    }else{
        QMessageBox::information(this,"",trUtf8("خطأ غير متوقع في انشاء الملف : "));
    }
}
//! [0]
bool Print::creatEpubDIrectory()
{
    QDir dir(ui->lineEdit->text()+"/"+m_bookTitle);
    if (!dir.exists())
    {
        return false;
    }
    if( dir.mkdir("OEBPS")==false){
        //     QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    if( dir.mkdir("OEBPS/xhtml")==false){
        //  QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    if( dir.mkdir("OEBPS/img")==false){
        //    QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    if( dir.mkdir("META-INF")==false){
        //  QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    //save logo
    QPixmap pixlogo(266,245);
    pixlogo.fill(Qt::transparent);
    QPixmap pix1(":/images/image/groupbook.png");
    QPixmap pix2(":/images/image/titlekirtasse.png");
    QPainter p;
    p.begin(&pixlogo);
    p.drawPixmap(69,0,128,128,pix1);
    p.drawPixmap(0,128,266,117,pix2);
    p.end();
    pixlogo.save(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/img/logo.png");
    //save mimetype
    QFile file(ui->lineEdit->text()+"/"+m_bookTitle+"/mimetype");
    if (!file.open(QFile::WriteOnly))
        return false;
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    out<<"application/epub+zip";
    //save container.xml
    file.close();
    file.setFileName(ui->lineEdit->text()+"/"+m_bookTitle+"/META-INF/container.xml");
    if (!file.open(QFile::WriteOnly))
        return false;
    QTextStream out1(&file);
    out1.setCodec(QTextCodec::codecForName("UTF-8"));
    out1<<"<?xml version=\"1.0\"?>"
          "<container version=\"1.0\" xmlns=\"urn:oasis:names:tc:opendocument:xmlns:container\">"
          "<rootfiles>"
          "<rootfile full-path=\"OEBPS/content.opf\" media-type=\"application/oebps-package+xml\"/>"
          "</rootfiles>"
          "</container>";
    file.close();
    file.setFileName(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/style.css");
    if (!file.open(QFile::WriteOnly))
        return false;
    QTextStream out2(&file);
    out2.setCodec(QTextCodec::codecForName("UTF-8"));
    out2<< "body {direction: rtl; margin: 2%; background-color: #FEFBE7; }"
           " body.rtl { direction: rtl; text-align: right; }"
           "body.ltr { direction: ltr; text-align: justify; } "
           "#book-container {  }"
           "#book-container span.matn { color: #0000AF; } "
           "#book-container span.title { color: #A52A2A; font-weight: bold; }"
           "#book-container span.prifired { color: #007200; } "
           "#book-container span.red { color: #FF0000; }"
           "#book-container span.footnote { color: #665555; font-size: 0.9em; } "
           "#book-container span.footnote-hr { font-size: 1px; display: block; width: 25%; border-bottom: 1px solid #665555; }"
           "#book-container span.matn-hr { font-size: 1px; display: block; width: 95%; border-bottom: 3px solid #000000; margin: 0pt auto; } .center { text-align:center;display:block; } .info-item { display: block; margin-bottom: 5px; } .info-title { display: inline-block; width: 25%; font-weight: bold; vertical-align: top; } .info-desc { display: inline-block; width: 55%; vertical-align: top; } ";
    file.close();
    return true;
}

//! [1]
bool Print::creatEpubContent()
{
    QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/content.opf");

    if (!fileContent.open(QFile::WriteOnly)){
        return false;
    }
    QTextStream out(&fileContent);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out <<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    out <<  "<package xmlns=\"http://www.idpf.org/2007/opf\" unique-identifier=\"BookID\" version=\"2.0\">";
    out << "<metadata xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:opf=\"http://www.idpf.org/2007/opf\">";
    out <<   "<dc:title>"+m_bookTitle+"</dc:title>";
    out << "<dc:creator opf:role=\"aut\">"+m_bookAuthor+"</dc:creator>";
    out <<  "<dc:publisher>http://elkirtasse.ws</dc:publisher>";
    out <<    "<dc:language>ar</dc:language>";
    out <<   "<dc:identifier id=\"BookID\" opf:scheme=\"UUID\">urn:uuid:f38f5e73c5be19930ef2d0b440d52b34</dc:identifier>";
    out <<  "</metadata>";
    out << "<manifest>";
    out <<"<item id=\"ncx\" href=\"toc.ncx\" media-type=\"application/x-dtbncx+xml\"/>";
    out << "<item id=\"stylesheet\" href=\"style.css\" media-type=\"text/css\"/>";
    out <<   "<item id=\"logo\" href=\"img/logo.png\" media-type=\"image/png\"/>";
    out <<   "<item id=\"info\" href=\"xhtml/info.xhtml\" media-type=\"application/xhtml+xml\"/>";

    for(int i=0;i<rowsCount;i++){
        QString txt=QString("<item id=\"P%1\" href=\"xhtml/P%1.xhtml\" media-type=\"application/xhtml+xml\"/>").arg(QString::number(i+1));
        out <<txt+"\n";
    }
    out <<"</manifest>";
    out <<"<spine toc=\"ncx\">";
    out <<   "<itemref idref=\"info\"/>";

    for(int i=0;i<rowsCount;i++){
        QString txt=QString("<itemref idref=\"P%1\"/>").arg(QString::number(i+1));
        out <<txt;
    }
    out <<"</spine>";
    out <<"</package>";

    fileContent.close();
    return true;
}
//! [1]
//! [2]
bool Print::creatEpubToc()
{
    QString bkinf=trUtf8("بطاقة الكتاب");
    QFile fileToc(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/toc.ncx");

    if (!fileToc.open(QFile::WriteOnly)){
        return false;
    }
    QTextStream out(&fileToc);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out <<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    out << "<!DOCTYPE ncx PUBLIC \"-//NISO//DTD ncx 2005-1//EN\"  \"http://www.daisy.org/z3986/2005/ncx-2005-1.dtd\">";
    out <<"<ncx xmlns=\"http://www.daisy.org/z3986/2005/ncx/\" version=\"2005-1\">";
    out <<"<head>";
    out <<"<meta name=\"dtb:uid\" content=\"f38f5e73c5be19930ef2d0b440d52b34\"/>";
    out << "<meta name=\"dtb:depth\" content=\"2\"/>";
    out <<  "<meta name=\"dtb:totalPageCount\" content=\"0\"/>";
    out <<  "<meta name=\"dtb:maxPageNumber\" content=\"0\"/>";
    out <<"</head>";
    out << " <docTitle>";
    out << " <text>"+m_bookTitle+"</text>";
    out << "</docTitle>";
    out << "<docAuthor>";
    out << "<text>"+m_bookAuthor+"</text>";
    out << "</docAuthor>";
    out <<"<navMap><navPoint id=\"info\" playOrder=\"1\"><navLabel><text>"+bkinf+"</text></navLabel><content src=\"xhtml/info.xhtml\"/></navPoint>";
    //---get-fahariss
    int countTop=treeviw->topLevelItemCount();
    m_n=1;
    for (int i=0 ;i<countTop;i++){
        m_n++;
        QTreeWidgetItem *item=treeviw->topLevelItem(i);
        QString order=QString::number(m_n);
        QString id=item->data(1,1).toString();
        QString txt=item->text(0);
        out << "<navPoint id=\"C"+order+"\" playOrder=\""+order+"\"><navLabel><text>"+txt+".</text></navLabel><content src=\"xhtml/P"+id+".xhtml\"/>";
        //child her----------------------------
        out <<getChildNavpoint(item);
        out << "</navPoint>";
    }
    out <<"</navMap></ncx>";
    fileToc.close();
    return true;
}
//! [2] [0]
QString Print::getChildNavpoint(QTreeWidgetItem *item)
{
    QString txtNav;
    int count=item->childCount();
    for (int i=0 ;i<count;i++){
        m_n++;
        QTreeWidgetItem *itemChild=item->child(i);
        QString order=QString::number(m_n);
        QString id=itemChild->data(1,1).toString();
        QString txt=itemChild->text(0);

        txtNav.insert(txtNav.length(), "<navPoint id=\"C"+order+"\" playOrder=\""+order+"\"><navLabel><text>"+txt+".</text></navLabel><content src=\"xhtml/P"+id+".xhtml\"/>");
        //child her----------------------------
        txtNav.insert(txtNav.length(), getChildNavpoint(itemChild));
        txtNav.insert(txtNav.length(), "</navPoint>");
    }
    return txtNav;
}
//! [2]
//! [3]
bool Print::creatEpubInfo()
{
    QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/xhtml/info.xhtml");

    if (!fileContent.open(QFile::WriteOnly)){
        return false ;
    }
    QString elkirtasse=trUtf8("مكتبة القرطاس");
    QTextStream out(&fileContent);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    out << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n";

    out << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n";
    out << "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n";
    out << "<head>\n";
    out << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>\n";
    out << "<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />\n";
    out <<"<title>"+m_bookTitle+"</title>\n";
    out <<  "</head>\n";
    out <<  "<body  dir=\"RTL\"  class=\"rtl\">\n";
    out <<"<div id=\"book-container\">\n";
    // out <<"<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\" ><tr><td style=\"text-align:center; \" >";
    // out << "<div class=\"center\"><img src=\"../img/logo.png\" style=\"margin:4px;\" alt=\""+elkirtasse+"\" /></div> \n";
    //   out << "</td> </tr></table>";

    out << "<CENTER>";
    out <<   "<TABLE  CELLPADDING=4 CELLSPACING=0>";
    out <<      "<COL WIDTH=100%>";
    out <<     "<TR>";
    out <<         "<TD WIDTH=100% VALIGN=TOP STYLE=\"border: 1px solid #000000; padding: 0.1cm\">";
    out <<          "<P ALIGN=CENTER><IMG SRC=\"../img/logo.png\"  ALIGN=CENTER  BORDER=0>";
    out <<            "</P>";
    out <<       "</TD>";
    out <<    "</TR>";
    out <<  "</TABLE>";
    out <<   "</CENTER>";

    out << "<div class=\"rtl\">";
    out << "<h1  class=\"title center\">"+m_bookTitle+"</h1>\n";
    out <<  "<h2 span class=\"center\">"+m_bookAuthor+"</span></h2>\n";
    out <<  "<h2 span class=\"info-desc\"> "+convertTextBetaka(m_bookBetaka)+"</span></h2>\n";
    out <<   "</div>\n</body>\n</html>";
    fileContent.close();
    return true;
}
//! [3]
//! [4]
bool Print::creatEpubPages()
{
    QString txtContent1="<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"
            "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
            " <html xmlns=\"http://www.w3.org/1999/xhtml\">"
            "<head>"
            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>"
            "<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />"
            "<title>"+m_bookTitle+"</title>"
            "</head>"
            "<body dir=\"RTL\"  class=\"rtl\">"
            "<div id=\"book-container\">";
    QString txtContent2="</div>"
            "</body>"
            "</html>";

    ui->progressBar->setMaximum(rowsCount);
    QDomElement racine = m_docBooK.documentElement();
    for (int i=0;i<rowsCount;i++)
    {

        ui->progressBar->setValue(i);
        QDomNode noeud = racine.childNodes().item(i);
        QString  bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString  bookPage= noeud.firstChildElement("page").firstChild().toText().data();
        QString  bookPart=noeud.firstChildElement("part").firstChild().toText().data();
        // QString Content= bookNass;// convertText(bookNass,bookPart,bookPage,i+1);
        QString Content= convertEpubStyle(bookNass,bookPart,bookPage,i+1);
        QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/xhtml/P"+QString::number(i+1)+".xhtml");

        if (!fileContent.open(QFile::WriteOnly)){
            return false;
        }
        QTextStream out(&fileContent);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out << txtContent1;
        out << Content;
        out << txtContent2;
        fileContent.close();
    }
    ui->progressBar->setValue(rowsCount);
    return true;
}
//! [4]
//! [4] [0]
QString Print::convertEpubStyle(QString txt,QString part,QString page, int id)
{

    txt.replace(QByteArray("\n"), QByteArray("<br />"));
    txt.replace(QByteArray("\r"), QByteArray("<br />"));
    //*******************************************

    if (txt.contains("$")){
        txt.replace("$", "");
    }


    QVariant dd=id;
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            treeviw->findItems(
                dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);//تنشاء قائمة بكل العناصر

    foreach (item, found){

        txt.replace( item->text(0)+"<br />","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace("  "+ item->text(0),"<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace("<br />"+ item->text(0),"<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+"<br />","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+" <br />","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+" :","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+".","<span class=\"title\">"+item->text(0)+"</span><br />");

        if(txt.trimmed()== item->text(0).trimmed()){
            txt="<span class=\"title\">"+item->text(0)+"</span><br />";
        }
    }

    //********************************************
    QRegExp rxi("_____+");
    QRegExp rxd("ـــــ+");
    bool hachia=false;
    if(txt.contains(rxi)|| txt.contains(rxd)){
        txt.replace(rxi," <span class=\"footnote-hr\">&nbsp;</span><span class=\"footnote\">");
        txt.replace(rxd,"  <span class=\"footnote-hr\">&nbsp;</span><span class=\"footnote\">");
        hachia=true;
    }




    txt.replace("صلى الله عليه وسلم","<span class=\"prifired\">صلى الله عليه وسلم</span>");
    txt.replace("C تعالى","<span class=\"prifired\">رحمه الله تعالى</span>");
    txt.replace("{","<span class=\"prifired\">﴿</span>");
    txt.replace("}","<span class=\"prifired\">﴾</span>");
    txt.replace("رضي الله عنهم ","<span class=\"prifired\">رضي الله عنهم </span>");
    txt.replace("رضي الله عنه ","<span class=\"prifired\">رضي الله عنه </span>");
    txt.replace("رضي الله عنهما ","<span class=\"prifired\">رضي الله عنهما </span>");
    txt.replace(" A ","<span class=\"prifired\">صلى الله عليه وسلم</span>");
    txt.replace("Bه","<span class=\"prifired\">رضي الله عنه </span>");
    txt.replace(" D ","<span class=\"prifired\"> تعالى  </span>");
    txt.replace(" E ","<span class=\"prifired\"> عليه السلام </span>");

    if (txt.contains("**")){
        QRegExp rx("(\\d\\d? )[(]");
        txt.replace(rx,"<br />(");
        QRegExp rx1("(\\d\\d?)[(]");
        txt.replace(rx1,"<br />(");
        txt.replace(") (",")<br />(");
        txt.replace(")(",")<br />(");
    }
    txt.replace("<br /><br />","<br />");
    txt.replace("<br /> <br />","<br />");
    txt.replace("<br />  <br />","<br />");

    if(hachia==true)
        txt.insert(txt.length(),"</span>");

    if (ui->checkBox->isChecked())
    {
        QString gg=" الجزء: "+part+" /الصفحة : "+page;
        txt.insert(txt.length(),"<br /><br /><br /><div class=\"center\">"+gg +"</div>");
        //   txt.insert(txt.length(),"<br><font size='1' ><p> __________ الجزء: "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
        //   m_textEdit->insertHtml("<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
    }

    QLocale lc(this->locale().name());
    // qDebug()<<this->locale().name();
    QRegExp rxD("(\\d+)");
    lc.setNumberOptions(QLocale::OmitGroupSeparator);
    int pos = 0;

    while ((pos = rxD.indexIn(txt, pos)) != -1) {

        txt.remove(pos,rxD.matchedLength());
        txt.insert(pos,lc.toString(rxD.cap(1).toInt()));


        pos += rxD.matchedLength();
    }
    return txt;

}
bool Print::zipUpubDocument()
{
/*
    QProcess prosses;
    QString pathToAdd="  \""+ui->lineEdit->text()+"/"+m_bookTitle+"/*\"";

    QString fileName="\""+ui->lineEdit->text()+"/"+m_bookTitle+".zip\"";


    if(QFile::exists("/usr/bin/7z")){
        prosses.start("7z a  "+fileName+" "+pathToAdd);
    }else if(QFile::exists("/usr/bin/zip")){
        prosses.setWorkingDirectory(ui->lineEdit->text()+"/"+m_bookTitle+"/");
        prosses.start("zip -r "+fileName+" . -i \*");
    }else{
        QMessageBox::information(this,"",("please install 7z or zip "));
        return false;
    }
    prosses.waitForFinished();


    QString epubfileName="\""+ui->lineEdit->text()+"/"+m_bookTitle+".epub\"";
    QString pathTodDelet="\""+ui->lineEdit->text()+"/"+m_bookTitle+"\"";
    prosses.execute("mv "+fileName+" "+epubfileName);
    prosses.waitForFinished();
    qDebug()<<epubfileName;
    prosses.execute("rm -r "+pathTodDelet);
    return true;
    */


#ifdef   Q_WS_WIN
    QProcess prosses;
       QString pathToAdd="  \""+ui->lineEdit->text()+"/"+m_bookTitle+"/*\"";

       QString fileName=ui->lineEdit->text()+"/"+m_bookTitle+".zip";
       QString epubfileName=ui->lineEdit->text()+"/"+m_bookTitle+".epub";
       QString pathTodDelet=ui->lineEdit->text()+"/"+m_bookTitle;
    prosses.setWorkingDirectory(QApplication::applicationDirPath());
     prosses.start("7z a  \""+fileName+"\" "+pathToAdd);
      prosses.waitForFinished();
       qDebug()<<fileName;
      while(prosses.state()==QProcess::Running){
          qApp->processEvents();
         prosses.waitForFinished();
      }
      if(QFile::exists(fileName)){
      if(  QFile::rename(fileName,epubfileName)==true){
          qDebug()<<"edpub renmed true";
          removeTempDirs(pathTodDelet);

      }else{
           qDebug()<<"epub renamed false";
           return false;
      }
  }else{
   qDebug()<<"zip no exist";
    return false;
}


#else
       QProcess prosses;
       QString pathToAdd="  \""+ui->lineEdit->text()+"/"+m_bookTitle+"/*\"";

       QString fileName="\""+ui->lineEdit->text()+"/"+m_bookTitle+".zip\"";
#ifdef Q_OS_HAIKU
       prosses.setWorkingDirectory(ui->lineEdit->text()+"/"+m_bookTitle+"/");
      prosses.start("zip -r "+fileName+" . -i \*");
      prosses.waitForFinished();
       #else
       if(QFile::exists("/usr/bin/7z")){
           prosses.start("7z a  "+fileName+" "+pathToAdd);
       }else if(QFile::exists("/usr/bin/zip")){
           prosses.setWorkingDirectory(ui->lineEdit->text()+"/"+m_bookTitle+"/");
           prosses.start("zip -r "+fileName+" . -i \*");
       }else{
           QMessageBox::information(this,"",("please install 7z or zip "));
           return false;
       }
       #endif
       prosses.waitForFinished();


       QString epubfileName="\""+ui->lineEdit->text()+"/"+m_bookTitle+".epub\"";
       QString pathTodDelet="\""+ui->lineEdit->text()+"/"+m_bookTitle+"\"";
       prosses.execute("mv "+fileName+" "+epubfileName);
       prosses.waitForFinished();
       qDebug()<<epubfileName;
       prosses.execute("rm -r "+pathTodDelet);
       return true;

#endif

return true;
}
//---------HTML
void Print::creatHtmlDocument(bool isQml)
{
    QDir dir(ui->lineEdit->text()+"/"+m_bookTitle);
    if (!dir.exists())
    {
        return ;
    }

    if( dir.mkdir("HTML")==false){
        //  QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return ;
    }
    if(isQml==true){

        if(dir.mkdir("content")==true){
            QFile file;
            //     file.copy(m_pathApp+"/data/index.qml",ui->lineEdit->text()+"/"+m_bookTitle+"/index.qml");
            file.copy(m_pathApp+"/data/qml/Button.qml",  ui->lineEdit->text()+"/"+m_bookTitle+"/content/Button.qml");
            file.copy(m_pathApp+"/data/qml/FlickableWebView.qml",  ui->lineEdit->text()+"/"+m_bookTitle+"/content/FlickableWebView.qml") ;
            file.copy(m_pathApp+"/data/qml/Header.qml",  ui->lineEdit->text()+"/"+m_bookTitle+"/content/Header.qml") ;
            file.copy(m_pathApp+"/data/qml/ScrollBar.qml",  ui->lineEdit->text()+"/"+m_bookTitle+"/content/ScrollBar.qml") ;

            if(dir.mkdir("content/pics")==true){
                file.copy(m_pathApp+"/data/qml/pics/titlebar-bg.png",  ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/titlebar-bg.png") ;
            }
            QFile fileQml(ui->lineEdit->text()+"/"+m_bookTitle+"/index.qml");

            if (!fileQml.open(QFile::WriteOnly)){
                return ;
            }
            QTextStream out(&fileQml);
            out.setCodec(QTextCodec::codecForName("UTF-8"));
            out <<"import QtQuick 1.0 \n";
            out <<"import QtWebKit 1.0 \n";
            out << "import \"content\" \n";
            out <<"Rectangle { \n";
            out << QString("  id: webBrowser ; property int countpage:%1;property string urlString : \"index.html\"; width: 800; height: 600; color: \"#343434\" \n").arg(QString::number(rowsCount));
            out << "FlickableWebView {\n";
            out <<"   id: webView ; url: webBrowser.urlString; onProgressChanged: header.urlChanged = false; \n";
            out <<"   anchors { top: headerSpace.bottom; left: parent.left; right: parent.right; bottom: parent.bottom  } \n}\n";
            out <<"Item { \n id: headerSpace; width: parent.width; height: 40 \n } \n";
            out <<"ScrollBar { \n";
            out <<"  scrollArea: webView; width: 8 \n";
            out <<"  anchors {  right: parent.right; top: header.bottom; bottom: parent.bottom } \n} \n";
            out << "ScrollBar { \nscrollArea: webView; height: 8; orientation: Qt.Horizontal \n";
            out <<"  anchors { right: parent.right; rightMargin: 8; left: parent.left; bottom: parent.bottom } \n} \n";
            out <<"Header { \n  id: header; count:webBrowser.countpage \n";
            out <<"  width: headerSpace.width; height: 40; anchors.top: parent.top; anchors.topMargin: 0 } \n} \n";
        }
    }
    if( dir.mkdir("HTML/img")==false){
        //    QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return ;
    }

    QPixmap pix1(":/images/image/go-first.png");
    QPixmap pix2(":/images/image/go-back.png");
    QPixmap pix3(":/images/image/groupb.png");
    QPixmap pix4(":/images/image/go-next.png");
    QPixmap pix5(":/images/image/go-last.png");
    //---------------------------------------------------------------

    if(isQml==false){
        pix1.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/first.png");
        pix2.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/prev.png");
        pix3.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/home.png");
        pix4.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/next.png");
        pix5.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/last.png");
    }else{
        QPixmap pixBack(style()->standardPixmap(QStyle::SP_ArrowBack));
        QPixmap pixForward(style()->standardPixmap(QStyle::SP_ArrowForward));
        pix1.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/first.png");
        pix2.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/prev.png");
        pix3.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/home.png");
        pix4.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/next.png");
        pix5.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/last.png");
        pixBack.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/go-next-view.png");
        pixForward.save(ui->lineEdit->text()+"/"+m_bookTitle+"/content/pics/go-previous-view.png");
    }

    //save logo
    QPixmap pixlogo(266,245);
    pixlogo.fill(Qt::transparent);
    QPixmap pix6(":/images/image/groupbook.png");
    QPixmap pix7(":/images/image/titlekirtasse.png");
    QPainter p;
    p.begin(&pixlogo);
    p.drawPixmap(69,0,128,128,pix6);
    p.drawPixmap(0,128,266,117,pix7);
    p.end();
    pixlogo.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/logo.png");
    creatHtmlFahrassa(isQml);
    if(creatHtmlPages(isQml)==true){
        QMessageBox msgBox;
        msgBox.setText(trUtf8("تم انشاء الملفات بنجاح"));
        msgBox.setInformativeText("هل تريد فتح الملف للمعاينة ؟");
        msgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Ok:
            if(isQml==false){
                QDesktopServices::openUrl( QUrl::fromLocalFile(ui->lineEdit->text()+"/"+m_bookTitle+"/index.html") );
            }else{
                QDesktopServices::openUrl( QUrl::fromLocalFile(ui->lineEdit->text()+"/"+m_bookTitle+"/index.qml") );
            }
            break;
        default:
            // should never be reached
            break;
        }
    }

}
bool Print::creatHtmlPages(bool isQml)
{
    QString bgr;
    if(ui->checkBox_bgr->isChecked())
        bgr="bgcolor=\""+m_WebColorBack+"\"";
    QFont font;
    font.fromString(m_WebFont);
    QString fontname=font.family();
    QString fontHeight;
    if(isQml==false){
        QString fontsize=QString::number(font.pointSize());
        QString fontwith=QString::number(font.weight());
        fontHeight="font-size:"+fontsize+"pt; font-weight:"+fontwith+";";
    }
    QString title=m_bookTitle;


    ui->progressBar->setMaximum(rowsCount);
    QDomElement racine = m_docBooK.documentElement();
    for (int i=0;i<rowsCount;i++)
    {
        if(isQml==true){
            title=QString::number(i+1);
        }
        QString txtContent1="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">"
                "<HTML DIR=\"RTL\">"
                "<HEAD>"
                "<META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=utf-8\">"
                "<TITLE>"+title+"</TITLE>"
                "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>"
                "<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
                "</HEAD>"
                "<body style=\" font-family:'"+fontname+"';"+fontHeight+" font-style:normal;\" "+bgr+"><font color='"+m_WebFontColor+"' >";

        QString txtContent2="</P>"
                "</font>"
                "</body>"
                "</html>";

        int next=i+2;
        if(i==rowsCount-1)next=rowsCount;
        int prev=i;
        if(i<=1)prev=1;
        ui->progressBar->setValue(i);
        QDomNode noeud = racine.childNodes().item(i);
        QString  bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString  bookPage= noeud.firstChildElement("page").firstChild().toText().data();
        QString  bookPart=noeud.firstChildElement("part").firstChild().toText().data();
        QLocale lc(this->locale().name());
        QString TableImages= "<TABLE WIDTH=100% CELLPADDING=0 CELLSPACING=0  STYLE=\"page-break-before: always\">"
                "<TR VALIGN=TOP>"
                "<TD WIDTH=26 HEIGHT=26 STYLE=\"; border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P1.html\"><IMG SRC=\"img/first.png\" NAME=\"first\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P"+QString::number(prev)+".html\"><IMG SRC=\"img/prev.png\" NAME=\"prev\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"../index.html\"><IMG SRC=\"img/home.png\" NAME=\"home\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P"+QString::number(next)+".html\"><IMG SRC=\"img/next.png\" NAME=\"next\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P"+QString::number(rowsCount)+".html\"><IMG SRC=\"img/last.png\" NAME=\"last\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=100% STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=CENTER>الجزء : "+lc.toString(bookPart.toInt())+" / الصفحة : "+lc.toString(bookPage.toInt())+"</P></TD>\n"
                "</TR>"
                "</TABLE>";

        QString qmlTitle=  "<P ALIGN=CENTER>"+m_bookTitle+"   الجزء : "+lc.toString(bookPart.toInt())+" / الصفحة : "+lc.toString(bookPage.toInt())+"</P>";

        QString Content= convertText(bookNass,bookPart,bookPage,i+1);



        QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/P"+QString::number(i+1)+".html");

        if (!fileContent.open(QFile::WriteOnly)){
            return false;
        }
        QTextStream out(&fileContent);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out << txtContent1;
        if(isQml==false){
            out << TableImages;
        }else{
            out << qmlTitle;
        }
        out << "<P ALIGN=RIGHT><BR>";
        out << Content;
        out << "<P ALIGN=RIGHT><BR>";
        if(isQml==false)
            out << TableImages;
        out << txtContent2;
        fileContent.close();
    }
    ui->progressBar->setValue(rowsCount);
    return true;
}
void Print::creatHtmlFahrassa(bool isQml )
{
    QFile fileToc(ui->lineEdit->text()+"/"+m_bookTitle+"/index.html");
    if (!fileToc.open(QFile::WriteOnly)){
        return ;
    }
    QTextStream out(&fileToc);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    QString title=m_bookTitle;
    if(isQml==true){
        title="0";
    }
    QString txtContent1="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">"
            "<HTML DIR=\"RTL\">"
            "<HEAD>"
            "<META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=utf-8\">"
            "<TITLE>"+title+"</TITLE>"
            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>"
            "</HEAD><body style=\" font-size:9pt; font-weight:400; font-style:normal;\">\n"
            "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\"HTML/img/logo.png\" /></p>\n"
            "<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; color:#ff0000;\">"+m_bookTitle+"</span></p>\n"
            "<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ff0000;\">"+m_bookAuthor+"</span></p>\n"
            "<p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; \">"+convertTextBetaka(m_bookBetaka)+"</span></p>\n"
            "<p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#0055ff;\">فهرسة</span></p>\n";

    out <<txtContent1;

    out <<"<ul>";
    //<p align="right" dir='rtl' style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><a href="www.gggh.cim"><span style=" text-decoration: underline;
    int countTop=treeviw->topLevelItemCount();

    for (int i=0 ;i<countTop;i++){
        // m_n++;
        QTreeWidgetItem *item=treeviw->topLevelItem(i);
        // QString order=QString::number(m_n);
        QString id=item->data(1,1).toString();
        QString txt=item->text(0);
        out << "<li><p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:5px; margin-right:5px; -qt-block-indent:0; text-indent:0px;\">"
               "<a href=\"HTML/P"+id+".html\"><span style=\" text-decoration: underline;color:#0057ae;\">"+txt+"</span></a> </p></li>\n";

        //child her----------------------------
        out <<getChildHtml(item);

    }
    out <<"</ul>";
    out <<"</body></html>";
    fileToc.close();

}
QString Print::getChildHtml(QTreeWidgetItem *item)
{

    QString txtNav;
    txtNav.insert(txtNav.length(),"<ul>");
    int count=item->childCount();
    for (int i=0 ;i<count;i++){

        QTreeWidgetItem *itemChild=item->child(i);

        QString id=itemChild->data(1,1).toString();
        QString txt=itemChild->text(0);
        txtNav.insert(txtNav.length(),"<li><p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                      "<a href=\"HTML/P"+id+".html\"><span style=\" text-decoration: underline;color:#0057ae;\">"+txt+"</span></a> </p></li>\n");

        //child her----------------------------
        txtNav.insert(txtNav.length(), getChildHtml(itemChild));
    }
    txtNav.insert(txtNav.length(),"</ul>");
    return txtNav;
}

void Print::on_comboBox_currentIndexChanged(int index)
{
    if(index==0||index==4){
        ui->checkBox->setVisible(false);
        ui->checkBox->setChecked(false);
        ui->radioButton_part->setVisible(false);
        ui->radioButton_nbr->setVisible(false);
        ui->spinBox->setVisible(false);
    }else if(index==3){
        ui->checkBox->setVisible(true);
        ui->radioButton_part->setVisible(false);
        ui->radioButton_nbr->setVisible(false);
        ui->spinBox->setVisible(false);
    }else{
        ui->checkBox->setVisible(true);
        ui->radioButton_part->setVisible(true);
        ui->radioButton_nbr->setVisible(true);
        ui->spinBox->setVisible(true);
    }
}

//-------
void Print::removeTempDirs(QString dirName)
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

bool  Print::removeTempFiles(QString tempDir)
{

        QDir dirS(tempDir);
        QString subfile;
        QFile filetemp;
        foreach ( subfile, dirS.entryList(QDir::AllEntries)){

            filetemp.remove(tempDir+"/"+subfile);
        }

return true;


}
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
#include "print.h"
#include  "ui_print.h"
#include <QtGui>
#include <QMessageBox>
Print::Print(QWidget *parent)
    : QDialog(parent), ui(new Ui::Print)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    mCurPart=1;
    QLocale Arabic(QLocale::Arabic);
    Arabic.setNumberOptions(QLocale::OmitGroupSeparator);
    QString txt="1234567890";
     QString s2 = Arabic.toString(txt.toInt());
    ui->comboBoxNumber->addItem(trUtf8("system"));
    ui->comboBoxNumber->addItem(trUtf8("Arabic")+" ("+txt+")");
    ui->comboBoxNumber->addItem(trUtf8("Arabic India")+" ("+s2+")");
    ui->checkBox->setVisible(false);
    ui->radioButton_part->setVisible(false);
    ui->radioButton_nbr->setVisible(false);
    ui->spinBox->setVisible(false);

}
Print::~Print()
{

}
void Print::setBookTitle(QString name)
{
    m_bookTitle=name;
}

void Print::setBookAuthor(QString name)
{
    m_bookAuthor=name;
}

void Print::setBookBetaka(QString name)
{
    m_bookBetaka=name;
}

void Print::setBookColorBack(QString name)
{
    m_WebColorBack=name;
}

void Print::setBookFont(QString name)
{
      m_WebFont=name;
}

void Print::setBookFontColor(QString name)
{
      m_WebFontColor=name;
}

void Print::setBookFontTitleColor(QString name)
{
      m_WebFontTitleColor=name;
}

void Print::setBookFontPrefertColor(QString name)
{
      m_WebFontPrefertColor=name;
}

void Print::setBookCurentPath(QString name)
{
      m_curentPath=name;
   }

 void Print::setBookFontTitle(QString name)
 {
       m_WebFontTitle=name;
 }

void Print::on_buttonBox_clicked(QAbstractButton* button)
{
    if(ui->comboBoxNumber->currentIndex()==1){
          this->setLocale(QLocale(QLocale::Latin));
    } else if(ui->comboBoxNumber->currentIndex()==2) {
          this->setLocale(QLocale(QLocale::Arabic));
    }

    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok)
    {
        if (ui->comboBox->currentIndex()==2)
        {
            int reponse = QMessageBox::information(this, trUtf8("تنبيه"), trUtf8("ان حفظ الكتاب بهذه الصيغة يأخذ وقتا أطول سيما اذا كان الكتاب كبيرا \n هل تريد المتابعة؟") , QMessageBox::Yes | QMessageBox::Cancel);
            if (reponse == QMessageBox::Cancel){
               return;
            }
        }
        QDir dir(ui->lineEdit->text());
        if (!dir.exists())
        {
            return;
        }
        if( dir.mkdir(m_bookTitle)==false)
        {
            QMessageBox::critical(this,trUtf8("خطأ"), trUtf8(" لا يمكن انشاء الملف في هذا الدليل اختر دليلا اخر"));
            return;
        }

        m_fileName=ui->lineEdit->text()+"/"+m_bookTitle+"/"+m_bookTitle+"_";
        ui->frame->setVisible(true);
        button->setEnabled(false);
        ui->frame_2->setEnabled(false);
        if (openBook()==true){
        if (ui->comboBox->currentIndex()==0){

            creatHtmlDocument();
         }else if (ui->comboBox->currentIndex()==3){
                creatEpubDocument();
            }else{
                creatDocument();
            }

        }
    }
}
bool Print::openBook()
{
   // QString path=QCoreApplication::applicationDirPath ();
    //  QString path=curentPath;
                   QString bkpath=m_curentPath +"/book.xml";           //مسار الكتاب
    QFile file(bkpath);
    if( !file.open(QIODevice::ReadOnly))                            //فتح الملف
    {
         return false;
    }

    m_docBooK.clear();                                                    //تفريغ الذاكرة
    if (!m_docBooK.setContent(&file))                                      //اذا كانت البيانات صحيحة
    {
        return false;
    }

    QDomElement racine = m_docBooK.documentElement(); //renvoie la balise racine
    QVariant i = racine.childNodes().count();
    rowsCount=i.toInt();
    file.close();

    return true;
}

void Print::creatDocument()
{
int counter=0;
QString bgr="<body";
if (ui->checkBox_bgr->isChecked())
{
    bgr=bgr="<body  bgcolor='"+m_WebColorBack+"'";
}
QString bgrcolor = "<html dir=rtl ><head><title>مكتبة القرطاس :"+m_bookTitle+"</title></head>"+bgr+">< font color='"+m_WebFontColor+"' >";
    QString image="<p align=\"center\"><img src=\":/images/image/groupbook.png\" /></p>";
    QString title="<font size='6'color='"+m_WebFontTitleColor+"' ><p align=\"center\">"+m_bookTitle+"</p></font>";
    QString hothor="<font size='3' ><p align=\"center\">"+m_bookAuthor+"</p></font><p align=\"right\"></p>";

    QFont font;
    font.fromString(m_WebFont);

    m_textEdit=new QTextEdit(this);
    m_textEdit->setLayoutDirection(Qt::RightToLeft);
    m_textEdit->setAlignment(Qt::AlignRight);
    m_textEdit->setFont(font);
    m_textEdit->setHtml(bgrcolor);
    m_textEdit->insertHtml(image+title+hothor);

    ui->progressBar->setMaximum(rowsCount);

    QDomElement racine = m_docBooK.documentElement();
    for (int i=0;i<rowsCount;i++)
    {
        counter=counter+1;
        ui->progressBar->setValue(i);
        QDomNode noeud = racine.childNodes().item(i);
        QString  bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString  bookPage= noeud.firstChildElement("page").firstChild().toText().data();
        QString  bookPart=  noeud.firstChildElement("part").firstChild().toText().data();

        if (ui->radioButton_part->isChecked())
        {
            if (!(bookPart.isNull()) || !(bookPart.isEmpty()) || !(bookPart=="0"))
            {

                if (bookPart.toInt()>mCurPart)
                {
                    if (fileSave()==false)
                    {
                        QMessageBox::information(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
                        return;
                    }
                    mCurPart=mCurPart+1;
                    m_textEdit->clear();
                    m_textEdit->setHtml(bgrcolor);
                    m_textEdit->insertHtml(image+title+hothor);
                }
            }
        } else{
            if (counter==ui->spinBox->value())
            {
                if (fileSave()==false)
                {
                    QMessageBox::information(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
                    return;
                }
                counter=0;
                mCurPart=mCurPart+1;
                m_textEdit->clear();
                m_textEdit->setHtml(bgrcolor);
                m_textEdit->insertHtml(image+title+hothor);
            }

        }
       m_textEdit->insertHtml( convertText("<br>"+bookNass,bookPart,bookPage,i+1));
    }

    if (fileSave()==false)
    {
        QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن حفظ الملف"));
        return;
    }
    QMessageBox::information(this,trUtf8("حفظ"), trUtf8("تمت عملية الحفظ بنجاح"));
    this->reject();
}
QString Print::convertText(QString txt,QString part,QString page, int id)
{

    txt.replace(QByteArray("\n"), QByteArray("<br>"));
    txt.replace(QByteArray("\r"), QByteArray("<br>"));
    //*******************************************
 // QString id=DataBook->bookCurentId[m_currentBookIndex];
    if (txt.contains("$")){
         txt.replace("$", "");
    }

    QLocale lc(this->locale().name());
     lc.setNumberOptions(QLocale::OmitGroupSeparator);
//      qDebug()<<this->locale().name();
    QRegExp rxD("(\\d+)");
     int pos = 0;
     while ((pos = rxD.indexIn(txt, pos)) != -1) {
       txt.remove(pos,rxD.matchedLength());
       txt.insert(pos,lc.toString(rxD.cap(1).toInt()));
         pos += rxD.matchedLength();
     }
     QVariant dd=id;
   QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
           treeviw->findItems(
                    dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);//تنشاء قائمة بكل العناصر

        foreach (item, found){

            //    QMessageBox::information(this,trUtf8("llop"),item->text(0));
             txt.replace( item->text(0)+"<br>","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
             txt.replace("  "+ item->text(0),"<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'><br> "+item->text(0)+"</font><br>");
             txt.replace("<br>"+ item->text(0),"<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'><br> "+item->text(0)+"</font><br>");
             txt.replace( item->text(0)+"<br>","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
             txt.replace( item->text(0)+" <br>","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
             txt.replace( item->text(0)+" :","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+" :</font><br>");
             txt.replace( item->text(0)+".","<font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+". </font><br>");

             if(txt.trimmed()== item->text(0).trimmed()){
                 txt="< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"' > "+item->text(0)+" </font>";
             }
         }

    //********************************************

        txt.replace("صلى الله عليه وسلم","<font color='"+m_WebFontPrefertColor+"' >صلى الله عليه وسلم</font> ");
        txt.replace("C تعالى","<font color='"+m_WebFontPrefertColor+"' >رحمه الله تعالى</font> ");
         txt.replace("{","<font color='"+m_WebFontPrefertColor+"' >﴿</font> ");
         txt.replace("}","<font color='"+m_WebFontPrefertColor+"' >﴾</font> ");
        txt.replace("رضي الله عنهم ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنهم </font> "));
        txt.replace("رضي الله عنه ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
        txt.replace("رضي الله عنهما ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("' >رضي الله عنهما </font> "));
        txt.replace(" A ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'> صلى الله عليه سلم </font> "));
        txt.replace("Bه",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
        txt.replace(" D ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'>  تعالى </font> "));
        txt.replace(" E ",trUtf8("<font color='")+m_WebFontPrefertColor+trUtf8("'> عليه السلام </font> "));

    if (txt.contains("**")){
        QRegExp rx("(\\d\\d? )[(]");
        txt.replace(rx,"<br>(");
        QRegExp rx1("(\\d\\d?)[(]");
        txt.replace(rx1,"<br>(");
        txt.replace(") (",")<br>(");
        txt.replace(")(",")<br>(");
    }
txt.replace("<br><br>","<br>");
txt.replace("<br> <br>","<br>");
txt.replace("<br>  <br>","<br>");

QRegExp rxi("_____+");
QRegExp rxd("ـــــ+");
    txt.replace(rxi," <font size='1'><br>__________");
    txt.replace(rxd," <font size='1'><br>__________");

        if (ui->checkBox->isChecked())
        {
            txt.insert(txt.length(),"<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
         //   m_textEdit->insertHtml("<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
        }

return txt;

}

void Print::on_toolButton_clicked()
{
    QString homeDir=QDir::homePath () ;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    homeDir,
                                                    QFileDialog::ShowDirsOnly
                                                    |QFileDialog::DontResolveSymlinks
                                                    |QFileDialog::ReadOnly);
      ui->lineEdit->setText(dir);
}



bool Print::fileSave()
{
     QVariant d=mCurPart;
     QString fileName;
    if (ui->comboBox->currentIndex()==2)
    {
        fileName=m_fileName+d.toString()+".pdf";
        #ifndef QT_NO_PRINTER
        QPrinter printer(QPrinter::ScreenResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
         QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

        m_textEdit->document()->print(&printer);

        QApplication::restoreOverrideCursor();
        #endif
         return true;
    }else if(ui->comboBox->currentIndex()==1){
        fileName=m_fileName+d.toString()+".odf";
        QTextDocumentWriter writer(fileName);
        bool success = writer.write(m_textEdit->document());
        if (success)
            return success;
    }else{
        fileName=m_fileName+d.toString()+".html";
        QTextDocumentWriter writer(fileName);
        bool success = writer.write(m_textEdit->document());
        if (success)
            return success;
    }
return true;

}
///----------------------------------------epub-------------------------------------------------------
void Print::creatEpubDocument()
{


    //! [0]
    if(creatEpubDIrectory()==false){
        QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
    return;
    }
    //! [1]
     if(creatEpubContent()==false){
         QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
     return;
     }
    //! [2]
    if(creatEpubToc()==false){
        QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
    return;
    }
   //! [3]
    if(creatEpubInfo()==false){
            QMessageBox::information(this,"",trUtf8("خطأ في انشاء الملفات اختر دليلا اخر"));
        return;
        }
    //! [4]
   if(creatEpubPages()==true){
       zipUpubDocument();
   }
   QString epubFile=ui->lineEdit->text()+"/"+m_bookTitle+".epub";
QFile file(epubFile);
if(file.exists()){
    QMessageBox::information(this,"",trUtf8("تم انشاء : ")+epubFile);
}else{
        QMessageBox::information(this,"",trUtf8("خطأ غير متوقع في انشاء الملف : "));
}
}
//! [0]
bool Print::creatEpubDIrectory()
{
    QDir dir(ui->lineEdit->text()+"/"+m_bookTitle);
    if (!dir.exists())
    {
        return false;
    }
    if( dir.mkdir("OEBPS")==false){
        //     QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    if( dir.mkdir("OEBPS/xhtml")==false){
        //  QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    if( dir.mkdir("OEBPS/img")==false){
        //    QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    if( dir.mkdir("META-INF")==false){
        //  QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return false;
    }
    //save logo
    QPixmap pixlogo(266,245);
    pixlogo.fill(Qt::transparent);
    QPixmap pix1(":/images/image/groupbook.png");
    QPixmap pix2(":/images/image/titlekirtasse.png");
    QPainter p;
    p.begin(&pixlogo);
    p.drawPixmap(69,0,128,128,pix1);
    p.drawPixmap(0,128,266,117,pix2);
    p.end();
    pixlogo.save(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/img/logo.png");
    //save mimetype
    QFile file(ui->lineEdit->text()+"/"+m_bookTitle+"/mimetype");
    if (!file.open(QFile::WriteOnly))
        return false;
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    out<<"application/epub+zip";
    //save container.xml
    file.setFileName(ui->lineEdit->text()+"/"+m_bookTitle+"/META-INF/container.xml");
    if (!file.open(QFile::WriteOnly))
        return false;
    QTextStream out1(&file);
    out1.setCodec(QTextCodec::codecForName("UTF-8"));
    out1<<"<?xml version=\"1.0\"?>"
          "<container version=\"1.0\" xmlns=\"urn:oasis:names:tc:opendocument:xmlns:container\">"
          "<rootfiles>"
          "<rootfile full-path=\"OEBPS/content.opf\" media-type=\"application/oebps-package+xml\"/>"
          "</rootfiles>"
          "</container>";
    file.setFileName(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/style.css");
    if (!file.open(QFile::WriteOnly))
        return false;
    QTextStream out2(&file);
    out2.setCodec(QTextCodec::codecForName("UTF-8"));
    out2<< "body { margin: 2%; background-color: #FEFBE7; }"
           " body.rtl { direction: rtl; text-align: right; }"
           "body.ltr { direction: ltr; text-align: justify; } "
           "#book-container {  }"
           "#book-container span.matn { color: #0000AF; } "
           "#book-container span.title { color: #A52A2A; font-weight: bold; }"
           "#book-container span.prifired { color: #007200; } "
           "#book-container span.red { color: #FF0000; }"
           "#book-container span.footnote { color: #665555; font-size: 0.9em; } "
           "#book-container span.footnote-hr { font-size: 1px; display: block; width: 25%; border-bottom: 1px solid #665555; }"
           "#book-container span.matn-hr { font-size: 1px; display: block; width: 95%; border-bottom: 3px solid #000000; margin: 0pt auto; } .center { text-align:center;display:block; } .info-item { display: block; margin-bottom: 5px; } .info-title { display: inline-block; width: 25%; font-weight: bold; vertical-align: top; } .info-desc { display: inline-block; width: 55%; vertical-align: top; } ";
    file.close();
    return true;
}

//! [1]
bool Print::creatEpubContent()
{
    QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/content.opf");

    if (!fileContent.open(QFile::WriteOnly)){
        return false;
    }
    QTextStream out(&fileContent);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out <<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    out <<  "<package xmlns=\"http://www.idpf.org/2007/opf\" unique-identifier=\"BookID\" version=\"2.0\">";
    out << "<metadata xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:opf=\"http://www.idpf.org/2007/opf\">";
    out <<   "<dc:title>"+m_bookTitle+"</dc:title>";
    out << "<dc:creator opf:role=\"aut\">"+m_bookAuthor+"</dc:creator>";
    out <<  "<dc:publisher>http://elkirtasse.ws</dc:publisher>";
    out <<    "<dc:language>ar</dc:language>";
    out <<   "<dc:identifier id=\"BookID\" opf:scheme=\"UUID\">urn:uuid:f38f5e73c5be19930ef2d0b440d52b34</dc:identifier>";
    out <<  "</metadata>";
    out << "<manifest>";
    out <<"<item id=\"ncx\" href=\"toc.ncx\" media-type=\"application/x-dtbncx+xml\"/>";
    out << "<item id=\"stylesheet\" href=\"style.css\" media-type=\"text/css\"/>";
    out <<   "<item id=\"logo\" href=\"img/logo.png\" media-type=\"image/png\"/>";
    out <<   "<item id=\"info\" href=\"xhtml/info.xhtml\" media-type=\"application/xhtml+xml\"/>";

    for(int i=0;i<rowsCount;i++){
        QString txt=QString("<item id=\"P%1\" href=\"xhtml/P%1.xhtml\" media-type=\"application/xhtml+xml\"/>").arg(QString::number(i+1));
        out <<txt+"\n";
    }
    out <<"</manifest>";
    out <<"<spine toc=\"ncx\">";
    out <<   "<itemref idref=\"info\"/>";

    for(int i=0;i<rowsCount;i++){
        QString txt=QString("<itemref idref=\"P%1\"/>").arg(QString::number(i+1));
        out <<txt;
    }
    out <<"</spine>";
    out <<"</package>";

fileContent.close();
return true;
}
//! [1]
//! [2]
bool Print::creatEpubToc()
{
    QString bkinf=trUtf8("بطاقة الكتاب");
    QFile fileToc(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/toc.ncx");

    if (!fileToc.open(QFile::WriteOnly)){
        return false;
    }
    QTextStream out(&fileToc);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out <<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    out << "<!DOCTYPE ncx PUBLIC \"-//NISO//DTD ncx 2005-1//EN\"  \"http://www.daisy.org/z3986/2005/ncx-2005-1.dtd\">";
    out <<"<ncx xmlns=\"http://www.daisy.org/z3986/2005/ncx/\" version=\"2005-1\">";
    out <<"<head>";
    out <<"<meta name=\"dtb:uid\" content=\"f38f5e73c5be19930ef2d0b440d52b34\"/>";
    out << "<meta name=\"dtb:depth\" content=\"2\"/>";
    out <<  "<meta name=\"dtb:totalPageCount\" content=\"0\"/>";
    out <<  "<meta name=\"dtb:maxPageNumber\" content=\"0\"/>";
    out <<"</head>";
    out << " <docTitle>";
    out << " <text>"+m_bookTitle+"</text>";
    out << "</docTitle>";
    out << "<docAuthor>";
    out << "<text>"+m_bookAuthor+"</text>";
    out << "</docAuthor>";
   out <<"<navMap><navPoint id=\"info\" playOrder=\"1\"><navLabel><text>"+bkinf+"</text></navLabel><content src=\"xhtml/info.xhtml\"/></navPoint>";
 //---get-fahariss
   int countTop=treeviw->topLevelItemCount();
m_n=1;
   for (int i=0 ;i<countTop;i++){
      m_n++;
       QTreeWidgetItem *item=treeviw->topLevelItem(i);
       QString order=QString::number(m_n);
       QString id=item->data(1,1).toString();
       QString txt=item->text(0);
       out << "<navPoint id=\"C"+order+"\" playOrder=\""+order+"\"><navLabel><text>"+txt+".</text></navLabel><content src=\"xhtml/P"+id+".xhtml\"/>";
    //child her----------------------------
        out <<getChildNavpoint(item);
     out << "</navPoint>";
   }
    out <<"</navMap></ncx>";
    fileToc.close();
    return true;
}
//! [2] [0]
QString Print::getChildNavpoint(QTreeWidgetItem *item)
{
  QString txtNav;
     int count=item->childCount();
     for (int i=0 ;i<count;i++){
           m_n++;
           QTreeWidgetItem *itemChild=item->child(i);
           QString order=QString::number(m_n);
           QString id=itemChild->data(1,1).toString();
           QString txt=itemChild->text(0);

           txtNav.insert(txtNav.length(), "<navPoint id=\"C"+order+"\" playOrder=\""+order+"\"><navLabel><text>"+txt+".</text></navLabel><content src=\"xhtml/P"+id+".xhtml\"/>");
           //child her----------------------------
           txtNav.insert(txtNav.length(), getChildNavpoint(itemChild));
           txtNav.insert(txtNav.length(), "</navPoint>");
     }
     return txtNav;
}
//! [2]
//! [3]
bool Print::creatEpubInfo()
{
    QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/xhtml/info.xhtml");

    if (!fileContent.open(QFile::WriteOnly)){
        return false ;
    }
    QString elkirtasse=trUtf8("مكتبة القرطاس");
    QTextStream out(&fileContent);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    out << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n";

    out << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n";
    out << "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n";
    out << "<head>\n";
    out << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>\n";
    out << "<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />\n";
    out <<"<title>"+m_bookTitle+"</title>\n";
    out <<  "</head>\n";
    out <<  "<body class=\"rtl\">\n";
    out <<"<div id=\"book-container\">\n";
    out << "<div class=\"center\"><img src=\"../img/logo.png\" style=\"margin:4px;\" alt=\""+elkirtasse+"\" /></div>\n";
    out << "<br style=\"clear:both;\" /><span class=\"title center\">"+m_bookTitle+"</span>\n";
    out <<  "<span class=\"center\">"+m_bookAuthor+"</span>\n";
    out <<  "<span class=\"info-desc\"> "+m_bookBetaka+"</span>\n";
    out <<   "</div>\n</body>\n</html>";
    fileContent.close();
    return true;
}
//! [3]
//! [4]
bool Print::creatEpubPages()
{
    QString txtContent1="<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"
            "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
            " <html xmlns=\"http://www.w3.org/1999/xhtml\">"
            "<head>"
            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>"
            "<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />"
            "<title>"+m_bookTitle+"</title>"
            "</head>"
            "<body class=\"rtl\">"
            "<div id=\"book-container\">";
    QString txtContent2="</div>"
            "</body>"
            "</html>";

    ui->progressBar->setMaximum(rowsCount);
    QDomElement racine = m_docBooK.documentElement();
    for (int i=0;i<rowsCount;i++)
    {

        ui->progressBar->setValue(i);
        QDomNode noeud = racine.childNodes().item(i);
        QString  bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString  bookPage= noeud.firstChildElement("page").firstChild().toText().data();
        QString  bookPart=noeud.firstChildElement("part").firstChild().toText().data();
        // QString Content= bookNass;// convertText(bookNass,bookPart,bookPage,i+1);
        QString Content= convertEpubStyle(bookNass,bookPart,bookPage,i+1);
        QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/OEBPS/xhtml/P"+QString::number(i+1)+".xhtml");

        if (!fileContent.open(QFile::WriteOnly)){
            return false;
        }
        QTextStream out(&fileContent);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out << txtContent1;
        out << Content;
        out << txtContent2;
        fileContent.close();
    }
    ui->progressBar->setValue(rowsCount);
    return true;
}
//! [4]
//! [4] [0]
QString Print::convertEpubStyle(QString txt,QString part,QString page, int id)
{

    txt.replace(QByteArray("\n"), QByteArray("<br />"));
    txt.replace(QByteArray("\r"), QByteArray("<br />"));
    //*******************************************

    if (txt.contains("$")){
        txt.replace("$", "");
    }


    QVariant dd=id;
    QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
            treeviw->findItems(
                dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);//تنشاء قائمة بكل العناصر

    foreach (item, found){

        txt.replace( item->text(0)+"<br />","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace("  "+ item->text(0),"<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace("<br />"+ item->text(0),"<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+"<br />","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+" <br />","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+" :","<span class=\"title\">"+item->text(0)+"</span><br />");
        txt.replace( item->text(0)+".","<span class=\"title\">"+item->text(0)+"</span><br />");

        if(txt.trimmed()== item->text(0).trimmed()){
            txt="<span class=\"title\">"+item->text(0)+"</span><br />";
        }
    }

    //********************************************
    QRegExp rxi("_____+");
    QRegExp rxd("ـــــ+");
    bool hachia=false;
    if(txt.contains(rxi)|| txt.contains(rxd)){
        txt.replace(rxi," <span class=\"footnote-hr\">&nbsp;</span><span class=\"footnote\">");
        txt.replace(rxd,"  <span class=\"footnote-hr\">&nbsp;</span><span class=\"footnote\">");
        hachia=true;
    }




    txt.replace("صلى الله عليه وسلم","<span class=\"prifired\">صلى الله عليه وسلم</span>");
    txt.replace("C تعالى","<span class=\"prifired\">رحمه الله تعالى</span>");
    txt.replace("{","<span class=\"prifired\">﴿</span>");
    txt.replace("}","<span class=\"prifired\">﴾</span>");
    txt.replace("رضي الله عنهم ","<span class=\"prifired\">رضي الله عنهم </span>");
    txt.replace("رضي الله عنه ","<span class=\"prifired\">رضي الله عنه </span>");
    txt.replace("رضي الله عنهما ","<span class=\"prifired\">رضي الله عنهما </span>");
    txt.replace(" A ","<span class=\"prifired\">صلى الله عليه وسلم</span>");
    txt.replace("Bه","<span class=\"prifired\">رضي الله عنه </span>");
    txt.replace(" D ","<span class=\"prifired\"> تعالى  </span>");
    txt.replace(" E ","<span class=\"prifired\"> عليه السلام </span>");

    if (txt.contains("**")){
        QRegExp rx("(\\d\\d? )[(]");
        txt.replace(rx,"<br />(");
        QRegExp rx1("(\\d\\d?)[(]");
        txt.replace(rx1,"<br />(");
        txt.replace(") (",")<br />(");
        txt.replace(")(",")<br />(");
    }
    txt.replace("<br /><br />","<br />");
    txt.replace("<br /> <br />","<br />");
    txt.replace("<br />  <br />","<br />");

    if(hachia==true)
        txt.insert(txt.length(),"</span>");

    if (ui->checkBox->isChecked())
    {
        QString gg=" الجزء: "+part+" /الصفحة : "+page;
        txt.insert(txt.length(),"<br /><br /><br /><div class=\"center\">"+gg +"</div>");
        //   txt.insert(txt.length(),"<br><font size='1' ><p> __________ الجزء: "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
        //   m_textEdit->insertHtml("<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
    }

    QLocale lc(this->locale().name());
    // qDebug()<<this->locale().name();
    QRegExp rxD("(\\d+)");
   lc.setNumberOptions(QLocale::OmitGroupSeparator);
    int pos = 0;

    while ((pos = rxD.indexIn(txt, pos)) != -1) {

        txt.remove(pos,rxD.matchedLength());
        txt.insert(pos,lc.toString(rxD.cap(1).toInt()));


        pos += rxD.matchedLength();
    }
    return txt;

}
bool Print::zipUpubDocument()
{

            QProcess prosses;
               QString pathToAdd="  \""+ui->lineEdit->text()+"/"+m_bookTitle+"/*\"";

               QString fileName="\""+ui->lineEdit->text()+"/"+m_bookTitle+".zip\"";


  if(QFile::exists("/usr/bin/7z")){
         prosses.start("7z a  "+fileName+" "+pathToAdd);
  }else if(QFile::exists("/usr/bin/zip")){
      prosses.setWorkingDirectory(ui->lineEdit->text()+"/"+m_bookTitle+"/");
     prosses.start("zip -r "+fileName+" . -i \*");
  }else{
        QMessageBox::information(this,"",("please install 7z or zip "));
        return false;
  }
    prosses.waitForFinished();


             QString epubfileName="\""+ui->lineEdit->text()+"/"+m_bookTitle+".epub\"";
             QString pathTodDelet="\""+ui->lineEdit->text()+"/"+m_bookTitle+"\"";
           prosses.execute("mv "+fileName+" "+epubfileName);
              prosses.waitForFinished();
               qDebug()<<epubfileName;
          prosses.execute("rm -r "+pathTodDelet);
          return true;
}
//---------HTML
void Print::creatHtmlDocument()
{
    QDir dir(ui->lineEdit->text()+"/"+m_bookTitle);
    if (!dir.exists())
    {
        return ;
    }

    if( dir.mkdir("HTML")==false){
        //  QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return ;
    }
    if( dir.mkdir("HTML/img")==false){
        //    QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
        return ;
    }
    QPixmap pix1(":/images/image/go-first.png");
    QPixmap pix2(":/images/image/go-back.png");
    QPixmap pix3(":/images/image/groupb.png");
    QPixmap pix4(":/images/image/go-next.png");
    QPixmap pix5(":/images/image/go-last.png");
    pix1.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/first.png");
    pix2.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/prev.png");
    pix3.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/home.png");
    pix4.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/next.png");
    pix5.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/last.png");
    //save logo
    QPixmap pixlogo(266,245);
    pixlogo.fill(Qt::transparent);
    QPixmap pix6(":/images/image/groupbook.png");
    QPixmap pix7(":/images/image/titlekirtasse.png");
    QPainter p;
    p.begin(&pixlogo);
    p.drawPixmap(69,0,128,128,pix6);
    p.drawPixmap(0,128,266,117,pix7);
    p.end();
    pixlogo.save(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/img/logo.png");
    creatHtmlFahrassa();
    if(creatHtmlPages()==true){
        QMessageBox msgBox;
        msgBox.setText(trUtf8("تم انشاء الملفات بنجاح"));
         msgBox.setInformativeText("هل تريد فتح الملف للمعاينة ؟");
         msgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Ok);
         int ret = msgBox.exec();
         switch (ret) {
            case QMessageBox::Ok:
               QDesktopServices::openUrl( QUrl::fromLocalFile(ui->lineEdit->text()+"/"+m_bookTitle+"/index.html") );
                break;
             default:
                // should never be reached
                break;
          }
    }

}
bool Print::creatHtmlPages()
{
    QString bgr;
    if(ui->checkBox_bgr->isChecked())
        bgr="bgcolor=\""+m_WebColorBack+"\"";
    QFont font;
    font.fromString(m_WebFont);
    QString fontname=font.family();
    QString fontsize=QString::number(font.pointSize());
    QString fontwith=QString::number(font.weight());
    QString txtContent1="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">"
            "<HTML DIR=\"RTL\">"
            "<HEAD>"
            "<META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=utf-8\">"
            "<TITLE>"+m_bookTitle+"</TITLE>"
            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>"
            "<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
            "</HEAD>"
            "<body style=\" font-family:'"+fontname+"'; font-size:"+fontsize+"pt; font-weight:"+fontwith+"; font-style:normal;\" "+bgr+"><font color='"+m_WebFontColor+"' >";

    QString txtContent2="</P>"
           "</font>"
            "</body>"
            "</html>";

    ui->progressBar->setMaximum(rowsCount);
    QDomElement racine = m_docBooK.documentElement();
    for (int i=0;i<rowsCount;i++)
    {
        int next=i+2;
        if(i==rowsCount-1)next=rowsCount;
        int prev=i;
        if(i<=1)prev=1;
        ui->progressBar->setValue(i);
        QDomNode noeud = racine.childNodes().item(i);
        QString  bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString  bookPage= noeud.firstChildElement("page").firstChild().toText().data();
        QString  bookPart=noeud.firstChildElement("part").firstChild().toText().data();
        QLocale lc(this->locale().name());
        QString TableImages= "<TABLE WIDTH=100% CELLPADDING=0 CELLSPACING=0  STYLE=\"page-break-before: always\">"
                "<TR VALIGN=TOP>"
                "<TD WIDTH=26 HEIGHT=26 STYLE=\"; border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P1.html\"><IMG SRC=\"img/first.png\" NAME=\"first\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P"+QString::number(prev)+".html\"><IMG SRC=\"img/prev.png\" NAME=\"prev\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"../index.html\"><IMG SRC=\"img/home.png\" NAME=\"home\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P"+QString::number(next)+".html\"><IMG SRC=\"img/next.png\" NAME=\"next\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=26 STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=RIGHT><A HREF=\"P"+QString::number(rowsCount)+".html\"><IMG SRC=\"img/last.png\" NAME=\"last\" ALIGN=LEFT WIDTH=24 HEIGHT=24 BORDER=0></P></TD>\n"
                "<TD WIDTH=100% STYLE=\"border: none; padding: 0cm\">"
                "<P ALIGN=CENTER>الجزء : "+lc.toString(bookPart.toInt())+" / الصفحة : "+lc.toString(bookPage.toInt())+"</P></TD>\n"
                "</TR>"
                "</TABLE>";

        // QString Content= convertEpubStyle(bookNass,bookPart,bookPage,i+1);
        QString Content= convertText(bookNass,bookPart,bookPage,i+1);



        QFile fileContent(ui->lineEdit->text()+"/"+m_bookTitle+"/HTML/P"+QString::number(i+1)+".html");

        if (!fileContent.open(QFile::WriteOnly)){
            return false;
        }
        QTextStream out(&fileContent);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out << txtContent1;
        out << TableImages;
        out << "<P ALIGN=RIGHT><BR>";
        out << Content;
        out << "<P ALIGN=RIGHT><BR>";
        out << TableImages;
        out << txtContent2;
        fileContent.close();
    }
    ui->progressBar->setValue(rowsCount);
    return true;
}
void Print::creatHtmlFahrassa()
{
    QFile fileToc(ui->lineEdit->text()+"/"+m_bookTitle+"/index.html");
    if (!fileToc.open(QFile::WriteOnly)){
        return ;
    }
    QTextStream out(&fileToc);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    QString txtContent1="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">"
            "<HTML DIR=\"RTL\">"
            "<HEAD>"
            "<META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=utf-8\">"
            "<TITLE>"+m_bookTitle+"</TITLE>"
            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>"
            "</HEAD><body style=\" font-size:9pt; font-weight:400; font-style:normal;\">\n"
            "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\"HTML/img/logo.png\" /></p>\n"
            "<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; color:#ff0000;\">"+m_bookTitle+"</span></p>\n"
            "<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ff0000;\">"+m_bookAuthor+"</span></p>\n"
            "<p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; \">"+m_bookBetaka+"</span></p>\n"
            "<p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#0055ff;\">فهرسة</span></p>\n";
    out <<txtContent1;
      out <<"<ul>";
    //<p align="right" dir='rtl' style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><a href="www.gggh.cim"><span style=" text-decoration: underline;
    int countTop=treeviw->topLevelItemCount();

    for (int i=0 ;i<countTop;i++){
        // m_n++;
        QTreeWidgetItem *item=treeviw->topLevelItem(i);
        // QString order=QString::number(m_n);
        QString id=item->data(1,1).toString();
        QString txt=item->text(0);
        out << "<li><p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:5px; margin-right:5px; -qt-block-indent:0; text-indent:0px;\">"
               "<a href=\"HTML/P"+id+".html\"><span style=\" text-decoration: underline;color:#0057ae;\">"+txt+"</span></a> </p></li>\n";

        //child her----------------------------
        out <<getChildHtml(item);

    }
    out <<"</ul>";
    out <<"</body></html>";
    fileToc.close();

}
QString Print::getChildHtml(QTreeWidgetItem *item)
{

    QString txtNav;
    txtNav.insert(txtNav.length(),"<ul>");
    int count=item->childCount();
    for (int i=0 ;i<count;i++){

        QTreeWidgetItem *itemChild=item->child(i);

        QString id=itemChild->data(1,1).toString();
        QString txt=itemChild->text(0);
        txtNav.insert(txtNav.length(),"<li><p align=\"right\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                      "<a href=\"HTML/P"+id+".html\"><span style=\" text-decoration: underline;color:#0057ae;\">"+txt+"</span></a> </p></li>\n");

        //child her----------------------------
        txtNav.insert(txtNav.length(), getChildHtml(itemChild));
    }
    txtNav.insert(txtNav.length(),"</ul>");
    return txtNav;
}

void Print::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->checkBox->setVisible(false);
        ui->checkBox->setChecked(false);
        ui->radioButton_part->setVisible(false);
        ui->radioButton_nbr->setVisible(false);
        ui->spinBox->setVisible(false);
    }else if(index==3){
        ui->checkBox->setVisible(true);
        ui->radioButton_part->setVisible(false);
        ui->radioButton_nbr->setVisible(false);
        ui->spinBox->setVisible(false);
    }else{
        ui->checkBox->setVisible(true);
        ui->radioButton_part->setVisible(true);
        ui->radioButton_nbr->setVisible(true);
        ui->spinBox->setVisible(true);
    }
}
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
