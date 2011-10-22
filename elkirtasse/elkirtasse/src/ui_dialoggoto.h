/********************************************************************************
** Form generated from reading UI file 'dialoggoto.ui'
**
** Created: Fri Sep 9 14:57:42 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGOTO_H
#define UI_DIALOGGOTO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialoggoto
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxPart;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxPage;
    QCheckBox *checkBoxValue;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QSpinBox *spinBoxValue;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialoggoto)
    {
        if (dialoggoto->objectName().isEmpty())
            dialoggoto->setObjectName(QString::fromUtf8("dialoggoto"));
        dialoggoto->resize(211, 148);
        dialoggoto->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(dialoggoto);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(dialoggoto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label);

        spinBoxPart = new QSpinBox(dialoggoto);
        spinBoxPart->setObjectName(QString::fromUtf8("spinBoxPart"));
        spinBoxPart->setMinimum(1);
        spinBoxPart->setMaximum(5000);

        horizontalLayout->addWidget(spinBoxPart);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(dialoggoto);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_2);

        spinBoxPage = new QSpinBox(dialoggoto);
        spinBoxPage->setObjectName(QString::fromUtf8("spinBoxPage"));
        spinBoxPage->setMinimum(1);
        spinBoxPage->setMaximum(100000);

        horizontalLayout_2->addWidget(spinBoxPage);


        verticalLayout->addLayout(horizontalLayout_2);

        checkBoxValue = new QCheckBox(dialoggoto);
        checkBoxValue->setObjectName(QString::fromUtf8("checkBoxValue"));

        verticalLayout->addWidget(checkBoxValue);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSlider = new QSlider(dialoggoto);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        spinBoxValue = new QSpinBox(dialoggoto);
        spinBoxValue->setObjectName(QString::fromUtf8("spinBoxValue"));
        spinBoxValue->setEnabled(false);
        spinBoxValue->setMinimum(1);
        spinBoxValue->setMaximum(5000);

        horizontalLayout_3->addWidget(spinBoxValue);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(dialoggoto);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dialoggoto);
        QObject::connect(buttonBox, SIGNAL(rejected()), dialoggoto, SLOT(reject()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBoxValue, SLOT(setValue(int)));
        QObject::connect(spinBoxValue, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(checkBoxValue, SIGNAL(toggled(bool)), horizontalSlider, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxValue, SIGNAL(toggled(bool)), spinBoxValue, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxValue, SIGNAL(toggled(bool)), spinBoxPage, SLOT(setDisabled(bool)));
        QObject::connect(checkBoxValue, SIGNAL(toggled(bool)), spinBoxPart, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(dialoggoto);
    } // setupUi

    void retranslateUi(QDialog *dialoggoto)
    {
        dialoggoto->setWindowTitle(QApplication::translate("dialoggoto", "\330\247\331\206\330\252\331\202\330\247\331\204 \330\247\331\204\331\211 \330\265\331\201\330\255\330\251 \331\205\330\271\331\212\331\206\330\251", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialoggoto", "\330\247\331\204\330\254\330\262\330\241 :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialoggoto", "\330\247\331\204\330\265\331\201\330\255\330\251 :", 0, QApplication::UnicodeUTF8));
        checkBoxValue->setText(QApplication::translate("dialoggoto", "\330\247\331\206\330\252\331\202\330\247\331\204 \330\247\331\204\331\211 \331\205\331\210\330\266\330\271 \331\201\331\212 \330\247\331\204\331\203\330\252\330\247\330\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialoggoto: public Ui_dialoggoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGOTO_H
