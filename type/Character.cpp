#include "Character.h"
#include "../interface/ICommonTypeVisitor.h"

Character::Character() : CommonScalar(1, std::hash<std::string>()("Character"))
{}

void Character::visiteCommonType(ICommonTypeVisitor &visitor) const
{
    visitor.visiteType(*this);
}

bool Character::equals(const ICommonType &v) const noexcept
{
    return this == &v || dynamic_cast<const Character *>(&v) || v.hashType() == hashType();
}


std::string Character::name() const noexcept
{
    return "Character";
}

std::shared_ptr<Character> Character::getInstance() noexcept
{
    static std::shared_ptr<Character> instance = std::make_shared<Character>(Character());
    return instance;
}
