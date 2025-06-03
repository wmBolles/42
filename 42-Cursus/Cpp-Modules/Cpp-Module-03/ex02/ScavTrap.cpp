
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Parameterised Constructor Called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap& rhs) : ClapTrap(rhs)
{
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}
ScavTrap&   ScavTrap::operator=(ScavTrap& rhs)
{
    if (this != &rhs) 
    {
        ClapTrap::operator=(rhs); // Call base class assignment operator
        std::cout << "ScavTrap Assignment Operator Called" << std::endl;
    }
    return *this;
}
ScavTrap::~ScavTrap() {

    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_points == 0 || this->hit_points <= 0)
    {
        std::cout << "ScavTrap " << this->name << " Has No energy_points/hit_points To Attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << " , " << "causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--; // Attacking and repairing each cost 1 energy point
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}