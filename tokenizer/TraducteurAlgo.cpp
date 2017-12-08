#include "TraducteurAlgo.h"

void TraducteurAlgo::addModule(const std::shared_ptr<ModuleTraduction> &def) noexcept
{
    m_module.push_back(def);
}
