#include "shell.h"

/**
 * interactive - returns true if the shell is on the interactive mode
 * @info: struct address
 * Return: 1 if on interactive mode, otherwise 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the char is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 *
 * Return: 1 and 0 conditionally
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - charcks for alpha chars
 * @c: Char input
 * Return: 1 or 0 conditionally
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * _atoi - converts string to int
 * @s: string to be converted
 *
 * Return: 0 if there's no number in string, otherwise converted value
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else
			if (flag == 1)
				flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
