#include "Affectation.h"
//#include "ArrayPrototype.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

Affectation::Affectation(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b) : MathExpression::Binaire(a,b)
{}

void Affectation::ToCppCode(ostream &Result)
{
    m_a->ToCppCode(Result);
    Result << " = ";
    m_b->ToCppCode(Result);
}

bool Affectation::isFinalValue()
{
    return false;
}

/*
binaire::SmartPtr<void> Affectation::Execute(EnvGlobal &env)
{
    if(m_a->getTypeIndex() == m_Type && m_b->getTypeIndex() == m_Type)
    {
        if(m_a->getTypeIndex().getArrayLevel() != 0 && m_b->getTypeIndex().getArrayLevel() != 0)
        {
            binaire::SmartPtr<ArrayPrototype> value2(m_b->Execute(env));
            binaire::SmartPtr<ArrayPrototype> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_Type.getType() == typeid(string))
        {
            binaire::SmartPtr<string> value2(m_b->Execute(env));
            binaire::SmartPtr<string> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_Type.getType() == typeid(int64_t))
        {
            binaire::SmartPtr<int64_t> value2(m_b->Execute(env));
            binaire::SmartPtr<int64_t> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_Type.getType() == typeid(char))
        {
            binaire::SmartPtr<char> value2(m_b->Execute(env));
            binaire::SmartPtr<char> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_Type.getType() == typeid(double))
        {
            binaire::SmartPtr<double> value2(m_b->Execute(env));
            binaire::SmartPtr<double> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_Type.getType() == typeid(bool))
        {
            binaire::SmartPtr<bool> value2(m_b->Execute(env));
            binaire::SmartPtr<bool> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else
            throw runtime_error("Type Non transtypable");
    }

    else if(m_a->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(int64_t))
    {
        if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(char))
        {
            binaire::SmartPtr<char> value2(m_b->Execute(env));
            binaire::SmartPtr<int64_t> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(double))
        {
            binaire::SmartPtr<double> value2(m_b->Execute(env));
            binaire::SmartPtr<int64_t> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(bool))
        {
            binaire::SmartPtr<bool> value2(m_b->Execute(env));
            binaire::SmartPtr<int64_t> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else
            throw runtime_error("Type Non transtypable");
    }
    else if(m_a->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(char))
    {
        if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(int64_t))
        {
            binaire::SmartPtr<int64_t> value2(m_b->Execute(env));
            binaire::SmartPtr<char> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(double))
        {
            binaire::SmartPtr<double> value2(m_b->Execute(env));
            binaire::SmartPtr<char> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(bool))
        {
            binaire::SmartPtr<bool> value2(m_b->Execute(env));
            binaire::SmartPtr<char> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else
            throw runtime_error("Type Non transtypable");
    }
    else if(m_a->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(double))
    {
        if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(int64_t))
        {
            binaire::SmartPtr<int64_t> value2(m_b->Execute(env));
            binaire::SmartPtr<double> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(char))
        {
            binaire::SmartPtr<char> value2(m_b->Execute(env));
            binaire::SmartPtr<double> value(m_a->Execute(env));

            *value = *value2;
            return value;}
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(bool))
        {
            binaire::SmartPtr<bool> value2(m_b->Execute(env));
            binaire::SmartPtr<double> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else
            throw runtime_error("Type Non transtypable");
    }
    else if(m_a->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(bool))
    {
        if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(int64_t))
        {
            binaire::SmartPtr<int64_t> value2(m_b->Execute(env));
            binaire::SmartPtr<bool> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(char))
        {
            binaire::SmartPtr<char> value2(m_b->Execute(env));
            binaire::SmartPtr<bool> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else if(m_b->getTypeIndex().getVar()->getVarTypeStructure().getType() == typeid(double))
        {
            binaire::SmartPtr<double> value2(m_b->Execute(env));
            binaire::SmartPtr<bool> value(m_a->Execute(env));

            *value = *value2;
            return value;
        }
        else
            throw runtime_error("Type Non transtypable");
    }
    else
        throw runtime_error("Type Non transtypable");
}*/
