#include "BadModificator.h"

BadModificator::BadModificator(const std::string &msg) : TraductorException(msg)
{}

BadModificator::BadModificator(size_t line, const std::string &file, const std::string &msg) : TraductorException(line, file, msg)
{}
