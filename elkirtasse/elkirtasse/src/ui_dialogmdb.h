/********************************************************************************
** Form generated from reading UI file 'dialogmdb.ui'
**
** Created: Mon 4. Apr 10:00:57 2011
**      by: Qt User Interface Compiler version 4.6.2
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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogmdb
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_fileNam;
    QToolButton *toolButton_fileNam;
    QLineEdit *lineEdit_booknam;
    QLabel *label;
    QLineEdit *lineEdit_autor;
    QLabel *label_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QTextBrowser *textBrowser;
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
        Dialogmdb->resize(342, 349);
        Dialogmdb->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(Dialogmdb);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Dialogmdb);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_fileNam = new QLineEdit(Dialogmdb);
        lineEdit_fileNam->setObjectName(QString::fromUtf8("lineEdit_fileNam"));

        horizontalLayout_3->addWidget(lineEdit_fileNam);

        toolButton_fileNam = new QToolButton(Dialogmdb);
        toolButton_fileNam->setObjectName(QString::fromUtf8("toolButton_fileNam"));

        horizontalLayout_3->addWidget(toolButton_fileNam);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        lineEdit_booknam = new QLineEdit(Dialogmdb);
        lineEdit_booknam->setObjectName(QString::fromUtf8("lineEdit_booknam"));

        gridLayout->addWidget(lineEdit_booknam, 1, 1, 1, 1);

        label = new QLabel(Dialogmdb);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_autor = new QLineEdit(Dialogmdb);
        lineEdit_autor->setObjectName(QString::fromUtf8("lineEdit_autor"));

        gridLayout->addWidget(lineEdit_autor, 2, 1, 1, 1);

        label_2 = new QLabel(Dialogmdb);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(Dialogmdb);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(Dialogmdb);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        textBrowser = new QTextBrowser(Dialogmdb);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setReadOnly(false);

        horizontalLayout->addWidget(textBrowser);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        comboBox = new QComboBox(Dialogmdb);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        checkBox_curan = new QCheckBox(Dialogmdb);
        checkBox_curan->setObjectName(QString::fromUtf8("checkBox_curan"));

        verticalLayout->addWidget(checkBox_curan);

        label_6 = new QLabel(Dialogmdb);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        progressBar = new QProgressBar(Dialogmdb);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(1000);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(progressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(Dialogmdb);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialogmdb);
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogmdb, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogmdb);
    } // setupUi

    void retranslateUi(QDialog *Dialogmdb)
    {
        Dialogmdb->setWindowTitle(QApplication::translate("Dialogmdb", "\330\247\330\263\330\252\330\261\330\247\330\257 \331\205\331\204\331\201\330\247\330\252 \330\247\331\204\331\205\331\203\330\252\330\250\330\251 \330\247\331\204\330\264\330\247\331\205\331\204\330\251", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialogmdb", "\331\205\330\263\330\247\330\261 \330\247\331\204\331\205\331\204\331\201", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit_fileNam->setWhatsThis(QApplication::translate("Dialogmdb", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
#ifndef QT_NO_WHATSTHIS
        toolButton_fileNam->setWhatsThis(QApplication::translate("Dialogmdb", "\330\247\331\206\331\202\330\261 \331\207\331\206\330\247 \331\204\330\247\330\256\330\252\331\212\330\247\330\261 \330\247\331\204\331\205\330\263\330\247\330\261", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toolButton_fileNam->setText(QApplication::translate("Dialogmdb", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialogmdb", "\330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialogmdb", "\330\247\330\263\331\205 \330\247\331\204\331\205\330\244\331\204\331\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialogmdb", "\330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialogmdb", "\330\250\330\267\330\247\331\202\330\251 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        textBrowser->setWhatsThis(QApplication::translate("Dialogmdb", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\257\330\256\331\204 \330\250\331\212\330\247\331\206\330\247\330\252 \330\252\330\271\330\261\331\201 \330\271\331\206 \331\205\330\255\330\252\331\210\331\212\330\247\330\252 \330\247\331\204\331\203\330\252\330\247\330\250 \331\210\331\205\330\265\330\257\330\261 \330\247\331\204\331\203\330\252\330\247\330\250 \331\210 \331\205\330\247 \330\247\331\204\331\211 \330\260\331\204\331\203</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\204"
                        "\331\212\330\263 \331\205\331\206 \330\247\331\204\330\266\330\261\331\210\330\261\331\212 \330\247\331\206 \330\252\330\257\330\256\331\204 \330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250 \331\210\330\247\331\204\331\205\330\244\331\204\331\201 \330\263\331\212\330\252\331\205 \330\247\330\257\330\261\330\247\330\254\331\207\331\205 \330\252\331\204\331\202\330\247\330\246\331\212\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
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
