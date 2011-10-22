/****************************************************************************
** Meta object code from reading C++ file 'print.h'
**
** Created: Thu Oct 6 18:59:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/print.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'print.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Print[] = {

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
       7,    6,    6,    6, 0x08,
      38,   31,    6,    6, 0x08,
      82,    6,   77,    6, 0x08,
      93,    6,   77,    6, 0x08,
     104,    6,    6,    6, 0x08,
     137,  120,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Print[] = {
    "Print\0\0on_toolButton_clicked()\0button\0"
    "on_buttonBox_clicked(QAbstractButton*)\0"
    "bool\0openBook()\0fileSave()\0creatDocument()\0"
    "txt,part,page,id\0"
    "convertText(QString,QString,QString,int)\0"
};

const QMetaObject Print::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Print,
      qt_meta_data_Print, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Print::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Print::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Print::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Print))
        return static_cast<void*>(const_cast< Print*>(this));
    return QDialog::qt_metacast(_clname);
}

int Print::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_toolButton_clicked(); break;
        case 1: on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: { bool _r = openBook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: creatDocument(); break;
        case 5: convertText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
