#pragma once

#include <iostream>
#include <iterator>
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

		void	GradeTooHighException();
		void	GradeTooLowException();
		
		int	getGrade() const;
		std::string	getName() const;
		void	setGrade(int grade);
		void	setName(const std::string& name);

		void	UpGrade(int grade);
		void	DownGrade(int grade);

		void	GradeTooHighException(int grade) const;
		void	GradeTooLowException(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat bureaucrat);
