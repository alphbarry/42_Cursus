#include "../inc/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}

unsigned long Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(unsigned long raw) {
	return reinterpret_cast<Data *>(raw);
}
