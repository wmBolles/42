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
        
        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;

        Fixed   operator+(const Fixed &rhs) const;
        Fixed   operator-(const Fixed &rhs) const;
        Fixed   operator*(const Fixed &rhs) const;
        Fixed   operator/(const Fixed &rhs) const;

        Fixed&  operator++();
        Fixed&  operator--();
        Fixed  operator++(int d);
        Fixed  operator--(int d);

        static Fixed&  min(Fixed &a, Fixed &b);
        const static Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed&  max(Fixed &a, Fixed &b);
        const static Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& t, const Fixed& rhs);