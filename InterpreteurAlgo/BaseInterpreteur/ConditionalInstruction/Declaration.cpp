#include "Declaration.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

Declaration::Declaration(VariablePrototype *Var) : VarName(Var)
{}

std::string unRollArray(const std::string &Type, unsigned n)
{
    std::string Result;
    unsigned b(n);
    // on reserve la taille du type du tableau
    Result.reserve(n * 12 + Type.size() + n * 2);
    while(n != 0)
    {
        Result += "std::vector< ";
        --n;
    }

    Result += Type;

    while(b != 0)
    {
        Result += " >";
        --b;
    }
    return Result;
}

void Declaration::ToCppCode(ostream &Result)
{
    string Type(findKey(cppType.begin(), cppType.end(), VarName->getVarTypeStructure().getType())->first);
    // Pour les tableau il peut-être spécifier une taille de dépard
    if(VarName->getVarTypeStructure().getVariableType() == false)
    {
        // si la taille est numérique
        if(VarName->getVarTypeStructure().getSize() == 0)
            Result << string(Indentation*4, ' ') << unRollArray(Type, VarName->getVarTypeStructure().getArrayLevel()) << ' '  << VarName->getName() << ";\n";
        else
            Result << string(Indentation*4, ' ') << unRollArray(Type, VarName->getVarTypeStructure().getArrayLevel()) << ' ' << VarName->getName() << "(" << VarName->getVarTypeStructure().getSize() << ");\n";
    }
    else
    {
        // si la taille est donné par une variable
        if(VarName->getVarTypeStructure().getVar()->getName() == "")
            Result << string(Indentation*4, ' ') << unRollArray(Type, VarName->getVarTypeStructure().getArrayLevel()) << ' ' << VarName->getName() << ";\n";
        else
            Result << string(Indentation*4, ' ') << unRollArray(Type, VarName->getVarTypeStructure().getArrayLevel()) << ' ' << VarName->getName() << "(" << VarName->getVarTypeStructure().getVar()->getName() << ");\n";
    }
}
