/****************************************
Author: Jay Khan
LAB: 5
Date: 10/2/2014

Description: ***important*** if you got project->properties->debugging->
command line, I've already put the morse_code.txt and 
to_encrypt.txt as command line arguments so you
don't have to do it manually, anyways this project uses a BST tree to keep
data of our morse code which corresponds to an ascii value

Note: I've modified this lab from Andy's so that it randomizes
the morse code when inserting into the BST, that way we don't have
a linear structure. It'll be a different BST every single time.

Note: If this solution helped you at out all, please come 
check out the linux users group..
LUG office hours: Fridays 10-11, 12-1 @ eme 16, come join LUG and learn
about Linux!
*****************************************/
#include "bstnode.h"

/*******************
This randomizes our morse code file, so our bst is 
a different case everytime
*******************/
int main(int argc, char **argv)
{
	char buffer[50];
	FILE *morse_code = fopen(argv[1], "r");
	FILE *to_encrypt = fopen(argv[2], "r");
	FILE *decrypted_morse = fopen(argv[3], "w");
	char **lines = NULL;
	int i = 0, size = 0, random = 0, count;
	int *hold = NULL;
	BSTnode *root = NULL;

	//in this initial step, I randomize the strings
	//so we have a different bst structure every single time
	//we compile, you can keep this static
	//but it makes for the bst to be interesting
	//rather than have the nodes pile up on one side
	//like a linear structure, defeating the purpose of BST's.

	srand(time(NULL));

	//this will be our dynamic array that grows as we read
	//from our morse_code.txt file
	//just think of it as a dynamic array that grows and holds
	//dynamically allocated strings in it.
	//comes to my office hours if you want me to draw out 
	//and explain what is actually happening in memory here.
	lines = (char **)malloc(sizeof(char *));

	//first read in the strings from the file into a vector of strings
	while (!feof(morse_code))
	{
		fgets(buffer, 50, morse_code);
		//grow the vector of strings by 1 each iteration
		lines = (char **)realloc(lines, sizeof(char *) * (i + 1)); 
		//extra number for the nullbyte
		lines[i] = (char *)malloc(sizeof(char)* strlen(buffer) + 1); 
		strcpy(lines[i], buffer);
		i++;
	}

	size = i; // save the size of our vector of strings for later use.
	i = 0;

	hold = (int *)malloc(sizeof(int) * size); 

	while (i < size) //iterate elements till we hit the size capacity
	{
		random = rand() % size; // get a random number

		// use one as a placeholder to
		//tell us that we've already use this number
		//so we use that number as an indices and store a flag (1)
		//in there to tell us exactly that.
		while (hold[random] == 1)
		{
			random = rand() % size;
		}

		hold[random] = 1; //when we get a random we can use, set that to 1
		//so then it becomes unusuable for our next run

		InsertNode(&root, lines[random]);

		i++;
	}
	
	//uncomment and check the other traversals if you want.
	PreOrderTraversal(root);
	//InOrderTraversal(root);
	//PostOrderTraversal(root);

	PrintOutput(root, to_encrypt, decrypted_morse);

	DestroyTree(&root); // free all the nodes in your BST
	free(hold); // free our hold dynamic array

	i = 0;
	while (i < size)
	{
		free(lines[i++]); //free each individual char *
	}

	free(lines); //then free the vector pointers

	fclose(morse_code);
	fclose(to_encrypt);
	fclose(decrypted_morse);

	return 0;
}