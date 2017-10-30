#ifndef TRADUCTEUR_ALGO_VARIABLE_H
#define TRADUCTEUR_ALGO_VARIABLE_H

#include <memory>
#include <string>
#include "../interface/Expression.h"
#include "../type/AbstractDataType.h"

class Variable : public Expression
{
public:
    Variable(const std::string &name, const std::shared_ptr<AbstractDataType> &variable);
    std::string name() const noexcept;
    std::shared_ptr<AbstractDataType> type() const noexcept;
    void visiteExpression(IExpressionVisitor &) const override;
    std::shared_ptr<AbstractDataType> result() const override;
    value_cast resultValueCast() const noexcept override;

private:
    const std::string m_name;
    std::shared_ptr<AbstractDataType> m_type;
};

#endif //TRADUCTEUR_ALGO_VARIABLE_H
