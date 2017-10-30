#include "ExpressionNaire.h"
#include "../interface/Expression.h"
#include "../interface/IExpressionVisitor.h"
#include <cassert>

void ExpressionNaire::visiteExpression(IExpressionVisitor &v) const
{
    v.visiteExpression(*this);
}

std::shared_ptr<AbstractDataType> ExpressionNaire::result() const
{
    return m_operation->result(m_arguments);
}

std::shared_ptr<AbstractOperation> ExpressionNaire::operation() const
{
    return m_operation;
}

const std::list<std::shared_ptr<Expression>> &ExpressionNaire::arguments() const noexcept
{
    return m_arguments;
}

Expression::value_cast ExpressionNaire::resultValueCast() const noexcept
{
    return m_operation->castValueOfResult();
}

ExpressionNaire::ExpressionNaire(const std::shared_ptr<AbstractOperation> &op, const std::list<std::shared_ptr<Expression> > &arg) noexcept : m_operation(op), m_arguments(arg)
{}

void ExpressionNaire::visiteInstruction(IInstructionVisitor &v) const
{
    v.visiteInstruction(*this);
}
