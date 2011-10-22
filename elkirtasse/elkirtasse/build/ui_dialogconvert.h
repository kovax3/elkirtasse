/********************************************************************************
** Form generated from reading UI file 'dialogconvert.ui'
**
** Created: Thu Oct 6 18:58:31 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONVERT_H
#define UI_DIALOGCONVERT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogconvert
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_fileNam;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_delete;
    QToolButton *toolButton_up;
    QToolButton *toolButton_down;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_booknam;
    QLabel *label_2;
    QLineEdit *lineEdit_autor;
    QLabel *label_4;
    QComboBox *comboBox_group;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_NB;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_SG;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QRadioButton *radioButtonFull;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *dialogconvert)
    {
        if (dialogconvert->objectName().isEmpty())
            dialogconvert->setObjectName(QString::fromUtf8("dialogconvert"));
        dialogconvert->resize(474, 543);
        dialogconvert->setLayoutDirection(Qt::RightToLeft);
        verticalLayout_3 = new QVBoxLayout(dialogconvert);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(dialogconvert);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setLayoutDirection(Qt::LeftToRight);
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout_2->addWidget(listWidget, 0, 1, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton_fileNam = new QToolButton(groupBox_2);
        toolButton_fileNam->setObjectName(QString::fromUtf8("toolButton_fileNam"));

        verticalLayout->addWidget(toolButton_fileNam);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolButton_delete = new QToolButton(groupBox_2);
        toolButton_delete->setObjectName(QString::fromUtf8("toolButton_delete"));
        toolButton_delete->setMaximumSize(QSize(24, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/edit-delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_delete->setIcon(icon);

        verticalLayout->addWidget(toolButton_delete);

        toolButton_up = new QToolButton(groupBox_2);
        toolButton_up->setObjectName(QString::fromUtf8("toolButton_up"));
        toolButton_up->setMaximumSize(QSize(24, 24));
        toolButton_up->setIcon(icon);

        verticalLayout->addWidget(toolButton_up);

        toolButton_down = new QToolButton(groupBox_2);
        toolButton_down->setObjectName(QString::fromUtf8("toolButton_down"));
        toolButton_down->setMaximumSize(QSize(24, 24));
        toolButton_down->setIcon(icon);

        verticalLayout->addWidget(toolButton_down);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        lineEdit_booknam = new QLineEdit(groupBox_2);
        lineEdit_booknam->setObjectName(QString::fromUtf8("lineEdit_booknam"));

        gridLayout_3->addWidget(lineEdit_booknam, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_autor = new QLineEdit(groupBox_2);
        lineEdit_autor->setObjectName(QString::fromUtf8("lineEdit_autor"));

        gridLayout_3->addWidget(lineEdit_autor, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        comboBox_group = new QComboBox(groupBox_2);
        comboBox_group->setObjectName(QString::fromUtf8("comboBox_group"));

        gridLayout_3->addWidget(comboBox_group, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 110));
        textBrowser->setReadOnly(false);

        horizontalLayout_4->addWidget(textBrowser);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_NB = new QRadioButton(groupBox);
        radioButton_NB->setObjectName(QString::fromUtf8("radioButton_NB"));
        radioButton_NB->setChecked(true);

        horizontalLayout_3->addWidget(radioButton_NB);

        horizontalSpacer = new QSpacerItem(151, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1000);
        spinBox->setMaximum(5000);
        spinBox->setValue(3000);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_SG = new QRadioButton(groupBox);
        radioButton_SG->setObjectName(QString::fromUtf8("radioButton_SG"));

        horizontalLayout_2->addWidget(radioButton_SG);

        horizontalSpacer_2 = new QSpacerItem(151, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        radioButtonFull = new QRadioButton(groupBox);
        radioButtonFull->setObjectName(QString::fromUtf8("radioButtonFull"));

        verticalLayout_4->addWidget(radioButtonFull);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(dialogconvert);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(dialogconvert);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(dialogconvert);
        QObject::connect(pushButton_2, SIGNAL(clicked()), dialogconvert, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogconvert);
    } // setupUi

    void retranslateUi(QDialog *dialogconvert)
    {
        dialogconvert->setWindowTitle(QApplication::translate("dialogconvert", "\330\252\330\255\331\210\331\212\331\204 \331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("dialogconvert", "\330\256\331\212\330\247\330\261\330\247\330\252", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("dialogconvert", "\331\205\330\271\331\204\331\210\331\205\330\247\330\252 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dialogconvert", "\331\205\331\204\331\201\330\247\330\252 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        listWidget->setWhatsThis(QApplication::translate("dialogconvert", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\270\331\201 \331\205\331\204\331\201\330\247\330\252 \330\247\331\204\331\203\330\252\330\247\330\250 \331\207\331\206\330\247</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\212\331\205\331\203\331\206 \330\247\331\206 \331\212\330\255\330\252\331\210\331\212 \330\247\331\204\331\203\330\252\330\247\330\250 \330\271\331\204\331\211 \330\271\330\257\330\251 \331\205\331\204\331\201\330\247\330\252 \331\201\331\201\331\212 \331\207\330\260"
                        "\331\207 \330\247\331\204\330\255\330\247\331\204\330\251 \331\212\331\202\331\210\331\205 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254 \330\250\330\252\330\261\331\205\331\212\330\262 \331\203\331\204 \331\205\331\204\331\201 \330\271\331\204\331\211 \330\247\331\206\331\207 \330\254\330\262\330\241 \331\205\331\206 \331\203\330\252\330\247\330\250 \331\201\331\205\330\253\331\204\330\247 \330\247\330\260\330\247 \331\203\330\247\331\206 \331\207\331\206\330\247\331\203 4 \331\205\331\204\331\201\330\247\330\252 \331\201\330\263\331\210\331\201 \331\212\331\203\331\210\331\206 \330\271\331\206\330\257\331\203 \331\203\330\252\330\247\330\250 \330\2504\330\243\330\254\330\262\330\247\330\241</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        toolButton_fileNam->setToolTip(QApplication::translate("dialogconvert", "\330\247\330\270\330\247\331\201\330\251 \331\205\331\204\331\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_fileNam->setText(QApplication::translate("dialogconvert", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_delete->setToolTip(QApplication::translate("dialogconvert", "\330\255\330\260\331\201 \330\247\331\204\331\205\331\204\331\201 \330\247\331\204\331\205\330\255\330\257\330\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_delete->setText(QString());
#ifndef QT_NO_TOOLTIP
        toolButton_up->setToolTip(QApplication::translate("dialogconvert", "\331\206\331\202\331\204 \330\247\331\204\331\205\331\204\331\201 \330\247\331\204\331\205\330\255\330\257\330\257 \331\204\331\204\330\247\330\271\331\204\331\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_up->setText(QString());
#ifndef QT_NO_TOOLTIP
        toolButton_down->setToolTip(QApplication::translate("dialogconvert", "\331\206\331\202\331\204 \330\247\331\204\331\205\331\204\331\201 \330\247\331\204\331\205\330\255\330\257\330\257 \331\204\331\204\330\247\330\263\331\201\331\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_down->setText(QString());
        label->setText(QApplication::translate("dialogconvert", "\330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialogconvert", "\330\247\330\263\331\205 \330\247\331\204\331\205\330\244\331\204\331\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dialogconvert", "\330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        comboBox_group->setWhatsThis(QApplication::translate("dialogconvert", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\256\330\252\330\261 \330\247\331\204\331\205\330\254\331\205\331\210\330\271\330\251 \330\247\331\204\330\252\331\212 \330\263\331\212\330\252\331\205 \330\247\330\266\330\247\331\201\330\251 \330\247\331\204\331\203\330\252\330\247\330\250 \330\247\331\204\331\212\331\207\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("dialogconvert", "\330\250\330\267\330\247\331\202\330\251 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        textBrowser->setWhatsThis(QApplication::translate("dialogconvert", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\257\330\256\331\204 \330\250\331\212\330\247\331\206\330\247\330\252 \330\252\330\271\330\261\331\201 \330\271\331\206 \331\205\330\255\330\252\331\210\331\212\330\247\330\252 \330\247\331\204\331\203\330\252\330\247\330\250 \331\210\331\205\330\265\330\257\330\261 \330\247\331\204\331\203\330\252\330\247\330\250 \331\210 \331\205\330\247 \330\247\331\204\331\211 \330\260\331\204\331\203</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\204"
                        "\331\212\330\263 \331\205\331\206 \330\247\331\204\330\266\330\261\331\210\330\261\331\212 \330\247\331\206 \330\252\330\257\330\256\331\204 \330\247\330\263\331\205 \330\247\331\204\331\203\330\252\330\247\330\250 \331\210\330\247\331\204\331\205\330\244\331\204\331\201 \330\263\331\212\330\252\331\205 \330\247\330\257\330\261\330\247\330\254\331\207\331\205 \330\252\331\204\331\202\330\247\330\246\331\212\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_NB->setText(QApplication::translate("dialogconvert", "\330\271\330\257\330\257 \330\247\331\204\330\247\330\255\330\261\331\201 \331\201\331\212 \330\247\331\204\330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        spinBox->setWhatsThis(QApplication::translate("dialogconvert", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\212\331\205\331\203\331\206\331\203 \330\252\330\255\330\257\331\212\330\257 \330\271\330\257\330\257 \330\247\331\204\330\247\330\255\330\261\331\201 \331\201\331\212 \331\203\331\204 \330\265\331\201\330\255\330\251 \330\250\330\255\331\212\330\253 \331\212\331\202\331\210\331\205 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254 \330\271\331\206\330\257 \331\203\331\204 \330\271\330\257\330\257 \331\205\330\271\331\212\331\206 \330\250\330\247\331\204\330\250\330\255\330\253 \330\250\330\271\330\257\331\207 \330\271\331\206 \331"
                        "\206\331\207\330\247\331\212\330\251 \330\247\331\204\330\254\331\205\331\204\330\251 \330\253\331\205 \331\212\331\206\330\264\330\243 \330\265\331\201\330\255\330\251 \330\254\331\212\330\257\330\251 \330\250\330\271\330\257\331\207\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_SG->setText(QApplication::translate("dialogconvert", "\330\252\330\261\331\205\331\212\330\262 \331\201\331\212 \330\247\331\204\330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("dialogconvert", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\212\331\205\331\203\331\206\331\203 \330\247\330\257\330\256\330\247\331\204 \330\252\330\261\331\205\331\212\330\262 \330\247\330\260\330\247 \331\203\330\247\331\206 \330\247\331\204\331\205\331\204\331\201 \331\202\330\257 \330\247\330\271\330\257 \330\256\330\265\331\212\330\265\330\247 \331\204\331\204\330\252\331\205\331\212\331\212\330\262 \330\250\331\212\331\206 \330\247\331\204\330\265\331\201\330\255\330\247\330\252</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\"><span style=\" color:#ff007f;\">\331\205\330\253\330\247\331\204</span>: \330\247\330\260\330\247 \331\203\331\206\330\252 \331\202\330\257 \330\247\330\257\330\256\331\204\330\252 \331\201\331\212 \330\247\330\256\330\261 \331\203\331\204 \330\265\331\201\330\255\330\251 \331\205\330\253\331\204\330\247 \330\271\331\204\330\247\331\205\330\251 *** \331\201\331\201\331\212 \331\207\330\260\331\207 \330\247\331\204\330\255\330\247\331\204\330\251 \330\247\330\257\330\256\331\204 \331\201\331\212 \331\205\330\261\330\250\330\271 \330\247\331\204\330\252\330\261\331\205\331\212\330\262 \330\253\331\204\330\247\330\253 \331\206\330\254\331\205\330\247\330\252 \331\201\331\212\331\202\331\210\331\205 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254 \330\252\331\204\331\202\330\247\330\246\331\212\330\247 \331\203\331\204\331\205\330\247 \331\210\330\254\330\257 \331\207\330\260\330\247 \330\247\331\204\330\252\330\261\331\205\331\212\330\262 \330\250\330\247\331\206\330\264"
                        "\330\247\330\241 \330\265\331\201\330\255\330\251 \330\254\330\257\331\212\330\257\330\251 </p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        radioButtonFull->setToolTip(QApplication::translate("dialogconvert", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\330\257\330\261\330\247\330\254 \331\203\331\204 \331\205\331\204\331\201 \331\201\331\212 \330\265\331\201\330\255\330\251 \330\255\330\263\330\250 \330\247\331\204\330\252\330\261\330\252\331\212\330\250 \331\205\330\263\330\252\330\255\330\250 \331\204\331\204\331\205\331\204\331\201\330\247\330\252 \330\247\331\204\330\265\330\272\331\212\330\261\330\251</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;"
                        "\">\330\252\331\206\330\250\331\212\331\207: </span>\331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \330\272\331\212\330\261 \331\205\330\263\330\252\330\255\330\250 \330\256\330\265\331\210\330\265\330\247 \330\247\330\260\330\247 \331\203\330\247\331\206 \330\255\330\254\331\205 \330\247\331\204\331\205\331\204\331\201 \331\212\331\201\331\210\331\202 \330\247\331\204\330\256\331\205\330\263\330\251 \330\247\331\204\330\247\331\201 \330\255\330\261\331\201</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButtonFull->setText(QApplication::translate("dialogconvert", "\331\203\331\204 \331\205\331\204\331\201 \331\201\331\212 \330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("dialogconvert", "\330\247\331\204\330\272\330\247\330\241", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dialogconvert", "\331\205\331\210\330\247\331\201\331\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogconvert: public Ui_dialogconvert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONVERT_H
