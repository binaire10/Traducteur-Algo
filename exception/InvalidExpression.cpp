#include "InvalidExpression.h"

InvalidExpression::InvalidExpression(size_t line, const std::string &file, const std::string &msg) : TraductorException(line, file, msg)
{}

InvalidExpression::InvalidExpression(const std::string &msg) : TraductorException(msg)
{}
