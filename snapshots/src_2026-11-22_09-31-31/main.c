#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef long double ldbl;
typedef unsigned int Bool;

int main(void)
{
	char message_one[32] = "I am a Rustacen ...";
	char message_two[64] =
		"Not only I am a Rustacean I am a C developer as well";

	printf("the content of message_one is:\n%s\n", message_one);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("the content of message_two is:\n%s\n", message_two);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
