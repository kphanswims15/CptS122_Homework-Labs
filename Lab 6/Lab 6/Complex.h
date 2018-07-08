#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

class Complex
{
public:

	Complex(double newRealPart = 0.0, double newImginaryPart = 0.0);
	Complex(const Complex &rhs);
	~Complex();

	Complex add(const Complex &rhs);
	double getReal() const;
	double getImaginary() const;
	void setReal(const int newRealPart);
	void setImaginary(const int newImaginaryPart);

private:
	double realPart;
	double imaginaryPart;
};

Complex operator- (const Complex & lhs, const Complex & rhs)
{
	Complex temp;
	temp.setReal(lhs.getReal() + rhs.getReal());
}