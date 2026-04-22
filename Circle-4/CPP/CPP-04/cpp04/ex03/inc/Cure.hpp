#pragma once

#include "AMateria.hpp"

class Cure : AMateria{
	public:
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		~Cure();
		AMateria* clone (); 
};
