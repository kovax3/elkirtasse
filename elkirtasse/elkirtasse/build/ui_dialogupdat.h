/********************************************************************************
** Form generated from reading UI file 'dialogupdat.ui'
**
** Created: Thu Oct 6 18:58:31 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUPDAT_H
#define UI_DIALOGUPDAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogupdat
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonImg;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_booknam;
    QLabel *label_2;
    QLineEdit *lineEdit_autor;
    QLabel *label_4;
    QComboBox *comboBox_group;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QTextEdit *textBrowser;
    QCheckBox *checkBox_curan;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogupdat)
    {
        if (dialogupdat->objectName().isEmpty())
            dialogupdat->setObjectName(QString::fromUtf8("dialogupdat"));
        dialogupdat->resize(416, 266);
        dialogupdat->setLayoutDirection(Qt::RightToLeft);
        verticalLayout_2 = new QVBoxLayout(dialogupdat);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonImg = new QPushButton(dialogupdat);
        pushButtonImg->setObjectName(QString::fromUtf8("pushButtonImg"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonImg->sizePolicy().hasHeightForWidth());
        pushButtonImg->setSizePolicy(sizePolicy);
        pushButtonImg->setMinimumSize(QSize(136, 128));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/booki.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonImg->setIcon(icon);
        pushButtonImg->setIconSize(QSize(128, 128));

        horizontalLayout_2->addWidget(pushButtonImg);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(dialogupdat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_booknam = new QLineEdit(dialogupdat);
        lineEdit_booknam->setObjectName(QString::fromUtf8("lineEdit_booknam"));

        gridLayout->addWidget(lineEdit_booknam, 0, 1, 1, 1);

        label_2 = new QLabel(dialogupdat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_autor = new QLineEdit(dialogupdat);
        lineEdit_autor->setObjectName(QString::fromUtf8("lineEdit_autor"));

        gridLayout->addWidget(lineEdit_autor, 1, 1, 1, 1);

        label_4 = new QLabel(dialogupdat);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        comboBox_group = new QComboBox(dialogupdat);
        comboBox_group->setObjectName(QString::fromUtf8("comboBox_group"));

        gridLayout->addWidget(comboBox_group, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(dialogupdat);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        textBrowser = new QTextEdit(dialogupdat);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout->addWidget(textBrowser);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        checkBox_curan = new QCheckBox(dialogupdat);
        checkBox_curan->setObjectName(QString::fromUtf8("checkBox_curan"));

        verticalLayout_2->addWidget(checkBox_curan);

        buttonBox = new QDialogButtonBox(dialogupdat);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(dialogupdat);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogupdat, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogupdat, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogupdat);
    } // setupUi

    void retranslateUi(QDialog *dialogupdat)
    {
        dialogupdat->setWindowTitle(QApplication::translate("dialogupdat", "\330\252\330\271\330\257\331\212\331\204 \330\250\331\212\330\247\331\206\330\247\330\252 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        pushButtonImg->setText(QString());
        label->setText(QApplication::translate("dialogupdat", "\330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialogupdat", "\330\247\330\263\331\205 \330\247\331\204\331\205\330\244\331\204\331\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dialogupdat", "\330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        comboBox_group->setWhatsThis(QApplication::translate("dialogupdat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\256\330\252\330\261 \330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251 \330\247\331\204\330\252\331\212 \330\263\331\212\330\252\331\205 \330\247\330\266\330\247\331\201\330\251 \330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\331\212\331\207\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("dialogupdat", "\330\250\330\267\330\247\331\202\330\251 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        checkBox_curan->setWhatsThis(QApplication::translate("dialogupdat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\271\331\204\331\205 \331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \330\247\330\260\330\247 \331\203\330\247\331\206 \331\203\330\252\330\247\330\250 \330\247\331\204\330\252\331\201\330\263\331\212\330\261 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\255\331\202\331\210\331\204 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">   \"Aya\" \331\210\330\255\331\202\331\204 \"Sora\"</p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_curan->setText(QApplication::translate("dialogupdat", "\330\252\331\201\330\263\331\212\330\261 \331\205\331\201\331\207\330\261\330\263 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogupdat: public Ui_dialogupdat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUPDAT_H
