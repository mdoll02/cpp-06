#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cfloat>
#include <iomanip>
#include <limits>
#include <climits>

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << "Assignation operator called" << std::endl;
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(std::string &str) {
	std::cout << "convert called with " << str << std::endl;
	long double literal_ld;
	bool valid = true;
	char *endptr;

	if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]))
		literal_ld = static_cast<int>(str[0]);
	else {
		literal_ld = std::strtold(str.c_str(), &endptr);
		if (*endptr != '\0' && strncmp(endptr, "f", 2) != 0 && !isscience(str))
			valid = false;
	}

	displayChar(static_cast<int>(literal_ld));
	displayInt(literal_ld, valid);
	displayFloat(literal_ld, valid, str);
	displayDouble(literal_ld, valid, str);
}

void ScalarConverter::displayChar(int c) {
	std::cout << "char: ";

	if (c < 0 || c > 127)
	{
		std::cout << RED "impossible" << R << std::endl;
		return;
	}
	if (isprint(c)) {
		std::cout << GREEN << "'" << static_cast<char>(c) << "'" << R << std::endl;
		return;
	}
	else
	{
		std::cout << RED << "Non displayable" << R << std::endl;
		return;
	}
}

void ScalarConverter::displayInt(long double &literal, bool valid) {
	std::cout << "int: ";

	if (!valid || literal > INT_MAX || literal < INT_MIN || literal != static_cast<int>(literal)) {
		std::cout << RED "impossible" << R << std::endl;
		return;
	}
	std::cout << GREEN << static_cast<int>(literal) << R << std::endl;
}

void ScalarConverter::displayFloat(long double &literal, bool valid, std::string &str) {
	std::cout << "float: ";

	if (displayPsuedoLiteral(str))
		return;
	if (!valid || literal > FLT_MAX || literal < -FLT_MAX) {
		std::cout << RED << "impossible" << R << std::endl;
		return;
	}
	std::cout << GREEN << static_cast<double>(literal);
	if (static_cast<double>(literal) == static_cast<int>(literal))
		std::cout << ".0";
	std::cout << "f" << R << std::endl;
}

void ScalarConverter::displayDouble(long double &literal, bool valid, std::string &str) {
	std::cout << "double: ";

	if (displayPsuedoLiteral(str))
		return;
	if (!valid || literal > DBL_MAX || literal < -DBL_MAX) {
		std::cout << RED << "impossible" << R << std::endl;
		return;
	}
	std::cout << GREEN << static_cast<double>(literal);
	if (static_cast<double>(literal) == static_cast<int>(literal))
		std::cout << ".0";
	std::cout << R << std::endl;
}

bool ScalarConverter::displayPsuedoLiteral(std::string &str) {
	if (str == "+inff")
	{
		std::cout << GREEN << static_cast<float>(std::numeric_limits<float>::infinity()) << R << std::endl;
		return true;
	}
	if (str == "-inff")
	{
		std::cout << GREEN << static_cast<float>(-std::numeric_limits<float>::infinity()) << R << std::endl;
		return true;
	}
	if (str == "nanf")
	{
		std::cout << GREEN << static_cast<float>(-std::numeric_limits<float>::quiet_NaN()) << R << std::endl;
		return true;
	}
	if (str == "+inf")
	{
		std::cout << GREEN << static_cast<double>(std::numeric_limits<double>::infinity()) << R << std::endl;
		return true;
	}
	if (str == "-inf")
	{
		std::cout << GREEN << static_cast<double>(-std::numeric_limits<double>::infinity()) << R << std::endl;
		return true;
	}
	if (str == "nan")
	{
		std::cout << GREEN << static_cast<double>(-std::numeric_limits<double>::quiet_NaN()) << R << std::endl;
		return true;
	}
	return false;
}

bool ScalarConverter::isscience(std::string &str) {
	if (str == "nan" || str == "nanf")
		return true;
	if (str == "+inf" || str == "+inff")
		return true;
	if (str == "-inf" || str == "-inff")
		return true;
	return false;
}
