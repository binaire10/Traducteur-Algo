#include "Boolean.h"
#include "../interface/ICommonAbstractDataVisitor.h"

Boolean::Boolean() : CommonScalar(1, std::hash<std::string>()("Boolean"))
{}

std::shared_ptr<Boolean> Boolean::getInstance() noexcept
{
    static std::shared_ptr<Boolean> instance = std::make_shared<Boolean>(Boolean());
    return instance;
}

void Boolean::visiteCommonType(ICommonAbstractDataVisitor &v) const
{
    v.visiteType(*this);
}

std::string Boolean::name() const noexcept
{
    return "Boolean";
}

bool Boolean::equals(const ICommonAbstractData &v) const noexcept
{
    return this == &v || dynamic_cast<const Boolean *>(&v) || v.hashType() == hashType();
}
