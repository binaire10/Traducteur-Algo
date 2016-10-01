#pragma once
#include <MyMemory/SmartPtr.hpp>
#include <MyParse/StringParse.h>
#include <list>
#include <stdexcept>
#include <vector>
#include <iostream>
#include "CoreExpression.h"
#include "Fonction.h"

extern std::vector<std::pair<std::string, std::type_index> > cppType;
extern unsigned Indentation;
std::string unRollArray(const std::string &Type, unsigned n);


typedef std::pair<std::string::const_iterator, std::string::const_iterator> StringRef;

inline ElementAlgorithmique::VariablePrototype *findVar(std::list< std::list<ElementAlgorithmique::VariablePrototype *> > &ar, const std::string &VarName)
{
    ElementAlgorithmique::VariablePrototype *result(nullptr);
    for(std::list<ElementAlgorithmique::VariablePrototype *> &iVarList : ar)
        for(ElementAlgorithmique::VariablePrototype *&iVar : iVarList)
            if(iVar->getName() == VarName)
                result = iVar;

    return result;
}

inline ElementAlgorithmique::VariablePrototype *findVar(std::list< std::list<ElementAlgorithmique::VariablePrototype *> > &ar, const StringRef &VarName)
{
    ElementAlgorithmique::VariablePrototype *result(nullptr);
    for(std::list<ElementAlgorithmique::VariablePrototype *> &iVarList : ar)
        for(ElementAlgorithmique::VariablePrototype *&iVar : iVarList)
            if(binaire::StringParse::equal(VarName, iVar->getName()))
                result = iVar;
    return result;
}

inline ElementAlgorithmique::Fonction *findFonction(std::list<ElementAlgorithmique::Fonction *> &Tab, const std::string &FoncName)
{
    for(ElementAlgorithmique::Fonction *&i : Tab)
        if(FoncName == i->GetName())
            return i;
    return nullptr;
}

inline ElementAlgorithmique::Fonction *findFonction(std::list<ElementAlgorithmique::Fonction *> &Tab, const std::string &FoncName, const unsigned &carg)
{
    for(ElementAlgorithmique::Fonction *&i : Tab)
        if(FoncName == i->GetName() && i->ArgumenntAllow(carg))
            return i;
    return nullptr;
}

template<typename Iter_t, typename Value>
Iter_t findKey(Iter_t beg, const Iter_t &end, const Value &val)
{
    while(beg != end && beg->second != val)
        ++beg;
    return beg;
}

template<typename Iter_t, typename Value>
Iter_t findValue(Iter_t beg, const Iter_t &end, const Value &val)
{
    while(beg != end && beg->first != val)
        ++beg;
    return beg;
}

inline ElementAlgorithmique::Fonction *findFonction(std::list<ElementAlgorithmique::Fonction *> &Tab, const std::string &FoncName, const std::list<binaire::SmartPtr<ElementAlgorithmique::Expression> > &carg)
{
    std::cout << "Select : " << FoncName << std::endl;
    for(ElementAlgorithmique::Fonction *&i : Tab)
    {
        if(FoncName == i->GetName() && i->Validate(carg))
        {
            if(i->GetInput().size() == 1)
            std::cout << "Valide -> " << i->GetName() << " Because : " << unRollArray(findKey(cppType.begin(), cppType.end(), i->GetInput().front().getVarTypeStructure().getType())->first, i->GetInput().front().getVarTypeStructure().getArrayLevel()) << std::endl;
            return i;
        }
        else if(i->GetInput().size() == 1 && FoncName == i->GetName())
        {
            std::cout << "Reject " << i->GetName() << " Because : " << unRollArray(findKey(cppType.begin(), cppType.end(), i->GetInput().front().getVarTypeStructure().getType())->first, i->GetInput().front().getVarTypeStructure().getArrayLevel()) << std::endl;
        }
    }
    return nullptr;
}

inline ElementAlgorithmique::Fonction *findFonction(std::list<ElementAlgorithmique::Fonction *> &Tab, const StringRef &FoncName, const std::list<binaire::SmartPtr<ElementAlgorithmique::Expression> > &carg)
{
    for(ElementAlgorithmique::Fonction *&i : Tab)
        if(binaire::StringParse::equal(FoncName, i->GetName()) && i->Validate(carg))
            return i;
    return nullptr;
}

inline ElementAlgorithmique::Fonction *findFonction(std::list<ElementAlgorithmique::Fonction *> &Tab, const StringRef &FoncName)
{
    for(ElementAlgorithmique::Fonction *&i : Tab)
        if(binaire::StringParse::equal(FoncName, i->GetName()))
            return i;
    return nullptr;
}

inline ElementAlgorithmique::Fonction *findFonction(std::list<ElementAlgorithmique::Fonction *> &Tab, const StringRef &FoncName, const std::list< ElementAlgorithmique::VariablePrototype > &carg)
{
    for(ElementAlgorithmique::Fonction *&i : Tab)
        if(binaire::StringParse::equal(FoncName, i->GetName()) && i->Validate(carg))
            return i;
    return nullptr;
}
