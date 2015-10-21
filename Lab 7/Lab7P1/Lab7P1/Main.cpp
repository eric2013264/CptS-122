#include "Header.h"

int main (void)
{
	FILE *infile = NULL;
	FILE *outfile = NULL;
	infile = fopen ("input.txt", "r");
	outfile = fopen("output.txt", "w");

	int month = 0, year = 0, customer = 0, hours = 0, rounded = 0;
	double avgcost = 0.0, charge = 0.0;

	fscanf(infile, "%d", &month);

