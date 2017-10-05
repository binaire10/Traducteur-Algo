#include "BitWiseOperation.h"
#include "../type/CommonScalar.h"

AbstractDataType BitWiseOperation::result(const IParameters &arg) const
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into BitWiseOperation operation");

    if(arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>())
        return arg.at(0).sizeType() < arg.at(1).sizeType() ? arg.at(1) : arg.at(0);
    throw std::runtime_error("BitWiseOperation operation requier scalar argument");
}

bool BitWiseOperation::matchArguments(const IParameters &arg) const noexcept
{
    return arg.size() != 2 && arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>();
}
