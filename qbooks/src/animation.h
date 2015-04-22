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
#ifndef ANIMATION_H
#define ANIMATION_H



#include <QtGui>
#include <QObject>

class Pixmap : public QGraphicsWidget
{
    Q_OBJECT

public:
    Pixmap(const QPixmap &pix, QGraphicsItem *parent = 0)
        : QGraphicsWidget(parent), orig(pix), p(pix)
    {

        setCacheMode(DeviceCoordinateCache);
        setAcceptHoverEvents(true);
    }


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
    {
        painter->drawPixmap(QPointF(), p);
    }

    virtual void setGeometry(const QRectF &rect)
    {
        QGraphicsWidget::setGeometry(rect);

        if (rect.size().width() > orig.size().width())
            p = orig.scaled(rect.size().toSize());
        else
            p = orig;
    }
signals:
    void pressed();
    void release();
    void enter();
    void leave();


protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *)
    {
        emit pressed();
        update();
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *)
    {
        emit release();
        update();
    }
    void hoverEnterEvent(  QGraphicsSceneHoverEvent *)
    {

        emit enter();
        update();

    }
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent  *)
    {
        emit leave();
        update();
    }
private:
    QPixmap orig;
    QPixmap p;

};
class View : public QGraphicsView
{
    Q_OBJECT
public:
    View( QWidget *parent) : QGraphicsView(parent) { }
    View();
    ~View();
    QTreeWidget *treeView;
    void chargePixmap();
    QLineEdit *lineEdit;
    QLabel *label;
    bool threeD;
   // QComboBox *comboBox;
    int recentNbr;
    enum { MaxRecentFiles = 15 };
    QAction *recentFileActs[MaxRecentFiles];
protected:
    void resizeEvent(QResizeEvent *event)
    {
        //        if (threeD==true){
        //            QGraphicsView::resizeEvent(event);
        //            fitInView(sceneRect(), Qt::KeepAspectRatio);
        //        }else{
        //            QGraphicsView::resizeEvent(event);
        //            fitInView(sceneRect(), Qt::IgnoreAspectRatio);
        //        }
        QGraphicsView::resizeEvent(event);
        setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    }
void keyPressEvent(QKeyEvent *event);
void keyReleaseEvent(QKeyEvent *event);
private:
    QGraphicsScene *mscene;
    #if QT_VERSION >= 0x040600
    QEasingCurve::Type curveType;
#endif
    int itemCurant;
    QList<Pixmap *> items;
    QTimer  *m_timer ;
    bool m_right;
    bool isBook;
     bool isThreeD;
public slots:
    void chargeLevelOne();
    void chargeRecent();
    void chargeEnrto();
private slots:
    void animChargePixmape(int level,int index,int indexParent);
    void ThreeDChargePixmape(int level,int index,int indexParent);
    void animTeled();
    void animChargeLevelTow();
    void animItemOpenBook();
    void moveThreeDright();
    void moveThreeDleft();
    void moveThreeD(bool right);
    void animEnterItem();
    void animLeaveItem();
    void ThreeDItemOpenBook();
    void threedChargeLevelTow();
    void time_run();
    void stop_time();
    void chargeNavigator();
    void chargeMaskItem();
    void comboItemOpenBook();
    void ThreeDcomboItemOpenBook();
    void animEtoile(QRect rect);
       void animEtoileTitle();
        void animEtoileBook();
};

#endif // ANIMATION_H
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
#ifndef ANIMATION_H
#define ANIMATION_H



#include <QtGui>
#include <QObject>

class Pixmap : public QGraphicsWidget
{
    Q_OBJECT

public:
    Pixmap(const QPixmap &pix, QGraphicsItem *parent = 0)
        : QGraphicsWidget(parent), orig(pix), p(pix)
    {

        setCacheMode(DeviceCoordinateCache);
        setAcceptHoverEvents(true);
    }


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
    {
        painter->drawPixmap(QPointF(), p);
    }

    virtual void setGeometry(const QRectF &rect)
    {
        QGraphicsWidget::setGeometry(rect);

        if (rect.size().width() > orig.size().width())
            p = orig.scaled(rect.size().toSize());
        else
            p = orig;
    }
signals:
    void pressed();
    void release();
    void enter();
    void leave();


protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *)
    {
        emit pressed();
        update();
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *)
    {
        emit release();
        update();
    }
    void hoverEnterEvent(  QGraphicsSceneHoverEvent *)
    {

        emit enter();
        update();

    }
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent  *)
    {
        emit leave();
        update();
    }
private:
    QPixmap orig;
    QPixmap p;

};
class View : public QGraphicsView
{
    Q_OBJECT
public:
    View( QWidget *parent) : QGraphicsView(parent) { }
    View();
    ~View();
    QTreeWidget *treeView;
    void chargePixmap();
    QLineEdit *lineEdit;
    QLabel *label;
    bool threeD;
   // QComboBox *comboBox;
    int recentNbr;
    enum { MaxRecentFiles = 15 };
    QAction *recentFileActs[MaxRecentFiles];
protected:
    void resizeEvent(QResizeEvent *event)
    {
        //        if (threeD==true){
        //            QGraphicsView::resizeEvent(event);
        //            fitInView(sceneRect(), Qt::KeepAspectRatio);
        //        }else{
        //            QGraphicsView::resizeEvent(event);
        //            fitInView(sceneRect(), Qt::IgnoreAspectRatio);
        //        }
        QGraphicsView::resizeEvent(event);
        setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    }
void keyPressEvent(QKeyEvent *event);
void keyReleaseEvent(QKeyEvent *event);
private:
    QGraphicsScene *mscene;
    #if QT_VERSION >= 0x040600
    QEasingCurve::Type curveType;
#endif
    int itemCurant;
    QList<Pixmap *> items;
    QTimer  *m_timer ;
    bool m_right;
    bool isBook;
     bool isThreeD;
public slots:
    void chargeLevelOne();
    void chargeRecent();
    void chargeEnrto();
private slots:
    void animChargePixmape(int level,int index,int indexParent);
    void ThreeDChargePixmape(int level,int index,int indexParent);
    void animTeled();
    void animChargeLevelTow();
    void animItemOpenBook();
    void moveThreeDright();
    void moveThreeDleft();
    void moveThreeD(bool right);
    void animEnterItem();
    void animLeaveItem();
    void ThreeDItemOpenBook();
    void threedChargeLevelTow();
    void time_run();
    void stop_time();
    void chargeNavigator();
    void chargeMaskItem();
    void comboItemOpenBook();
    void ThreeDcomboItemOpenBook();
    void animEtoile(QRect rect);
       void animEtoileTitle();
        void animEtoileBook();
};

#endif // ANIMATION_H
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
