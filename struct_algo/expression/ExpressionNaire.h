#ifndef EXPRESSIONNAIRE_H
#define EXPRESSIONNAIRE_H

#include "../interface/Instruction.h"
#include "../interface/Expression.h"
#include "../interface/AbstractOperation.h"

class ExpressionNaire : public Expression, public Instruction
{
public:
    ExpressionNaire(const std::shared_ptr<AbstractOperation> &, const std::list<std::shared_ptr<Expression>> &) noexcept;
    void visiteInstruction(IInstructionVisitor &) const override;
    void visiteExpression(IExpressionVisitor &) const override;
    std::shared_ptr<AbstractDataType> result() const override;
    std::shared_ptr<AbstractOperation> operation() const;
    const std::list<std::shared_ptr<Expression> > &arguments() const noexcept;
    Expression::value_cast resultValueCast() const noexcept override;

private:
    std::shared_ptr<AbstractOperation> m_operation;
    std::list<std::shared_ptr<Expression>> m_arguments;
};

#endif // EXPRESSIONNAIRE_H
