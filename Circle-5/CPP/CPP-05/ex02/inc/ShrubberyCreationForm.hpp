#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

		void performAction() const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();

		const std::string &getTarget() const;
};
