#pragma once

class Animal
{
public:
    virtual ~Animal() {}
    virtual void sound() const = 0;
};