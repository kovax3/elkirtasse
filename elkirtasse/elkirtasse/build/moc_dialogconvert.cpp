/****************************************************************************
** Meta object code from reading C++ file 'dialogconvert.h'
**
** Created: Thu Oct 6 18:59:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogconvert.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogconvert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dialogconvert[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      44,   14,   14,   14, 0x08,
      71,   14,   14,   14, 0x08,
     108,  102,   14,   14, 0x08,
     151,   14,   14,   14, 0x08,
     183,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dialogconvert[] = {
    "dialogconvert\0\0on_toolButton_down_clicked()\0"
    "on_toolButton_up_clicked()\0"
    "on_toolButton_delete_clicked()\0index\0"
    "on_comboBox_group_currentIndexChanged(int)\0"
    "on_toolButton_fileNam_clicked()\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject dialogconvert::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialogconvert,
      qt_meta_data_dialogconvert, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialogconvert::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialogconvert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialogconvert::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialogconvert))
        return static_cast<void*>(const_cast< dialogconvert*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialogconvert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_toolButton_down_clicked(); break;
        case 1: on_toolButton_up_clicked(); break;
        case 2: on_toolButton_delete_clicked(); break;
        case 3: on_comboBox_group_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_toolButton_fileNam_clicked(); break;
        case 5: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
