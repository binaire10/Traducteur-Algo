#ifndef TRADUCTEUR_ALGO_TRADUCTEURALGO_H
#define TRADUCTEUR_ALGO_TRADUCTEURALGO_H

#include <list>
#include <memory>
#include "ModuleTraduction.h"

class TraducteurAlgo
{
public:
    void addModule(const std::shared_ptr<ModuleTraduction> &) noexcept;

private:
    std::list<std::shared_ptr<ModuleTraduction>> m_module;
};

#endif //TRADUCTEUR_ALGO_TRADUCTEURALGO_H
