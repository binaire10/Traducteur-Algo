#pragma once
#include <unordered_map>
#include <string>
#include <typeindex>
#include <list>
#include <utility>
#include <MyParse/LexicalParseur.h>
#include <MyParse/WordParse.h>
#include "Fonction.h"
#include "VariablePrototype.h"
#include "gestionairemacrocode.h"
#include "struccore.h"
#include "BaseLoop.h"

class GestionnaireInstruction;
bool MyWord(const char &Value) noexcept;
bool MySymbole(const char &Value) noexcept;
bool LoopFaire(const StringRef &cmd) noexcept;
bool LoopFFaire(const StringRef &cmd) noexcept;
bool OpenBlock(const StringRef &cmd) noexcept;
bool CloseBlock(const StringRef &cmd) noexcept;
bool NoOpenClose(const StringRef &) noexcept;
bool CloseLoop(const StringRef &cmd) noexcept;
bool CloseBLoop(const StringRef &cmd) noexcept;
bool CloseIf(const StringRef &cmd) noexcept;

namespace ElementAlgorithmique
{
    class LecteurCode
    {
    public:
        LecteurCode() noexcept;
        LecteurCode(const LecteurCode &) = delete;
        LecteurCode &operator =(const LecteurCode &) = delete;
        virtual ~LecteurCode() noexcept;

        void readCode(std::list<std::pair<unsigned, StringRef> > &CodeLine);
        void ToCppCode(std::ostream &os);
        void execute();

        void InstructionDecodeur(binaire::LexicalParseur &GlobalParseur, binaire::SmartPtr<InstructionBlock> &impl, StringRef InstructionName, Fonction *currentFonc, BaseLoop *currentLoop);
        void ConstruireArgument(binaire::LexicalParseur &ArgumentParseur, std::list< binaire::SmartPtr<Expression> > &FonctionArgument);

        binaire::SmartPtr<Expression> resolve(binaire::LexicalParseur &ParseExpression);

        // Suivit des priorité operatoir telle que decrit ici http://fr.cppreference.com/w/cpp/language/operator_precedence

        binaire::SmartPtr<Expression> analyserPriorite1(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite2(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite3(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite4(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite5(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite6(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite7(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite8(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserPriorite9(binaire::LexicalParseur &ParseExpression);
        binaire::SmartPtr<Expression> analyserOperation(binaire::LexicalParseur &ParseExpression);


        template<bool(&AnalyseBlockDebut)(const StringRef &), bool(&SortieBlock)(const StringRef &)>
        inline void analyseImplementation(binaire::LexicalParseur &parseur, binaire::SmartPtr<InstructionBlock> &impl, Fonction *currentFonc, BaseLoop *currentLoop)
        {
            StringRef command;
            m_VariableContexte.push_back(std::list<VariablePrototype *>());

            parseur.setSource(m_i->second);
            if(!AnalyseBlockDebut(parseur.getCurrent()))
                throw std::runtime_error("Unautorized openning block at " + std::to_string(m_i->first+1));

            ++m_i;
            if(m_i == m_CodeLine->cend())
                throw std::runtime_error("Missing End Block");

            while(true)
            {
                parseur.setSource(m_i->second);
                command = parseur.getCurrent();
                if(SortieBlock(command))
                {
                    m_VariableContexte.pop_back();
                    break;
                }
                else if(binaire::WordParse::equal(command, "//") || binaire::WordParse::equal(command, "/*"))
                    continue;
                InstructionDecodeur(parseur, impl, command, currentFonc, currentLoop);
                if(m_i == m_CodeLine->cend())
                    throw std::runtime_error("Missing End Block");
                ++m_i;
                if(m_i == m_CodeLine->cend())
                    throw std::runtime_error("Missing End Block");
            }
        }
        const std::list<std::list<ElementAlgorithmique::VariablePrototype *> > &VariableContexte() const;

    private:
        std::unordered_map<std::string, std::type_index> m_localType = {
            {"string", typeid(std::string)},
            {"entier", typeid(int64_t)},
            {"caractere", typeid(char)},
            {"entier_naturel", typeid(unsigned)},
            {"reel", typeid(double)},
            {"booleen", typeid(bool)}
        };
        std::list< std::list<ElementAlgorithmique::VariablePrototype *> > m_VariableContexte = {};
        std::list<ElementAlgorithmique::Fonction *> m_fonctionList = {};
        std::list<ElementAlgorithmique::mainInfo> m_Program = {};
        InstructionAvance::GestionaireMacroCode m_Gestionaire = {};
        GestionnaireInstruction *m_InstructionGest;
        std::list<std::pair<unsigned, StringRef> >::const_iterator m_i;
        std::list<std::pair<unsigned, StringRef> > *m_CodeLine;

    public:
        class InstructionGenerator
        {
        public:
            inline InstructionGenerator(ElementAlgorithmique::LecteurCode *code) noexcept : m_Instance(code)
            {}
            InstructionGenerator() = delete;
            InstructionGenerator(const InstructionGenerator &) = delete;
            InstructionGenerator &operator =(const InstructionGenerator &) = delete;

            virtual ~InstructionGenerator() = default;
            virtual bool valideInstruction(const StringRef &) const noexcept = 0;
            virtual void buildInstructionFromAlgo(const StringRef &InstructionName, binaire::LexicalParseur &GlobalParseur, binaire::SmartPtr<ElementAlgorithmique::InstructionBlock> &impl, ElementAlgorithmique::Fonction *currentFonc, ElementAlgorithmique::BaseLoop *currentLoop) = 0;
            void NextLine();
            const std::pair<unsigned, StringRef> &GetLine();

        protected:
            std::list<std::list<VariablePrototype *> > &getVariableEnv();
            std::unordered_map<std::string, std::type_index> &getTypeArray();
            ElementAlgorithmique::LecteurCode *m_Instance;
        };

        void setCodeLine(std::list<std::pair<unsigned, StringRef> > *CodeLine);
    };
}
