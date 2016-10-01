#include "fonctionmacro.h"

using namespace ElementAlgorithmique;
using namespace InstructionAvance;
using namespace std;
using namespace binaire;

const string &FonctionMacro::Name() const
{
    return m_Name;
}

void FonctionMacro::setName(const string &Name)
{
    m_Name = Name;
}

binaire::SmartPtr<Expression> FonctionMacro::dupliqueFonction(const std::list<binaire::SmartPtr<Expression> > &AExp)
{
    binaire::SmartPtr<FonctionMacro> ptrToMacro(new FonctionMacro(*this));
    if(!ValideInput(AExp))
        throw runtime_error("Invalide input");
    ptrToMacro->m_Arg = AExp;

    return ptrToMacro;
}

void FonctionMacro::setToCpp(const string &ToCpp)
{
    m_ToCpp = ToCpp;
}

bool FonctionMacro::isFinalValue()
{
    return false;
}

list<VarType> &FonctionMacro::TypeContraite()
{
    return m_TypeContraite;
}

FonctionMacro::FonctionMacro(const FonctionMacro &value) : Expression(value), m_Name(value.m_Name), m_ToCpp(value.m_ToCpp), m_Arg(value.m_Arg), m_TypeContraite(value.m_TypeContraite)
{}


bool FonctionMacro::ValideName(const string &Name) const
{
    return m_Name == Name;
}

bool FonctionMacro::ValideName(StringRef value) const
{
    unsigned sizeString(std::distance(value.first, value.second));
    if(sizeString != m_Name.size())
        return false;
    string::const_iterator i(m_Name.cbegin());
    while(value.first != value.second && i != m_Name.cend() && *value.first == *i)
    {
        ++i;
        ++value.first;
    }

    return value.first == value.second;
}

bool FonctionMacro::ValideInput(const list<SmartPtr<Expression> > &exp) const
{
    list<VarType>::const_iterator v(m_TypeContraite.begin());
    for(const SmartPtr<Expression> &i : exp)
    {
        if(!(VarType::isTranstypable(*v, i->getTypeIndex()) || (v->getType() == typeid(AllType_t) && (v->getArrayLevel() == i->getTypeIndex().getArrayLevel() || (v->getArrayLevel() == AnySize && i->getTypeIndex().getArrayLevel() != 0)))))
            return false;
        ++v;
    }
    return true;
}

void FonctionMacro::ToCppCode(ostream &os)
{
    for(string::const_iterator i(m_ToCpp.cbegin()) ; i != m_ToCpp.cend() ; ++i)
    {
        if(*i == '%')
        {
            ++i;
            if(isdigit(*i))
            {
                string::const_iterator beg(i);
                while(i != m_ToCpp.cend() && isdigit(*i))
                    ++i;
                unsigned indice(std::stoul(string(beg, i)));
                list< binaire::SmartPtr<Expression> >::iterator val(m_Arg.begin());
                for(unsigned i(0) ; i <indice ; ++i)
                    ++val;
                val->GetPtr()->ToCppCode(os);
                if(i == m_ToCpp.cend())
                    break;
                --i;
            }
            else if(*i == '%')
                os << '%';
            else
                os << '%' << *i;
        }
        else
            os << *i;
    }
    return;
}

bool FonctionMacroVariadic::ValideInput(const std::list<binaire::SmartPtr<Expression> > &exp) const
{
    list<VarType>::const_iterator v(m_TypeContraite.begin());
    if(m_TypeContraite.size())
        for(const SmartPtr<Expression> &i : exp)
        {
            if(!(VarType::isTranstypable(*v, i->getTypeIndex()) || (v->getType() == typeid(AllType_t) && (v->getArrayLevel() == i->getTypeIndex().getArrayLevel() || (v->getArrayLevel() == AnySize && i->getTypeIndex().getArrayLevel() != 0)))))
                return false;
            ++v;
            if(v == m_TypeContraite.end())
                --v;
        }
    return exp.size() != 0;
}

binaire::SmartPtr<Expression> FonctionMacroVariadic::dupliqueFonction(const std::list<binaire::SmartPtr<Expression> > &AExp)
{
    binaire::SmartPtr<FonctionMacroVariadic> ptr(new FonctionMacroVariadic(*this));
    ptr->m_Arg = AExp;
    return ptr;
}

void FonctionMacroVariadic::ToCppCode(ostream &os)
{
    string symbole("");
    for(string::const_iterator i(m_ToCpp.cbegin()) ; i != m_ToCpp.cend() ; ++i)
    {
        if(*i == '%')
        {
            ++i;
            if(*i == '#')
            {
                for(list< binaire::SmartPtr<Expression> >::iterator val(m_Arg.begin()), validInp(m_Arg.begin()) ; val != m_Arg.end() ; ++val)
                {
                    os << symbole << '(';
                    val->GetPtr()->ToCppCode(os);
                    os << ')';
                }
            }
            else if(*i == '.')
            {
                ++i;
                while(i != m_ToCpp.cend())
                {
                    if(*i == '%')
                    {
                        ++i;
                        if(*i == '/')
                            break;
                        symbole += '%';
                    }
                    symbole += *i;
                    ++i;
                }
            }
            else
                os << '%' << *i;
        }
        else
            os << *i;
    }
    return;
}

FonctionMacroVariadic::FonctionMacroVariadic(const FonctionMacroVariadic &cpy) : FonctionMacro(cpy)
{}
