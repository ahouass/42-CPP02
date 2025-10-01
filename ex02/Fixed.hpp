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

		bool operator!=( const Fixed& other ) const;
		bool operator==( const Fixed& other ) const;
		bool operator>( const Fixed& other ) const;
		bool operator>=( const Fixed& other ) const;
		bool operator<( const Fixed& other ) const;
		bool operator<=( const Fixed& other ) const;

		Fixed operator+( const Fixed other ) const;
		Fixed operator-( const Fixed other ) const;
		Fixed operator*( const Fixed other ) const;
		Fixed operator/( const Fixed other ) const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&		min( Fixed& a, Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
		static Fixed&		max( Fixed& a, Fixed& b );

		~Fixed();

		Fixed(const int n);
		Fixed(const float n);

		int		toInt( void ) const;
		float	toFloat( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
