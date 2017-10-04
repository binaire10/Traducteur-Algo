#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "CommonScalar.h"

class Boolean : public CommonScalar
{
public:
    static std::shared_ptr<Boolean> getInstance() noexcept;
    void visiteCommonType(ICommonAbstractDataVisitor &) const override;
    std::string name() const noexcept override;
    bool equals(const ICommonAbstractData &) const noexcept override;
protected:
    Boolean();
};

#endif // BOOLEAN_H
