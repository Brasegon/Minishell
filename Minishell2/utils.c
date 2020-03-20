/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Brandon Segers
*/
#include "struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    while (*str != 0) {
        my_putchar(*str);
        str++;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *my_strcat(char *str1, char *str2)
{
    char *str;
    int i;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    i = my_strlen(str1) + my_strlen(str2) + 1;
    if ((str = malloc(sizeof(char) * i)) == NULL)
        return (NULL);
    i = 0;
    while (*str1 != '\0')
        str[i++] = *str1++;
    while (*str2 != '\0')
        str[i++] = *str2++;
    str[i] = '\0';
    return (str);
}
