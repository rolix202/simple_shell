#include "shell.h"

/**
 * bfree - This function frees a pointer and give a  NULL value of the address
 * @ptr: The address of the pointer to freed
 *
 * Return: 1 if free, otherwise return 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

