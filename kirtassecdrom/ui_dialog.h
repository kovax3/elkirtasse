/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Jun 28 22:44:19 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonMain;
    QLineEdit *lineEditPathMain;
    QLabel *labelPathMain;
    QFrame *line;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButtonBooks;
    QLineEdit *lineEditBooks;
    QLabel *labelPathBooks;
    QFrame *line_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButtonBooksNew;
    QLineEdit *lineEditPathBooksNew;
    QLabel *labelPathBooksNew;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(486, 341);
        Dialog->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QPalette palette;
        QBrush brush(QColor(254, 255, 170, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(132, 132, 132, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label_4->setPalette(palette);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 170);"));
        label_4->setWordWrap(true);

        verticalLayout->addWidget(label_4);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButtonMain = new QToolButton(Dialog);
        toolButtonMain->setObjectName(QString::fromUtf8("toolButtonMain"));

        horizontalLayout_2->addWidget(toolButtonMain);

        lineEditPathMain = new QLineEdit(Dialog);
        lineEditPathMain->setObjectName(QString::fromUtf8("lineEditPathMain"));

        horizontalLayout_2->addWidget(lineEditPathMain);

        labelPathMain = new QLabel(Dialog);
        labelPathMain->setObjectName(QString::fromUtf8("labelPathMain"));
        labelPathMain->setPixmap(QPixmap(QString::fromUtf8(":/images/image/edit-delete.png")));

        horizontalLayout_2->addWidget(labelPathMain);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButtonBooks = new QToolButton(Dialog);
        toolButtonBooks->setObjectName(QString::fromUtf8("toolButtonBooks"));

        horizontalLayout_3->addWidget(toolButtonBooks);

        lineEditBooks = new QLineEdit(Dialog);
        lineEditBooks->setObjectName(QString::fromUtf8("lineEditBooks"));

        horizontalLayout_3->addWidget(lineEditBooks);

        labelPathBooks = new QLabel(Dialog);
        labelPathBooks->setObjectName(QString::fromUtf8("labelPathBooks"));
        labelPathBooks->setPixmap(QPixmap(QString::fromUtf8(":/images/image/edit-delete.png")));

        horizontalLayout_3->addWidget(labelPathBooks);


        verticalLayout->addLayout(horizontalLayout_3);

        line_2 = new QFrame(Dialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        toolButtonBooksNew = new QToolButton(Dialog);
        toolButtonBooksNew->setObjectName(QString::fromUtf8("toolButtonBooksNew"));

        horizontalLayout_4->addWidget(toolButtonBooksNew);

        lineEditPathBooksNew = new QLineEdit(Dialog);
        lineEditPathBooksNew->setObjectName(QString::fromUtf8("lineEditPathBooksNew"));

        horizontalLayout_4->addWidget(lineEditPathBooksNew);

        labelPathBooksNew = new QLabel(Dialog);
        labelPathBooksNew->setObjectName(QString::fromUtf8("labelPathBooksNew"));
        labelPathBooksNew->setPixmap(QPixmap(QString::fromUtf8(":/images/image/edit-delete.png")));

        horizontalLayout_4->addWidget(labelPathBooksNew);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\330\252\330\255\331\210\331\212\331\204 \331\203\330\252\330\250 \330\247\331\204\330\264\330\247\331\205\331\204\330\251", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hacen Casablanca Light'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\330\252\331\206\330\250\331\212\331\207 : </span><span style=\" color:#000000;\">\330\247\330\260\330\247 \331\203\331\206\330\252 \330\252\330\263\330\252\330\256\330\257\331\205 \331\204\331\206\331\203\330\263 \330\252\330\243\331\203\330\257 \331\205\331\206 \331\210\330\254\331\210\330\257 mdbtools \330\271\331\204\331\211 \330\254\331\207\330\247\330\262\331\203</span></p>\n"
"<p dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0p"
                        "x;\"><span style=\" color:#000000;\">\330\247\330\260\330\247 \331\203\330\247\331\206\330\252 \330\247\331\204\330\264\330\247\331\205\331\204\330\251 \331\205\330\253\330\250\330\252\330\251 \330\271\331\204\331\211 \330\254\331\207\330\247\330\262\331\203 \331\201\331\207\330\260\330\247 \330\247\331\201\330\266\331\204 \331\205\331\206 \330\252\330\255\331\210\331\212\331\204\331\207\330\247 \331\205\331\206 \330\247\331\204\331\202\330\261\330\265 </span></p>\n"
"<p dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\330\247\330\260\330\247\331\203\330\247\331\206 \331\204\330\257\331\212\331\203 \331\202\330\261\330\265 \330\247\331\204\330\264\330\247\331\205\331\204\330\251 \330\247\331\204\330\247\330\265\330\257\330\247\330\261 3 \331\201\331\205\330\247 \331\201\331\210\331\202 \330\252\330\243\331\203\330\257 \331\205\331\206 \330\247\331\206 \331\203\331\204 \330\247\331\204\331\203\330\252"
                        "\330\250 \331\202\330\257 \330\252\331\205 \330\247\330\256\330\261\330\247\330\254\331\207\330\247 \331\205\331\206 \330\247\331\204\330\247\330\261\330\264\331\212\331\201</span></p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\331\205\330\263\330\247\330\261 \331\205\331\204\331\201 \330\250\331\212\330\247\331\206\330\247\330\252 \330\247\331\204\330\264\330\247\331\205\331\204\330\251 main.mdb", 0, QApplication::UnicodeUTF8));
        toolButtonMain->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        lineEditPathMain->setText(QString());
        labelPathMain->setText(QString());
        label_2->setText(QApplication::translate("Dialog", "\331\205\330\263\330\247\330\261 \330\247\331\204\331\203\330\252\330\250 \331\205\330\254\331\204\330\257 books \330\247\331\204\330\260\331\212 \331\212\330\255\330\252\331\210\331\212 \331\203\330\252\330\250 \330\247\331\204\330\264\330\247\331\205\331\204\330\251", 0, QApplication::UnicodeUTF8));
        toolButtonBooks->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        lineEditBooks->setText(QString());
        labelPathBooks->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "\330\247\331\204\331\205\330\263\330\247\330\261 \330\247\331\204\330\260\331\212 \330\263\331\212\330\252\331\205 \330\247\331\206\330\264\330\247\330\241 \330\247\331\204\331\203\330\252\330\250 \331\201\331\212\331\207", 0, QApplication::UnicodeUTF8));
        toolButtonBooksNew->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        lineEditPathBooksNew->setText(QString());
        labelPathBooksNew->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cdrom: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
