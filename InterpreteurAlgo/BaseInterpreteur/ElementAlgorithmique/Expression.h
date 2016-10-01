#pragma once
#include <ostream>
#include "VariablePrototype.h"
#include <MyMemory/SmartPtr.h>
//#include "EnvGlobal.h"

namespace ElementAlgorithmique
{
    /**
     * @brief The Expression class
     * Objet mére de tout les expression Algorithmique
     */
    class Expression
    {
    public:
        Expression() = default;
        Expression(const Expression &) = default;
        Expression &operator =(const Expression &) = default;
        Expression(const VarType &type) noexcept;
        virtual ~Expression() = default;

        //virtual binaire::SmartPtr<void> Execute(EnvGlobal &) = 0;

        /**
         * @brief ToCppCode
         * Permet de traduire l'expression en c++
         * @param os
         * Sortie du code
         */
        virtual void ToCppCode(std::ostream &os) = 0;

        /**
         * @brief getType
         * Permet de récupérer le type d'expression
         * @return
         */
        const VarType &getTypeIndex() const;
        /**
         * @brief setType
         * Permet de modifier le type de l'expression
         * @param value
         */
        void setType(const VarType &value);
        virtual bool isFinalValue() = 0;

    protected:
        /**
         * @brief Type
         * Variable Contenant le type d'expression (une fois executer quel est le type de retour)
         */
        VarType m_Type = VarType(false, false, 0, typeid(void), 0u);
    };
}
