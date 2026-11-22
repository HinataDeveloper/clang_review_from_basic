#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"

int main(void)
{
	int number_one = 0;

	printf("Enter a number: ");
	scanf("%d", &number_one);

	printf("what you typed is: %d\n", number_one);

	function_one();
	function_two();

puts("\nThe End ...");
	return EXIT_SUCCESS;
}