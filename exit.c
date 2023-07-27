#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_command_length 200

/**
 * main - allow the function that handles the exit status
 * Return: 0 success
 */
int main(void)
{
	printf("$ ");

	char command[200];

	scanf("%s", command);

	if (strcmp(command, "exit") == 0)
	{
		printf("Exiting the shell...\n");
		exit(0);
	}
	else
	{
		printf("Unknown command: %s\n", command);
	}
	return (0);
}
