#include "ArgumentType.h"
#include "../interface/IArgumentVisitor.h"

ArgumentType::ArgumentType()
{}

ArgumentType::ArgumentType(const std::vector<AbstractDataType> &tab) : m_types(tab)
{}

ArgumentType::ArgumentType(const std::initializer_list<AbstractDataType> &tab) : m_types(tab)
{}

void ArgumentType::visiteArgument(IArgumentVisitor &v) const
{
    v.visiteArgument(*this);
}

std::size_t ArgumentType::size() const noexcept
{
    return m_types.size();
}

AbstractDataType ArgumentType::at(std::size_t i) const
{
    return m_types.at(i);
}
