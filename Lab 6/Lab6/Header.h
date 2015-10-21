#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Complex
{
	public:
		//Complex();
		Complex(double real, double imag);	// default constructor
		Complex (Complex &newComplex);

		~Complex();	// destrctor

		// setters
		void setReal(double real);
		void setImag(double imag);

		// getters
		double getReal(); 
		double getImag();

		void add(Complex n1);

		void printComplex();

	private:
		double myReal;
		double myImag;
};