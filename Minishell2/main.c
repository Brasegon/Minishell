/*
** EPITECH PROJECT, 2019
** Brandon Segers
** File description:
** test
*/
#include "struct.h"
#include <fcntl.h>

char **get_env(char **env, s_t *t)
{
    int i = 0;
    char **newenv = NULL;

    while (env[i]) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
            env[i][3] == 'H')
            newenv = test(t, env, i);
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
            env[i][3] == 'E')
            t->home = my_str_to_wordtab(env[i], 5);
        ++i;
    }
    i = 0;
    while (newenv[i] != 0) {
        newenv[i] = my_strcat(newenv[i], "/");
        i++;
    }
    return (newenv);
}

void execution(char **env, s_t *t, char *str, int z)
{
    t->z = 0;
    if ((t->pid = fork()) == -1)
        exit(0);
    else if (t->pid == 0) {
        pipe_gestion(t);
        check_dir(t);
        exec2(env, t, str);
        if (t->z == -1 && t->var != 0) {
            my_printf("%s: Command not found.\n", t->arg[0]);
            exit(0);
        }
        if (t->var == 0)
            exit(0);
    } else {
        redir(t);
    }
}

void minishell(s_t *t, char **env)
{
    int z = 0;

    if (env[0] != NULL) {
        t->newenv = get_env(env, t);
        setenvi(t);
    }
    else
        t->newenv = env_null(t);
    for (aff(t); (t->str = get_next_line(0));) {
        pipe(t->tube);
        t->str = suppr_space(t);
        t->first = my_str_to_wordarray(t->str, ';', 0);
        for (int i = 0; t->first[i] != 0; i++)
            execv2(env, t, t->first[i]);
        aff(t);
    }
}

void c(int sig)
{
    int i = 0;
    int j = 0;
    char str[256];
    char dir[256];

    sig = sig + 0;
    getcwd(dir, sizeof(dir));
    for (; dir[i]; i++);
    for (; dir[i] != '/'; i--);
    i += 1;
    for (; dir[i];) {
        str[j] = dir[i];
        j++;
        i++;
    }
    str[j] = '\0';
    my_putstr("\n");
    my_printf("\033[1;32m➜\033[1;36m  %s\033[0;38m ", str);
}

int main(int ac, char **av, char **env)
{
    s_t t;
       
    av = av + 1;
    if (ac == 1) {
        signal(SIGQUIT, c);
        signal(SIGINT, c);
        signal(SIGTERM, c);
        minishell(&t, env);
    }
    else
        my_putstr("Error");
}
