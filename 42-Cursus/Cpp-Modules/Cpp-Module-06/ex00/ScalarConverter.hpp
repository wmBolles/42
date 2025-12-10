#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>
#include <string>
#include <stdexcept>
#include <exception>

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConverter
{
	private:
	    ScalarConverter();
	    ScalarConverter(const ScalarConverter& right);
	    ScalarConverter& operator=(const ScalarConverter& right);
	    ~ScalarConverter();
	
	public:
	    static void convert(const std::string& str);
};