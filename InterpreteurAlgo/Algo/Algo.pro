include($$PWD/../../../BinaireLib/import.pri)
TARGET = Algo
TEMPLATE = lib
CONFIG -= app_bundle qt
CONFIG += staticlib

INCLUDEPATH += $$PWD/../../BaseInterpreteur/ElementAlgorithmique
INCLUDEPATH += $$PWD/../../BaseInterpreteur/MathExpression
INCLUDEPATH += $$PWD/../../BaseInterpreteur/ConditionalInstruction
INCLUDEPATH += $$PWD/../../BaseInterpreteur/InstructionAvancee

LIBS += -lElementAlgorithmique -lMathExpression -lConditionalInstruction -lInstructionAvancee


QMAKE_CXXFLAGS += -pedantic -Wwrite-strings -Weffc++  -std=c++14

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
    conditionbuilder.h \
    functioninstructionbuilder.h \
    GestionnaireInstruction.h \
    LecteurCode.h \
    LoopBuilder.h \
    gestionairemacrocode.h \
    choixsur.h

SOURCES += \
    LecteurCode/AnalyseCode.cpp \
    LecteurCode/AnalyseMath.cpp \
    LecteurCode/FonctionDelimiteur.cpp \
    conditionbuilder.cpp \
    functioninstructionbuilder.cpp \
    GestionnaireInstruction.cpp \
    loopbuilder.cpp \
    gestionairemacrocode.cpp \
    choixsur.cpp
