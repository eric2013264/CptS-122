// Author: Andrew S. O'Fallon

#include "SimApp.h"

SimApp::SimApp ()
{
}

SimApp::~SimApp ()
{
}

string SimApp::getFileName ()
{
	string fileName;

	cout << "Please enter the name of the SML file (i.e. filename.sml): ";
	cin >> fileName;

	return fileName;
}

void SimApp::openFile (string fileName, ifstream &inStream)
{
	// Need to convert from "string" type to "char *" --> c_str ()
	inStream.open (fileName.c_str (), ios::in);
}

void SimApp::loadProgram (ifstream &inStream)
{
	SmlInstruction *tempPtr = mSmlComputer.getProgramMemoryPtr ();
	int index = 0;
	string instruction = "";

	while (!inStream.eof ())
	{
		std::getline (inStream, instruction);
		tempPtr[index].setOpcode ((OpcodeType) (atoi (instruction.c_str ()) / mSmlComputer.getDataSize ()));
		tempPtr[index].setOperand ((atoi (instruction.c_str ()) % mSmlComputer.getDataSize ()));
		index++;
	}

	mSmlComputer.setProgramSize (index);
}

void SimApp::displayProgram ()
{
	mSmlComputer.dumpMemory ();
}

void SimApp::closeFile (ifstream &inStream)
{
	inStream.close ();
}

void SimApp::runApp ()
{
	string fileName;
	ifstream inStream;

	fileName = getFileName ();
	openFile (fileName, inStream);

	loadProgram (inStream);

	displayProgram ();

	system ("pause");

	do
	{
		mSmlComputer.fetch (); // get the instruction
		mSmlComputer.decode (); // determine the opcode and operands
		displayProgram ();
		mSmlComputer.execute (); // execute the correct operation
	} while (mSmlComputer.getOpcode () != HALT);

	displayProgram ();

	closeFile (inStream);
}