#include "ScavTrap.hpp"

int     main(void)
{
    // Polymorphism check 
    ScavTrap    obj;
    ClapTrap    *test = &obj;
    test->attack("chi 7ed");

    // simple check
    ScavTrap    rondaldo("ronaldo");
    rondaldo.attack("messi");

    //  invoke the derived mehtod
    ScavTrap    guardGate;
    guardGate.guardGate();

    //  delete problem | override destructor
    // ClapTrap *scv = new ScavTrap("frida");
    // ScavTrap *scv = new ScavTrap("frida");
    // delete scv;
}