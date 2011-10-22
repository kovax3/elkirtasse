/********************************************************************************
** Form generated from reading UI file 'mdbexport.ui'
**
** Created: Fri Sep 9 14:57:42 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDBEXPORT_H
#define UI_MDBEXPORT_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_mdbexport
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLineEdit *lineEdit_fileNam;
    QToolButton *toolButton_fileNam;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *lineEdit_booknam;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit_autor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_curan;
    QVBoxLayout *verticalLayout;
    QLabel *label_Info;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *mdbexport)
    {
        if (mdbexport->objectName().isEmpty())
            mdbexport->setObjectName(QString::fromUtf8("mdbexport"));
        mdbexport->resize(397, 442);
        mdbexport->setLayoutDirection(Qt::RightToLeft);
        verticalLayout_2 = new QVBoxLayout(mdbexport);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(mdbexport);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_3);

        lineEdit_fileNam = new QLineEdit(mdbexport);
        lineEdit_fileNam->setObjectName(QString::fromUtf8("lineEdit_fileNam"));

        horizontalLayout_7->addWidget(lineEdit_fileNam);

        toolButton_fileNam = new QToolButton(mdbexport);
        toolButton_fileNam->setObjectName(QString::fromUtf8("toolButton_fileNam"));

        horizontalLayout_7->addWidget(toolButton_fileNam);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(mdbexport);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(label);

        lineEdit_booknam = new QLineEdit(mdbexport);
        lineEdit_booknam->setObjectName(QString::fromUtf8("lineEdit_booknam"));

        horizontalLayout_6->addWidget(lineEdit_booknam);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(mdbexport);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_autor = new QLineEdit(mdbexport);
        lineEdit_autor->setObjectName(QString::fromUtf8("lineEdit_autor"));

        horizontalLayout_5->addWidget(lineEdit_autor);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(mdbexport);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_4);

        comboBox = new QComboBox(mdbexport);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(mdbexport);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        textEdit = new QTextEdit(mdbexport);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        checkBox_curan = new QCheckBox(mdbexport);
        checkBox_curan->setObjectName(QString::fromUtf8("checkBox_curan"));

        verticalLayout_2->addWidget(checkBox_curan);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_Info = new QLabel(mdbexport);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        label_Info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Info);

        progressBar = new QProgressBar(mdbexport);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(1000);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(158, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(mdbexport);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(mdbexport);
        QObject::connect(buttonBox, SIGNAL(rejected()), mdbexport, SLOT(reject()));

        QMetaObject::connectSlotsByName(mdbexport);
    } // setupUi

    void retranslateUi(QDialog *mdbexport)
    {
        mdbexport->setWindowTitle(QApplication::translate("mdbexport", "\330\247\330\263\330\252\330\261\330\247\330\257 \331\205\331\204\331\201\330\247\330\252 \330\247\331\204\330\264\330\247\331\205\331\204\330\251", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("mdbexport", "\331\205\330\263\330\247\330\261 \330\247\331\204\331\205\331\204\331\201", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit_fileNam->setWhatsThis(QApplication::translate("mdbexport", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\257\330\256\331\204 \330\247\330\263\331\205 \330\247\331\204\331\205\331\204\331\201 \330\247\331\204\331\212 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\247\331\204\331\203\330\252\330\247\330\250</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\252\331\206\330\250\331\212\331\207 : </p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\"> \331\212\330\254\330\250 \330\247\331\206 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\254\330\257\331\210\331\204\331\212\331\206 </p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">book</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">title</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        toolButton_fileNam->setToolTip(QApplication::translate("mdbexport", "\330\247\330\256\330\252\330\261 \330\247\331\204\331\205\330\263\330\247\330\261 ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_fileNam->setText(QApplication::translate("mdbexport", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mdbexport", "\330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mdbexport", "\330\247\330\263\331\205 \330\247\331\204\331\205\330\244\331\204\331\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("mdbexport", "\330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("mdbexport", "\330\250\330\267\330\247\331\202\330\251 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        checkBox_curan->setWhatsThis(QApplication::translate("mdbexport", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\271\331\204\331\205 \331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \330\247\330\260\330\247 \331\203\330\247\331\206 \331\203\330\252\330\247\330\250 \330\247\331\204\330\252\331\201\330\263\331\212\330\261 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\255\331\202\331\210\331\204 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">   \"Aya\" \331\210\330\255\331\202\331\204 \"Sora\"</p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_curan->setText(QApplication::translate("mdbexport", "\330\252\331\201\330\263\331\212\330\261 \331\205\331\201\331\207\330\261\330\263 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261", 0, QApplication::UnicodeUTF8));
        label_Info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mdbexport: public Ui_mdbexport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDBEXPORT_H
