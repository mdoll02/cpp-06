#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer() {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	std::cout << "Assignation operator called" << std::endl;
	(void)other;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
