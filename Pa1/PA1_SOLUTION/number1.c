#include "header.h"

void StringSorter(char **strar, char way, int str_length)
{
	int C = 0, U = 0;
	char *temp_string = '\0';
	for(U = str_length - 1; U > 1; U--) //outer loop: while unsorted section is great than 1
	{
		for(C = 1; C <= U; C++) //inner loop: start current at 1, while current is less than or equal to unsorted
		{
			if(way == 'D') // Descending ascii
			{
				//doing a swap here
				if(*strar[C] > *strar[C - 1])
				{
					temp_string = strar[C];
					strar[C] = strar[C - 1];
					strar[C - 1] = temp_string;
				}
			}
			
			else // Ascending ascii is default
			{
				//also doing a swap here
				if(*strar[C] < *strar[C - 1])
				{
					temp_string = strar[C];
					strar[C] = strar[C - 1];
					strar[C - 1] = temp_string;
				}
			}
		}
	}
}
