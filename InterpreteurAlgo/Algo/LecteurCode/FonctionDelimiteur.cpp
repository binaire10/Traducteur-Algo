#include "LecteurCode.h"
#include <MyValidator/MyValidator.hpp>
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;
using namespace InstructionAvance;

bool MyWord(const char &Value) noexcept
{
    return binaire::IsInWord(Value) || Value == '_' || Value == '.';
}

bool MySymbole(const char &Value)noexcept
{
    return binaire::IsSymbol(Value) && Value!='_' && Value != '.';
}

bool LoopFaire(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "faire");
}

bool LoopFFaire(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "ffaire");
}

bool OpenBlock(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "debut");
}

bool CloseBlock(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "fin");
}

bool NoOpenClose(const StringRef &) noexcept
{
    return true;
}

bool CloseLoop(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "fboucle");
}

bool CloseBLoop(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "jusqua");
}

bool CloseIf(const StringRef &cmd) noexcept
{
    return WordParse::equal(cmd, "fsi") || WordParse::equal(cmd, "sinon") || WordParse::equal(cmd, "sinon_si");
}
