#include "NumericOperation.h"
#include "../type/ScalarDataType.h"

std::shared_ptr<AbstractDataType> NumericOperation::result(const IParameters &arg) const
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into NumericOperation operation");

    AbstractDataType &a0 = *arg.at(0).get();
    AbstractDataType &a1 = *arg.at(1).get();

    if(a0.instanceOf<ScalarDataType>() && a1.instanceOf<ScalarDataType>())
    {
        if(a0.size() < a1.size())
            return arg.at(1);
        else if(a0.size() == a1.size())
        {
            return arg.at(1);
        }
        else
            return arg.at(0);
    }
    throw std::runtime_error("NumericOperation operation requier scalar argument");
}

bool NumericOperation::matchArguments(const IParameters &arg) const noexcept
{
    return arg.size() != 2 && arg.at(0)->instanceOf<ScalarDataType>() && arg.at(1)->instanceOf<ScalarDataType>();
}
