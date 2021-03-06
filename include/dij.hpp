#pragma once

#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

class dij
{
public:
    dij() = delete;
    dij(const dij &) = delete;
    virtual ~dij() = default;

    template <typename Interface, typename Implementation, typename... Args>
    static void Register(Args &&... args)
    {
        instances()[typeid(Interface)] = std::make_shared<Implementation>(std::forward<Args>(args)...);
    }

    template <typename Interface>
    static Interface &Resolve()
    {
        if (instances().find(typeid(Interface)) == instances().end())
        {
            throw std::runtime_error(std::string("No instance registered for type: ") + typeid(Interface).name());
        }
        return *(std::static_pointer_cast<Interface>(instances()[typeid(Interface)]));
    }

private:
    static std::unordered_map<std::type_index, std::shared_ptr<void>> &instances();
};