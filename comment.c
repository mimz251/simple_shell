#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_command_length 200

/**
 * main - this function allows a comment in the shell
 * Return: 0
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

		char *comment_pos = strchr(command, '#');

		if (comment_pos != NULL)
		{
			*comment_pos = '\0';
		}
		if (strcmp(command, "exit") == 0)
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
