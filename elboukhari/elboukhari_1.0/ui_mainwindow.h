/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Oct 17 20:21:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTreeList;
    QAction *actionNextKitab;
    QAction *actionPrevKitab;
    QAction *actionNextBab;
    QAction *actionPrevBab;
    QAction *actionPlayPause;
    QAction *actionStop;
    QAction *actionOption;
    QAction *actionFind;
    QAction *actionAbout;
    QAction *actionFullScreen;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QFrame *frameFind;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditFind;
    QPushButton *pushButtonFind;
    QPushButton *pushButtonFindNext;
    QSpacerItem *horizontalSpacer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolBar {\n"
"                        \n"
"	background-image: url(:/images/barBg.png);\n"
"\n"
"                          spacing: 3px;\n"
"border-width: 0px;\n"
"                         }"));
        actionTreeList = new QAction(MainWindow);
        actionTreeList->setObjectName(QString::fromUtf8("actionTreeList"));
        actionTreeList->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/view-list-details-symbolic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTreeList->setIcon(icon1);
        actionNextKitab = new QAction(MainWindow);
        actionNextKitab->setObjectName(QString::fromUtf8("actionNextKitab"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/go-first.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNextKitab->setIcon(icon2);
        actionPrevKitab = new QAction(MainWindow);
        actionPrevKitab->setObjectName(QString::fromUtf8("actionPrevKitab"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/go-last.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevKitab->setIcon(icon3);
        actionNextBab = new QAction(MainWindow);
        actionNextBab->setObjectName(QString::fromUtf8("actionNextBab"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/go-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNextBab->setIcon(icon4);
        actionPrevBab = new QAction(MainWindow);
        actionPrevBab->setObjectName(QString::fromUtf8("actionPrevBab"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/go-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevBab->setIcon(icon5);
        actionPlayPause = new QAction(MainWindow);
        actionPlayPause->setObjectName(QString::fromUtf8("actionPlayPause"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlayPause->setIcon(icon6);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/media-playback-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon7);
        actionOption = new QAction(MainWindow);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/properties.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOption->setIcon(icon8);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon9);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/help-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon10);
        actionFullScreen = new QAction(MainWindow);
        actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/view-fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFullScreen->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(graphicsView);

        frameFind = new QFrame(centralWidget);
        frameFind->setObjectName(QString::fromUtf8("frameFind"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameFind->sizePolicy().hasHeightForWidth());
        frameFind->setSizePolicy(sizePolicy);
        frameFind->setFrameShape(QFrame::NoFrame);
        frameFind->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameFind);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditFind = new QLineEdit(frameFind);
        lineEditFind->setObjectName(QString::fromUtf8("lineEditFind"));
        lineEditFind->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(lineEditFind);

        pushButtonFind = new QPushButton(frameFind);
        pushButtonFind->setObjectName(QString::fromUtf8("pushButtonFind"));

        horizontalLayout->addWidget(pushButtonFind);

        pushButtonFindNext = new QPushButton(frameFind);
        pushButtonFindNext->setObjectName(QString::fromUtf8("pushButtonFindNext"));

        horizontalLayout->addWidget(pushButtonFindNext);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frameFind);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::CustomContextMenu);
        mainToolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionTreeList);
        mainToolBar->addAction(actionOption);
        mainToolBar->addAction(actionFind);
        mainToolBar->addAction(actionFullScreen);
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPrevKitab);
        mainToolBar->addAction(actionPrevBab);
        mainToolBar->addAction(actionNextBab);
        mainToolBar->addAction(actionNextKitab);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPlayPause);
        mainToolBar->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\330\265\330\255\331\212\330\255 \330\247\331\204\330\250\330\256\330\247\330\261\331\212", 0, QApplication::UnicodeUTF8));
        actionTreeList->setText(QApplication::translate("MainWindow", "\330\247\331\204\331\201\331\207\330\261\330\263\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTreeList->setToolTip(QApplication::translate("MainWindow", "\330\247\331\204\331\201\331\207\330\261\330\263\330\251\n"
"Ctrl+L", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTreeList->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionNextKitab->setText(QApplication::translate("MainWindow", "\330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\330\252\330\247\331\204\331\212", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNextKitab->setToolTip(QApplication::translate("MainWindow", "\330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\330\252\330\247\331\204\331\212\n"
"Ctrl+PgUp", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNextKitab->setShortcut(QApplication::translate("MainWindow", "Ctrl+PgUp", 0, QApplication::UnicodeUTF8));
        actionPrevKitab->setText(QApplication::translate("MainWindow", "\330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\330\263\330\247\330\250\331\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPrevKitab->setToolTip(QApplication::translate("MainWindow", "\330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\330\263\330\247\330\250\331\202\n"
"Ctrl+PgDown", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPrevKitab->setShortcut(QApplication::translate("MainWindow", "Ctrl+PgDown", 0, QApplication::UnicodeUTF8));
        actionNextBab->setText(QApplication::translate("MainWindow", "\330\247\331\204\330\250\330\247\330\250 \330\247\331\204\330\252\330\247\331\204\331\212", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNextBab->setToolTip(QApplication::translate("MainWindow", "\330\247\331\204\330\250\330\247\330\250 \330\247\331\204\330\252\330\247\331\204\331\212\n"
"Ctrl+Left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNextBab->setShortcut(QApplication::translate("MainWindow", "Ctrl+Left", 0, QApplication::UnicodeUTF8));
        actionPrevBab->setText(QApplication::translate("MainWindow", "\330\247\331\204\330\250\330\247\330\250 \330\247\331\204\330\263\330\247\330\250\331\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPrevBab->setToolTip(QApplication::translate("MainWindow", "\330\247\331\204\330\250\330\247\330\250 \330\247\331\204\330\263\330\247\330\250\331\202\n"
"Ctrl+Right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPrevBab->setShortcut(QApplication::translate("MainWindow", "Ctrl+Right", 0, QApplication::UnicodeUTF8));
        actionPlayPause->setText(QApplication::translate("MainWindow", "\331\202\330\261\330\247\330\241\330\251 / \330\252\331\210\331\202\331\201 \331\205\330\244\331\202\330\252", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPlayPause->setToolTip(QApplication::translate("MainWindow", "\331\202\330\261\330\247\330\241\330\251 / \330\252\331\210\331\202\331\201 \331\205\330\244\331\202\330\252\n"
"Space", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPlayPause->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "\330\252\331\210\331\202\331\201", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "\330\252\331\210\331\202\331\201\n"
"Alt+S", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStop->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0, QApplication::UnicodeUTF8));
        actionOption->setText(QApplication::translate("MainWindow", "\330\256\331\212\330\247\330\261\330\247\330\252", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOption->setToolTip(QApplication::translate("MainWindow", "\330\256\331\212\330\247\330\261\330\247\330\252Ctrl+O", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOption->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("MainWindow", "\330\250\330\255\330\253", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFind->setToolTip(QApplication::translate("MainWindow", "\330\250\330\255\330\253\n"
"Ctrl+F", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "\330\255\331\210\331\204 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254", 0, QApplication::UnicodeUTF8));
        actionFullScreen->setText(QApplication::translate("MainWindow", "\331\205\331\204\330\243 \330\247\331\204\330\264\330\247\330\264\330\251", 0, QApplication::UnicodeUTF8));
        actionFullScreen->setShortcut(QApplication::translate("MainWindow", "F11", 0, QApplication::UnicodeUTF8));
        pushButtonFind->setText(QApplication::translate("MainWindow", "\330\250\330\255\330\253 \331\201\331\212 \330\247\331\204\330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
        pushButtonFindNext->setText(QApplication::translate("MainWindow", "\330\250\330\255\330\253 \330\271\331\206 \330\247\331\204\330\252\330\247\331\204\331\212", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "\330\243\330\262\330\261\330\247\330\261 \331\202\331\212\330\247\330\263\331\212\330\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
