#pragma once

#include <iostream>
# include <stdint.h>


typedef struct s_data {
	int age;
	std::string name;
	std::string sername;
} Data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
