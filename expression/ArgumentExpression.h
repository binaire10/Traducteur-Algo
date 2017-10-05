#ifndef ARGUMENTEXPRESSION_H
#define ARGUMENTEXPRESSION_H

#include <vector>
#include "../interface/IParameters.h"
#include "../interface/IExpression.h"

class ArgumentExpression : public IParameters
{
public:
    ArgumentExpression();
    ArgumentExpression(const std::vector<std::shared_ptr<IExpression>> &);
    ArgumentExpression(const std::initializer_list<std::shared_ptr<IExpression>> &);
    void visiteArgument(IParametersVisitor &) const override;
    std::size_t size() const noexcept override;
    AbstractDataType at(std::size_t) const override;
private:
    std::vector<std::shared_ptr<IExpression>> m_expression;
};

#endif // ARGUMENTEXPRESSION_H
