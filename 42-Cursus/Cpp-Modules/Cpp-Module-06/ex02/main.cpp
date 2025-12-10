#include "Base.hpp"
#include <stdint.h>
#include <stdlib.h>


int			main(void)
{
	Base	*rand = generate();
	
	identify(rand);
	identify(*rand);
	
	delete rand;
}