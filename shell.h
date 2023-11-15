#ifndef _SHELLS_H_
#define _SHELLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* To read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Do command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* To convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field node
 * @str: a string
 * @next: pointing to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfl: the fl from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* ptr to cmd ; chain buffer, for mem mgt */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfl;
	int histcount;
} runtime_info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(runtime_info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(runtime_info_t *, char **);
int find_builtin(runtime_info_t *);
void find_cmd(runtime_info_t *);
void fork_cmd(runtime_info_t *);

/* toem_custom_parser.c */
int custom_is_cmd(runtime_info_t *, char *);
char *custom_dup_chars(char *, int, int);
char *custom_find_path(runtime_info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_error_handling.c */
void _eputs(char *);
int _eputchar(char);
int _putfl(char c, int fd);
int _putsfl(char *str, int fd);

/* toem_string_man.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string_man1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_string_manipulation.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenize.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realm.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_custom_utils.c */
int cuz_interactive(runtime_info_t *);
int cuz_is_delim(char, char *);
int cuz_isalpha(int);
int cuz_atoi(char *);

/* toem_error_handling2.c */
int _erratoi(char *);
void print_error(runtime_info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_custom_builtin.c */
int cuz_myexit(runtime_info_t *);
int cuz_mycd(runtime_info_t *);
int cuz_myhelp(runtime_info_t *);

/* toem_builtin2.c */
int cuz_myhistory(runtime_info_t *);
int _myalias(runtime_info_t *);

/*toem_input.c */
ssize_t get_input(runtime_info_t *);
int _getline(runtime_info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_info.c */
void clear_info(runtime_info_t *);
void set_info(runtime_info_t *, char **);
void free_info(runtime_info_t *, int);

/* toem_environment_manager.c */
char *_getenv(runtime_info_t *, const char *);
int _myenv(runtime_info_t *);
int _mysetenv(runtime_info_t *);
int _myunsetenv(runtime_info_t *);
int populate_env_list(runtime_info_t *);

/* toem_environment.c */
char **get_environ(runtime_info_t *);
int _unsetenv(runtime_info_t *, char *);
int _setenv(runtime_info_t *, char *, char *);

/* toem_history.c */
char *get_history_file(runtime_info_t *info);
int write_history(runtime_info_t *info);
int read_history(ruuntime_info_t *info);
int build_history_list(runtime_info_t *info, char *buf, int linecount);
int renumber_history(runtime_info_t *info);

/* toem_custom_list.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_custom_lists2.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_chaining.c */
int cuz_is_chain(runtime_info_t *, char *, size_t *);
void cuz_check_chain(runtime_info_t *, char *, size_t *, size_t, size_t);
int replace_alias(runtime_info_t *);
int replace_vars(runtime_info_t *);
int replace_string(char **old, char *new);

#endif
