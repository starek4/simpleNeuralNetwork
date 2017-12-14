QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = momentum
MAKEFILE = momentum_makefile
TEMPLATE = app
CONFIG += c++11 release
RESOURCES = momentum.qrc

SOURCES += \
        momentum.cpp \
        mainwindow.cpp \
    network.cpp \
    neuron.cpp \
    random.cpp

HEADERS += \
        mainwindow.h \
    network.h \
    neuron.h \
    random.h \
    algorithms.h

FORMS += \
        mainwindow.ui
