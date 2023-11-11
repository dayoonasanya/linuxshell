#ifndef SHELL_H
#define SHELL_H

/**global variables*/
extern char **environ;

/* libc header files*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>

/**libc made functions*/
size_t _strcspn(const char *s, const char *reject);
size_t _strlen(const char *s);
char *_strchr(const  char *s, int c);
int _putchar(int c);
int puts(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *_getenv(const char *name);

/*libc made functions2*/
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);


/** defined functions **/
void start_shell(const char **argv);
void print_prompt(void);
void trim_start(char **string);
void command_options(char *command, const char **argv);
int find_number_of_strings(char *command);
void execute(char **av, const char **argv);
void execute_command_no_args_with_path(char *command, const char **argv);
void execute_command_args_with_path(char *command, const char **argv);


/** handle comment **/
void handle_comment(char *input);
#endif
