#include "../inc/Fixed.hpp"

const int Fixed::fractionalBits = 8; // Initialize the static member variable

Fixed::Fixed() : fixedvalue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const input){
	std::cout << "Int constructor called" << std::endl;
	this->fixedvalue = input << fractionalBits; // Convert int to fixed-point representation
}

Fixed::Fixed(float const input) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedvalue = roundf(input * (1 << fractionalBits)); // Convert float to fixed-point representation
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

int Fixed::Fixed::toInt(void) const {
	return this->fixedvalue >> fractionalBits; // Convert fixed-point to int
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedvalue) / (1 << fractionalBits);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedvalue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedvalue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat(); // Output the float representation of the fixed-point number
	return os;
}

bool Fixed::operator>(Fixed Fixed) const {
	return this->fixedvalue > Fixed.fixedvalue;
}

bool Fixed::operator<(Fixed Fixed) const {
	return this->fixedvalue < Fixed.fixedvalue;
}

bool Fixed::operator>=(Fixed Fixed) const {
	return this->fixedvalue >= Fixed.fixedvalue;
}

bool Fixed::operator<=(Fixed Fixed) const {
	return this->fixedvalue <= Fixed.fixedvalue;
}

bool Fixed::operator==(Fixed Fixed) const {
	return this->fixedvalue == Fixed.fixedvalue;
}

bool Fixed::operator!=(Fixed Fixed) const {
	return this->fixedvalue != Fixed.fixedvalue;
}

float Fixed::operator+(Fixed Fixed) const {
	return this->toFloat() + Fixed.toFloat();
}

float Fixed::operator-(Fixed Fixed) const {
	return this->toFloat() - Fixed.toFloat();
}

float Fixed::operator*(Fixed Fixed) const {
	return this->toFloat() * Fixed.toFloat();
}

float Fixed::operator/(Fixed Fixed) const {
	return this->toFloat() / Fixed.toFloat();
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this; // Create a copy of the current object
	this->fixedvalue++; // Increment the fixed value
	return temp; // Return the old value
}

Fixed Fixed::operator++(void) {
	this->fixedvalue++; // Increment the fixed value
	return *this; // Return the current object
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this; // Create a copy of the current object
	this->fixedvalue--; // Decrement the fixed value
	return temp; // Return the old value
}

Fixed Fixed::operator--(void) {
	this->fixedvalue--; // Decrement the fixed value
	return *this; // Return the current object
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b; // Return the smaller of the two Fixed objects
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b; // Return the smaller of the two Fixed objects
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b; // Return the larger of the two Fixed objects
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b; // Return the larger of the two Fixed objects
}
