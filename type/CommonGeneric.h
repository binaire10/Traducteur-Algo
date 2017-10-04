#ifndef COMMONGENERIC_H
#define COMMONGENERIC_H

#include "CommonAbstractData.h"

class CommonGeneric : public CommonAbstractData
{
public:
    CommonGeneric();
    void visiteCommonType(ICommonTypeVisitor &) const override;
    std::string name() const noexcept override;
    std::size_t hashType() const noexcept override;
    bool equals(const ICommonType &) const noexcept override;
    bool convertible(const ICommonType &) const noexcept override;
    std::size_t size() const noexcept override;
    bool hasOperand(const IOperator &, const IArguments &) const noexcept override;

private:
    std::list<std::shared_ptr<ICommonType>> m_generic;
};

#endif // COMMONGENERIC_H
