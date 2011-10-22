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


#ifndef DIALOGCONVERT_H
#define DIALOGCONVERT_H
#include <QDialog>
#include "messages.h"
 #include <QTextEdit>

namespace Ui
{
    class dialogconvert;
}

class dialogconvert : public QDialog
{
    Q_OBJECT
    messages *Messages;
public:
    dialogconvert(QWidget *parent = 0);
    ~dialogconvert();
    QString m_pathCostum;
private:
    Ui::dialogconvert *ui;
    bool creat_xmlfile(QString path);
    bool load(const QString &f);
    bool creat_dir();
    bool ecrirexml(int jozaa);
    QTextEdit m_textEdit;
    QDomDocument m_docBook;
    QString m_newPath;
    QString m_newPathDir;
    QString m_addGroupeId;
int creatId;
public slots:


private slots:

    void on_toolButton_down_clicked();
    void on_toolButton_up_clicked();
    void on_toolButton_delete_clicked();
    void on_comboBox_group_currentIndexChanged(int index);
    void on_toolButton_fileNam_clicked();
    void on_pushButton_clicked();


};
#endif // DIALOGCONVERT_H
