#include "CommonGeneric.h"

CommonGeneric::CommonGeneric()
{}

void CommonGeneric::visiteCommonType(ICommonAbstractDataVisitor &) const
{}

std::string CommonGeneric::name() const noexcept
{
    std::string str;
    for(const std::shared_ptr<ICommonAbstractData> &i : m_generic)
        str += i->name() + ", ";
    if(str.size())
        str.erase(str.end()-3,str.end());
    return "Generic[" + str + "]";
}

std::size_t CommonGeneric::hashType() const noexcept
{
    std::size_t hashRes = std::hash<std::string>()(name());
    for(const std::shared_ptr<ICommonAbstractData> &i : m_generic)
        hashRes = hashRes ^ (i->hashType()<<1);
    return hashRes;
}

bool CommonGeneric::equals(const ICommonAbstractData &t) const noexcept
{
    for(const std::shared_ptr<ICommonAbstractData> &i : m_generic)
        if(i->equals(t))
            return true;
    return !m_generic.size();
}

bool CommonGeneric::convertible(const ICommonAbstractData &t) const noexcept
{
    for(const std::shared_ptr<ICommonAbstractData> &i : m_generic)
        if(i->convertible(t))
            return true;
    return !m_generic.size();
}

std::size_t CommonGeneric::size() const noexcept
{
    return 0;
}

bool CommonGeneric::hasOperand(const IOperator &t, const IArguments &a) const noexcept
{
    for(const std::shared_ptr<ICommonAbstractData> &i : m_generic)
        if(i->hasOperand(t, a))
            return true;
    return !m_generic.size();
}
