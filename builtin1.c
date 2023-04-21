#include "shell.h"

/**
 * _myhistory - This displays the history list, one command by line, preceded
 *              with line numbers, starting at 0 and in cronological oorder 
 * @info: Thew Structure containing arguemnts to maintain the function 
 *        constant function
 *  Return: Always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This sets alias to the character string string
 * @info: parameter structure 
 * @str: the string alias for the function 
 *
 * Return: Always 0 on success, 1 on failure 
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - This sets alias to the character string
 * @info: parameter structure information 
 * @str: the string alias function 
 *
 * Return: Always 0 on success, 1 on failure 
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This  prints the  alias of the string character
 * @node: the alias node fuction 
 *
 * Return: Always 0 on success, 1 on failure 
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias -replicates  the alias built in 
 * @info: This Structure containing the  arguments used to maintain the function
 *          constant function 
 *  Return: Always returns 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

