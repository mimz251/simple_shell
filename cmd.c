#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/*
 * main - the entry point
 * av: argument vector
 * ac: argument counter
 */
int main(int ac, char *av[])
{
	printf("arguments entered are: %d\n",ac);

	for (int b = 0; b < ac; b++)
		printf("av[%d]=%s\n", b, av[b]);
	return (0);
}
