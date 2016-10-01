#include "Equal.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Equal::Equal(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{}

void Equal::ToCppCode(ostream &Result)
{
    m_a->ToCppCode(Result);
    Result << " == ";
    m_b->ToCppCode(Result);
}

bool Equal::isFinalValue()
{
    return false;
}
