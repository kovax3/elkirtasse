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
#ifndef DIALOGOPTION_H
#define DIALOGOPTION_H
#include <QDialog>

namespace Ui
{
    class Dialogoption;
}

class Dialogoption : public QDialog
{
    Q_OBJECT

public:
    Dialogoption(QWidget *parent = 0);
    ~Dialogoption();
    QFont  fontName;
 QString fontTitleName;
 QString fontTitleSize;
   QString  fontHachiaName;
    QString colorFont;
    QString colorTitle;
    QString colorPrefer;
    QString colorFind;
    QString colorBack;
    QString themesStyle;
    QString pathCostm;
    QString cadreFolder;
    bool webCadre;
    int recentNbr;
private:
    Ui::Dialogoption *ui;

    QString m_btnStyleDown;
    QString m_btnStyleUp;


private slots:
    void on_comboBoxCadre_currentIndexChanged(QString img );
    void on_toolButton_3_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_costmPath_clicked();

    void on_buttonBox_accepted();
    void on_toolButton_clicked();
    void on_pushButton_backcolor_clicked();
    void on_pushButton_findcolor_clicked();
    void on_pushButton_prefercolor_clicked();
    void on_pushButton_titlecolor_clicked();
    void on_pushButton_fontcolor_clicked();
public slots:
    void recharge();
};
#endif // DIALOGOPTION_H
