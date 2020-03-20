/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Brandon SEGERS
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

void	my_put_base(int nb, char *base)
{
    int	mod;

    base = base + 1;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_base(nb, "123456789");
            my_putchar(48 + mod);
        }
        else
            my_putchar(48 + nb % 10);
    }
}

int print_low(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 7) {
            my_putstr("\00");
            my_put_base(str[i] , "01234567");
        }
        else if (str[i] > 7 && str[i] <= 32){
            my_putstr("\0");
            my_put_base(str[i], "01234567");
        }
        my_putchar(str[i++]);
    }
    return (0);
}

int check(char c)
{
    char *f = "scdixXobup%S";
    int i = 0;

    while (f[i] != '\0') {
        if (f[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

void list(int (**flag)(va_list args))
{
    flag[0] = &print_s;
    flag[1] = &print_c;
    flag[2] = &print_di;
    flag[3] = &print_di;
    flag[4] = &print_x;
    flag[5] = &print_high;
    flag[6] = &print_o;
    flag[7] = &print_b;
    flag[8] = &print_u;
    flag[9] = &print_p;
    flag[11] = &print_low;
}

void my_printf(char *str, ...)
{
    va_list args;
    int  (*flag[12])(va_list args);
    int i = 0;

    va_start(args, str);
    list(flag);
    while (str[i] != '\0') {
        if (str[i] == '%' && check(str[i + 1]) != -1){
            flag[check(str[i + 1])](args);
            i++;
        }
        else
            my_putchar(str[i]);
        i++;
    }
    va_end(args);
}
