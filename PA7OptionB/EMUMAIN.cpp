#include "CPUEMU.h"
#include <fstream>

using namespace std;


void PrintHeader(void)
{
	cerr << endl
		<< "*** Simpletron Simulator ***" << endl;

}

int main(int argc, char *argv[])
{
	int InputFile;
	ifstream in;

	Computer MyComputer;
	PrintHeader();
	if (argc < 2)
		InputFile = 0;
	else
	{
		in.open(argv[1], ios::in);
		if (!in)
		{
			cerr << "Unable to open the file " << argv[1] << "." << endl;
			return 1;
 		}
		InputFile = 1;
	}
	if (InputFile)
	{
		cout << "Receiving input from the file " << argv[1] << "..." << endl;
		MyComputer.Begin(in);
		in.close();
	}
	else
	{
		cout << "Receiving input from the keyboard" << endl;
		MyComputer.Begin(cin);

	}

	return 0;
}
