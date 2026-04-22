#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		virtual ~Animal();
		virtual void makeSound() const = 0; // Pure virtual function
		std::string getType() const;
};

#endif
