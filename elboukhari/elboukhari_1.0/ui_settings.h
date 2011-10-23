/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Oct 17 20:21:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *labelFont;
    QToolButton *toolButtonFont;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButtonFileName;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxAutoPlay;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonPlayNext;
    QRadioButton *radioButtonPlayOne;
    QRadioButton *radioButtonPlayRepeat;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(271, 277);
        settings->setLayoutDirection(Qt::RightToLeft);
        verticalLayout_3 = new QVBoxLayout(settings);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(settings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        labelFont = new QLabel(settings);
        labelFont->setObjectName(QString::fromUtf8("labelFont"));

        horizontalLayout->addWidget(labelFont);

        toolButtonFont = new QToolButton(settings);
        toolButtonFont->setObjectName(QString::fromUtf8("toolButtonFont"));

        horizontalLayout->addWidget(toolButtonFont);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(settings);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(settings);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        toolButtonFileName = new QToolButton(settings);
        toolButtonFileName->setObjectName(QString::fromUtf8("toolButtonFileName"));

        horizontalLayout_2->addWidget(toolButtonFileName);


        verticalLayout_3->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBoxAutoPlay = new QCheckBox(groupBox);
        checkBoxAutoPlay->setObjectName(QString::fromUtf8("checkBoxAutoPlay"));
        checkBoxAutoPlay->setChecked(true);

        verticalLayout->addWidget(checkBoxAutoPlay);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtonPlayNext = new QRadioButton(frame);
        radioButtonPlayNext->setObjectName(QString::fromUtf8("radioButtonPlayNext"));
        radioButtonPlayNext->setChecked(true);

        verticalLayout_2->addWidget(radioButtonPlayNext);

        radioButtonPlayOne = new QRadioButton(frame);
        radioButtonPlayOne->setObjectName(QString::fromUtf8("radioButtonPlayOne"));

        verticalLayout_2->addWidget(radioButtonPlayOne);

        radioButtonPlayRepeat = new QRadioButton(frame);
        radioButtonPlayRepeat->setObjectName(QString::fromUtf8("radioButtonPlayRepeat"));

        verticalLayout_2->addWidget(radioButtonPlayRepeat);


        verticalLayout->addWidget(frame);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settings, SLOT(reject()));
        QObject::connect(radioButtonPlayNext, SIGNAL(clicked(bool)), checkBoxAutoPlay, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "\330\256\331\212\330\247\330\261\330\247\330\252", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settings", "\330\247\331\204\330\256\330\267 : ", 0, QApplication::UnicodeUTF8));
        labelFont->setText(QString());
        toolButtonFont->setText(QApplication::translate("settings", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settings", "\331\205\330\263\330\247\330\261 \331\205\331\204\331\201\330\247\330\252 \330\247\331\204\330\265\331\210\330\252 :", 0, QApplication::UnicodeUTF8));
        toolButtonFileName->setText(QApplication::translate("settings", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("settings", "\330\256\331\212\330\247\330\261\330\247\330\252 \330\247\331\204\331\202\330\261\330\247\330\241\330\251", 0, QApplication::UnicodeUTF8));
        checkBoxAutoPlay->setText(QApplication::translate("settings", "\331\202\330\261\330\247\330\241\330\251 \330\252\331\204\331\202\330\247\330\246\331\212\330\251", 0, QApplication::UnicodeUTF8));
        radioButtonPlayNext->setText(QApplication::translate("settings", "\331\202\330\261\330\247\330\241\330\251 \330\247\331\204\330\252\330\247\331\204\331\212 \330\271\331\206\330\257 \330\247\331\204\330\247\331\206\330\252\331\207\330\247\330\241", 0, QApplication::UnicodeUTF8));
        radioButtonPlayOne->setText(QApplication::translate("settings", "\331\202\330\261\330\247\330\241\330\251 \331\205\330\261\330\251 \331\210\330\247\330\255\330\257\330\251", 0, QApplication::UnicodeUTF8));
        radioButtonPlayRepeat->setText(QApplication::translate("settings", "\330\252\331\203\330\261\330\247\330\261 \330\271\331\206\330\257 \330\247\331\204\330\247\331\206\330\252\331\207\330\247\330\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
