#pragma once
#include <stdexcept>

class CAgloException : public std::exception
{
public:
    CAgloException(unsigned Line, const std::string &reason);
    const char *what() const noexcept;
    unsigned Line() const;

private:
    unsigned m_Line;
    std::string m_Error;
    mutable std::string out;
};
