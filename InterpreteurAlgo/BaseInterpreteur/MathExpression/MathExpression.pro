include($$PWD/../../../BinaireLib/import.pri)

TARGET = MathExpression
TEMPLATE = lib
CONFIG -= app_bundle qt
CONFIG += staticlib

INCLUDEPATH += $$PWD/../ElementAlgorithmique

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
    Affectation.h \
    ArrayAcess.h \
    CValue.h \
    CVariable.h \
    Division.h \
    Equal.h \
    EtBinaire.h \
    EtLogique.h \
    FonctionCall.h \
    ForceExpression.h \
    LessThan.h \
    Multiplication.h \
    NegationBool.h \
    NotEqual.h \
    OuBinaire.h \
    OuLogique.h \
    Soustract.h \
    Sum.h

SOURCES += \
    Affectation.cpp \
    ArrayAcess.cpp \
    CVariable.cpp \
    Division.cpp \
    Equal.cpp \
    EtBinaire.cpp \
    EtLogique.cpp \
    FonctionCall.cpp \
    ForceExpression.cpp \
    LessThan.cpp \
    Multiplication.cpp \
    NegationBool.cpp \
    NotEqual.cpp \
    OuBinaire.cpp \
    OuLogique.cpp \
    Soustract.cpp \
    Sum.cpp
