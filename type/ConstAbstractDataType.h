#ifndef CONSTABSTRACTDATATYPE_H
#define CONSTABSTRACTDATATYPE_H

#include "memory"
#include "AbstractDataType.h"

class ConstAbstractDataType : public AbstractDataType
{
public:
    ConstAbstractDataType(const std::shared_ptr<AbstractDataType> &internalType);
    bool equals(const AbstractDataType &) const noexcept override;
    bool isConvertible(const AbstractDataType &) const noexcept override;
    void visiteType(AbstractDataTypeVisitor &) const override;
    std::shared_ptr<AbstractDataType> internalType() const noexcept;

private:
    std::shared_ptr<AbstractDataType> m_internalType;
};

#endif // CONSTABSTRACTDATATYPE_H
