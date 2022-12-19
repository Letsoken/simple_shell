<<<<<<< HEAD
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>





extern char **environ;

/*tools_1*/
size_t readline(char **buffer, FILE *stream);
char **_splstr(char **buffer, size_t characters);
void execute(char **av);

/*tools_2*/
void sig_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);
void freeav(char **av);

/*strings_1*/
unsigned int _strlen(const char *s);
char *concat_all(char *name, char *sep, char *value);
char *_strdup(char *str);
int _putchar(char c);
void _puts(char *str);

/*strings_2*/
int _strcmp(char *s1, char *s2);

#endif
