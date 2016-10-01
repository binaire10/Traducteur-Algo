#include "LessThan.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

LessThan::LessThan(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{}

void LessThan::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " < ";
    m_b->ToCppCode(os);
}

bool LessThan::isFinalValue()
{
    return false;
}
