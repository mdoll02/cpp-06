#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	static void convert(std::string &str);

private:
	ScalarConverter();

	ScalarConverter(const ScalarConverter& other);

	ScalarConverter& operator=(const ScalarConverter& other);

	~ScalarConverter();

	static void displayChar(std::string &str);
	static void displayInt(long double &literal, bool valid);
	static void displayFloat(long double &literal, bool valid, std::string &str);
	static void displayDouble(long double &literal, bool valid, std::string &str);
	static bool displayPsuedoLiteral(std::string &str);
};

#endif