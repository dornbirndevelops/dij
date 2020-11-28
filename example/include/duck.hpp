#pragma once

#include "animal.hpp"

class Duck : public Animal
{
public:
    Duck();
    virtual ~Duck();
    virtual void sound() const override;
};