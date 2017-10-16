#include "NumericOperation.h"
#include "../type/ScalarDataType.h"
#include "../exception/BadCastParameters.h"
#include "../exception/ParametersCount.h"

std::shared_ptr<AbstractDataType> NumericOperation::result(const std::list<std::shared_ptr<Expressionable> > &arg) const
{
    if(arg.size() != 2)
        throw ParametersCount("bad argument count into NumericOperation operation");

    std::shared_ptr<AbstractDataType> a0 = arg.front()->result();
    std::shared_ptr<AbstractDataType> a1 = arg.back()->result();

    if(a0->instanceOf<ScalarDataType>() && a1->instanceOf<ScalarDataType>())
    {
        if(a0->size() < a1->size())
            return a1;
        else if(a0->size() == a1->size())
        {
            return a1;
        }
        else
            return a0;
    }
    throw BadCastParameters("NumericOperation operation requier scalar argument");
}

bool NumericOperation::matchArguments(const std::list<std::shared_ptr<AbstractDataType>> &arg) const noexcept
{
    return arg.size() != 2 && arg.front()->instanceOf<ScalarDataType>() && arg.back()->instanceOf<ScalarDataType>();
}

bool NumericOperation::matchArguments(const std::list<std::shared_ptr<Expressionable> > &arg) const
{
    return arg.size() != 2 && arg.front()->result()->instanceOf<ScalarDataType>() && arg.back()->result()->instanceOf<ScalarDataType>();
}

Expressionable::value_cast NumericOperation::castValueOfResult() const noexcept
{
    return Expressionable::prvalue;
}
