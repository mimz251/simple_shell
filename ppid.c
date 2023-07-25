#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point
 * pid - process id
 * ppid - parent process id
 */
int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(10);
		printf("I am the child\n");
	}

	else
	{
		ppid = getpid();
		printf("parent pid is: %u\n", ppid);
	}
	return (0);
}
