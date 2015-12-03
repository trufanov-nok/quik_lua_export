#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T22:20:24
#
#-------------------------------------------------

QT       -= core gui
CONFIG -= console app_bundle
QMAKE_LFLAGS += -static # to remove libgcc_s_dw2-1.dll dependance in case mingw is used

TARGET = quik_lua_export
TEMPLATE = lib

LIBS += -llua5.1 -L"c:/Program Files (x86)/Lua/5.1/lib"

INCLUDEPATH += "c:/Program Files (x86)/Lua/5.1/include/" "c:/Qt/Qt5.5.1/Tools/mingw492_32/i686-w64-mingw32/include/c++/"
SOURCES += \
    quik_lua_export.cpp

HEADERS += quik_lua_export.h

#include(Copy2Lib.pri)


