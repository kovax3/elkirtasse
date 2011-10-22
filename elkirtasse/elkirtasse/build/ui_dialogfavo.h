/********************************************************************************
** Form generated from reading UI file 'dialogfavo.ui'
**
** Created: Thu Oct 6 18:58:31 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFAVO_H
#define UI_DIALOGFAVO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogfavo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogfavo)
    {
        if (dialogfavo->objectName().isEmpty())
            dialogfavo->setObjectName(QString::fromUtf8("dialogfavo"));
        dialogfavo->resize(313, 196);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/groupb.png"), QSize(), QIcon::Normal, QIcon::Off);
        dialogfavo->setWindowIcon(icon);
        dialogfavo->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(dialogfavo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(dialogfavo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(dialogfavo);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(dialogfavo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(76, 16777215));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(dialogfavo);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(dialogfavo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(dialogfavo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(dialogfavo);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogfavo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogfavo, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogfavo);
    } // setupUi

    void retranslateUi(QDialog *dialogfavo)
    {
        dialogfavo->setWindowTitle(QApplication::translate("dialogfavo", "\330\247\331\204\331\205\331\201\330\266\331\204\330\251", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialogfavo", "\330\255\330\257\330\257 \331\205\330\254\331\204\330\257\330\247 \331\205\331\206 \330\247\331\204\331\202\330\247\330\246\331\205\330\251 \330\247\331\210 \330\247\331\206\330\264\330\243 \331\205\330\254\331\204\330\257\330\247 \330\254\331\212\330\257\330\247 ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dialogfavo", "\331\205\330\254\331\204\330\257 \330\254\330\257\331\212\330\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialogfavo", "\330\247\330\257\330\256\331\204 \330\247\330\263\331\205\330\247 \331\204\331\204\331\205\331\201\330\266\331\204\330\251 \331\201\331\212 \331\205\330\261\330\250\330\271 \330\247\331\204\331\206\330\265", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dialogfavo: public Ui_dialogfavo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFAVO_H
