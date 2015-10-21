#ifndef SIMPLETRON_H_
#define SIMPLETRON_H_

#include <iostream>

using namespace std;

class Simpletron {
public:
	Simpletron();
	void printState();
	void interactiveInput();
	void streamInput(istream& in);
	void execute();
	void arithResultCheck();

	//Set operation code constants.
	static const int READ = 10;
	static const int WRITE = 11;

	static const int LOAD = 20;
	static const int STORE = 21;

	static const int ADD = 30;
	static const int SUBTRACT = 31;

	static const int DIVIDE = 32;
	static const int MULTIPLY = 33;

	static const int BRANCH = 40;
	static const int BRANCHNEG = 41;
	static const int BRANCHZERO = 42;
	static const int HALT = 43;

private:
	static const int MEMSIZE = 100;
	static const int ENDINPUTLOOP = -99999;

	static const char *FATAL_ERROR_MESSAGE;

	int instructionRegister, operationCode, operand;
	int action, accumulator, instructionCounter;

	int memory[MEMSIZE];

	void printError();


};

#endif
