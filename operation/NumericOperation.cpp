#include "NumericOperation.h"
#include "../type/CommonScalar.h"
#include "../type/CommonNumeric.h"

AbstractDataType NumericOperation::result(const IParameters &arg) const
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into NumericOperation operation");

    AbstractDataType a0 = arg.at(0);
    AbstractDataType a1 = arg.at(1);

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

bool NumericOperation::matchArguments(const IParameters &arg) const noexcept
{
    return arg.size() != 2 && arg.at(0).instanceOf<CommonScalar>() && arg.at(1).instanceOf<CommonScalar>();
}
