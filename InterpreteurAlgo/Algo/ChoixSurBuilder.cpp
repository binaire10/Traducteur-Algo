#include "ChoixSurBuilder.h"
#include "ConditionIf.h"
#include "CVariable.h"
#include "Equal.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace InstructionAvance;
using namespace MathExpression;

/**
        "choix_sur variable_de_choix entre\n"
        "  cas Valeur_1 :\n"
        "      Sequence_1;\n"
        "\n"
        "  cas Valeur_2 :\n"
        "      Sequence_2;\n"
        "\n"
        "  cas Valeur_n :\n"
        "      Sequence_n;\n"
        "\n"
        "  autre :\n"
        "      TraitementAutre;\n"
        "fchoix"
        "\n"**/

bool LoopFChoix(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "cas") || WordParse::equal(cmd, "fchoix");
}


ChoixSurBuilder::ChoixSurBuilder(LecteurCode *code) : InstructionGenerator(code)
{}

bool ChoixSurBuilder::valideInstruction(const StringRef &InstructionName) const noexcept
{
    return WordParse::equal(InstructionName, "choix_sur");
}

void ChoixSurBuilder::buildInstructionFromAlgo(const StringRef &InstructionName, LexicalParseur &GlobalParseur, SmartPtr<InstructionBlock> &impl, Fonction *currentFonc, BaseLoop *currentLoop)
{
    StringRef Buffer;
    if(WordParse::equal(InstructionName, "choix_sur"))
    {
        Buffer = GlobalParseur.getCurrent();
        GlobalParseur.Next();

        VariablePrototype *VarTested(findVar(this->getVariableEnv(), Buffer));
        SmartPtr<CVariable> CurrentVar(new CVariable(VarTested));

        if(VarTested == nullptr)
            throw runtime_error("choix_sur doit être appliqué sur une variable");

        if(!WordParse::equal(GlobalParseur.getCurrent(), "entre"))
            throw runtime_error("mot clé 'entre' attendue");
        GlobalParseur.Next();
        if(!GlobalParseur.AtEnd())
            throw runtime_error("Aucune instruction attendue");

        NextLine();
        GlobalParseur.setSource(GetLine().second);

        if(!WordParse::equal(GlobalParseur.getCurrent(), "cas"))
            throw runtime_error("mot clé 'cas' attendue");
        GlobalParseur.Next();

        Buffer = GlobalParseur.getCurrent();
        GlobalParseur.Next();

        if(!WordParse::equal(GlobalParseur.getCurrent(), ":"))
            throw runtime_error("seule les valeurs sont autorisée");
        GlobalParseur.setOutput(Buffer);

        ConditionIf *currentIf;
        SmartPtr<InstructionBlock> ifImpl(currentIf = new ConditionIf(make_SmartPtr(new Equal(CurrentVar, m_Instance->resolve(GlobalParseur)))));
        impl->getInstructionList().push_back(ifImpl);

        while (true)
        {
            m_Instance->analyseImplementation<NoOpenClose, LoopFChoix>(GlobalParseur, ifImpl, currentFonc, currentLoop);

            if(WordParse::equal(GlobalParseur.getCurrent(), "fchoix"))
                break;
            if(!WordParse::equal(GlobalParseur.getCurrent(), "cas"))
                throw runtime_error("mot clé 'cas' attendue");
            GlobalParseur.Next();

            Buffer = GlobalParseur.getCurrent();
            GlobalParseur.Next();

            if(!WordParse::equal(GlobalParseur.getCurrent(), ":"))
                throw runtime_error("seule les valeurs sont autorisée");
            GlobalParseur.setOutput(Buffer);

            ifImpl = SmartPtr<InstructionBlock>(currentIf->ElseIf(make_SmartPtr(new Equal(CurrentVar, m_Instance->resolve(GlobalParseur)))), new SmartPtr<InstructionBlock>::DeleterNothing_t);

        }

    }
    else
        throw runtime_error("Non décodable");
}
