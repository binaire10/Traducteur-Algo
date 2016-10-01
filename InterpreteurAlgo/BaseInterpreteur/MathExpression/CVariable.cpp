#include "CVariable.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

CVariable::CVariable(VariablePrototype *const &Value) : Expression(Value->getVarTypeStructure()), var(Value)
{}

void CVariable::ToCppCode(ostream &Result)
{
    Result << var->getName();
}


/*
SmartPtr<void> CVariable::Execute(EnvGlobal &Env)
{
    return Env.getVar(var);
}*/
