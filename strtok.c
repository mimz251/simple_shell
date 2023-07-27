#include <stdio.h>
#include <string.h>
/**
 * main - tokenizes a string and uses space as delimeter
 * @delim - space is eudto distinguish  parts of the sentence
 * @token - string tokenized
 * Return: 0.
 */
int main(void)
{
	char str[] = "THE ELEGANTS";
	char *delim = " ";
	char *token;

	token = strtok(str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}
