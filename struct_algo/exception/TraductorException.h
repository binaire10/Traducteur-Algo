#ifndef TRADUCTEUR_ALGO_TRADUCTOREXCEPTION_H
#define TRADUCTEUR_ALGO_TRADUCTOREXCEPTION_H

#include <exception>
#include <string>

class TraductorException : public std::exception
{
public:
    size_t line() const;
    const std::string &file() const;
    const char *what() const noexcept override;

protected:
    TraductorException(const std::string &msg) noexcept;
    TraductorException(std::size_t line, const std::string &file, const std::string &msg) noexcept;
    TraductorException(size_t line, const std::string &file, const TraductorException &upgrade) noexcept;

private:
    std::size_t m_line;
    std::string m_file;
    std::string m_msg;
};

#endif //TRADUCTEUR_ALGO_TRADUCTOREXCEPTION_H
