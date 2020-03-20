/*
** EPITECH PROJECT, 2019
** brandon
** File description:
** epitech
*/

#include <stdlib.h>
#include "struct.h"

int check_chara(char c, char a)
{
    if ((c == a) || (c == 0))
        return (0);
    return (1);
}

char    **my_str_to_wordarray(char const *str, char c, int i)
{
    int j = 0;
    char **tab = malloc(sizeof(char *) * lenline(str) + 1);
    int z = 0;

    while (str[i]) {
        if (check_chara(str[i], c) == 1)
            z++;
        if (check_chara(str[i], c) == 1 && check_chara(str[i + 1], c) == 0) {
            tab[j] = malloc(sizeof(char) * z + 1);
            tab[j] = cp(tab[j], str, i - z + 1, z);
            z = 0;
            j++;
        }
        tab[j] = '\0';
        i++;
    }
    return (tab);
}

