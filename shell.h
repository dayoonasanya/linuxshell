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
#include <stdarg.h>
#include <errno.h>


typedef struct
{
	int error_number;
	int last_proc_exit_status;
	char *error_msg;

} runtime_t;

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
char *_strrev(char *s);
int _snprintf(char *str, size_t size, const char *format, ...);
int _atoi(const char *s);



/** defined functions **/
void start_shell(const char **argv, runtime_t *runtime);
void print_prompt(void);
void trim_start(char **string);
void command_options(char *command, const char **argv, runtime_t *runtime);
int find_number_of_strings(char *command);
void execute(char **av, const char**argv, runtime_t *runtime);
void execute_command_args_with_path(char *command, const char **argv, runtime_t *runtime);
void execute_command_no_args_with_path(char *command, const char **argv, runtime_t *runtime);
void find_path(char *command, const char **argv, runtime_t *runtime);
void print_command_error(char *command, const  char **argv, runtime_t *runtime);
int  builtin_command(char *command, const char **argv, runtime_t *runtime);
int contains_chars(const char *s);
void print_env(void);

/** handler functions */
int handle_string(va_list list, size_t *size, char *str);
int handle_char(va_list list, size_t *size, char *str);
int handle_normal_char(const char *format, size_t *size, char *str);

#endif
