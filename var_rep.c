#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define max_command_length 200

void replace_variables(char* command)
{
	char* token = strtok(command, " ");
	while (token != NULL)
	{
		if (strcmp(token, "$?") == 0)
		{
			snprintf(token, sizeof(token), "%d", WEXITSTATUS(system("true")));
		}
		/* Replace $$ with the PID of the shell process*/
		else if (strcmp(token, "$$") == 0)
		{
			snprintf(token, sizeof(token), "%d", getpid());
		}
		token = strtok(NULL, " ");
	}
}

int main()
{
	char command[max_command_length];

	while (1)
	{
		printf("$ ");
		fgets(command, sizeof(command), stdin);

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
