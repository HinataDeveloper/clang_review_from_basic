#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float float_number;
	double double_number;
	long double long_double_number;

	float_number = 2.0 / 3.0;
	double_number = 2.0 / 3.0;
	long_double_number = 2.0 / 3.0;

	printf("result if float_number is: %lf\n", float_number);
	printf("result of the double_number is: %lf\n", double_number);
	printf("result of the long_double_number is: %.55Lf\n",
	       long_double_number);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
