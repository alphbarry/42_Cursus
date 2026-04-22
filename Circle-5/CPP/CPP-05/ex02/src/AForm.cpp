#include "../inc/AForm.hpp"

AForm::AForm() : _name("Default Form"), _is_signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _is_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _is_signed(copy._is_signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy) {
		_is_signed = copy._is_signed;
	}
	return *this;
}

AForm::~AForm() {
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_is_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	performAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &aform) {
	os << "Form Name: " << aform.getName() << "\n"
	   << "Is Signed: " << (aform.getIsSigned() ? "Yes" : "No") << "\n"
	   << "Grade to Sign: " << aform.getGradeToSign() << "\n"
	   << "Grade to Execute: " << aform.getGradeToExecute();
	return os;
}
