#include <stdlib.h>
#include <stdio.h>
/**
 * main - creates an enviroment variable.
 * @var -
 * @value
 * Return: 0.
 */
int main(void)
{
	char *var = "struggles_1";
	char *value = "earth, hard";

	if (setenv(var, value, 1) == 0)
	{
		printf("success");
	}

	else
	{
		printf("ERROR");
	}
	return (0);
}
