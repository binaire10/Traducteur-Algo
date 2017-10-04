#include "BitWiseOperation.h"
#include "../type/CommonScalar.h"

Type BitWiseOperation::result(const IArguments &arg)
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into BitWiseOperation operation");

    if(arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>())
        return arg.at(0).sizeType() < arg.at(1).sizeType() ? arg.at(1) : arg.at(0);
    throw std::runtime_error("BitWiseOperation operation requier scalar argument");
}
