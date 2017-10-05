#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../interface/IInstruction.h"
#include "../interface/IExpression.h"
#include "../interface/IOperation.h"
#include "../interface/IParameters.h"
#include "ArgumentExpression.h"

class Expression : public IExpression, public IInstruction
{
public:
    Expression(const std::shared_ptr<IOperation> &, const std::shared_ptr<ArgumentExpression> &) noexcept;
    void visiteInstruction(IInstructionVisitor &) const override;
    void visiteExpression(IExpressionVisitor &) const override;
    AbstractDataType result() const override;
    std::shared_ptr<IOperation> operation() const;
    std::shared_ptr<ArgumentExpression> arguments() const;

private:
    std::shared_ptr<IOperation> m_operation;
    std::shared_ptr<ArgumentExpression> m_arguments;
};

#endif // EXPRESSION_H
