#include "OuBinaire.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

OuBinaire::OuBinaire(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a, b)
{}

void OuBinaire::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " | ";
    m_b->ToCppCode(os);
}

bool OuBinaire::isFinalValue()
{
    return false;
}
