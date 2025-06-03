#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
    this->type = "noType";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal Parameterised Constructor Called" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = rhs;
}
WrongAnimal&   WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal Copy Assignment Constructor Called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

const std::string& WrongAnimal::getType() const
{
    return this->type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}