#include "LecteurCode.h"
#include <MyValidator/MyValidator.hpp>
#include <algorithm>
#include "struccore.h"
#include "ExpressionToInstruction.h"
#include "Expression.h"
#include <MyParse/SymboleParse.h>
#include <MyParse/LimitedSequenceParse.h>
#include "Multiplication.h"
#include "Sum.h"
#include "EtLogique.h"
#include "EtBinaire.h"
#include "OuLogique.h"
#include "OuBinaire.h"
#include "Division.h"
#include "FonctionCall.h"
#include "ArrayAcess.h"
#include "CVariable.h"
#include "CValue.h"
#include "NotEqual.h"
#include "Equal.h"
#include "Soustract.h"
#include "LessThan.h"
#include "Affectation.h"
#include "NegationBool.h"
#include "ForceExpression.h"
#include "LessOrEqualThan.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;
using namespace InstructionAvance;


void LecteurCode::ConstruireArgument(LexicalParseur &ArgumentParseur, list<SmartPtr<Expression> > &FonctionArgument)
{
    LexicalParseur ExpressionParseur(ArgumentParseur);
    StringRef Argument;

    while(!ArgumentParseur.AtEnd())
    {
        // On lit le premier argument
        Argument = ArgumentParseur.getCurrent();

        // On vas jusqu'à la fin du premier argument
        // le but est de connaître l'interval ou se trouve les arguments pour le passer par la suite à l'analyse d'expression
        while(*ArgumentParseur.getCurrent().first != ',' && !ArgumentParseur.AtEnd())
            ArgumentParseur.Next();

        // on eviter le cas ou il y un seul terme dans l'expression
        if(Argument != ArgumentParseur.getCurrent())
        {
            Argument.second = ArgumentParseur.getCurrent().first;
            ArgumentParseur.Next();
        }

        // On vas utilisé notre parseur de chaine pour sequencer notre expression
        ExpressionParseur.setSource(Argument);

        // On contstruit puis ajoute notre nouvelle argument à notre appel de fonction
        FonctionArgument.push_back(analyserOperation(ExpressionParseur));
    }
}

