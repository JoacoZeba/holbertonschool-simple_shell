#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* split_line - Splits a string into words
* @line: The input string
* Return: Pointer to an array of strings (tokens)
*/
char **split_line(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n"); /* First word */

	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc failed");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n"); /* Next word */
	}
	tokens[i] = NULL; /* Null-terminate the array */

	return (tokens);
}

/**
 * main - Reads a line and prints each token
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	int i;

	printf("$ ");
	getline(&line, &len, stdin);

	args = split_line(line);

	for (i = 0; args[i] != NULL; i++)
		printf("arg[%d]: %s\n", i, args[i]);

	free(line);
	free(args);

	return (0);
}

