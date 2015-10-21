/**********************************************************************************
 * Programmer: Andrew S. O'Fallon                                                 *
 * Class: Cpt S 122; Lab Section 0                                                *
 * Programming Assignment: A solution to PA 3.                                    *
 * Date:                                                                          *
 *                                                                                *
 * Description: This file implements all of the stack operations required to      *
 *              evaluate the postfix expression.                                  *
 *                                                                                *
 *********************************************************************************/

#include "postfix.h"
#include "infix.h"

/***************************************************************************************************
 * Function: evaluatePostfixExpression ()                                                          *
 * Date Created:                                                                                   *
 * Date Last Modified:                                                                             *
 * Description:                                                                                    *
 *	(1) Append the null character ('\0') to the end of the postfix expression.                     *
 *	    When the null character is encountered, no further processing is necessary.                *
 *  (2) While '\0' has not been encountered, read the expression from left to right.               *
 *			(a) If the current character is a digit,                                               *
 *					Push its integer value onto the stack (the integer value of a digit character  *
 *						is its value in the computer's set minus the                               *
 *							value of '0' in the computer's character set).                         *
 *			(b) Otherwise, if the current character is an operator,                                *
 *					Pop the two top elements of the stack into variables x and y.                  *
 *					Calculate y operator x.                                                        *
 *					Push the result of the calculation onto the stack.                             *
 *   (3) When the null character is encountered in the expression, pop the top value of the stack. *
 *		 This is the result of the postfix expression.                                             *
 * Input parameters: The postfix expression.                                                       *
 * Returns: The integer result of the evaluation of the postfix expression.                        *
 * Preconditions:                                                                                  *
 * Postconditions:                                                                                 *
 ***************************************************************************************************/

int evaluatePostfixExpression (char *expr)
{
	int result = 0, index = 0, x = 0, y = 0;
	StackNodeIntPtr topPtr = NULL;

	// Step 1 of algorithm was completed at the end of the convert infix to postfix algorithm!

	while (expr[index] != '\0') // Step 2
	{
		if (isdigit (expr[index])) // Step 2a
		{
			pushInt (&topPtr, (expr[index] - '0')); 
			printIntStack (topPtr);
		}
		else if (isOperator (expr[index])) // Step 2b
		{
			x = popInt (&topPtr);
			y = popInt (&topPtr);
			result = calculate (y, x, expr[index]);
			pushInt (&topPtr, result);
			printIntStack (topPtr);
		}

		index++;
	}

	result = popInt (&topPtr);
	printIntStack (topPtr);

	return result;
}

/*************************************************************
 * Function: calculate ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int calculate (int op1, int op2, char operator1)
{
	int result = 0;

	switch (operator1)
	{
		case '^': result = (int) pow (op1, op2);
			      break;
		case '%': result = op1 % op2;
			      break;
		case '*': result = op1 * op2;
			      break;
		case '/': result = op1 / op2;
			      break;
		case '+': result = op1 + op2;
			      break;
		case '-': result = op1 - op2;
			      break;
	}

	return result;
}

/*************************************************************
 * Function: makeIntStackNode ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

StackNodeIntPtr makeIntStackNode (int value)
{
	StackNodeIntPtr newNodePtr = NULL;

	newNodePtr = (StackNodeIntPtr) malloc (sizeof (StackNodeInt));

	if (newNodePtr != NULL)
	{
		newNodePtr -> data = value;
		newNodePtr -> nextPtr = NULL;
	}

	return newNodePtr;
}

/*************************************************************
 * Function: pushInt ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function creates a node to place on     *
 *              top of the stack with int data "value".      *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void pushInt (StackNodeIntPtr *topPtr, int value)
{
	StackNodeIntPtr tempPtr = NULL;

	tempPtr = makeIntStackNode (value);

	if (tempPtr == NULL)
	{
		printf ("WARNING: Could not push () value, no memory available!\n");
	}
	else
	{
		(tempPtr -> nextPtr) = *topPtr;
		*topPtr = tempPtr;
	}
}

/*************************************************************
 * Function: popInt ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function removes a node from the top    *
 *              of the stack.                                *
 * Input parameters:                                         *
 * Returns: The int data from the top of the stack.          *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int popInt (StackNodeIntPtr *topPtr)
{
	int value = 0;
	StackNodeIntPtr tempPtr = NULL;

	if (isEmptyInt (*topPtr))
	{
		printf ("WARNING: Cannot pop (), stack is empty!\n");
	}
	else
	{
		tempPtr = *topPtr;
		value = (*topPtr) -> data;
		*topPtr = (*topPtr) -> nextPtr;
		free (tempPtr);
	}

	return value;
}

/*************************************************************
 * Function: isEmptyInt ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns: 1 if the stack is empty, 0 otherwise.            *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int isEmptyInt (StackNodeIntPtr topPtr)
{
	return (topPtr == NULL);
}

/*************************************************************
 * Function: printIntStack ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Prints the stack used to evaluate the postfix*
 *              expression.                                  *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void printIntStack (StackNodeIntPtr topPtr)
{
	printf ("The postfix stack is:\n");
	printf ("  --  \n");
	while (!isEmptyInt (topPtr))
	{
		printf ("| %d  |\n", topPtr -> data);
		printf ("  --  \n");
		topPtr = topPtr -> nextPtr;
	}
}