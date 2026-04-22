#include "../inc/iter.hpp"

void printInt(int& x) {
	std::cout << x << " ";
}

void printString(std::string& s) {
	std::cout << s << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Iterating over int array:" << std::endl;
	iter(intArray, intLength, printInt);
	std::cout << std::endl;

	std::string strArray[] = {"Hello", "World", "!"};
	size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Iterating over string array:" << std::endl;
	iter(strArray, strLength, printString);
	std::cout << std::endl;

	return 0;
}

