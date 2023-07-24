#include <stdio.h>
#include <stdlib.h>

int main(void) {
	size_t n = 0;
	ssize_t read;
	char *buff = NULL;

	while (1)
	{
		printf("collabo$ ");
		read = getline(&buff, &n, stdin);
		if (read != -1)
		{
			printf("Date is %s buffer size is %ld\n", buff, n);
		}
		if (read == -1)
			perror("Error");
		free(buff);
		buff = NULL;

	}

	return 0;
}
