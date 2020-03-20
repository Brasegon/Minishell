/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** Brandon sgeers
*/
#include "struct.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>

void setenvi(s_t *t)
{
    char **env = t->newenv;
    int b = 0;

    t->var = 0;
    if (t->arg[1] == NULL)
        return;
    t->newenv = malloc(sizeof(char **) * b + 2);
    while (env[b]) {
        t->newenv[b] = my_strdup(env[b], t->newenv[b], 0);
        b++;
    }
    t->newenv[b] = malloc(sizeof(char *) * my_strlen(t->arg[1]) + 1);
    t->newenv[b] = t->arg[1];
    t->newenv[b] = my_strcat(t->newenv[b], "/");
    t->newenv[b + 1] = malloc(sizeof(char *) * 1);
    t->newenv[b + 1] = 0;
}

void command(char **env, s_t *t)
{
    t->arg = my_str_to_wordtab(t->str, 0);
    t->var = 10;
    if (my_strcmp(t->arg[0], "setenv") == 0)
        setenvi(t);
    if (my_strcmp(t->arg[0], "cd") == 0)
        cd_command(t);
    if (my_strcmp(t->arg[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    execution(env, t);
}

void aff(s_t *t)
{
    int i = 0;
    int j = 0;
    char str[256];

    getcwd(t->dir, sizeof(t->dir));
    for (; t->dir[i]; i++);
    for (; t->dir[i] != '/'; i--);
    i += 1;
    for (; t->dir[i];) {
        str[j] = t->dir[i];
        j++;
        i++;
    }
    str[j] = '\0';
    my_printf("\033[1;32m➜\033[1;36m  %s\033[0;38m ", str);
}

void cd_command(s_t *t)
{
    DIR* rep = NULL;

    t->var = 0;
    if (t->arg[1] == NULL)
        chdir(t->home[0]);
    else if (my_strcmp(t->arg[1], "-") == 0) {
        rep = (t->arg[1] == NULL) ? 0 : opendir(t->tmp);
        if (rep == NULL)
            perror("cd");
        chdir(t->tmp);
        my_printf("%s\n", t->tmp);
    } else {
        rep = (t->arg[1] == NULL) ? 0 : opendir(t->arg[1]);
        if (rep == NULL)
            perror("cd");
        chdir(t->arg[1]);
    }
    my_strcpy(t->tmp, t->dir);
}

void exec(char **env, s_t *t)
{
    int b = 0;

    while (t->newenv[b] && t->var != 0) {
        t->len = my_strcat(t->newenv[b], t->arg[0]);
        if (execve(t->len, t->arg, env) != 0
            && my_strcmp(t->str, "cd") == 1)
            t->z = -1;
        else
            t->z = 0;
        b++;
    }
}
