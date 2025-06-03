#include "Zombie.hpp"

int	main(void)
{
	int N = 40;
	Zombie *z = zombieHorde(N, "Foo");
	if (!z) return 1;
	for (int i= 0 ; i < N; i++)
		z[i].announce();

	delete [] z;
}