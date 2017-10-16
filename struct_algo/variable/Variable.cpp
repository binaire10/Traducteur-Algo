#include "Variable.h"
#include "../interface/IExpressionVisitor.h"

Variable::Variable(const std::string &name, const std::shared_ptr<AbstractDataType> &type) : m_name(name), m_type(type)
{}

std::string Variable::name() const noexcept
{
    return m_name;
}

std::shared_ptr<AbstractDataType> Variable::type() const noexcept
{
    return m_type;
}

void Variable::visiteExpression(IExpressionVisitor &visitor) const
{
    visitor.visiteExpression(*this);
}

std::shared_ptr<AbstractDataType> Variable::result() const
{
    return m_type;
}

Expressionable::value_cast Variable::resultValueCast() const noexcept
{
    return Expressionable::lvalue;
}
