#-------------------------------------------------
#
# Project created by QtCreator 2014-03-31T13:15:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_fibonacci
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    field.cpp

HEADERS  += mainwindow.h \
    cell.h \
    field.h

FORMS    += mainwindow.ui
