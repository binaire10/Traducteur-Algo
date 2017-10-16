#ifndef TRADUCTEUR_ALGO_BADMODIFICATOR_H
#define TRADUCTEUR_ALGO_BADMODIFICATOR_H

#include "TraductorException.h"

class BadModificator : public TraductorException
{
public:
    BadModificator(const std::string &msg);
    BadModificator(size_t line, const std::string &file, const std::string &msg);
    BadModificator(size_t line, const std::string &file, const BadModificator &upgrade);
};

#endif //TRADUCTEUR_ALGO_BADMODIFICATOR_H
