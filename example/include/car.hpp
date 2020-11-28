#pragma once

class Car
{
public:
    virtual ~Car() {}
    virtual void drive() const = 0;
};