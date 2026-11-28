#include "formula.h"
#include <stdio.h>

int main()
{
	long double rds = 325.159793;
	auto result = circle_area(rds);

	printf("value of result is: %Lf\n", result);

	puts("\n The End ...\n");
	return 0;
}


