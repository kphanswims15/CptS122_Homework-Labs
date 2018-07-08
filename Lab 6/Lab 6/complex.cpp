#include "Complex.h"

Complex::Complex(double newRealPart, double newImginaryPart)
{
	realPart = newRealPart;
	imaginaryPart = newImginaryPart;
}

Complex::Complex(const Complex & rhs)
{
	realPart = rhs.realPart;
	imaginaryPart = rhs.imaginaryPart;
}

Complex::~Complex()
{

}

Complex Complex::add(const Complex & rhs)
{
	return Complex();
}

double Complex::getReal() const
{
	return realPart;
}

double Complex::getImaginary() const
{
	return imaginaryPart;
}

void Complex::setReal(const int newRealPart)
{
	realPart = newRealPart;
}

void Complex::setImaginary(const int newImaginaryPart)
{
	imaginaryPart = newImaginaryPart;
}
