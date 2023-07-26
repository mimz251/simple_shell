#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shell.h>

#define max_command_length 200

/**
 * main - allow the function that handles the exit status
 * Return: 0 success
 */
int main(void)
{
	char command[max_command_length];

	while (1)
	{
		printf("$ ");
		sstream(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';
		/* Remove trailing newline from the command*/

		if (strncmp(command, "exit", 4) == 0)
		{
			/*Parse the exit status*/
			int status = 0;
			char *arg = strtok(command, " ");

			arg = strtok(NULL, " ");

			if (arg != NULL)
			{
				status = atoi(arg);
			}
			exit(status);
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
