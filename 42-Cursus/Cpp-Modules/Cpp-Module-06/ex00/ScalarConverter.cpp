#include "ScalarConverter.hpp"
#include <cctype>
#include <stdexcept>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& right) { *this = right; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& __attribute__ ((unused)) right)
{
	return *this;
}

static bool isChar(const std::string& str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    if (str.length() == 1 && !std::isdigit(str[0]))
        return true;
    return false;
}

static bool isInt(const std::string& str)
{
    if (str.empty())
        return false;
    
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    if (i >= str.length())
        return false;
    
    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string& str)
{
    if (str.empty())
        return false;
    
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    
    if (str[str.length() - 1] != 'f')
        return false;
    
    std::string withoutF = str.substr(0, str.length() - 1);
    size_t i = 0;
    bool hasDot = false;
    
    if (withoutF[i] == '+' || withoutF[i] == '-')
        i++;
    
    if (i >= withoutF.length())
        return false;
    
    while (i < withoutF.length())
    {
        if (withoutF[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!std::isdigit(withoutF[i]))
            return false;
        i++;
    }
    return hasDot;
}

static bool isDouble(const std::string& str)
{
    if (str.empty())
        return false;
    
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    
    size_t i = 0;
    bool hasDot = false;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    if (i >= str.length())
        return false;
    
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return hasDot;
}

static Type detectType(const std::string& str)
{
    if (isChar(str))
        return CHAR;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    return INVALID;
}

static void printChar(double value, bool isSpecial)
{
    if (isSpecial || std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    
    if (value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    
    char c = static_cast<char>(value);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: non printable" << std::endl;
}

static void printInt(double value, bool isSpecial)
{
    if (isSpecial || std::isnan(value) || std::isinf(value))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value, bool isSpecial, const std::string& original)
{
    if (isSpecial)
    {
        if (original == "nanf" || original == "nan")
            std::cout << "float: nanf" << std::endl;
        else if (original == "+inff" || original == "+inf")
            std::cout << "float: +inff" << std::endl;
        else if (original == "-inff" || original == "-inf")
            std::cout << "float: -inff" << std::endl;
        return;
    }
    
    float f = static_cast<float>(value);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double value, bool isSpecial, const std::string& original)
{
    if (isSpecial)
    {
        if (original == "nanf" || original == "nan")
            std::cout << "double: nan" << std::endl;
        else if (original == "+inff" || original == "+inf")
            std::cout << "double: +inf" << std::endl;
        else if (original == "-inff" || original == "-inf")
            std::cout << "double: -inf" << std::endl;
        return;
    }
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

static void convertFromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl; 
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void convertFromInt(int n)
{
    double d = static_cast<double>(n);
    printChar(d, false);
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void convertFromFloat(float f)
{
    double d = static_cast<double>(f);
    bool isSpecial = std::isnan(f) || std::isinf(f);
    
    printChar(d, isSpecial);
    printInt(d, isSpecial);
    
    std::string check = "";
    if (std::isnan(f))
        check = "nanf";
    else if (std::isinf(f))
        check = (f > 0) ? "+inff" : "-inff";
    
    printFloat(d, isSpecial, check);
    printDouble(d, isSpecial, check);
}

static void convertFromDouble(double d)
{
    bool isSpecial = std::isnan(d) || std::isinf(d);
    
    printChar(d, isSpecial);
    printInt(d, isSpecial);
    
    std::string check = "";
    if (std::isnan(d))
        check = "nan";
    else if (std::isinf(d))
        check = (d > 0) ? "+inf" : "-inf";
    
    printFloat(d, isSpecial, check);
    printDouble(d, isSpecial, check);
}

void ScalarConverter::convert(const std::string& str)
{
    Type type = detectType(str);
    
    if (type == INVALID)
    	throw  (std::runtime_error("Error: Invalid dataType"));

    
    if (type == CHAR)
    {
        char c;
        if (str.length() == 3)
            c = str[1];
        else
            c = str[0];
        convertFromChar(c);
    }
    else if (type == INT)
    {
        long tmp = std::strtol(str.c_str(), NULL, 10);
        if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        int n = static_cast<int>(tmp);
        convertFromInt(n);
    }
    else if (type == FLOAT)
    {
        float f = std::strtof(str.c_str(), NULL);
        convertFromFloat(f);
    }
    else if (type == DOUBLE)
    {
        double d = std::strtod(str.c_str(), NULL);
        convertFromDouble(d);
    }
}
