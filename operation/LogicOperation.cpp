#include "LogicOperation.h"
#include "../type/NumericDataType.h"

std::shared_ptr<AbstractDataType> LogicOperation::result(const IParameters &arg) const
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into LogicOperation operation");

    if(matchArguments(arg))
        return NumericDataType::getInstance(NumericDataType::Type::Boolean);
    throw std::runtime_error("LogicOperation operation requier scalar argument");
}

bool LogicOperation::matchArguments(const IParameters &arg) const noexcept
{
    if(arg.size() == m_parametersCount)
    {
        for(std::size_t i(0) ; i < m_parametersCount ; ++i)
            if(!arg.at(0)->instanceOf<NumericDataType>())
                return false;
    }
    else
        return false;
    return true;
}
