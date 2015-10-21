#include "bstnode.h"

/**********
This function allocates dynamic memory 
to our node accordingly
*********/
BSTnode *MakeNode(char *line)
{
	BSTnode *pNew = NULL;
	int i = 0, j = 0;
	char *morse = NULL;

	pNew = (BSTnode *) malloc(sizeof(BSTnode));

	if (pNew != NULL)
	{
		pNew->left = NULL;
		pNew->right = NULL;
		pNew->ascii = line[0]; //the 0th element of our line is the ascii character
		pNew->morse = (char *)malloc(sizeof(char));

		//we start at 4 because that's the index where the morse code
		//starts, and then we go until the end of it, so the substring
		//without the ascci and space
		for (i = 4, j = 0; i < strlen(line); i++, j++)// -1 to ignore newline character
		{
			pNew->morse = (char *)realloc(pNew->morse, sizeof(char) * (j + 1));
			pNew->morse[j] = line[i];
		}
		
		if (pNew->morse[j - 1] == '\n') //if our lsat character is a new line then get rid of it
		{
			pNew->morse[j - 1] = '\0'; //replace newline with nullbyte
		}
	}

	return pNew;
}

/********
inserts a node
into our BST using
recursion
*********/
void InsertNode(BSTnode **root, char *line)
{
	if (*root == NULL) //base case if our pointer is pointing to NULL
	{
		*root = MakeNode(line); //we make a node once our base is met
	}
	// else if our ascii value 
	//is less than the current ascii, traverse left
	else if (line[0] < (*root)->ascii)
	{
		InsertNode(&(*root)->left, line); //recursive step for going left in our bst
	}
	// else if our ascii value is 
	//greater than or equal to, traverse right
	else
	{
		InsertNode(&(*root)->right, line); //recursive step for going right in our bst
	}
}

/**********
This function searches for our passed in ascii 
and returns corresponding morse
**********/
BSTnode *BSTsearch(BSTnode *root, char ascii)
{
	//return the corresponding morse 
	//if we find the ascii we're looking for

	if (root == NULL)
	{
		return NULL;
	}

	else if (ascii == root->ascii)
	{
		return root;
	}

	else if (ascii < root->ascii)
	{
		return BSTsearch(root->left, ascii);
	}

	else  //if ascii is greater than equal to root->ascii
	{
		return BSTsearch(root->right, ascii);
	}
}

/*******
I wonder what this function does...
*********/
void PrintOutput(BSTnode *root, FILE*infile, FILE *outfile)
{
	char temp = '\0';
	BSTnode *found = NULL;

	while (!feof(infile))
	{
		temp = toupper(getc(infile)); //store the upper version of a character to temp

		found = BSTsearch(root, temp); //return the node corresponding to the ascii

		if (found != NULL && (temp != '\n' && temp != ' '))
		{
			fprintf(outfile, "%s ", found->morse); //access the morse ascii print it out to your text file
		}
		else if (temp == '\n') //newline prints newline
		{
			fprintf(outfile, "%c", temp);
		}
		else if (temp == ' ') //we'll give it an extra space to make sure the morse code is outputting correctly
		{
			fprintf(outfile, "%s", "   ");
		}
	}
}

//traversals that print ascii values 
void PreOrderTraversal(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%c\n", root->ascii); 
	PreOrderTraversal(root->left); 
	PreOrderTraversal(root->right); 
}
void InOrderTraversal(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}

	PreOrderTraversal(root->left);
	printf("%c\n", root->ascii);
	PreOrderTraversal(root->right);
}
void PostOrderTraversal(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}

	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
	printf("%c\n", root->ascii);
}

/*********
Diagram out a post traversal tree,
you'll see that if you want to delete very node
in a BST, it's very easy to do so using a post traversal
order.
***********/
void DestroyTree(BSTnode **root)
{
	if (*root == NULL)
	{
		return;
	}

	DestroyTree(&(*root)->left);
	DestroyTree(&(*root)->right);
	free((*root)->morse); // free the morse field first
	free(*root); // then free the BSTnode
}
