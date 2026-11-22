#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

int main(void)
{
	char string1[32];
	char string2[32];

	strcpy(string1, "I am a Rustacean ...");

	/* Encounter with error.
         * Because size of `string2[32]` is less than the relevant text. */
	strcpy(string2,
	       "I am a C developer and some other languages such as C++ and Python");

	printf("value of string1 is: %s\n", string1);
	printf("value of string2 is %s\n", string2);

	uint length_one = (uint)strlen(string1);
	uint length_two = (uint)strlen(string2);

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("length of the string1 is: %u\n", length_one);
	printf("length of the string2 is: %u\n", length_two);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
