#include "Expression.h"

using namespace std;
//using namespace binaire;
using namespace ElementAlgorithmique;

Expression::Expression(const VarType &type) noexcept : m_Type(type)
{}

const VarType &Expression::getTypeIndex() const
{
    return m_Type;
}

void Expression::setType(const VarType &value)
{
    m_Type = value;
}
