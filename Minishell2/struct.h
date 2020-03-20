/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Brandon Sgeres
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "lib/my_printf.h"
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_struct {
    char **newenv;
    char *test;
    char **home;
    char *str;
    char **arg;
    char *len;
    pid_t pid;
    int status;
    int           a;
    int           b;
    int           i;
    int var;
    int z;
    char dir[256];
    char tmp[256];
    int c;
    int d;
    int lev;
    char **first;
    char **se;
    char **te;
    int red;
    int tube[2];
    int ta;
    int tas;
    int ppid;
    int tr;
} s_t;

typedef struct l {
    int tube[2];
    int tube1[2];
    struct l *next;
}l_t;

char *get_next_line(int const fd);
char    **my_str_to_wordtab(char const *str, int z);
char **get_env(char **env, s_t *t);
void execution(char **env, s_t *t, char *str, int z);
void minishell(s_t *t, char **env);
char *my_strcat(char *str1, char *str2);
void cd_command(s_t *t);
void exec(char **env, s_t *t, char *str);
char *my_strcpy(char *src, char *dest);
int my_strcmp(char *s1, char *s2);
void aff(s_t *t);
void setenvi(s_t *t);
void free_tab(s_t *t, int z);
void command(char **env, s_t *t, char *str);
char *suppr_space(s_t *t);
char *my_strdup(char *str, char *dest, int i);
char **test(s_t *t, char **env, int i);
char **env_null(s_t *t);
char    **my_str_to_wordarray(char const *str, char c, int i);
void execv2(char **env, s_t *t, char *str);
void exec2(char **env, s_t *t, char *str);
char *cp(char *dest, char const *src, int i, int n);
int lenline(char const *str);
void redir(s_t *t);
l_t *add_params(l_t *list);
void pipe_gestion(s_t *t);
void cd_error(DIR *rep, char *str);
