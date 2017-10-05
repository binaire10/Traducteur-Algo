#include "BitWiseOperation.h"
#include "../type/CommonScalar.h"

AbstractDataType BitWiseOperation::result(const IParameters &arg) const
{
    if(arg.size() != m_parametersCount)
        throw std::runtime_error("bad argument count into BitWiseOperation operation");
//
    return arg.at(0).sizeType() < arg.at(1).sizeType() ? arg.at(1) : arg.at(0);
    if(matchArguments(arg))
    {
        AbstractDataType Data = arg.at(0);
        for(std::size_t i(1) ; i < m_parametersCount ; ++i)
            if(Data.sizeType() < arg.at(i).sizeType())
                Data = arg.at(i);
        return Data;
    }
    throw std::runtime_error("BitWiseOperation operation requier scalar argument");
}

bool BitWiseOperation::matchArguments(const IParameters &arg) const noexcept
{
    if(arg.size() == m_parametersCount)
    {
        for(std::size_t i(0) ; i < m_parametersCount ; ++i)
            if(!arg.at(0).instanceOf<CommonScalar>())
                return false;
    }
    else
        return false;
    return true;
}
