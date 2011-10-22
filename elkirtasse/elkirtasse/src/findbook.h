/****************************************************************************/
// 
// #
// All rights reserved.
// Contact: abouzakaria (yahia67@live.com)
// 
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
//If you have questions regarding the use of this file, please contact
// abouzakaria (yahia67@live.com)
// $elkirtasse_END_LICENSE$
/****************************************************************************/

#ifndef FINDBOOK_H
#define FINDBOOK_H
#include <QObject>
#include <QTreeWidget>
#include <QDomDocument>
#include <QXmlStreamReader>
class QProgressBar;
class QAction;
class QLabel;
class QTextDocument;
class QPushButton;

class findbook : public QObject
{
    Q_OBJECT

public:


    findbook();
    ~findbook();


    QTreeWidget *treeView;
    QLabel *labelProgress;
    QLabel *label_progressImg;
    QProgressBar *progressBar1;
    QAction *buttonStop;
    QString  findText;
    QString  findTitle;
    QString findAuthor;
    QString findName;
bool isTefsir;
    //مسار البرنامج
 bool isNassToFind;
    QString pathCostum;
    int resultCount;
    int getFind;
    bool isFindRuned;
    bool findToList;
    bool findFirst;
    bool stopFind;
    bool findMultiFind;
    bool findAnd;
    bool findSawabik;
private:
    int m_listbkfind;
    QList<QString> m_listStrToFind;

    QString m_pathUser;

    int m_progresseValue;

    QXmlStreamReader xml;

    QDomDocument m_docBKfindlist;                   //وثيقة قائمة الكتب للبحث

    QString str;
    QString id;
    QString page;
    QString part;
public slots:
    void findOneBook(QString bookpath);
    void findInAllBook(bool inbooks);
void findInAllFahariss(QString bookpath);

void findFahariss(QTreeWidget *view,QString bookpath,QRegExp str1,QRegExp str2,int rowcount);
//*****************************
    bool searchInDoc(QTextDocument *document,QString searchString,QColor color);
    void searchInTreeview(QTreeWidget *view,QString searchString,int colum);

    //**********************load save result searsh
    void loadResultFind(QTreeWidget *view,QString fn);
    bool saveResultFind(QTreeWidget *view,QString fn);

private slots:
void readStrFirst();
    void readXml();
    void readStrMultiFind();
    void readStr();
    bool chargelistStrToFind(QString search);
    bool chargelistStrMultiFind(QString search);
    bool showAllItems( QTreeWidgetItem* parent ,QTreeWidget *view) ;
    bool searchTreeForString( const QString &searchString, QTreeWidgetItem* parent ,bool  itemtop,int  topindex,QTreeWidget *view,int colum) ;


};
#endif // FINDBOOK_H
