#include "InvalidExpression.h"
#include "TraductorException.h"

const char *TraductorException::what() const noexcept
{
    return m_msg.c_str();
}

size_t TraductorException::line() const
{
    return m_line;
}

const std::string &TraductorException::file() const
{
    return m_file;
}

TraductorException::TraductorException(const std::string &msg) noexcept : m_msg(msg)
{}

TraductorException::TraductorException(std::size_t line, const std::string &file, const std::string &msg) noexcept : m_line(line), m_file(file), m_msg(msg)
{}

TraductorException::TraductorException(size_t line, const std::string &file, const TraductorException &upgrade) noexcept : m_line(line), m_file(file), m_msg(upgrade.m_msg)
{}
