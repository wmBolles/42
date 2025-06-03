#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int     fixed_point;
        static  int const fractional_bits = 8;
    public:
        Fixed();
        Fixed(const float number);
        Fixed(const int integer);
        Fixed(const Fixed& rhs);
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);