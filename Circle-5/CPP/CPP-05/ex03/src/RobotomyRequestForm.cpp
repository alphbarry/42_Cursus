#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: AForm(copy), _target(copy._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

const std::string &RobotomyRequestForm::getTarget() const {
	return _target;
}

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw() {
	return "Robotomy failed!";
}

void RobotomyRequestForm::performAction() const {
	std::cout << "Drrrrrr... " << _target << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	} else {
		throw RobotomyFailedException();
		std::cout << "Robotomy failed for " << _target << std::endl;
	}
}
