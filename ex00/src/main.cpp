#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Usage: " << argv[0] << " string" << R << std::endl;
		return 1;
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
	return 0;
}