include($$PWD/../../../BinaireLib/import.pri)

TARGET = InstructionAvancee
TEMPLATE = lib
CONFIG -= app_bundle qt
CONFIG += staticlib

INCLUDEPATH += $$PWD/../ElementAlgorithmique

LIBS += -lElementAlgorithmique #-lMathExpression -lConditionalInstruction


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

unix {
    LIBS += -L$$shadowed($$PWD/../../BaseInterpreteur/ElementAlgorithmique) -lElementAlgorithmique
}


HEADERS += \
    CustomFonction.h \
    fonctionmacro.h

SOURCES += \
    CustomFonction.cpp \
    fonctionmacro.cpp
