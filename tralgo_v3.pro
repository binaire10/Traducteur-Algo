SOURCES += \
    main.cpp

HEADERS += \
    Function.h

DEFINES += undefined=0

include($$PWD/interface/interface.pri)
include($$PWD/type/type.pri)
include($$PWD/instruction/instruction.pri)
include($$PWD/expression/expression.pri)
include($$PWD/operation/operation.pri)
CONFIG -= qt
CONFIG += console

LIBS += -static
