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

#ifndef DIALOGCONFIGBOOKS_H
#define DIALOGCONFIGBOOKS_H
#include "messages.h"
#include <QDialog>

namespace Ui {
    class DialogConfigBooks;
}

class DialogConfigBooks : public QDialog
{
    Q_OBJECT
    messages *Messages;
public:
    explicit DialogConfigBooks(QWidget *parent = 0);
    ~DialogConfigBooks();
QString pathCostm;
public slots:
void setPathCostum(QString path);
private slots:
    void on_comboBoxSection_activated(int index);

    void on_toolButtonBookToGroup_clicked();

    void on_toolButtonGroupTosection_clicked();

    void on_treeWidgetCurGroup_itemSelectionChanged( );

    void on_toolButtonSectionAdd_clicked();

    void on_toolButtonGroupAdd_clicked();

    void on_toolButtonGrouprename_clicked();

    void on_treeWidgetBooks_itemSelectionChanged();

    void on_toolButtonSectionRname_clicked();

    void on_toolButtonSectionRemove_clicked();

    void on_toolButtonGroupRemove_clicked();

    void on_toolButtonRemoveBooks_clicked();

    void on_pushButtonImg_clicked();

    void on_toolButtonUpdatBk_clicked();

    void on_toolButtonOPenGroup_clicked();

    void on_toolButtonGroupUpdat_clicked();

    void on_toolButtonBkPath_clicked();

    void on_toolButtonRenBkPath_clicked();



    void on_buttonBox_accepted();

    void on_toolButtonFindBKOld_clicked();
void addbook(QTreeWidgetItem *itemNew,QTreeWidgetItem *item,QString name);


void on_treeWidgetCurGroup_itemActivated(QTreeWidgetItem , int );

void on_treeWidgetCurGroup_itemClicked(QTreeWidgetItem , int );

void on_toolButtonReloadAll_clicked();

private:
    Ui::DialogConfigBooks *ui;
      int indexGroup;
      bool imgChanged;
      QStringList listRenameBk;
 QString     pathCostmOld;
};

#endif // DIALOGCONFIGBOOKS_H
