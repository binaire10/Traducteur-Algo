INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/conditionbuilder.h \
    $$PWD/functioninstructionbuilder.h \
    $$PWD/GestionnaireInstruction.h \
    $$PWD/LecteurCode.h \
    $$PWD/LoopBuilder.h \
    $$PWD/gestionairemacrocode.h \
    $$PWD/ChoixSurBuilder.h \
    $$PWD/CAgloException.h

SOURCES += \
    $$PWD/LecteurCode/AnalyseCode.cpp \
    $$PWD/LecteurCode/AnalyseMath.cpp \
    $$PWD/LecteurCode/FonctionDelimiteur.cpp \
    $$PWD/GestionnaireInstruction.cpp \
    $$PWD/LoopBuilder.cpp \
    $$PWD/GestionaireMacroCode.cpp \
    $$PWD/FunctionInstructionBuilder.cpp \
    $$PWD/ConditionBuilder.cpp \
    $$PWD/ChoixSurBuilder.cpp \
    $$PWD/CAgloException.cpp
