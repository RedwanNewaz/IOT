#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T14:44:52
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextServerReader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    downloader.cpp

HEADERS  += mainwindow.h \
    downloader.h

FORMS    += mainwindow.ui
