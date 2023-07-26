#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - function that handles the execution process in shell
 * Return: 0 success
 */
int main(void)
{
	pid_t pid;
	char *av[] = {"/bin/ls", "-l", NULL};

	pid = fork();

	if (pid == -1)
	{
		return (-1);
	}
	if (pid == 0)
	{
		int val = execve(av[0], av, NULL);

		if (val == -1)
			perror("Error");
	}
	else
	{
		wait(NULL);
		printf("execve successful\n");
	}
	return (0);
}
