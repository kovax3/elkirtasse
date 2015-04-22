/****************************************************************************
** Meta object code from reading C++ file 'dialognet.h'
**
** Created: Thu 24. Jan 11:05:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialognet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialognet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialognet[] = {

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
      33,   16,   11,   10, 0x0a,
      63,   10,   10,   10, 0x08,
     122,   98,   10,   10, 0x08,
     213,  165,   11,   10, 0x08,
     297,  285,   11,   10, 0x08,
     341,   10,   10,   10, 0x08,
     378,   10,   10,   10, 0x08,
     402,   10,   10,   10, 0x08,
     426,   10,   10,   10, 0x08,
     459,  443,   10,   10, 0x08,
     510,  489,   10,   10, 0x08,
     557,  542,   10,   10, 0x08,
     602,  597,   11,   10, 0x08,
     638,  631,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialognet[] = {
    "Dialognet\0\0bool\0urlPath,distPath\0"
    "downloadFile(QString,QString)\0"
    "on_lineEdit_2_textChanged(QString)\0"
    "view,searchString,colum\0"
    "searchInTreeview(QTreeWidget*,QString,int)\0"
    "searchString,parent,itemtop,topindex,view,colum\0"
    "searchTreeForString(QString,QTreeWidgetItem*,bool,int,QTreeWidget*,int"
    ")\0"
    "parent,view\0showAllItems(QTreeWidgetItem*,QTreeWidget*)\0"
    "on_treeWidget_itemSelectionChanged()\0"
    "on_buttonBox_accepted()\0on_toolButton_clicked()\0"
    "cancelDownload()\0requestId,error\0"
    "httpRequestFinished(int,bool)\0"
    "bytesRead,totalBytes\0"
    "updateDataReadProgress(int,int)\0"
    "responseHeader\0readResponseHeader(QHttpResponseHeader)\0"
    "view\0treeSaveGroupe(QTreeWidget*)\0"
    "errors\0sslErrors(QList<QSslError>)\0"
};

void Dialognet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialognet *_t = static_cast<Dialognet *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->downloadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->on_lineEdit_2_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->searchInTreeview((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: { bool _r = _t->searchTreeForString((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QTreeWidget*(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->showAllItems((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidget*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->on_treeWidget_itemSelectionChanged(); break;
        case 6: _t->on_buttonBox_accepted(); break;
        case 7: _t->on_toolButton_clicked(); break;
        case 8: _t->cancelDownload(); break;
        case 9: _t->httpRequestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->updateDataReadProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->readResponseHeader((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 12: { bool _r = _t->treeSaveGroupe((*reinterpret_cast< QTreeWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialognet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialognet::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialognet,
      qt_meta_data_Dialognet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialognet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialognet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialognet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialognet))
        return static_cast<void*>(const_cast< Dialognet*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialognet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
