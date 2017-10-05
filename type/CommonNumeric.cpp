#include "CommonNumeric.h"
#include "CommonNumeric_p.h"
#include <map>
#include "../interface/ICommonAbstractDataVisitor.h"


CommonNumeric::CommonNumeric(CommonNumeric::Type type) : CommonScalar(std::make_shared<CommonNumeric_p>(sizeofType(type), std::hash<std::string>()("Numeric")^ (std::hash<std::size_t>()(sizeofType(type))<<1), type))
{}

std::shared_ptr<CommonNumeric> CommonNumeric::getInstance(CommonNumeric::Type t)
{
    static std::map<Type, std::shared_ptr<CommonNumeric>> instance;
    using iterator = std::map<Type, std::shared_ptr<CommonNumeric>>::iterator;
    iterator it = instance.find(t);
    if(it != instance.end())
        return it->second;

    instance.insert({t, std::make_shared<CommonNumeric>(CommonNumeric(t))});
    return instance.at(t);
}

void CommonNumeric::visiteCommonType(ICommonAbstractDataVisitor &visitor) const
{
    visitor.visiteType(*this);
}

bool CommonNumeric::equals(const ICommonAbstractData &value) const noexcept
{
    const CommonNumeric *p = dynamic_cast<const CommonNumeric *>(&value);
    return (p && p->getData()->type() == getData()->type()) || value.hashType() == hashType();
}

CommonNumeric::Type CommonNumeric::type() const
{
    return getData()->type();
}

CommonNumeric::CommonNumeric(const std::shared_ptr<CommonNumeric_p> &ptr) : CommonScalar(ptr)
{}

std::string CommonNumeric::name() const noexcept
{
    return "Numeric[" + std::to_string(static_cast<std::underlying_type<CommonNumeric::Type>::type>(getData()->type())) + "]";
}
