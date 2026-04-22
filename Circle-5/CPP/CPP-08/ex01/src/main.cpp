#include "../inc/Span.hpp"

int main() {
	Span sp = Span(5);
	
	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		// Uncommenting the next line will throw an exception
		sp.addNumber(5); // This will throw AlreadyExistsException
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
