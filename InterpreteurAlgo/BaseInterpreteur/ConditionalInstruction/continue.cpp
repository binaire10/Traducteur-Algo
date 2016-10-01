#include "continue.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

Continue::Continue(BaseLoop *loop) : m_Target(loop)
{
    if(m_Target == nullptr)
        throw std::runtime_error("commande non autorisée sans boucle");
}

void Continue::ToCppCode(std::ostream &os)
{
    os << string(Indentation * 4, ' ') << "continue;\n";
}
