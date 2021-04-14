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
#define DELIMITERS " \t\0"
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
} linked_t;

void shellPrompt(void);
int _strlen(char *buf);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strconcat(char *s1, char *s2);
char *_concatenate(char *concatenate, char *s1, char *s2);
int _atoi(char *s);

int checkBuiltins(char **ar, char **env, char *line, char *newline, int cmd_count);
char *print_int(int num);
linked_t *create_linkedt(char *str);
linked_t *addnodes_list(char *str, linked_t *list);
void free_list(linked_t *head);
void free_tokens(char **t_array);
void free_all(char *line, char *newline, char **t_array);
int ctrld_handler(char *line);
void ctrlc_handler(int signum);
void error_handler(char **argv, char **ar, int cmdcount_int, char *line, char *nline);
int exit_handler(char **array, char *line, char *newline, int cmd_count);
int cd_handler(char **array, char **env);
int env_handler(char **env);
char **tokenize(char *line);
int execute_cmd(char **ar, char **env, char **av, char *line, char *nline, int cmd_count);
char *_getenv(const char *name, char **env);
char *_realloc(char *ptr);
char *path_handler(char *str, char **env);

#endif
