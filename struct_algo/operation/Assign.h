#ifndef ASSIGN_H
#define ASSIGN_H

#include "../interface/AbstractOperation.h"

class Assign : public AbstractOperation
{
public:
    Assign() noexcept;
    bool matchArguments(const std::list<std::shared_ptr<AbstractDataType> > &) const override;
    bool matchArguments(const std::list<std::shared_ptr<Expressionable> > &) const override;
    std::shared_ptr<AbstractDataType> result(const std::list<std::shared_ptr<Expressionable> > &) const override;
    void visiteOperation(AbstractOperationVisitor &) const override;
    Expressionable::value_cast castValueOfResult() const override;
};

#endif // ASSIGN_H
