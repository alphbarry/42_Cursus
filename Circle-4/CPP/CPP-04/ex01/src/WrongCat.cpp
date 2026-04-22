#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(){
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) {
	this->type = src.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
	if (this != &src) {
		this->type = src.type;
	}
	std::cout << "WrongCat assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound!" << std::endl;
}

std::string WrongCat::getType() const {
	return type;
}
