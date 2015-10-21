/****************************************************************************************
* Programmer: Eric Chen																	*
* Class: CptS 122, Fall 2014; Lab Section 4												*
* Programming Assignment: PA2								 						    *
* Date: Spet 22, 2014															        *
* Description: DMM that is missing some functionality. Sorts based on record/album name	*
*****************************************************************************************/

#include "PA2.h"

Node *InitNode()
{
	Node *pNewNode = NULL;

	pNewNode = (Node *)malloc(sizeof(Node));

	if (pNewNode != NULL)
	{
		pNewNode->pRecord = (Record *)malloc(sizeof(Record));

		if (pNewNode->pRecord != NULL)
		{
			pNewNode->next = NULL;

			pNewNode->pRecord->artist = NULL;

			pNewNode->pRecord->album_title = NULL;

			pNewNode->pRecord->song_title = NULL;

			pNewNode->pRecord->genre = NULL;
		}
	}

	return pNewNode;
}

Node *MakeNode(char *artist, char *album_title, char *song_title, char *genre, char *number_times_played)
{
	Node *pNewNode = NULL;

	//allocate memory
	pNewNode = (Node *)malloc(sizeof(Node));

	if (pNewNode != NULL) 
	{

		pNewNode->pRecord = (Record *)malloc(sizeof(Record));
		
		if (pNewNode->pRecord != NULL) // cases where you run out of memory where malloc wasn't able to allocate memory
		{
			pNewNode->next = NULL;
			
			//Since we are using all char pointers, we must allocate memory of type char *
			pNewNode->pRecord->artist = (char *)malloc(sizeof(char)* strlen(artist) + 1);
			strcpy(pNewNode->pRecord->artist, artist);

			pNewNode->pRecord->album_title = (char *)malloc(sizeof(char)* strlen(album_title) + 1);
			strcpy(pNewNode->pRecord->album_title, album_title);

			pNewNode->pRecord->song_title = (char *)malloc(sizeof(char)* strlen(song_title) + 1);
			strcpy(pNewNode->pRecord->song_title, song_title);

			pNewNode->pRecord->genre = (char *)malloc(sizeof(char)* strlen(genre) + 1);
			strcpy(pNewNode->pRecord->genre, genre);

			pNewNode->pRecord->number_times_played = (char *)malloc(sizeof(char)* strlen(number_times_played) + 1);
			strcpy(pNewNode->pRecord->number_times_played, number_times_played);
		}
	}

	return pNewNode;
}

char *GetAlbumName(char *full_name)
{
	char last_name[50];
	int i = 0, j = 0;

	while (full_name[i] != '\0')
	{
		last_name[j++] = full_name[i];
		i++;
	}

	last_name[j] = '\0';

	return last_name;
}

Node *GetNodeToAdd()
{
	Node *pNewNode = NULL;
	int i = 0, j = 0;
	char buffer[50], *artist,*album_title, *song_title, *genre, *number_times_played;
	/*int *rating;*/

	printf("Please enter an album title: ");
	gets(buffer);
	album_title = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
	strcpy(album_title, buffer);
	printf("\n\n");

	printf("Please enter the artist name: ");
	gets(buffer);
	artist = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
	strcpy(artist, buffer);
	printf("\n\n");

	printf("Please enter a song title: ");
	gets(buffer);
	song_title = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
	strcpy(song_title, buffer);
	printf("\n\n");

	printf("Please enter the genre: ");
	gets(buffer);
	genre = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
	strcpy(genre, buffer);
	printf("\n\n");

	printf("Please enter number of times played: ");
	gets(buffer);
	number_times_played = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
	strcpy(number_times_played, buffer);
	printf("\n\n");

	//Have pNewNode point to the address of our newly allocated node with given parameters
	pNewNode = MakeNode(artist,album_title, song_title, genre, number_times_played);
	
	artist = NULL;
	album_title = NULL;
	song_title = NULL;
	genre = NULL;
	number_times_played = NULL;

	return pNewNode;
}

Boolean AddNodeInOrder(Node **root, Node *pNewNode)
{
	Node *pCurrNode = NULL;
	Boolean success = FALSE;
	int i = 0, j = 0;

	if (*root == NULL)
	{
		*root = pNewNode;
		pNewNode = NULL;
		success = TRUE;
	}

	else
	{
		// this if statement says if the album of new node has a greater first letter than
		// the the first letter of our root's album name , then we want to our root pointer to point
		// to our new_node
		if (*(GetAlbumName(pNewNode->pRecord->album_title)) < *(GetAlbumName((*root)->pRecord->album_title)))
		{
			pNewNode->next = *root;
			*root = pNewNode;
			pNewNode = NULL;
			return TRUE;
		}

		else
		{
			//or else we set our current position to point to the address our *root is pointing to.
			pCurrNode = *root;

			while (pCurrNode->next != NULL)
			{
				//This compares the first characters in ascci value and if
				//it sees that
				if (*(GetAlbumName(pNewNode->pRecord->album_title)) < *(GetAlbumName((pCurrNode)->next->pRecord->album_title)))
				{
					pNewNode->next = pCurrNode->next;
					pCurrNode->next = pNewNode;
					success = TRUE;
					
					return success;
				}
				pCurrNode = pCurrNode->next;
			}

			//this is if we have traversed the list without having added our new node. 
			//Which means that the node will go at the end of our list
			if (pCurrNode->next == NULL)
			{
				pCurrNode->next = pNewNode;
				success = TRUE;
			}
		}
	}

	return success;
}

