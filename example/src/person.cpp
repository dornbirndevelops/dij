#include "person.hpp"

#include <dij.hpp>
#include <iostream>

Person::Person()
    : m_animal(dij::Resolve<Animal>()), m_car(dij::Resolve<Car>()) {
        std::cout << "Person ctor" << std::endl;
    }

Person::~Person() {
    std::cout << "Person dtor" << std::endl;
}

void Person::petAnimal()
{
    m_animal.sound();
}

void Person::driveCar()
{
    m_car.drive();
}