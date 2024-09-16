#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T13:42:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hangman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hangman.cpp

HEADERS  += mainwindow.h \
    hangman.h

FORMS    += mainwindow.ui

RESOURCES += \
    hangmanimages.qrc

DISTFILES += \
    hangmanWords
