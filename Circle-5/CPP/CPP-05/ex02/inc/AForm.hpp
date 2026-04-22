#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	AForm : public Bureaucrat{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		virtual void 		performAction() const = 0; // Pure virtual function

	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw(); 
		};

		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);
