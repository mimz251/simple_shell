#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define max_command_length 200

/**
 * main -  function that allows the cd command to work in shell
 * Return: 0 success
 */

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

		char *token = strtok(command, " ");
		char *cmd = token;

		token = strtok(NULL, " ");

		char *arg = token;

		if (cmd != NULL && strcmp(cmd, "cd") == 0)
		{
			if (arg == NULL)
			{
				arg = getenv("HOME");
			}
			else if (strcmp(arg, "-") == 0)
			{
				char *prev_dir = getenv("OLDPWD");

				if (prev_dir != NULL)
				{
					arg = prev_dir;
				}
				else
				{
					printf("cd: OLDPWD not set\n");
					continue;
				}
			}
			char *getcwd(char *buf, size_t size);

			if (getcwd(cmd, sizeof(cmd)) == NULL)
			{
				perror("getcwd");
				continue;
			}
			setenv("OLDPWD", cmd, 1);
			if (chdir(arg) != 0)
			{
				perror("cd");
			}
			else
			{
				if (getcwd(cmd, sizeof(cmd)) != NULL)
				{
					setenv("PWD", cmd, 1);
				}
				else
				{
					perror("getcwd");
				}
			}
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
