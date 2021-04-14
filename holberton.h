#ifndef _HOLB_
#define _HOLB_
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#define DELIMS " \t\0"
/**
 *struct path_s - linked list structure for PATH variable
 *@directory: directory to search
 *@next: pointer to the next node
 *
 *Description: singly linked list node structure for PATH variable
 */
typedef struct path_s
{
	char *directory;
	struct path_s *next;
} path_t;

void printprompt(void);
int _strlen(char *buf);
int printpath(char *path);
void print_path(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_concat(char *concatenate, char *s1, char *s2);
int _atoi(char *s);

int check_builtins(char **ar, char **env, char *line, char *newline, int cdnum);
char *printint(int num);
path_t *create_ll(char *str);
path_t *fill_list(char *str, path_t *list);
void free_list(path_t *head);
void free_tokens(char **tokenarray);
void free_all(char *line, char *newline, char **tokenarray);
int ctrld(char *line);
void ctrlc(int signum);
void no_file_er(char **argv, char **ar, int cmdnum, char *line, char *nline);
int exit_op(char **array, char *line, char *newline, int cdnum);
int cd_op(char **array, char **env);
int env_op(char **env);
char **tokensplit(char *line);
int exec(char **ar, char **env, char **av, char *line, char *nline, int cdnum);
char *_getenv(const char *name, char **env);
char **_realloccharss(char **ptr, int n);
char *_reallocchar(char *ptr);
char *path_handler(char *str, char **env);

#endif
