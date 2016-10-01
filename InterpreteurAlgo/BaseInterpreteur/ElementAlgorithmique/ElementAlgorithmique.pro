include($$PWD/../../../BinaireLib/import.pri)

TARGET = ElementAlgorithmique
TEMPLATE = lib

CONFIG -= app_bundle qt
CONFIG += staticlib

QMAKE_CXXFLAGS += -pedantic -Wwrite-strings -Weffc++  -std=c++14

SOURCES += \
    Fonction.cpp \
    Instruction.cpp \
    InstructionBlock.cpp \
    MacroInstruction.cpp \
    struccore.cpp \
    typage.cpp \
    VariablePrototype.cpp \
    VariadicFunction.cpp \
    Expression.cpp \
    CoreExpression.cpp

unix:!macx{
    include(../../../linux.pri)
}

macx{
    include(../../../macosx.pri)
}

win32 {
    include(../../../win32.pri)
}

HEADERS += \
    Fonction.h \
    Instruction.h \
    InstructionBlock.h \
    MacroInstruction.h \
    struccore.h \
    VariablePrototype.h \
    VariadicFunction.h \
    Expression.h \
    CoreExpression.h
