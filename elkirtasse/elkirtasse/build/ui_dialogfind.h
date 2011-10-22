/********************************************************************************
** Form generated from reading UI file 'dialogfind.ui'
**
** Created: Thu Oct 6 18:58:31 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFIND_H
#define UI_DIALOGFIND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogfind
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QTreeWidget *treeWidget;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButtonbooks;
    QRadioButton *radioButtonFahariss;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonNass;
    QRadioButton *radioButtonMulti;
    QRadioButton *radioButtonJidre;
    QRadioButton *radioButtonFirst;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxSawabik;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxAnd;
    QCheckBox *checkBoxOr;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogfind)
    {
        if (Dialogfind->objectName().isEmpty())
            Dialogfind->setObjectName(QString::fromUtf8("Dialogfind"));
        Dialogfind->resize(556, 369);
        Dialogfind->setLayoutDirection(Qt::RightToLeft);
        gridLayout = new QGridLayout(Dialogfind);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialogfind);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Dialogfind);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(Dialogfind);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(Dialogfind);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(Dialogfind);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(Dialogfind);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        lineEdit = new QLineEdit(Dialogfind);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        frame_2 = new QFrame(Dialogfind);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radioButtonbooks = new QRadioButton(frame_2);
        radioButtonbooks->setObjectName(QString::fromUtf8("radioButtonbooks"));
        radioButtonbooks->setChecked(true);
        radioButtonbooks->setAutoRepeat(true);

        horizontalLayout_4->addWidget(radioButtonbooks);

        radioButtonFahariss = new QRadioButton(frame_2);
        radioButtonFahariss->setObjectName(QString::fromUtf8("radioButtonFahariss"));
        radioButtonFahariss->setAutoRepeat(true);

        horizontalLayout_4->addWidget(radioButtonFahariss);


        verticalLayout_4->addWidget(frame_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        groupBox = new QGroupBox(Dialogfind);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButtonNass = new QRadioButton(frame_3);
        radioButtonNass->setObjectName(QString::fromUtf8("radioButtonNass"));
        radioButtonNass->setCheckable(true);
        radioButtonNass->setChecked(true);
        radioButtonNass->setAutoRepeat(true);

        verticalLayout_3->addWidget(radioButtonNass);

        radioButtonMulti = new QRadioButton(frame_3);
        radioButtonMulti->setObjectName(QString::fromUtf8("radioButtonMulti"));
        radioButtonMulti->setCheckable(true);
        radioButtonMulti->setAutoRepeat(true);

        verticalLayout_3->addWidget(radioButtonMulti);

        radioButtonJidre = new QRadioButton(frame_3);
        radioButtonJidre->setObjectName(QString::fromUtf8("radioButtonJidre"));
        radioButtonJidre->setCheckable(true);
        radioButtonJidre->setAutoRepeat(true);

        verticalLayout_3->addWidget(radioButtonJidre);

        radioButtonFirst = new QRadioButton(frame_3);
        radioButtonFirst->setObjectName(QString::fromUtf8("radioButtonFirst"));
        radioButtonFirst->setCheckable(true);
        radioButtonFirst->setAutoRepeat(true);

        verticalLayout_3->addWidget(radioButtonFirst);


        horizontalLayout_3->addWidget(frame_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBoxSawabik = new QCheckBox(groupBox);
        checkBoxSawabik->setObjectName(QString::fromUtf8("checkBoxSawabik"));
        checkBoxSawabik->setChecked(true);

        verticalLayout_2->addWidget(checkBoxSawabik);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(false);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBoxAnd = new QCheckBox(frame);
        checkBoxAnd->setObjectName(QString::fromUtf8("checkBoxAnd"));
        checkBoxAnd->setChecked(true);
        checkBoxAnd->setAutoExclusive(true);

        horizontalLayout_2->addWidget(checkBoxAnd);

        checkBoxOr = new QCheckBox(frame);
        checkBoxOr->setObjectName(QString::fromUtf8("checkBoxOr"));
        checkBoxOr->setAutoExclusive(true);

        horizontalLayout_2->addWidget(checkBoxOr);


        verticalLayout_2->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout_4, 0, 2, 1, 2);

        label_4 = new QLabel(Dialogfind);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 252, 210);"));
        label_4->setWordWrap(true);

        gridLayout->addWidget(label_4, 1, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 2);

        buttonBox = new QDialogButtonBox(Dialogfind);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 3, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit_2);
        label_2->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialogfind);
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogfind, SLOT(reject()));
        QObject::connect(radioButtonMulti, SIGNAL(toggled(bool)), frame, SLOT(setEnabled(bool)));
        QObject::connect(radioButtonJidre, SIGNAL(toggled(bool)), checkBoxSawabik, SLOT(setDisabled(bool)));
        QObject::connect(radioButtonFirst, SIGNAL(toggled(bool)), checkBoxSawabik, SLOT(setDisabled(bool)));
        QObject::connect(radioButtonFahariss, SIGNAL(toggled(bool)), groupBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButtonFahariss, SIGNAL(toggled(bool)), radioButtonNass, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(Dialogfind);
    } // setupUi

    void retranslateUi(QDialog *Dialogfind)
    {
        Dialogfind->setWindowTitle(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \331\205\330\252\331\202\330\257\331\205", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialogfind", "\330\271\331\204\331\205 \330\247\331\204\331\203\330\252\330\250 \330\247\331\204\331\205\330\261\330\247\330\257 \330\247\331\204\330\250\330\255\330\253 \331\201\331\212\331\207\330\247 \331\204\330\247\331\212\330\252\331\205 \330\247\331\204\330\250\330\255\330\253 \330\247\331\204\330\247 \331\201\331\212 \330\247\331\204\331\203\330\252\330\250 \330\247\331\204\331\205\330\271\331\204\331\205\330\251 ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialogfind", "\330\247\330\250\330\255\330\253 \330\271\331\206 \331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\331\204\330\250\330\255\330\253 \331\201\331\212 \330\247\331\204\330\264\330\254\330\261\330\251</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\250\330\255\331\212\330\253 \331\212\330\252\331\205 \330\247\331\204\330\250\330\255\330\253 \330\252\331\204\331\202\330\247\330\246\331\212\330\247 \330\271\331\206\330\257 \330\247\330\257\330\256\330\247\331\204 \331\203\331\204 \330\255\330\261\331\201 \330\254\330\257\331\212\330\257 \330\250"
                        "\330\255\331\212\330\253 \331\204\330\247 \330\252\330\270\331\207\330\261 \330\247\331\204\330\247 \330\247\331\204\331\206\330\252\330\247\330\246\330\254 \330\247\331\204\330\247\330\254\330\247\330\250\331\212\330\251 \331\201\331\202\330\267</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        treeWidget->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\271\331\204\331\205 \330\247\331\204\331\203\330\252\330\250 \330\247\331\204\331\205\330\261\330\247\330\257 \330\247\331\204\330\250\330\255\330\253 \331\201\331\212\331\207\330\247</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("Dialogfind", "\330\247\330\257\330\256\331\204 \331\206\330\265 \330\247\331\204\330\250\330\255\330\253 \331\201\331\212 \331\205\330\261\330\250\330\271 \330\247\331\204\331\206\330\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\331\204\331\206\330\265 \330\247\331\204\330\247\331\201\330\252\330\261\330\247\330\266\331\212 \330\247\331\204\330\260\331\212 \331\204\330\247 \331\212\330\252\331\205 \330\247\331\204\330\250\330\255\330\253 \331\205\331\206 \330\257\331\210\331\206\331\207</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButtonbooks->setText(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \331\201\331\212 \331\206\330\265 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        radioButtonFahariss->setText(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \331\201\331\212 \330\247\331\204\331\201\331\207\330\247\330\261\330\263", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialogfind", "\330\256\331\212\330\247\330\261\330\247\330\252", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        radioButtonNass->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \331\212\330\250\330\255\330\253 \330\271\331\206 \330\247\331\204\331\206\330\265 \331\203\331\205\330\247 \331\207\331\210 \330\263\331\210\330\247\330\241 \331\203\330\247\331\206 \330\250\330\263\331\210\330\247\330\250\331\202\331\207 \331\210\331\204\331\210\330\247\330\255\331\202\331\207 \330\247\331\205 \331\204\330\247</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButtonNass->setText(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \331\206\330\265\331\212", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        radioButtonMulti->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\212\331\205\331\203\331\206\331\203 \331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \331\205\331\206 \330\247\331\204\330\250\330\255\330\253 \330\271\331\206 \331\205\331\202\330\247\330\267\330\271 \330\247\331\204\331\206\330\265 \330\247\331\204\330\260\331\212 \330\243\330\257\330\256\331\204\330\252\331\207</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\205\330\253\330\247\331\204 \330\247\330\260\330"
                        "\247 \330\247\330\257\330\256\331\204\330\252 \330\247\331\204\331\206\330\265 \330\271\331\205\330\261 \330\250\331\206 \330\247\331\204\330\256\330\267\330\247\330\250 \331\205\330\271 \330\247\331\204\330\256\331\212\330\247\330\261 \331\210</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\201\331\212 \331\207\330\260\331\207 \330\247\331\204\330\255\330\247\331\204\330\251 \330\263\330\252\331\203\331\210\331\206 \330\247\331\204\331\206\330\252\330\247\330\246\330\254 \331\207\331\212 \330\247\331\204\330\265\331\201\330\255\330\247\330\252 \330\247\331\204\330\252\331\212 \330\252\330\255\330\252\331\210\331\212 \330\271\331\204\331\211 \331\203\331\204\331\205\330\251 \330\271\331\205\330\261 \331\210  \331\203\331\204\331\205\330\251 \330\247\331\204\330\256\330\267\330\247\330\250</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\">\331\210\331\204\330\247 \331\212\331\207\331\205 \330\252\330\261\330\252\331\212\330\250\331\207\330\247 \330\247\331\210 \331\205\331\210\331\202\330\271\331\207\330\247 \331\201\331\212 \330\247\331\204\330\265\331\201\330\255\330\251</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\330\247\331\205\330\247 \330\247\330\260\330\247 \330\247\330\256\330\252\330\261\330\252 \330\243\331\210 \331\201\330\263\330\252\331\203\331\210\331\206 \330\247\331\204\331\206\330\252\330\247\330\246\330\254 \331\203\331\204 \330\247\331\204\330\265\331\201\330\255\330\247\330\252 \330\247\331\204\330\252\331\212 \330\252\330\255\330\252\331\210\331\212 \330\247\331\212 \331\203\331\204\331\205\330\251 \331\205\331\206\331\207\330\247 \330\263\331\210\330\247\330\241 \330\247\331\204\330\256\330\267\330\247\330\250 \330\243\331\210 \330\271\331\205\330\261</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButtonMulti->setText(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \331\205\330\252\330\271\330\257\330\257", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        radioButtonJidre->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \331\212\331\205\331\203\331\206\331\203 \331\205\331\206 \330\247\331\204\330\250\330\255\330\253 \330\271\331\206 \330\247\331\204\331\203\331\204\331\205\330\251 \330\271\331\204\331\211 \331\205\330\263\330\252\331\210\331\211 \330\247\331\204\330\254\330\260\330\261 \330\247\331\204\330\253\331\204\330\247\330\253\331\212</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        ";\">\331\205\330\253\331\204\330\247 \331\203\331\204\331\205\330\251 \331\201\330\271\331\204 \330\263\330\252\331\203\331\210\331\206 \331\206\330\252\330\247\330\246\330\254\331\207\330\247</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\201\330\271\331\204</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\201\330\271\331\210\331\204</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\205\331\201\330\247\330\271\331\212\331\204</p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">....\330\247\331\204\330\256</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButtonJidre->setText(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \330\271\331\204\331\211 \331\205\330\263\330\252\331\210\331\211 \330\247\331\204\330\254\330\260\330\261", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        radioButtonFirst->setWhatsThis(QApplication::translate("Dialogfind", "\331\207\330\260\330\247 \330\247\331\204\330\256\331\212\330\247\330\261 \331\212\330\250\330\255\330\253 \330\271\331\206 \330\247\331\204\331\206\330\265 \331\201\331\212 \330\250\330\257\330\247\331\212\330\251 \330\247\331\204\330\265\331\201\330\255\330\251 \331\201\331\202\330\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButtonFirst->setText(QApplication::translate("Dialogfind", "\330\250\330\255\330\253 \331\201\331\212 \330\243\331\210\331\204 \331\206\330\265 \330\247\331\204\330\265\331\201\330\255\330\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        checkBoxSawabik->setWhatsThis(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:10pt;\">\330\247\331\212 \330\247\331\204\330\250\330\255\330\253 \330\255\330\252\331\211 \330\247\331\206 \331\203\330\247\331\206 \330\247\331\204\331\206\330\265 \330\254\330\262\330\241\330\247 \331\205\331\206 \331\206\330\265 \330\243\330\256\330\261 </span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bott"
                        "om:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:10pt;\">\331\205\330\253\331\204\330\247 \330\271\331\206\330\257 \330\247\330\257\330\256\330\247\331\204 \331\203\331\204\331\205\330\251 \331\201\330\271\331\204</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:10pt;\">\330\263\331\212\330\252\331\205 \330\247\331\204\330\250\330\255\330\253 \330\271\331\206 \331\207\330\260\331\207 \330\247\331\204\331\203\331\204\331\205\330\251 \331\210\331\205\330\247 \331\212\331\204\330\255\331\202 \330\250\331\207\330\247 \330\247\331\210\331\212\330\263\330\250\331\202\331\207\330\247 \331\205\330\253\331\204</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; "
                        "font-size:10pt;\">\331\212\331\201\330\271\331\204 \330\247\331\204\331\201\330\271\331\204 \331\212\331\201\330\271\331\204\331\210\331\206 ...\330\247\331\204\330\256</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:10pt;\">\330\247\331\205\330\247 \330\250\330\257\331\210\331\206 \330\247\331\204\330\263\331\210\330\247\330\250\331\202 \331\210\330\247\331\204\331\204\331\210\330\247\330\255\331\202 \331\201\331\204\330\247 \331\212\330\252\331\205 \330\247\331\204\330\250\330\255\330\253 \330\247\331\204\330\247 \330\271\331\204\331\211 \331\206\331\201\330\263 \330\247\331\204\331\203\331\204\331\205\330\251 \330\247\331\210 \330\247\331\204\331\206\330\265 \331\201\331\202\330\267</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBoxSawabik->setText(QApplication::translate("Dialogfind", "\330\250\330\247\331\204\330\263\331\210\330\247\330\250\331\202  \331\210 \330\247\331\204\331\204\330\247\330\255\331\202", 0, QApplication::UnicodeUTF8));
        checkBoxAnd->setText(QApplication::translate("Dialogfind", "\331\210", 0, QApplication::UnicodeUTF8));
        checkBoxOr->setText(QApplication::translate("Dialogfind", "\330\243\331\210", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialogfind", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:4px; margin-right:4px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">     </span><span style=\" font-size:8pt; color:#ff5500;\">\330\252\331\206\330\250\331\212\331\207</span><span style=\" font-size:8pt;\">: \331\204\331\204\330\250\330\255\330\253 \330\271\331\204\331\211 \331\205\330\263\330\252\331\210\331\211 \330\247\331\204\330\254\330\260\330\261 \331\212\330\254\330\250 \330\247\331\206 \331\212\331\203\331\210\331\206 \330\247\331\204\331\206\330\265 \330\254\330\260\330\261\330\247 \331\212\330\252\331\203\331\210\331\206 \331\205\331\206 \330\253\331\204\330\247\330"
                        "\253\330\251 \330\243\330\255\330\261\331\201 \331\201\331\202\330\267 \331\203\331\205\330\247\330\243\331\206 \330\271\331\205\331\204\331\212\330\251 \330\247\331\204\330\250\330\255\330\253  \330\247\331\204\331\205\330\252\330\271\330\257\330\257 \330\247\331\210 \330\271\331\204\331\211 \331\205\330\263\330\252\331\210\331\211 \330\247\331\204\330\254\330\260\330\261 \330\252\330\263\330\252\330\272\330\261\331\202 \331\210\331\202\330\252\330\247 \330\243\330\267\331\210\331\204</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialogfind: public Ui_Dialogfind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFIND_H
