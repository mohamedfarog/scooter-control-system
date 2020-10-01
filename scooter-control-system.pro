#-------------------------------------------------
#
# Project created by QtCreator 2020-06-04T08:53:40
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scooter-control-system
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cardreader.cpp \
    application.cpp \
    database.cpp \
    modules/common/filemanager.cpp \
    modules/pin/pin-controllers/pcimx6ixoralinux.cpp \
    modules/pin/pin-controllers/pcrpi3linux.cpp \
    modules/pin/pin-controllers/pctk1ixoralinux.cpp \
    modules/pin/ipclinux.cpp \
    modules/pin/pinmanager.cpp \
    modules/pin/pinsystem.cpp

HEADERS += \
        mainwindow.h \
    cardreader.h \
    application.h \
    database.h \
    modules/common/filemanager.h \
    modules/common/globals.h \
    modules/pin/pin-controllers/pcimx6ixoralinux.h \
    modules/pin/pin-controllers/pcrpi3linux.h \
    modules/pin/pin-controllers/pctk1ixoralinux.h \
    modules/pin/idpins.h \
    modules/pin/ipclinux.h \
    modules/pin/ipincontroller.h \
    modules/pin/pinmanager.h \
    modules/pin/pinsystem.h

FORMS += \
  mainwindow.ui
