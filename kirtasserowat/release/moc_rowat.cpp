/****************************************************************************
** Meta object code from reading C++ file 'rowat.h'
**
** Created: Thu 24. Jan 11:05:47 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rowat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rowat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rowat[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,    7,    6,    6, 0x0a,
      50,    6,   45,    6, 0x0a,
      81,   72,   64,    6, 0x0a,
     105,  101,   64,    6, 0x0a,
     135,  118,    6,    6, 0x0a,
     179,    6,    6,    6, 0x0a,
     191,    6,   64,    6, 0x08,
     208,  203,   64,    6, 0x08,
     226,  118,   45,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rowat[] = {
    "rowat\0\0view\0treeChargeRowtName(QTreeWidget*)\0"
    "bool\0chargeRowat()\0QString\0position\0"
    "moveToPosition(int)\0pos\0readxml(int)\0"
    "rawi,viewS,viewD\0"
    "rawiFind(QString,QTreeWidget*,QTreeWidget*)\0"
    "clearData()\0creatHtml()\0rawi\0"
    "fullRawi(QString)\0"
    "rawiFindAbou(QString,QTreeWidget*,QTreeWidget*)\0"
};

void rowat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        rowat *_t = static_cast<rowat *>(_o);
        switch (_id) {
        case 0: _t->treeChargeRowtName((*reinterpret_cast< QTreeWidget*(*)>(_a[1]))); break;
        case 1: { bool _r = _t->chargeRowat();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->moveToPosition((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->readxml((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: _t->rawiFind((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidget*(*)>(_a[2])),(*reinterpret_cast< QTreeWidget*(*)>(_a[3]))); break;
        case 5: _t->clearData(); break;
        case 6: { QString _r = _t->creatHtml();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->fullRawi((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->rawiFindAbou((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidget*(*)>(_a[2])),(*reinterpret_cast< QTreeWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rowat::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rowat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rowat,
      qt_meta_data_rowat, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rowat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rowat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rowat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rowat))
        return static_cast<void*>(const_cast< rowat*>(this));
    if (!strcmp(_clname, "RowatInterface"))
        return static_cast< RowatInterface*>(const_cast< rowat*>(this));
    if (!strcmp(_clname, "com.trolltech.Plugin.RowatInterface/1.0"))
        return static_cast< RowatInterface*>(const_cast< rowat*>(this));
    return QObject::qt_metacast(_clname);
}

int rowat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
