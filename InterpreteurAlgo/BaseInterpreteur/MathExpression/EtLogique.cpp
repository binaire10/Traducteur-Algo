#include "EtLogique.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

EtLogique::EtLogique(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a, b)
{}

void EtLogique::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " && ";
    m_b->ToCppCode(os);
}

bool EtLogique::isFinalValue()
{
    return false;
}
