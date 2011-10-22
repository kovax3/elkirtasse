/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created: Thu Oct 6 18:59:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      43,    7,    7,    7, 0x08,
      75,    7,    7,    7, 0x08,
     105,   99,    7,    7, 0x08,
     153,    7,  148,    7, 0x08,
     170,  165,  148,    7, 0x08,
     196,  188,    7,    7, 0x08,
     228,  220,  148,    7, 0x08,
     253,  165,    7,    7, 0x08,
     275,  165,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dialog[] = {
    "Dialog\0\0on_toolButton_zipFileNam_clicked()\0"
    "on_toolButton_fileNam_clicked()\0"
    "on_buttonBox_accepted()\0index\0"
    "on_comboBox_group_currentIndexChanged(int)\0"
    "bool\0creat_dir()\0path\0uzipBook(QString)\0"
    "dirName\0removeTempDirs(QString)\0tempDir\0"
    "removeTempFiles(QString)\0loadBookInfo(QString)\0"
    "loadTarGz(QString)\0"
};

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog,
      qt_meta_data_Dialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_toolButton_zipFileNam_clicked(); break;
        case 1: on_toolButton_fileNam_clicked(); break;
        case 2: on_buttonBox_accepted(); break;
        case 3: on_comboBox_group_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { bool _r = creat_dir();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = uzipBook((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: removeTempDirs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { bool _r = removeTempFiles((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: loadBookInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: loadTarGz((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
