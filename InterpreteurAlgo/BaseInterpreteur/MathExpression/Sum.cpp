#include "Sum.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Sum::Sum(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire()
{
    m_a = a;
    m_b = b;
    if(b->getTypeIndex().getType() == typeid(char) && a->getTypeIndex().getType() == typeid(std::string))
        m_Type = a->getTypeIndex();
    else
        m_Type = VarType::getBestType(a->getTypeIndex(), b->getTypeIndex());
}

void Sum::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " + ";
    m_b->ToCppCode(os);
}

bool Sum::isFinalValue()
{
    return false;
}
