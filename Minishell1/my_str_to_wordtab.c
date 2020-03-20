/*
** EPITECH PROJECT, 2019
** brandon Segers
** File description:
** d
*/

#include <stdlib.h>
#include "struct.h"

int check_char(char c)
{
    if ((c == ' ' || c == ':' || c == '\0'))
        return (0);
    return (1);
}

int lenline(char const *str)
{
    int i = 0;
    int z = 0;

    while (str[i]) {
        if (check_char(str[i]) == 1 && check_char(str[i + 1]) == 0)
            z++;
        i++;
    }
    return (z);
}

char *cp(char *dest, char const *src, int i, int n)
{
    int j = 0;

    while (j < n) {
        dest[j] = src[i];
        j++;
        i++;
    }
    dest[j + 1] = '\0';
    return (dest);
}

char **my_str_to_wordtab(char const *str, int i)
{
    int j = 0;
    char **tab = malloc(sizeof(char **) * lenline(str) + 1);
    int z = 0;

    while (str[i]) {
        if (check_char(str[i]) == 1)
            z++;
        if (check_char(str[i]) == 1 && check_char(str[i + 1]) == 0) {
            tab[j] = malloc(sizeof(char *) * z + 1);
            tab[j] = cp(tab[j], str, i - z + 1, z);
            z = 0;
            j++;
        }
        i++;
    }
    tab[j] = malloc(1);
    tab[j] = '\0';
    return (tab);
}
