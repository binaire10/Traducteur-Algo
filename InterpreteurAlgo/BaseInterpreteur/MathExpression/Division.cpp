#include "Division.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Division::Division(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{}

void Division::ToCppCode(ostream &Result)
{
    m_a->ToCppCode(Result);
    Result << " / ";
    m_b->ToCppCode(Result);
}

bool Division::isFinalValue()
{
    return false;
}
/**
        switch (m_b->getTypeIndex().getValueType() & !VarType::ARRAYS)
        {
        case VarType::INT:
        {
            SmartPtr<int64_t> BValue(m_a->Execute(Env));
        }
            break;
        case VarType::CHAR:
        {
            SmartPtr<char> BValue(m_a->Execute(Env));
        }
            break;
        case VarType::UNSIGNED:
        {
            SmartPtr<unsigned> BValue(m_a->Execute(Env));
        }
            break;
        case VarType::DOUBLE:
        {
            SmartPtr<double> BValue(m_a->Execute(Env));
        }
            break;
        case VarType::STRING:
        {
            SmartPtr<string> BValue(m_a->Execute(Env));
        }
            break;
        default:
            throw runtime_error("Case Missing Source Code Error");
            break;
        }**/

/*binaire::SmartPtr<void> ElementAlgorithmique::MathExpression::Division::Execute(EnvGlobal &Env)
{
    switch (m_a->getTypeIndex().getValueType())
    {
    case VarType::INT:
    {
        SmartPtr<int64_t> AValue(m_a->Execute(Env));
        switch (m_b->getTypeIndex().getValueType())
        {
        case VarType::INT:
        {
            SmartPtr<int64_t> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::CHAR:
        {
            SmartPtr<char> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::UNSIGNED:
        {
            SmartPtr<unsigned> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::DOUBLE:
        {
            SmartPtr<double> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
            break;
        default:
            throw runtime_error("Case Missing Source Code Error");
            break;
        }
    }
        break;
    case VarType::CHAR:
    {
        SmartPtr<char> AValue(m_a->Execute(Env));
        switch (m_b->getTypeIndex().getValueType())
        {
        case VarType::INT:
        {
            SmartPtr<int64_t> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::CHAR:
        {
            SmartPtr<char> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::UNSIGNED:
        {
            SmartPtr<unsigned> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::DOUBLE:
        {
            SmartPtr<double> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        default:
            throw runtime_error("Case Missing Source Code Error");
            break;
        }
    }
        break;
    case VarType::UNSIGNED:
    {
        SmartPtr<unsigned> AValue(m_a->Execute(Env));
        switch (m_b->getTypeIndex().getValueType())
        {
        case VarType::INT:
        {
            SmartPtr<int64_t> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::CHAR:
        {
            SmartPtr<char> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::UNSIGNED:
        {
            SmartPtr<unsigned> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::DOUBLE:
        {
            SmartPtr<double> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        default:
            throw runtime_error("Case Missing Source Code Error");
            break;
        }
    }
        break;
    case VarType::DOUBLE:
    {
        SmartPtr<double> AValue(m_a->Execute(Env));
        switch (m_b->getTypeIndex().getValueType())
        {
        case VarType::INT:
        {
            SmartPtr<int64_t> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::CHAR:
        {
            SmartPtr<char> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::UNSIGNED:
        {
            SmartPtr<unsigned> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        case VarType::DOUBLE:
        {
            SmartPtr<double> BValue(m_a->Execute(Env));
            *AValue /= *BValue;
        }
            break;
        default:
            throw runtime_error("Case Missing Source Code Error");
            break;
        }
    }
        break;
    default:
        throw runtime_error("Case Missing Source Code Error");
        break;
    }
}*/
