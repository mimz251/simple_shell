#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define max_command_length 200
/**
 * main - function that handles the separator used in shell
 * Return: 0 success
 */

void execute_command(const char *command)
{
	int status = system(command);

	if (status != 0)
	{
		printf("Command execution failed.\n");
	}
}

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &bufsize, stdin) == -1)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		char *token = strtok(command, ";");

		while (token != NULL)
		{
			execute_command(token);

			token = strtok(NULL, ";");
		}
	}
	free(command);
	return (0);
}
