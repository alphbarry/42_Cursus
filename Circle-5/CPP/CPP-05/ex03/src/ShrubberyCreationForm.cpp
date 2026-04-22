#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy), _target(copy._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::performAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << _target << "_shrubbery" << std::endl;
		return;
	}
	file << "       _-_\n"
     << "    /~~   ~~\\\n"
     << " /~~         ~~\\\n"
     << "{               }\n"
     << " \\  _-     -_  /\n"
     << "   ~  \\\\ //  ~\n"
     << "_- -   | | _- _\n"
     << "  _ -  | |   -_\n"
     << "      // \\\\" << std::endl;
	file.close();
	std::cout << "Shrubbery created in file: " << _target << "_shrubbery" << std::endl;
}
