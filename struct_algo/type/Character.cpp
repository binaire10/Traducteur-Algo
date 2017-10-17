#include "Character.h"
#include "../interface/AbstractDataTypeVisitor.h"

Character::Character() : ScalarDataType(ScalarDataType::Type::Char)
{}

bool Character::equals(const AbstractDataType &c) const noexcept
{
    return dynamic_cast<const Character *>(&c);
}

void Character::visiteType(AbstractDataTypeVisitor &v) const
{
    v.visiteType(*this);
}

std::shared_ptr<Character> Character::getInstance() noexcept
{
    static std::shared_ptr<Character> instance = std::make_shared<Character>(Character());
    return instance;
}
