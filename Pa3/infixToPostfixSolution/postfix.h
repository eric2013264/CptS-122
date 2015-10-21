/**********************************************************************************
 * Programmer: Andrew S. O'Fallon                                                 *
 * Class: Cpt S 122; Lab Section 0                                                *
 * Programming Assignment: A solution to PA 3.                                    *
 * Date:                                                                          *
 *                                                                                *
 * Description:                                                                   *
 *                                                                                *
 *********************************************************************************/

#ifndef POSTFIX_H
#define POSTFIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

 struct stackNodeInt
{
	int data;
	struct stackNodeInt *nextPtr;
}; // Used with the evaluation of the postfix expression

typedef struct stackNodeInt StackNodeInt;
typedef StackNodeInt * StackNodeIntPtr;

int evaluatePostfixExpression (char *expr); // Evaluate the postfix expression.
int calculate (int op1, int op2, char operator1); // Evaluate the expression op1 operator op2.

StackNodeIntPtr makeIntStackNode (int value);
void pushInt (StackNodeIntPtr *topPtr, int value); // Push an integer value on the stack.
int popInt (StackNodeIntPtr *topPtr); // Pop an integer value off the stack.
int isEmptyInt (StackNodeIntPtr topPtr); // Determine if the stack is empty
void printIntStack (StackNodeIntPtr topPtr); // Print the stack.

#endif