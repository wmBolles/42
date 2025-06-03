#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int     main(void)
{
    // Polymorphism check 
    FragTrap    obj;
    ClapTrap    *test = &obj;
    test->attack("chi 7ed");

    // // simple check
    // FragTrap    rondaldo("ronaldo");
    // rondaldo.attack("messi");

    FragTrap    highfive;
    highfive.highFivesGuys();

    //  delete problem | override destructor
    // ClapTrap *scv = new FragTrap("frida");
    // FragTrap *scv = new FragTrap("frida");
    // delete scv;

    // ScavTrap c1("frida");
    // c1.x = 100;
    // FragTrap c2("ddd");

    // std::cout << c1.x << std::endl;
    // std::cout << c2.x << std::endl;

}