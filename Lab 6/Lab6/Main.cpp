#include "Header.h"

int main (void)
{
	Complex num(5,6), num1(4,3);

	num.add(num1);
	num.printComplex();

	system("Pause");
	return 0;
}