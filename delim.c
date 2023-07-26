#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - function that allows the separation os small parts of a program
 * Return: 0 success
 */
int main(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	printf("Enter a sentence: ");
	getline(&input, &bufsize, stdin);

	input[strcspn(input, "\n")] = '\0';

	char *token = strtok(input, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	free(input);

	return (0);
}
