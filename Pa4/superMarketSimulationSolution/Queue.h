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

#ifndef QUEUE_H
#define QUEUE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode
{
	int customer;
	struct queueNode *nextPtr;
} QueueNode;

typedef QueueNode* QueueNodePtr;

QueueNodePtr makeQueueNode (int newCustomer);
int isEmpty (QueueNodePtr headPtr);
void printQueue (QueueNodePtr headPtr);
int dequeue (QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue (QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int newCustomer);

#endif