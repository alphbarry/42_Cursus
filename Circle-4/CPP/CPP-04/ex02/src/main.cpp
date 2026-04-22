#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main(){
	const Dog dodi;

	dodi.makeSound();

	Dog qoqi(dodi);

	dodi.makeSound();

	const Animal* loli = new Dog();
	const Animal* koki = new Cat();
	const WrongAnimal* popi = new WrongCat();
	const Dog toti;
	
	std::cout << "loli is a " << loli->getType() << std::endl;
	std::cout << "koki is a " << koki->getType() << std::endl;
	std::cout << "toti is a " << toti.getType() << std::endl;
	std::cout << "popi is a " << popi->getType() << std::endl;
	koki->makeSound(); //will output the cat sound!
	loli->makeSound();
	toti.makeSound();
	popi->makeSound();
	delete loli;
	delete koki;
	delete popi;
	return 0;
}
