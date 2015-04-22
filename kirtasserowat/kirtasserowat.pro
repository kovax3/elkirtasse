TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../qbooks
TARGET = $$qtLibraryTarget(kirtasserowat)
DESTDIR = ../usr/share/elkirtasse/plugins
HEADERS += rowat.h
   QT += xml
SOURCES += rowat.cpp \
    
# install
MKDIR = mkdir -p /usr/share/elkirtasse/plugins


target.path = /usr/share/elkirtasse/plugins

INSTALLS += target
   

