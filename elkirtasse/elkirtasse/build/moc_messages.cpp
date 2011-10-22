/****************************************************************************
** Meta object code from reading C++ file 'messages.h'
**
** Created: Thu Oct 6 18:59:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/messages.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_messages[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x0a,
      45,   10,    9,    9, 0x0a,
      86,   75,    9,    9, 0x0a,
     150,  126,    9,    9, 0x0a,
     202,  190,    9,    9, 0x0a,
     259,  243,  238,    9, 0x0a,
     292,   10,  238,    9, 0x0a,
     321,    9,    9,    9, 0x0a,
     369,  334,    9,    9, 0x0a,
     424,    9,    9,    9, 0x0a,
     439,    9,    9,    9, 0x0a,
     464,  452,  238,    9, 0x0a,
     503,  497,    9,    9, 0x0a,
     573,  527,  238,    9, 0x0a,
     647,  630,    9,    9, 0x0a,
     689,   10,    9,    9, 0x0a,
     717,   10,  238,    9, 0x0a,
     750,   10,  238,    9, 0x0a,
     779,   10,  238,    9, 0x0a,
     814,   10,  810,    9, 0x0a,
     868,  839,  238,    9, 0x0a,
     923,  914,  238,    9, 0x0a,
     965,  953,  945,    9, 0x0a,
    1006,  993,  238,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_messages[] = {
    "messages\0\0view\0treeChargeSoura(QTreeWidget*)\0"
    "treeChargeJozaa(QTreeWidget*)\0view,Bname\0"
    "treeChargeFahrass(QTreeWidget*,QString)\0"
    "view,checked,asCombobox\0"
    "treeChargeGroupe(QTreeWidget*,int,bool)\0"
    "view,remove\0treeUpdateGroupe(QTreeWidget*,bool)\0"
    "bool\0BKname,removall\0"
    "treeMenuRemoveBook(QString,bool)\0"
    "treeSaveGroupe(QTreeWidget*)\0recentLoad()\0"
    "Bname,Btitle,Baut,Bid,nbr,isTefsir\0"
    "recentChange(QString,QString,QString,QString,int,bool)\0"
    "recentCharge()\0recentSave()\0view,bkname\0"
    "fahrasSave(QTreeWidget*,QString)\0combo\0"
    "comboCharge(QComboBox*)\0"
    "bkpath,bktitle,bkauth,bkbetaka,groupid,cheked\0"
    "addNewBook(QString,QString,QString,QString,QString,bool)\0"
    "view,icong,iconf\0"
    "favorite_charge(QTreeWidget*,QIcon,QIcon)\0"
    "favorite_save(QTreeWidget*)\0"
    "treeviewItemRemove(QTreeWidget*)\0"
    "treeviewItemUp(QTreeWidget*)\0"
    "treeviewItemDown(QTreeWidget*)\0int\0"
    "genirateId(QTreeWidget*)\0"
    "bookname,title,author,betaka\0"
    "saveBookInfo(QString,QString,QString,QString)\0"
    "bookname\0loadBookInfo(QString)\0QString\0"
    "groupParent\0geniratNewBookName(QString)\0"
    "tit,data,lvl\0writeInDoc(QString,QString,QString)\0"
};

const QMetaObject messages::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_messages,
      qt_meta_data_messages, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &messages::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *messages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *messages::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_messages))
        return static_cast<void*>(const_cast< messages*>(this));
    return QObject::qt_metacast(_clname);
}

int messages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: treeChargeSoura((*reinterpret_cast< QTreeWidget*(*)>(_a[1]))); break;
        case 1: treeChargeJozaa((*reinterpret_cast< QTreeWidget*(*)>(_a[1]))); break;
        case 2: treeChargeFahrass((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: treeChargeGroupe((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: treeUpdateGroupe((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: { bool _r = treeMenuRemoveBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = treeSaveGroupe((*reinterpret_cast< QTreeWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: recentLoad(); break;
        case 8: recentChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 9: recentCharge(); break;
        case 10: recentSave(); break;
        case 11: { bool _r = fahrasSave((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: comboCharge((*reinterpret_cast< QComboBox*(*)>(_a[1]))); break;
        case 13: { bool _r = addNewBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: favorite_charge((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QIcon(*)>(_a[2])),(*reinterpret_cast< QIcon(*)>(_a[3]))); break;
        case 15: favorite_save((*reinterpret_cast< QTreeWidget*(*)>(_a[1]))); break;
        case 16: { bool _r = treeviewItemRemove((*reinterpret_cast< QTreeWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = treeviewItemUp((*reinterpret_cast< QTreeWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = treeviewItemDown((*reinterpret_cast< QTreeWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { int _r = genirateId((*reinterpret_cast< QTreeWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 20: { bool _r = saveBookInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 21: { bool _r = loadBookInfo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { QString _r = geniratNewBookName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: { bool _r = writeInDoc((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
