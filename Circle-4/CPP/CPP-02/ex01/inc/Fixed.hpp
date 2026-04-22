#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	private:
		int	fixedvalue;
		static const int	fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& src);
		Fixed(int const input);
		Fixed(float const input);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};	

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
