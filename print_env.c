#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

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

		if (strcmp(command, "env") == 0)
		{
			char **env_var = environ;

			while (*env_var != NULL)
			{
				printf("%s\n", *env_var);
				env_var++;
			}
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else
		{
			int status = system(command);

			if (status != 0)
			{
				printf("failed.\n");
			}
		}
	}

	free(command);

	return (0);
}
