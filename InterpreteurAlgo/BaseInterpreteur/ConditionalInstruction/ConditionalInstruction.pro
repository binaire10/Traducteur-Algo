include($$PWD/../../../BinaireLib/import.pri)

TARGET = ConditionalInstruction
TEMPLATE = lib
CONFIG -= app_bundle qt
CONFIG += staticlib

INCLUDEPATH += $$PWD/../ElementAlgorithmique
INCLUDEPATH += $$PWD/../MathExpression

unix {
    LIBS += -L$$shadowed($$PWD/../../BaseInterpreteur/ElementAlgorithmique) -lElementAlgorithmique
}


QMAKE_CXXFLAGS += -pedantic -Wwrite-strings -Weffc++  -std=c++14

unix:!macx{
    include(../../../linux.pri)
}

macx{
    include(../../../macosx.pri)
}

win32 {
    include(../../../win32.pri)
    CONFIG(debug, debug|release) {
        LIBS += -L$$shadowed($$PWD/../../BaseInterpreteur/ElementAlgorithmique)/debug -lElementAlgorithmique
    }else {
        LIBS += -L$$shadowed($$PWD/../../BaseInterpreteur/ElementAlgorithmique)/debug -lElementAlgorithmique
    }
}

HEADERS += \
    BaseLoop.h \
    BreakLoop.h \
    ConditionIf.h \
    continue.h \
    Declaration.h \
    DoWhileLoop.h \
    ExpressionToInstruction.h \
    Loop.h \
    LoopFor.h \
    RetourDeFonction.h \
    WhileLoop.h \
    multichoix.h

SOURCES += \
    BaseLoop.cpp \
    BreakLoop.cpp \
    ConditionIf.cpp \
    continue.cpp \
    Declaration.cpp \
    DoWhileLoop.cpp \
    ExpressionToInstruction.cpp \
    Loop.cpp \
    LoopFor.cpp \
    RetourDeFonction.cpp \
    WhileLoop.cpp \
    multichoix.cpp
