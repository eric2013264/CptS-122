// Author: Andrew S. O'Fallon

#ifndef SIM_APP_H
#define SIM_APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Simpletron.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;

class SimApp
{
	public:
		SimApp ();
		~SimApp ();

		// No need for overloaded assignment = operator
		
		string getFileName ();
		void openFile (string fileName, ifstream &inStream);
		void loadProgram (ifstream &inStream);
		void displayProgram ();
		void closeFile (ifstream &inStream);

		void runApp ();

	private:
		Simpletron mSmlComputer;
};

#endif