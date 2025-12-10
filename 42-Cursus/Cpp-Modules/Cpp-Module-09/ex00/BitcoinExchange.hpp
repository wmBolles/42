#pragma once

# include <string>
# include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#ifndef DEBUG
# define DEBUG 0
#endif

class BitcoinExchange
{
	private:
		std::map<std::string, float> db;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &right);
		BitcoinExchange &operator=(BitcoinExchange const &right);
		~BitcoinExchange();

		bool		isValidDate(std::string const &date) const;
		bool		isValidValue(std::string const &value, float &val) const;
		std::string	strtrim(std::string const &str) const;
		float		get_rate(std::string const &date) const;
		void		fill_db(std::string const &filename);
		void		parse(std::string const &filename);
};
