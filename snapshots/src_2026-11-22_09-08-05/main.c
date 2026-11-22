#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef long double ldbl;
typedef unsigned int Bool;

int main(void)
{
	uint a = 23;
	uint b = 39;
	Bool c = a > b;

	ldbl x = 36.3698;
	ldbl y = 56.32569;
	ldbl z = x / y;

	printf("value of c is: %u\n", c);
	printf("value of z is: %Lf\n", z);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
