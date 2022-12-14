#include "main.h"


unsigned int _strlen(const char *s);
char **_splstr(char **buffer, size_t characters);


/**
  *
  */
unsigned int _strlen(const char *s)
{
	unsigned int count = 0;
	
	while(*s!='\0')
	{
		count++;
		s++;
	}
	return count;
}


/**
  *
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
	
	ptr = strtok (*buffer, s);

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
		ptr = strtok (NULL, s);
	}
	_argv[i] = NULL;

	return (_argv);
}
