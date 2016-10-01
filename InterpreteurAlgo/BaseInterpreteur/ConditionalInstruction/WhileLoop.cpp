#include "WhileLoop.h"
#include "struccore.h"
#include <cassert>

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

WhileLoop::WhileLoop(const binaire::SmartPtr<Expression> &exp) : m_Exp(exp)
{
    if(!VarType::isTranstypable(VarType(false, false, 0, typeid(bool), 0u), m_Exp->getTypeIndex()))
        throw runtime_error("Condition non Autorisé");
}

void WhileLoop::ToCppCode(ostream &out)
{
    assert(m_Exp.GetPtr() != nullptr);
    out << string(Indentation * 4, ' ') << "while(";
    m_Exp->ToCppCode(out);
    out << ")\n" << string(Indentation * 4, ' ') << "{\n";
    InstructionBlock::ToCppCode(out);
    out << string(Indentation * 4, ' ') << "}\n";
}

void WhileLoop::setExp(const binaire::SmartPtr<Expression> &Exp)
{
    if(m_Exp.GetPtr() == nullptr)
        throw runtime_error("Empty Expression");
    m_Exp = Exp;
    if(!VarType::isTranstypable(VarType(false, false, 0, typeid(bool), 0u), m_Exp->getTypeIndex()))
        throw runtime_error("Condition non Autorisé");
}
