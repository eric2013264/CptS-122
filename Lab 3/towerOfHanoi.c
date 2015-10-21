#include "lab3.h"
#include "towerOfHanoi.h"

// This will initilize Peg A with n discs on it, and Peg B and C wil nothing. 
// We will structure our program to always move from Peg A to Peg C
void setUpGame(int numNodes, Peg **A, Peg **B, Peg **C)
{
	int i;
	StackNode *temp;

	// Allocate memory for Pegs A, B, and C
	(*A) = (Peg *)malloc(sizeof(Peg));
	(*B) = (Peg *)malloc(sizeof(Peg));
	(*C) = (Peg *)malloc(sizeof(Peg));

	// Assign names to the Pegs
	(*A)->name = 'A';
	(*B)->name = 'B';
	(*C)->name = 'C';

	// Peg B and C will not initially start with discs, so we initilize their stackNodes to NULL
	(*B)->hPtr = NULL;
	(*C)->hPtr = NULL;

	// Create the discs for Peg A
	(*A)->hPtr = (StackNode *)malloc(sizeof(StackNode));


	(*A)->hPtr->data = 1.0;
	temp = (*A)->hPtr;

	for (i = 2; i <= numNodes; i++)
	{
		temp->next = (StackNode *)malloc(sizeof(StackNode));
		temp->next->data = (double)i;

		temp = temp->next;
	}

	// Make the stack end with a null pointer
	temp->next = NULL;

	return;

}

void towers(int n, Peg **frompeg, Peg **topeg, Peg **auxpeg)
{ /* If only 1 disk, make the move and return */
	if (n == 1)
	{
		printf("Move disk 1 from peg %c to peg %c\n", (*frompeg)->name, (*topeg)->name);
		MoveStackNode(&((*topeg)->hPtr), &((*frompeg)->hPtr));
		return;
	}
	

	/* Move top n-1 disks from A to B, using C as auxiliary */
	towers(n - 1, frompeg, auxpeg, topeg);

	/* Move remaining disks from A to C */
	printf("Move disk %d from peg %c to peg %c\n", n, (*frompeg)->name, (*topeg)->name);


	/* Move n-1 disks from B to C using A as auxiliary */
	towers(n - 1, auxpeg, topeg, frompeg);
}

void MoveStackNode(StackNode **toPeg, StackNode **fromPeg)
{
	StackNode *temp;
	double data = (*fromPeg)->data;

	pop(fromPeg);
	push(toPeg, data);

	return;
}