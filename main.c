#include "main.h"

/**
  *
  */
int main(void)
{
	char *buffer = NULL;
	char **av;
	int ac;
	pid_t child_pid1;
	int status; /* size_t characters can be used to hold return of getline()*/
	size_t characters;

	printf("($) ");

	/*char *strtok(char *str, const char *delim);*/
	/*getline(char **strin, size_t *n, FILE *stream)*/
	
	/*characters = getline(&buffer, &bufsize, stdin);*/
	characters = readline(&buffer, stdin);
	av = _splstr(&buffer, characters);

	if (av == NULL)
	{
		perror("av is Null. Could not execute\n");
		exit(1);
	}

	ac = 0;	
	while (av[ac])
	{
		ac++;
	}

	if ( av[0] == "exit")
		return (0);

	child_pid1 = fork(); 

	if (child_pid1 == -1)
	{
		perror("Error");
		return (1);
	}

	if (child_pid1 == 0)
	{	
		if (execve(av[0], av, environ) == -1)
			perror("Error");
		sleep(3);
	}
	else
	{
		wait(&status);


		for (; ac > 0; ac--)
			free(av[ac - 1]);
		free(av);

		free(buffer);
	}
	return (0);
}
