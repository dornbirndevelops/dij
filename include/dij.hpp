#pragma once

#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace dij
{
    extern std::unordered_map<std::type_index, std::shared_ptr<void>> instances;

    template <typename Interface, typename Implementation, typename... Args>
    void Register(Args &&... args)
    {
        instances[typeid(Interface)] = std::make_shared<Implementation>(std::forward<Args>(args)...);
    }

    template <typename Interface>
    Interface &Resolve()
    {
        if (instances.find(typeid(Interface)) == instances.end())
        {
            throw std::runtime_error(std::string("No instance registered for type: ") + typeid(Interface).name());
        }
        return *(std::static_pointer_cast<Interface>(instances[typeid(Interface)]));
    }
} // namespace dij