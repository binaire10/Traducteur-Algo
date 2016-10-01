#include "VariablePrototype.h"

using namespace std;
//using namespace binaire;
using namespace ElementAlgorithmique;

VarType::VarType(bool isRefVar, bool isConst, unsigned ArrayLevel, const type_index &Type, unsigned Size) noexcept : m_ArrayLevel(ArrayLevel), m_Type(Type), m_VariableType(false), m_Size(Size), m_isRefVar(isRefVar), m_isConst(isConst), m_ValueType(UNKNOWN)
{
    if(Type == typeid(string))
        m_ValueType = STRING;
    else if(Type == typeid(int64_t))
        m_ValueType = INT;
    else if(Type == typeid(unsigned))
        m_ValueType = UNSIGNED;
    else if(Type == typeid(char))
        m_ValueType = CHAR;
    else if(Type == typeid(double))
        m_ValueType = DOUBLE;
    if(ArrayLevel != 0u)
        m_ValueType |= ARRAYS;
}

VarType::VarType(bool isRefVar, bool isConst, unsigned ArrayLevel, const type_index &Type, VariablePrototype *Var) noexcept : m_ArrayLevel(ArrayLevel), m_Type(Type), m_VariableType(true), m_Var(Var), m_isRefVar(isRefVar), m_isConst(isConst), m_ValueType(UNKNOWN)
{}

bool VarType::getIsConst() const noexcept
{
    return m_isConst;
}

void VarType::setIsConst(bool isConst) noexcept
{
    m_isConst = isConst;
}

bool VarType::getIsRefVar() const noexcept
{
    return m_isRefVar;
}

void VarType::setIsRefVar(bool isRefVar) noexcept
{
    m_isRefVar = isRefVar;
}

bool VarType::getVariableType() const noexcept
{
    return m_VariableType;
}

const VariablePrototype *VarType::getVar() const noexcept
{
    return m_Var;
}

void VarType::setVar(VariablePrototype *value) noexcept
{
    m_VariableType = true;
    m_Var = value;
}

bool VarType::operator ==(const VarType &output) const noexcept
{
    return output.m_ArrayLevel == m_ArrayLevel && m_Type == output.m_Type;
}

VarType::ValueType VarType::getValueType() const
{
    return m_ValueType;
}

unsigned &VarType::getSize() noexcept
{
    return m_Size;
}

VariablePrototype *VarType::getVar() noexcept
{
    return m_Var;
}

void VarType::setSize(unsigned value) noexcept
{
    m_VariableType = false;
    m_Size = value;
}

std::type_index VarType::getType() const noexcept
{
    return m_Type;
}

void VarType::setType_Index(const std::type_index &Type) noexcept
{
    m_Type = Type;

    if(Type == typeid(string))
        m_ValueType = STRING;
    else if(Type == typeid(int))
        m_ValueType = INT;
    else if(Type == typeid(unsigned))
        m_ValueType = UNSIGNED;
    else if(Type == typeid(char))
        m_ValueType = CHAR;
    else if(Type == typeid(double))
        m_ValueType = DOUBLE;
}

const unsigned &VarType::getArrayLevel() const noexcept
{
    return m_ArrayLevel;
}

void VarType::setArrayLevel(unsigned value) noexcept
{
    m_ArrayLevel = value;

    if(m_ArrayLevel != 0)
        m_ValueType |= ARRAYS;
    else
        m_ValueType &= !ARRAYS;
}

VariablePrototype::VariablePrototype(const string &Name, bool isConst, bool isRefVar, const VarType &vType) noexcept : m_sType(vType), m_Name(Name)
{
    m_sType.setIsConst(isConst);
    m_sType.setIsRefVar(isRefVar);
}

VariablePrototype::VariablePrototype(const string &Name, bool isConst, bool isRefVar, unsigned ArrayLevel, const type_index &Type, unsigned Size) noexcept : m_sType(isRefVar, isConst, ArrayLevel, Type, Size), m_Name(Name)
{}

VariablePrototype::VariablePrototype(const string &Name, bool isConst, bool isRefVar, unsigned ArrayLevel, const type_index &Type, VariablePrototype *Var) noexcept : m_sType(isRefVar, isConst, ArrayLevel, Type, Var), m_Name(Name)
{}

const std::string &VariablePrototype::getName() const noexcept
{
    return m_Name;
}

void VariablePrototype::setName(const std::string &value) noexcept
{
    m_Name = value;
}

VarType &VariablePrototype::getVarTypeStructure() noexcept
{
    return m_sType;
}

const VarType &VariablePrototype::getVarTypeStructure() const noexcept
{
    return m_sType;
}
