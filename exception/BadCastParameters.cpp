#include "BadCastParameters.h"

BadCastParameters::BadCastParameters(size_t line, const std::string &file, const std::string &msg) : TraductorException(line, file, msg)
{}

BadCastParameters::BadCastParameters(const std::string &msg) : TraductorException(msg)
{}
