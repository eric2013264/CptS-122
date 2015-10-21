#include "Header.h"

// Constructor initializes everything to 0
//Complex::Complex()
//{
//	myReal = 0;
//	myImag = 0;
//}

Complex::Complex(double real, double imag)
{
	myReal = real;	// setting value to myReal
	myImag = imag;	// setting value to myImag
}

Complex::Complex (Complex &newComplex)
{
	myReal = newComplex.getReal ();
	myImag = newComplex.getImag ();
}

Complex::~Complex()
{

}

// setters
void Complex::setReal (double real)
{
	myReal = real;
}

void Complex::setImag (double imag)
{
	myImag = imag;
}

// getters
double Complex::getReal ()
{
	return myReal;
}
		
double Complex::getImag ()
{
	return myImag;
}

void Complex::add (Complex n1)
{
	myReal += n1.getReal();
	myImag += n1.getImag();
}

void Complex::printComplex()
{
	cout << myReal << " + i" << myImag << endl;
}

