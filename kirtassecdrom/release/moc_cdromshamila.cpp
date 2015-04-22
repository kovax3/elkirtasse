/****************************************************************************
** Meta object code from reading C++ file 'cdromshamila.h'
**
** Created: Thu 24. Jan 11:05:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cdromshamila.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cdromshamila.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cdromShamila[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   13,   14,   13, 0x0a,
      40,   13,   35,   13, 0x08,
      57,   13,   35,   13, 0x08,
      76,   13,   35,   13, 0x08,
      92,   13,   35,   13, 0x08,
     123,  111,   35,   13, 0x08,
     157,  154,   35,   13, 0x08,
     180,   13,   35,   13, 0x08,
     197,   13,   35,   13, 0x08,
     214,  154,   35,   13, 0x08,
     243,  236,   35,   13, 0x08,
     309,  270,   35,   13, 0x08,
     373,  361,   35,   13, 0x08,
     440,  411,   35,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_cdromShamila[] = {
    "cdromShamila\0\0QString\0execPlugin()\0"
    "bool\0creatShamellaX()\0creatShamellaWin()\0"
    "winCreatBooks()\0winCreatgroupXml()\0"
    "fn,bookname\0winWriteBooks(QString,QString)\0"
    "fn\0creatBashMain(QString)\0creatCatigorie()\0"
    "creatBooksInfo()\0creatBashMdb(QString)\0"
    "id,cat\0creatBook(QString,QString)\0"
    "bkpath,bktitle,bkauth,bkbetaka,groupid\0"
    "addNewBook(QString,QString,QString,QString,QString)\0"
    "f,table,csv\0creatXmlFile(QString,QString,QString)\0"
    "bookname,title,author,betaka\0"
    "saveBookInfo(QString,QString,QString,QString)\0"
};

void cdromShamila::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cdromShamila *_t = static_cast<cdromShamila *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->execPlugin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->creatShamellaX();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->creatShamellaWin();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->winCreatBooks();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->winCreatgroupXml();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->winWriteBooks((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->creatBashMain((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->creatCatigorie();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->creatBooksInfo();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->creatBashMdb((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->creatBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->addNewBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->creatXmlFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->saveBookInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData cdromShamila::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cdromShamila::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cdromShamila,
      qt_meta_data_cdromShamila, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cdromShamila::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cdromShamila::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cdromShamila::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cdromShamila))
        return static_cast<void*>(const_cast< cdromShamila*>(this));
    if (!strcmp(_clname, "ShamilaInterface"))
        return static_cast< ShamilaInterface*>(const_cast< cdromShamila*>(this));
    if (!strcmp(_clname, "com.trolltech.Plugin.ShamilaInterface/1.0"))
        return static_cast< ShamilaInterface*>(const_cast< cdromShamila*>(this));
    return QObject::qt_metacast(_clname);
}

int cdromShamila::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
