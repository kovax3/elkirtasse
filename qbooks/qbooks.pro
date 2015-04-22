# -------------------------------------------------
# Project created by QtCreator 2009-09-04T23:38:07
# -------------------------------------------------
QT += xml
TEMPLATE = app
CONFIG += qt \
    release
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
INCLUDEPATH += build
<<<<<<< HEAD


win32 {
    QT += sql
    SOURCES += src/dialogmdb.cpp
    HEADERS += src/dialogmdb.h
    FORMS += ui/dialogmdb.ui
    RC_FILE = src/myapp.rc
    DESTDIR = ../usr/bin
    TARGET = elkirtasse
}
else {
    SOURCES += src/mdbexport.cpp
    HEADERS += src/mdbexport.h
    FORMS += ui/mdbexport.ui
    TARGET = ../usr/bin/elkirtasse


}

=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/dialogupdat.cpp \
    src/dialogfind.cpp \
    src/dialogfavo.cpp \
    src/dialogconvert.cpp \
    src/dialog.cpp \
    src/dialogoption.cpp \
    src/messages.cpp \
    src/databook.cpp \
    src/classwizard.cpp \
    src/about.cpp \
    src/print.cpp \
    src/animation.cpp \
    src/dialoggoto.cpp \
    src/findbook.cpp \
    src/dialogconfigbooks.cpp \
    src/dialogimportdvd.cpp\
<<<<<<< HEAD
    src/classepub.cpp \
    src/toolrubon.cpp \
    src/dialogactions.cpp
=======
src/classepub.cpp
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

HEADERS += src/mainwindow.h \
    src/dialogupdat.h \
    src/dialogfind.h \
    src/dialogfavo.h \
    src/dialogconvert.h \
    src/dialog.h \
    src/dialogoption.h \
    src/messages.h \
    src/databook.h \
    src/classwizard.h \
    src/about.h \
    src/print.h \
    src/animation.h \
    src/dialoggoto.h \
    src/findbook.h \
    src/booksInterface.h \
    src/booksInterface.h \
    src/dialogconfigbooks.h \
    src/dialogimportdvd.h\
<<<<<<< HEAD
    src/classepub.h \
    src/toolrubon.h \
    src/dialogactions.h
=======
src/classepub.h
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
FORMS += ui/mainwindow.ui \
    ui/dialogupdat.ui \
    ui/dialogfind.ui \
    ui/dialogfavo.ui \
    ui/dialogconvert.ui \
    ui/dialog.ui \
    ui/dialogoption.ui \
    ui/about.ui \
    ui/print.ui \
    ui/dialoggoto.ui \
    ui/dialogconfigbooks.ui \
<<<<<<< HEAD
    ui/dialogimportdvd.ui \
    ui/dialogactions.ui
RESOURCES += ui/images.qrc



   # install
    MKDIR = mkdir -p /usr/share/elkirtasse


    target.path = /usr/bin/
    INSTALLS += target
#  INSTALLS += data \







=======
    ui/dialogimportdvd.ui
RESOURCES += ui/images.qrc

win32 { 
    QT += sql
    SOURCES += src/dialogmdb.cpp
    HEADERS += src/dialogmdb.h
    FORMS += ui/dialogmdb.ui
    RC_FILE = src/myapp.rc
    debug:DESTDIR = ../debug/
    release:DESTDIR = ../release/
    TARGET = ../elkirtasse
}
else { 
    SOURCES += src/mdbexport.cpp
    HEADERS += src/mdbexport.h
    FORMS += ui/mdbexport.ui
    TARGET = ../usr/bin/elkirtasse
   # install
    MKDIR = mkdir -p /usr/share/elkirtasse
   

    target.path = /usr/bin/
    INSTALLS += target

       
}
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e






