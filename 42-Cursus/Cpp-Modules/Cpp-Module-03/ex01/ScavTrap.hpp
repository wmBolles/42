#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(ScavTrap& rhs);
        ScavTrap(std::string name);
        ScavTrap&   operator=(ScavTrap& rhs);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};