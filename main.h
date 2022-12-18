#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

unsigned int my_strlen(const char *s);
size_t readline(char **buffer, FILE *stream);
char **_splstr(char **buffer, size_t characters);

#endif
