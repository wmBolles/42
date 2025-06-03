#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	ins(name);
	ins.announce();
}