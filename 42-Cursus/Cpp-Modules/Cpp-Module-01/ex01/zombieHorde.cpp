#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1) return NULL;
	Zombie	*ins = new Zombie[N];

	for (int i = 0; i < N; i++)
		ins[i].setName(name);
	return ins;
}
