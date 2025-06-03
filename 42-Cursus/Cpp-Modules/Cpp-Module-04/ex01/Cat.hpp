#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat  : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat& rhs);
        Cat&   operator=(const Cat& rhs);
        ~Cat();
        void   makeSound() const;
};