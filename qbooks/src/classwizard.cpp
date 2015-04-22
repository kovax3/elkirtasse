<<<<<<< HEAD
/****************************************************************************
//   elkirtasse Copyright (C) 2010 yahia abouzakaria <yahiaui@gmail.com>
//
//      This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
//      This is free software, and you are welcome to redistribute it
//      under certain conditions; type `show c' for details.
//
//  The hypothetical commands `show w' and `show c' should show the appropriate
//  parts of the General Public License.  Of course, your program's commands
//  might be different; for a GUI interface, you would use an "about box".
//
//    You should also get your employer (if you work as a programmer) or school,
//  if any, to sign a "copyright disclaimer" for the program, if necessary.
//  For more information on this, and how to apply and follow the GNU GPL, see
//  <http://www.gnu.org/licenses/>.
//
//    The GNU General Public License does not permit incorporating your program
//  into proprietary programs.  If your program is a subroutine library, you
//  may consider it more useful to permit linking proprietary applications with
//  the library.  If this is what you want to do, use the GNU Lesser General
//  Public License instead of this License.  But first, please read
//  <http://www.gnu.org/philosophy/why-not-lgpl.html>.
// ----------------------------------------------------------
** If you have questions regarding the use of this file, please contact
** abouzakaria (yahiaui@gmail.com)
** $elkirtasse_END_LICENSE$
**
****************************************************************************/
#include <QtGui>
#include "classwizard.h"
#include <QMessageBox>



