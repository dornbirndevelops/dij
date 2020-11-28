#include <dij.hpp>

#include "animal.hpp"
#include "duck.hpp"
#include "car.hpp"
#include "skoda.hpp"
#include "person.hpp"

int main()
{
    dij::Register<Animal, Duck>();
    dij::Register<Car, Skoda>();

    Person alex;
    alex.petAnimal();
    alex.driveCar();

    return 0;
}