#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/* Function to print all environment variables*/
void print_environment()
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

int main()
{
	char command[1000];

	while (1)
	{
		printf("$ ");
		fgets(command, sizeof(command), stdin);
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
