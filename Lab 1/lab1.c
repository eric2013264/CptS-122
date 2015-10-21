#include "lab1.h"

// 2a.) Recursive string reverse function
// x: pass in a stringthat you have initilized with malloc and copied in a string with strcpy()
// begin: the begin index. Pretty much always 0.
// end: the end index. Example - for "Hello", the end index should be 4
void reverseString(char *x, int begin, int end)
{
	// A temporary character we use for swapping.
	char c;

	// BASE CASE: check if the beginning index is equal to or greater than the end index.
	// If it is, then we are done and we return.
	if (begin >= end)
		return;

	// Swap the character at the beginning index with the character at the end index.
	c = x[begin];
	x[begin] = x[end];
	x[end] = c;

	// The recursive call. Iterate begin index 1 forward, and end index 1 backward.
	reverseString(x, ++begin, --end);
}

// 2bi.) Merge Unsorted Strings function, with third, fixed array.
// str1 - any string initilized with malloc(), and created with strcpy()
// str2 - any string initilized with malloc(), and created with strcpy()
void mergeUnsortedStrings1(char *str1, char *str2)
{
	// We assume the string length of str1 + str2 is less than or equal to 19 characters.
	char mergedString[20];

	// Copy in the first string.
	strcpy(mergedString, str1);
	// Concatenate the second string onto the end.
	strcat(mergedString, str2);

	// Use bubble sort to sort the letters into alphabetical order.
	bubblesort(mergedString);

	printf("mergedString: %s\n", mergedString);
	

}

// 2bii.) Merge Unsorted Strings function, with third, fixed array.
// str1 - any string initilized with malloc(), and created with strcpy()
// str2 - any string initilized with malloc(), and created with strcpy()
void mergeUnsortedStrings2(char *str1, char *str2)
{
	// This is the dynamic char array. It's dynamic because we used malloc(), instead of creating a fixed array.
	char *mergedString = (char *)malloc((sizeof(char)* strlen(str1) * strlen(str2)) + 1);

	// copy in string 1 and concatentate string 2 to the end.
	strcpy(mergedString, str1);
	strcat(mergedString, str2);

	// bubble sort to alphabetize the letters
	bubblesort(mergedString);

	printf("mergedString: %s\n", mergedString);
}

// 2biii.) Merge Unsorted Strings function, with third, fixed array.
// str1 - any string initilized with malloc(), and created with strcpy()
// str2 - any string initilized with malloc(), and created with strcpy()
void mergeUnsortedStrings3(char *str1, char *str2)
{
	// This time, we use realloc to increase the memory size of str1
	str1 = realloc(str1, sizeof(char)* (strlen(str1) + strlen(str2)) + 1);

	// Concatenate str2 to the end of str1.
	strcat(str1, str2);

	// Sort string 1
	bubblesort(str1);

	printf("str1: %s\n", str1);



}

// Character count function.
// infile - A file pointer that was initilized with NULL.
void charCount(FILE *infile)
{
	// A temporary character that we use later in the function.
	char temp = '\0';
	// We start on line 1, instead of line 0.
	int lineNum = 1;
	// This keeps track of the character count.
	int charCount = 0;

	// Open the file into read mode.
	infile = fopen("test.txt", "r");

	// We keep looping until we reach the end of the file.
	while (!feof(infile))
	{
		// Scan in a character into the temp character we initilized above.
		fscanf(infile, "%c", &temp);
		// Iterate the character count
		charCount++;

		// If the character is a newline character, that means we are going to a new line,
		// so we iterate lineNum by 1.
		if (temp == '\n')
		{
			lineNum++;
		}
		else
		{
			// We only come here is the character scanned in isn't a line number.
			// We print the character number, what line it's on, and the character itself into the console.
			printf("Char Num: %d \t Line number: %d \t Character: %c\n", charCount, lineNum, temp);
		}

		
	}

	// Don't forget to close the file.
	fclose(infile);

}

// Bubble sort function. This is the function that sorts the letters in our string to be in alphabetical order.
// For a good animation of what bubble sort does visually, watch the video at:
// https://www.youtube.com/watch?v=JP5KkzdUEYI
// strToSort - any string initilized with malloc(), and created with strcpy()
void bubblesort(char *strToSort)
{
	int i = 0, j = 0;

	// We have i starting at the end of the string, looping toward the beginning
	for (i = (strlen(strToSort) - 1); i > 0; i--)
	{
		// We have j starting at the beginning of the string, looping toward the end.
		for (j = 0; j < i; j++)
		{
			// We need to compare only lower case letters, because 
			// upper case letters have a lower ascii value ironically than lower case values.
			// We wouldn't want 'Z' to be less than 'a', because that wouldn't make sense for alphabetizing!
			char char1 = tolower(strToSort[j]);
			char char2 = tolower(strToSort[j + 1]);
			
			// char2 is the character to the right of a. If it's ASCII value is less than char1, 
			// meaning it comes before char1 in the alphabet, then we have to swap characters
			if (char2 < char1)
			{
				char temp = strToSort[j];
				strToSort[j] = strToSort[j + 1];
				strToSort[j + 1] = temp;
			}
		}
	}



}