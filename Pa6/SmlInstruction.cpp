// Author: Andrew S. O'Fallon

#include "SmlInstruction.h"

SmlInstruction::SmlInstruction ()
{
	mOpcode = NO_OP;
	mOperand = 0;
}

SmlInstruction::~SmlInstruction ()
{
	// Instructions will be deallocated by the Simpletron class
}

SmlInstruction & SmlInstruction::operator= (const SmlInstruction &rhs)
{
	if (this != &rhs)
	{
		mOpcode = rhs.getOpcode ();
		mOperand = rhs.getOperand ();
	}

	return *this;
}

ostream & operator<< (ostream &output, const SmlInstruction &rhs)
{
	output.setf (ios::showpos);
	int size = output.width (2);
	char fillChar = output.fill ('0');
	output << rhs.getOpcode ();
	output.unsetf(ios::showpos);
	output.width (3);
	output << rhs.getOperand ();

	output.width (size);
	output.fill (fillChar);

	return output;
}

OpcodeType SmlInstruction::getOpcode () const
{
	return mOpcode;
}

int SmlInstruction::getOperand () const
{
	return mOperand;
}

void SmlInstruction::setOpcode (OpcodeType newOpcode)
{
	mOpcode = newOpcode;
}

void SmlInstruction::setOperand (int newOperand)
{
	mOperand = newOperand;
}