#include "CommonAbstractData.h"
#include <algorithm>

CommonAbstractData::CommonAbstractData(const std::list<std::shared_ptr<IOperator>> &array) : m_operand(array)
{}

bool CommonAbstractData::hasOperand(const IOperator &op, const IArguments &arg) const noexcept
{
    if(!op.matchArguments(arg))
        return false;
    return std::find_if(m_operand.begin(), m_operand.end(), [&op](const std::shared_ptr<IOperator> &iop){
        return iop && iop.get() == &op;
    }) == m_operand.end();
}

void CommonAbstractData::addSupportedOperand(const std::list<std::shared_ptr<IOperator>> &tab)
{
    m_operand.insert(m_operand.begin(), tab.begin(), tab.end());
}

void CommonAbstractData::addSupportedOperand(const std::shared_ptr<IOperator> &val)
{
    m_operand.push_back(val);
}
