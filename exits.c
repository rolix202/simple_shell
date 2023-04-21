#include "shell.h"

/**
 **_strncpy -This  copies a string for concatenation
 *@dest: the destination string to copy string to 
 *@src: the source string to copy straing from 
 *@n: the amount of characters to be copied all together 
 *Return: the concatenated string put togather 
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - This concatenates two strings to make one 
 *@dest: the first string to be concatenated 
 *@src: the second string to be concatenated 
 *@n: the amount of bytes to be maximally used for the concatenation 
 *Return: the concatenated string put toegtehr as one 
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - This  locates a character in a string file 
 *@s: the character  string to be parsed out
 *@c: the character to look for to locate the string 
 *Return: return  a pointer to the memory area of stack 
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}


