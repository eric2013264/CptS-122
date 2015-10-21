#include "header.h"

//this is not just a whitespace remover,
//but removes anything that is not a character
//like punctuation, etc.
char *WSRemover(char *str)
{
	int i = 0, j = 0;
	int size = 0; 
	char *ret_string = NULL;

	//initially allocate our memory for 
	//the string to return, as realloc needs it
	ret_string = (char *) malloc(sizeof(char));

	size = (int)strlen(str);
	
	for(i = 0; i < size; i++)
	{
		//we use toupper to  only check ascii values of upper characters to keep it
		//simple. Bounds are >= 'A' and <= 'Z'
		if(toupper(str[i]) >= 65 && toupper(str[i]) <= 90)
		{	
			//realloc and push values in every time you see it's a letter. Otherwise skip.
			ret_string = (char *) realloc (ret_string, sizeof(char) * (j + 1));
			//increment operator.. If you're confused, all this is saying is
			//we will first do the operation of which j belongs to and then
			//increment it once it has performed a single operation
		
			ret_string[j++] = str[i];
		}
	}

	//finally, don't forget your terminating character
	//this is very important to remember or the compiler won't
	//recognize ret_string as a c string.
	ret_string = (char *) realloc (ret_string, sizeof(char) * (j + 1));
	ret_string[j] = '\0';

	return ret_string;
} 

void IsPalindrome(char *NoWSstring, char *str, int start, int end)
{
	//if an element starting from the left isn't equal to the one coming in from the right
	//during the recursive process, then we know the string isn't a palindrome.
	if(toupper(NoWSstring[start]) != toupper(NoWSstring[end]))
	{
		printf("The string %s is not a palindrome\n\n", str);
		return;
	}

	//However if start element has gotten
	//to the point of the end or past it
	//we know that it never entered the initial base case
	//thus it must be a palindrome
	else if(start >= end)
	{
		printf("The string %s is a palindrome\n\n", str);
		return;
	}
	
	//and if you haven't fullfilled either of those two steps yet, well
	//if you've ever watched the movie inception, think about how they go
	//levels deep into a dream, that is sort of like the recursion
	//over here... you dive into a deeper level, but this time the difference
	//being that start is shifting it's element to the right and end is shifting
	//it's element to the left
	else 
	{
		IsPalindrome(NoWSstring, str, start+1, end-1);
		return;
	}

	return;
}

//This function just mashs everything
//together
void IsPal(char *str)
{
	int start = 0, end = 0;
	char *new_string = NULL;

	new_string = WSRemover(str);
	
	//make sure your end is the last accessable index
	//in your new_string, strlen(new_string) is the length
	//but since we work with 0 index-based adjacent blocks
	//we must subtract 1 more to access the last character
	//(not including the null byte)
	end = strlen(new_string) - 1;

	IsPalindrome(new_string, str, start, end);

	//since we dynamically allocated, don't forget to free our
	//memory from its misery! D:
	free(new_string);
}