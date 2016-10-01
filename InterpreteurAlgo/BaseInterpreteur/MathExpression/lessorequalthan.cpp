#include "LessOrEqualThan.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

LessOrEqualThan::LessOrEqualThan(const SmartPtr<Expression> &a, const SmartPtr<Expression> &b) : Binaire(a, b)
{}

void LessOrEqualThan::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " < ";
    m_b->ToCppCode(os);
}

bool LessOrEqualThan::isFinalValue()
{
    return false;
}
