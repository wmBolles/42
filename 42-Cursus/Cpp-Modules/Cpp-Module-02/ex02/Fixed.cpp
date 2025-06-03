#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const Fixed& rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->fixed_point = rhs.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = (integer << this->fractional_bits);
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(number * (1 << this->fractional_bits));
}

float Fixed::toFloat( void ) const
{
    return (float)this->fixed_point / (1 << this->fractional_bits);
}

int Fixed::toInt( void ) const
{
    return (this->fixed_point >> this->fractional_bits);
}

std::ostream&  operator<<(std::ostream& t, const Fixed& rhs)
{
    t << rhs.toFloat();
    return t;
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return (this->fixed_point > rhs.fixed_point);
}
bool Fixed::operator<(const Fixed& rhs) const
{
    return (this->fixed_point < rhs.fixed_point);
}
bool Fixed::operator>=(const Fixed& rhs) const
{
    return (this->fixed_point >= rhs.fixed_point);
}
bool Fixed::operator<=(const Fixed& rhs) const
{
    return (this->fixed_point <= rhs.fixed_point);
}
bool Fixed::operator==(const Fixed& rhs) const
{
    return (this->fixed_point == rhs.fixed_point);
}
bool Fixed::operator!=(const Fixed& rhs) const
{
    return (this->fixed_point != rhs.fixed_point);
}


Fixed   Fixed::operator+(const Fixed &rhs) const
{
    return this->toFloat() + rhs.toFloat();
}
Fixed   Fixed::operator-(const Fixed &rhs) const
{
    return this->toFloat() - rhs.toFloat();
}

Fixed   Fixed::operator*(const Fixed &rhs) const
{
    return this->toFloat() * rhs.toFloat();
}
Fixed   Fixed::operator/(const Fixed &rhs) const
{
    return this->toFloat() / rhs.toFloat();
}

Fixed&  Fixed::operator++()
{
    this->fixed_point++;
    return *this;
}
Fixed&  Fixed::operator--()
{
    this->fixed_point--;
    return *this;
}

Fixed  Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed  Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}


Fixed&  Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
