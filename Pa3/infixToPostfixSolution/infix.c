/**********************************************************************************
 * Programmer: Andrew S. O'Fallon                                                 *
 * Class: Cpt S 122; Lab Section 0                                                *
 * Programming Assignment: A solution to PA 3.                                    *
 * Date:                                                                          *
 *                                                                                *
 * Description: This file implements all of the stack operations required to      *
 *              convert an infix expression to a postfix expression.              *
 *                                                                                *
 *********************************************************************************/

#include "infix.h"

/***************************************************************************************************
 * Function: convertToPostfix ()                                                                   *
 * Date Created:                                                                                   *
 * Date Last Modified:                                                                             *
 * Description:  (infix to postfix algorithm):                                                     *
	(1) Push a left parenthesis '(' onto the stack.                                                *
	(2) Append a right parenthesis ')' to the end of infix.                                        *
	(3) While the stack is not empty, read infix from left to right and do the following:          *
		(a) If the current character in infix is a digit, copy it to the next element of postfix.  *
		(b) If the current character in infix is a left parenthesis, push it onto the stack.       *
		(c) If the current character in infix is an operator,                                      *
				Pop operators (if there are any) at the top of the stack while they have equal or  *
					higher precedence than the current operator, and insert the popped operators   *
					in postfix.                                                                    *
				Push the current character in infix onto the stack.                                *
		(d) If the current character in infix is a right parenthesis                               *
				Pop operators from the top of the stack and insert them in postfix until a left    *
					parenthesis is at the top of the stack.                                        *
				Pop (and discard) the left parenthesis from the stack.                             *
 * Input parameters: An infix expression and postfix expression.                                   *
 * Returns: The postfix expression.                                                                *
 * Preconditions: Have obtained an infix expression from the user.                                 *
 * Postconditions:                                                                                 *
 ***************************************************************************************************/

void convertToPostfix (char infix[], char postfix[])
{
	int infixIndex = 0, postfixIndex = 0;
	char topValue = '\0';
	StackNodeCharPtr topPtr = NULL;

	push (&topPtr, '('); // Step 1 of infix to postfix algorithm
	printCharStack (topPtr);

	strcat (infix, ")"); // Step 2 of infix to postfix algorithm

	while (!isEmptyChar (topPtr))
	{
		if (isdigit (infix[infixIndex])) // Step 3a
		{
			postfix[postfixIndex++] = infix[infixIndex];
		}
		else if (infix[infixIndex] == '(') // Step 3b
		{
			push (&topPtr, '(');
			printCharStack (topPtr);
		}
		else if (isOperator (infix[infixIndex])) // Step 3c
		{
			topValue = stackTop (topPtr);
			while ((isOperator (topValue)) && (precedence (infix[infixIndex], topValue) != 1))
			{
				postfix[postfixIndex++] = pop (&topPtr);
				topValue = stackTop (topPtr);
			}
			push (&topPtr, infix[infixIndex]);
			printCharStack (topPtr);
		}
		else if (infix[infixIndex] == ')') // Step 3d
		{
			topValue = stackTop (topPtr);
			while ((isOperator (topValue)) && (topValue != '('))
			{
				postfix[postfixIndex++] = pop (&topPtr);
				topValue = stackTop (topPtr);
				printCharStack (topPtr);
			}
			pop (&topPtr);
			printCharStack (topPtr);
		}

		infixIndex++;
	}

	postfix[postfixIndex] = '\0';
}

/*************************************************************
 * Function: isOperator ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Determines if the character passed in is an  *
 *              operator, i.e. '^', '*', '/', '%', '+', '-'  *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int isOperator (char c)
{
	Boolean result = FALSE;

	if ((c == '^') || (c == '%') || (c == '/') || (c == '*') || (c == '+') || (c == '-'))
	{
		result = TRUE;
	}

	return ((int) result);
}

/*************************************************************
 * Function: precedence ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Determines the operator precedence relative  *
 *              to 2 operators.                              *
 * Input parameters:                                         *
 * Returns: -1 if op1 < op2, 0 if op1 == op2, 1 if op1 > op2 *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int precedence (char operator1, char operator2)
{
	int op1Precedence = 0, op2Precedence = 0, finalPrecedence = 0;

	switch (operator1)
	{
		case '^': op1Precedence = 3; // highest precedence
			      break;
		case '*': op1Precedence = 2;
			      break;
		case '/': op1Precedence = 2;
			      break;
		case '%': op1Precedence = 2;
			      break;
		case '+': op1Precedence = 1; // lowest precedence
			      break;
		case '1': op1Precedence = 1;
			      break;	
	}

	switch (operator2)
	{
		case '^': op2Precedence = 3; // highest precedence
			      break;
		case '*': op2Precedence = 2;
			      break;
		case '/': op2Precedence = 2;
			      break;
		case '%': op2Precedence = 2;
			      break;
		case '+': op2Precedence = 1; // lowest precedence
			      break;
		case '1': op2Precedence = 1;
			      break;	
	}

	if (op1Precedence < op2Precedence)
	{
		finalPrecedence = -1;
	}
	else if (op1Precedence > op2Precedence)
	{
		finalPrecedence = 1;
	}

	return finalPrecedence;
}

/*************************************************************
 * Function: makeStackNode ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

StackNodeCharPtr makeStackNode (char value)
{
	StackNodeCharPtr newNodePtr = NULL;

	newNodePtr = (StackNodeCharPtr) malloc (sizeof (StackNodeChar));

	if (newNodePtr != NULL)
	{
		newNodePtr -> data = value;
		newNodePtr -> nextPtr = NULL;
	}

	return newNodePtr;
}

/*************************************************************
 * Function: push ()                                         *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function creates a node to place on     *
 *              top of the stack with char data "value".     *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void push (StackNodeCharPtr *topPtr, char value)
{
	StackNodeCharPtr tempPtr = NULL;

	tempPtr = makeStackNode (value);

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
 * Function: pop ()                                          *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function removes a node from the top    *
 *              of the stack.                                *
 * Input parameters:                                         *
 * Returns: The char data from the top of the stack.         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

char pop (StackNodeCharPtr *topPtr)
{
	char value = '\0';
	StackNodeCharPtr tempPtr = NULL;

	if (isEmptyChar (*topPtr))
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
 * Function: stackTop ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns: The char data from the top of the stack.         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

char stackTop (StackNodeCharPtr topPtr)
{
	char topData = '\0';

	if (isEmptyChar (topPtr))
	{
		printf ("WARNING: No data in the stack!\n");
	}
	else
	{
		topData = topPtr -> data;
	}

	return topData;
}

/*************************************************************
 * Function: isEmptyChar ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns: 1 if the stack is empty, 0 otherwise.            *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int isEmptyChar (StackNodeCharPtr topPtr)
{
	return (topPtr == NULL);
}

/*************************************************************
 * Function: printCharStack ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Prints the stack used to convert from infix  *
 *              to postfix.                                  *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void printCharStack (StackNodeCharPtr topPtr)
{
	printf ("The infix stack is:\n");
	printf ("  --  \n");
	while (!isEmptyChar (topPtr))
	{
		printf ("| %c  |\n", topPtr -> data);
		printf ("  --  \n");
		topPtr = topPtr -> nextPtr;
	}
}