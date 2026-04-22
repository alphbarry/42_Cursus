#include "../inc/Animal.hpp"

Animal::Animal() : _type("Fenix"){
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& src){
	_type = src._type;
	std::cout << "Animal constructor copy called." << std::endl; 
}

Animal& Animal::operator=(const Animal& src){
	if (this != &src){
		_type = src._type;
	}
	std::cout << "Animal operator= called." << std::endl;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const{
	std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const{
	return (this->_type);
}
