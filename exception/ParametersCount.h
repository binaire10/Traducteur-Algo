#ifndef TRADUCTEUR_ALGO_PARAMETERSCOUNT_H
#define TRADUCTEUR_ALGO_PARAMETERSCOUNT_H

#include "TraductorException.h"

class ParametersCount : public TraductorException
{
public:
    ParametersCount(const std::string &msg);
    ParametersCount(size_t line, const std::string &file, const std::string &msg);
    ParametersCount(size_t line, const std::string &file, const ParametersCount &upgrade);
};

#endif //TRADUCTEUR_ALGO_PARAMETERSCOUNT_H
