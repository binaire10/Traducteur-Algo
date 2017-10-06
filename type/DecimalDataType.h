#ifndef DECIMALDATATYPE_H
#define DECIMALDATATYPE_H

#include "ScalarDataType.h"
#include <memory>

class DecimalDataType : public ScalarDataType
{
public:
    bool equals(const AbstractDataType &) const noexcept override;
    static std::shared_ptr<DecimalDataType> getInstance() noexcept;
    void visiteType(AbstractDataTypeVisitor &) const override;

protected:
    DecimalDataType();
};

#endif // DECIMALDATATYPE_H
