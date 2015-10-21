/**********************************************************************************
 * Programmer: Andrew S. O'Fallon                                                 *
 * Class: Cpt S 122; Lab Section 0                                                *
 * Programming Assignment: A solution to PA 3.                                    *
 * Date:                                                                          *
 *                                                                                *
 * Description: This program is responsible for obtaining a infix expression from * 
 *              the user. It then converts it to a postfix expression and         *
 *              the result.                                                       *
 *                                                                                *
 *********************************************************************************/

#include "infix.h"
#include "postfix.h"

int main (void)
{
	char infix[MAX] = {'\0'}, postfix[MAX] = {'\0'};
	int postfixResult = 0;

	printf ("Enter infix expression: ");
	gets (infix);

	convertToPostfix (infix, postfix);

	printf ("Postfix expression: %s\n", postfix);

	postfixResult = evaluatePostfixExpression (postfix);

	printf ("Postfix expression evaluated as: %d\n", postfixResult);

	return 0;
}