TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../qbooks
TARGET = $$qtLibraryTarget(kirtassecdrom)
DESTDIR = ../usr/share/elkirtasse/plugins
HEADERS += \ 
    cdromshamila.h \
    dialogcdrom.h
<<<<<<< HEAD
     QT += xml sql
=======
   QT += xml
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
SOURCES += \ 
    cdromshamila.cpp \
    dialogcdrom.cpp
FORMS += \
    Dialogcdrom.ui
    
# install
MKDIR = mkdir -p /usr/share/elkirtasse/plugins
target.path = /usr/share/elkirtasse/plugins

INSTALLS += target 
   














