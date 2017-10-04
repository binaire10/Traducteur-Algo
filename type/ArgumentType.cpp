#include "ArgumentType.h"
#include "../interface/IArgumentVisitor.h"

ArgumentType::ArgumentType()
{}

ArgumentType::ArgumentType(const std::vector<Type> &tab) : m_types(tab)
{}

ArgumentType::ArgumentType(const std::initializer_list<Type> &tab) : m_types(tab)
{}

void ArgumentType::visiteArgument(IArgumentVisitor &v) const
{
    v.visiteArgument(*this);
}

std::size_t ArgumentType::size() const noexcept
{
    return m_types.size();
}

Type ArgumentType::at(std::size_t i) const
{
    return m_types.at(i);
}
