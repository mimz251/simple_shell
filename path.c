#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

/**
 * main - function that handles printing of directory in variable
 * Retur: 0 success
 * else 1 fail
 */
/* Linked list node to store the directories*/
struct PathNode
{
	char *directory;
	struct PathNode *next;
};

/* Function to free the linked list memory*/

void free_path_list(struct PathNode *head)
{
	struct PathNode *current = head;

	while (current != NULL)
	{
		struct PathNode *next = current->next;

		free(current->directory);
		free(current);
		current = next;
	}
}

int main(void)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		printf("PATH environment variable is not set.\n");
		return (1);
	}

	struct PathNode *head = NULL;
	struct PathNode *tail = NULL;

	char *path_copy = strdup(path_env);

	if (path_copy == NULL)
	{
		perror("strdup");
		return (1);
	}

	char *path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		struct PathNode *new_node = (struct PathNode *)malloc(sizeof(struct PathNode));

		if (new_node == NULL)
		{
			perror("malloc");
			free_path_list(head);
			free(path_copy);
			return (1);
		}

		new_node->directory = strdup(path_token);
		new_node->next = NULL;

		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}

		path_token = strtok(NULL, ":");
	}

	free(path_copy);

	/* Print each directory in the PATH*/
	struct PathNode *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}

	free_path_list(head);

	return (0);
}
