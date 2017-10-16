#include "ParametersCount.h"

ParametersCount::ParametersCount(size_t line, const std::string &file, const std::string &msg) : TraductorException(line, file, msg)
{}

ParametersCount::ParametersCount(const std::string &msg) : TraductorException(msg)
{}

ParametersCount::ParametersCount(size_t line, const std::string &file, const ParametersCount &upgrade) : TraductorException(line, file, upgrade)
{}
