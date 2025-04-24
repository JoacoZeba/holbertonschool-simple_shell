/**
 * trim_spaces - removes leading spaces from input
 * @str: input string
 *
 * Return: pointer to trimmed string
 */
char *trim_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}
