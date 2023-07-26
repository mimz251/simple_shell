#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#inclde <shell.h>

/**
 * main - entry point
 * Return: 0 success
 */
void print_environment(void)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

int main(void)
{
	sstream ss;
	char command[1000];

	while (1)
	{
		printf("$ ");
		ss(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break; /*Exit the shell*/
		}
		else if (strcmp(command, "env") == 0)
		{
			print_environment();
		}
		else
		{
			int status = system(command);

			if (status != 0)
			{
				printf("Command execution failed.\n");
			}
		}
	}

	return (0);
}