SmartPtr<Expression> LecteurCode::resolve(LexicalParseur &ParseExpression)
{
    StringRef Facteur = ParseExpression.getCurrent();
    ParseExpression.Next();

    // On cherche à identifier si c'est une sous Expression
    if(*Facteur.first == '(')
    {
        if(*(Facteur.second-1)!=')')
            throw runtime_error("Sous expression incomplet");

        // on elimine les parentése parasite
        ++Facteur.first;
        --Facteur.second;

        LexicalParseur ParseSousExpression(ParseExpression);
        ParseSousExpression.setSource(Facteur);

        // On renvoie un objet contenant notre objet avec les expressions Forcer
        return make_SmartPtr(new ForceExpression(analyserOperation(ParseSousExpression)));
    }

    // On cherche à identifier c'est le Facteur est une variable qui existe
    if(findVar(m_VariableContexte, Facteur) != nullptr)
    {
        StringRef VariableElementI = ParseExpression.getCurrent();
        // On verrifie si il y a tentative d'accéder à l'élement suivant
        if(*VariableElementI.first == '[' || *(VariableElementI.second - 1) == ']')
        {
            ParseExpression.Next();
            ++VariableElementI.first;
            --VariableElementI.second;

            LexicalParseur ParseIElement(ParseExpression);

            ParseIElement.setSource(VariableElementI);

            // On renvoie une expression qui permet d'accéder à l'élement
            return make_SmartPtr(new ArrayAccess(findVar(m_VariableContexte, Facteur), analyserOperation(ParseIElement)));
        }
        // Par défaut on renvoie la variable
        return make_SmartPtr(new CVariable(findVar(m_VariableContexte, Facteur)));
    }
    //On cherche à identifier si la Facteur est une fonction
    else if(findFonction(m_fonctionList, Facteur) != nullptr)
    {
        StringRef ArgumentFonction = ParseExpression.getCurrent();

        // On valide la présentce d'argument
        if(ArgumentFonction.first == ArgumentFonction.second || *ArgumentFonction.first != '(' || *(ArgumentFonction.second - 1) != ')')
            throw runtime_error("Argument Manquant à l'appel de la fonction " + buildString(Facteur));

        ++ArgumentFonction.first;
        --ArgumentFonction.second;

        // On verifie s'il y a des argument
        if(ArgumentFonction.first != ArgumentFonction.second)
        {
            LexicalParseur ParseArgument(ParseExpression);
            ParseArgument.setSource(ArgumentFonction);

            // On recupére les argument
            list< SmartPtr<Expression> > sArg;
            ConstruireArgument(ParseArgument, sArg);

            // on recherche la fonction avec un profile précis
            Fonction *res(findFonction(m_fonctionList, Facteur, sArg));
            if(res != nullptr)
            {
                ParseExpression.Next();
                // si on la trouve on renvoie l'expression applicable
                return make_SmartPtr(new FonctionCall(res, sArg));
            }
            else
                throw runtime_error("Prototype de la fonction " + buildString(Facteur) +"  Introuvable");
        }
        else
            // S'il n'y en a pas on vas au plus vite
            return make_SmartPtr(new FonctionCall(findFonction(m_fonctionList, Facteur), list< SmartPtr<Expression> >()));
    }

    // si on identifie le facteur comme étant
    if(isNumber(Facteur.first, Facteur.second))
    {
        return make_SmartPtr(new CValue<unsigned>(stoul(buildString(Facteur))));
    }
    // sur un mal entendue c'est condition est fausse
    else if(*Facteur.first == '-' && isNumber(Facteur.first+1, Facteur.second))
    {
        return make_SmartPtr(new CValue<int64_t>(stoll(buildString(Facteur))));
    }
    // si la valeur est un réel
    else if(isDecimalNumber(Facteur.first, Facteur.second))
    {
        return make_SmartPtr(new CValue<double>(stod(buildString(Facteur))));
    }
    // si la valeur est une chaine
    else if(*Facteur.first == '"' && *(Facteur.second-1) == '"')
    {
        ++Facteur.first;
        --Facteur.second;
        return make_SmartPtr(new CValue<string>(buildString(Facteur)));
    }
    // si la valeur est un char
    else if(*Facteur.first == '\'' && *(Facteur.second-1) == '\'')
    {
        if(*(Facteur.first+1) == '\\')
        {
            switch (*(Facteur.first+2))
            {
            case 'n':
                return make_SmartPtr(new CValue<char>('\n'));
            case 't':
                return make_SmartPtr(new CValue<char>('\t'));
            case 'r':
                return make_SmartPtr(new CValue<char>('\r'));
            default:
                return make_SmartPtr(new CValue<char>(*(Facteur.first+2)));
                break;
            }
        }
        else
            return make_SmartPtr(new CValue<char>(*(Facteur.first+1)));
    }
    // si se sont des valeurs booléen
    else if(WordParse::equal(Facteur, "vrai") || WordParse::equal(Facteur, "faux"))
    {
        return make_SmartPtr(new CValue<bool>(WordParse::equal(Facteur, "vrai")));
    }
    // si c'est une negation d'expression
    else if(WordParse::equal(Facteur, "NON"))
    {
        StringRef ExpressionInverser(ParseExpression.getCurrent());

        // On va essayer de recupérer tout l'expression ou on applique la negation pour ensuite faire un traitement à part

        ParseExpression.Next();

        if(findFonction(m_fonctionList, ExpressionInverser) != nullptr)
        {
            ExpressionInverser.second = ParseExpression.getCurrent().second;
            ParseExpression.Next();
        }

        LexicalParseur ParseSousExpression(ParseExpression);
        ParseSousExpression.setSource(ExpressionInverser);

        return make_SmartPtr(new NegationBool(analyserOperation(ParseSousExpression)));
    }
    else if(m_Gestionaire.existMacro(Facteur))
    {
        StringRef ArgumentFonction = ParseExpression.getCurrent();

        // On valide la présentce d'argument
        if(ArgumentFonction.first == ArgumentFonction.second || *ArgumentFonction.first != '(' || *(ArgumentFonction.second - 1) != ')')
            throw runtime_error("Argument Manquant à l'appel de la fonction " + buildString(Facteur));

        ++ArgumentFonction.first;
        --ArgumentFonction.second;

        // On verifie s'il y a des argument
        if(ArgumentFonction.first != ArgumentFonction.second)
        {
            LexicalParseur ParseArgument(ParseExpression);
            ParseArgument.setSource(ArgumentFonction);

            // On recupére les argument
            list< SmartPtr<Expression> > sArg;
            ConstruireArgument(ParseArgument, sArg);

            ParseExpression.Next();
            // si on la trouve on renvoie l'expression applicable
            return m_Gestionaire.getMacro(Facteur, sArg)->dupliqueFonction(sArg);
        }
        else
            // S'il n'y en a pas on vas au plus vite
            return m_Gestionaire.getMacro(Facteur, list< SmartPtr<Expression> >())->dupliqueFonction(list< SmartPtr<Expression> >());
    }
    else
    {
        // ici on vas cherché à construire des fonction dynamique appeler mais pas encore existant donc non trouver
        // le shemat est identique de l'un à l'autre
        // on identifie le profil manquant
        // on crée le profile
        throw runtime_error("Symbole '" + buildString(Facteur) +"' Non identifié veuillez verifié votre expression");

    }
}

