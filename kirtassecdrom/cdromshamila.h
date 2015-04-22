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
#ifndef CDROMSHAMILA_H
#define CDROMSHAMILA_H
#include "src/booksInterface.h"
#include <QDomDocument>
#include <QList>
 #ifdef   Q_WS_WIN
#include <QSqlDatabase>
 #endif
class cdromShamila : public QObject, ShamilaInterface
{
    Q_OBJECT
    Q_INTERFACES(ShamilaInterface)
public:

private:

    QString m_pathMain;
    QString m_pathBooks;
    QString m_pathBooksNew;
    QString m_tempDir;
    QDomDocument m_doc;
    QList<QString> listId;
#ifdef   Q_WS_WIN
    QSqlDatabase m_db;
#endif
    int  tbcount;
signals:

public slots:
    QString execPlugin();
private slots:



    bool creatShamellaX();
#ifdef   Q_WS_WIN
    bool creatShamellaWin();
    bool winCreatBooks();
    bool  winCreatgroupXml();
    bool winWriteBooks(QString fn,QString bookname);
#endif
    bool creatBashMain(QString fn);
    //  bool creatListBooks();
    bool creatCatigorie();
    bool creatBooksInfo();
    bool creatBashMdb(QString fn);
    bool creatBook(QString id,QString cat);
    bool addNewBook(QString bkpath,QString bktitle,QString bkauth,QString bkbetaka,QString groupid);
    bool creatXmlFile(QString f,QString table,QString csv);
    bool saveBookInfo(QString bookname,QString title,QString author,QString betaka);
};

#endif // CDROMSHAMILA_H
