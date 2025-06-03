#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}
Cat&   Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat Copy Assignment Constructor Called" << std::endl;
    Animal::operator=(rhs);
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << this->type << ": Meow Meow" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}