#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	(DEBUG) && std::cout << "BitcoinExchange default constructor invoked!" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &right)
{
	(DEBUG) && std::cout << "BitcoinExchange copy constructor invoked!" << std::endl;
	*this = right;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &right)
{
	(DEBUG) && std::cout << "BitcoinExchange copy asseignment invoked!" << std::endl;
	if (this != &right)
		this->db = right.db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	(DEBUG) && std::cout << "BitcoinExchange destructor invoked!" << std::endl;
}


std::string BitcoinExchange::strtrim(std::string const &str) const
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;
	return (str.substr(start, end - start));
}

bool BitcoinExchange::isValidDate(std::string const &date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);

	return (true);
}

bool BitcoinExchange::isValidValue(std::string const &value, float &val) const
{
	char *endptr;
	const char *str = value.c_str();

	val = strtof(str, &endptr);

	if (endptr == str || *endptr != '\0')
		return (false);

	return (true);
}

void BitcoinExchange::fill_db(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: failed open db file !" << std::endl;
		return ;
	}

	std::string		line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t	pos = line.find(',');
		if (pos == std::string::npos)
			continue ;

		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);

		float rateValue = strtof(rate.c_str(), NULL);
		db[date] = rateValue;
	}

	file.close();
}

float BitcoinExchange::get_rate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it = db.find(date);
	if (it != db.end())
		return (it->second);

	it = db.lower_bound("date");
	if (it == db.begin())
    std::cout << it->first << "--->" << it->second << std::endl;
		return (0);
	--it;
	return (it->second);
}

void BitcoinExchange::parse(std::string const &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = strtrim(line.substr(0, pos));
		std::string valueStr = strtrim(line.substr(pos + 1));

		if (!isValidDate(dateStr))
		{
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = get_rate(dateStr);
		float result = value * rate;

		std::cout << dateStr << " => " << value << " = " << result << std::endl;
	}

	file.close();
}
