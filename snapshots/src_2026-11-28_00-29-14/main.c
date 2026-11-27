#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int int_value = 0;
	int weight = 5;
	int k = 1;
	int flag = (k < 10);

	int result = int_value + flag * weight * k++;
	printf("value of result is: %d\n", result);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
