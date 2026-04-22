#pragma once

#include <limits>
#include <cctype>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>     // para strtod

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()


enum e_type{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	SPECIAL = 4,
	INVALID = -1
};

class	ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void	convert(const std::string& literal);
};

e_type	which_type(const std::string& literal);
void	convertChar(const std::string& literal);
void	convertInt(const std::string& literal);
void	convertFloat(const std::string& literal);
void	convertDouble(const std::string& literal);
void	printSpecial(const std::string& literal);

