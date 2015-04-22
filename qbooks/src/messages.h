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
#ifndef MESSAGES_H
#define MESSAGES_H
#include <QObject>
#include <QDomDocument>
#include <QTreeWidget>
#include <QWidget>
#include <QTimer>
 #include <QLabel>
#include <QIcon>

class QComboBox;
class QProgressBar;
class QPushButton;
class QTextDocument;
class messages : public QObject
{
    Q_OBJECT

public:

    messages();
    ~messages();

   // QDomDocument docfind;
    QComboBox *comboGroup;
    QTreeWidget *treeView;

    enum { MaxRecentFiles = 16 };
    QAction *recentFileActs[MaxRecentFiles];
    QString infoBookTitle;
    QString infoBookAutor;
    QString infoBookBetaka;

    QString m_pathCostum;

public slots:
    void treeChargeSoura(QTreeWidget *view);
    void treeChargeJozaa(QTreeWidget *view);
    void treeChargeFahrass(QTreeWidget *view,QString Bname);
<<<<<<< HEAD
  QTreeWidgetItem *getItem(QTreeWidgetItem *item);
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    void treeChargeGroupe(QTreeWidget *view,int checked,bool asCombobox);
     void treeUpdateGroupe(QTreeWidget *view,bool remove);
    bool treeMenuRemoveBook(QString BKname,bool removall);
    bool treeSaveGroupe(QTreeWidget *view);
    void recentLoad();
    void recentChange(QString Bname,QString Btitle,QString Baut,QString Bid,int nbr,bool isTefsir);
    void recentCharge();
    void recentSave();
    bool fahrasSave(QTreeWidget *view,QString bkname);

    //*************************



    //***************
    void comboCharge(QComboBox *combo);
    bool addNewBook(QString bkpath,QString bktitle,QString bkauth,QString bkbetaka,QString groupid ,bool cheked);
    //*****************************


    //****************favorite***************
    void favorite_charge(QTreeWidget *view,QIcon icong,QIcon iconf);
    void favorite_save(QTreeWidget *view);
    //************************************
    bool treeviewItemRemove(QTreeWidget *view);
     bool treeviewItemUp(QTreeWidget *view);
    bool treeviewItemDown(QTreeWidget *view);
    int genirateId(QTreeWidget *view);
    bool saveBookInfo(QString bookname,QString title,QString author,QString betaka);
    bool loadBookInfo(QString bookname);
    QString geniratNewBookName(QString groupParent);
    //**********************load save result searsh
bool loadTarGz(QString path);
void removeTempDirs(QString dirName);
private slots:

bool removeTempFiles(QString tempDir);



    bool writeInDoc(QString tit,QString data,QString lvl);
//*******************************


private:

 QString m_pathUser;
QList<QString> listId;

    QDomDocument m_doc;
    QDomDocument m_docR;                             //وثيقة الكتب السابقة

};
#endif // MESSAGES_H
