#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include "lab3.h"

typedef struct peg
{
	StackNode *hPtr;
	char name;
} Peg;

void setUpGame(int numNodes, Peg **A, Peg **B, Peg **C);
void towers(int n, Peg **frompeg, Peg **topeg, Peg **auxpeg);
void MoveStackNode(StackNode **fromPeg, StackNode **toPeg);


#endif