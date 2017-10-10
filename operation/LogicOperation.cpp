#include "LogicOperation.h"
#include "../type/NumericDataType.h"

std::shared_ptr<AbstractDataType> LogicOperation::result(const std::list<std::shared_ptr<Expressionable> > &arg) const
{
    if(arg.size() != 2)
        throw std::runtime_error("bad argument count into LogicOperation operation");

    if(matchArguments(arg))
        return NumericDataType::getInstance(NumericDataType::Type::Boolean);
    throw std::runtime_error("LogicOperation operation requier scalar argument");
}

bool LogicOperation::matchArguments(const std::list<std::shared_ptr<Expressionable> > &arg) const
{
    if(arg.size() == m_parametersCount)
    {
        for(auto &value : arg)
            if(!value->result()->instanceOf<NumericDataType>())
                return false;
    }
    else
        return false;
    return true;
}

bool LogicOperation::matchArguments(const std::list<std::shared_ptr<AbstractDataType> > &arg) const noexcept
{
    if(arg.size() == m_parametersCount)
    {
        for(auto &value : arg)
            if(!value->instanceOf<NumericDataType>())
                return false;
    }
    else
        return false;
    return true;
}

Expressionable::value_cast LogicOperation::castValueOfResult() const noexcept
{
    return Expressionable::prvalue;
}
