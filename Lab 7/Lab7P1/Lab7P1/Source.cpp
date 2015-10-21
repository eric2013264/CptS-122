#include "Header.h"

int charges(double *charge_2, double *avg) // <-- these don't have to be the same name but the types have to match up
{
	int i = 11;

	if (hours > 10)
	{
		*charge_2 = 7.99;
		for (int i = 11; i <= hours; i++)
		{
			*charge_2 = *charge_2 + 1.99;
		}
	}
	else
	{
		*chrage_2 = 7.99;
		*avg = 7.99/hours;
	}
}

		
/*round_money() */