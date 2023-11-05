#ifndef MAIN_H
#define MAIN_H

/********************HEADER FILE*************************/
/**
 * File_name: __MAIN_H
 * Auth: dayoonasanya & chifundo365
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct builtin_s - builtins.
 * @env: environment.
 * @exit: exit.
 */
typedef struct builtin_s
{
	char *env;
	char *exit;
} builtin_s;

/**
 * struct info_s - info.
 * @f_exit: final exit.
 * @ln_count: count.
 */
typedef struct info_s
{
	int f_exit;
	int ln_count;
} info_s;

/**
 * struct flag_s - handle flags.
 * @intercative: interactive.
 */
typedef struct flag_s
{
	bool interactive;
} flag_s;

/* handle built ins */
int checker(char **cmd, char *buf);
void prompt_user(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

void print_env(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void)

/* helper function for efficient free */
void free_buffers(char **buf);
/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#endif
