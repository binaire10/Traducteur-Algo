#include "functioninstructionbuilder.h"
#include <MyValidator/MyValidator.hpp>
#include "MacroInstruction.h"
#include "RetourDeFonction.h"
#include "Declaration.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace InstructionAvance;

FunctionInstructionBuilder::FunctionInstructionBuilder(LecteurCode *code) : InstructionGenerator(code)
{}


bool FunctionInstructionBuilder::valideInstruction(const StringRef &InstructionName) const noexcept
{
    return WordParse::equal(InstructionName, "renvoie") || WordParse::equal(InstructionName, "ligne_suivante") || WordParse::equal(InstructionName, "declarer");
}

void FunctionInstructionBuilder::buildInstructionFromAlgo(const StringRef &InstructionName, LexicalParseur &GlobalParseur, SmartPtr<InstructionBlock> &impl, Fonction *currentFonc, BaseLoop *currentLoop)
{
    static_cast<void>(currentLoop);
    StringRef buffer;
    if(WordParse::equal(InstructionName, "ligne_suivante"))
    {
        MacroInstruction *macroInstruction;
        impl->getInstructionList().push_back(make_SmartPtr(macroInstruction = new MacroInstruction));
        macroInstruction->setCppCode("std::cout << std::endl");
    }
    else if(WordParse::equal(InstructionName, "declarer"))
    {
        const StringRef variableName(GlobalParseur.getCurrent());
        GlobalParseur.Next();

        if(!binaire::LexicalParseur::SequenceParse::equal(GlobalParseur.getCurrent(), ":"))
            throw std::runtime_error("Unautorized declaration  at " + std::to_string(GetLine().first));
        GlobalParseur.Next();

        buffer = GlobalParseur.getCurrent();
        GlobalParseur.Next();

        impl->getVariableContexte().push_back(VariablePrototype(buildString(variableName), false, false, 0, typeid(void), 0u));
        VariablePrototype &NewVar = impl->getVariableContexte().back();

        while(NewVar.getVarTypeStructure().getType() == typeid(void))
        {
            while(binaire::LexicalParseur::SequenceParse::equal(buffer, "tableau_de"))
            {
                NewVar.getVarTypeStructure().setArrayLevel(NewVar.getVarTypeStructure().getArrayLevel()+1);
                buffer = GlobalParseur.getCurrent();
                GlobalParseur.Next();
            }

            if(binaire::isNumber(buffer.first, buffer.second))
            {
                if(NewVar.getVarTypeStructure().getArrayLevel() == 1)
                {
                    NewVar.getVarTypeStructure().getSize() = std::stoul(buildString(buffer));
                    buffer = GlobalParseur.getCurrent();
                    GlobalParseur.Next();
                    continue;
                }
            }

            auto val(getTypeArray().find(buildString(buffer)));
            if(val == getTypeArray().end())
            {
                if(NewVar.getVarTypeStructure().getArrayLevel() == 1)
                {
                    NewVar.getVarTypeStructure().setVar(findVar(getVariableEnv(), buffer));
                    buffer = GlobalParseur.getCurrent();
                    GlobalParseur.Next();
                    continue;
                }
            }
            NewVar.getVarTypeStructure().setType_Index(val->second);
        }

        getVariableEnv().back().push_back(&NewVar);
        impl->getInstructionList().push_back(binaire::make_SmartPtr(new Declaration(&NewVar)));
    }
    else if(WordParse::equal(InstructionName, "renvoie"))
    {
        if(GlobalParseur.LastWord())
        {
            impl->getInstructionList().push_back(make_SmartPtr(new RetourDeFonction(currentFonc)));
        }
        else
        {
            impl->getInstructionList().push_back(make_SmartPtr(new RetourDeFonction(currentFonc, m_Instance->analyserOperation(GlobalParseur))));
        }
    }
}
