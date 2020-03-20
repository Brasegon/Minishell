/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Brandon Segers
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

int print_s(va_list args)
{
    my_putstr(va_arg(args, char *));
    return (0);
}

int print_c(va_list args)
{
    my_putchar(va_arg(args, int));
    return (0);
}

int print_di(va_list args)
{
    my_put_base(va_arg(args, int), "0123456789");
    return (0);
}

int print_x(va_list args)
{
    my_put_base(va_arg(args, unsigned int), "0123456789abcdef");
    return (0);
}

int print_high(va_list args)
{
    my_put_base(va_arg(args, unsigned int), "0123456789ABCDEF");
    return (0);
}
