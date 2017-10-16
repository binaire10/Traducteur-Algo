#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../interface/Instructable.h"
#include "../interface/Expressionable.h"
#include "../interface/AbstractOperation.h"

class Expression : public Expressionable, public Instructable
{
public:
    Expression(const std::shared_ptr<AbstractOperation> &, const std::list<std::shared_ptr<Expressionable>> &) noexcept;
    void visiteInstruction(IInstructionVisitor &) const override;
    void visiteExpression(IExpressionVisitor &) const override;
    std::shared_ptr<AbstractDataType> result() const override;
    std::shared_ptr<AbstractOperation> operation() const;
    const std::list<std::shared_ptr<Expressionable> > &arguments() const noexcept;
    Expressionable::value_cast resultValueCast() const noexcept override;

private:
    std::shared_ptr<AbstractOperation> m_operation;
    std::list<std::shared_ptr<Expressionable>> m_arguments;
};

#endif // EXPRESSION_H
