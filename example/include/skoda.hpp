#pragma once

#include "car.hpp"

class Skoda : public Car
{
public:
    Skoda();
    virtual ~Skoda();
    virtual void drive() const override;
};