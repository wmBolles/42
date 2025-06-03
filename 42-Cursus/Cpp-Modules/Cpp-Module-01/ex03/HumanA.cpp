#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& wapon) : name(str), weapon(wapon){}

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}