TEMPLATE = app
#CONFIG -= app_bundle
#CONFIG -= qt

QT += widgets
LIBS += -static-libstdc++

SOURCES += main.cpp \
    mainwindow.cpp \
    highlighter.cpp \
    editor.cpp \
    outputedit.cpp

include($$PWD/../InterpreteurAlgo/BaseInterpreteur/ElementAlgorithmique/ElementAlgorithmique.pri)
include($$PWD/../InterpreteurAlgo/BaseInterpreteur/MathExpression/MathExpression.pri)
include($$PWD/../InterpreteurAlgo/BaseInterpreteur/ConditionalInstruction/ConditionalInstruction.pri)
include($$PWD/../InterpreteurAlgo/BaseInterpreteur/InstructionAvancee/InstructionAvancee.pri)
include($$PWD/../InterpreteurAlgo/Algo/Algo.pri)

QMAKE_CXXFLAGS += -pedantic -Wwrite-strings -std=c++14 #-Weffc++

unix:!macx{
    include(../linux.pri)
}

macx{
    include(../macosx.pri)
}

win32{
    include(../win32.pri)
}

include($$PWD/../BinaireLib/import.pri)

HEADERS += \
    algo.h \
    mainwindow.h \
    highlighter.h \
    editor.h \
    outputedit.h

FORMS += \
    mainwindow.ui \
    setup.ui
