#pragma once
#include <list>
#include <MyMemory/SmartPtr.h>
#include "VariablePrototype.h"

class ArrayPrototype
{
public:
    typedef std::list<ArrayPrototype> Array_t;
    typedef binaire::SmartPtr<void> Value_t;
    typedef std::list< Value_t > ValueArray_t;

    ArrayPrototype() = default;
    ArrayPrototype(const ElementAlgorithmique::VarType &Input);
    ArrayPrototype(const ArrayPrototype &);
    ArrayPrototype &operator=(const ArrayPrototype &);
    virtual ~ArrayPrototype();

    void resize(unsigned i);
    void *getValue(unsigned i);
    const ElementAlgorithmique::VarType &getType();
    void PrintType();

private:
    ElementAlgorithmique::VarType m_VarType = ElementAlgorithmique::VarType(false, false, 0u, typeid(void), 0u);
    void *m_Value = nullptr;
};
