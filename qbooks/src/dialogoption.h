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


private:
    Ui::Dialogoption *ui;

    QString m_btnStyleDown;
    QString m_btnStyleUp;
    QFont  fontName;
    QString fontTitleName;
    QString colorBack;
    QString colorFont;
    QString fontTitleSize;
    QString fontHachiaName;
    QString fontKhasse;
    QString colorTitle;
    QString colorPrefer;
    QString colorFind;
    QString themesStyle;
    QString pathCostm;
    QString cadreFolder;

private slots:
    void on_toolButton_10_clicked();
<<<<<<< HEAD
//    void on_comboBoxCadre_currentIndexChanged(QString img );
=======
    void on_comboBoxCadre_currentIndexChanged(QString img );
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
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
<<<<<<< HEAD


    void on_checkBoxStandardTool_clicked();

    void on_toolButtonStyleCostum_clicked();

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
public slots:
    //-------------set------------

    void setArabicNumber(int arg);
    int getArabicNumber();
    void setFontName(QFont f);
    void setFontTitleName(QString arg);
    void setLayouDir(bool arg);
    void setColorBack(QString arg);
    void setColorFont(QString arg);
    void setFontTitleSize(QString arg);
    void setFontHachiaName(QString arg);
    void setFontKhasse(QString arg);
    void setcolorTitle(QString arg);
    void setColorPrefer(QString arg);
    void setColorFind(QString arg);
    void setThemesStyle(QString arg);
    void setPathCostm(QString arg);
    void setCadreFolder(QString arg);
    void setWebCadre(bool arg);
    void setIconsThemes(bool arg);
    void setRecentNbr(int arg);
     void setLng(int arg);
<<<<<<< HEAD
     void setStandardTool(bool st);
 void setTxtUnderIcon(bool istxt);
 bool getTxtUnderIcon();
 void setIconSize(int s);
 int getIconSize();
 void setStyleType(bool arg);
 bool getStyleType();
 void setStyleSheetName(QString arg);
 QString getStyleSheetName();
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    //---------get----------
    QFont  getFontName();
    QString getFontTitleName();
    QString getColorBack();
    bool getLayouDir();
    QString getColorFont();
    QString getFontTitleSize();
    QString getFontHachiaName();
    QString getFontKhasse();
    QString getcolorTitle();
    QString getColorPrefer();
    QString getColorFind();
    QString getThemesStyle();
    QString getPathCostm();
    QString getCadreFolder();
    bool getWebCadre();
<<<<<<< HEAD
  bool getsetStandardTool();
=======

>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    bool getIconsThemes();
    int getRecentNbr();

    int getLng();
    /*



 */
};
#endif // DIALOGOPTION_H
