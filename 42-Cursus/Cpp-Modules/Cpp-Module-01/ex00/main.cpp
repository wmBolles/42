#include "Zombie.hpp"
#include <exception>

int		main(void)
{
    try
    {
        Zombie*	ins = newZombie("NULL");
        ins->announce();
        delete ins;
        
        randomChump(NULL);
    } catch (std::exception &_) {
        std::cout << _.what() << std::endl;
    }
}