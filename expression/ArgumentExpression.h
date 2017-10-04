#ifndef ARGUMENTEXPRESSION_H
#define ARGUMENTEXPRESSION_H

#include <vector>
#include "../interface/IArguments.h"
#include "../interface/IExpression.h"

class ArgumentExpression : public IArguments
{
public:
    ArgumentExpression();
    ArgumentExpression(const std::vector<std::shared_ptr<IExpression>> &);
    ArgumentExpression(const std::initializer_list<std::shared_ptr<IExpression>> &);
    void visiteArgument(IArgumentVisitor &) const override;
    std::size_t size() const noexcept override;
    Type at(std::size_t) const override;
private:
    std::vector<std::shared_ptr<IExpression>> m_expression;
};

#endif // ARGUMENTEXPRESSION_H
