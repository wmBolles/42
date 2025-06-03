#include "ClapTrap.hpp"

int     main(void)
{
    // Default
    // ClapTrap    unknown;

    // unknown.attack("another one");
    // unknown.takeDamage(10);

    ClapTrap    redx("redx");

    redx.attack("lferda");
    redx.takeDamage(9);
    redx.attack("lferda");
    redx.beRepaired(5);
    redx.takeDamage(6);
    
    // ClapTrap    redx_clone = redx;
    
    // redx_clone.attack("lferda");


    // ClapTrap    noenergy("l3yan");

    // for (int i = 0; i < 11; i++)
    //     noenergy.attack("lferda");
}