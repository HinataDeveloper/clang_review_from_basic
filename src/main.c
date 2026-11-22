#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch;
	char name[32];
	char family[32];

	printf("enter a charachter: ");
	ch = getchar();

	printf("enter your name: ");
	scanf("%31s", name);

	printf("enter your family: ");
	scanf("%31s", family);

	printf("The charater you typed is: %c", ch);
	printf("The name you typed is: %s\n", name);
	printf("The family you typed is: %s\n", family);

	puts("\nThe End ...\n");
	return EXIT_SUCCESS;
}
