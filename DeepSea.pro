TEMPLATE = app
CONFIG += console c++11
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    geometrystrutctures.cpp \
    trinagulatordelaunaygreedy.cpp

HEADERS += \
    geometrystrutctures.h \
    triangulatorinterface.h \
    trinagulatordelaunaygreedy.h
