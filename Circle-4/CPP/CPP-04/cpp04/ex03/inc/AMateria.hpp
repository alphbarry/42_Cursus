#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter; // Forward declaration

class	AMateria{
	protected:
		std::string	type;


	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& copy);
		virtual ~AMateria();

		std::string const& getType();
		virtual AMateria* clone() const = 0; // Pure virtual function
		virtual void use(ICharacter& target);
};

