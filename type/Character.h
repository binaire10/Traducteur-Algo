#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include "ScalarDataType.h"

class Character : public ScalarDataType
{
public:
    bool equals(const AbstractDataType &) const noexcept override;
    void visiteType(AbstractDataTypeVisitor &) const override;
    static std::shared_ptr<Character> getInstance() noexcept;

protected:
    Character();
};

#endif // CHARACTER_H
