#include "Header.h"

void enqueue(Queue *pQ, int data)
{
	Node *pMem = makeNode(data);
	if (pQ=>pHead == NULL)
	{
		pQ->pHead = pMem;
		pQ->pTail = pMem;
	}
	else
	{
		pQ->pTail->pNext=pMem;
		pQ->pTail=pQ->pTail->pNext;
	}
}