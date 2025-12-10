#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc filename" << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	btc.fill_db("data.csv");
	btc.parse(av[1]);

	return (0);
}
