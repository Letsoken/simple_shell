#include "main.h"

/**
  * _strcmp - compare elements of string s1 and s2
  * @s1: pointer to string 1
  * @s2: pointer to string 2
  *
  * Return: difference between strings
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
