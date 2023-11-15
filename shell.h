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

#define SEPARATE_STRING " \t\r\n\a"

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
char *_itoa(int num, char *str, int base);

/*libc made functions2*/
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strrev(char *s);
int _snprintf(char *str, size_t size, const char *format, ...);
int _atoi(const char *s);

/**stringtokens*/
char *_strtok(char *line, char *delim);
int _delim(char c, char *delim);
char **tokenize(char *line);
int delim_count(char *string, char delim);

/** defined functions **/
void start_shell(const char **argv, runtime_t *runtime);
void print_prompt(void);
void trim_start(char **string);
void command_options(char *command, const char **argv, runtime_t *runtime);
int find_number_of_strings(char *command);


/** handle comment **/
void handle_comment(char *input);
void handle_newline(char *str);
void execute(char *command, char **av, const char**argv, runtime_t *runtime);
void execute_command_args_with_path(char *command, const char **argv, runtime_t *runtime);
void execute_command_no_args_with_path(char *command, const char **argv, runtime_t *runtime);
void find_path(char *command, const char **argv, runtime_t *runtime);
void print_command_error(char *command, const  char **argv, runtime_t *runtime);
int  builtin_command(char *command, const char **argv, runtime_t *runtime);
int contains_chars(const char *s);
void print_env(void);
void free_resources(runtime_t *runtime);
/** handler functions */
int handle_string(va_list list, size_t *size, char *str);
int handle_char(va_list list, size_t *size, char *str);
int handle_normal_char(const char *format, size_t *size, char *str);


/**memory management */
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
#endif
