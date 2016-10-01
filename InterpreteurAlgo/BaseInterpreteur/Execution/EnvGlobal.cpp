#include "EnvGlobal.h"
#include <stdexcept>
#include "ArrayPrototype.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

void EnvGlobal::popEnv()
{
    m_Env.pop_back();
    if(m_Env.size() != 0)
        m_Current = &m_Env.back();
    else
        m_Current = nullptr;
}

void EnvGlobal::pushEnv()
{
    m_Env.push_back(list< list<pair<VariablePrototype *, SmartPtr<void> > > >());
    m_Current = &m_Env.back();
}

void EnvGlobal::newBlock()
{
    m_Current->push_back(list< pair<VariablePrototype *, SmartPtr<void> > >());
}

void EnvGlobal::popBlock()
{
    m_Current->pop_back();
}

SmartPtr<void> EnvGlobal::getVar(VariablePrototype * const Adr)
{
    for(list< pair< VariablePrototype *, SmartPtr<void> > > &iArray: *m_Current)
        for(pair< VariablePrototype *, SmartPtr<void> > &iValue: iArray)
            if(iValue.first == Adr)
                return iValue.second;

    throw runtime_error("La variable n'existe pas!");
}

binaire::SmartPtr<void> EnvGlobal::creatVar(VariablePrototype * const Adr)
{
    m_Current->back().push_back({const_cast<VariablePrototype *>(Adr), SmartPtr<void>()});

    if(Adr->getVarTypeStructure().getArrayLevel() != 0)
        m_Current->back().back().second = make_SmartPtr(new ArrayPrototype(Adr->getVarTypeStructure()));

    else if(Adr->getVarTypeStructure().getType() == typeid(int64_t))
        m_Current->back().back().second = make_SmartPtr(new int64_t);

    else if(Adr->getVarTypeStructure().getType() == typeid(char))
        m_Current->back().back().second = make_SmartPtr(new char);

    else if(Adr->getVarTypeStructure().getType() == typeid(string))
        m_Current->back().back().second = make_SmartPtr(new string);

    else if(Adr->getVarTypeStructure().getType() == typeid(unsigned))
        m_Current->back().back().second = make_SmartPtr(new unsigned);

    else if(Adr->getVarTypeStructure().getType() == typeid(double))
        m_Current->back().back().second = make_SmartPtr(new double);

    else
        throw runtime_error("Type Inconnue");

    return m_Current->back().back().second;
}
