#include <stdio.h>

/**
* main - Print all arguments passed to the program.
* @ac: argument count (unused)
* @av: argument vector
* Return: Always 0.
*/
int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
