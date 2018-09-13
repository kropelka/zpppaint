#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T15:12:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zppaint
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
    canvas.cpp \
    tool.cpp \
    toolbar.cpp \
    newfiledialog.cpp \
    pencil.cpp \
    brush.cpp \
    bresenham.cpp \
    mixerdialog.cpp \
    thresholddialoh.cpp \
    selectcolordialog.cpp \
    brightnessdialog.cpp \
    contrastdialog.cpp \
    gammadialog.cpp \
    fill.cpp \
    colorpicker.cpp \
    paste.cpp \
    clipcopy.cpp \
    line.cpp

HEADERS += \
        mainwindow.h \
    canvas.h \
    tool.h \
    toolbar.h \
    newfiledialog.h \
    pencil.h \
    brush.h \
    bresenham.h \
    mixerdialog.h \
    thresholddialoh.h \
    selectcolordialog.h \
    brightnessdialog.h \
    contrastdialog.h \
    gammadialog.h \
    fill.h \
    colorpicker.h \
    paste.h \
    clipcopy.h \
    line.h

FORMS += \
        mainwindow.ui \
    mixerdialog.ui \
    thresholddialoh.ui \
    selectcolordialog.ui \
    brightnessdialog.ui \
    contrastdialog.ui \
    gammadialog.ui

RESOURCES += \
    zppaint.qrc
