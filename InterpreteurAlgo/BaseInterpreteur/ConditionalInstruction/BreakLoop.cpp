#include "BreakLoop.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;


BreakLoop::BreakLoop(BaseLoop *current) : m_loop(current)
{
    if(m_loop == nullptr)
        throw std::runtime_error("No loop found");
}

void BreakLoop::ToCppCode(ostream &out)
{
    out << string(Indentation * 4, ' ') << "break;\n";
}
