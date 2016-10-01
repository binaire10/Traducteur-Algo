#include "NegationBool.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

NegationBool::NegationBool(const binaire::SmartPtr<Expression> &a) : Unuaire(a)
{}

void NegationBool::ToCppCode(ostream &os)
{
    os << " !";
    m_x->ToCppCode(os);
}

bool NegationBool::isFinalValue()
{
    return false;
}
