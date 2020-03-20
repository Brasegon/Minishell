/*
** EPITECH PROJECT, 2019
** exec2
** File description:
** brandon
*/
#include "struct.h"
#include <fcntl.h>
#include <string.h>

char *my_strtol(char *str)
{
    int i = 0;
    int j = 0;
    char *str2;

    str2 = malloc(my_strlen(str) + 1);
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str2[j] = str[i];
            ++j;
        }
        ++i;
    }
    str2[j] = '\0';
    return (str2);
}

void next_execv2(char **env, s_t *t, int j)
{
    if (t->se[j + 1] == 0 && t->red == 1)
        return;
    t->te = my_str_to_wordarray(t->se[j], '|', 0);
    for (t->ta = 0; t->te[t->ta]; t->ta++);
    for (int z = 0;t->te[z]; z++) {
        if (t->te[z + 1] == NULL)
            t->tas = 1;
        command(env, t, t->te[z]);
    }
}

void redir(s_t *t)
{
    int wait_ret = -1;

    wait_ret = waitpid(t->pid, &t->status, 0);
    if (WTERMSIG(t->status) == SIGFPE)
        my_printf("Floating exception\n");
    else if (WTERMSIG(t->status) != 0 && WTERMSIG(t->status) != SIGINT) {
        my_putstr(strsignal(WTERMSIG(t->status)));
        my_putstr("\n");
    }
    kill(wait_ret, SIGKILL);
    close(t->tube[1]);
}

void write_into(s_t *t)
{
    char c;
    int fd = 0;
    int a = 0;

    if (t->red == 1) {
        t->se[1] = my_strtol(t->se[1]);
        fd = open(t->se[1], O_CREAT | O_RDWR | a, 0644);
        while (read(t->tube[0], &c, 1) != 0)
            write(fd, &c, 1);
    }
}

void execv2(char **env, s_t *t, char *str)
{
    int j = 0;

    t->red = 0;
    t->tas = 0;
    t->se = my_str_to_wordarray(str, '>', 0);
    for (int i = 0; str[i]; i++)
        if (str[i] == '>' && str[i + 1] != NULL)
            t->red = 1;
    while (t->se[j]) {
        next_execv2(env, t, j);
        j++;
    }
    write_into(t);
}
