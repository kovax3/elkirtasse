/****************************************************************************/
// 
// 
// All rights reserved.
// Contact: abouzakaria (yahia67@live.com)
// 
/   elkirtasse Copyright (C) 2010  yahia abouzakaria  <yahiaui@gmail.com>
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
//If you have questions regarding the use of this file, please contact
// abouzakaria (yahia67@live.com)
// $elkirtasse_END_LICENSE$
/****************************************************************************/

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

}
Print::~Print()
{

}

void Print::on_buttonBox_clicked(QAbstractButton* button)
{

    if(ui->buttonBox->standardButton(button)==QDialogButtonBox::Ok)
    {
        if (ui->comboBox->currentIndex()==2)
        {
            int reponse = QMessageBox::warning(this, trUtf8("تنبيه"), trUtf8("ان حفظ الكتاب بهذه الصيغة يأخذ وقتا أطول سيما اذا كان الكتاب كبيرا \n هل تريد المتابعة؟") , QMessageBox::Yes | QMessageBox::Cancel);
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
            QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن انشاء الملف في هذا الدليل"));
            return;
        }



        m_fileName=ui->lineEdit->text()+"/"+m_bookTitle+"/"+m_bookTitle+"_";
        ui->frame->setVisible(true);
        button->setEnabled(false);
        ui->frame_2->setEnabled(false);
        if (openBook()==true)
        {
            creatDocument();
        }
    }
}
bool Print::openBook()
{
   // QString path=QCoreApplication::applicationDirPath ();
    //  QString path=curentPath;
                   QString bkpath=curentPath +"/book.xml";           //مسار الكتاب
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
        QString   bookNass= noeud.firstChildElement("nass").firstChild().toText().data();
        QString   bookPage= noeud.firstChildElement("page").firstChild().toText().data();
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
        convertText("<br>"+bookNass,bookPart,bookPage,i+1);
    }

    if (fileSave()==false)
    {
        QMessageBox::critical(this,trUtf8("خطأ"), trUtf8("لا يمكن حفظ الملف"));
        return;
    }
    QMessageBox::information(this,trUtf8("حفظ"), trUtf8("تمت عملية الحفظ بنجاح"));
    this->reject();
}
void Print::convertText(QString txt,QString part,QString page, int id)
{

    txt.replace(QByteArray("\n"), QByteArray("<br>"));
    txt.replace(QByteArray("\r"), QByteArray("<br>"));
    //*******************************************
 // QString id=DataBook->bookCurentId[m_currentBookIndex];
    if (txt.contains("$")){
         txt.replace("$", "");
    }


     QVariant dd=id;
   QTreeWidgetItem *item=new QTreeWidgetItem;
    QList<QTreeWidgetItem *> found =
           treeviw->findItems(
                    dd.toString(),Qt::MatchExactly | Qt::MatchRecursive,1);//تنشاء قائمة بكل العناصر

        foreach (item, found){

            //    QMessageBox::information(this,trUtf8("llop"),item->text(0));
             txt.replace( item->text(0)+"<br>","< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
             txt.replace("  "+ item->text(0),"< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'><br> "+item->text(0)+"</font><br>");
             txt.replace("<br>"+ item->text(0),"< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'><br> "+item->text(0)+"</font><br>");
             txt.replace( item->text(0)+"<br>","< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
             txt.replace( item->text(0)+" <br>","< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+"</font><br>");
             txt.replace( item->text(0)+" :","< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+" :</font><br>");
             txt.replace( item->text(0)+".","< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"'> "+item->text(0)+". </font><br>");

             if(txt.trimmed()== item->text(0).trimmed()){
                 txt="< font face='"+m_WebFontTitle+"' color='"+m_WebFontTitleColor+"' > "+item->text(0)+" </font>";
             }
         }

    //********************************************
    QRegExp rxi("_____+");
    QRegExp rxd("ـــــ+");
        txt.replace(rxi," < font size='1'><br>__________");
        txt.replace(rxd," < font size='1'><br>__________");
        txt.replace("صلى الله عليه وسلم","< font color='"+m_WebFontPrefertColor+"' >صلى الله عليه وسلم</font> ");
        txt.replace("C تعالى","< font color='"+m_WebFontPrefertColor+"' >رحمه الله تعالى</font> ");
         txt.replace("{","< font color='"+m_WebFontPrefertColor+"' >﴿</font> ");
         txt.replace("}","< font color='"+m_WebFontPrefertColor+"' >﴾</font> ");
        txt.replace("رضي الله عنهم ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنهم </font> "));
        txt.replace("رضي الله عنه ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
        txt.replace("رضي الله عنهما ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("' >رضي الله عنهما </font> "));
        txt.replace(" A ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'> صلى الله عليه سلم </font> "));
        txt.replace("Bه",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>رضي الله عنه </font> "));
        txt.replace(" D ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'>  تعالى </font> "));
        txt.replace(" E ",trUtf8("< font color='")+m_WebFontPrefertColor+trUtf8("'> عليه السلام </font> "));

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


        m_textEdit->insertHtml(txt);
        if (ui->checkBox->isChecked())
        {
            m_textEdit->insertHtml("<br><font size='1' ><p> __________الجزء : "+part+" /الصفحة : "+page+"__________</p></font><p align=\"right\"></p>");
        }



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
