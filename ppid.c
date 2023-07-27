#include <stdio.h>
#include <unistd.h>
/**
 * main - gives the process id of child and parent
 * pid - process id
 * ppid - parent process id
 * Return: 0 success
 * else 1 unsuccessful
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
