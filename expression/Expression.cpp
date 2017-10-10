#include "Expression.h"
#include "../interface/IExpressionVisitor.h"
#include "cassert"

void Expression::visiteExpression(IExpressionVisitor &v) const
{
    v.visiteExpression(*this);
}

std::shared_ptr<AbstractDataType> Expression::result() const
{
    return m_operation->result(m_arguments);
}

std::shared_ptr<AbstractOperation> Expression::operation() const
{
    return m_operation;
}

const std::list<std::shared_ptr<Expressionable>> &Expression::arguments() const noexcept
{
    return m_arguments;
}

Expressionable::value_cast Expression::resultValueCast() const noexcept
{
    return m_operation->castValueOfResult();
}

Expression::Expression(const std::shared_ptr<AbstractOperation> &op, const std::list<std::shared_ptr<Expressionable> > &arg) noexcept : m_operation(op), m_arguments(arg)
{}

void Expression::visiteInstruction(IInstructionVisitor &v) const
{
    v.visiteInstruction(*this);
}
