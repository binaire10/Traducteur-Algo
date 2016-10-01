#include "CAgloException.h"

using namespace std;

CAgloException::CAgloException(unsigned Line, const string &reason) : m_Line(Line), m_Error(reason)
{

}

const char *CAgloException::what() const noexcept
{
    out = "'" + m_Error + "' at Line " + to_string(m_Line);
    return out.data();
}

unsigned CAgloException::Line() const
{
    return m_Line;
}
