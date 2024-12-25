TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        function.cpp \
        main.cpp \
        reader.cpp \
        tabulator.cpp

HEADERS += \
    config.h \
    function.h \
    reader.h \
    tabulator.h
