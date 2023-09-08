#include "Base.hpp"
#include <iostream>

Base::~Base() {
	std::cout << "Base destructor called" << std::endl;
}