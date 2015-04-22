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
#include <QtGui>

#include "networkplugin.h"

//! [0]


//! [1]
QString networkplugin::execPlugin()
{
    //QMessageBox::information(0,"","exec");
Dialognet *dlg =new Dialognet();
if ( dlg->exec() == QDialog::Accepted ){
  return dlg->mypath;
}
return "";
}
<<<<<<< HEAD
QString networkplugin::loadFile(QString urlPath)
{

Dialognet *dlg =new Dialognet();
if (dlg->downloadFile(urlPath,QDir::homePath()+"/.kirtasse/download/")==true){

    return dlg->mypath;
}
return "";
}
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
//! [1]
QString networkplugin::pluginTitle()
{
    return trUtf8("تحميل الكتب");
}

//! [2]
Q_EXPORT_PLUGIN2(kirtassenet, networkplugin);
//! [2]
