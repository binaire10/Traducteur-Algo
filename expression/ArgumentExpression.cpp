#include "ArgumentExpression.h"
#include "../interface/IParametersVisitor.h"

ArgumentExpression::ArgumentExpression()
{}

ArgumentExpression::ArgumentExpression(const std::vector<std::shared_ptr<IExpression> > &tab) : m_expression(tab)
{}

ArgumentExpression::ArgumentExpression(const std::initializer_list<std::shared_ptr<IExpression> > &tab) : m_expression(tab)
{}

void ArgumentExpression::visiteArgument(IParametersVisitor &v) const
{
    v.visiteArgument(*this);
}

std::size_t ArgumentExpression::size() const noexcept
{
    return m_expression.size();
}

std::shared_ptr<AbstractDataType> ArgumentExpression::at(std::size_t i) const
{
    return m_expression.at(i)->result();
}
