#include "lab3.h"
#include "testStack.h"
#include "towerOfHanoi.h"



int main()
{
	StackNode *stack = NULL;
	Peg *A = NULL, *B = NULL, *C = NULL;
	int numDiscs = 0;

	// Stack stuff
	testPush(&stack);
	testPush(&stack);
	testPop(&stack);
	testIsEmpty(stack);
	testTop(stack);


	// Hanoi Stuff
	printf("Enter number of discs: ");
	scanf("%d", &numDiscs);

	setUpGame(numDiscs, &A, &B, &C);
	towers(numDiscs, &A, &C, &B);




	return 0;
}