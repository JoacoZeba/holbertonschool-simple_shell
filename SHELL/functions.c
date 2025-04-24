#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
* trim_spaces - removes leading spaces from input
* @str: input string
* Return: pointer to trimmed string
*/
char *trim_spaces(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '-' || *str == '_')
		str++;
	return (str);
}

/**
* phrase_arguments - split the command line into arguments (by spaces)
* @line: the input line to split
* Return: an array of strings (arguments)
*/
char **phrase_arguments(char *line)
{
	char **args = malloc(sizeof(char *) * 64);
	char *arg;
	int i = 0;

	arg = strtok(line, " \t\r\n");
	while (arg != NULL)
	{
		args[i] = arg;
		i++;
		arg = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;
	return (args);
}
