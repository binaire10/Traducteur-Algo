#include "LoopBuilder.h"
#include <MyParse/WordParse.h>
#include "LecteurCode.h"
#include "LoopFor.h"
#include "WhileLoop.h"
#include "DoWhileLoop.h"
#include "Loop.h"
#include "BreakLoop.h"
#include "NegationBool.h"
#include "ForceExpression.h"
#include "continue.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;


LoopBuilder::LoopBuilder(LecteurCode *code) : InstructionGenerator(code)
{}

bool LoopBuilder::valideInstruction(const StringRef &InstructionName) const noexcept
{
    return WordParse::equal(InstructionName, "jusqua") || WordParse::equal(InstructionName, "repeter") || WordParse::equal(InstructionName, "tant_que") || WordParse::equal(InstructionName, "boucle") || WordParse::equal(InstructionName, "pour") || WordParse::equal(InstructionName, "continue") || WordParse::equal(InstructionName, "sortie");
}

void LoopBuilder::buildInstructionFromAlgo(const StringRef &InstructionName, LexicalParseur &GlobalParseur, SmartPtr<InstructionBlock> &impl, Fonction *currentFonc, BaseLoop *currentLoop)
{
    StringRef buffer;
    if(WordParse::equal(InstructionName, "jusqua"))
    {
        buffer = GlobalParseur.getCurrent();
        GlobalParseur.Next();

        if(*buffer.first != '(' || *(buffer.second-1) != ')')
            throw runtime_error("Condition parse failled");
        ++buffer.first;
        --buffer.second;

        LexicalParseur NewParse(GlobalParseur);
        NewParse.setSource(InstructionName);

        WhileLoop *lpid;
        binaire::SmartPtr<InstructionBlock> loopInfinit(lpid = new WhileLoop(make_SmartPtr(new NegationBool(make_SmartPtr(new ForceExpression(m_Instance->analyserOperation(NewParse)))))));
        impl->getInstructionList().push_back(loopInfinit);
        NextLine();
        m_Instance->analyseImplementation<LoopFaire, LoopFFaire>(GlobalParseur, loopInfinit, currentFonc, lpid);
    }
    else if(WordParse::equal(InstructionName, "pour"))
    {
        getVariableEnv().push_back(std::list<VariablePrototype *>());
        LoopFor *llop;
        SmartPtr<InstructionBlock> newInsBl(llop = new LoopFor);
        std::list<VariablePrototype *> &currentContext = const_cast<std::list<std::list<VariablePrototype *> > &>(m_Instance->VariableContexte()).back();

        StringRef Arg = GlobalParseur.getCurrent();
        if(*Arg.first != '(' && *(Arg.second-1) != ')')
            throw std::runtime_error("Loop for Error '(' and ')' are missing");
        ++Arg.first;
        --Arg.second;

        binaire::LexicalParseur NewParse(GlobalParseur);
        NewParse.setSource(Arg);
        string var(binaire::buildString(NewParse.getCurrent()));
        NewParse.Next();

        if(!binaire::WordParse::equal(NewParse.getCurrent(), "variant_de"))
            throw std::runtime_error("Loop for Error missing keyword");
        NewParse.Next();

        Arg = NewParse.getCurrent();
        NewParse.Next();

        while(WordParse::equal(NewParse.getCurrent(), "a") && !NewParse.AtEnd())
        {
            NewParse.Next();
        }

        if(WordParse::equal(NewParse.getCurrent(), "a") || (NewParse.AtEnd() && Arg != NewParse.getCurrent()))
        {
            Arg.second = NewParse.getCurrent().first;
            NewParse.Next();
        }
        StringRef Arg2 = NewParse.getCurrent();
        NewParse.Next();

        while(*NewParse.getCurrent().first != ')' && !NewParse.AtEnd())
        {
            NewParse.Next();
        }

        if(*NewParse.getCurrent().first == ')' || (NewParse.AtEnd() && Arg != NewParse.getCurrent()))
        {
            Arg2.second = NewParse.getCurrent().first;
            NewParse.Next();
        }
        NextLine();

        impl->getInstructionList().push_back(newInsBl);

        NewParse.setSource(Arg);
        llop->setBegin(m_Instance->analyserOperation(NewParse));

        NewParse.setSource(Arg2);
        llop->setFinal(m_Instance->analyserOperation(NewParse));

        newInsBl->getVariableContexte().push_back(VariablePrototype(var, false, false, 0, VarType::getBestType(llop->getFinal()->getTypeIndex(), llop->getBegin()->getTypeIndex()).getType(), 0u));
        llop->setI(&newInsBl->getVariableContexte().back());
        currentContext.push_back(&llop->getVariableContexte().back());
        m_Instance->analyseImplementation<LoopFaire, LoopFFaire>(GlobalParseur, newInsBl, currentFonc, llop);

        getVariableEnv().pop_back();
    }
    else if(WordParse::equal(InstructionName, "boucle"))
    {
        Loop *lpid;
        binaire::SmartPtr<InstructionBlock> loopInfinit(lpid = new Loop);
        impl->getInstructionList().push_back(loopInfinit);
        m_Instance->analyseImplementation<NoOpenClose, CloseLoop>(GlobalParseur, loopInfinit, currentFonc, lpid);
    }
    else if(WordParse::equal(InstructionName, "tant_que"))
    {
        buffer = GlobalParseur.getCurrent();
        GlobalParseur.Next();

        if(*buffer.first != '(' || *(buffer.second-1) != ')')
            throw runtime_error("Condition parse failled");
        ++buffer.first;
        --buffer.second;

        LexicalParseur NewParse(GlobalParseur);
        NewParse.setSource(buffer);

        WhileLoop *lpid;
        binaire::SmartPtr<InstructionBlock> loopInfinit(lpid = new WhileLoop(m_Instance->analyserOperation(NewParse)));
        impl->getInstructionList().push_back(loopInfinit);
        NextLine();
        GlobalParseur.setSource(GetLine().second);
        m_Instance->analyseImplementation<LoopFaire, LoopFFaire>(GlobalParseur, loopInfinit, currentFonc, lpid);
    }
    else if(WordParse::equal(InstructionName, "repeter"))
    {
        DoWhileLoop *lpid;
        binaire::SmartPtr<InstructionBlock> loopInfinit(lpid = new DoWhileLoop);

        m_Instance->analyseImplementation<NoOpenClose, CloseBLoop>(GlobalParseur, loopInfinit, currentFonc, lpid);

        impl->getInstructionList().push_back(loopInfinit);

        buffer = GlobalParseur.getCurrent();

        if(!WordParse::equal(buffer, "jusqua"))
            throw std::runtime_error("Code Fails");
        GlobalParseur.Next();
        buffer = GlobalParseur.getCurrent();

        if(*buffer.first != '(' || *(buffer.second-1) != ')')
            throw runtime_error("Condition parse failled");
        ++buffer.first;
        --buffer.second;

        lpid->setExp(m_Instance->analyserOperation(GlobalParseur));

    }
    else if(WordParse::equal(InstructionName, "continue"))
    {
        impl->getInstructionList().push_back(make_SmartPtr(new Continue(currentLoop)));
    }
    else if(WordParse::equal(InstructionName, "sortie"))
    {
        impl->getInstructionList().push_back(make_SmartPtr(new BreakLoop(currentLoop)));
    }
    else
        throw runtime_error("Non décodable");
}
