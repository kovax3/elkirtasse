/********************************************************************************
** Form generated from reading UI file 'dialogmdb.ui'
**
** Created: Thu 24. Jan 11:03:23 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMDB_H
#define UI_DIALOGMDB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogmdb
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_fileNam;
    QToolButton *toolButtonDelete;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButtonInfo;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QCheckBox *checkBox_curan;
    QLabel *label_6;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogmdb)
    {
        if (Dialogmdb->objectName().isEmpty())
            Dialogmdb->setObjectName(QString::fromUtf8("Dialogmdb"));
        Dialogmdb->resize(470, 359);
        verticalLayout_2 = new QVBoxLayout(Dialogmdb);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget = new QListWidget(Dialogmdb);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton_fileNam = new QToolButton(Dialogmdb);
        toolButton_fileNam->setObjectName(QString::fromUtf8("toolButton_fileNam"));
        toolButton_fileNam->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(toolButton_fileNam);

        toolButtonDelete = new QToolButton(Dialogmdb);
        toolButtonDelete->setObjectName(QString::fromUtf8("toolButtonDelete"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/edit-delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonDelete->setIcon(icon);
        toolButtonDelete->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(toolButtonDelete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolButtonInfo = new QToolButton(Dialogmdb);
        toolButtonInfo->setObjectName(QString::fromUtf8("toolButtonInfo"));
        toolButtonInfo->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(toolButtonInfo);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        verticalLayout->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(Dialogmdb);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_4);

        comboBox = new QComboBox(Dialogmdb);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        checkBox_curan = new QCheckBox(Dialogmdb);
        checkBox_curan->setObjectName(QString::fromUtf8("checkBox_curan"));

        verticalLayout_2->addWidget(checkBox_curan);

        label_6 = new QLabel(Dialogmdb);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        progressBar = new QProgressBar(Dialogmdb);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(1000);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(progressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(Dialogmdb);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(Dialogmdb);
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogmdb, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogmdb);
    } // setupUi

    void retranslateUi(QDialog *Dialogmdb)
    {
        Dialogmdb->setWindowTitle(QApplication::translate("Dialogmdb", "\330\247\330\263\330\252\330\261\330\247\330\257 \331\205\331\204\331\201\330\247\330\252 \330\247\331\204\331\205\331\203\330\252\330\250\330\251 \330\247\331\204\330\264\330\247\331\205\331\204\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        toolButton_fileNam->setWhatsThis(QApplication::translate("Dialogmdb", "\330\247\331\206\331\202\330\261 \331\207\331\206\330\247 \331\204\330\247\330\256\330\252\331\212\330\247\330\261 \330\247\331\204\331\205\330\263\330\247\330\261", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toolButton_fileNam->setText(QApplication::translate("Dialogmdb", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        toolButtonDelete->setWhatsThis(QApplication::translate("Dialogmdb", "\330\255\330\260\331\201 \330\247\331\204\330\271\331\206\330\265\330\261 \330\247\331\204\331\205\330\255\330\257\330\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toolButtonDelete->setText(QApplication::translate("Dialogmdb", "\330\255\330\260\331\201 \330\247\331\204\330\271\331\206\330\265\330\261 \330\247\331\204\331\205\330\255\330\257\330\257", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonInfo->setToolTip(QApplication::translate("Dialogmdb", "\331\205\330\271\331\204\331\210\331\205\330\247\330\252  \330\271\331\206 \330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\331\205\330\255\330\257\330\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toolButtonInfo->setWhatsThis(QApplication::translate("Dialogmdb", "\331\205\330\271\331\204\331\210\331\205\330\247\330\252  \330\271\331\206 \330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\331\205\330\255\330\257\330\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toolButtonInfo->setText(QApplication::translate("Dialogmdb", "\330\237", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialogmdb", "\330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("Dialogmdb", "\331\205\331\206 \331\207\331\206\330\247 \331\212\331\205\331\203\331\206\331\203 \330\247\330\256\330\252\331\212\330\247\330\261 \330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251 \330\247\331\204\330\252\331\212 \330\263\331\212\330\266\330\247\331\201 \330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\331\212\331\207\330\247", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        checkBox_curan->setWhatsThis(QApplication::translate("Dialogmdb", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\271\331\204\331\205 \331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \330\247\330\260\330\247 \331\203\330\247\331\206 \331\203\330\252\330\247\330\250 \330\247\331\204\330\252\331\201\330\263\331\212\330\261 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\255\331\202\331\210\331\204 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">   \"Aya\" \331\210\330\255\331\202\331\204 \"Sora\"</p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_curan->setText(QApplication::translate("Dialogmdb", "\330\252\331\201\330\263\331\212\330\261 \331\205\331\201\331\207\330\261\330\263 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialogmdb", ".", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialogmdb: public Ui_Dialogmdb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMDB_H
