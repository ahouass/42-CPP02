#pragma once

#include <iostream>

class Fixed
{
	private:
		int					raw;
		static const int	fractional_bits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=( const Fixed& copy );
		~Fixed();

		Fixed(const int n);
		Fixed(const float n);

		int		toInt( void ) const;
		float	toFloat( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
