#pragma once

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& rhs);
        WrongAnimal&   operator=(const WrongAnimal& rhs);
        virtual ~WrongAnimal();
        const std::string& getType() const;
        void makeSound() const;
};