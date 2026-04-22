#pragma once

#include <iostream>
#include <ostream>

class	Bureaucrat{
	private:
		std::string const	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		int	getGrade() const;
		std::string	getName() const;
		void	setGrade(int grade);
		void	setName(const std::string& name);
		void	SignForm(class AForm& form) const;

		void	UpGrade();
		void	DownGrade();
		void		executeForm(AForm const& form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
