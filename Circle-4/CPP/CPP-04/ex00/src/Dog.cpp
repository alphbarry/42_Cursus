#include "../inc/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog destructor calledd" << std::endl;
}

Dog::Dog(const Dog& src){
	this->_type = src._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src){
	if (this != &src)
		this->_type = src._type;
	std::cout << "Dog operator= constructor called." << std::endl;
	return *this;
}

void	Dog::makeSound() const{
	std::cout << "*WAFF WAFF" << std::endl;
}
