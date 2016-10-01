#include "Multiplication.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Multiplication::Multiplication(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : Binaire(a,b)
{}

void Multiplication::ToCppCode(ostream &os)
{
    m_a->ToCppCode(os);
    os << " * ";
    m_b->ToCppCode(os);
}

bool Multiplication::isFinalValue()
{
    return false;
}
