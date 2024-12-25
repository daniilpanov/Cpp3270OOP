TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        configparser.cpp \
        currentfunction.cpp \
        tabulator.cpp \
        main.cpp

HEADERS += \
    abstractfunction.h \
    config.h \
    configparser.h \
    currentfunction.h \
    tabulator.h

DISTFILES += \
    main.qmodel
