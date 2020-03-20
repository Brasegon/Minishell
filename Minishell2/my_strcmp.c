/*
** EPITECH PROJECT, 2019
** cmp
** File description:
** d
*/
#include "struct.h"

char    *my_strcpyi(char *dest, char const *src, int i)
{
    int j = 0;

    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char **env_null(s_t *t)
{
    char **newenv;
    char *str;
    int i = 0;

    str = malloc(sizeof(char *) * 2048);
    str = my_strcat(str, "/:.");
    newenv = my_str_to_wordtab(str, 0);
    while (newenv[i]) {
        newenv[i] = my_strcat(newenv[i], "/");
        i++;
    }
    return (newenv);
}

char **test(s_t *t, char **env, int i)
{
    char **newenv = NULL;

    t->test = malloc(sizeof(char *) * 2048);
    t->test = my_strcpyi(t->test, env[i], 5);
    t->test = my_strcat(t->test, ":/");
    newenv = my_str_to_wordtab(t->test, 0);
    return (newenv);
}

char *my_strdup(char *str, char *dest, int i)
{
    int j = 0;

    dest = malloc(sizeof(char) * 2048);
    while (str[i]) {
        dest[j] = str[i];
        i++;
        j++;
    }
    dest[j] = 0;
    return (dest);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] == s2[i])
        return (0);
    else if (s1[i] < s2[i])
        return (-1);
    else
        return (1);
}
