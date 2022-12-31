#include "main.h"

/**
  * main - Shell.
  * freeav - av
  * Return: Always 0 on success.
  */
int main(void)
{
	char *buffer = NULL;
	char **av;
	int nread = 0;

	signal(SIGINT, sig_handler);
	while (nread != EOF)
	{
		_isatty();
		nread = readline(&buffer, stdin);
		_EOF(nread, buffer);
		av = _splstr(&buffer, nread);

		if (!av || !av[0])
		{
			free(buffer);
			free(av);
			continue;
		}

		execute(av);
	}
	freeav(av);
	free(buffer);
	return (0);
}
