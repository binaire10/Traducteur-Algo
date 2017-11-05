#ifndef TRADUCTEUR_ALGO_TRADUCTEURALGO_H
#define TRADUCTEUR_ALGO_TRADUCTEURALGO_H


#include <memory>
#include "ModuleTraduction.h"

class TraducteurAlgo
{
public:
    void addModule(const std::shared_ptr<ModuleTraduction> &) noexcept;
};


#endif //TRADUCTEUR_ALGO_TRADUCTEURALGO_H
