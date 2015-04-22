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
#include "about.h"
#include  "ui_about.h"
#include <QtGui>
About::About(QWidget *parent)
    : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);
    QGraphicsWidget *  panelParent = new QGraphicsWidget;
    QGraphicsPixmapItem* lab=new QGraphicsPixmapItem(panelParent);
   // QGraphicsPixmapItem* labreflet=new QGraphicsPixmapItem(panelParent);
    m_scene=new QGraphicsScene();
    //setText(trUtf8("القرطاس"),m_scene);
    lab->setPixmap(QPixmap(QString::fromUtf8(":/images/image/groupbook.png")));
   // labreflet->setPixmap(QPixmap(QString::fromUtf8(":/images/image/groupbook2.png")));
#if QT_VERSION >= 0x040600

    QGraphicsDropShadowEffect *efet=new QGraphicsDropShadowEffect;
    efet->setOffset(4,3);
    efet->setColor(QColor(63, 63, 63, 80));
    lab->setGraphicsEffect(efet);

//    QLinearGradient alphaGradient(0, 0,0,128);
//    //  alphaGradient.setColorAt(0.0, Qt::transparent);
 //   alphaGradient.setColorAt(0.0, QColor(63, 63, 63, 30));
//    alphaGradient.setColorAt(0.2, QColor(63, 63, 63, 40));
//    alphaGradient.setColorAt(1.0, Qt::transparent);
//    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
//    effect->setOpacityMask(alphaGradient);
//    labreflet->setGraphicsEffect(effect);

    //labreflet->setTransform(QTransform().rotate(180).translate(-120, -120));

    QPropertyAnimation * anim = new QPropertyAnimation(panelParent, "pos");
    //  lab->setAlignment(Qt::AlignRight);
    anim->setEasingCurve(QEasingCurve::CosineCurve);
    //startAnimation();
    anim->setStartValue(QPointF(0, 0));
    anim->setEndValue(QPointF(0, ui->graphicsView->height()));
    anim->setDuration(1000);
    anim->setLoopCount(-1); // forever
    anim->start();


 #endif
    lab->setPos(0,0);
    //labreflet->setPos(0,128);

    m_scene->addItem(panelParent);

    //   m_scene->setBackgroundBrush(m_scene->palette().window());

    ui->graphicsView->setScene(m_scene);
}
About::~About()
{

//m_anim->stop();
}

