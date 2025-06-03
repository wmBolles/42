#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog  : public Animal
{
    public:
        Dog();
        Dog(const Dog& rhs);
        Dog&   operator=(const Dog& rhs);
        ~Dog();
        void   makeSound() const;
};