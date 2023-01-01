#include "main.h"

void sig_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);
void freeav(char **av);

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n $ ");
	}
}


/**
  * _EOF - handles the End of File
  * @len: return value of getline function
  * @buff: buffer
  */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}


/**
 * _isatty - verif if terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts(" $ ");
}


/**
 * freearv - frees the array of pointers arv
 * @av: array of pointers
 */
void freeav(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
}
