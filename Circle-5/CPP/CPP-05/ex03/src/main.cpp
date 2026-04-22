#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"

int	main(){
	Intern someRandomIntern;
	AForm* rrf;

	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Bureaucrat b("Bureaucrat", 73);
		b.SignForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}	

	return (0);	
}
