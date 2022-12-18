#include "shell.h"

/**
 * _myhistory - shows the hist list, one command by line preceded with 
 * line nums, starting with 0
 *
 * @info: Struct containing potential args. Used to maintain
 * const func prototype
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter  struct
 * @str: string alias
 *
 * Return: Always 0 on success, otherwise 1
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
			get_node_index(info->alias, node_starts_with(info-.alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - set string to alias
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success and 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, st));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints a string alias
 * @node: alias node 
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{

		p = _strchr(node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin
 * @info: structure containing argd. Used to maintain
 * const funct prototype
 * Return: Always 0
 */
int  _myalias(info_t *info)
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
			print_alias(mode_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
