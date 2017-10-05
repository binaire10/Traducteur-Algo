#include "TypeParameters.h"
#include "../interface/IParametersVisitor.h"

TypeParameters::TypeParameters()
{}

TypeParameters::TypeParameters(const std::vector<AbstractDataType> &tab) : m_types(tab)
{}

TypeParameters::TypeParameters(const std::initializer_list<AbstractDataType> &tab) : m_types(tab)
{}

void TypeParameters::visiteArgument(IParametersVisitor &v) const
{
    v.visiteArgument(*this);
}

std::size_t TypeParameters::size() const noexcept
{
    return m_types.size();
}

AbstractDataType TypeParameters::at(std::size_t i) const
{
    return m_types.at(i);
}
