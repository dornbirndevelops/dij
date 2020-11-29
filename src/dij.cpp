#include "dij.hpp"

std::unordered_map<std::type_index, std::shared_ptr<void>> &dij::instances()
{
    static std::unordered_map<std::type_index, std::shared_ptr<void>> singleton;
    return singleton;
}
