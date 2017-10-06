#ifndef IABSTRACTDATATYPEVISITOR_H
#define IABSTRACTDATATYPEVISITOR_H

class Character;
class NumericDataType;
class DecimalDataType;
class AbstractDataTypeVisitor
{
public:
    AbstractDataTypeVisitor() noexcept = default;
    virtual void visiteType(const DecimalDataType &) = undefined;
    virtual void visiteType(const NumericDataType &) = undefined;
    virtual void visiteType(const Character &) = undefined;
};

#endif // IABSTRACTDATATYPEVISITOR_H
