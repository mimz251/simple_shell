#include <stdio.h>
#include <unistd.h>
#include <shell.h>

/**
 * main - compares variables for env and environ
 * @av: argument vector
 * @ac: argument counter
 * @env: environment variable
 * Return: 0 success
 */

int main(int ac, char *av[], char *env[])
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
