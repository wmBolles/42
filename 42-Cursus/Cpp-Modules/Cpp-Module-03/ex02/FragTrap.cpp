
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Parameterised Constructor Called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap& rhs) : ClapTrap(rhs)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap&   FragTrap::operator=(FragTrap& rhs)
{
    if (this != &rhs) 
    {
        ClapTrap::operator=(rhs); // Call base class assignment operator
        std::cout << "FragTrap Assignment Operator Called" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap()
{

    std::cout << "FragTrap Destructor Called" << std::endl;
}


void        FragTrap::highFivesGuys(void)
{
     std::cout << "Can i get a high five 👋" << std::endl;
}