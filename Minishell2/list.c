/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** brandon sgeres
*/
#include "struct.h"

l_t *add_params(l_t *list)
{
    l_t *new_list = malloc(sizeof(l_t));

    pipe(new_list->tube);
    pipe(new_list->tube1);
    new_list->next = list;
    return (new_list);
}
