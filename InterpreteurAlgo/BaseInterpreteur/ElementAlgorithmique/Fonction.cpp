#include "Fonction.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

Fonction::Fonction(const string &Name) noexcept : Name(Name), Implementation(new InstructionBlock)
{}

std::list<VariablePrototype> &Fonction::GetInput()
{
    return Input;
}

binaire::SmartPtr<InstructionBlock> &Fonction::getImplementation()
{
    return Implementation;
}

binaire::SmartPtr<InstructionBlock> &mainInfo::getImplementation()
{
    return Implementation;
}

VarType &Fonction::GetOutput()
{
    return Output;
}

string &Fonction::GetName()
{
    return Name;
}

bool Fonction::ArgumenntAllow(unsigned i) const
{
    // compare le nombre d'argument i avec les nombre d'entré de la fonction
    return i == Input.size();
}

bool Fonction::Validate(const std::list<binaire::SmartPtr<Expression> > &ExpresionArgument)
{
    // on Verifie que il y a autant d'argument que d'entrer
    if(ExpresionArgument.size() != Input.size())
        return false;

    std::list<VariablePrototype>::iterator v(Input.begin());
    for(const binaire::SmartPtr<Expression> &i : ExpresionArgument)
    {
        // on verifie que les type soit identique
        if(!(v->getVarTypeStructure() == i->getTypeIndex() || (!v->getVarTypeStructure().getIsRefVar() && VarType::isTranstypable(v->getVarTypeStructure(), i->getTypeIndex()))))
            return false;
        ++v;
    }
    // si les entrée son valide alors en renvoie true
    return true;
}

bool Fonction::Validate(const std::list<VariablePrototype> &ExpresionArgument)
{
    // on Verifie que il y a autant d'argument que d'entrer
    if(ExpresionArgument.size() != Input.size())
        return false;

    std::list<VariablePrototype>::iterator v(Input.begin());
    for(const VariablePrototype &i : ExpresionArgument)
    {
        // on verifie que les type soit identique
        if(!(v->getVarTypeStructure() == i.getVarTypeStructure()))
            return false;
        ++v;
    }
    // si les entrée son valide alors en renvoie true
    return true;
}
