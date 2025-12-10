#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try {
		if (ac != 2)	throw (std::runtime_error("Usage: ./convert <literal>"));
		else			ScalarConverter::convert(av[1]);
	}
	catch (std::exception &base) {
		std::cout << base.what() << std::endl;
	}
} 
