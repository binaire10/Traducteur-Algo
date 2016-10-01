#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <Expression.h>
#include <MyMemory/SmartPtr.hpp>
#include <MetaTemplate/MetaType.hpp>
#include "struccore.h"

namespace ElementAlgorithmique
{
    namespace InstructionAvance
    {
        class FonctionMacro : public Expression
        {
        public:
            typedef binaire::true_type AllType_t;
            enum{
                AnySize = 42
            };

            FonctionMacro() = default;
            bool ValideName(const std::string &) const;
            bool ValideName(StringRef) const;
            virtual bool ValideInput(const std::list< binaire::SmartPtr<Expression> > &) const;
            void ToCppCode(std::ostream &os) override;
            const std::string &Name() const;
            void setName(const std::string &Name);
            virtual binaire::SmartPtr<Expression> dupliqueFonction(const std::list< binaire::SmartPtr<Expression> > &AExp);
            void setToCpp(const std::string &ToCpp);
            bool isFinalValue() override;

            std::list<VarType> &TypeContraite();

        protected:
            FonctionMacro(const FonctionMacro &);

        private:
            std::string m_Name = {};
        protected:
            std::string m_ToCpp = {};
            std::list< binaire::SmartPtr<Expression> > m_Arg = {};
            std::list<VarType > m_TypeContraite = {};
        };

        class FonctionMacroVariadic : public FonctionMacro
        {
        public:
            typedef binaire::true_type AllType_t;
            enum{
                AnySize = 42
            };

            FonctionMacroVariadic() = default;
            bool ValideInput(const std::list< binaire::SmartPtr<Expression> > &) const override;
            binaire::SmartPtr<Expression> dupliqueFonction(const std::list< binaire::SmartPtr<Expression> > &AExp) override;
            void ToCppCode(std::ostream &os) override;

        protected:
            FonctionMacroVariadic(const FonctionMacroVariadic &);
        };
    }
}