void AddApp(Node **root)
{
	Node *pNewNode = NULL;
	pNewNode = GetNodeToAdd();
	AddNodeInOrder(root, pNewNode);
}

Boolean PrintList(Node *list)
{
	Boolean success = FALSE;

	// in the case that our pointer is already pointing to NULL
	// just means our Record list is empty and we have nothing to print
	if (list == NULL) 
	{
		success = TRUE;
	}

	while (list != NULL)
	{
		printf("album_title = %s\n", list->pRecord->album_title);
		printf("artist Name = %s\n", list->pRecord->artist);
		
		printf("song_title = %s\n", list->pRecord->song_title);
		printf("genre = %s\n", list->pRecord->genre);
		printf("number_times_played = %s\n\n", list->pRecord->number_times_played);
		list = list->next;
		success = TRUE; // If we have things printed we'll know that it's true;
	}

	return success;
}

/*******
This is a helper function that 
deletes the contents of a Node's Record
******/
Boolean deleteRecord(Node **root) 
{
	Boolean success = FALSE;
	// free the current Records information 
	free((*root)->pRecord->artist);
	free((*root)->pRecord->album_title);
	free((*root)->pRecord->song_title);
	free((*root)->pRecord->genre);

	// free the memory allocated for the Record itself
	free((*root)->pRecord);

	// then finally free the Node that contained the Record, since now it is safe to do so without memory leaks.
	free((*root));
	*root = NULL; // Finally have it point back to NULL for use with later functions

	success = TRUE; //at this point everything has been freed so test has passed

	return success;
}

void RemoveRecord(Node **root)
{
	Node *pCurrNode = NULL;
	Node *pDelNode = NULL;
	char buffer[30];
	int test = 0;

	printf("Please enter the full name of the album you wish to remove: ");
	gets(buffer);

	if (*root != NULL)
	{
		pCurrNode = *root;

		//The case that our first Node needs to be removed, we have to have our root pointer point to the next node
		if (strcmp((*root)->pRecord->artist, buffer) == 0)
		{
			*root = (*root)->next;
			deleteRecord(&pCurrNode);
			pCurrNode = NULL;
		}

		else
		{
			//This loop is saying while our current pointer's next is not pointing to NULL
			// we will traverse but if we see that we have same name, we will have our pDelNode
			// point to the same location our current node pointer is pointing to and then have
			// our current node pointer's next point to our current node pointer's next next
			// so that we can successfully free pur pDelNode and still obtain the linked list
			// form without memory leaks. Come see me in office hours if this doesn't make sense.
			//because this is extremely important to understand.
			while (pCurrNode->next != NULL) 
			{
				if (strcmp(pCurrNode->next->pRecord->artist, buffer) == 0)
				{
					pDelNode = pCurrNode->next;
					pCurrNode->next = pCurrNode->next->next;
					deleteRecord(&pDelNode);

					return;
				}
				pCurrNode = pCurrNode->next;
			}
		}
	}
}

