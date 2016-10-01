#include "conditionbuilder.h"
#include "LecteurCode.h"
#include "ConditionIf.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace InstructionAvance;

ConditionBuilder::ConditionBuilder(LecteurCode *code) : InstructionGenerator(code)
{}

bool ConditionBuilder::valideInstruction(const StringRef &InstructionName) const noexcept
{
    return WordParse::equal(InstructionName, "si");
}

void ConditionBuilder::buildInstructionFromAlgo(const StringRef &InstructionName, LexicalParseur &GlobalParseur, SmartPtr<InstructionBlock> &impl, Fonction *currentFonc, BaseLoop *currentLoop)
{
    StringRef Buffer;
    if(WordParse::equal(InstructionName, "si"))
    {
        Buffer = GlobalParseur.getCurrent();
        GlobalParseur.Next();

        if(*Buffer.first != '(' || *(Buffer.second-1) != ')')
            throw runtime_error("Condition parse failled");
        ++Buffer.first;
        --Buffer.second;
        LexicalParseur NewParse(GlobalParseur);
        NewParse.setSource(Buffer);
        ConditionIf *currentIf;
        SmartPtr<InstructionBlock> ifImpl(currentIf = new ConditionIf(m_Instance->analyserOperation(NewParse)));
        impl->getInstructionList().push_back(ifImpl);

        if(!GlobalParseur.AtEnd())
        {
            Buffer = GlobalParseur.getCurrent();
            GlobalParseur.Next();
            m_Instance->InstructionDecodeur(GlobalParseur, ifImpl, Buffer, currentFonc, currentLoop);
        }
        else
        {
            m_Instance->analyseImplementation<NoOpenClose, CloseIf>(GlobalParseur, ifImpl, currentFonc, currentLoop);
        }

        while(WordParse::equal(GlobalParseur.getCurrent(), "sinon_si"))
        {
            GlobalParseur.Next();

            Buffer = GlobalParseur.getCurrent();
            GlobalParseur.Next();

            if(*Buffer.first != '(' || *(Buffer.second-1) != ')')
                throw runtime_error("Condition parse failled");
            ++Buffer.first;
            --Buffer.second;

            NewParse.setSource(Buffer);

            ifImpl = SmartPtr<InstructionBlock>(currentIf = currentIf->ElseIf(m_Instance->analyserOperation(NewParse)), new BaseSmartPtr::DeleterNothing_t);

            if(!GlobalParseur.AtEnd())
            {
                Buffer = GlobalParseur.getCurrent();
                GlobalParseur.Next();
                m_Instance->InstructionDecodeur(GlobalParseur, ifImpl, Buffer, currentFonc, currentLoop);
            }
            else
            {
                m_Instance->analyseImplementation<NoOpenClose, CloseIf>(GlobalParseur, ifImpl, currentFonc, currentLoop);
            }
        }

        if(WordParse::equal(GlobalParseur.getCurrent(), "sinon"))
        {
            GlobalParseur.Next();

            NewParse.setSource(Buffer);

            ifImpl = SmartPtr<InstructionBlock>(currentIf = currentIf->Else(), new BaseSmartPtr::DeleterNothing_t);

            if(!GlobalParseur.AtEnd())
            {
                Buffer = GlobalParseur.getCurrent();
                GlobalParseur.Next();
                m_Instance->InstructionDecodeur(GlobalParseur, ifImpl, Buffer, currentFonc, currentLoop);
            }
            else
            {
                m_Instance->analyseImplementation<NoOpenClose, CloseIf>(GlobalParseur, ifImpl, currentFonc, currentLoop);
                if(!WordParse::equal(GlobalParseur.getCurrent(), "fsi"))
                    throw runtime_error("Condition non finit");
            }
        }
    }
    else
        throw runtime_error("Non décodable");
}