ClassWizard::ClassWizard(QWidget *parent)
    : QWizard(parent)
{
     setPage(Page_Intro, new IntroPage);
     setPage(Page_InfoPage, new ClassInfoPage);
     setPage(Page_TreeBook, new PageTreeBook);
     setPage(Page_Details, new PageTreeFavorite);
     setPage(Page_Conclusion, new ConclusionPage);

     setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
     setPixmap(QWizard::BackgroundPixmap, QPixmap(":/images/background.png"));

     setWindowTitle(trUtf8("معالج الارتباط التشعبي"));
}
//ترتيب النوافذ
int ClassWizard::nextId()const
{
   switch (currentId()) {
     case Page_Intro:
          return Page_InfoPage;
     case Page_InfoPage:
     if (field("rUrlBook").toBool()) {
         return ClassWizard::Page_TreeBook;
     } else if(field("rUrlFavorite").toBool()){
         return ClassWizard::Page_Details;
     }else{
         return ClassWizard::Page_Conclusion;
     }
     case Page_TreeBook:
         return ClassWizard::Page_Conclusion;
     case Page_Details:
         return ClassWizard::Page_Conclusion;
     case Page_Conclusion:
         default:
         return -1;
    }
}
//عند الانتهاء والقبول
void ClassWizard::accept()
{
    if (field("rUrlBook").toBool()) {
        urlTexte=field("bookInfo").toString();

    } else if(field("rUrlFavorite").toBool()){
        urlTexte=field("FavoriteInfo").toString();

    }else{
        QString texte=field("UrlWebName").toString();
     if (texte.isEmpty()){
         QMessageBox::information(this,"",trUtf8("الرجاء انقر على الرجوع للخلف ثم ادخل عنوان صفحة ويب في مربع النص"));
         return;
     }
        if (texte.contains("http://")){
            urlTexte=texte;
        }else{
            urlTexte="http://"+texte;
        }
    }
    QDialog::accept();
}
//نافذة البداية
IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{

    setTitle(trUtf8("مرحبا"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark1.png"));

    label = new QLabel(trUtf8("هذا المعالج سينشئ لك ارتباطا تشعبيا  "
                              "بين صفحتك وصفحة أخرى سوء كانت في نفس الكتاب أو في كتاب أخر " ));

    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}
//نافذة الاختيار
ClassInfoPage::ClassInfoPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("اختيار الصفحة"));
    setSubTitle(trUtf8("يمكنك تحديد الصفحة التي تريد الارتباط بها مع الصفحة الحالية "
                   "واختيار اسم لهذا الارتباط"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/image/groupbook.png"));

    labelUrlName = new QLabel(trUtf8("&اسم الارتباط"));
    lineEditUrlName = new QLineEdit;
    labelUrlName->setBuddy(lineEditUrlName);

     groupBox = new QGroupBox(trUtf8(" ارتبط مع "));

    radioButtonUrlBook = new QRadioButton(trUtf8(" كتاب محدد "));
    radioButtonUrlFavorite = new QRadioButton(trUtf8(" صفحة كتاب في المفضلة "));
    radioButtonUrlWeb = new QRadioButton(trUtf8(" ارتباط مع صفحة ويب "));
lineEditUrlWebName = new QLineEdit;
    radioButtonUrlFavorite->setChecked(true);
lineEditUrlWebName->setEnabled(false);

connect(radioButtonUrlWeb, SIGNAL(toggled(bool)),
            lineEditUrlWebName, SLOT(setEnabled(bool)));

    registerField("urlName*", lineEditUrlName);
    registerField("rUrlBook", radioButtonUrlBook);
    registerField("rUrlFavorite", radioButtonUrlFavorite);
    registerField("UrlWeb", radioButtonUrlWeb);
 registerField("UrlWebName", lineEditUrlWebName);
    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(radioButtonUrlBook);
    groupBoxLayout->addWidget(radioButtonUrlFavorite);
    groupBoxLayout->addWidget(radioButtonUrlWeb);
groupBoxLayout->addWidget(lineEditUrlWebName);

    groupBox->setLayout(groupBoxLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelUrlName, 0, 0);
    layout->addWidget(lineEditUrlName, 0, 1);
    layout->addWidget(groupBox, 3, 0, 1, 2);
    layout->addWidget(groupBox, 3, 0, 1, 2);

    setLayout(layout);
}

//نافذة مجموعة الكتب
PageTreeBook::PageTreeBook(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("اختر كتابا"));
    setSubTitle(trUtf8("اختر كتابا من شجرة الكتب حتى يتم اظافته للارتباط التشعبي"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/image/groupbook.png"));

    treeViewBook=new QTreeWidget();
    bookInfo = new QLineEdit();

    //**********تحميل الشجرة********
    Messages->treeChargeGroupe(treeViewBook,0,true);

    connect(treeViewBook, SIGNAL(itemSelectionChanged()),
            this, SLOT(treeBookitemSelectionChanged()));

    registerField("bookInfo*", bookInfo);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(treeViewBook, 0, 0);
    setLayout(layout);

}
//النقر على العنصر المحدد في الشجرة
void PageTreeBook::treeBookitemSelectionChanged()
{
    QTreeWidgetItem *item=treeViewBook->currentItem();
    QString textId=item->data(1,1).toString();
    QString textbook=item->text(0);
    QString oldText=field("urlName").toString();
    QString textAutors=item->text(1);

    if (!textId.isEmpty()){

         bookInfo->setText(oldText+"/"+textbook+"/"+textAutors+"/"+textId+"/0");
     }else{
         bookInfo->setText("");
     }
}
//تحرير الفهرسة
PageTreeFavorite::PageTreeFavorite(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("اشارة مرجعية في المفضلة"));
    setSubTitle(trUtf8(" يمكنك اختيار صفحة من اشارة مرجعية في المفضلة  "
                   " قم بتحديد عنصر من شجرة المفضلة"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/image/groupbook.png"));

    FavoriteInfo = new QLineEdit;
    treeViewFavorite=new QTreeWidget();
    registerField("FavoriteInfo*", FavoriteInfo);
QIcon ico;
QIcon ico2;
    connect(treeViewFavorite, SIGNAL(itemSelectionChanged()),
            this, SLOT(treeFavoriteItemSelectionChanged()));
     //**********تحميل الشجرة********
   Messages->favorite_charge(treeViewFavorite,ico,ico2);

    QGridLayout *layout = new QGridLayout;
   layout->addWidget(treeViewFavorite, 0, 0);
   setLayout(layout);
}
void PageTreeFavorite::treeFavoriteItemSelectionChanged()
{
  QTreeWidgetItem *item=treeViewFavorite->currentItem();
    QString textId=item->data(1,1).toString();
    QString textbook=item->text(1);
    QString oldText=field("urlName").toString();
     QString textpage=item->data(2,1).toString();;
    QString textAutors=item->text(2);

    if (!textId.isEmpty()){
         FavoriteInfo->setText(oldText+"/"+textbook+"/"+textAutors+"/"+textId+"/"+textpage);
     }else{
         FavoriteInfo->setText("");
     }
}
ConclusionPage::ConclusionPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("انتهاء"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark2.png"));
    label = new QLabel;
    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

void ConclusionPage::initializePage()
{
//QTreeWidgetItem* item=
    QString finishText = wizard()->buttonText(QWizard::FinishButton);
    finishText.remove('&');
    label->setText(trUtf8("انقر %1 لانهاء المعالج.")
                   .arg(finishText));
}
=======
/****************************************************************************
//   elkirtasse Copyright (C) 2010 yahia abouzakaria <yahiaui@gmail.com>
//
//      This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
//      This is free software, and you are welcome to redistribute it
//      under certain conditions; type `show c' for details.
//
//  The hypothetical commands `show w' and `show c' should show the appropriate
//  parts of the General Public License.  Of course, your program's commands
//  might be different; for a GUI interface, you would use an "about box".
//
//    You should also get your employer (if you work as a programmer) or school,
//  if any, to sign a "copyright disclaimer" for the program, if necessary.
//  For more information on this, and how to apply and follow the GNU GPL, see
//  <http://www.gnu.org/licenses/>.
//
//    The GNU General Public License does not permit incorporating your program
//  into proprietary programs.  If your program is a subroutine library, you
//  may consider it more useful to permit linking proprietary applications with
//  the library.  If this is what you want to do, use the GNU Lesser General
//  Public License instead of this License.  But first, please read
//  <http://www.gnu.org/philosophy/why-not-lgpl.html>.
// ----------------------------------------------------------
** If you have questions regarding the use of this file, please contact
** abouzakaria (yahiaui@gmail.com)
** $elkirtasse_END_LICENSE$
**
****************************************************************************/
#include <QtGui>
#include "classwizard.h"
#include <QMessageBox>



ClassWizard::ClassWizard(QWidget *parent)
    : QWizard(parent)
{
     setPage(Page_Intro, new IntroPage);
     setPage(Page_InfoPage, new ClassInfoPage);
     setPage(Page_TreeBook, new PageTreeBook);
     setPage(Page_Details, new PageTreeFavorite);
     setPage(Page_Conclusion, new ConclusionPage);

     setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
     setPixmap(QWizard::BackgroundPixmap, QPixmap(":/images/background.png"));

     setWindowTitle(trUtf8("معالج الارتباط التشعبي"));
}
//ترتيب النوافذ
int ClassWizard::nextId()const
{
   switch (currentId()) {
     case Page_Intro:
          return Page_InfoPage;
     case Page_InfoPage:
     if (field("rUrlBook").toBool()) {
         return ClassWizard::Page_TreeBook;
     } else if(field("rUrlFavorite").toBool()){
         return ClassWizard::Page_Details;
     }else{
         return ClassWizard::Page_Conclusion;
     }
     case Page_TreeBook:
         return ClassWizard::Page_Conclusion;
     case Page_Details:
         return ClassWizard::Page_Conclusion;
     case Page_Conclusion:
         default:
         return -1;
    }
}
//عند الانتهاء والقبول
void ClassWizard::accept()
{
    if (field("rUrlBook").toBool()) {
        urlTexte=field("bookInfo").toString();

    } else if(field("rUrlFavorite").toBool()){
        urlTexte=field("FavoriteInfo").toString();

    }else{
        QString texte=field("UrlWebName").toString();
     if (texte.isEmpty()){
         QMessageBox::information(this,"",trUtf8("الرجاء انقر على الرجوع للخلف ثم ادخل عنوان صفحة ويب في مربع النص"));
         return;
     }
        if (texte.contains("http://")){
            urlTexte=texte;
        }else{
            urlTexte="http://"+texte;
        }
    }
    QDialog::accept();
}
//نافذة البداية
IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{

    setTitle(trUtf8("مرحبا"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark1.png"));

    label = new QLabel(trUtf8("هذا المعالج سينشئ لك ارتباطا تشعبيا  "
                              "بين صفحتك وصفحة أخرى سوء كانت في نفس الكتاب أو في كتاب أخر " ));

    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}
//نافذة الاختيار
ClassInfoPage::ClassInfoPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("اختيار الصفحة"));
    setSubTitle(trUtf8("يمكنك تحديد الصفحة التي تريد الارتباط بها مع الصفحة الحالية "
                   "واختيار اسم لهذا الارتباط"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/image/groupbook.png"));

    labelUrlName = new QLabel(trUtf8("&اسم الارتباط"));
    lineEditUrlName = new QLineEdit;
    labelUrlName->setBuddy(lineEditUrlName);

     groupBox = new QGroupBox(trUtf8(" ارتبط مع "));

    radioButtonUrlBook = new QRadioButton(trUtf8(" كتاب محدد "));
    radioButtonUrlFavorite = new QRadioButton(trUtf8(" صفحة كتاب في المفضلة "));
    radioButtonUrlWeb = new QRadioButton(trUtf8(" ارتباط مع صفحة ويب "));
lineEditUrlWebName = new QLineEdit;
    radioButtonUrlFavorite->setChecked(true);
lineEditUrlWebName->setEnabled(false);

connect(radioButtonUrlWeb, SIGNAL(toggled(bool)),
            lineEditUrlWebName, SLOT(setEnabled(bool)));

    registerField("urlName*", lineEditUrlName);
    registerField("rUrlBook", radioButtonUrlBook);
    registerField("rUrlFavorite", radioButtonUrlFavorite);
    registerField("UrlWeb", radioButtonUrlWeb);
 registerField("UrlWebName", lineEditUrlWebName);
    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(radioButtonUrlBook);
    groupBoxLayout->addWidget(radioButtonUrlFavorite);
    groupBoxLayout->addWidget(radioButtonUrlWeb);
groupBoxLayout->addWidget(lineEditUrlWebName);

    groupBox->setLayout(groupBoxLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelUrlName, 0, 0);
    layout->addWidget(lineEditUrlName, 0, 1);
    layout->addWidget(groupBox, 3, 0, 1, 2);
    layout->addWidget(groupBox, 3, 0, 1, 2);

    setLayout(layout);
}

//نافذة مجموعة الكتب
PageTreeBook::PageTreeBook(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("اختر كتابا"));
    setSubTitle(trUtf8("اختر كتابا من شجرة الكتب حتى يتم اظافته للارتباط التشعبي"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/image/groupbook.png"));

    treeViewBook=new QTreeWidget();
    bookInfo = new QLineEdit();

    //**********تحميل الشجرة********
    Messages->treeChargeGroupe(treeViewBook,0,true);

    connect(treeViewBook, SIGNAL(itemSelectionChanged()),
            this, SLOT(treeBookitemSelectionChanged()));

    registerField("bookInfo*", bookInfo);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(treeViewBook, 0, 0);
    setLayout(layout);

}
//النقر على العنصر المحدد في الشجرة
void PageTreeBook::treeBookitemSelectionChanged()
{
    QTreeWidgetItem *item=treeViewBook->currentItem();
    QString textId=item->data(1,1).toString();
    QString textbook=item->text(0);
    QString oldText=field("urlName").toString();
    QString textAutors=item->text(1);

    if (!textId.isEmpty()){

         bookInfo->setText(oldText+"/"+textbook+"/"+textAutors+"/"+textId+"/0");
     }else{
         bookInfo->setText("");
     }
}
//تحرير الفهرسة
PageTreeFavorite::PageTreeFavorite(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("اشارة مرجعية في المفضلة"));
    setSubTitle(trUtf8(" يمكنك اختيار صفحة من اشارة مرجعية في المفضلة  "
                   " قم بتحديد عنصر من شجرة المفضلة"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/image/groupbook.png"));

    FavoriteInfo = new QLineEdit;
    treeViewFavorite=new QTreeWidget();
    registerField("FavoriteInfo*", FavoriteInfo);
QIcon ico;
QIcon ico2;
    connect(treeViewFavorite, SIGNAL(itemSelectionChanged()),
            this, SLOT(treeFavoriteItemSelectionChanged()));
     //**********تحميل الشجرة********
   Messages->favorite_charge(treeViewFavorite,ico,ico2);

    QGridLayout *layout = new QGridLayout;
   layout->addWidget(treeViewFavorite, 0, 0);
   setLayout(layout);
}
void PageTreeFavorite::treeFavoriteItemSelectionChanged()
{
  QTreeWidgetItem *item=treeViewFavorite->currentItem();
    QString textId=item->data(1,1).toString();
    QString textbook=item->text(1);
    QString oldText=field("urlName").toString();
     QString textpage=item->data(2,1).toString();;
    QString textAutors=item->text(2);

    if (!textId.isEmpty()){
         FavoriteInfo->setText(oldText+"/"+textbook+"/"+textAutors+"/"+textId+"/"+textpage);
     }else{
         FavoriteInfo->setText("");
     }
}
ConclusionPage::ConclusionPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(trUtf8("انتهاء"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark2.png"));
    label = new QLabel;
    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

void ConclusionPage::initializePage()
{
//QTreeWidgetItem* item=
    QString finishText = wizard()->buttonText(QWizard::FinishButton);
    finishText.remove('&');
    label->setText(trUtf8("انقر %1 لانهاء المعالج.")
                   .arg(finishText));
}
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
