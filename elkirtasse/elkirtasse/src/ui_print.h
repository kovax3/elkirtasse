/********************************************************************************
** Form generated from reading UI file 'print.ui'
**
** Created: Fri Sep 9 14:57:42 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINT_H
#define UI_PRINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Print
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QRadioButton *radioButton_part;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_nbr;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_bgr;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Print)
    {
        if (Print->objectName().isEmpty())
            Print->setObjectName(QString::fromUtf8("Print"));
        Print->resize(346, 318);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/groupb.png"), QSize(), QIcon::Normal, QIcon::Off);
        Print->setWindowIcon(icon);
        Print->setLayoutDirection(Qt::RightToLeft);
        verticalLayout_3 = new QVBoxLayout(Print);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_2 = new QFrame(Print);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(52, 16777215));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(52, 16777215));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        toolButton = new QToolButton(frame_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        radioButton_part = new QRadioButton(frame_2);
        radioButton_part->setObjectName(QString::fromUtf8("radioButton_part"));
        radioButton_part->setChecked(true);

        verticalLayout_2->addWidget(radioButton_part);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_nbr = new QRadioButton(frame_2);
        radioButton_nbr->setObjectName(QString::fromUtf8("radioButton_nbr"));

        horizontalLayout_3->addWidget(radioButton_nbr);

        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(100);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        checkBox = new QCheckBox(frame_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        verticalLayout_2->addWidget(checkBox);

        checkBox_bgr = new QCheckBox(frame_2);
        checkBox_bgr->setObjectName(QString::fromUtf8("checkBox_bgr"));
        checkBox_bgr->setChecked(true);

        verticalLayout_2->addWidget(checkBox_bgr);


        verticalLayout_3->addWidget(frame_2);

        frame = new QFrame(Print);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 60));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_3->addWidget(frame);

        buttonBox = new QDialogButtonBox(Print);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(Print);
        QObject::connect(buttonBox, SIGNAL(rejected()), Print, SLOT(reject()));

        QMetaObject::connectSlotsByName(Print);
    } // setupUi

    void retranslateUi(QDialog *Print)
    {
        Print->setWindowTitle(QApplication::translate("Print", "\330\252\330\265\330\257\331\212\330\261 \331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Print", "\331\206\331\210\330\271 \330\247\331\204\330\252\330\265\330\257\331\212\330\261", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Print", "\331\205\331\204\331\201\330\247\330\252 \331\210\331\212\330\250 html", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Print", "\331\205\331\204\331\201\330\247\330\252 \330\247\331\210\330\250\331\206 \330\247\331\210\331\201\331\212\330\263 \330\247\331\210\330\261\330\254 odf", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Print", "\331\205\331\204\331\201\330\247\330\252 \330\247\331\204\330\267\330\250\330\247\330\271\330\251 \330\247\331\204\331\205\330\255\331\205\331\210\331\204\330\251 pdf", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("Print", "\330\257\331\204\331\212\331\204 \330\247\331\204\330\255\331\201\330\270", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("Print", "...", 0, QApplication::UnicodeUTF8));
        radioButton_part->setText(QApplication::translate("Print", "\331\203\331\204 \330\254\330\262\330\241 \331\201\331\212 \331\205\331\204\331\201 ", 0, QApplication::UnicodeUTF8));
        radioButton_nbr->setText(QApplication::translate("Print", "\330\271\330\257\330\257 \330\247\331\204\330\265\331\201\330\255\330\247\330\252 \331\201\331\212 \331\203\331\204 \331\205\331\204\331\201", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Print", "\330\247\330\257\330\261\330\247\330\254 \330\247\330\261\331\202\330\247\331\205 \330\247\331\204\330\265\331\201\330\255\330\247\330\252 \331\210 \330\247\331\204\330\247\330\254\330\262\330\247\330\241", 0, QApplication::UnicodeUTF8));
        checkBox_bgr->setText(QApplication::translate("Print", "\330\247\330\257\330\261\330\247\330\254 \331\204\331\210\331\206 \330\247\331\204\330\256\331\204\331\201\331\212\330\251", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Print", "\330\247\331\204\330\261\330\254\330\247\330\241 \330\247\331\204\330\247\330\252\330\270\330\247\330\261 \330\254\330\247\330\261\331\212 \330\247\331\204\330\255\331\201\330\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Print: public Ui_Print {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINT_H
