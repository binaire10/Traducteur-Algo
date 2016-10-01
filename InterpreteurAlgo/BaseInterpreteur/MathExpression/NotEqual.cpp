#include "NotEqual.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

NotEqual::NotEqual(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{}

void NotEqual::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " != ";
    m_b->ToCppCode(os);
}

bool NotEqual::isFinalValue()
{
    return false;
}
