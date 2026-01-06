#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    long check = N;
    
	if (check > 2147483647 || check < -2147483648 || check < 1) return NULL;
	Zombie	*ins = new Zombie[N];

	for (int i = 0; i < N; i++)
		ins[i].setName(name);
	return ins;
}