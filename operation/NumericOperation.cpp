#include "NumericOperation.h"
#include "../type/CommonScalar.h"
#include "../type/Numeric.h"

Type NumericOperation::result(const IArguments &arg)
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into NumericOperation operation");

    Type a0 = arg.at(0);
    Type a1 = arg.at(1);

    if(a0.instanceOf<CommonScalar>() && a1.instanceOf<CommonScalar>())
    {
        if(a0.sizeType() < a1.sizeType())
            return arg.at(1);
        else if(a0.sizeType() == a1.sizeType())
        {
            // check if we lose precision
//            if(a0.instanceOf<Numeric>() && a1.instanceOf<Numeric>())
//            {}
            return arg.at(1);
        }
        else
            return arg.at(0);
    }
    throw std::runtime_error("NumericOperation operation requier scalar argument");
}
