/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Oct 17 20:22:08 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      44,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     133,  131,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     308,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,
     369,   11,   11,   11, 0x08,
     403,  398,   11,   11, 0x08,
     441,   11,   11,   11, 0x08,
     455,   11,   11,   11, 0x08,
     476,   11,   11,   11, 0x08,
     502,  491,   11,   11, 0x08,
     540,  535,   11,   11, 0x08,
     558,   11,   11,   11, 0x08,
     580,   11,   11,   11, 0x08,
     596,   11,   11,   11, 0x08,
     615,   11,   11,   11, 0x08,
     632,   11,   11,   11, 0x08,
     664,  660,  652,   11, 0x08,
     685,   11,   11,   11, 0x08,
     709,  703,   11,   11, 0x08,
     746,  728,   11,   11, 0x08,
     788,   11,   11,   11, 0x08,
     804,   11,   11,   11, 0x08,
     823,   11,   11,   11, 0x08,
     834,   11,   11,   11, 0x08,
     849,   11,   11,   11, 0x08,
     891,  869,  864,   11, 0x08,
     927,  869,   11,   11, 0x08,
     960,   11,   11,   11, 0x08,
    1027,  979,  864,   11, 0x08,
    1111, 1099,  864,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionFullScreen_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_pushButtonFindNext_clicked()\0"
    "on_pushButtonFind_clicked()\0v\0"
    "on_actionFind_toggled(bool)\0"
    "on_actionOption_triggered()\0"
    "on_actionPrevKitab_triggered()\0"
    "on_actionNextKitab_triggered()\0"
    "on_actionStop_triggered()\0"
    "on_actionPlayPause_triggered()\0"
    "on_actionTreeList_toggled(bool)\0"
    "on_actionNextBab_triggered()\0"
    "on_actionPrevBab_triggered()\0item\0"
    "fahrasItemActivated(QTreeWidgetItem*)\0"
    "chargePages()\0treeChargeFahrassa()\0"
    "creatFahrasa()\0gridLayout\0"
    "creatCadre(QGraphicsGridLayout*)\0open\0"
    "animFahrasa(bool)\0animFahrasaFinished()\0"
    "animPagesLeft()\0setCurWidgetLeft()\0"
    "animPagesRight()\0setCurWidgetRight()\0"
    "QString\0txt\0convertText(QString)\0"
    "playCurentMedia()\0index\0setCurentPage(int)\0"
    "newstate,oldstate\0"
    "stateChanged(Phonon::State,Phonon::State)\0"
    "mediaFinished()\0openDialogFolder()\0"
    "openFont()\0loadSettings()\0saveSettings()\0"
    "bool\0document,searchString\0"
    "searchInDoc(QTextDocument*,QString)\0"
    "findNext(QTextDocument*,QString)\0"
    "searchInTreeview()\0"
    "searchString,parent,itemtop,topindex,view,colum\0"
    "searchTreeForString(QString,QTreeWidgetItem*,bool,int,QTreeWidget*,int"
    ")\0"
    "parent,view\0showAllItems(QTreeWidgetItem*,QTreeWidget*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionFullScreen_triggered(); break;
        case 1: on_actionAbout_triggered(); break;
        case 2: on_pushButtonFindNext_clicked(); break;
        case 3: on_pushButtonFind_clicked(); break;
        case 4: on_actionFind_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_actionOption_triggered(); break;
        case 6: on_actionPrevKitab_triggered(); break;
        case 7: on_actionNextKitab_triggered(); break;
        case 8: on_actionStop_triggered(); break;
        case 9: on_actionPlayPause_triggered(); break;
        case 10: on_actionTreeList_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: on_actionNextBab_triggered(); break;
        case 12: on_actionPrevBab_triggered(); break;
        case 13: fahrasItemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 14: chargePages(); break;
        case 15: treeChargeFahrassa(); break;
        case 16: creatFahrasa(); break;
        case 17: creatCadre((*reinterpret_cast< QGraphicsGridLayout*(*)>(_a[1]))); break;
        case 18: animFahrasa((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: animFahrasaFinished(); break;
        case 20: animPagesLeft(); break;
        case 21: setCurWidgetLeft(); break;
        case 22: animPagesRight(); break;
        case 23: setCurWidgetRight(); break;
        case 24: { QString _r = convertText((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: playCurentMedia(); break;
        case 26: setCurentPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 28: mediaFinished(); break;
        case 29: openDialogFolder(); break;
        case 30: openFont(); break;
        case 31: loadSettings(); break;
        case 32: saveSettings(); break;
        case 33: { bool _r = searchInDoc((*reinterpret_cast< QTextDocument*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 34: findNext((*reinterpret_cast< QTextDocument*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 35: searchInTreeview(); break;
        case 36: { bool _r = searchTreeForString((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QTreeWidget*(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 37: { bool _r = showAllItems((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidget*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 38;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
