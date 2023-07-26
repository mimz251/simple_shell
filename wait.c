#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
/*
 * main - entry point
 * wait: system call
 * pid_t: stores process ids
 */
int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("child process\n");
	}
	else
	{
		wait (NULL);
		sleep(10);
		printf("Parent process\n");
	}
	return (0);
}
