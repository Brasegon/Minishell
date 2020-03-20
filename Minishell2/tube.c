/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Brandon Segers
*/
#include "struct.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

void check_dir(s_t *t)
{
    struct stat sb;

    stat(t->arg[0], &sb);
    if (sb.st_mode == 16877) {
        my_printf("%s: Permission denied.\n", t->arg[0]);
        exit(0);
    }
}

void check_cat(s_t *t)
{
    int fd = open(t->arg[1], O_RDWR);
    int a = 0;
    char c;

    if (fd == -1)
        return;
    while (read(fd, &c, 1) != 0) {
        if (a >= 6000)
            exit(0);
        a++;
    }
}

void pipe_gestion(s_t *t)
{
    check_cat(t);
    if (t->red == 1) {
        dup2(t->tube[1], STDOUT_FILENO);
        dup2(t->tube[1], 2);
        close(t->tube[1]);
    }
    if (t->tas == 0) {
        my_printf("test\n");
        dup2(t->tube[1], STDOUT_FILENO);
        close(t->tube[1]);
    }
    else if (t->tas == 1 && t->red != 1 && t->ta != 1) {
        dup2(t->tube[0], 0);
        close(t->tube[1]);
    }
}

void cd_error(DIR* rep, char *str)
{
    if (access(str, F_OK) == -1)
        my_printf("%s: No such file or directory.\n", str);
    else if (access(str, R_OK) == -1)
        my_printf("%s: Permission denied.\n", str);
    else
        my_printf("%s: Not a directory.\n", str);
}
