#include "lab3.h"



void testPush(StackNode **hPtr)
{
	Boolean flag = TRUE;
	int i;
	double width = 0.0;

	srand(time(NULL));

	// create width to be pushed to stack
	width = rand() % 10 + .5;

	if (push(hPtr, width))
	{
		printf("Push() succeeded!\n");
	}
	else
	{
		printf("Push() failed.\n");
	}
	
	return;

}

void testPop(StackNode **hPtr)
{
	StackNode *temp = (*hPtr);
	

	if (pop(hPtr))
	{
		printf("Pop() succeeded!\n");
	}
	else
	{
		printf("Pop() failed.\n");
	}

	return;
}

void testIsEmpty(StackNode *hPtr)
{
	Boolean check = FALSE;
	Boolean functionCheck;

	if (hPtr == NULL)
	{
		check = TRUE;
	}

	functionCheck = isEmpty(hPtr);

	if (functionCheck != check)
	{
		printf("IsEmpty() failed.\n");
	}
	else
	{
		printf("IsEmpty() succeeded!\n");
	}

	return;

}

void testTop(StackNode *hPtr)
{
	double width;
	double functionwidth;

	if (hPtr == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}

	width = hPtr->data;
	functionwidth = top(hPtr);

	if (width != functionwidth)
	{
		printf("top() failed.\n");
	}
	else
	{
		printf("top() succeeded!\n");
	}

	return;

}

