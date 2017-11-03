#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T10:40:00
#
#-------------------------------------------------

QT       += core gui widgets
TARGET    = BookMaker
TEMPLATE  = app
CONFIG   += c++11

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
    imagemodel.cpp \
    imagelist.cpp \
    imagelistcontroller.cpp \
    page.cpp \
    caption.cpp \
    captionlist.cpp \
    captionlistcontroller.cpp \
    pagelist.cpp \
    pagelistcontroller.cpp

HEADERS += \
        mainwindow.h \
    imagemodel.h \
    imagelist.h \
    imagelistcontroller.h \
    page.h \
    caption.h \
    captionlist.h \
    captionlistcontroller.h \
    pagelist.h \
    pagelistcontroller.h

FORMS += \
        mainwindow.ui

RESOURCES += \
        app_images.qrc
