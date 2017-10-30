#include "Assign.h"
#include "../exception/BadCastParameters.h"
#include "../interface/AbstractOperationVisitor.h"

Assign::Assign() noexcept
{}

bool Assign::matchArguments(const std::list<std::shared_ptr<AbstractDataType> > &argList) const noexcept
{
    return argList.size() == 2 && argList.front()->equals(*argList.back());
}

bool Assign::matchArguments(const std::list<std::shared_ptr<Expression> > &argList) const noexcept
{
    std::shared_ptr<Expression> lvalue(argList.front());
    std::shared_ptr<AbstractDataType> rvalue(argList.back()->result());
    return argList.size() == 2 && lvalue->result()->equals(*rvalue) && (lvalue->resultValueCast() & Expression::glvalue);
}

std::shared_ptr<AbstractDataType> Assign::result(const std::list<std::shared_ptr<Expression> > &argList) const
{
    if(!matchArguments(argList))
        throw BadCastParameters("operation Assign should be aplied on the same type");
    return argList.front()->result();
}

void Assign::visiteOperation(AbstractOperationVisitor &visitor) const
{
    visitor.visiteOperation(*this);
}

Expression::value_cast Assign::castValueOfResult() const noexcept
{
    return Expression::lvalue;
}
