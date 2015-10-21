/************************************************************************************************
*	Programmer: Eric Chen																		*
*	Class: CptS 122, Fall 2014; Lab Section 4													*
*	Programming Assignment: Personal Assignment 7 Option B - Simpletron Compiler				*
*	Date: Dec 6, 2014																			*
*	Description:	A simpletron compiler which converts a simple program into SML code			*
*					using 2 passes and executes it using the simulator.							*
*					Results are then outputted to the screen and an output file.				*
*	Credit: Contributers include Nick S, Chris C, John S, and									*
*	http://www.dreamincode.net/forums/topic/77117-infix-to-postfix-conversion-and-evaluation/	*
*	http://www.dreamincode.net/forums/topic/276073-simpletron/									*
*	https://www.daniweb.com/software-development/cpp/threads/314577/simpletron-in-c-			*
*	http://faculty.cs.niu.edu/~karonis/Classes/01spring/580M/scc/node4.html						*
************************************************************************************************/

#include "SimpletronCompiler.h"
#include "InToPostFix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <iomanip>
#include "Utilities.h"

using namespace std;

// Returns location in SML that should be jumped to
// 0 checks again on the second pass.
int SimpletronCompiler::gotoToSML(string strLineNo) {
	int locationNo;

	//Get line number if statement should go to if true.
	int lineNo = atoi(strLineNo.c_str());

	if (this->isElementInSymbolTable(lineNo, 'L')) {
		locationNo = this->getSymbolTableRow(lineNo, 'L').getLocation();
	} else {
		locationNo = 0;
		flags[instructionCounter] = lineNo;
	}
	return locationNo;
}

// Converts postFix stack of operators and addresses to SML instruction sequence.
int SimpletronCompiler::postFixToSML(queue<string> postfixStack) {
	stack<int> evalStack; // Holds addresses of variables

	while (!postfixStack.empty()) {

		string currStr = postfixStack.front();
		postfixStack.pop();
		if (util::isStringNumber(currStr)) {
			int position = atoi(currStr.c_str());
			evalStack.push(position);
		}
		else {
			char op = currStr.at(0);
			// Convert postfix operations into SML commands.
			int rOperand = evalStack.top();
			evalStack.pop();

			int lOperand = evalStack.top();
			evalStack.pop();

			smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
					+ lOperand;

			switch (op) {
			case '+':
				smlInstructs[++instructionCounter] = Simpletron::ADD * 100
						+ rOperand;
				break;
			case '-':
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ rOperand;
				break;
			case '/':
				smlInstructs[++instructionCounter] = Simpletron::DIVIDE * 100
						+ rOperand;
				break;
			case '*':
				smlInstructs[++instructionCounter] = Simpletron::MULTIPLY * 100
						+ rOperand;
				break;
			}

			smlInstructs[++instructionCounter] = Simpletron::STORE * 100
					+ --dataCounter;

			evalStack.push(dataCounter);
		}
	}
	// Last address in evalStack is where result is stored after calculation, could have made this the address of variable so room for optimization.

	return evalStack.top();

}

// Check if a string is a variable value.
bool SimpletronCompiler::isStringVar(string str) {

	return str.size() == 1 && str.at(0) >= 'a' && str.at(0) <= 'z';
}

// Checks if an element of a specific type exists in the symbol table.
bool SimpletronCompiler::isElementInSymbolTable(int symbol, char type) {

	bool symbolFound = false;

	for (int i = 0; i < symbolTable.size(); i++) {
		if (symbolTable[i].getSymbol() == symbol
				&& symbolTable[i].getType() == type) {
			symbolFound = true;
			break;
		}
	}
	return symbolFound;

}

// Returns row containing symbol and type
TableEntry SimpletronCompiler::getSymbolTableRow(int symbol, char type) {

	// Search for variable, if found return.
	for (unsigned int i = 0; i < symbolTable.size(); i++) {
		if (symbolTable[i].getSymbol() == symbol
				&& symbolTable[i].getType() == type) {

			return symbolTable[i];
		}
	}

	// If variable doesn't exist then add it.
	TableEntry te(symbol, type, --dataCounter);
	symbolTable.push_back(te);
	if (type == 'C') {
		smlInstructs[dataCounter] = symbol;
	}
	return te;

}

// Initialize flags array and set instance variable values.
SimpletronCompiler::SimpletronCompiler() {
	// Flags for second pass, -1 if no pass needed.
	for (unsigned int i = 0; i < MEMSIZE; i++) {
		flags[i] = -1;
		smlInstructs[i] = 0;
	}
	dataCounter = MEMSIZE; // Point last variable was added to memory.
	instructionCounter = -1; // Last statement was added to memory.

}

