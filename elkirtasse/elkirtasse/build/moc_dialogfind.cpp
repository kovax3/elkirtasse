/****************************************************************************
** Meta object code from reading C++ file 'dialogfind.h'
**
** Created: Thu Oct 6 18:59:34 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogfind.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogfind.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialogfind[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      73,   66,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialogfind[] = {
    "Dialogfind\0\0item,\0"
    "on_treeWidget_itemChanged(QTreeWidgetItem*,int)\0"
    "button\0on_buttonBox_clicked(QAbstractButton*)\0"
    "on_lineEdit_2_textChanged(QString)\0"
};

const QMetaObject Dialogfind::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialogfind,
      qt_meta_data_Dialogfind, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialogfind::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialogfind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialogfind::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialogfind))
        return static_cast<void*>(const_cast< Dialogfind*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialogfind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_treeWidget_itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: on_lineEdit_2_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
