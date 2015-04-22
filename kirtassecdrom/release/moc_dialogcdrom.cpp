/****************************************************************************
** Meta object code from reading C++ file 'dialogcdrom.h'
**
** Created: Thu 24. Jan 11:05:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogcdrom.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogcdrom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialogcdrom[] = {

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
      18,   13,   12,   12, 0x08,
      59,   13,   12,   12, 0x08,
      97,   13,   12,   12, 0x08,
     142,   12,   12,   12, 0x08,
     170,   12,   12,   12, 0x08,
     199,   12,   12,   12, 0x08,
     231,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialogcdrom[] = {
    "Dialogcdrom\0\0arg1\0"
    "on_lineEditPathMain_textChanged(QString)\0"
    "on_lineEditBooks_textChanged(QString)\0"
    "on_lineEditPathBooksNew_textChanged(QString)\0"
    "on_toolButtonMain_clicked()\0"
    "on_toolButtonBooks_clicked()\0"
    "on_toolButtonBooksNew_clicked()\0"
    "on_buttonBox_accepted()\0"
};

void Dialogcdrom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialogcdrom *_t = static_cast<Dialogcdrom *>(_o);
        switch (_id) {
        case 0: _t->on_lineEditPathMain_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEditBooks_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEditPathBooksNew_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_toolButtonMain_clicked(); break;
        case 4: _t->on_toolButtonBooks_clicked(); break;
        case 5: _t->on_toolButtonBooksNew_clicked(); break;
        case 6: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialogcdrom::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialogcdrom::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialogcdrom,
      qt_meta_data_Dialogcdrom, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialogcdrom::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialogcdrom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialogcdrom::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialogcdrom))
        return static_cast<void*>(const_cast< Dialogcdrom*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialogcdrom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
