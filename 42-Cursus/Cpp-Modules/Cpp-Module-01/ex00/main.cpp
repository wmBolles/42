#include "Zombie.hpp"

int		main(void)
{
	Zombie*	ins = newZombie("Foo");
	ins->announce();

	delete ins;
	randomChump("FOO2");
}