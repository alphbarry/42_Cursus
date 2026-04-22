#include "../inc/PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;
	sorter.parseArguments(argc, argv);
	sorter.displayResults();
	sorter.sort();

	return 0;
}

