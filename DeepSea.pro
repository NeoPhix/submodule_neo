TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    geometrystrutctures.cpp \
    trinagulatordelaunaygreedy.cpp

HEADERS += \
    geometrystrutctures.h \
    triangulatorinterface.h \
    trinagulatordelaunaygreedy.h
