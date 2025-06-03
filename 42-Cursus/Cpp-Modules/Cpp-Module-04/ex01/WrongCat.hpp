#pragma once

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat  : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& rhs);
        WrongCat&   operator=(const WrongCat& rhs);
        ~WrongCat();
        void   makeSound() const;
};