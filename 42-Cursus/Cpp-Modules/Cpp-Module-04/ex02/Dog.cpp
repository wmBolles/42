#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}


Dog::Dog(const Dog& rhs)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = rhs;
}

Dog&   Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog Copy Assignment Constructor Called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << this->type << ": Woaf Woaf" << std::endl;
}

Dog::~Dog()
{
    delete  this->brain;
    std::cout << "Dog Destructor Called" << std::endl;
}
