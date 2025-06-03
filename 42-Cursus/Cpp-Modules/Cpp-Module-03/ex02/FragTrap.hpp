#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap :  public ClapTrap
{
    public:
        FragTrap();
        FragTrap(FragTrap& rhs);
        FragTrap(std::string name);
        FragTrap&   operator=(FragTrap& rhs);
        ~FragTrap();
        void highFivesGuys(void);
};
