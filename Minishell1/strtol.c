/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Brandon segers
*/
#include "struct.h"

int my_strprint(char str)
{
    int j = 0;

    if (str < 33 || str > 126)
        j = 1;
    if (j == 1)
        return (0);
    else
        return (1);
}

char *suppr_space(s_t *t)
{
    char *dest = t->str;

    for (t->c = 0; (my_strprint(t->str[t->c]) != 1 &&
                    t->str[t->c] != '\0'); t->c++);
    if (t->str[t->c] == '\0') {
        dest[0] = '\0';
        return (dest);
    }
    for (t->d = 0; t->str[t->c];) {
        if (t->str[t->c] == '\t')
            t->str[t->c] = ' ';
        if (!(t->str[t->c] == ' ' && t->str[t->c + 1] == ' ')) {
            dest[t->d] = t->str[t->c];
            t->d++;
        }
        t->c++;
    }
    dest[t->d] = '\0';
    return (dest);
}
