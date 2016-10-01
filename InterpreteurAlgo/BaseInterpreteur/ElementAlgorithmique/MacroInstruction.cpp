#include "MacroInstruction.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

void MacroInstruction::setCppCode(const std::string &CppCode) noexcept
{
    m_CppCode = CppCode;
}

void MacroInstruction::ToCppCode(ostream &out)
{
    out << string(Indentation*4, ' ') << m_CppCode << ";\n";
}
