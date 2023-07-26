#include <stdio.h>
#include <unistd.h>

/*
 * main - entry point
 * @av: argument vector
 * @ac: argument counter
 * @env: environment variable
 */
extern char **environ;

int main(int argc, char *argv[], char *env[]) 
{
	printf("Address of env : %p\n", (void *)env);
	printf("Address of environ: %p\n", (void *)environ);

	/*Compare the addresses*/
	if (env == environ)
	{
		printf("The addresses are the same.\n");
	}
	else
	{
		printf("The addresses are different.\n");
	}
	return (0);
}
