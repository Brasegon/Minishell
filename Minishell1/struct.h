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
} s_t;

char *get_next_line(int const fd);
char    **my_str_to_wordtab(char const *str, int z);
char **get_env(char **env, s_t *t);
void execution(char **env, s_t *t);
void minishell(char **env);
char *my_strcat(char *str1, char *str2);
void cd_command(s_t *t);
void exec(char **env, s_t *t);
char *my_strcpy(char *src, char *dest);
int my_strcmp(char *s1, char *s2);
void aff(s_t *t);
void setenvi(s_t *t);
void free_tab(s_t *t, int z);
void command(char **env, s_t *t);
char *suppr_space(s_t *t);
char *my_strdup(char *str, char *dest, int i);
char **test(s_t *t, char **env, int i);
char **env_null(s_t *t);
