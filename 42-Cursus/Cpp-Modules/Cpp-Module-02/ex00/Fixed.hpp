#pragma once

#include <iostream>

class Fixed
{
    private:
        int     fixed_point;
        static  int const fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& rhs);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};