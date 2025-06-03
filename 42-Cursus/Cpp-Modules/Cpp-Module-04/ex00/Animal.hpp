#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& rhs);
        Animal&   operator=(const Animal& rhs);
        virtual ~Animal();
        const std::string& getType() const;
        virtual void makeSound() const;
};