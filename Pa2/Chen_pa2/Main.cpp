#include "PA2.h"
//#include "test.h"

int main(void)
{
	//start menu
	char option = '\0', c = '\0';
	Node *root = NULL; 
	FILE *fRecords = NULL;
	
	while (option != '8')
	{
		do
		{
			system("cls");
			printf("***Digital Music Manager***\n\n");
			printf("1. Add album information\n");
			printf("2. Remove album information\n");
			printf("3. Edit album information\n");
			printf("4. Print to console\n");
			printf("5. Store album information to file\n");
			printf("6. Load album information from file\n");
			printf("7. Exit\n");
			printf("\n>>> ");
			scanf(" %c", &option);
		} while (option < 49 || option > 55);

		fflush(stdin);

		system("cls");

		switch (option)
		{
		case '1':
			//add
			printf("Currently Adding Record info..\n\n");
			AddApp(&root);
			break;

		case '2':
			//remove
			printf("Currently Removing Record info..\n\n");
			RemoveRecord(&root);
			break;

		case '3':
			//edit
			EditList(root);
			break;

		case '4':
			//print to console
			printf("Record Info: \n\n");
			PrintList(root);
			system("PAUSE");
			break;

		case '5':
			//store Record information in file
			printf("Storing Info..\n\n");
			StoreInfo(root, fRecords);
			system("PAUSE");
			break;

		case '6':
			//load Record information from file
			printf("Loading Info..\n\n");
			LoadInfo(&root, fRecords);
			system("PAUSE");
			break;

		case '7': //exit
			break;
		}
	}

	DestroyList(&root);

	return 0;
}