#-------------------------------------------------
#
# Project created by QtCreator 2014-05-19T12:43:51
#
#-------------------------------------------------

QT       += core gui opengl network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    smartphone.cpp \
    thread.cpp \
    thread1.cpp \
    ip.cpp \
    sobre.cpp


HEADERS  += mainwindow.h \
    smartphone.h \
    thread.h \
    thread1.h \
    ip.h \
    sobre.h

FORMS    += mainwindow.ui \
    ip.ui \
    sobre.ui

OTHER_FILES +=
