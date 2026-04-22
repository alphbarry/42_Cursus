#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};
