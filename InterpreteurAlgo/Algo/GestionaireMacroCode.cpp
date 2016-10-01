#include "gestionairemacrocode.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace InstructionAvance;

GestionaireMacroCode::~GestionaireMacroCode() noexcept
{
    for(const FonctionMacro * const value : m_AllMacro)
        delete value;
}

bool GestionaireMacroCode::existMacro(const string &Name)
{
    for(const FonctionMacro * const &value : m_AllMacro)
        if(value->ValideName(Name))
            return true;
    return false;
}

bool GestionaireMacroCode::existMacro(const StringRef &Name)
{
    for(const FonctionMacro * const &value : m_AllMacro)
        if(value->ValideName(Name))
            return true;
    return false;
}

FonctionMacro *GestionaireMacroCode::getMacro(const string &Name, const std::list<binaire::SmartPtr<Expression> > &exp)
{
    for(FonctionMacro * const &value : m_AllMacro)
        if(value->ValideName(Name) && value->ValideInput(exp))
            return value;
    throw runtime_error("Macro Implementation Not Found");
}

FonctionMacro *GestionaireMacroCode::getMacro(const StringRef &Name, const std::list<binaire::SmartPtr<Expression> > &exp)
{
    for(FonctionMacro * const &value : m_AllMacro)
        if(value->ValideName(Name) && value->ValideInput(exp))
            return value;
    throw runtime_error("Macro Implementation Not Found");
}

void GestionaireMacroCode::addMacro(FonctionMacro *macro) noexcept
{
    m_AllMacro.push_back(macro);
}
