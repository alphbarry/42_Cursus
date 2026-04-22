#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other; 
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other) {
	}
	return *this;
}

namespace sc {
	double stod98(const std::string& str) {
		char* end;
		const char* cstr = str.c_str();
		double result = std::strtod(cstr, &end);

		if (cstr == end || *end != '\0') {
			throw std::invalid_argument("stod98: Invalid conversion");
		}
		return result;
	}
}

void ScalarConverter::convert(const std::string &literal) {
    std::cout << "Converting literal: " << literal << std::endl;

    int type = which_type(literal);

    switch (type) {
        case CHAR: {
            char c = literal[0];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
            break;
        }

        case INT:
        case DOUBLE: {
            double value;
            try {
                value = sc::stod98(literal);
            } catch (const std::exception& e) {
                std::cerr << "Invalid literal" << std::endl;
                return;
            }

            // char
            std::cout << "char: ";
            if (std::isnan(value) || value < 0 || value > 127)
                std::cout << "impossible";
            else if (!isprint(static_cast<char>(value)))
                std::cout << "Non displayable";
            else
                std::cout << "'" << static_cast<char>(value) << "'";
            std::cout << std::endl;

            // int
            std::cout << "int: ";
            if (std::isnan(value) || value < MIN_INT || value > MAX_INT)
                std::cout << "impossible";
            else
                std::cout << static_cast<int>(value);
            std::cout << std::endl;

            // float
            float f = static_cast<float>(value);
            std::cout << "float: " << f;
            if (f == static_cast<int>(f)) std::cout << ".0";
            std::cout << "f" << std::endl;

            // double
            std::cout << "double: " << value;
            if (value == static_cast<int>(value)) std::cout << ".0";
            std::cout << std::endl;
            break;
        }

        case FLOAT: {
            double value;
            std::string tmp = literal.substr(0, literal.length() - 1);
            try {
                value = sc::stod98(tmp);
            } catch (const std::exception& e) {
                std::cerr << "Invalid literal" << std::endl;
                return;
            }

            // char
            std::cout << "char: ";
            if (std::isnan(value) || value < 0 || value > 127)
                std::cout << "impossible";
            else if (!isprint(static_cast<char>(value)))
                std::cout << "Non displayable";
            else
                std::cout << "'" << static_cast<char>(value) << "'";
            std::cout << std::endl;

            // int
            std::cout << "int: ";
            if (std::isnan(value) || value < MIN_INT || value > MAX_INT)
                std::cout << "impossible";
            else
                std::cout << static_cast<int>(value);
            std::cout << std::endl;

            // float
            float f = static_cast<float>(value);
            std::cout << "float: " << f;
            if (f == static_cast<int>(f)) std::cout << ".0";
            std::cout << "f" << std::endl;

            // double
            std::cout << "double: " << value;
            if (value == static_cast<int>(value)) std::cout << ".0";
            std::cout << std::endl;
            break;
        }

        default:
            std::cerr << "Invalid literal" << std::endl;
    }
}

