/****************************************************************************
** Meta object code from reading C++ file 'dialogupdat.h'
**
** Created: Thu Oct 6 18:59:33 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogupdat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogupdat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dialogupdat[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      46,   40,   12,   12, 0x08,
      89,   12,   12,   12, 0x08,
     113,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dialogupdat[] = {
    "dialogupdat\0\0on_pushButtonImg_clicked()\0"
    "index\0on_comboBox_group_currentIndexChanged(int)\0"
    "on_buttonBox_accepted()\0okEnabled()\0"
};

const QMetaObject dialogupdat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialogupdat,
      qt_meta_data_dialogupdat, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialogupdat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialogupdat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialogupdat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialogupdat))
        return static_cast<void*>(const_cast< dialogupdat*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialogupdat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonImg_clicked(); break;
        case 1: on_comboBox_group_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_buttonBox_accepted(); break;
        case 3: okEnabled(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
