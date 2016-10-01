#include "ArrayAcess.h"
//#include "ArrayPrototype.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

ArrayAccess::ArrayAccess(VariablePrototype *const &Value, const binaire::SmartPtr<Expression> &i) : Expression(Value->getVarTypeStructure()), m_var(Value), i(i)
{
    if(m_Type.getArrayLevel() == 0 && m_Type.getType() == typeid(std::string))
        m_Type.setType_Index(typeid(char));
    else
        m_Type.setArrayLevel(m_Type.getArrayLevel()-1);
    m_Type.setSize(0);
}

void ArrayAccess::ToCppCode(ostream &os)
{
    os << m_var->getName() << '[';
    i->ToCppCode(os);
    os << ']';
}

bool ArrayAccess::isFinalValue()
{
    return false;
}

/*
binaire::SmartPtr<void> ArrayAccess::Execute(EnvGlobal &Contexte)
{
    if(m_Type.getArrayLevel()==1)
    {
        binaire::SmartPtr<ArrayPrototype> array(Contexte.getVar(m_var));
        if(i->getTypeIndex().getType() == typeid(int64_t))
        {
            binaire::SmartPtr<int64_t> indice(i->Execute(Contexte));
            if(m_Type.getArrayLevel() == 1)
                return *static_cast< SmartPtr<void> *>(array->getValue(*indice));
        }
        else if(i->getTypeIndex().getType() == typeid(unsigned))
        {
            binaire::SmartPtr<unsigned> indice(i->Execute(Contexte));
            if(m_Type.getArrayLevel() == 1)
                return *static_cast< SmartPtr<void> *>(array->getValue(*indice));
        }
        else if(i->getTypeIndex().getType() == typeid(char))
        {
            binaire::SmartPtr<char> indice(i->Execute(Contexte));
            if(m_Type.getArrayLevel() == 1)
                return *static_cast< SmartPtr<void> *>(array->getValue(*indice));
        }
        else if(i->getTypeIndex().getType() == typeid(bool))
        {
            binaire::SmartPtr<bool> indice(i->Execute(Contexte));
            if(m_Type.getArrayLevel() == 1)
                return *static_cast< SmartPtr<void> *>(array->getValue(*indice));
        }
    }
    else
    {
        throw runtime_error("MultiArray not supported");
    }
    throw runtime_error("Case Missing Source Code Error");

}
*/
