#include "LogicOperation.h"
#include "../type/Boolean.h"

AbstractDataType LogicOperation::result(const IParameters &arg) const
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into LogicOperation operation");

    if(arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>())
        return AbstractDataType(Boolean::getInstance());
    throw std::runtime_error("LogicOperation operation requier scalar argument");
}

bool LogicOperation::matchArguments(const IParameters &arg) const noexcept
{
    return arg.size() != 2 && arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>();
}
