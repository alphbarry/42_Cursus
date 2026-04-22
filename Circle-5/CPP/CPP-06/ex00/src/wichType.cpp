#include "../inc/ScalarConverter.hpp"
#include <cctype>

static int isspecial(const std::string& lit){
	if (lit == "nan" || lit == "nanf" || lit == "-inf" || lit == "+inf" || lit == "-inff" || lit == "+inff")
		return 1;
	return 0;
}

static int ischar(const std::string& lit){
	if(lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0]))
		return 1;
	return 0;
}

static int	isint(const std::string& lit){
	size_t	i = 0;

	if (lit.empty())
		return 0;
	if (lit[i] == '-' || lit[i] == '+')
		i++;
	if (i == lit.length())
		return 0;
	for (; i < lit.length(); i++){
		if (!isdigit(lit[i]))
			return 0;
	}
	return 1;
}

static int isfloat(const std::string& lit) {
	if (lit.empty() || lit[lit.length() - 1] != 'f')
		return 0;

	std::string num = lit.substr(0, lit.length() - 1); // quitar 'f'
	if (num.empty())
		return 0;

	size_t i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;

	if (i == num.length()) // solo "+" o "-" es inválido
		return 0;

	bool has_digit = false;
	bool has_dot = false;

	for (; i < num.length(); ++i) {
		if (std::isdigit(num[i])) {
			has_digit = true;
		} else if (num[i] == '.') {
			if (has_dot)
				return 0; // más de un punto
			has_dot = true;
		} else {
			return 0; // carácter no válido
		}
	}

	return (has_digit && has_dot);
}


static int isdouble(const std::string& lit) {
	size_t i = 0;
	bool dot = false;

	if (lit.empty())
		return 0;

	if (lit[i] == '+' || lit[i] == '-')
		i++;

	if (i == lit.length()) // solo "+" o "-" es inválido
		return 0;

	bool digit = false;
	for (; i < lit.length(); i++) {
		if (isdigit(lit[i])) {
			digit = true;
		} else if (lit[i] == '.') {
			if (dot)
				return 0;
			dot = true;
		} else {
			return 0;
		}
	}

	return (digit && dot);
}

e_type	which_type(const std::string& literal){
	if(ischar(literal))
		return CHAR;
	if(isint(literal))
		return INT;
	if(isfloat(literal))
		return FLOAT;
	if(isdouble(literal))
		return DOUBLE;
	if (isspecial(literal))
		return SPECIAL;
	return INVALID;
}
