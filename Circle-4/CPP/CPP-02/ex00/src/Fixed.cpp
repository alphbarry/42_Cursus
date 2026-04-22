#include "../inc/Fixed.hpp"

const int Fixed::fractionalBits = 8; // Initialize the static member variable

Fixed::Fixed() : fixedvalue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : fixedvalue(copy.fixedvalue) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; // Using assignment operator to copy the value
}

Fixed &Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->fixedvalue = src.fixedvalue;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedvalue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedvalue = raw;
}
