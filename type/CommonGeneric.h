#ifndef COMMONGENERIC_H
#define COMMONGENERIC_H

#include "CommonAbstractData.h"

class CommonGeneric : public CommonAbstractData
{
public:
    CommonGeneric();
    void visiteCommonType(ICommonAbstractDataVisitor &) const override;
    std::string name() const noexcept override;
    std::size_t hashType() const noexcept override;
    bool equals(const ICommonAbstractData &) const noexcept override;
    bool convertible(const ICommonAbstractData &) const noexcept override;
    std::size_t size() const noexcept override;
    bool hasOperand(const IOperator &, const IArguments &) const noexcept override;

private:
    std::list<std::shared_ptr<ICommonAbstractData>> m_generic;
};

#endif // COMMONGENERIC_H
