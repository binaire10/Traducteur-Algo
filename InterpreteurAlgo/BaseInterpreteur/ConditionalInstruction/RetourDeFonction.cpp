#include "RetourDeFonction.h"
#include "CoreExpression.h"
#include <stdexcept>
#include <struccore.h>

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

RetourDeFonction::RetourDeFonction(Fonction *block) : m_ValueReturn(false), m_block(block), m_exp()
{
    if(block == nullptr)
        throw std::runtime_error("No Fonction found");
}

RetourDeFonction::RetourDeFonction(Fonction *block, const SmartPtr<Expression> &exp) : m_ValueReturn(true), m_block(block), m_exp(exp)
{
    if(block == nullptr)
        throw std::runtime_error("No Fonction found");

    if(!VarType::isTranstypable(m_exp->getTypeIndex(), block->GetOutput()))
        throw std::runtime_error("No Transtype Allow");
}


void RetourDeFonction::ToCppCode(ostream &out)
{
    out << std::string(Indentation *4,' ') << "return";
    if(m_ValueReturn)
    {
        out << ' ';
        m_exp->ToCppCode(out);
    }
    out << ";\n";
}
