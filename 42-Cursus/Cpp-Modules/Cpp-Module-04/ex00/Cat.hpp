#pragma once

#include "Animal.hpp"
#include <iostream>

class Cat  : public Animal
{
    public:
        Cat();
        Cat(const Cat& rhs);
        Cat&   operator=(const Cat& rhs);
        ~Cat();
        void   makeSound() const;
};