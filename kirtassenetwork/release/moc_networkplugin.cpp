/****************************************************************************
** Meta object code from reading C++ file 'networkplugin.h'
**
** Created: Thu 24. Jan 11:05:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../networkplugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_networkplugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   14,   15,   14, 0x0a,
      44,   36,   15,   14, 0x0a,
      62,   14,   15,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_networkplugin[] = {
    "networkplugin\0\0QString\0execPlugin()\0"
    "urlPath\0loadFile(QString)\0pluginTitle()\0"
};

void networkplugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        networkplugin *_t = static_cast<networkplugin *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->execPlugin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->loadFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->pluginTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData networkplugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject networkplugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_networkplugin,
      qt_meta_data_networkplugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &networkplugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *networkplugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *networkplugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_networkplugin))
        return static_cast<void*>(const_cast< networkplugin*>(this));
    if (!strcmp(_clname, "NetInterface"))
        return static_cast< NetInterface*>(const_cast< networkplugin*>(this));
    if (!strcmp(_clname, "com.elirtasse.Plugin.NetInterface/1.0"))
        return static_cast< NetInterface*>(const_cast< networkplugin*>(this));
    return QObject::qt_metacast(_clname);
}

int networkplugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
