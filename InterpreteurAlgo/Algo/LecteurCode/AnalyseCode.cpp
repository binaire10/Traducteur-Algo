#include "LecteurCode.h"
#include <algorithm>
#include <MyValidator/MyValidator.hpp>
#include <MyParse/SymboleParse.h>
#include <MyParse/LimitedSequenceParse.h>
#include "struccore.h"
#include "struccore.h"
#include "ExpressionToInstruction.h"
#include "GestionnaireInstruction.h"
#include "functioninstructionbuilder.h"
#include "LoopBuilder.h"
#include "conditionbuilder.h"
#include "ChoixSurBuilder.h"
#include "CAgloException.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;
using namespace InstructionAvance;

LecteurCode::LecteurCode() noexcept : m_InstructionGest(new GestionnaireInstruction)
{//Rand
    FonctionMacro *currentMacros;
    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("tolower");
    currentMacros->setToCpp("tolower(%0)");
    currentMacros->setType(VarType(false, false, 0u, typeid(char), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(char), 0u)
};
    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("Rand");
    currentMacros->setToCpp("(rand()%%((%1)-(%0))+%0)");
    currentMacros->setType(VarType(false, false, 0u, typeid(int64_t), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(int64_t), 0u),
            VarType(true, true, 0u, typeid(int64_t), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("toupper");
    currentMacros->setToCpp("toupper(%0)");
    currentMacros->setType(VarType(false, false, 0u, typeid(char), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(char), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("succ");
    currentMacros->setToCpp("(%0+1)");
    currentMacros->setType(VarType(false, false, 0u, typeid(char), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(char), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("rang");
    currentMacros->setToCpp("static_cast<unsigned>(%0)");
    currentMacros->setType(VarType(false, false, 0u, typeid(unsigned), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(char), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("pred");
    currentMacros->setToCpp("(%0-1)");
    currentMacros->setType(VarType(true, true, 0u, typeid(char), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(char), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("modulo");
    currentMacros->setToCpp("(%0%%%1)");
    currentMacros->setType(VarType(false, false, 0u, typeid(int64_t), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0u, typeid(int64_t), 0u),
            VarType(true, true, 0u, typeid(int64_t), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("taille");
    currentMacros->setToCpp("%0.size()");
    currentMacros->setType(VarType(false, false, 0u, typeid(unsigned), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0, typeid(std::string), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("taille");
    currentMacros->setToCpp("%0.size()");
    currentMacros->setType(VarType(false, false, 0u, typeid(unsigned), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, FonctionMacro::AnySize, typeid(FonctionMacro::AllType_t), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("allonger");
    currentMacros->setToCpp("%0.resize(%0.size() + %1)");
    currentMacros->setType(VarType(false, false, 0u, typeid(void), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, false, 0, typeid(std::string), 0u),
            VarType(true, true, 0u, typeid(unsigned), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("allonger");
    currentMacros->setToCpp("%0.resize(%0.size() + %1)");
    currentMacros->setType(VarType(false, false, 0u, typeid(void), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, false, FonctionMacro::AnySize, typeid(FonctionMacro::AllType_t), 0u),
            VarType(true, true, 0u, typeid(unsigned), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("redimensionner");
    currentMacros->setToCpp("%0.resize(%1)");
    currentMacros->setType(VarType(false, false, 0u, typeid(void), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, false, 0u, typeid(std::string), 0u),
            VarType(true, true, 0u, typeid(unsigned), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("redimensionner");
    currentMacros->setToCpp("%0.resize(%1)");
    currentMacros->setType(VarType(false, false, 0u, typeid(void), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, false, FonctionMacro::AnySize, typeid(FonctionMacro::AllType_t), 0u),
            VarType(true, true, 0u, typeid(unsigned), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacro);
    currentMacros->setName("saisir");
    currentMacros->setToCpp("std::cin >> %0");
    currentMacros->setType(VarType(false, false, 0u, typeid(void), 0u));
    currentMacros->TypeContraite() = {
            VarType(false, false, 0, typeid(FonctionMacro::AllType_t), 0u)
};

    m_Gestionaire.addMacro(currentMacros = new FonctionMacroVariadic);
    currentMacros->setName("afficher");
    currentMacros->setToCpp("std::cout%. << %/%#");
    currentMacros->setType(VarType(false, false, 0u, typeid(void), 0u));
    currentMacros->TypeContraite() = {
            VarType(true, true, 0, typeid(FonctionMacro::AllType_t), 0u)
};
    m_InstructionGest->addDecodeur(new LoopBuilder(this));
    m_InstructionGest->addDecodeur(new ConditionBuilder(this));
    m_InstructionGest->addDecodeur(new FunctionInstructionBuilder(this));
    m_InstructionGest->addDecodeur(new ChoixSurBuilder(this));
}

LecteurCode::~LecteurCode() noexcept
{
    for(Fonction *&i : m_fonctionList)
        delete i;
    delete m_InstructionGest;
}

void LecteurCode::readCode(std::list< std::pair<unsigned, StringRef> > &CodeLine)
{
    m_CodeLine = &CodeLine;
    WordParse Word(MyWord, MySymbole);
    StringParse StringSeq("\"", "\"", '\\'), CharSeq("'", "'", '\\');
    SymboleParse UniqWord(2);
    UniqWord.UniqSymbole().push_back("<-");
    UniqWord.UniqSymbole().push_back("<=");
    UniqWord.UniqSymbole().push_back(">=");
    UniqWord.UniqSymbole().push_back("//");
    UniqWord.UniqSymbole().push_back("/*");
    StringParse LineComment("//", "\n", '\0'), MultiLineComment("/*", "*/", '\0');
    LimitedSequenceParse ParenteseParse("(", ")"), CrochetParse("[", "]");

    LexicalParseur parseur({&Word, &UniqWord, &StringSeq, &CharSeq, &LineComment, &MultiLineComment, &ParenteseParse, &CrochetParse});
    ParenteseParse.SequenceurList() = {&Word, &UniqWord, &StringSeq, &CharSeq, &LineComment, &MultiLineComment, &ParenteseParse, &CrochetParse};
    CrochetParse.SequenceurList() = {&Word, &UniqWord, &StringSeq, &CharSeq, &LineComment, &MultiLineComment, &ParenteseParse, &CrochetParse};


    StringRef command;

    unsigned levelContext(0);

    //std::list<VariablePrototype *> &MasterContext = VariableContexte.back();

    for(m_i = CodeLine.cbegin() ; m_i != CodeLine.cend() ; ++m_i)
    {
        try
        {
            const StringRef &Value = m_i->second;
            parseur.setSource(Value);

            command = parseur.getCurrent();
            parseur.Next();

            if(LexicalParseur::SequenceParse::equal(command, "fonction"))
            {
                m_VariableContexte.push_back(std::list<VariablePrototype *>());
                ++levelContext;
                std::list<VariablePrototype *> &currentContext = m_VariableContexte.back();

                StringRef fonctionName(parseur.getCurrent());
                parseur.Next();

                std::list<VariablePrototype> arg;
                StringRef Arg(parseur.getCurrent());
                parseur.Next();


                if(std::distance(Arg.first, Arg.second) > 2 && *Arg.first == '(' && *(Arg.second-1) == ')')
                {
                    binaire::LexicalParseur subParseur(parseur);
                    subParseur.setSource(Arg.first + 1, Arg.second - 1);

                    while(!subParseur.LastWord())
                    {
                        const StringRef argumentName(subParseur.getCurrent());
                        subParseur.Next();
                        if(!WordParse::equal(subParseur.getCurrent(), ":"))
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));
                        subParseur.Next();

                        bool isInput;
                        static_cast<void>(isInput);
                        std::pair<std::string::const_iterator, std::string::const_iterator> type(subParseur.getCurrent());
                        subParseur.Next();

                        if(binaire::WordParse::equal(type, "in"))
                            isInput = false;
                        else if(binaire::WordParse::equal(type, "out"))
                            isInput = true;
                        else if(binaire::WordParse::equal(type, "in_out"))
                            isInput = true;
                        else
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));

                        type = subParseur.getCurrent();
                        subParseur.Next();
                        unsigned ArrayLevel(0);
                        while(binaire::WordParse::equal(type, "tableau_de"))
                        {
                            ++ArrayLevel;
                            type = subParseur.getCurrent();
                            subParseur.Next();
                        }


                        const std::string currentType = binaire::buildString(type);
                        auto val(m_localType.find(currentType));
                        if(val == m_localType.end())
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));

                        arg.push_back(VariablePrototype(buildString(argumentName), false, isInput, ArrayLevel, val->second, 0u));

                        if(!WordParse::equal(subParseur.getCurrent(), ",") && !subParseur.AtEnd())
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));
                        subParseur.Next();
                    }

                }

                if(findFonction(m_fonctionList, fonctionName, arg) == nullptr)
                {
                    m_fonctionList.push_back(new Fonction(buildString(fonctionName)));
                    m_fonctionList.back()->GetInput() = arg;
                }
                Fonction &NewFonction = *findFonction(m_fonctionList, fonctionName, arg);

                if(!binaire::WordParse::equal(parseur.getCurrent(), "renvoie"))
                    throw std::runtime_error("Unautorized declaration at " + std::to_string(m_i->first));
                parseur.Next();

                command = parseur.getCurrent();
                parseur.Next();

                while(binaire::WordParse::equal(command, "tableau_de"))
                {
                    NewFonction.GetOutput().setArrayLevel(NewFonction.GetOutput().getArrayLevel()+1);
                    command = parseur.getCurrent();
                    parseur.Next();
                }

                auto val(m_localType.find(buildString(command)));
                if(val == m_localType.end())
                    throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));
                NewFonction.GetOutput().setType_Index(val->second);

                if(*(command.second) != ';')
                {
                    for(VariablePrototype &a : NewFonction.GetInput())
                        currentContext.push_back(&a);

                    ++m_i;
                    if(m_i == m_CodeLine->cend())
                        throw std::runtime_error("Missing End Block");
                    analyseImplementation<OpenBlock, CloseBlock>(parseur, NewFonction.getImplementation(), &NewFonction, nullptr);
                }
                m_VariableContexte.pop_back();
                --levelContext;
            }
            else if(WordParse::equal(command, "procedure"))
            {
                m_VariableContexte.push_back(std::list<VariablePrototype *>());
                ++levelContext;
                std::list<VariablePrototype *> &currentContext = m_VariableContexte.back();

                StringRef procedureName(parseur.getCurrent());
                parseur.Next();
                std::list<VariablePrototype> arg;

                StringRef Arg(parseur.getCurrent());
                parseur.Next();

                if(std::distance(Arg.first, Arg.second) > 2 && *Arg.first == '(' && *(Arg.second-1) == ')')
                {
                    binaire::LexicalParseur subParseur(parseur);
                    subParseur.setSource(Arg.first + 1, Arg.second - 1);

                    while(!subParseur.LastWord())
                    {
                        const StringRef argumentName(subParseur.getCurrent());
                        subParseur.Next();
                        if(!WordParse::equal(subParseur.getCurrent(), ":"))
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));
                        subParseur.Next();

                        bool isInput;
                        static_cast<void>(isInput);
                        std::pair<std::string::const_iterator, std::string::const_iterator> type(subParseur.getCurrent());
                        subParseur.Next();

                        if(binaire::WordParse::equal(type, "in"))
                            isInput = false;
                        else if(binaire::WordParse::equal(type, "out"))
                            isInput = true;
                        else if(binaire::WordParse::equal(type, "in_out"))
                            isInput = true;
                        else
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));

                        type = subParseur.getCurrent();
                        subParseur.Next();
                        unsigned ArrayLevel(0);
                        while(binaire::WordParse::equal(type, "tableau_de"))
                        {
                            ++ArrayLevel;
                            type = subParseur.getCurrent();
                            subParseur.Next();
                        }


                        const std::string currentType = binaire::buildString(type);
                        auto val(m_localType.find(currentType));
                        if(val == m_localType.end())
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));

                        arg.push_back(VariablePrototype(buildString(argumentName), false, isInput, ArrayLevel, val->second, 0u));

                        if(!WordParse::equal(subParseur.getCurrent(), ",") && !subParseur.AtEnd())
                            throw std::runtime_error("Unautorized declaration  at " + std::to_string(m_i->first));
                        subParseur.Next();
                    }
                }
                if(findFonction(m_fonctionList, procedureName, arg) == nullptr)
                {
                    m_fonctionList.push_back(new Fonction(buildString(procedureName)));
                    m_fonctionList.back()->GetInput() = arg;
                }

                Fonction &NewProcedure = *findFonction(m_fonctionList, procedureName, arg);


                if(*(command.second) != ';')
                {
                    for(VariablePrototype &a : NewProcedure.GetInput())
                        currentContext.push_back(&a);
                    ++m_i;
                    if(m_i == m_CodeLine->cend())
                        throw std::runtime_error("Missing End Block");
                    analyseImplementation<OpenBlock, CloseBlock>(parseur, NewProcedure.getImplementation(), &NewProcedure, nullptr);
                }
                m_VariableContexte.pop_back();
                --levelContext;
            }
            else if(LexicalParseur::SequenceParse::equal(command, "algorithme"))
            {
                m_VariableContexte.push_back(std::list<VariablePrototype *>());
                StringRef algorithmeName(parseur.getCurrent());
                m_Program.push_back({buildString(algorithmeName), SmartPtr<InstructionBlock>(new InstructionBlock)});
                mainInfo &currentProgram = m_Program.back();

                if(*(command.second) != ';')
                {
                    ++m_i;
                    if(m_i == m_CodeLine->cend())
                        throw std::runtime_error("Missing End Block");
                    analyseImplementation<OpenBlock, CloseBlock>(parseur, currentProgram.getImplementation(), nullptr, nullptr);
                }
                /// impl
            }
            else if(WordParse::equal(command, "//"))
                continue;
            else
                throw std::runtime_error("Section non reconue");
        }
        catch(const std::runtime_error &error)
        {
            cout << "Error \"" << error.what() << "\" at line '" << buildString(m_i->second) << "' "  << m_i->first << endl;
            for(Fonction * const &i : m_fonctionList)
                delete i;
            m_fonctionList.clear();
            m_CodeLine = nullptr;
            throw CAgloException(m_i->first, string(error.what()));
        }
        catch(const std::exception &e)
        {
            cout << "Error when reading line '" << buildString(m_i->second) << "' " << m_i->first << " -> " << e.what() << endl;
            for(Fonction * const &i : m_fonctionList)
                delete i;
            m_fonctionList.clear();
            m_CodeLine = nullptr;
            throw CAgloException(m_i->first, string(e.what()));
        }
        catch(...)
        {
            cout << "Error at line " << m_i->first << endl;
            for(Fonction * const &i : m_fonctionList)
                delete i;
            m_fonctionList.clear();
            m_CodeLine = nullptr;
            throw;
        }
    }
    m_CodeLine = nullptr;

}

void LecteurCode::ToCppCode(ostream &os)
{
    os << "#include <iostream>\n#include <string>\n#include <cstdlib>\n#include <vector>\n"
          "#include <ctime>\n\n"
          "#ifnde int64_t\ntypedef long long int int64_t;\n#endif\n\n;

    for(Fonction *&i : m_fonctionList)
    {
        os << (i->GetOutput().getIsConst() ? "const " : "") << unRollArray(findKey(cppType.begin(), cppType.end(), i->GetOutput().getType())->first, i->GetOutput().getArrayLevel()) << " " << i->GetName() << "(";
        unsigned rest(i->GetInput().size());
        for(VariablePrototype &v: i->GetInput())
        {
            os << (v.getVarTypeStructure().getIsConst() ? "const " : "") << unRollArray(findKey(cppType.begin(), cppType.end(), v.getVarTypeStructure().getType())->first, v.getVarTypeStructure().getArrayLevel()) << ' ' << (v.getVarTypeStructure().getIsRefVar() ? "&" : "") << v.getName();
            --rest;
            if(rest != 0)
            {
                os << ", ";
            }
        }
        os << ");\n";
    }
    os << '\n';

    for(Fonction *&i : m_fonctionList)
    {
        os << (i->GetOutput().getIsConst() ? "const " : "") << unRollArray(findKey(cppType.begin(), cppType.end(), i->GetOutput().getType())->first, i->GetOutput().getArrayLevel()) << " " << i->GetName() << "(";
        unsigned rest(i->GetInput().size());
        for(VariablePrototype &v: i->GetInput())
        {
            os << (v.getVarTypeStructure().getIsConst() ? "const " : "") << unRollArray(findKey(cppType.begin(), cppType.end(), v.getVarTypeStructure().getType())->first, v.getVarTypeStructure().getArrayLevel()) << ' ' << (v.getVarTypeStructure().getIsRefVar() ? "&" : "") << v.getName();
            --rest;
            if(rest != 0)
            {
                os << ", ";
            }
        }
        os << ")\n";
        os << "{\n";
        i->getImplementation()->ToCppCode(os);
        os << "}\n\n";
    }

    for(mainInfo &i : m_Program)
    {
        os << "int main() // Algo : " << i.Name << "\n{\n" << string(4,' ') << "srand(time(nullptr));\n";
        i.Implementation->ToCppCode(os);
        os << "}\n";
    }
}

void LecteurCode::execute()
{
}

void LecteurCode::InstructionDecodeur(LexicalParseur &GlobalParseur, SmartPtr<InstructionBlock> &impl, StringRef InstructionName, Fonction *currentFonc, BaseLoop *currentLoop)
{
    GlobalParseur.Next();

    if(m_InstructionGest->findDecodeur(InstructionName))
        m_InstructionGest->getDecodeur(InstructionName)->buildInstructionFromAlgo(InstructionName, GlobalParseur, impl, currentFonc, currentLoop);
    else if(findFonction(m_fonctionList, InstructionName) || m_Gestionaire.existMacro(InstructionName) || findVar(m_VariableContexte, InstructionName))
    {
        GlobalParseur.setSource(m_i->second);
        impl->getInstructionList().push_back(make_SmartPtr(new ExpressionToInstruction(analyserOperation(GlobalParseur))));
        if(!WordParse::equal(GlobalParseur.getCurrent(), ";") || !GlobalParseur.LastWord())
            throw runtime_error(u8"Expression non terminé");
    }
    else if(WordParse::equal(InstructionName, "//"));
    else if(WordParse::isInsideStr1At(InstructionName, "//") || InstructionName.first == InstructionName.second);
    else
        throw std::runtime_error("Instructruction Inconue");
}

const std::list<std::list<VariablePrototype *> > &LecteurCode::VariableContexte() const
{
    return m_VariableContexte;
}


void LecteurCode::InstructionGenerator::NextLine()
{
    ++m_Instance->m_i;
    if(m_Instance->m_i == m_Instance->m_CodeLine->cend())
        throw std::runtime_error("Lecteur Hors du Code");
}

const std::pair<unsigned, StringRef> &LecteurCode::InstructionGenerator::GetLine()
{
    return *m_Instance->m_i;
}

std::list<std::list<VariablePrototype *> > &LecteurCode::InstructionGenerator::getVariableEnv()
{
    return m_Instance->m_VariableContexte;
}

std::unordered_map<string, type_index> &LecteurCode::InstructionGenerator::getTypeArray()
{
    return m_Instance->m_localType;
}


void LecteurCode::setCodeLine(std::list<std::pair<unsigned, StringRef> > *CodeLine)
{
    m_CodeLine = CodeLine;
    m_i = CodeLine->begin();
}
