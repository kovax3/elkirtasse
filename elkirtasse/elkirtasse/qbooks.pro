# ------------------------------------------------------------------------------
# Project created by QtCreator 2009-09-04T23:38:07
#-------------------------------------------------------------------------------
# 
#
#  All rights reserved.
#  Contact: abouzakaria (yahiaui@gmail.com)
# 
#  elkirtasse Copyright (C) 2010  yahia abouzakaria  <yahiaui@gmail.com>
#     This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
#     This is free software, and you are welcome to redistribute it
#     under certain conditions; type `show c' for details.
# 
# The hypothetical commands `show w' and `show c' should show the appropriate
# parts of the General Public License.  Of course, your program's commands
# might be different; for a GUI interface, you would use an "about box".
# 
#   You should also get your employer (if you work as a programmer) or school,
# if any, to sign a "copyright disclaimer" for the program, if necessary.
# For more information on this, and how to apply and follow the GNU GPL, see
# <http://www.gnu.org/licenses/>.
# 
#   The GNU General Public License does not permit incorporating your program
# into proprietary programs.  If your program is a subroutine library, you
# may consider it more useful to permit linking proprietary applications with
# the library.  If this is what you want to do, use the GNU Lesser General
# Public License instead of this License.  But first, please read
# <http://www.gnu.org/philosophy/why-not-lgpl.html>.
#----------------------------------------------------------
 




QT += xml
TARGET = elkirtasse
TEMPLATE = app
CONFIG += qt \
 release
 OBJECTS_DIR =  build
 MOC_DIR =  build
 UI_DIR =  build

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
    src/rowat.cpp
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
    src/rowat.h
FORMS += ui/mainwindow.ui \
    ui/dialogupdat.ui \
    ui/dialogfind.ui \
    ui/dialogfavo.ui \
    ui/dialogconvert.ui \
    ui/dialog.ui \
    ui/dialogoption.ui \
    ui/about.ui \
    ui/print.ui \
    ui/dialoggoto.ui
RESOURCES += images.qrc
win32 { 
    QT += sql
    SOURCES += src/dialogmdb.cpp
    HEADERS += src/dialogmdb.h
    FORMS += ui/dialogmdb.ui
    RC_FILE = src/myapp.rc
    debug:DESTDIR = debug/
    release:DESTDIR = release/
}
else { 
    SOURCES += src/mdbexport.cpp
    HEADERS += src/mdbexport.h
    FORMS += ui/mdbexport.ui

  MKDIR         = mkdir -p /usr/share/elkirtasse/data
 data.path=/usr/share/elkirtasse/
 data.files=usr/share/elkirtasse/data*

applications.path=/usr/share/applications
applications.files=usr/share/applications/elkirtasse.desktop

icon.path=/usr/share/icons/hicolor/scalable/apps
icon.files=usr/share/icons/hicolor/scalable/apps/elkirtasse.png

icon48.path=/usr/share/icons/hicolor/48x48/apps
icon48.files=usr/share/icons/hicolor/48x48/apps/elkirtasse.png


bin.path=/usr/bin
bin.files=-m 755 usr/bin/elkirtasse

 target.path =  /usr/share/elkirtasse

 INSTALLS += data \
            target \
            icon \
             icon48 \
            bin \
           applications
}


