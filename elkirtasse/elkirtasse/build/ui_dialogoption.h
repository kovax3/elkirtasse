/********************************************************************************
** Form generated from reading UI file 'dialogoption.ui'
**
** Created: Thu Oct 6 18:58:31 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPTION_H
#define UI_DIALOGOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialogoption
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_font;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_fontTitle;
    QToolButton *toolButton_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_fontHachia;
    QToolButton *toolButton_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_fontcolor;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_titlecolor;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_prefercolor;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_findcolor;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_backcolor;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_9;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *lineEdit_costmPath;
    QToolButton *toolButton_costmPath;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxCadre;
    QComboBox *comboBoxCadre;
    QLabel *labelCadre;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogoption)
    {
        if (Dialogoption->objectName().isEmpty())
            Dialogoption->setObjectName(QString::fromUtf8("Dialogoption"));
        Dialogoption->resize(505, 401);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/groupb.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialogoption->setWindowIcon(icon);
        Dialogoption->setLayoutDirection(Qt::RightToLeft);
        Dialogoption->setAutoFillBackground(false);
        formLayout = new QFormLayout(Dialogoption);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(Dialogoption);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/image/groupbook.png")));

        verticalLayout->addWidget(label_5);

        label_10 = new QLabel(Dialogoption);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setAutoFillBackground(false);

        verticalLayout->addWidget(label_10);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        tabWidget = new QTabWidget(Dialogoption);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        label_font = new QLabel(tab);
        label_font->setObjectName(QString::fromUtf8("label_font"));

        horizontalLayout_2->addWidget(label_font);

        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(46, 26));

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_12->addWidget(label_12);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_8);

        label_fontTitle = new QLabel(tab);
        label_fontTitle->setObjectName(QString::fromUtf8("label_fontTitle"));

        horizontalLayout_12->addWidget(label_fontTitle);

        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(46, 26));

        horizontalLayout_12->addWidget(toolButton_2);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_13->addWidget(label_13);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_10);

        label_fontHachia = new QLabel(tab);
        label_fontHachia->setObjectName(QString::fromUtf8("label_fontHachia"));

        horizontalLayout_13->addWidget(label_fontHachia);

        toolButton_3 = new QToolButton(tab);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(46, 26));

        horizontalLayout_13->addWidget(toolButton_3);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_fontcolor = new QPushButton(tab);
        pushButton_fontcolor->setObjectName(QString::fromUtf8("pushButton_fontcolor"));
        pushButton_fontcolor->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(pushButton_fontcolor);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        pushButton_titlecolor = new QPushButton(tab);
        pushButton_titlecolor->setObjectName(QString::fromUtf8("pushButton_titlecolor"));

        horizontalLayout_5->addWidget(pushButton_titlecolor);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        pushButton_prefercolor = new QPushButton(tab);
        pushButton_prefercolor->setObjectName(QString::fromUtf8("pushButton_prefercolor"));

        horizontalLayout_6->addWidget(pushButton_prefercolor);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(341, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        pushButton_findcolor = new QPushButton(tab);
        pushButton_findcolor->setObjectName(QString::fromUtf8("pushButton_findcolor"));

        horizontalLayout_7->addWidget(pushButton_findcolor);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_6 = new QSpacerItem(97, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        pushButton_backcolor = new QPushButton(tab);
        pushButton_backcolor->setObjectName(QString::fromUtf8("pushButton_backcolor"));

        horizontalLayout_8->addWidget(pushButton_backcolor);


        verticalLayout_2->addLayout(horizontalLayout_8);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        spinBox_3 = new QSpinBox(tab_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(15);
        spinBox_3->setValue(7);

        horizontalLayout_9->addWidget(spinBox_3);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_9);

        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_10->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_11->addWidget(label_11);

        lineEdit_costmPath = new QLineEdit(tab_2);
        lineEdit_costmPath->setObjectName(QString::fromUtf8("lineEdit_costmPath"));
        lineEdit_costmPath->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_11->addWidget(lineEdit_costmPath);

        toolButton_costmPath = new QToolButton(tab_2);
        toolButton_costmPath->setObjectName(QString::fromUtf8("toolButton_costmPath"));

        horizontalLayout_11->addWidget(toolButton_costmPath);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBoxCadre = new QCheckBox(tab_2);
        checkBoxCadre->setObjectName(QString::fromUtf8("checkBoxCadre"));

        horizontalLayout_3->addWidget(checkBoxCadre);

        comboBoxCadre = new QComboBox(tab_2);
        comboBoxCadre->setObjectName(QString::fromUtf8("comboBoxCadre"));

        horizontalLayout_3->addWidget(comboBoxCadre);


        verticalLayout_3->addLayout(horizontalLayout_3);

        labelCadre = new QLabel(tab_2);
        labelCadre->setObjectName(QString::fromUtf8("labelCadre"));

        verticalLayout_3->addWidget(labelCadre);

        verticalSpacer = new QSpacerItem(20, 194, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());

        formLayout->setWidget(0, QFormLayout::FieldRole, tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(Dialogoption);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        horizontalLayout->addWidget(buttonBox);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(Dialogoption);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialogoption, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogoption, SLOT(reject()));
        QObject::connect(checkBoxCadre, SIGNAL(toggled(bool)), comboBoxCadre, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialogoption);
    } // setupUi

    void retranslateUi(QDialog *Dialogoption)
    {
        Dialogoption->setWindowTitle(QApplication::translate("Dialogoption", "\330\256\331\212\330\247\330\261\330\247\330\252", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_10->setText(QApplication::translate("Dialogoption", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'KacstLetter'; font-size:10pt;\"> </span><span style=\" font-family:'KacstLetter'; font-size:12pt; color:#ff0000;\">\330\256\331\212\330\247\330\261\330\247\330\252 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'KacstLetter'; font-size:10pt;\">\331\202\331\205 \330\250\330\252\330\272\331\212\331\212\330\261 \330\247\330\271\330\257\330\247\330\257\330\247\330\252 \330\247\331\204\330\247\331\204\331\210\330\247\331\206 \331\210\330\247\331\204\330\263\331\205\330\251 </span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'KacstLetter'; font-size:10pt;\">\331\204\330\252\330\271\330\267\331\212 \331\204\331\204\330\250\330\261\331\206\330\247\331\205\330\254 \331\205\330\270\331\207\330\261\330\247 \331\212\331\206\330\247\330\263\330\250\331\203</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'KacstLetter'; font-size:10pt;\">\331\203\331\205\330\247 \331\212\331\205\331\203\331\206\331\203 \330\252\330"
                        "\272\331\212\331\212\330\261 \331\205\330\263\330\247\330\261 \330\247\331\204\331\203\330\252\330\250 </span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'KacstLetter'; font-size:10pt;\">\330\247\331\204\331\211 \330\247\331\204\330\257\331\212\331\204 \330\247\331\204\330\260\331\212 \330\252\330\256\330\252\330\247\330\261\331\207</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialogoption", "\330\256\330\267 \330\247\331\204\330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
        label_font->setText(QString());
        toolButton->setText(QApplication::translate("Dialogoption", "...\330\247\330\256\330\252\330\261", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Dialogoption", "\330\256\330\267 \330\247\331\204\330\271\331\206\330\247\331\212\331\206", 0, QApplication::UnicodeUTF8));
        label_fontTitle->setText(QString());
        toolButton_2->setText(QApplication::translate("Dialogoption", "...\330\247\330\256\330\252\330\261", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Dialogoption", "\330\256\330\267 \330\247\331\204\330\255\330\247\330\264\331\212\330\251", 0, QApplication::UnicodeUTF8));
        label_fontHachia->setText(QString());
        toolButton_3->setText(QApplication::translate("Dialogoption", "...\330\247\330\256\330\252\330\261", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialogoption", "\331\204\331\210\331\206 \330\256\330\267 \330\247\331\204\330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
        pushButton_fontcolor->setText(QString());
        label_3->setText(QApplication::translate("Dialogoption", "\331\204\331\210\331\206 \330\247\331\204\330\271\331\206\330\247\331\210\331\212\331\206", 0, QApplication::UnicodeUTF8));
        pushButton_titlecolor->setText(QString());
        label_4->setText(QApplication::translate("Dialogoption", "\330\247\331\204\330\247\331\204\331\210\330\247\331\206 \330\247\331\204\331\205\330\256\330\265\330\265\330\251", 0, QApplication::UnicodeUTF8));
        pushButton_prefercolor->setText(QString());
        label_6->setText(QApplication::translate("Dialogoption", "\331\204\331\210\331\206 \330\252\331\205\331\212\331\212\330\262 \330\247\331\204\330\250\330\255\330\253", 0, QApplication::UnicodeUTF8));
        pushButton_findcolor->setText(QString());
        label_7->setText(QApplication::translate("Dialogoption", "\330\247\331\210\331\206 \330\247\331\204\330\256\331\204\331\201\331\212\330\251", 0, QApplication::UnicodeUTF8));
        pushButton_backcolor->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialogoption", "\330\247\331\204\330\247\331\204\331\210\330\247\331\206 \331\210\330\247\331\204\330\256\330\267\331\210\330\267", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Dialogoption", "\330\271\330\257\330\257 \330\247\331\204\331\203\330\252\330\250 \330\247\331\204\330\263\330\247\330\250\331\202\330\251", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialogoption", "\330\247\331\204\330\263\331\205\330\251", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialogoption", "\331\205\330\263\330\247\330\261\330\247\331\204\331\203\330\252\330\250", 0, QApplication::UnicodeUTF8));
        toolButton_costmPath->setText(QApplication::translate("Dialogoption", "...", 0, QApplication::UnicodeUTF8));
        checkBoxCadre->setText(QApplication::translate("Dialogoption", "\330\271\330\261\330\266 \330\245\330\267\330\247\330\261 \330\247\331\204\331\206\330\265", 0, QApplication::UnicodeUTF8));
        labelCadre->setText(QApplication::translate("Dialogoption", "\331\205\330\271\330\247\331\212\331\206\330\251", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialogoption", "\330\256\331\212\330\247\330\261\330\247\330\252 \330\243\330\256\330\261\331\211", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialogoption: public Ui_Dialogoption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPTION_H
