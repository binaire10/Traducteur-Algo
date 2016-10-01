#include "LoopFor.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

LoopFor::LoopFor(const binaire::SmartPtr<Expression> &start, const binaire::SmartPtr<Expression> &final) noexcept : m_begin(start), m_final(final)
{}

void LoopFor::ToCppCode(ostream &Result)
{
    Result <<  string(Indentation*4, ' ') << "for(" + findKey(cppType.begin(), cppType.end(), i->getVarTypeStructure().getType())->first << ' ' + i->getName() << "(";
    m_begin->ToCppCode(Result);
    Result << ") ; " << i->getName() << " < (";
    m_final->ToCppCode(Result);
    Result << ") ; ++" << i->getName() << ")\n";
    Result  <<  string(Indentation*4, ' ') << "{\n";
    InstructionBlock::ToCppCode(Result);
    Result  <<  string(Indentation*4, ' ') << "}\n";
}

const binaire::SmartPtr<Expression> &LoopFor::getFinal() const
{
    return m_final;
}

void LoopFor::setFinal(const binaire::SmartPtr<Expression> &value)
{
    m_final = value;
}

const VariablePrototype *LoopFor::getI() const
{
    return i;
}

void LoopFor::setI(VariablePrototype *value)
{
    i = value;
}

const binaire::SmartPtr<Expression> &LoopFor::getBegin() const
{
    return m_begin;
}

void LoopFor::setBegin(const binaire::SmartPtr<Expression> &value)
{
    m_begin = value;
}
