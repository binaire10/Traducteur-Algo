#pragma once
#include <MyMemory/SmartPtr.h>
#include <list>
#include "VariablePrototype.h"


class EnvGlobal
{
public:
    EnvGlobal();
    EnvGlobal(const EnvGlobal &) = delete;
    EnvGlobal &operator=(const EnvGlobal &) = delete;
    void popEnv();
    void pushEnv();
    void newBlock();
    void popBlock();
    binaire::SmartPtr<void> getVar(ElementAlgorithmique::VariablePrototype * const Adr);
    binaire::SmartPtr<void> creatVar(ElementAlgorithmique::VariablePrototype * const Adr);

private:
    std::list< std::list< std::list<std::pair<ElementAlgorithmique::VariablePrototype *, binaire::SmartPtr<void> > > > > m_Env;
    std::list< std::list<std::pair<ElementAlgorithmique::VariablePrototype *, binaire::SmartPtr<void> > > > *m_Current;
};
