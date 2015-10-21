// Author: Andrew S. O'Fallon

#ifndef SML_INSTRUCTION_H
#define SML_INSTRUCTION_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::string;
using std::ios;

typedef enum opcodeType
{
	NO_OP = 0, READ = 10, WRITE = 11, LOAD = 20, STORE = 21, 
	ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33,
	MOD = 34, EXP = 35,
	BRANCH = 40, BRANCHNEG = 41, BRANCHZERO = 42, HALT = 43
} OpcodeType;

class SmlInstruction
{
	friend ostream & operator<< (ostream &output, const SmlInstruction &rhs);
	public:
		SmlInstruction ();
		~SmlInstruction ();

		SmlInstruction & operator= (const SmlInstruction &rhs);

		OpcodeType getOpcode () const;
		int getOperand () const;

		void setOpcode (OpcodeType newOpcode);
		void setOperand (int newOperand);

	private:
		OpcodeType mOpcode;
		int mOperand;
};

#endif