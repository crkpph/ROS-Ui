#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T14:48:03
#
#-------------------------------------------------


QT       += multimedia

QT       += multimediawidgets

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RosUiSDK
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    upload_commands.cpp \
    dialooog.cpp

HEADERS  += mainwindow.h \
    upload_commands.h \
    dialooog.h

FORMS    += mainwindow.ui \
    upload_commands.ui \
    dialooog.ui