SmartPtr<Expression> LecteurCode::analyserPriorite1(LexicalParseur &ParseExpression)
{
    // On identifie le Symbole de l'expression
    SmartPtr<Expression> result = resolve(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(!ParseExpression.AtEnd())
    {
        if(WordParse::equal(Op, "*"))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new Multiplication(result, resolve(ParseExpression)));
        }
        else if(WordParse::equal(Op, "/"))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new Division(result, resolve(ParseExpression)));
        }
        else
            break;
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite2(LexicalParseur &ParseExpression)
{
    StringRef Op = ParseExpression.getCurrent();
    SmartPtr<Expression> result;

    // resolution du signe
    if(WordParse::equal(Op, "-" ))
    {
        ParseExpression.Next();
        result = make_SmartPtr(new Soustract(make_SmartPtr(new CValue<int64_t>(0LL)), analyserPriorite1(ParseExpression)));
    }
    else
        result = analyserPriorite1(ParseExpression);
    Op = ParseExpression.getCurrent();


    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(!ParseExpression.AtEnd())
    {
        if(WordParse::equal(Op, "+" ))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new Sum(result, analyserPriorite1(ParseExpression)));
        }
        else if(WordParse::equal(Op, "-" ))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new Soustract(result, analyserPriorite1(ParseExpression)));
        }
        else
            break;
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite3(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite2(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(!ParseExpression.AtEnd())
    {
        if(WordParse::equal(Op, "<"))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new LessThan(result, analyserPriorite2(ParseExpression)));
        }
        else if(WordParse::equal(Op, ">"))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new LessThan(analyserPriorite2(ParseExpression), result));
        }
        else if(WordParse::equal(Op, "<="))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new LessOrEqualThan(result, analyserPriorite2(ParseExpression)));
        }
        else if(WordParse::equal(Op, ">="))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new LessOrEqualThan(analyserPriorite2(ParseExpression), result));
        }
        else
            break;

        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite4(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite3(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(!ParseExpression.AtEnd())
    {
        if(WordParse::equal(Op, "vaut"))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new Equal(result, analyserPriorite3(ParseExpression)));
        }
        else if(WordParse::equal(Op, "ne_vaut_pas"))
        {
            ParseExpression.Next();
            result = make_SmartPtr(new NotEqual(result, analyserPriorite3(ParseExpression)));
        }
        else
            break;
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite5(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite4(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(WordParse::equal(Op, "ET")  && !ParseExpression.AtEnd())
    {
        ParseExpression.Next();
        result = make_SmartPtr(new EtBinaire(result, analyserPriorite4(ParseExpression)));
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite6(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite5(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(WordParse::equal(Op, "OU")  && !ParseExpression.AtEnd())
    {
        ParseExpression.Next();
        result = make_SmartPtr(new OuBinaire(result, analyserPriorite5(ParseExpression)));
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite7(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite6(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    // Tant que on est pas au dernier mots lue soit ';' on continue
    // de toute maniére il n'est pas traitable à ce niveau
    while(WordParse::equal(Op, "ET_ALORS") && !ParseExpression.AtEnd())
    {
        ParseExpression.Next();
        result = make_SmartPtr(new EtLogique(result, analyserPriorite6(ParseExpression)));
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite8(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite7(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    while(WordParse::equal(Op, "OU_SINON")  && !ParseExpression.AtEnd())
    {
        ParseExpression.Next();
        result = make_SmartPtr(new OuLogique(result, analyserPriorite7(ParseExpression)));
        Op = ParseExpression.getCurrent();
    }
    return result;
}

SmartPtr<Expression> LecteurCode::analyserPriorite9(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite8(ParseExpression);

    StringRef Op = ParseExpression.getCurrent();

    while(WordParse::equal(Op, "<-")  && !ParseExpression.AtEnd())
    {
        ParseExpression.Next();
        result = make_SmartPtr(new Affectation(result, analyserPriorite8(ParseExpression)));
        Op = ParseExpression.getCurrent();
    }
    return result;
}

binaire::SmartPtr<Expression> LecteurCode::analyserOperation(LexicalParseur &ParseExpression)
{
    SmartPtr<Expression> result = analyserPriorite9(ParseExpression);

    return result;
}
