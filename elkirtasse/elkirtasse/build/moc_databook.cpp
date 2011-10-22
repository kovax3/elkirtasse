/****************************************************************************
** Meta object code from reading C++ file 'databook.h'
**
** Created: Thu Oct 6 18:59:41 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/databook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_databook[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,    9,   10,    9, 0x0a,
      54,   29,   10,    9, 0x0a,
      93,   84,    9,    9, 0x0a,
     123,  113,   10,    9, 0x0a,
     173,  148,    9,    9, 0x0a,
     205,    9,   10,    9, 0x0a,
     220,  216,    9,    9, 0x0a,
     246,  235,    9,    9, 0x0a,
     300,  295,  287,    9, 0x08,
     320,    9,   10,    9, 0x08,
     340,  337,  333,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_databook[] = {
    "databook\0\0bool\0getIfTefsir()\0"
    "bookName,position,bkpath\0"
    "openBook(QString,int,QString)\0position\0"
    "moveToPosition(int)\0soura,aya\0"
    "findAya(QString,QString)\0"
    "oldText,newText,fullText\0"
    "updatPage(QString,QString,bool)\0"
    "saveBook()\0num\0claerBook(int)\0view,Bname\0"
    "treeOrganizFahrass(QTreeWidget*,QString)\0"
    "QString\0text\0noTechkile(QString)\0"
    "chargeList()\0int\0id\0getPositionID(QString)\0"
};

const QMetaObject databook::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_databook,
      qt_meta_data_databook, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &databook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *databook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *databook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_databook))
        return static_cast<void*>(const_cast< databook*>(this));
    return QObject::qt_metacast(_clname);
}

int databook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = getIfTefsir();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = openBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: moveToPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { bool _r = findAya((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: updatPage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: { bool _r = saveBook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: claerBook((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: treeOrganizFahrass((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: { QString _r = noTechkile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { bool _r = chargeList();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { int _r = getPositionID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
