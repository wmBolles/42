#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default Constructor Called" << std::endl;
    this->name = "unknown";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Parameterised Constructor Called" << std::endl;
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap& rhs)
{
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
    *this = rhs;
}
ClapTrap&   ClapTrap::operator=(ClapTrap& rhs)
{
    std::cout << "ClapTrap Copy Assignment Constructor Called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_points == 0 || this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " Has No energy_points/hit_points To Attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << " , " << "causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--; // Attacking and repairing each cost 1 energy point
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " Is Already dead" << std::endl;
    }
    else
    {
        this->hit_points -=  amount;
        std::cout << "ClapTrap " << this->name << " Took " << amount << " Of Damage";
        if (this->hit_points <= 0)
            std::cout << " (DeaD) ";
        std::cout << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " Can not be repaired Cuz He Is Already dead" << std::endl;
    }
    else if (this->energy_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " Can not be repaired Cuz he has no energy points left" << std::endl;
    }
    else 
    {
        this->hit_points += amount;
        this->energy_points--;  // Attacking and repairing each cost 1 energy point
        std::cout << "ClapTrap " << this->name << " Has Been Repaired With " << amount << " Amount!" << std::endl;
    }
}