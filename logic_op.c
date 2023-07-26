#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char command[1000];

	printf("Enter: ");
	fgets(command, sizeof(command), stdin);

	char *token = strtok(command, "&|");
	int last_status = 0;

	while (token != NULL)
	{
		int start = 0;
		while (token[start] == ' ' || token[start] == '\t')
		{
			start++;
		}

		int end = strlen(token) - 1;
		while (end >= start && (token[end] == ' ' || token[end] == '\t' || token[end] == '\n'))
		{
			token[end] = '\0';
			end--;
		}

		if (strlen(token) > 0)
		{
			int status = system(token);
			last_status = status;
		}

		token = strtok(NULL, "&|");

		if (token != NULL)
		{
			if (token[0] == '&')
			{
				if (last_status == 0)
				{
					token++;
				}
				else
				{
					token = strtok(NULL, "|");
				}
			}
			else if (token[0] == '|')
			{
				if (last_status != 0)
				{
					token++;
				}
				else
				{
					token = strtok(NULL, "&");
				}
			}
		}
	}

	return (0);
}