Boolean EditList(Node *pList)
{
	char buffer[30], option = '\0';
	Boolean success = FALSE;

	printf("Editing Album information...\n\n");

	printf("Please enter the name of the Album to edit the info: ");
	gets(buffer);

	while (pList != NULL && strcmp(pList->pRecord->album_title, buffer) != 0)
	{
		pList = pList->next;
	}

	//Either There is no list or the name user entered is not in your Records
	if (pList != NULL)
	{
		while (option != '6')
		{
			do
			{
				system("cls");
				printf("Editing Record information...\n\n");
				printf("1. Edit Album Title(%s)\n", pList->pRecord->album_title);
				printf("2. Edit Artist(%s)\n", pList->pRecord->artist);
				printf("3. Edit Song Title(%s)\n", pList->pRecord->song_title);
				printf("4. Edit Genre(%s)\n", pList->pRecord->genre);
				printf("5. Edit Number Of Times Played(%s)\n", pList->pRecord->number_times_played);
				printf("6. Exit editing\n");
				printf("\noption: ");
				scanf(" %c", &option);
			} while (option < 48 || option > 55);

			fflush(stdin);

			system("cls");
			printf("Editing Album information...\n\n");

			switch (option)
			{
			case '1':
				printf("Current Album Name(%s)Edit Album Name:  ", pList->pRecord->album_title);
				gets(buffer);
				free(pList->pRecord->album_title);
				pList->pRecord->album_title = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
				strcpy(pList->pRecord->album_title, buffer);
				success = TRUE;
				break;

			case '2':
				printf("Current Album Artist(%s)Edit Album Artist: ", pList->pRecord->artist);
				gets(buffer);
				pList->pRecord->artist = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
				strcpy(pList->pRecord->artist, buffer);
				success = TRUE;
				break;

			case '3':
				printf("Curret Song Title(%s)Edit Sont Title: ", pList->pRecord->song_title);
				gets(buffer);
				pList->pRecord->song_title = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
				strcpy(pList->pRecord->song_title, buffer);
				success = TRUE;
				break;
			case '4':
				printf("Current Genre(%s)Edit Genre: ", pList->pRecord->genre);
				gets(buffer);
				pList->pRecord->genre = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
				strcpy(pList->pRecord->genre, buffer);
				success = TRUE;
				break;
			case '5':
				printf("Current Number Of Times PLayed(%s)Edit Number Of Times Played: ", pList->pRecord->number_times_played);
				gets(buffer);
				pList->pRecord->number_times_played = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
				strcpy(pList->pRecord->number_times_played, buffer);
				success = TRUE;
				break;
			case '6':
				break;
			}
		}
	}

	return success;
}

void LoadIntoNode(Node *list, char *buffer, int count)
{
	switch (count)
	{
	case 1:
		list->pRecord->artist = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
		strcpy(list->pRecord->artist, buffer);
		break;

	case 2:
		list->pRecord->album_title = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
		strcpy(list->pRecord->album_title, buffer);
		break;

	case 3:
		list->pRecord->song_title = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
		strcpy(list->pRecord->song_title, buffer);
		break;

	case 4:
		list->pRecord->genre = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
		strcpy(list->pRecord->genre, buffer);
		break;
	case 5:
		list->pRecord->number_times_played = (char *)malloc(sizeof(char)* strlen(buffer) + 1);
		strcpy(list->pRecord->number_times_played, buffer);
		break;
	}
}

Boolean LoadInfo(Node **root, FILE *fRecords)
{
	Boolean success = FALSE;
	Node *pCurNode = NULL;
	char buffer[50];
	int count = 0;

	//First get rid of our current list
	DestroyList(root);

	fRecords = fopen("Music.txt", "r");

	if (fRecords != NULL) // check to see if file is open, will return false for test case
	{
		success = TRUE;
		
		pCurNode = InitNode(); // initialize first node

		count = 1;

		while (!feof(fRecords))
		{
			fgets(buffer, 50, fRecords);

			if (count != 6)
			{
				buffer[strlen(buffer) - 1] = '\0'; //When our count is 1-4, it'll be one of our Record info properties
				// therefore we'll want to get rid of the newline character and replace it with null byte terminating character
			}

			else if (count == 6)
			{
				count = 0; // sets count to 0 for preperation of an increment to 1 and so it'll skip loading into node case
				AddNodeInOrder(root, pCurNode); //puts our pCurNode into our list, and orders it
				pCurNode = InitNode(); // since the pCurNode is now part of our list (root), we can now init to a new empty node
			}
			//testing
			LoadIntoNode(pCurNode, buffer, count); // we Load

			count++;
		} 

	}

	fclose(fRecords); //always remember to close our FILE *!

	return success;

}

Boolean StoreInfo(Node *root, FILE *fRecords)
{
	Boolean success = FALSE;
	int count = 0;

	fRecords = fopen("Music.txt", "w+"); //this overwrites current file
	if (root == NULL) // We have nothing to print to file
	{
		success = TRUE;
	}

	while (root != NULL)
	{
		fprintf(fRecords, "%s\n", root->pRecord->album_title);
		fprintf(fRecords, "%s\n", root->pRecord->artist);
		fprintf(fRecords, "%s\n", root->pRecord->song_title);
		fprintf(fRecords, "%s\n", root->pRecord->genre);
		fprintf(fRecords, "%s\n", root->pRecord->number_times_played);
		if (root->next != NULL)
		{
			fprintf(fRecords, "\n");
		}
		root = root->next;
	}

	fclose(fRecords);

	return success;
}

Boolean DestroyList(Node **root)
{
	Node *pDelNode = NULL;
	Boolean success = FALSE;

	while (*root != NULL) // going until our *root has no more node addresses to point to
	{
		pDelNode = *root; // set del node to current *root
		
		(*root) = (*root)->next;

		deleteRecord(&pDelNode);
	}

	if (*root == NULL) 
	{
		success = TRUE;
	}

	return success;
}