// -------------------------------------------------
//  Project created by QtCreator 2011-04-30T21:17:32
/* -----------------------------------------------------
// 
//   elboukhari Copyright (C) 2011  <abouzakaria  yahiaui@gmail.com>
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
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QGraphicsWidget>
#include <QPropertyAnimation>
#include <QGraphicsGridLayout>
#include <QTreeWidget>
#include <QLineEdit>

#include <phonon/audiooutput.h>
#include <phonon/backendcapabilities.h>
#include <phonon/effect.h>
#include <phonon/effectparameter.h>
#include <phonon/effectwidget.h>
#include <phonon/mediaobject.h>
#include <phonon/seekslider.h>
#include <phonon/videowidget.h>
#include <phonon/volumeslider.h>
class Ui_settings;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
void initSettingsDialog();


protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;

    QDialog *settingsDialog;
     Ui_settings *UI;
    QGraphicsScene *mscene;
    enum { WidgetIndex = 4 };
    QTextBrowser *txtBrewser[WidgetIndex];
    QGraphicsWidget *widget[WidgetIndex];
    QPropertyAnimation *animGroup;
    QGraphicsWidget *widgetOption;
    QGraphicsWidget *widgetFahrasa;
    QTreeWidget *treeWidgetFahrasa;
    QLineEdit *lineEditSearch;
    QIcon playIcon;
    QIcon pauseIcon;
    int m_curWidget;
    int m_curText;
    int m_nextText;
    int m_prevText;
    int m_rowCount;
    QString m_curFile;
    int m_curIndex;
    QList<QString > m_listNass;
    QList<QString > m_listFile;
    bool animRuned;

//setting
    QString m_font;
    QString m_mediaFolder;
    bool m_autoPlay;
    bool m_autoRepeat;
    bool m_autoPlayNext;
    bool m_autoStop;

    //Phonon
    Phonon::MediaObject m_MediaObject;
    Phonon::AudioOutput m_AudioOutput;
    Phonon::SeekSlider *slider;
    Phonon::VolumeSlider *volume;
private slots:

    //sigal
    void on_actionFullScreen_triggered();
    void on_actionAbout_triggered();
    void on_pushButtonFindNext_clicked();
    void on_pushButtonFind_clicked();
    void on_actionFind_toggled(bool v);
    void on_actionOption_triggered();
    void on_actionPrevKitab_triggered();
    void on_actionNextKitab_triggered();
    void on_actionStop_triggered();
    void on_actionPlayPause_triggered();
    void on_actionTreeList_toggled(bool );
    void on_actionNextBab_triggered();
    void on_actionPrevBab_triggered();
    void fahrasItemActivated(QTreeWidgetItem *item);
    //chargment
    void chargePages();
    void treeChargeFahrassa();
    void creatFahrasa();
    void creatCadre(QGraphicsGridLayout *gridLayout);

   //animation
    void animFahrasa(bool open);
    void animFahrasaFinished();
    void animPagesLeft();
    void setCurWidgetLeft();
    void animPagesRight();
    void setCurWidgetRight();

    //text
       QString convertText(QString txt);
    //phonon
    void playCurentMedia();
    void setCurentPage(int index);
    void stateChanged(Phonon::State newstate, Phonon::State oldstate);
    void mediaFinished();
    //setting
    void openDialogFolder();
    void openFont();
    void loadSettings();
    void saveSettings();
    //find
    bool searchInDoc(QTextDocument *document,QString searchString);
    void findNext(QTextDocument *document,QString searchString);
    void searchInTreeview();
    bool searchTreeForString( const QString &searchString, QTreeWidgetItem* parent,bool itemtop,int  topindex,QTreeWidget *view,int colum);
bool showAllItems( QTreeWidgetItem* parent,QTreeWidget *view );
};

#endif // MAINWINDOW_H
