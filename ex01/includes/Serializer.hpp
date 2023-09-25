#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <stdint.h>

typedef struct Data {
	std::string s1;
	int n;
	std::string s2;
} Data;


class Serializer {
public:
	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);

	~Serializer();
private:
	Serializer();

	Serializer(const Serializer& other);

	Serializer& operator=(const Serializer& other);
};

#endif