#include "skoda.hpp"
#include <iostream>

Skoda::Skoda()
{
    std::cout << "Skoda ctor" << std::endl;
}
Skoda::~Skoda()
{
    std::cout << "Skoda dtor" << std::endl;
}
void Skoda::drive() const
{
    std::cout << "Brumm" << std::endl;
}