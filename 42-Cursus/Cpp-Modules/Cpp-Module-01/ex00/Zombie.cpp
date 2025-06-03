#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	this->name = "none";
}

Zombie::~Zombie()
{
	std::cout << this->name << " Has Been Distroyed\n";
}