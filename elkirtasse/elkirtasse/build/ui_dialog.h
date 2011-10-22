/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Oct 6 18:58:31 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QLocale>
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
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_fileNam;
    QToolButton *toolButton_fileNam;
    QToolButton *toolButton_zipFileNam;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_booknam;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_autor;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_group;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QTextEdit *textEdit_betaka;
    QCheckBox *checkBox_curan;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::WindowModal);
        Dialog->resize(327, 332);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/address-book-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setLayoutDirection(Qt::RightToLeft);
        Dialog->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        Dialog->setModal(true);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_fileNam = new QLineEdit(Dialog);
        lineEdit_fileNam->setObjectName(QString::fromUtf8("lineEdit_fileNam"));

        horizontalLayout_3->addWidget(lineEdit_fileNam);

        toolButton_fileNam = new QToolButton(Dialog);
        toolButton_fileNam->setObjectName(QString::fromUtf8("toolButton_fileNam"));

        horizontalLayout_3->addWidget(toolButton_fileNam);

        toolButton_zipFileNam = new QToolButton(Dialog);
        toolButton_zipFileNam->setObjectName(QString::fromUtf8("toolButton_zipFileNam"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/image/tar-gz.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_zipFileNam->setIcon(icon1);
        toolButton_zipFileNam->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(toolButton_zipFileNam);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit_booknam = new QLineEdit(Dialog);
        lineEdit_booknam->setObjectName(QString::fromUtf8("lineEdit_booknam"));

        horizontalLayout->addWidget(lineEdit_booknam);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_autor = new QLineEdit(Dialog);
        lineEdit_autor->setObjectName(QString::fromUtf8("lineEdit_autor"));

        horizontalLayout_4->addWidget(lineEdit_autor);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_4);

        comboBox_group = new QComboBox(Dialog);
        comboBox_group->setObjectName(QString::fromUtf8("comboBox_group"));

        horizontalLayout_5->addWidget(comboBox_group);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        textEdit_betaka = new QTextEdit(Dialog);
        textEdit_betaka->setObjectName(QString::fromUtf8("textEdit_betaka"));

        horizontalLayout_6->addWidget(textEdit_betaka);


        verticalLayout->addLayout(horizontalLayout_6);

        checkBox_curan = new QCheckBox(Dialog);
        checkBox_curan->setObjectName(QString::fromUtf8("checkBox_curan"));

        verticalLayout->addWidget(checkBox_curan);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\330\245\330\270\330\247\331\201\330\251 \331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "\331\205\330\254\331\204\330\257 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit_fileNam->setWhatsThis(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\257\330\256\331\204 \330\247\330\263\331\205 \330\247\331\204\331\205\330\254\331\204\330\257 \330\247\331\204\331\212 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\247\331\204\331\203\330\252\330\247\330\250</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\252\331\206\330\250\331\212\331\207 :\331\212\330\254\330\250 \330\247\331\206 \331\212\331\203\331\210\331\206 \330\247\331\204\331\205\330\254\331\204\330\257"
                        " \331\201\331\212 \331\206\331\201\330\263 \330\247\331\204\331\205\330\254\331\204\330\257 \330\247\331\204\330\260\331\212 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\247\331\204\331\203\330\252\330\250 \330\247\331\204\331\205\330\263\331\205\331\211 </p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">books</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\203\331\205\330\247 \331\212\330\254\330\250 \330\247\331\206 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \331\205\331\204\331\201\331\212\331\206 \331\207\331\205\330\247 :</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">book.xml</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; marg"
                        "in-right:0px; -qt-block-indent:0; text-indent:0px;\">title.xml</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        toolButton_fileNam->setToolTip(QApplication::translate("Dialog", "\331\201\330\252\330\255 \331\205\330\254\331\204\330\257 \331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_fileNam->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_zipFileNam->setToolTip(QApplication::translate("Dialog", "\331\201\330\252\330\255 \330\247\330\261\330\264\331\212\331\201 \331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_zipFileNam->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "\330\247\330\263\331\205 \330\247\331\204\331\205\330\244\331\204\331\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "\330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        comboBox_group->setWhatsThis(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\256\330\252\330\261 \330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251 \330\247\331\204\330\252\331\212 \330\263\331\212\330\252\331\205 \330\247\330\266\330\247\331\201\330\251 \330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\331\212\331\207\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("Dialog", "\330\250\330\267\330\247\331\202\330\251 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        checkBox_curan->setWhatsThis(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\271\331\204\331\205 \331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \330\247\330\260\330\247 \331\203\330\247\331\206 \331\203\330\252\330\247\330\250 \330\247\331\204\330\252\331\201\330\263\331\212\330\261 \331\212\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \330\255\331\202\331\210\331\204 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">   \"Aya\" \331\210\330\255\331\202\331\204 \"Sora\"</p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_curan->setText(QApplication::translate("Dialog", "\330\252\331\201\330\263\331\212\330\261 \331\205\331\201\331\207\330\261\330\263 \330\247\331\204\330\247\331\212\330\247\330\252 \331\210\330\247\331\204\330\263\331\210\330\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
