/****************************************************************************
** Meta object code from reading C++ file 'dialogmdb.h'
**
** Created: Thu 24. Jan 11:05:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogmdb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogmdb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialogmdb[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      39,   10,   10,   10, 0x08,
      72,   69,   10,   10, 0x08,
      96,   10,   91,   10, 0x08,
     114,  107,   10,   10, 0x08,
     159,  153,   10,   10, 0x08,
     196,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialogmdb[] = {
    "Dialogmdb\0\0on_toolButtonInfo_clicked()\0"
    "on_toolButtonDelete_clicked()\0fn\0"
    "creatBook(QString)\0bool\0creatDir()\0"
    "button\0on_buttonBox_clicked(QAbstractButton*)\0"
    "index\0on_comboBox_currentIndexChanged(int)\0"
    "on_toolButton_fileNam_clicked()\0"
};

void Dialogmdb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialogmdb *_t = static_cast<Dialogmdb *>(_o);
        switch (_id) {
        case 0: _t->on_toolButtonInfo_clicked(); break;
        case 1: _t->on_toolButtonDelete_clicked(); break;
        case 2: _t->creatBook((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: { bool _r = _t->creatDir();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_toolButton_fileNam_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialogmdb::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialogmdb::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialogmdb,
      qt_meta_data_Dialogmdb, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialogmdb::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialogmdb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialogmdb::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialogmdb))
        return static_cast<void*>(const_cast< Dialogmdb*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialogmdb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
