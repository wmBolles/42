#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    Animal* animal[10];
    for (int i = 0; i < 5; i++ )
        animal[i] = new Dog();

    for (int i = 5; i < 10; i++ )
        animal[i] = new Cat();

    for (int i = 0; i <  10; i++)
    {
        animal[i]->makeSound();
        delete animal[i];
    }
}


// void    __attribute__ ((destructor)) _end(void)
// {
//     system("leaks deepcopy");
// }