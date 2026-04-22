#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main(){
	const Animal* meta = new Animal();
	const Animal* loli = new Dog();
	const Animal* koki = new Cat();
	const Animal sosi;
	const Dog toti;
	
	std::cout << "loli is a " << loli->getType() << std::endl;
	std::cout << "koki is a " << koki->getType() << std::endl;
	std::cout << "sosi is a " << sosi.getType() << std::endl;
	std::cout << "toti is a " << toti.getType() << std::endl;
	std::cout << "meta is a " << meta->getType() << std::endl;
	koki->makeSound(); //will output the cat sound!
	loli->makeSound();
	sosi.makeSound();
	toti.makeSound();
	meta->makeSound();
	delete loli;
	delete koki;
	return 0;
}
