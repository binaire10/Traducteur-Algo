#include "CommonType.h"
#include <algorithm>

CommonType::CommonType(const std::list<std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments> > > &array) : m_operand(array)
{}

bool CommonType::hasOperand(const IOperator &op, const IArguments &arg) const noexcept
{
    if(!op.matchArguments(arg))
        return false;
    return std::find_if(m_operand.begin(), m_operand.end(), [&op](const std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments>> &iop){
        return iop.first && iop.first.get() == &op;
    }) == m_operand.end();
}

void CommonType::addParamter(const std::list<std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments> > > &tab)
{
    m_operand.insert(m_operand.begin(), tab.begin(), tab.end());
}

void CommonType::addParamter(const std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments> > &val)
{
    m_operand.push_back(val);
}
