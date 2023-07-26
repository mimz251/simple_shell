#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <shell.h>

#define max_command_length 200

/**
 * main - function that allows variable replacement
 * replace_variable - variable replacement
 * Return: 0 success
 */
void replace_variables(char *command)
{
	sstream ss;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		if (strcmp(token, "$?") == 0)
		{
			ss(token, sizeof(token), "%d", WEXITSTATUS(system("true")));
		}
		/* Replace $$ with the PID of the shell process*/
		else if (strcmp(token, "$$") == 0)
		{
			(token, sizeof(token), "%d", getpid());
		}
		token = strtok(NULL, " ");
	}
}

int main(void)
{
	char command[max_command_length];

	while (1)
	{
		printf("$ ");
		getline(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else
		{
			replace_variables(command);
			int status = system(command);

			if (status != 0)
			{
				printf("failed.\n");
			}
		}
	}

	return (0);
}
