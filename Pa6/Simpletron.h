// Author: Andrew S. O'Fallon

#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include "SmlInstruction.h"

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Simpletron
{
	public:
		Simpletron (int newProgramSize = 1000, int newDataSize = 1000);
		~Simpletron ();

		Simpletron & operator= (const Simpletron &rhs);

		// getters / accessors
		SmlInstruction * getProgramMemoryPtr () const;
		int * getDataMemoryPtr () const;
		int getAccumulator () const;
		int getInstructionCounter () const;
		SmlInstruction getInstructionRegister () const;
		int getProgramSize () const;
		int getDataSize () const;
		OpcodeType getOpcode () const;
		int getOperand () const;

		// setters / mutators
		void setProgramMemoryPtr (SmlInstruction *newProgramMemoryPtr);
		void setDataMemoryPtr (int *newDataMemoryPtr);
		void setAccumulator (int newAccumulator);
		void setInstructionCounter (int newInstructionCounter);
		void setInstructionRegister (SmlInstruction newInstructionRegister);
		void setProgramSize (int newProgramSize);
		void setDataSize (int newDataSize);
		void setOpcode (OpcodeType newOpcode);
		void setOperand (int newOperand);

		// fetch/decode/execute cycle operations
		void fetch ();
		void decode ();
		void execute ();

		// display memory
		void dumpMemory ();

	private: // attributes
		SmlInstruction *mProgramMemoryPtr;
		int *mDataMemoryPtr;
		int mAccumulator;
		int mInstructionCounter;
		SmlInstruction mInstructionRegister;
		int mOperand;
		OpcodeType mOpcode;
		int mProgramSize;
		int mDataSize;
};

#endif