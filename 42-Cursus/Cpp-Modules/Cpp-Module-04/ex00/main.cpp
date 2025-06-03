#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // To Invoke everything in Orthodox Canonical Form,
    // Animal  def;
    // Animal  param("type");
    // Animal  copy(param);
    // Animal  copy2 = copy;
    // Animal  a,b;
    // a = b;

    // Dog  def;
    // Dog  param("type");
    // Dog  copy(param);
    // Dog  copy2 = copy;
    // Dog  a,b;
    // a = b;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    const WrongAnimal* o = new WrongCat(); 
    std::cout << o->getType() << " " << std::endl;
    o->makeSound(); //will output the Animal sound!
    return 0;
}