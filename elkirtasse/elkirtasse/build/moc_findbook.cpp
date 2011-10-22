/****************************************************************************
** Meta object code from reading C++ file 'findbook.h'
**
** Created: Thu Oct 6 18:59:55 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/findbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_findbook[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   10,    9,    9, 0x0a,
      48,   40,    9,    9, 0x0a,
      68,   10,    9,    9, 0x0a,
     128,   95,    9,    9, 0x0a,
     216,  188,  183,    9, 0x0a,
     283,  259,    9,    9, 0x0a,
     334,  326,    9,    9, 0x0a,
     371,  326,  183,    9, 0x0a,
     408,    9,    9,    9, 0x08,
     423,    9,    9,    9, 0x08,
     433,    9,    9,    9, 0x08,
     452,    9,    9,    9, 0x08,
     469,  462,  183,    9, 0x08,
     498,  462,  183,    9, 0x08,
     542,  530,  183,    9, 0x08,
     634,  586,  183,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_findbook[] = {
    "findbook\0\0bookpath\0findOneBook(QString)\0"
    "inbooks\0findInAllBook(bool)\0"
    "findInAllFahariss(QString)\0"
    "view,bookpath,str1,str2,rowcount\0"
    "findFahariss(QTreeWidget*,QString,QRegExp,QRegExp,int)\0"
    "bool\0document,searchString,color\0"
    "searchInDoc(QTextDocument*,QString,QColor)\0"
    "view,searchString,colum\0"
    "searchInTreeview(QTreeWidget*,QString,int)\0"
    "view,fn\0loadResultFind(QTreeWidget*,QString)\0"
    "saveResultFind(QTreeWidget*,QString)\0"
    "readStrFirst()\0readXml()\0readStrMultiFind()\0"
    "readStr()\0search\0chargelistStrToFind(QString)\0"
    "chargelistStrMultiFind(QString)\0"
    "parent,view\0showAllItems(QTreeWidgetItem*,QTreeWidget*)\0"
    "searchString,parent,itemtop,topindex,view,colum\0"
    "searchTreeForString(QString,QTreeWidgetItem*,bool,int,QTreeWidget*,int"
    ")\0"
};

const QMetaObject findbook::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_findbook,
      qt_meta_data_findbook, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &findbook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *findbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *findbook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_findbook))
        return static_cast<void*>(const_cast< findbook*>(this));
    return QObject::qt_metacast(_clname);
}

int findbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: findOneBook((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: findInAllBook((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: findInAllFahariss((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: findFahariss((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QRegExp(*)>(_a[3])),(*reinterpret_cast< QRegExp(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: { bool _r = searchInDoc((*reinterpret_cast< QTextDocument*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: searchInTreeview((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: loadResultFind((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: { bool _r = saveResultFind((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: readStrFirst(); break;
        case 9: readXml(); break;
        case 10: readStrMultiFind(); break;
        case 11: readStr(); break;
        case 12: { bool _r = chargelistStrToFind((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = chargelistStrMultiFind((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = showAllItems((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidget*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = searchTreeForString((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QTreeWidget*(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
