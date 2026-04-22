#include "../inc/Serializer.hpp"

#include <iostream>

int main() {
	Data data;
	data.age = 30;
	data.name = "John";
	data.sername = "Doe";

	std::cout << "Original Data: " << data.age << ", " << data.name << ", " << data.sername << std::endl;

	unsigned long raw = Serializer::serialize(&data);
	std::cout << "Serialized Data: " << raw << std::endl;

	Data *deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data: " << deserializedData->age << ", "
			  << deserializedData->name << ", "
			  << deserializedData->sername << std::endl;

	return 0;
}
