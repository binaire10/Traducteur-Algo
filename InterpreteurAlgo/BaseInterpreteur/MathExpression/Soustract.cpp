#include "Soustract.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Soustract::Soustract(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{
    if(m_b->getTypeIndex().getType() == typeid(unsigned))
        m_Type.setType_Index(typeid(int64_t));
}

void Soustract::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " - ";
    m_b->ToCppCode(os);
}

bool Soustract::isFinalValue()
{
    return false;
}
