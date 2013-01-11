#-------------------------------------------------
#
# Project created by QtCreator 2013-01-10T14:53:36
#
#-------------------------------------------------

TARGET   = table
TEMPLATE = lib
CONFIG  += qt warn_on staticlib

QT      += core gui

SOURCES += libtable.cpp

HEADERS += libtable.h \
           libtable_p.h

unix: {
        {
        target.path = /usr/lib
    }
    INSTALLS += target
}
