#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define max_command_length 200

void replace_variables(char *command, int exit_status, int pid)
{
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		if (strcmp(token, "$?") == 0)
		{
			printf(token, max_command_length, "%d", exit_status);
		}
		else if (strcmp(token, "$$") == 0)
		{
			printf(token, max_command_length, "%d", pid);
		}
		token = strtok(NULL, " ");
	}
}

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	int status = 0;

	while (1)
	{
		printf("$ ");
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
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
			}
			else if (pid == 0)
			{
				status = execlp(command, command, NULL);
				if (status == -1)
				{
					perror("execlp");
				}
				exit(status);
			}
			else
			{
				wait(&status);

				int exit_status = WEXITSTATUS(status);

				replace_variables(command, exit_status, getpid());
				printf("%s\n", command);
			}
		}
	}

	free(command);

	return (0);
}
