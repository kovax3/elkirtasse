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
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "booksInterface.h"
// #include <QSplashScreen>
 #include <QTranslator>
 #include <QLocale>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon;
    QPixmap pixmap(":/images/image/titlekirtasse.png");
    QSplashScreen splash(pixmap);
    splash.setMask(QBitmap(pixmap.mask()));
     splash.show();
    a.processEvents();
    QDir dir;
    QString h=dir.homePath();

    if (!dir.exists(h+"/.kirtasse")) //التاكد من وجود مجلد المكتبة
    {
        dir.mkdir( h+"/.kirtasse");
    }
    if (!dir.exists(h+"/.kirtasse/data")) //التاكد من وجود مجلد البياات
    {
        dir.mkdir( h+"/.kirtasse/data");
    }
    if (!dir.exists(h+"/.kirtasse/books")) //التاكد من وجود مجلد الكتاب
    {
        dir.mkdir( h+"/.kirtasse/books");
    }
    QFile file;

    if (!file.exists(h+"/.kirtasse/data/group.xml")){
        file.copy(QCoreApplication::applicationDirPath() +"/data/group.xml",h +"/.kirtasse/data/group.xml");
    }


QLocale::setDefault(QLocale(QLocale::Arabic, QLocale::Egypt));
    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&a);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        a.installTranslator(translator);

    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/image/groupbook.png")), QIcon::Normal, QIcon::Off);
    a.setWindowIcon(icon);
    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
