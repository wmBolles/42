#include "easyfind.hpp"
#include <vector>

int		main(void)
{
	std::vector<int> thef;
	thef.push_back(2);
	thef.push_back(-1);
	thef.push_back(1337);
	thef.push_back('a');
	
	
	short where = easyfind(thef, 'a');
	std::cout << where << std::endl;
	
	try
	{
		where = easyfind(thef, 3301);
	}
	catch (std::out_of_range &base) {
		std::cout << base.what() << std::endl;
	}
	
	std::vector<char> chrs;
	chrs.push_back('a');
	chrs.push_back('c');
	
	where = easyfind(chrs, 'a');
	std::cout << static_cast<char>(where) << std::endl;
}