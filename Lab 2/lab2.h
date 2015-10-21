#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct contact
{
	char first[50];
	char last[50];
	char number[50];
	char email[50];
	char title[50];
} Contact;

typedef enum boolean
{
	FALSE, TRUE
} BOOL;


//We need to make a struct for the node. The struct will contain
//a contact type (a person), and a pointer to the next node(contact).
typedef struct node
{
	Contact contact;
	struct node *next;
} Node;

// Linked List Functions
void Insert(Node **hPtr);
void Remove(Node **hPtr, char first[32], char last[32]);
void Edit(Node **hPtr, char first[32], char last[32]);
void Print(Node *hPtr);
void Store(Node *hPtr, FILE *infile);
void Load(Node **hPtr);


// Utility Functions
void PrintOptionsMenu();
Contact CreateContact();
void TrimNewLine(char *str);






