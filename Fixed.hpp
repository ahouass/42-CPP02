
class Fixed
{
	private:
		int					raw;
		static const int	fractional_bits;
		
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=( const Fixed& copy );
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};