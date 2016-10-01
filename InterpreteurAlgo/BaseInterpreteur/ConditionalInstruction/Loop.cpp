#include "Loop.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;


void Loop::ToCppCode(ostream &out)
{
    out << string(Indentation * 4, ' ') << "while(true)\n" << string(Indentation * 4, ' ') << "{\n";
    InstructionBlock::ToCppCode(out);
    out << string(Indentation * 4, ' ') << "}\n";
}
