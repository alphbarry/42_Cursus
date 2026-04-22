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

		bool operator>(Fixed Fixed) const;
		bool operator<(Fixed Fixed) const;
		bool operator>=(Fixed Fixed) const;
		bool operator<=(Fixed Fixed) const;
		bool operator==(Fixed Fixed) const;
		bool operator!=(Fixed Fixed) const;

		float operator+(Fixed Fixed) const;
		float operator-(Fixed Fixed) const;
		float operator*(Fixed Fixed) const;
		float operator/(Fixed Fixed) const;

		Fixed operator++(int);
		Fixed operator++(void);
		Fixed operator--(int);
		Fixed operator--(void);

		float	toFloat(void) const;
		int		toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};	

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
