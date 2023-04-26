#include "shell.h"

/**
 * is_cmd - This  determines if a file is an executable command or not 
 * @info: the information  structure 
 * @path: the path to the file
 *
 * Return: 1 if true, otherwise return 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chs function ars - This function  duplicates the  characters in the string 
 * @pathstr: the PATH caharacter string function 
 * @start: start the  index function 
 * @stop: stop the  index function 
 *
 * Return:The  pointer to new buffer stroage file 
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path -This function  finds the  command in the PATH character string
 * @info: the information  structure 
 * @pathstr: the PATH character string
 * @cmd: the command to look for 
 *
 * Return:the  full path of the command if found otherwise return  NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

