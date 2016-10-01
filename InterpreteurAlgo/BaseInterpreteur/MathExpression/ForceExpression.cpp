#include "ForceExpression.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

ForceExpression::ForceExpression(const binaire::SmartPtr<Expression> &x) : Unuaire(x)
{
}


void ForceExpression::ToCppCode(ostream &out)
{
    out << '(';
    m_x->ToCppCode(out);
    out << ')';
}

bool ForceExpression::isFinalValue()
{
    return false;
}
