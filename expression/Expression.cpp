#include "Expression.h"
#include "../interface/IExpressionVisitor.h"
#include "cassert"

void Expression::visiteExpression(IExpressionVisitor &v) const
{
    v.visiteExpression(*this);
}

AbstractDataType Expression::result() const
{
    return m_operation->result(*m_arguments);
}

std::shared_ptr<IOperation> Expression::operation() const
{
    return m_operation;
}

std::shared_ptr<ArgumentExpression> Expression::arguments() const
{
    return m_arguments;
}

Expression::Expression(const std::shared_ptr<IOperation> &op, const std::shared_ptr<ArgumentExpression> &arg) noexcept : m_operation(op), m_arguments(arg)
{}

void Expression::visiteInstruction(IInstructionVisitor &v) const
{
    v.visiteInstruction(*this);
}
