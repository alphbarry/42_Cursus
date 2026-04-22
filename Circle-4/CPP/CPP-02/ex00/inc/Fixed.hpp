#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
	private:
		int	fixedvalue;
		static const int	fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& src);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};	

#endif
