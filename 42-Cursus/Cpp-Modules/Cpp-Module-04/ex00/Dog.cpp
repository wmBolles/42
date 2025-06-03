#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}
Dog&   Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog Copy Assignment Constructor Called" << std::endl;
    Animal::operator=(rhs);
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << this->type << ": Woaf Woaf" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}