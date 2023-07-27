#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * _execute - Execute the provided shell command using execv().
 * @command: The shell command to be executed.
 * Return: Return value of the executed command.
 */
int _execute(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork unsuccessful");
		return (1);
	}
	else if (pid == 0)
	{
		char *args[] = {command, NULL};

		execv(command, args);
		perror("Unsuccessful");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		wait(&status);
		return (status);
	}
}

/**
 * main - Shell program that runs shell commands.
 * Reads the input using getline() from stdin.
 * Return: Always 0.
 */
int main(void)
{
	char *buff = NULL;
	size_t n = 0;
	ssize_t read;

	while (1)
	{
		printf("collabo$ ");
		read = getline(&buff, &n, stdin);

		if (read != -1)
		{
			printf("Name is %s buffer size is %zu\n", buff, n);
		}

		if (read == -1)
		{
			perror("Error");
		}

		int result = _execute(buff);

		printf("Command execution result: %d\n", result);

		free(buff);
		buff = NULL;
	}

	return (0);
}
