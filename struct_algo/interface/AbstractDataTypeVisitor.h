#ifndef ABSTRACTDATATYPEVISITOR_H
#define ABSTRACTDATATYPEVISITOR_H

class Character;
class NumericDataType;
class DecimalDataType;
class ConstAbstractDataType;
class AbstractDataTypeReference;
class AbstractDataTypeVisitor
{
public:
    AbstractDataTypeVisitor() noexcept = default;
    virtual void visiteType(const DecimalDataType &) = undefined;
    virtual void visiteType(const NumericDataType &) = undefined;
    virtual void visiteType(const Character &) = undefined;
    virtual void visiteType(const ConstAbstractDataType &) = undefined;
    virtual void visiteType(const AbstractDataTypeReference &) = undefined;
};

#endif // ABSTRACTDATATYPEVISITOR_H
