#include "BitWiseOperation.h"
#include "../type/ScalarDataType.h"

std::shared_ptr<AbstractDataType> BitWiseOperation::result(const IParameters &arg) const
{
    if(arg.size() != m_parametersCount)
        throw std::runtime_error("bad argument count into BitWiseOperation operation");
//
    if(matchArguments(arg))
    {
        std::shared_ptr<AbstractDataType> Data = arg.at(0);
        for(std::size_t i(1) ; i < m_parametersCount ; ++i)
            if(Data->size() < arg.at(i)->size())
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
            if(!arg.at(0)->instanceOf<ScalarDataType>())
                return false;
    }
    else
        return false;
    return true;
}
