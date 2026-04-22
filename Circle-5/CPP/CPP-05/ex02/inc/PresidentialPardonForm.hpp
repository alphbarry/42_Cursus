#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

		void performAction() const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();

		const std::string &getTarget() const;
};
