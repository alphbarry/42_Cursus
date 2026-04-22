#pragma once

#include "AMateria.hpp"

class	Ice : AMateria{
	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		~Ice();
};
