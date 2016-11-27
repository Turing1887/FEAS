#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T10:59:23
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FEAS
TEMPLATE = app

win32{
INCLUDEPATH += C:\dlib-19.2
LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
}

SOURCES += main.cpp\
        mainwindow.cpp \
    D:/Dlib/dlib-19.2/dlib/all/source.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include(../opencv/videoengine.pri)
