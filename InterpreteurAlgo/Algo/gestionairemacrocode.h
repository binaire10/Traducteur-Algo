#pragma once
#include <list>
#include "fonctionmacro.h"
#include "struccore.h"


namespace ElementAlgorithmique
{
    namespace InstructionAvance
    {
        class GestionaireMacroCode
        {
        public:
            GestionaireMacroCode() = default;
            GestionaireMacroCode(const GestionaireMacroCode &) = delete;
            GestionaireMacroCode &operator =(const GestionaireMacroCode &) = delete;
            virtual ~GestionaireMacroCode() noexcept;

            bool existMacro(const std::string &);
            bool existMacro(const StringRef &);
            FonctionMacro *getMacro(const std::string &, const std::list< binaire::SmartPtr<Expression> > &);
            FonctionMacro *getMacro(const StringRef &, const std::list< binaire::SmartPtr<Expression> > &);
            void addMacro(FonctionMacro *) noexcept;
        private:
            std::list<FonctionMacro *> m_AllMacro = std::list<FonctionMacro *>();
        };
    }
}
