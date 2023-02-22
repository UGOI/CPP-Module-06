#include "./include/ScalarConverter.hpp"
#include <limits>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::ConvertResult ScalarConverter::convert(const std::string& literal) {
	ConvertResult result;
	result.c = 0;
	result.i = 0;
	result.f = 0;
	result.d = 0;
	result.cError = "";
	result.iError = "";
	result.fError = "";
	result.dError = "";


	try
    {
        result.d = std::stod(literal);
		result.c = static_cast<char>(result.d);
		if (result.c < 32 || result.c > 126) {
			result.cError = "Non displayable";
		}
	}
	catch (const std::out_of_range& e)
	{
		result.dError = e.what();
	}
	catch (const std::invalid_argument& e)
	{
		if (literal.length() == 1) {
			result.c = literal[0];
			result.d = static_cast<double>(literal[0]);
			if (result.c < 32 || result.c > 126) {
				result.cError = "Non displayable";
			}
	}
		else {
			result.cError = "impossible";
		}
    }
	try {
		result.f = std::stof(literal);
	}
	catch (const std::out_of_range& e)
	{
		result.fError = e.what();
	}
	catch (const std::invalid_argument& e)
	{
		if (literal.length() == 1) {
			result.f = static_cast<float>(literal[0]);
		}
		else {
			result.fError = "impossible";
		}
	}
	try {
		result.i = std::stoi(literal);
	}
	catch (const std::out_of_range& e)
	{
		result.iError = e.what();
	}
	catch (const std::invalid_argument& e)
	{
	if (literal.length() == 1) {
		result.i = static_cast<int>(literal[0]);
	}
	else {
		result.iError = "impossible";
	}
	}

	return result;
}

void ScalarConverter::ConvertResult::print() const {
	std::cout << "char: ";
	if (cError != "") {
		std::cout << cError << std::endl;
	}
	else {
		std::cout << "'" << c << "'" << std::endl;
	}
	std::cout << "int: ";
	if (iError != "") {
		std::cout << iError << std::endl;
	}
	else {
		std::cout << i << std::endl;
	}
	std::cout << "float: ";
	if (fError != "") {
		std::cout << fError << std::endl;
	}
	else {
		std::cout << f << "f" << std::endl;
	}
	std::cout << "double: ";
	if (dError != "") {
		std::cout << dError << std::endl;
	}
	else {
		std::cout << d << std::endl;
	}
}