#ifndef VALUEEXPRESSION_TPP
#define VALUEEXPRESSION_TPP

#include "ValueExpression.h"
#include "../interface/IExpressionVisitor.h"
#include "../type/Numeric.h"
#include "../type/Character.h"
#include "../type/Boolean.h"

template<typename T>
inline typename ValueExpression_check<T>::typeLL make_typeExpression()
{
    return AbstractDataType(Numeric::getInstance(Numeric::Type::LongLong));
}

template<typename T>
inline typename ValueExpression_check<T>::typeU make_typeExpression()
{
    return AbstractDataType(Numeric::getInstance(Numeric::Type::Unsigned));
}

template<typename T>
inline typename ValueExpression_check<T>::typeD make_typeExpression()
{
    return AbstractDataType(Numeric::getInstance(Numeric::Type::Double));
}

template<typename T>
inline typename ValueExpression_check<T>::typeC make_typeExpression()
{
    return AbstractDataType(Character::getInstance());
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
AbstractDataType ValueExpression<T>::result() const
{
    return make_typeExpression<T>();
}


#endif // VALUEEXPRESSION_TPP
