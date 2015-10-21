#include "lab3.h"

// This function adds a StackNode to the top of the stack
// It is similiar to the InsertAtFront() function in linked lists.
// Remember, you can only "add" to the top of the stack, and "take away" from the 
// top of a stack! These actions are called "push" and "pop".
Boolean push(StackNode **hPtr, double data)
{
	Boolean status = FALSE;
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	
	// Check that the memory was allocated
	if (temp != NULL)
	{
		// Since we entered the if statement here, we will return true
		status = TRUE;

		// Set the data and the next pointer
		temp->data = data;
		temp->next = NULL;

		// If we don't have any StackNodes in the stack yet, we will 
		// assign the head pointer equal to the newly created node.
		if ((*hPtr) == NULL)
		{
			(*hPtr) = temp;
		}
		else		// This is if we already have StackNodes in our stack.
		{
			// Since we ONLY add to the top in stack nodes, we set the next pointer
			// of temp to the original head pointer.
			temp->next = (*hPtr);
			// Now we have to change the head pointer to point to the newly created
			// StackNode, which we named temp.
			(*hPtr) = temp;
		}

	}
	
	// we return true or false
	return status;
}

// This function pops off the top StackNode. 
// If there isn't anything in the stack, we return false.
Boolean pop(StackNode **hPtr)
{
	Boolean status = FALSE;
	StackNode *temp = NULL;

	// We cannot pop off a StackNode if there's nothing to pop!
	if (*hPtr == NULL)
	{
		printf("Nothing to pop!\n");
	}
	else		// Case if there is a StackNode to pop off.
	{
		status = TRUE;
		// We have to "hang on" to the memory address associated with (*hPtr), otherwise we would lost it!
		temp = (*hPtr);

		// Change head pointer to the next StackNode down on the stack
		(*hPtr) = (*hPtr)->next;

		// Free memory associated with the old head pointer.
		free(temp);
	}

	

	return status;

	
}

// This returns the data of the top StackNode.
// Remember, with a stack we are only supposed to know the data at the top of the 
// stack. We cannot look at the other node data until they become the top node.
// This is why it is called a stack.
double top(StackNode *hPtr)
{
	return hPtr->data;
}

// If the head StackNode is null, we know that the stack is empty.
// We return true if the stack is empty, and false if it is not.
Boolean isEmpty(StackNode *hPtr)
{
	Boolean empty = FALSE;
	if (hPtr == NULL)
	{
		empty = TRUE;
	}

	return empty;
}











