#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}

Intern::~Intern() {}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	if (formName == "shrubbery creation") {
		return new ShrubberyCreationForm(target);
	} else if (formName == "robotomy request") {
		return new RobotomyRequestForm(target);
	} else if (formName == "presidential pardon") {
		return new PresidentialPardonForm(target);
	} else {
		throw FormNotFoundException();
	}
}
