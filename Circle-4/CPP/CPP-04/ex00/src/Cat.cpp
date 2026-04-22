#include "../inc/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat destructor calledd" << std::endl;
}

Cat::Cat(const Cat& src){
	this->_type = src._type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src){
	if (this != &src)
		this->_type = src._type;
	std::cout << "Cat operator= constructor called." << std::endl;
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "*MEOW*" << std::endl;
}
