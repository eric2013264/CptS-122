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

#include "SuperMarketSim.h"

/*************************************************************
 * Function: randomTime ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Generates an int time between 1 and 4 minutes*
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

int randomTime (void)
{
	int time = 0;

	time = (rand () % 4) + 1; // Need to randomly determine arrival and service times 
	                          // between 1 and 4 minutes

	return time;
}

/*************************************************************
 * Function: supermarketSimulation ()                        *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void supermarketSimulation (void)
{
	int minutesOfDay = 0, nextArrivalTime = 0, 
		currentServiceTime = 0, newCustomer = 0, customerServiced = 0, inService = 0;
	QueueNodePtr headPtr = NULL, tailPtr = NULL;

	srand ((unsigned) time (NULL)); // Seed the random number generator

	nextArrivalTime = randomTime (); // Arrival time of first customer

	while (minutesOfDay <= 720) // Run simulation for 720 minutes
	{
		if (inService) // A customer is currently being serviced
		{
			currentServiceTime--;
		}

		if (nextArrivalTime == minutesOfDay) // Has a new customer showed up?
		{
			newCustomer++; // Assign customer number
			printf ("Customer %d has arrived in line at minute %d!\n", newCustomer, minutesOfDay);

			if (!inService) // If not currently servicing a customer, then immediately help customer
			{
				currentServiceTime = randomTime (); // How long will it take to service customer?
				customerServiced = newCustomer; // What is the number of the customer being helped?
				inService = 1; // Currently servicing a customer
				printf ("Starting to service customer %d at minute %d, will finish in %d minutes!\n", customerServiced, minutesOfDay, currentServiceTime);
			}
			else // A customer is currently being serviced, must wait in line
			{
				enqueue (&headPtr, &tailPtr, newCustomer); // The new customer enters at the back of the line
			}
			
			nextArrivalTime += randomTime (); // Determine the time that the next customer will arrive
			printQueue (headPtr); // Show the status of the line
		}

		if (currentServiceTime == 0) // A customer has finished being serviced?
		{
			if (!isEmpty (headPtr)) // If the line is not empty, service the next customer in line
			{
				printf ("Customer %d has finished being serviced at minute %d!\n", customerServiced, minutesOfDay);
				customerServiced = dequeue (&headPtr, &tailPtr); // Help the next customer
				currentServiceTime = randomTime (); // Determine amount of time to service current customer
				inService = 1;
				printf ("Starting to service customer %d at minute %d, will finish in %d minutes!\n", customerServiced, minutesOfDay, currentServiceTime);
				printQueue (headPtr); // Show the status of the line
			}
			else if (inService) // No more people in line
			{
				printf ("Customer %d has finished being serviced at minute %d!\n", customerServiced, minutesOfDay);
				inService = 0;
			}
			else // No one to service
			{
				inService = 0;
				currentServiceTime = 0;
			}
		}
	
		minutesOfDay++; // 1 more simulated minute has passed
	}
}