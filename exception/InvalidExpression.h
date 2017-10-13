#ifndef TRADUCTEUR_ALGO_INVALIDEXPRESSION_H
#define TRADUCTEUR_ALGO_INVALIDEXPRESSION_H

#include "TraductorException.h"

class InvalidExpression : public TraductorException
{
public:
    InvalidExpression(const std::string &msg);
    InvalidExpression(size_t line, const std::string &file, const std::string &msg);
    InvalidExpression(size_t line, const std::string &file, const InvalidExpression &upgrade);
};

#endif //TRADUCTEUR_ALGO_INVALIDEXPRESSION_H
