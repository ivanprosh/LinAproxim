#-------------------------------------------------
#
# Project created by QtCreator 2016-06-08T18:51:11
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Program
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    approximator.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    approximator.h

FORMS    += mainwindow.ui

DISTFILES += \
    resources.rc
