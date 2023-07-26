#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <shell.h>

/**
 * main - entry point
 * Return: 0 success
 * else 1 failure
 */
int main(void)
{
	/*accessing the directory*/
	DIR *directory;

	/*store pointer*/
	struct dirent *entry;

	directory = opendir("."); /*open directory*/

	if (directory == NULL)
	{
		printf("Can't open directory.\n");
		return (1);
	}

	while ((entry = readdir(directory)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			printf("File: %s\n", entry->d_name);
		}

		else if (entry->d_type == DT_DIR)
		{
			printf(" dir: %s\n", entry->d_name);
		}
	}
	if (closedir(directory) == -1)
	{
		printf("Error closing directory.\n");
		return (1);
	}

	return (0);
}