// This method compiles a file specified by filename and outputs it to stream.
void SimpletronCompiler::compileFile(string filename, ostream& out) {

	ifstream in;
	in.open(filename.c_str()); //open file to compile
	if (!in) {
		cout << "infile not found";
		exit(1);
	}

	while (getline(in, oneline)) {
		istringstream iss(oneline);
		deque<string> tokens;

		copy(istream_iterator<string>(iss), istream_iterator<string>(),
				back_inserter<deque<string> >(tokens));

		int symbol = atoi(tokens.front().c_str());
		tokens.pop_front();

		// Store line number in table if it doesn't exist
		if (!(this->isElementInSymbolTable(symbol, 'L'))) {
			TableEntry te(symbol, 'L', instructionCounter + 1);
			symbolTable.push_back(te);
		}

		string command = tokens.front();
		tokens.pop_front();

		if (command == "input") {
			// Next value is a variable
			char var = tokens.front().at(0);
			tokens.pop_front();

			// Convert to SML read and get location it should be read to
			smlInstructs[++instructionCounter] = Simpletron::READ * 100
					+ this->getSymbolTableRow(var, 'V').getLocation();

		}
/////////////////////////////////////////////////////////////////////////////////
		else if (command == "let") {

			// Get variable being assigned a value
			char var = tokens.front().at(0);
			tokens.pop_front();
			tokens.pop_front();

			TableEntry varRow = this->getSymbolTableRow(var, 'V');

			ostringstream infixStream;
			while (!tokens.empty()) {
				string str = tokens.front();
				tokens.pop_front();
				if (util::isStringNumber(str)) {
					infixStream
							<< ((int) this->getSymbolTableRow(atoi(str.c_str()),
									'C').getLocation());

				} else if (SimpletronCompiler::isStringVar(str)) {
					infixStream
							<< ((int) this->getSymbolTableRow(str.at(0), 'V').getLocation());
				}

				else {
					// Store operator.
					infixStream << str;
				}
				infixStream << " ";
			}

			queue<string> postfix = infixToPostfix(infixStream.str());

			// Load from result address
			int result = this->postFixToSML(postfix);
			smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
					+ result;

			smlInstructs[++instructionCounter] = Simpletron::STORE * 100
					+ varRow.getLocation();

		}

		else if (command == "goto")
				{
			smlInstructs[++instructionCounter] = Simpletron::BRANCH * 100
					+ this->gotoToSML(tokens.front());
		}

		else if (command == "print") {
			smlInstructs[++instructionCounter] =
					Simpletron::WRITE * 100
							+ this->getSymbolTableRow(tokens.front().at(0), 'V').getLocation();

		}

		else if (command == "if") {
			// Get LHS variable
			char var = tokens.front().at(0);
			tokens.pop_front();

			TableEntry varTe = this->getSymbolTableRow(var, 'V');

			// Next value is a comparison
			string comparison = tokens.front();
			tokens.pop_front();

			// Get RHS variable
			char var2 = tokens.front().at(0);
			tokens.pop_front();

			TableEntry var2Te = this->getSymbolTableRow(var2, 'V');

			if (comparison == "==") {
				// Load LHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ varTe.getLocation();
				// subtract RHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ var2Te.getLocation();

				tokens.pop_front(); // remove "goto" statement.
				// branch zero check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHZERO
						* 100 + this->gotoToSML(tokens.front());

			} else if (comparison == "<") {
				// Load LHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ varTe.getLocation();
				// subtract RHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ var2Te.getLocation();
				tokens.pop_front(); // remove "goto" statement.
				// branch neg check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHNEG * 100
						+ this->gotoToSML(tokens.front());

			} else if (comparison == ">") {
				// Load RHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ var2Te.getLocation();
				// subtract LHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ varTe.getLocation();
				tokens.pop_front(); // remove "goto" statement.
				// branch neg check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHNEG * 100
						+ this->gotoToSML(tokens.front());

			} else if (comparison == "<=") {
				// Load LHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ varTe.getLocation();
				// subtract RHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ var2Te.getLocation();
				tokens.pop_front(); // remove "goto" statement.
				// branch neg check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHNEG * 100
						+ this->gotoToSML(tokens.front());
				smlInstructs[++instructionCounter] = Simpletron::BRANCHZERO
						* 100 + this->gotoToSML(tokens.front());

			} else if (comparison == ">=") {
				// Load RHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ var2Te.getLocation();
				// subtract LHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ varTe.getLocation();
				tokens.pop_front(); // remove "goto" statement.
				// branch neg check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHNEG * 100
						+ this->gotoToSML(tokens.front());
				smlInstructs[++instructionCounter] = Simpletron::BRANCHZERO
						* 100 + this->gotoToSML(tokens.front());

			} else if (comparison == "!=") { // Achievable by checking both less than and greater than.
				// Load LHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ varTe.getLocation();
				// subtract RHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ var2Te.getLocation();
				tokens.pop_front(); // remove "goto" statement.
				// and do branch neg check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHNEG * 100
						+ this->gotoToSML(tokens.front());
				// Load RHS into accumulator,
				smlInstructs[++instructionCounter] = Simpletron::LOAD * 100
						+ var2Te.getLocation();
				// subtract LHS from it
				smlInstructs[++instructionCounter] = Simpletron::SUBTRACT * 100
						+ varTe.getLocation();
				// and do branch neg check on condition
				smlInstructs[++instructionCounter] = Simpletron::BRANCHNEG * 100
						+ this->gotoToSML(tokens.front());
			}
		}

		else if (command == "end") {
			smlInstructs[++instructionCounter] = Simpletron::HALT * 100;
		}
	}

	in.close(); //closes in file

	// SECOND PASS OVER
	for (int i = 0; i <= instructionCounter; i++) {
		//If location of instruction unfinished...
		if (flags[i] != -1) {
			//Find Simple line number and use it to find SML line number.
			for (int j = 0; j < symbolTable.size(); j++) {
				if (symbolTable[j].getSymbol() == flags[i]
						&& symbolTable[i].getType() == 'L') {
					smlInstructs[i] += symbolTable[j].getLocation();
					break;
				}
			}
		}
	}

	// Print compiled instructions
	for (int i = 0; i < MEMSIZE; i++) {
		if (smlInstructs[i] != 0)
			out << setfill('0') << setw(2) << noshowpos << i << setfill('0')
					<< setw(5) << showpos << internal << smlInstructs[i]
					<< endl;
	}

}
