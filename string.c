#include "shell.h"

/**
 * _strlen - this function returns the length of a string
 * @s:this is the string whose length is tobe  checked
 *
 * Return:the  integer length of the  string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - this functions  performs the comparison of two strings 
 * @s1: this does the comparison of the first string 
 * @s2: this does the comaparison for the second string 
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with -this  checks if needle starts with haystack
 * @haystack: this is thestring to search
 * @needle: the substring to find after the search
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - This function concatenates two strings
 * @dest: the destination buffer of the string 
 * @src: the source buffer of the straing 
 *
 * Return: a pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

