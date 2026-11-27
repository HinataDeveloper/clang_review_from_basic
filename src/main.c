#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	[[maybe_unused]] int a = 5;
	[[maybe_unused]] int b = -5;
	[[maybe_unused]] int c = 12;

	[[maybe_unused]] float r = 1.52F;
	[[maybe_unused]] float s = 2.08F;
	[[maybe_unused]] float t = -5.32F;

	[[maybe_unused]] int integer_result;
	[[maybe_unused]] float float_result;

	integer_result = a * r;
	puts("-------- PART 1 ----------------");
	printf("integer_value is: %d\n", integer_result);

	float_result = a * r;
	printf("float_value is: %f\n", float_result);

	integer_result = (a > b) * c;
	printf("integer_value is: %d\n", integer_result);

	integer_result = (a < b) * c;
	printf("integer_value is: %d\n", integer_result);

	puts("-------- PART 2 ----------------");
	printf("a before: %d\n", a);
	integer_result = (++a) * b;
	printf("integer_result: %d\n", integer_result);
	printf("a after: %d\n", a);

	puts("-------- PART 3 ----------------");
	a = 5;
	printf("a before: %d\n", a);
	integer_result = (a++) * b;
	printf("integer_result: %d\n", integer_result);
	printf("a after: %d\n", a);

	puts("-------- PART 4 ----------------");
	int initial_value = 0;
	int increment = 5;
	int counter = 0;

	int result = initial_value + increment * counter++;
	printf("result first time: %d, counter: %d\n", result, counter);

	result = initial_value + increment * counter++;
	printf("result first time: %d, counter: %d\n", result, counter);

	result = initial_value + increment * (++counter);
	printf("result first time: %d, counter: %d\n", result, counter);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
