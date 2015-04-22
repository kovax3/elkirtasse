TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../qbooks
TARGET = $$qtLibraryTarget(kirtassenet)
DESTDIR = ../usr/share/elkirtasse/plugins
HEADERS += networkplugin.h \
    dialognet.h
SOURCES += networkplugin.cpp \
    dialognet.cpp
QT += xml \
    network
FORMS += dialognet.ui
# install
KDIR = mkdir -p /usr/share/elkirtasse/plugins
target.path = /usr/share/elkirtasse/plugins
INSTALLS += target
