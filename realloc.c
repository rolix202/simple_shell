#include "shell.h"

/**
 * _memset - This fills the  memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill 
 * @n: the amount of bytes to be filled by the function 
 * Return: a pointer to the memory area 
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - This function frees a string of strings
 * @pp: string of charcters 
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - To  re allocates a block of memory
 * @ptr: The pointer to previous  block
 * @old_size:The  byte size of previous block
 * @new_size: The byte size of new block
 *
 * Return: return a pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

