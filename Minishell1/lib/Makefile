##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## f
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_printf.c	\
		fctprintf2.c	\
		fctprintf1.c	\
		my_strcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
