/****************************************************************************
** Meta object code from reading C++ file 'dialogoption.h'
**
** Created: Thu Oct 6 18:59:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogoption.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialogoption[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x08,
      64,   13,   13,   13, 0x08,
      90,   13,   13,   13, 0x08,
     116,   13,   13,   13, 0x08,
     150,   13,   13,   13, 0x08,
     174,   13,   13,   13, 0x08,
     198,   13,   13,   13, 0x08,
     232,   13,   13,   13, 0x08,
     266,   13,   13,   13, 0x08,
     302,   13,   13,   13, 0x08,
     337,   13,   13,   13, 0x08,
     371,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dialogoption[] = {
    "Dialogoption\0\0img\0"
    "on_comboBoxCadre_currentIndexChanged(QString)\0"
    "on_toolButton_3_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_costmPath_clicked()\0"
    "on_buttonBox_accepted()\0on_toolButton_clicked()\0"
    "on_pushButton_backcolor_clicked()\0"
    "on_pushButton_findcolor_clicked()\0"
    "on_pushButton_prefercolor_clicked()\0"
    "on_pushButton_titlecolor_clicked()\0"
    "on_pushButton_fontcolor_clicked()\0"
    "recharge()\0"
};

const QMetaObject Dialogoption::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialogoption,
      qt_meta_data_Dialogoption, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialogoption::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialogoption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialogoption::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialogoption))
        return static_cast<void*>(const_cast< Dialogoption*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialogoption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_comboBoxCadre_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_toolButton_3_clicked(); break;
        case 2: on_toolButton_2_clicked(); break;
        case 3: on_toolButton_costmPath_clicked(); break;
        case 4: on_buttonBox_accepted(); break;
        case 5: on_toolButton_clicked(); break;
        case 6: on_pushButton_backcolor_clicked(); break;
        case 7: on_pushButton_findcolor_clicked(); break;
        case 8: on_pushButton_prefercolor_clicked(); break;
        case 9: on_pushButton_titlecolor_clicked(); break;
        case 10: on_pushButton_fontcolor_clicked(); break;
        case 11: recharge(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
