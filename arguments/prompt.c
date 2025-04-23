#include <stdio.h>
#include <stdlib.h>

/**
* main - Displays a prompt, reads a line, and prints it.
* Return: Always 0.
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			break;
		}
		printf("%s", line);
	}
	free(line);
	return (0);
}
