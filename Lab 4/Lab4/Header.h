#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum boolean
{
	FALSE, TRUE
}Boolean;

typedef struct node
{
	Contact *pContact;
	struct node *next;
}Node;

typedef struct queue
{
	struct node *pHead;
	struct node *pTail;
}Node;

#endif
