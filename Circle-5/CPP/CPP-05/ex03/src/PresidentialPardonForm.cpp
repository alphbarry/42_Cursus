#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
	: AForm(copy), _target(copy._target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

const std::string &PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::performAction() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
