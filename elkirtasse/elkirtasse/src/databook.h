/****************************************************************************
**
** #
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

#ifndef DATABOOK_H
#define DATABOOK_H
#include <QObject>
#include <QDomDocument>
#include <QtGui>
class databook : public QObject
{
    Q_OBJECT

public:
   // enum  { NumRows = 10};
      static const int NumRows=10 ;
    databook();
    ~databook();
    bool isTefsir;
     int newPosition[NumRows];
   // int prevPosition[NumRows];
    int currentPosition[NumRows];
    int rowsCount[NumRows];
    int boocNumIndex;
bool removeTechkile;
    QString bookNass[NumRows];
    QString bookPart[NumRows];
    QString bookPage[NumRows];
    QString bookCurentId[NumRows];

    QString m_currentBookPath[NumRows];
public slots:
    bool getIfTefsir();
    bool openBook(QString bookName,int position,QString bkpath);
    void moveToPosition(int position);
    bool findAya(QString soura,QString aya);
    void updatPage(QString oldText,QString newText,bool fullText);
    bool saveBook();
    void claerBook(int num);


  void treeOrganizFahrass(QTreeWidget *view,QString Bname);
private slots:
     QString noTechkile(QString text) const;
  bool chargeList();
   int getPositionID(QString id);
private:
  QString m_currentBookName[NumRows];
    QDomDocument m_docBooK[NumRows];

QList<QString> listId;

};
#endif // DATABOOK_H
