#include "shell.h"

/**
 * interactive - this returns true if the simple shell is interactive mode
 * @info: strucuret address
 *
 * Return: 1 if is in interactive mode,otherwise  return 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - This function checks if character is a delimeter
 * @c: the characers  to check foor delimeter
 * @delim: the delimeter string to retuen 
 * Return: 1 if is true, return  0 if is false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - this checks for alphabetic characters to be converted 
 * @c: The character string to input at the command line 
 * Return: 1 if c is an  alphabetic,  otherwise return 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - This file  converts a string to an integer number 
 * @s: This is the  string to be converted to an integer number 
 * Return: 0 if the  numbers in string are  converted number otherwise 1
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
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}


