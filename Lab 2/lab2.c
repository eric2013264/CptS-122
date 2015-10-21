#include "lab2.h"



/************************ Linked List Functions ************************************/
void Insert(Node **hPtr)
{
	Node *curr, *prev = NULL;
	Node *newNode;
	BOOL success = FALSE;

	// Special case for head
	if((*hPtr) == NULL)
	{
		(*hPtr) = (Node *)malloc(sizeof(Node));

		if((*hPtr) != NULL)
		{
			(*hPtr)->contact = CreateContact();
			(*hPtr)->next = NULL;

			success = TRUE;
		}




	}
	else
	{
		newNode = (Node *)malloc(sizeof(Node));

		if(newNode != NULL)
		{
			newNode->next = NULL;
			newNode->contact = CreateContact();

			curr = (*hPtr);

			while((curr->next != NULL) && (strcmp(newNode->contact.last, curr->contact.last) == 1))
			{
				prev = curr;
				curr = curr->next;

			}

			// We insert at the end
			if(curr->next == NULL && curr != (*hPtr))
			{
				curr->next = newNode;
			}
			else
			{
				// This is when the new node created will become the head pointer, 
				// because the last name comes before the headPtr last name
				if(prev == NULL)
				{
					newNode->next = (*hPtr);
					(*hPtr) = newNode;
				}
				else	// This is when the new node is inserted into the "middle" of the list
				{
					Node *swap;
					swap = prev->next;
					prev->next = newNode;
					newNode->next = swap;
				}

			}

			success = TRUE;
		}


		
	}

	if(success == TRUE)
	{
		printf("Insert successful.\n");
	}
	else
	{
		printf("Unable to insert into list.\n");
	}



	return;

}

void Remove(Node **hPtr, char first[32], char last[32])
{
	BOOL found = FALSE;
	Node *curr, *prev = NULL;

	curr = (*hPtr);

	while(curr != NULL)
	{
		if(strcmp(curr->contact.first, first) == 0 && strcmp(curr->contact.last, last) == 0)		// We have found the node to delete
		{
			// Special case if curr is the head node
			if(curr == (*hPtr))
			{
				(*hPtr) = (*hPtr)->next;

			}
			else
			{
				prev->next = curr->next;
			}

			free(curr);
			found = TRUE;
			break;
		}
		prev = curr;
		curr = curr->next;
	}


	if(found == FALSE)
	{
		printf("Remove completed successfully.\n");
	}
	else
	{
		printf("Couldn't find node to delete.\n");
	}
}

void Edit(Node **hPtr, char first[32], char last[32])
{
	BOOL found = FALSE;
	Node *curr;
	char data[64];
	curr = (*hPtr);

	while(curr != NULL)
	{
		if(strcmp(curr->contact.first, first) == 0 && strcmp(curr->contact.last, last) == 0)		// We have found the node to edit
		{
			printf("Enter new first name: ");
			scanf("%s", data);
			strcpy(curr->contact.first, data);

			printf("Enter new last name: ");
			scanf("%s", data);
			strcpy(curr->contact.last, data);

			printf("Enter new phone number: ");
			scanf("%s", data);
			strcpy(curr->contact.number, data);

			printf("Enter new email: ");
			scanf("%s", data);
			strcpy(curr->contact.email, data);

			printf("Enter new title: ");
			scanf("%s", data);
			strcpy(curr->contact.title, data);

			found = TRUE;

			break;
		}

		curr = curr->next;

	}


	if(found == TRUE)
	{
		printf("Edit completed successfully.\n");
	}
	else
	{
		printf("Couldn't find node to edit.\n");
	}
}

void Print(Node *hPtr)
{
	Node *curr = hPtr;

	while(curr != NULL)
	{
		printf("First Name: %s\n", curr->contact.first);
		printf("Last Name: %s\n", curr->contact.last);
		printf("Phone Number: %s\n", curr->contact.number);
		printf("Email: %s\n", curr->contact.email);
		printf("Title: %s\n", curr->contact.title);

		printf("\n");

		curr = curr->next;

	}
}

