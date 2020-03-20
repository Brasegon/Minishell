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
    char *var = ".";

    t->var = 0;
    t->newenv = malloc(sizeof(char **) * b + 3);
    while (env[b]) {
        t->newenv[b] = my_strdup(env[b], t->newenv[b], 0);
        b++;
    }
    t->newenv[b] = malloc(sizeof(char *) * 1 + 1);
    t->newenv[b] = var;
    t->newenv[b] = my_strcat(t->newenv[b], "/");
    t->newenv[b + 1] = malloc(sizeof(char *) * 1);
    t->newenv[b + 1] = 0;
}

void command(char **env, s_t *t, char *str)
{
    t->arg = my_str_to_wordtab(str, 0);
    if (t->arg[0] == NULL || t->arg[0][0] == ' ')
        return;
    t->var = 10;
    if (my_strcmp(t->arg[0], "cd") == 0)
        cd_command(t);
    if (my_strcmp(t->arg[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    execution(env, t, str, 0);
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
            perror(t->arg[1]);
        chdir(t->tmp);
    } else {
        rep = (t->arg[1] == NULL) ? 0 : opendir(t->arg[1]);
        if (rep == NULL)
            cd_error(rep, t->arg[1]);
        chdir(t->arg[1]);
    }
    my_strcpy(t->tmp, t->dir);
}

void exec2(char **env, s_t *t, char *str)
{
    int b = 0;

    if ((my_strlen(str) > 20) || (t->ta >= 3) || (t->ta >= 2 && t->red == 1))
        exit(84);
    while (t->newenv[b] && t->var != 0) {
        t->len = my_strcat(t->newenv[b], t->arg[0]);
        if (access(t->len, F_OK) == 0)
            break;
        b++;
    }
    if (execve(t->len, t->arg, env) != 0
        && my_strcmp(str, "cd") == 1)
        t->z = -1;
    else
        t->z = -1;
}
