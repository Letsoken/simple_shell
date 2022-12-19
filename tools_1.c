#include "main.h"

size_t readline(char **buffer, FILE *stream);
char **_splstr(char **buffer, size_t characters);
void execute(char **av);


/**
  * readline - reads string fron input stream and removes newline.
  *@buffer: buffer
  *@stream: File stream
  *Return: number of characters read from input stream less newline.
  */
size_t readline(char **buffer, FILE *stream)
{
	size_t len = 0;
	size_t  chars = getline(buffer, &len, stream);

	if ((*buffer)[chars - 1] == '\n')
	{
		(*buffer)[chars - 1] = '\0';
		--chars;
	}

	return (chars);
}

/**
  * _splstr - splits string into an array of strings.
  * @buffer: buffer
  * @characters: number of characters in buffer
  * Return: an array of strings.
  */
char **_splstr(char **buffer, size_t characters)
{
	size_t wordcount, c;
	int i;
	char **_argv;
	char *ptr;
	const char *s = " ";


	wordcount = 0;
	c = 0;

	if (buffer == NULL)
		return (NULL);
	/*calculate total number of words*/
	while (c < characters && buffer[0][c])
	{
		if (buffer[0][c] == ' ')
			wordcount++;
		c++;
	}
	if (wordcount == 0)
		wordcount++;

	_argv = malloc((wordcount + 1) * sizeof(char *));
	if (_argv == NULL)
		return (NULL);

	ptr = strtok(*buffer, s);

	for (i = 0 ; ptr != NULL ; i++)
	{
		_argv[i] = malloc((_strlen(ptr) + 1) * sizeof(char));

		if (_argv[i] == NULL)
		{
			for (; i >= 0; i--)
				free(_argv[i]);
			free(_argv);
			return (NULL);
		}

		strcpy(_argv[i], ptr);
		ptr = strtok(NULL, s);
	}
	_argv[i] = NULL;

	return (_argv);
}

/**
  * execute - executes the command arguments.
  * @av: an array of arguments.
  */
void execute(char **av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(av[0], av, environ) == -1)
		{
			perror(av[0]);
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
		perror("Error:");
}
