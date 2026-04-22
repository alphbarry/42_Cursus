#include "../inc/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog destructor calledd" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog& src){
	this->_type = src._type;
	this->_brain = new Brain(*src._brain); // Deep copy of the brain
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src){
	if (this != &src){
		delete this->_brain; // Avoid memory leak
		this->_brain = new Brain(*src._brain); // Deep copy of the brain
		this->_type = src._type;
	}
	std::cout << "Dog operator= constructor called." << std::endl;
	return *this;
}

void	Dog::makeSound() const{
	std::cout << "*WAFF WAFF" << std::endl;
}
