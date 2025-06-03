#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& W)
{
	this->weapon = &W;
}

void HumanB::attack( void )
{
	if (this->weapon == NULL)
		std::cout << this->name << "Has no Weapon to attack with !\n";
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}