void Store(Node *hPtr, FILE *infile)
{
	BOOL success = FALSE;
	FILE *file = NULL;
	Node *curr;


	file = fopen("myfile.txt", "w");

	if(file != NULL)
	{
		curr = hPtr;

		while(curr != NULL)
		{
			fprintf(file, "%s,%s,%s,%s,%s\n", curr->contact.first, curr->contact.last, curr->contact.number, curr->contact.email, curr->contact.title);
			curr = curr->next;
		}

		success = TRUE;

		fclose(file);
	}

	if(success == TRUE)
	{
		printf("Store function stored list successfully.\n");
	}
	else
	{
		printf("Unable to print to file.\n");
	}



}

void Load(Node **hPtr)
{
	int i;
	char buf[64], *token = NULL;
	FILE *file = NULL;
	Node *curr, *temp;
	BOOL success = FALSE;

	// Clear and free all contents of list
	curr = (*hPtr);

	while(curr != NULL)
	{
		temp = curr;
		curr = curr->next;

		free(temp);
	}
	(*hPtr) = NULL;


	file = fopen("myfile.txt", "r");

	if(file != NULL)
	{
		while(fgets(buf, 64, file) != NULL)
		{
			TrimNewLine(buf);

			if((*hPtr) == NULL)
			{
				token = strtok(buf, ",");

				(*hPtr) = (Node *)malloc(sizeof(Node));
				(*hPtr)->next = NULL;

				// copy in information into new head pointer
				strcpy((*hPtr)->contact.first, token);
				token = strtok(NULL, ",");
				strcpy((*hPtr)->contact.last, token);
				token = strtok(NULL, ",");
				strcpy((*hPtr)->contact.number, token);
				token = strtok(NULL, ",");
				strcpy((*hPtr)->contact.email, token);
				token = strtok(NULL, ",");
				strcpy((*hPtr)->contact.title, token);

			}
			else
			{
				token = strtok(buf, ",");

				curr = (*hPtr);

				while(curr->next != NULL)
				{
					curr = curr->next;
				}

				curr->next = (Node *)malloc(sizeof(Node));
				curr->next->next = NULL;

				// copy in information into new node
				strcpy(curr->next->contact.first, token);
				token = strtok(NULL, ",");
				strcpy(curr->next->contact.last, token);
				token = strtok(NULL, ",");
				strcpy(curr->next->contact.number, token);
				token = strtok(NULL, ",");
				strcpy(curr->next->contact.email, token);
				token = strtok(NULL, ",");
				strcpy(curr->next->contact.title, token);
			}

		}

		success = TRUE;
		fclose(file);
	}

	

	if(success == TRUE)
	{
		printf("File loaded successfully.\n");
	}
	else
	{
		printf("Unable to load from file.\n");
	}

}


/************************ Utility Functions ************************************/
void PrintOptionsMenu()
{
	printf("\n");
	printf("Select a number from the list:\n");
	printf("1.) Insert Contact into List\n");
	printf("2.) Remove Contact From List\n");
	printf("3.) Edit Contact From List\n");
	printf("4.) Print Contact List\n");
	printf("5.) Store List to File\n");
	printf("6.) Load List from File\n");
	printf("7.) Quit\n");
}

Contact CreateContact()
{
	Contact newContact;

	printf("\n");
	printf("Enter first name: ");
	scanf("%s", &newContact.first);
	printf("Enter last name: ");
	scanf("%s", &newContact.last);
	printf("Enter number: ");
	scanf("%s", &newContact.number);
	printf("Enter email: ");
	scanf("%s", &newContact.email);
	printf("Enter title: ");
	scanf("%s", &newContact.title);

	// We can return by VALUE here
	return newContact;
}

void TrimNewLine(char *str)
{
	int endIndex = strlen(str) - 1;

	str[endIndex] = '\0';

	return;
}










