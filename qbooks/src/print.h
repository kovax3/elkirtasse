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
#ifndef PRINT_H
#define PRINT_H
#include <QDialog>
#include "databook.h"
#include <QTreeWidget>
#include <QDomDocument>

namespace Ui
{
    class Print;
}

class Print : public QDialog
{
    Q_OBJECT

public:
    Print(QWidget *parent = 0);
    ~Print();
   QTreeWidget *treeviw;
   // QString m_bookName;


    void setBookTitle(QString name);
    void setBookAuthor(QString name);
  void setBookBetaka(QString name);
   void setBookColorBack(QString name);
   void setBookFont(QString name);
   void setBookFontColor(QString name);
    void setBookFontTitleColor(QString name);
    void setBookFontPrefertColor(QString name);
    void setBookCurentPath(QString name);
     void setBookFontTitle(QString name);
<<<<<<< HEAD
     void setpathApp(QString path);
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
private:
    Ui::Print *ui;
    QDomDocument m_docBooK;
    int rowsCount;
    QString m_fileName;
    QTextEdit* m_textEdit;
    int mCurPart;
 int m_n;
 QString m_bookTitle;
 QString m_bookAuthor;
QString    m_bookBetaka;
 QString m_WebColorBack;                           //لون خلفية النص
 QString m_WebFont;                            //نوع النص
 QString m_WebFontColor;
 QString m_WebFontTitleColor;
 QString m_WebFontPrefertColor;
 QString m_curentPath;
 QString m_WebFontTitle;
<<<<<<< HEAD
 QString m_pathApp;
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
private slots:

    void on_toolButton_clicked();
    void on_buttonBox_clicked(QAbstractButton* button);
    bool openBook();

    bool fileSave();
    void creatDocument();
<<<<<<< HEAD
    QString convertTextBetaka(QString txt);
    QString convertText(QString txt,QString part,QString page,int id);
    QString convertEpubStyle(QString txt,QString part,QString page, int id);
  //html
 void    creatHtmlDocument(bool isQml);
 void creatHtmlFahrassa(bool isQml );
QString getChildHtml(QTreeWidgetItem *item);
bool creatHtmlPages(bool isQml);
=======
    QString convertText(QString txt,QString part,QString page,int id);
    QString convertEpubStyle(QString txt,QString part,QString page, int id);
  //html
 void    creatHtmlDocument();
 void creatHtmlFahrassa();
QString getChildHtml(QTreeWidgetItem *item);
bool creatHtmlPages();
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    //  epub
void creatEpubDocument();
bool   creatEpubDIrectory();
bool creatEpubContent();
 bool  creatEpubToc();
 QString getChildNavpoint(QTreeWidgetItem *item);
bool creatEpubInfo();
bool creatEpubPages();
bool   zipUpubDocument();
void on_comboBox_currentIndexChanged(int index);
<<<<<<< HEAD
void removeTempDirs(QString dirName);
bool removeTempFiles(QString tempDir);

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
};

#endif // PRINT_H
