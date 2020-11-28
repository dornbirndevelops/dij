#pragma once

#include "animal.hpp"
#include "car.hpp"

class Person
{
public:
    Person();
    virtual ~Person();
    void petAnimal();
    void driveCar();

private:
    Animal &m_animal;
    Car &m_car;
};