#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "functions.h"
void prompt(void);
char *read_line(void);
void execute_command(char *line, char **envp);

/**
 * main - entry point for the shell
 * @argc: argument count (unused)
 * @argv: argument vector (unused)
 * @envp: environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char *line;

	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();
		line = read_line();

		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
	
			line = trim_spaces(line);
		if (line[0] != '\0' && line [0] != ' ')
		execute_command(line, envp);
	}

	return (0);
}

/**
 * prompt - displays the shell prompt
 */
void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * read_line - reads a line from standard input
 *
 * Return: pointer to line, or NULL on failure
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
/**
 * execute_command - forks and executes the command
 * @line: command path to run
 * @envp: environment variables
 */
void execute_command(char *line, char **envp)
{

	pid_t pid;
	char **argv;

	argv = phrase_arguments(line);

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(line, argv, envp) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
