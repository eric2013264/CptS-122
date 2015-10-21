#ifndef LAB3_H
#define LAB3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stackNode
{
	double data;
	struct stackNode *next;
} StackNode;

typedef enum boolean
{
	FALSE, TRUE
} Boolean;


Boolean push(StackNode **hPtr, double width);
Boolean pop(StackNode **hPtr);
double top(StackNode *hPtr);
Boolean isEmpty(StackNode *hPtr);




#endif


