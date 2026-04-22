#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	type = src.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	if (this != &src) {
		type = src.type;
	}
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
