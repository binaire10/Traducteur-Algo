#ifndef TRADUCTEUR_ALGO_BADCASTPARAMETERS_H
#define TRADUCTEUR_ALGO_BADCASTPARAMETERS_H

#include "TraductorException.h"

class BadCastParameters : public TraductorException
{
public:
    BadCastParameters(const std::string &msg);
    BadCastParameters(size_t line, const std::string &file, const std::string &msg);
};

#endif //TRADUCTEUR_ALGO_BADCASTPARAMETERS_H
