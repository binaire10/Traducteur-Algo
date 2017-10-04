#ifndef CHARACTER_H
#define CHARACTER_H

#include "CommonScalar.h"

class Character : public CommonScalar
{
public:
    static std::shared_ptr<Character> getInstance() noexcept;
    void visiteCommonType(ICommonAbstractDataVisitor &) const override;
    bool equals(const ICommonAbstractData &) const noexcept override;
    std::string name() const noexcept override;

protected:
    Character();
};



#endif // CHARACTER_H
