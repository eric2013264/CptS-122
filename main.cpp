// Eric Chen
// 11381898
// CptS 223 - Advanced Data Structures
// Homework assignment #1

#include "ReversibleStack.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Display(ReversibleStack& rs) {
	// CHECK Implement this function (use only Push, Pop and IsEmpty member functions of stack)
	// CHECK After the function completes, the stack should be unmodified (see assignment instructions)

	// we make a new stack, the loop through the existing ones, popping off elements and putting them on the new stack
	// then we go through the new stack and pop them all off and put them back on the original one
	ReversibleStack newStack;
	while (!rs.IsEmpty()) {
		int value = rs.Pop();
		cout << value << (rs.IsEmpty() ? "" : " "); 		// OCD-level perfectionism to make sure there isn't a space behind the last number
		newStack.Push(value);			// pushes stack rs onto newStack
	}
	while (!newStack.IsEmpty()) {
		rs.Push(newStack.Pop());		// pushes newStack back onto stack rs
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Missing required argument for input file." << endl;
		return 1;                                     	// return nonzero for failure
	}

	// Omitted information to prevent direct referencing
	

	// Complete
	inFile.close();
	cout << endl << "Done" << endl;

	system("PAUSE");
	return 0;                                           // return 0 for success

}