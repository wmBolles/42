#pragma once

#include <iostream>

class ClapTrap
{
    protected:
        std::string     name;
        int             hit_points;
        unsigned int    energy_points;
        unsigned int    attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& rhs);
        ClapTrap&   operator=(ClapTrap& rhs);
        virtual ~ClapTrap();
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
