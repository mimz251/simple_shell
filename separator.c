#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 200

/**
 * execute_command: Function that executes the given command.
 * @command: The command to be executed.
 * reads the input using getline() in the input from stdin and the output.
 * main - shell program that runs shell commands.
 */
void execute_command(const char *command)
{
	int status = system(command);

	if (status == -1)
	{
		printf("Command execution failed.\n");
	}
	else
	{
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			printf("Command exited with status: %d\n", exit_status);
		}
		else
		{
			printf("Command did not exit normally.\n");
		}
	}
}

int main(void)
{
	size_t n = 0;
	ssize_t read;
	char *buff = NULL;

	while (1)
	{
		printf("collabo$ ");

		read = getline(&buff, &n, stdin);
		if (read != -1)
		{
			buff[strcspn(buff, "\n")] = '\0';

			char *token = strtok(buff, ";");

			while (token != NULL)
			{
				execute_command(token);
				token = strtok(NULL, ";");
			}
		}
		if (read == -1)
		{
			perror("Error");
			break;
		}

		free(buff);
		buff = NULL;
	}

	return (0);
}

