#include "ArgumentExpression.h"
#include "../interface/IArgumentVisitor.h"

ArgumentExpression::ArgumentExpression()
{}

ArgumentExpression::ArgumentExpression(const std::vector<std::shared_ptr<IExpression> > &tab) : m_expression(tab)
{}

ArgumentExpression::ArgumentExpression(const std::initializer_list<std::shared_ptr<IExpression> > &tab) : m_expression(tab)
{}

void ArgumentExpression::visiteArgument(IArgumentVisitor &v) const
{
    v.visiteArgument(*this);
}

std::size_t ArgumentExpression::size() const noexcept
{
    return m_expression.size();
}

AbstractDataType ArgumentExpression::at(std::size_t i) const
{
    return m_expression.at(i)->result();
}
