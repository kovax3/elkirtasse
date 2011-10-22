/****************************************************************************
** Meta object code from reading C++ file 'animation.h'
**
** Created: Thu Oct 6 18:59:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/animation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Pixmap[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      18,    7,    7,    7, 0x05,
      28,    7,    7,    7, 0x05,
      36,    7,    7,    7, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Pixmap[] = {
    "Pixmap\0\0pressed()\0release()\0enter()\0"
    "leave()\0"
};

const QMetaObject Pixmap::staticMetaObject = {
    { &QGraphicsWidget::staticMetaObject, qt_meta_stringdata_Pixmap,
      qt_meta_data_Pixmap, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Pixmap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Pixmap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Pixmap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Pixmap))
        return static_cast<void*>(const_cast< Pixmap*>(this));
    return QGraphicsWidget::qt_metacast(_clname);
}

int Pixmap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pressed(); break;
        case 1: release(); break;
        case 2: enter(); break;
        case 3: leave(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Pixmap::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Pixmap::release()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Pixmap::enter()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Pixmap::leave()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
static const uint qt_meta_data_View[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      23,    5,    5,    5, 0x0a,
      38,    5,    5,    5, 0x0a,
      76,   52,    5,    5, 0x08,
     107,   52,    5,    5, 0x08,
     140,    5,    5,    5, 0x08,
     152,    5,    5,    5, 0x08,
     173,    5,    5,    5, 0x08,
     192,    5,    5,    5, 0x08,
     210,    5,    5,    5, 0x08,
     233,  227,    5,    5, 0x08,
     250,    5,    5,    5, 0x08,
     266,    5,    5,    5, 0x08,
     282,    5,    5,    5, 0x08,
     303,    5,    5,    5, 0x08,
     326,    5,    5,    5, 0x08,
     337,    5,    5,    5, 0x08,
     349,    5,    5,    5, 0x08,
     367,    5,    5,    5, 0x08,
     384,    5,    5,    5, 0x08,
     404,    5,    5,    5, 0x08,
     435,  430,    5,    5, 0x08,
     453,    5,    5,    5, 0x08,
     471,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_View[] = {
    "View\0\0chargeLevelOne()\0chargeRecent()\0"
    "chargeEnrto()\0level,index,indexParent\0"
    "animChargePixmape(int,int,int)\0"
    "ThreeDChargePixmape(int,int,int)\0"
    "animTeled()\0animChargeLevelTow()\0"
    "animItemOpenBook()\0moveThreeDright()\0"
    "moveThreeDleft()\0right\0moveThreeD(bool)\0"
    "animEnterItem()\0animLeaveItem()\0"
    "ThreeDItemOpenBook()\0threedChargeLevelTow()\0"
    "time_run()\0stop_time()\0chargeNavigator()\0"
    "chargeMaskItem()\0comboItemOpenBook()\0"
    "ThreeDcomboItemOpenBook()\0rect\0"
    "animEtoile(QRect)\0animEtoileTitle()\0"
    "animEtoileBook()\0"
};

const QMetaObject View::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_View,
      qt_meta_data_View, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &View::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_View))
        return static_cast<void*>(const_cast< View*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: chargeLevelOne(); break;
        case 1: chargeRecent(); break;
        case 2: chargeEnrto(); break;
        case 3: animChargePixmape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: ThreeDChargePixmape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: animTeled(); break;
        case 6: animChargeLevelTow(); break;
        case 7: animItemOpenBook(); break;
        case 8: moveThreeDright(); break;
        case 9: moveThreeDleft(); break;
        case 10: moveThreeD((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: animEnterItem(); break;
        case 12: animLeaveItem(); break;
        case 13: ThreeDItemOpenBook(); break;
        case 14: threedChargeLevelTow(); break;
        case 15: time_run(); break;
        case 16: stop_time(); break;
        case 17: chargeNavigator(); break;
        case 18: chargeMaskItem(); break;
        case 19: comboItemOpenBook(); break;
        case 20: ThreeDcomboItemOpenBook(); break;
        case 21: animEtoile((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        case 22: animEtoileTitle(); break;
        case 23: animEtoileBook(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
