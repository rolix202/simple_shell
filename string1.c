#include "shell.h"

/**
 * _strcpy - This function copies a character string form the file 
 * @dest: the destination of the character 
 * @src: the source of the character 
 *
 * Return: The pointer to the destination of the file 
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - This function duplicates the cahracter string
 * @str: the string to be  duplicated 
 *
 * Return:the  pointer to the duplicated from the string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - this prints an input character  from string
 * @str: the string to be printed onto the string 
 *
 * Return: Null value 
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - This writes the character c to the standard output
 * @c: Thi is  the  character to print
 *
 * Return: if  successful return  1 ortherwise return 
 * if failure return, -1
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}


