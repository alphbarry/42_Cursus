#pragma once 

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

		void performAction() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();

		const std::string &getTarget() const;

		class RobotomyFailedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
