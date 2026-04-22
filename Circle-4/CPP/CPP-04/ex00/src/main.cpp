#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main(){
	const Animal* meta = new Animal();
	const Animal* loli = new Dog();
	const Animal* koki = new Cat();
	
	std::cout << "loli is a " << loli->getType() << std::endl;
	std::cout << "koki is a " << koki->getType() << std::endl;
	std::cout << "meta is a " << meta->getType() << std::endl;
	koki->makeSound(); //will output the cat sound!
	loli->makeSound();
	meta->makeSound();
	delete loli;
	delete koki;
	return 0;
}
