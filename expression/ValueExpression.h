#ifndef VALUEEXPRESSION_H
#define VALUEEXPRESSION_H

#include "../interface/IExpression.h"

template<typename T>
class ValueExpression : public IExpression
{
public:
    constexpr ValueExpression(T value) noexcept;
    void visiteExpression(IExpressionVisitor &) const override;
    AbstractDataType result() const override;

private:
    T m_value;
};

template<typename>
struct ValueExpression_check
{
    using fail = AbstractDataType;
};

template<typename T>
typename ValueExpression_check<T>::fail make_typeExpression() = delete;

template<>
struct ValueExpression_check<char>
{
    using typeC = AbstractDataType;
};

template<>
struct ValueExpression_check<unsigned>
{
    using typeU = AbstractDataType;
};

template<>
struct ValueExpression_check<long long>
{
    using typeLL = AbstractDataType;
};

template<>
struct ValueExpression_check<double>
{
    using typeD = AbstractDataType;
};

//template<>
//struct ValueExpression_check<short>
//{
//    using typeS = Type;
//};

//template<>
//struct ValueExpression_check<unsigned short>
//{
//    using typeUS = Type;
//};

//template<>
//struct ValueExpression_check<int>
//{
//    using typeI = Type;
//};

//template<>
//struct ValueExpression_check<unsigned long long>
//{
//    using typeULL = Type;
//};

//template<>
//struct ValueExpression_check<float>
//{
//    using typeF = Type;
//};

//template<>
//struct ValueExpression_check<std::string>
//{
//    using typeString = Type;
//};

#include "ValueExpression.tpp"

#endif // VALUEEXPRESSION_H
