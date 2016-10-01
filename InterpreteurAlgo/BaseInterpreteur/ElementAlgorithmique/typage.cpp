#include <typeindex>
#include "struccore.h"
#include <cassert>
#include <iostream>
#include <cxxabi.h>

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

bool xorX(const bool &a, const bool &b)
{
    return (a && !b) || (!a && b);
}

bool VarType::allowType(const ElementAlgorithmique::VarType &ty1)
{
    return ty1.m_Type == typeid(double) || ty1.m_Type == typeid(int64_t) || ty1.m_Type == typeid(unsigned) || ty1.m_Type == typeid(char) || ty1.m_Type == typeid(std::string) || ty1.m_Type == typeid(bool);
}

bool VarType::isTranstypable(const VarType &ty1, const VarType &ty2)
{
//    int     status;
//    cout << abi::__cxa_demangle(ty2.m_Type.name(),0 , 0, &status) << " " << abi::__cxa_demangle(ty1.m_Type.name(),0 , 0, &status) << endl;
    return ty1 == ty2 || (ty1.m_ArrayLevel == 0 && ty1.m_ArrayLevel == ty2.m_ArrayLevel && ((ty1.m_Type != typeid(std::string) || ty2.m_Type != typeid(std::string)) || ((ty1.m_Type == typeid(std::string) && ty2.m_Type == typeid(char)) || (ty1.m_Type == typeid(char) && ty2.m_Type == typeid(std::string)))));
}

VarType VarType::getBestType(const VarType &input, const VarType &output)
{
    assert(allowType(input));
    assert(allowType(output));

    if(input.m_ArrayLevel != 0 || output.m_ArrayLevel != 0)
    {
        if(input == output)
            return VarType(false, false, input.m_ArrayLevel, input.m_Type, 0u);
        else
            throw std::runtime_error("Different array type");
    }

    if(input == output)
        return output;

//    int     status;
//    cout << abi::__cxa_demangle(input.m_Type.name(),0 , 0, &status) << " " << abi::__cxa_demangle(output.m_Type.name(),0 , 0, &status) << endl;

    if(input.m_Type == typeid(double)            && output.m_Type != typeid(std::string))
        return input;
    else if(output.m_Type == typeid(double)      && input.m_Type != typeid(std::string))
        return output;
    else if(input.m_Type == typeid(int64_t)      && output.m_Type != typeid(std::string))
        return input;
    else if(output.m_Type == typeid(int64_t)     && input.m_Type != typeid(std::string))
        return output;
    else if(input.m_Type == typeid(unsigned)     && output.m_Type != typeid(std::string))
        return input;
    else if(output.m_Type == typeid(unsigned)    && input.m_Type != typeid(std::string))
        return output;
    else if(input.m_Type == typeid(char)         && output.m_Type != typeid(std::string))
        return input;
    else if(output.m_Type == typeid(char)        && input.m_Type != typeid(std::string))
        return output;
    else if(output.m_Type == typeid(bool)        && input.m_Type != typeid(std::string))
        return output;
    else if(input.m_Type == typeid(bool)         && output.m_Type != typeid(std::string))
        return input;

    throw std::runtime_error("Different");
}
