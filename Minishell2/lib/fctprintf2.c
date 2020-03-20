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

int print_o(va_list args)
{
    my_put_base(va_arg(args, unsigned int), "01234567");
    return (0);
}

int print_b(va_list args)
{
    my_put_base(va_arg(args, unsigned  int), "01");
    return (0);
}

int print_u(va_list args)
{
    my_put_base(va_arg(args, unsigned int), "0123456789");
    return (0);
}

int print_p(va_list args)
{
    my_putstr("0x");
    my_put_base(va_arg(args, unsigned int), "0123456789abcdef");
    return (0);
}

int print_pourcent(void)
{
    my_putchar('%');
    return (0);
}
