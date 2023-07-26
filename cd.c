#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define max_command_length 200

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
		else if (strncmp(command, "cd ", 3) == 0)
		{
			const char* path = command + 3;

			if (strcmp(path, "-") == 0)
			{
				const char* prev_dir = getenv("OLDPWD");

				if (prev_dir != NULL)
				{
					path = prev_dir;
				}
				else
				{
					printf("No previous directory found.\n");
					continue;
				}
			}

			if (chdir(path) == 0)
			{    
				char current_dir[max_command_length];
				if (getcwd(current_dir, sizeof(current_dir)) != NULL)
				{
					setenv("PWD", current_dir, 1);
				}
				else
				{
					perror("getcwd");
				}
				char prev_dir[max_command_length];
				if (getenv("PWD") != NULL)
				{
					strncpy(prev_dir, getenv("PWD"), sizeof(prev_dir));
					setenv("OLDPWD", prev_dir, 1);
				}
			}
			else
			{
				perror("cd");
			}
		}
		else
		{
			int status = system(command);
			if (status != 0)
			{
				printf("Command failed.\n");
			}
		}
	}

	return (0);
}
