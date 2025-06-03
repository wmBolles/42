#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = rhs;
}
Cat&   Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat Copy Assignment Constructor Called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << this->type << ": Meow Meow" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
    delete  this->brain;   
}