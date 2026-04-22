#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

Bureaucrat::Bureaucrat(){
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name){
	if(grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat(){
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

void	Bureaucrat::UpGrade(){
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::DownGrade(){
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << "The grade of " << bureaucrat.getName() << " is: " << bureaucrat.getGrade() << std::endl; // Output the float representation of the fixed-point number
	return os;
}

void	Bureaucrat::SignForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}
