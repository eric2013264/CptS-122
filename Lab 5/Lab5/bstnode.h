#ifndef BSTNODE_H
#define BSTNODE_H

#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>

typedef struct bstnode
{
	struct bstnode *left;
	struct bstnode *right;
	char *morse;
	char ascii;
}BSTnode;

BSTnode *MakeNode(char *line);
void InsertNode(BSTnode **root, char *line);
BSTnode *BSTsearch(BSTnode *root, char ascii);

void PrintOutput(BSTnode *root, FILE*infile, FILE *outfile);

void PreOrderTraversal(BSTnode *root);
void InOrderTraversal(BSTnode *root);
void PostOrderTraversal(BSTnode *root);

void DestroyTree(BSTnode **root);

#endif