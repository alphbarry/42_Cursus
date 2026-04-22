#include "../inc/Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat(){
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade){

}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy){
	this->_grade = copy._grade;
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
	if (this != &copy){
		this->_grade = copy._grade;
	}
	std::cout << "Bureaucrat operator= constructor called." << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}

int	Bureaucrat::getGrade() const{
	return this->_grade;
}
void	Bureaucrat::setGrade(int grade){
	this->_grade = grade;
}

void	Bureaucrat::UpGrade(int grade){
	this->_grade = grade - 1;
}

void	Bureaucrat::DownGrade(int grade){
	this->_grade = grade + 1;
}

void	Bureaucrat::GradeTooHighException(int grade) const{
	try {
		if (this->_grade < 1)
			throw std::out_of_range("Grade too high!");
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::GradeTooLowException(int grade) const {
	try{
		if (this->_grade > 150)
			throw std::out_of_range("Grade too low");
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat bureaucrat) {
	os << "The grade of " << bureaucrat.getName() << " is: " << bureaucrat.getGrade() << std::endl; // Output the float representation of the fixed-point number
	return os;
}
