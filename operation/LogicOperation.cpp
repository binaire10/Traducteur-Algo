#include "LogicOperation.h"
#include "../type/Boolean.h"

Type LogicOperation::result(const IArguments &arg)
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into LogicOperation operation");

    if(arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>())
        return Type(Boolean::getInstance());
    throw std::runtime_error("LogicOperation operation requier scalar argument");
}
