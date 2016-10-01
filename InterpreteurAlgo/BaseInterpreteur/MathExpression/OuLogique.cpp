#include "OuLogique.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

OuLogique::OuLogique(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a, b)
{}

void OuLogique::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " || ";
    m_b->ToCppCode(os);
}

bool OuLogique::isFinalValue()
{
    return false;
}
