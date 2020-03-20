/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** brandon segers
*/

#include "get_next_line.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int line(char **result, char **buffer)
{
    int i = 0;

    if ((*result = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
        return (-1);
    while (**buffer != 0 && (i == 0 || *(*buffer - 1) != '\n')) {
        (*result)[i] = **buffer;
        (*buffer) += 1;
        i += 1;
    }
    return (i);
}

static char *addline(char *str1, char *str2, t_t t)
{
    int len1;
    int len2;

    for (len1 = 0, len2 = 0; str1[len1] || str2[len2]; ++len1, ++len2);
    t.str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (t.str == NULL)
        return (NULL);
    for (int i = -1, j = -1; str1[i]; ++i, ++j)
        t.str[j] = str1[i];
    for (int i = -1, j = -1; str2[i]; ++i, ++j)
        t.str[j] = str2[i];
    return (t.str);
}

char            *get_next_line(const int fd)
{
    static char *buffer;
    t_t t;

    if (fd == -1)
        return (NULL);
    if (buffer == NULL || buffer[0] == 0) {
        buffer = malloc(sizeof(char) * (READ_SIZE + 1));
        t.i = read(fd, buffer, READ_SIZE);
        if (buffer[0] == 0)
            return (NULL);
    }
    t.i = line(&t.str, &buffer);
    t.str[t.i] = 0;
    if ((t.str[t.i - 1] == '\n' || t.str[t.i - 1] == '\0'))
        t.str[t.i - 1] = 0;
    else
        addline(t.str, get_next_line(fd), t);
    return (t.str);
}
