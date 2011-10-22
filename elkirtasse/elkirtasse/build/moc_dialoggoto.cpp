/****************************************************************************
** Meta object code from reading C++ file 'dialoggoto.h'
**
** Created: Thu Oct 6 18:59:54 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialoggoto.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialoggoto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dialoggoto[] = {

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
      35,   17,   12,   11, 0x08,
      71,   64,   11,   11, 0x08,
     110,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dialoggoto[] = {
    "dialoggoto\0\0bool\0spinPart,spinPage\0"
    "readXmlBook(QString,QString)\0button\0"
    "on_buttonBox_clicked(QAbstractButton*)\0"
    "updateValue()\0"
};

const QMetaObject dialoggoto::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialoggoto,
      qt_meta_data_dialoggoto, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialoggoto::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialoggoto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialoggoto::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialoggoto))
        return static_cast<void*>(const_cast< dialoggoto*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialoggoto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = readXmlBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: updateValue(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
