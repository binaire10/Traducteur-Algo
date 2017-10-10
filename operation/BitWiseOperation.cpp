#include "BitWiseOperation.h"
#include "../type/ScalarDataType.h"

std::shared_ptr<AbstractDataType> BitWiseOperation::result(const std::list<std::shared_ptr<Expressionable> > &arg) const
{
    if(arg.size() != m_parametersCount)
        throw std::runtime_error("bad argument count into BitWiseOperation operation");
    //
    if(matchArguments(arg))
    {
        std::shared_ptr<AbstractDataType> Data = arg.front()->result();
        std::shared_ptr<AbstractDataType> cData;
        for(const auto &i : arg)
            if(Data->size() < (cData = i->result())->size())
                Data = cData;
        return Data;
    }
    throw std::runtime_error("BitWiseOperation operation requier scalar argument");
}

bool BitWiseOperation::matchArguments(const std::list<std::shared_ptr<AbstractDataType> > &arg) const noexcept
{
    if(arg.size() == m_parametersCount)
    {
        for(const auto &i : arg)
            if(!i->instanceOf<ScalarDataType>())
                return false;
    }
    else
        return false;
    return true;
}

bool BitWiseOperation::matchArguments(const std::list<std::shared_ptr<Expressionable> > &arg) const
{
    if(arg.size() == m_parametersCount)
    {
        for(const auto &i : arg)
            if(!i->result()->instanceOf<ScalarDataType>())
                return false;
    }
    else
        return false;
    return true;
}

Expressionable::value_cast BitWiseOperation::castValueOfResult() const noexcept
{
    return Expressionable::prvalue;
}
