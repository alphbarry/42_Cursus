#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal& operator=(const WrongAnimal& src);
		virtual ~WrongAnimal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif // WRONGANIMAL_HPP
