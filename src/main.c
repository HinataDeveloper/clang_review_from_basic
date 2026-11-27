#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int value_one;
	int value_two;
	int value_three;
	int value_four;
	int value_five;

	printf("value_one: (Good = 1  Bad = 0): ");
	scanf("%d", &value_one);
	puts("");

	printf("value_two: (Good = 1  Bad = 0): ");
	scanf("%d", &value_two);
	puts("");

	printf("value_three: (Good = 1  Bad = 0): ");
	scanf("%d", &value_three);
	puts("");

	printf("value_four: (Good = 1  Bad = 0): ");
	scanf("%d", &value_four);
	puts("");

	printf("value_five: (Good = 1  Bad = 0): ");
	scanf("%d", &value_five);
	puts("");

	int decision = (value_one && (value_two || value_three) &&
			(value_four || value_five));

	printf("Decision is: %d\n", decision);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}