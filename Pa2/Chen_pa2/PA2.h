#ifndef PA2_H
#define PA2_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum boolean
{
	FALSE, TRUE
}Boolean;

typedef struct Record
{
	char *album_title;
	char *artist;
	char *song_title;
	char *genre;
	char *number_times_played;
	int *rating;
}Record;

typedef struct node
{
	Record *pRecord;
	struct node *next;
}Node;

Node *InitNode();
Node *MakeNode(char *artist, char *album_title, char *song_title, char *genre, char *number_times_played);

char *GetAlbumName(char *full_name);
Node *GetNodeToAdd();
Boolean AddNodeInOrder(Node **root, Node *pNewNode);
void AddApp(Node **root);

Boolean PrintList(Node *list);

Boolean deleteRecord(Node **root);
void RemoveRecord(Node **root);

Boolean EditList(Node *pList);

void LoadIntoNode(Node *list, char *buffer, int count);
Boolean LoadInfo(Node **root, FILE *fRecords);

Boolean StoreInfo(Node *root, FILE *fRecords);

Boolean DestroyList(Node **root);
#endif