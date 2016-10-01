#include "DoWhileLoop.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

DoWhileLoop::DoWhileLoop(const binaire::SmartPtr<Expression> &exp) noexcept : m_Exp(exp)
{}

DoWhileLoop::DoWhileLoop(const binaire::SmartPtr<Expression> &exp, const std::list< binaire::SmartPtr<Instruction> > &inst) noexcept : BaseLoop(inst), m_Exp(exp)
{}

const binaire::SmartPtr<Expression> &DoWhileLoop::Exp() const
{
    return m_Exp;
}

void DoWhileLoop::setExp(const binaire::SmartPtr<Expression> &Exp)
{
    m_Exp = Exp;
}

void DoWhileLoop::ToCppCode(ostream &out)
{
    out << string(Indentation * 4, ' ') << "do\n" << string(Indentation * 4, ' ') << "{\n";

    InstructionBlock::ToCppCode(out);

    out  << string(Indentation  * 4, ' ') << "} while (";
    m_Exp->ToCppCode(out);
    out << ");\n";
}
