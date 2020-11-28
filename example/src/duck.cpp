#include "duck.hpp"
#include <iostream>

Duck::Duck()
{
    std::cout << "Duck ctor" << std::endl;
}
Duck::~Duck()
{
    std::cout << "Duck dtor" << std::endl;
}
void Duck::sound() const
{
    std::cout << "Quack" << std::endl;
}