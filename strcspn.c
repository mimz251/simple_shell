#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - function to find the length of the initial segment of the string str.
 * @length - variable of unsigned integer.
 * @str - string to be checked.
 * @decline - contains delimeters.
 * Return: 0.
 */
int main(void)
{
	char str[] = "CODING IS AWESOME!";
	char decline[] = " ;";

	size_t length = strcspn(str, decline);

	printf("Length of initial segment: %zu\n", length);

	return (0);
}
