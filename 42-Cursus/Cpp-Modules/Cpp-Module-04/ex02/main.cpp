#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    Dog     Boby;
    
    Boby.makeSound();

    Cat     *tom = new Cat();

    tom->makeSound();

    delete tom;

}

// void    __attribute__ ((destructor)) _end(void)
// {
//     system("leaks abstract");
// }