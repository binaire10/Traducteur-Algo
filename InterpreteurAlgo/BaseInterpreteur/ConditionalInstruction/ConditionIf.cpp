#include "ConditionIf.h"
#include "VariablePrototype.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

ConditionIf::ConditionIf(const binaire::SmartPtr<Expression> &exp) : m_exp(exp), m_else(nullptr), m_SubCondition(false), m_hasCondition(true)
{
    if(!VarType::allowType(exp->getTypeIndex())  && exp->getTypeIndex().getType() != typeid(std::string))
        throw runtime_error("not allow type");
}

ConditionIf::~ConditionIf()
{
    delete m_else;
}

ConditionIf::ConditionIf(const binaire::SmartPtr<Expression> &exp, bool hasCondition)  : m_exp(exp), m_else(nullptr), m_SubCondition(true), m_hasCondition(hasCondition)
{}

ConditionIf *ConditionIf::ElseIf(const binaire::SmartPtr<Expression> &exp)
{
    if(m_else != nullptr)
        return m_else->ElseIf(exp);
    else
        m_else = new ConditionIf(exp, true);
    return m_else;
}

ConditionIf *ConditionIf::Else()
{
    if(m_else != nullptr)
        return m_else->Else();
    else
        m_else = new ConditionIf(binaire::SmartPtr<Expression>(), false);
    return m_else;
}

void ConditionIf::ToCppCode(ostream &os)
{
    if(m_SubCondition && m_hasCondition)
    {
        os << string(Indentation * 4, ' ') << "else if(";
        m_exp->ToCppCode(os);
        os << ")\n";
        if(getInstructionList().size() == 1)
        {
            ++Indentation;
            getInstructionList().front()->ToCppCode(os);
            --Indentation;
        }
        else
        {
            os << string(Indentation * 4, ' ') << "{\n";
            InstructionBlock::ToCppCode(os);
            os << string(Indentation * 4, ' ') << "}\n";
        }
    }
    else if(m_SubCondition)
    {
        os << string(Indentation * 4, ' ') << "else\n";
        if(getInstructionList().size() == 1)
        {
            ++Indentation;
            getInstructionList().front()->ToCppCode(os);
            --Indentation;
        }
        else
        {
            os << string(Indentation * 4, ' ') << "{\n";
            InstructionBlock::ToCppCode(os);
            os << string(Indentation * 4, ' ') << "}\n";
        }
    }
    else
    {
        os << string(Indentation * 4, ' ') << "if(";
        m_exp->ToCppCode(os);
        os << ")\n";
        if(getInstructionList().size() == 1)
        {
            ++Indentation;
            getInstructionList().front()->ToCppCode(os);
            --Indentation;
        }
        else
        {
            os << string(Indentation * 4, ' ') << "{\n";
            InstructionBlock::ToCppCode(os);
            os << string(Indentation * 4, ' ') << "}\n";
        }
    }
    if(m_else)
        m_else->ToCppCode(os);
}
