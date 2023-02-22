#pragma once

#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
public:
    struct ConvertResult {
        char c;
        int i;
        float f;
        double d;
		std::string cError;
		std::string iError;
		std::string fError;
		std::string dError;
		void print() const;
    };
    static ConvertResult convert(const std::string& literal);
	static void printResult(const ConvertResult& result);

};
