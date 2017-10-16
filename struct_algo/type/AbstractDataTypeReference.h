#ifndef ABSTRACTDATATYPEREFERENCE_H
#define ABSTRACTDATATYPEREFERENCE_H

#include "memory"
#include "AbstractDataType.h"

class AbstractDataTypeReference : public AbstractDataType
{
public:
    AbstractDataTypeReference(const std::shared_ptr<AbstractDataType> &internalType);
    bool equals(const AbstractDataType &) const noexcept override;
    bool isConvertible(const AbstractDataType &) const noexcept override;
    void visiteType(AbstractDataTypeVisitor &) const override;
    std::shared_ptr<AbstractDataType> internalType() const noexcept;

private:
    std::shared_ptr<AbstractDataType> m_internalType;
};

#endif // ABSTRACTDATATYPEREFERENCE_H
