#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shell.h>

/**
 * main - function that handles the separator used in shell
 * Return: 0 success
 */
int main(void)
{
	sstream ss;
	char command[1000];

	printf(": ");
	fgets(command, sizeof(command), stdin);

	char *token = strtok(command, ";");

	while (token != NULL)
	{
		int start = 0;

		while (token[start] == ' ' || token[start] == '\t')
		{
			start++;
		}

		int end = strlen(token) - 1;

		while (end >= start && (token[end] == ' ' || token[end] == '\t' || token[end] == '\n'))
		{
			token[end] = '\0';
			end--;
		}

		if (strlen(token) > 0)
		{
			int status = system(token);

			if (status != 0)
			{
				printf("Command execution failed: %s\n", token);
			}
		}
		token = strtok(NULL, ";");
	}
	return (0);
}
