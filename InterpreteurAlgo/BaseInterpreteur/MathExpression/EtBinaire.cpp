#include "EtBinaire.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

EtBinaire::EtBinaire(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{}

void EtBinaire::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " & ";
    m_b->ToCppCode(os);
}

bool EtBinaire::isFinalValue()
{
    return false;
}
