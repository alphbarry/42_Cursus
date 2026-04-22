#include "../inc/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat destructor calledd" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& src){
	this->_type = src._type;
	this->_brain = new Brain(*src._brain); // Deep copy of the brain
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src){
	if (this != &src){
		delete this->_brain; // Avoid memory leak
		this->_brain = new Brain(*src._brain); // Deep copy of the brain
		this->_type = src._type;
	}
	std::cout << "Cat operator= constructor called." << std::endl;
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "*MEOW*" << std::endl;
}
