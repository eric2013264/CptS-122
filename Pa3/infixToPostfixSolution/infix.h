/**********************************************************************************
 * Programmer: Andrew S. O'Fallon                                                 *
 * Class: Cpt S 122; Lab Section 0                                                *
 * Programming Assignment: A solution to PA 3.                                    *
 * Date:                                                                          *
 *                                                                                *
 * Description:                                                                   *
 *                                                                                *
 *********************************************************************************/

#ifndef INFIX_H
#define INFIX_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

enum boolean
{
	FALSE, TRUE
};

typedef enum boolean Boolean;

struct stackNodeChar
{
	char data;
	struct stackNodeChar *nextPtr;
}; // Used with the conversion from infix to postfix

typedef struct stackNodeChar StackNodeChar;
typedef StackNodeChar * StackNodeCharPtr;

void convertToPostfix (char infix[], char postfix[]); // Convert the infix expression to postfix notation
int isOperator (char c); // Determine if c is an operator
int precedence (char operator1, char operator2); // Determine if the precedence of operator1 is less than, equal to, or greater than the precedence
	                                                // of operator2. The function returns -1, 0, and 1, respectively.
StackNodeCharPtr makeStackNode (char value);
void push (StackNodeCharPtr *topPtr, char value); // Push a value on the stack.
char pop (StackNodeCharPtr *topPtr); // Pop a value off the stack.
char stackTop (StackNodeCharPtr topPtr); // Return the top value of the stack without popping the stack.
int isEmptyChar (StackNodeCharPtr topPtr); //Determine if the stack is empty.
void printCharStack (StackNodeCharPtr topPtr); // Print the stack.

#endif