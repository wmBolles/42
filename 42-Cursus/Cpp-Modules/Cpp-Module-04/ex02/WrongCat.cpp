#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}
WrongCat&   WrongCat::operator=(const WrongCat& rhs)
{
    std::cout << "WrongCat Copy Assignment Constructor Called" << std::endl;
    WrongAnimal::operator=(rhs);
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << this->type << ": Meow Meow" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}