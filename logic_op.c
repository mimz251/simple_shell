#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define max_command_length 200

/**
 * main - function that handles logic operator
 * retur: 0 succes
 * else 1 fail
 */

int execute_command(char *command)
{
	int status = system(command);
	return (status);
}

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("alex@~$ ");
		if (getline(&command, &bufsize, stdin) == -1)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else
		{
			char *token = strtok(command, " ");
			int result = 1;

			while (token != NULL)
			{
				if (strcmp(token, "&&") == 0)
				{
					token = strtok(NULL, " ");
					if (token == NULL)
					{
						break;
					}
					result = execute_command(token);
					if (result != 0)
					{
						break;
					}
				}
				else if (strcmp(token, "||") == 0)
				{
					token = strtok(NULL, " ");
					if (token == NULL)
					{
						break;
					}
					result = execute_command(token);
					if (result == 0)
					{
						break;
					}
				}
				else
				{
					result = execute_command(token);
					if (result != 0)
					{
						break;
					}
				}
				token = strtok(NULL, " ");
			}
		}
	}

	free(command);

	return (0);
}
