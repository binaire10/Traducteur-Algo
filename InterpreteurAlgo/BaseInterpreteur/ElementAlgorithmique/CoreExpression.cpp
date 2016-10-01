#include "CoreExpression.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Unuaire::Unuaire(const SmartPtr<Expression> &x) : Expression(x->getTypeIndex()), m_x(x)
{}

Binaire::Binaire(const SmartPtr<Expression> &a, const SmartPtr<Expression> &b) : Expression(VarType::getBestType(a->getTypeIndex(), b->getTypeIndex())), m_a(a), m_b(b)
{}
