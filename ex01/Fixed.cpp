#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	raw = 0;
}

Fixed::Fixed(const int n) : raw(n << fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : raw(roundf(n * (1 << fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	raw = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return raw;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

int		Fixed::toInt( void ) const
{
	return (raw >> fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)raw / (1 << fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
