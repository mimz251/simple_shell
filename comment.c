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
	char command[max_command_length];

	while (1)
	{
		printf("$ ");
		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';/*removes trailing space*/

		if (strcmp(command, "exit") == 0)
		{
			break;/*Exit the shell*/
		}
		else
		{
			char *comment_pos = strchr(command, '#');

			if (comment_pos != NULL)
			{
				*comment_pos = '\0';
			}

			int status = system(command);

			if (status != 0)
			{
				printf("Command execution failed.\n");
			}
		}
	}

	return (0);
}
