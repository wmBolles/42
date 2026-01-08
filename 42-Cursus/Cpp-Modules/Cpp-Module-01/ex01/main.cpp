#include "Zombie.hpp"

int	main(void)
{
	int N = 999999999;

	try {
    	Zombie *z = zombieHorde(N, "Foo");
    	if (!z) return 1;
    	for (int i= 0 ; i < N; i++)
    		z[i].announce();
    
    	delete [] z;
	}
	catch (std::bad_alloc &tacos_only)
	{
	    std::cout << "Nice Try , Better luck next time !" << std::endl;
	}
}
