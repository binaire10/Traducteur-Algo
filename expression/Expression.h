#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../interface/IInstruction.h"
#include "../interface/IExpression.h"
#include "../interface/AbstractOperation.h"
#include "../interface/IParameters.h"
#include "ArgumentExpression.h"

class Expression : public IExpression, public IInstruction
{
public:
    Expression(const std::shared_ptr<AbstractOperation> &, const std::shared_ptr<ArgumentExpression> &) noexcept;
    void visiteInstruction(IInstructionVisitor &) const override;
    void visiteExpression(IExpressionVisitor &) const override;
    std::shared_ptr<AbstractDataType> result() const override;
    std::shared_ptr<AbstractOperation> operation() const;
    std::shared_ptr<ArgumentExpression> arguments() const;

private:
    std::shared_ptr<AbstractOperation> m_operation;
    std::shared_ptr<ArgumentExpression> m_arguments;
};

#endif // EXPRESSION_H
