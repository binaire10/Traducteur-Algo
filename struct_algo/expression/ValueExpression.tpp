#ifndef VALUEEXPRESSION_TPP
#define VALUEEXPRESSION_TPP

#include "ValueExpression.h"
#include "../interface/IExpressionVisitor.h"
#include "../type/DecimalDataType.h"
#include "../type/NumericDataType.h"
#include "../type/Character.h"

template<typename T>
inline typename ValueExpression_check<T>::typeLL make_typeExpression()
{
    return NumericDataType::getInstance(NumericDataType::Type::LongLong);
}

template<typename T>
inline typename ValueExpression_check<T>::typeU make_typeExpression()
{
    return NumericDataType::getInstance(NumericDataType::Type::Unsigned);
}

template<typename T>
inline typename ValueExpression_check<T>::typeD make_typeExpression()
{
    return NumericDataType::getInstance(NumericDataType::Type::Double);
}

template<typename T>
inline typename ValueExpression_check<T>::typeC make_typeExpression()
{
    return Character::getInstance();
}

//template<typename T>
//inline typename ValueExpression_check<T>::typeI make_typeExpression()
//{
//    return Type(Numeric::getInstance(Numeric::Type::Int));
//}

//template<typename T>
//inline typename ValueExpression_check<T>::typeS make_typeExpression()
//{
//    return Type(Numeric::getInstance(Numeric::Type::Short));
//}

//template<typename T>
//inline typename ValueExpression_check<T>::typeUS make_typeExpression()
//{
//    return Type(Numeric::getInstance(Numeric::Type::Unsigned_Short));
//}

//template<typename T>
//inline typename ValueExpression_check<T>::typeF make_typeExpression()
//{
//    return Type(Numeric::getInstance(Numeric::Type::Float));
//}

template<typename T>
constexpr ValueExpression<T>::ValueExpression(T value) noexcept : m_value(value)
{}

template<typename T>
void ValueExpression<T>::visiteExpression(IExpressionVisitor &v) const
{
    v.visiteExpression(*this);
}

template<typename T>
std::shared_ptr<AbstractDataType> ValueExpression<T>::result() const
{
    return make_typeExpression<T>();
}

template<typename T>
Expressionable::value_cast ValueExpression<T>::resultValueCast() const noexcept
{
    return Expressionable::prvalue;
}


#endif // VALUEEXPRESSION_TPP