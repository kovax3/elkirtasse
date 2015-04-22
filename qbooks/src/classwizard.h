<<<<<<< HEAD
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
#ifndef CLASSWIZARD_H
#define CLASSWIZARD_H
#include <QWizard>
#include "messages.h"
QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
class QTreeWidget;
QT_END_NAMESPACE

//! [0]

class ClassWizard : public QWizard
{
    Q_OBJECT

public:
    ClassWizard(QWidget *parent = 0);

    enum { Page_Intro, Page_InfoPage, Page_TreeBook, Page_Details,
           Page_Conclusion };
    void accept();
    int nextId()const;
    QString urlTexte;

};
//! [0]

//! [1]
class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

private:
    QLabel *label;
};
//! [1]

//! [2]
class ClassInfoPage : public QWizardPage
{
    Q_OBJECT

public:
    ClassInfoPage(QWidget *parent = 0);

private:
    QLabel *labelUrlName;
    QLineEdit *lineEditUrlName;
    QGroupBox *groupBox;
    QRadioButton *radioButtonUrlBook;
    QRadioButton *radioButtonUrlFavorite;
    QRadioButton *radioButtonUrlWeb;
    QLineEdit *lineEditUrlWebName;
};
//! [2]

//! [3]
class PageTreeBook : public QWizardPage
{
    Q_OBJECT

public:
    PageTreeBook(QWidget *parent = 0);
    messages *Messages;
    QTreeWidget *treeViewBook;
private slots:
    void treeBookitemSelectionChanged();
private:
    QLineEdit *bookInfo;

};
//! [3]

class PageTreeFavorite : public QWizardPage
{
    Q_OBJECT

public:    
    PageTreeFavorite(QWidget *parent = 0);
    messages *Messages;
    QTreeWidget *treeViewFavorite;
    QString curentBook;
protected:
private slots:
    void treeFavoriteItemSelectionChanged();
private:
    QLineEdit  *FavoriteInfo;
};

class ConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    ConclusionPage(QWidget *parent = 0);

protected:
    void initializePage();

private:
    QLabel *label;
};

#endif
=======
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
#ifndef CLASSWIZARD_H
#define CLASSWIZARD_H
#include <QWizard>
#include "messages.h"
QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
class QTreeWidget;
QT_END_NAMESPACE

//! [0]

class ClassWizard : public QWizard
{
    Q_OBJECT

public:
    ClassWizard(QWidget *parent = 0);

    enum { Page_Intro, Page_InfoPage, Page_TreeBook, Page_Details,
           Page_Conclusion };
    void accept();
    int nextId()const;
    QString urlTexte;

};
//! [0]

//! [1]
class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

private:
    QLabel *label;
};
//! [1]

//! [2]
class ClassInfoPage : public QWizardPage
{
    Q_OBJECT

public:
    ClassInfoPage(QWidget *parent = 0);

private:
    QLabel *labelUrlName;
    QLineEdit *lineEditUrlName;
    QGroupBox *groupBox;
    QRadioButton *radioButtonUrlBook;
    QRadioButton *radioButtonUrlFavorite;
    QRadioButton *radioButtonUrlWeb;
    QLineEdit *lineEditUrlWebName;
};
//! [2]

//! [3]
class PageTreeBook : public QWizardPage
{
    Q_OBJECT

public:
    PageTreeBook(QWidget *parent = 0);
    messages *Messages;
    QTreeWidget *treeViewBook;
private slots:
    void treeBookitemSelectionChanged();
private:
    QLineEdit *bookInfo;

};
//! [3]

class PageTreeFavorite : public QWizardPage
{
    Q_OBJECT

public:    
    PageTreeFavorite(QWidget *parent = 0);
    messages *Messages;
    QTreeWidget *treeViewFavorite;
    QString curentBook;
protected:
private slots:
    void treeFavoriteItemSelectionChanged();
private:
    QLineEdit  *FavoriteInfo;
};

class ConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    ConclusionPage(QWidget *parent = 0);

protected:
    void initializePage();

private:
    QLabel *label;
};

#endif
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
