#include "ArrayPrototype.h"
#include <stdexcept>
#include <iostream>
#include <cxxabi.h>

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

template<typename Iter_t>
Iter_t getAt(Iter_t beg, const Iter_t &end, unsigned i)
{
    while (beg != end && i != 0)
    {
        ++beg;
        --i;
    }
    return beg;
}

ArrayPrototype::ArrayPrototype(const VarType &Input) : m_VarType(Input), m_Value(nullptr)
{
    if(Input.getArrayLevel() == 0)
        throw runtime_error("Invalid Range");
    if(Input.getArrayLevel() == 1)
        m_Value = static_cast<void *>(new ValueArray_t);
    else
        m_Value = static_cast<void *>(new Array_t);
}

ArrayPrototype::ArrayPrototype(const ArrayPrototype &val) : m_VarType(val.m_VarType)
{
    if(m_VarType.getArrayLevel() == 1)
    {
        m_Value = static_cast<void *>(new ValueArray_t(*static_cast<ValueArray_t *>(val.m_Value)));
    }
    else
    {
        m_Value = static_cast<void *>(new Array_t(*static_cast<Array_t *>(val.m_Value)));
    }
}

ArrayPrototype &ArrayPrototype::operator=(const ArrayPrototype &val)
{
    if(val.m_Value != nullptr)
    {
        if(m_VarType.getArrayLevel() == 1)
            delete static_cast<ValueArray_t *>(m_Value);
        else
            delete static_cast<Array_t *>(m_Value);
        m_Value = nullptr;
    }
    m_VarType = val.m_VarType;

    if(val.m_VarType.getArrayLevel() == 1)
    {
        m_Value = static_cast<void *>(new ValueArray_t(*static_cast<ValueArray_t *>(val.m_Value)));
    }
    else
    {
        m_Value = static_cast<void *>(new Array_t(*static_cast<Array_t *>(val.m_Value)));
    }

    return *this;
}

ArrayPrototype::~ArrayPrototype()
{
    if(m_VarType.getArrayLevel() == 1)
        delete static_cast<ValueArray_t *>(m_Value);
    else
        delete static_cast<Array_t *>(m_Value);
}

void ArrayPrototype::resize(unsigned i)
{
    if(m_VarType.getArrayLevel() == 1)
    {
        static_cast<ValueArray_t *>(m_Value)->resize(i);
        for(Value_t &i : *static_cast<ValueArray_t *>(m_Value))
        {
            if(m_VarType.getType() == typeid(int64_t))
            {
                i = make_SmartPtr(new int64_t);
            }
            else if(m_VarType.getType() == typeid(unsigned))
            {
                i = make_SmartPtr(new unsigned);
            }
            else if(m_VarType.getType() == typeid(char))
            {
                i = make_SmartPtr(new char);
            }
            else if(m_VarType.getType() == typeid(bool))
            {
                i = make_SmartPtr(new bool);
            }
            else if(m_VarType.getType() == typeid(string))
            {
                i = make_SmartPtr(new string);
            }
            else
                throw runtime_error("Type Inconue");
        }
    }
    else
    {
        VarType valType(m_VarType);
        --valType.getSize();
        static_cast<Array_t *>(m_Value)->resize(i);
        if(valType.getArrayLevel() == 1)
        {
            for(ArrayPrototype &Va : *static_cast<Array_t *>(m_Value))
            {
                if(Va.m_Value != nullptr)
                    continue;
                Va.m_VarType = valType;
                Va.m_Value = static_cast<void *>(new ValueArray_t);
            }
        }
        else
        {
            for(ArrayPrototype &Va : *static_cast<Array_t *>(m_Value))
            {
                Va.m_VarType = valType;
                Va.m_Value = static_cast<void *>(new Array_t);
            }
        }
    }
}

void *ArrayPrototype::getValue(unsigned i)
{
    if(m_VarType.getArrayLevel() == 1)
    {
        if(static_cast<ValueArray_t *>(m_Value)->size() <= i)
            throw runtime_error("Invalide Range");
        return static_cast<void *>(&*getAt(static_cast<ValueArray_t *>(m_Value)->begin(), static_cast<ValueArray_t *>(m_Value)->end(), i));
    }
    else
    {
        if(static_cast<Array_t *>(m_Value)->size() <= i)
            throw runtime_error("Invalide Range");
        return static_cast<void *>(&*getAt(static_cast<Array_t *>(m_Value)->begin(), static_cast<Array_t *>(m_Value)->end(), i));
    }
}

const VarType &ArrayPrototype::getType()
{
    return m_VarType;
}

void ArrayPrototype::PrintType()
{
    int     status;
    cout << "ArrayProto["<< abi::__cxa_demangle(typeid(m_Value).name(),0 , 0, &status) << ']' << endl;
}
