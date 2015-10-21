#include "lab2.h"


int main(void)
{
	int option = 0;
	char first[32], last[32];
	Node *ContactList = NULL;
	FILE *myfile = NULL;

	PrintOptionsMenu();
	scanf("%d", &option);

	while (option != 7)
	{
		switch (option)
		{
		case 1:
			Insert(&ContactList);
			break;
		case 2:
			printf("Enter first and last name to delete: ");
			scanf("%s %s", first, last);
			Remove(&ContactList, first, last);
			break;
		case 3:
			printf("Enter first and last name to edit: ");
			scanf("%s %s", first, last);
			Edit(&ContactList, first, last);
			break;
		case 4:
			Print(ContactList);
			break;
		case 5:
			Store(ContactList, myfile);
			break;
		case 6:
			Load(&ContactList);
			break;
		case 7:
			exit(0);
			break;
		default:
			printf("That wasn't an option! Please try again.\n");
			break;
		}

		PrintOptionsMenu();
		scanf("%d", &option);

	}




	return 0;
}

















