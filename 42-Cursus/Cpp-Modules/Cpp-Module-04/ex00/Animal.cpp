#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
    this->type = "noType";
}

Animal::Animal(std::string type)
{
    std::cout << "Animal Parameterised Constructor Called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal& rhs)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = rhs;
}
Animal&   Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal Copy Assignment Constructor Called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

const std::string& Animal::getType() const
{
    return this->type;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}