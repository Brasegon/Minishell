/*
** EPITECH PROJECT, 2017
** my_print
** File description:
** Brandon Segers
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void my_put_base(int nb, char *b);
int check(char c);
void my_printf(char *str, ...);
int print_s(va_list args);
int print_c(va_list args);
int print_di(va_list args);
int print_x(va_list args);
int print_high(va_list args);
int print_o(va_list args);
int print_b(va_list args);
int print_u(va_list args);
int print_p(va_list args);
#endif /*MY_H_*/
