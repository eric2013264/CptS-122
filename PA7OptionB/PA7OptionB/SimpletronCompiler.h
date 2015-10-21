#ifndef SIMPLETRONCOMPILER_H_
#define SIMPLETRONCOMPILER_H_

#include <vector>
#include "TableEntry.h"
#include <string>
#include <queue>

#include "Simpletron.h"

using namespace std;

class SimpletronCompiler {
public:
	SimpletronCompiler();
	void compileFile(string filename, ostream& out);
private:
	static bool isStringNumber(string str);
	static bool isStringVar(string str);
	int postFixToSML(queue<string> postfix);
	int gotoToSML(string strLineNo);
	TableEntry getSymbolTableRow(int symbol, char type);
	bool isElementInSymbolTable(int symbol, char type);
	static const int MEMSIZE = 100; // Size of Simpletron RAM.
	vector<TableEntry> symbolTable; // symbol table for compilation.
	int flags[MEMSIZE]; // Flags for second pass.
	int smlInstructs[MEMSIZE]; // The instructions for SML, ordered by array indices.
	int dataCounter; // Point to add next variable to memory.
	int instructionCounter; // Point to add next statement to memory.
	string oneline;


};

#endif
