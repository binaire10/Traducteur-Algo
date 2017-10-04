#include "CommonType.h"
#include <algorithm>

CommonType::CommonType(const std::vector<std::pair<std::shared_ptr<ICommonType>, std::shared_ptr<IArguments> > > &array) : m_operand(array)
{}

bool CommonType::hasOperand(const IOperator &op, const IArguments &arg) const
{
    if(op.)
    return std::find_if(m_operand.begin(), m_operand.end(), [&op, &arg](const std::weak_ptr<IOperator> &iop){
        return !iop.expired() &&iop.lock().get() == &op;
    }) == m_operand.end();
}
