#pragma once
#include <ostream>
#include <MyMemory/SmartPtr.hpp>
#include <list>
#include "VariablePrototype.h"
#include "Expression.h"
#include "InstructionBlock.h"


namespace ElementAlgorithmique
{
    /**
     * @brief The Fonction class
     * Permet de crée un objet de type fonction qui contient du code sous forme d'instruction
     */
    class Fonction
    {
    public:
        Fonction() = default;
        virtual ~Fonction() = default;
        Fonction(const std::string &Name) noexcept;
        /**
         * @brief GetInput
         * permet d'accéder au variable d'entrée de la fonction et d'en ajouter
         * @return
         */
        std::list<VariablePrototype> &GetInput();
        /**
         * @brief getImplementation
         * permet d'accéder au block d'instruction
         * @return
         */
        binaire::SmartPtr<InstructionBlock> &getImplementation();
        /**
         * @brief GetOutput
         * Permet d'accéder au type de retour de la fonction
         * @return
         */
        VarType &GetOutput();
        /**
         * @brief GetName
         * Permet d'accéder au Nom de la fonction
         * @return
         */
        std::string &GetName();
        /**
         * @brief ArgumenntAllow
         * Demande à la fonction si elle accepte i argument
         * @param i
         * Nombre d'argument
         * @return
         */
        virtual bool ArgumenntAllow(unsigned i) const;

        /**
         * @brief Validate
         * Demande à la fonction si elle supporte se genre d'argument en entré
         * @param ExpresionArgument
         * @return
         */
        virtual bool Validate(const std::list< binaire::SmartPtr<Expression> > &ExpresionArgument);
        virtual bool Validate(const std::list< VariablePrototype > &ExpresionArgument);
    private:
        std::string Name;
        std::list<VariablePrototype> Input = std::list<VariablePrototype>();
        binaire::SmartPtr<InstructionBlock> Implementation;
        VarType Output = VarType(false, false, 0, typeid(void), 0u);
    };

    struct mainInfo
    {
        binaire::SmartPtr<InstructionBlock> &getImplementation();
        std::string Name;
        binaire::SmartPtr<InstructionBlock> Implementation;
    };
}
