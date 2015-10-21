#include "header.h"

char *CaesarShift()
{
	char ar[26];
	int shift = 0, i = 0, j = 0;
	static char str[100];
	int index = 0;

	// initialize array
	// there are 26 alphabetical characters
	for (i = 0, j = 65; i < 26; i++, j++)
	{
		ar[i] = (char)j;
	}

	printf("Please Enter a string: ");
	
	scanf("%s", str);
		
	printf("\n\nPlease enter a shift: ");
	scanf("%d", &shift);

	for(i = 0; (unsigned)i < strlen(str); i++)
	{
		//say you have 'A' as your str[i] value
		//your ar is just an array of all the alphabetical characters
		//so 65 is the value of A, the 0th element in your ar, so then
		//to access the 0th element, A we would just do 'A' - 'A' which is
		//equal to 0 then to encrypt/decrypt we add the shift to it so it shifts
		//towards whatever you have coming up in the alphabet, in this case adding
		//4 would give you a value of E, then we must mod by 26 which is the size
		//of our array to make sure the index stays within bounds, 
		// 0 % 26 == 0, 1 % 26 == 1, 2 % 26 == 2, ...., (n < 26) % 26 == (n < 26)
		// however when it reaches 26 through a shift,
		// it will reset to 0
		// 26 % 26 == 0, 26 % 27 == 1, boom magic!
		index = (toupper(str[i]) - 65) + shift;
		//since % isn't actually a modulo operation in C, and it only gives us a remainder
		//when we have a negative number, this will give us a problem
		//hence to fix this, just add your index by what you wanted to mode with
		//i.e if your shift was -4, 'A' - 65 would give 0 then + shift would give -4
		//and -4 % 26 would give -4, which isn't an index, so if we add what we are modding
		//by (in this case 26), then it'll launch us back around the array.
		//also do a while loop, this way we can make sure we dont have a negative number
		while (index < 0)
		{
			index = index + 26;
		}
		str[i] = ar[index % 26];
	}

	return str;
}

void CaesarShiftDriver()
{
	int i = 0;
	char *str = NULL;
	
 	str = CaesarShift();

	printf("%s is your encrypted string.\n\n", str);
	
	str = CaesarShift();

	printf("%s is your decrypted string.\n\n", str);
}
