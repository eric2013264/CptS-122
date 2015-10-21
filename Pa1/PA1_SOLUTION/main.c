/*******************
Author: Jay Khan
Class: CPT_S 122
PA 1
Date: 9/13/2014

**IMPORTANT**: if you are on visual studios 2012 and this code isn't compiling
simply copy paste the .h, .c, and .txt files into a new project's folder
i.e if i had a project called 122LAB2, there would be a folder called 122LAB2 inside
and I would paste the mentioned files in there, then right click and add existing files
on the left tab, as you can see on this current project. Email me if this doesn't work for
ya!

This is the solution to PA 1. Carefully read the comments and go through the code
If you are unclear about something, go to your TA's office hours
or come by eme 16, 12-2 mwf for help! 
for help!

best way to get an A in this class.... code.. ALOT and ask questions when you're conffuzzled!

***NOTE**** Also, I'm gonna sneak this in but if this solution helped you at all
or you are interested in seeking knowledge beyond your computer science classes,
Come by eme 16 for Linux Users group. There will also be a tech talk on Wednesday
9/17/2014 on linux distributions in Sloan 169 <Mark your calendars!> (I'd especially recommend coming if
you have zero experience with linux) so definitely come check it out :-)
********************/

#include "header.h"

#define LEN 4

int main(void)
{
	char *strar[LEN] = {"Batman", "Xylophone", "Apple", "Cat"};
	int i = 0;
	char way = '\0';
	//char *some_string = "race car";
	char buffer[50];

	//number 1
	printf("**********Number 1:**************\n");

	printf("Unsorted:\n\n");

	for(i = 0; i < LEN; i++)
	{
		printf("%d. %s\n", i, strar[i]);
	}

	StringSorter(strar, 'D', LEN);
	
	printf("\nSorted:\n");

	for(i = 0; i <LEN; i++)
	{
		printf("%d. %s\n", i, strar[i]);
	}

	printf("\n");

	//number 2
	printf("**********Number 2:**************\n");
	printf("Please enter a string to check if it's a palindrome: "); //i.e put in Race car, which is an example of palindrome.
	gets(buffer);
	IsPal(buffer);

	//number 3
	printf("**********Number 3:**************\n");
	CaesarShiftDriver();

	//i.e: put in ABCD and shift of -4
	//this will output WXYZ
	//then to decrypt, put in WXYZ
	//give it a shift of 4
	//this will give you ABCD.. so it works!
	return 0;
}
