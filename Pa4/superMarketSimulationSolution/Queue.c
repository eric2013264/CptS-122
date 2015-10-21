/**********************************************************************************
 * Programmer: Andrew S. O'Fallon                                                 *
 * Class: Cpt S 122; Lab Section 0                                                *
 * Programming Assignment: A solution to PA 4.                                    *
 * Date:                                                                          *
 *                                                                                *
 * Description: This program is responsible simulating a customer line at a       *
 *              supermaket.                                                       *
 *                                                                                *
 *********************************************************************************/

#include "Queue.h"

/*************************************************************
 * Function: makeQueueNode ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

QueueNodePtr makeQueueNode (int newCustomer)
{
	QueueNodePtr tempPtr = NULL;

	tempPtr = (QueueNodePtr) malloc (sizeof (QueueNode));

	tempPtr -> customer = newCustomer;
	tempPtr -> nextPtr = NULL;

	return tempPtr;
}

/*************************************************************
 * Function: isEmpty ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int isEmpty (QueueNodePtr headPtr)
{
	return (headPtr == NULL);
}

/*************************************************************
 * Function: printQueue ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void printQueue (QueueNodePtr headPtr)
{
	printf ("\nQueue is:");
	while (headPtr != NULL)
	{
		printf ("|%d| ", headPtr -> customer);
		headPtr = headPtr -> nextPtr;
	}
	printf ("\n\n");
}

/*************************************************************
 * Function: dequeue ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions: Assume queue cannot be empty!              *
 * Postconditions:                                           *
 *************************************************************/

int dequeue (QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	QueueNodePtr tempPtr = NULL;
	int currentCustomer = 0;

	if (!isEmpty (*headPtr))
	{
		tempPtr = (*headPtr);
		currentCustomer = (*headPtr) -> customer;

		if ((*headPtr) == (*tailPtr))
		{ 
			(*tailPtr) = (*headPtr) = NULL;
		}
		else
		{
			(*headPtr) = (*headPtr) -> nextPtr;
		}

		free (tempPtr);
	}

	return currentCustomer;
}

/*************************************************************
 * Function: enqueue ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void enqueue (QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int newCustomer)
{
	QueueNodePtr tempPtr = NULL;

	tempPtr = makeQueueNode (newCustomer);

	if (isEmpty (*headPtr)) // Queue is empty
	{
		*tailPtr = *headPtr = tempPtr;
	}
	else // Queue is not empty
	{
		(*tailPtr) -> nextPtr = tempPtr;
		(*tailPtr) = (*tailPtr) -> nextPtr;
	}
}