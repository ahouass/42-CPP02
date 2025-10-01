#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	raw = 0;
}

Fixed::Fixed(const int n) : raw(n << fractional_bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : raw(roundf(n * (1 << fractional_bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	raw = copy.getRawBits();
	return *this;
}

bool Fixed::operator!=( const Fixed& other ) const
{
	if(this->raw != other.raw)
		return 1;
	return 0;
}

bool Fixed::operator==( const Fixed& other ) const
{
	if(this->raw == other.raw)
		return 1;
	return 0;
}

bool Fixed::operator>( const Fixed& other ) const
{
	if(this->raw > other.raw)
		return 1;
	return 0;
}

bool Fixed::operator>=( const Fixed& other ) const
{
	if(this->raw >= other.raw)
		return 1;
	return 0;
}

bool Fixed::operator<( const Fixed& other ) const
{
	if(this->raw < other.raw)
		return 1;
	return 0;
}

bool Fixed::operator<=( const Fixed& other ) const
{
	if(this->raw <= other.raw)
		return 1;
	return 0;
}

Fixed Fixed::operator+( const Fixed other ) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-( const Fixed other ) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}
 
Fixed Fixed::operator*( const Fixed other ) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/( const Fixed other ) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++( void )
{
	raw++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp = *this;

	raw++;
	return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	raw--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp = *this;

	raw--;
	return (tmp);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return raw;
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
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

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::min( Fixed& a, Fixed& b )
{ 
	if (a < b)
		return (a);
	return (b);
}
 
const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a > b)
		return (a);
	return (b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
