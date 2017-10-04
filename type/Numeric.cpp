#include "Numeric.h"
#include "Numeric_p.h"
#include <map>
#include "../interface/ICommonTypeVisitor.h"


Numeric::Numeric(Numeric::Type type) : CommonScalar(std::make_shared<Numeric_p>(sizeofType(type), std::hash<std::string>()("Numeric")^ (std::hash<std::size_t>()(sizeofType(type))<<1), type))
{}

std::shared_ptr<Numeric> Numeric::getInstance(Numeric::Type t)
{
    static std::map<Type, std::shared_ptr<Numeric>> instance;
    using iterator = std::map<Type, std::shared_ptr<Numeric>>::iterator;
    iterator it = instance.find(t);
    if(it != instance.end())
        return it->second;

    instance.insert({t, std::make_shared<Numeric>(Numeric(t))});
    return instance.at(t);
}

void Numeric::visiteCommonType(ICommonTypeVisitor &visitor) const
{
    visitor.visiteType(*this);
}

bool Numeric::equals(const ICommonType &value) const noexcept
{
    const Numeric *p = dynamic_cast<const Numeric *>(&value);
    return (p && p->getData()->type() == getData()->type()) || value.hashType() == hashType();
}

Numeric::Type Numeric::type() const
{
    return getData()->type();
}

Numeric::Numeric(const std::shared_ptr<Numeric_p> &ptr) : CommonScalar(ptr)
{}

std::string Numeric::name() const noexcept
{
    return "Numeric[" + std::to_string(static_cast<std::underlying_type<Numeric::Type>::type>(getData()->type())) + "]";
}
