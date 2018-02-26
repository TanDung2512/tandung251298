#-------------------------------------------------
#
# Project created by QtCreator 2017-08-08T12:04:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = conmeno
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
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
    register.cpp \
    registeruser.cpp \
    registeraccount.cpp \
    info.cpp \
    blirariancofirm.cpp \
    adminc.cpp \
    changebook.cpp \
    addbook.cpp

HEADERS += \
        mainwindow.h \
    register.h \
    registeruser.h \
    registeraccount.h \
    info.h \
    blirariancofirm.h \
    adminc.h \
    changebook.h \
    addbook.h

FORMS += \
        mainwindow.ui \
    register.ui \
    registeruser.ui \
    registeraccount.ui \
    info.ui \
    blirariancofirm.ui \
    adminc.ui \
    changebook.ui \
    addbook.ui

DISTFILES +=

RESOURCES += \
    resoure.qrc