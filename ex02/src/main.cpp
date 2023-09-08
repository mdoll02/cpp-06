#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


Base *generate();
void identify(Base *p);
void identify(Base &p);

int main ()	{
	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;
}

Base *generate() {
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	switch (random) {
		case 0:
			std::cout << GREEN << "Generating A" << R << std::endl;
			return new A();
		case 1:
			std::cout << GREEN << "Generating B" << R << std::endl;
			return new B();
		case 2:
			std::cout << GREEN <<  "Generating C" << R << std::endl;
			return new C();
	}
	return NULL;
}

void identify(Base *p) {
	std::cout << "Identified as ";
	if (dynamic_cast<A *>(p))
		std::cout << RED << "A" << R << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << RED << "B" << R << std::endl;
	else
		std::cout << RED << "C" << R << std::endl;
}

void identify(Base &p) {
	std::cout << "Identified as ";
	if (dynamic_cast<A *>(&p))
		std::cout << RED << "A" << R << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << RED << "B" << R << std::endl;
	else
		std::cout << RED << "C" << R << std::endl;
}