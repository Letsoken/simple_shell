#include "main.h"

/**
  *
  */
size_t readline(char **buffer, FILE *stream)
{
	size_t len = 0;
	size_t  chars = getline(buffer, &len, stream);
	if((*buffer)[chars - 1] == '\n')
	{
		(*buffer)[chars - 1] = '\0';
		--chars;
	}

	return chars;
}
