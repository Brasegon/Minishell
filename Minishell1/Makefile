NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= ./exec.c \
	  ./get_next_line.c \
	  ./lib/fctprintf1.c \
	  ./lib/fctprintf2.c \
	  ./lib/my_printf.c \
	  ./lib/my_strcpy.c \
	  ./main.c \
	  ./my_str_to_wordtab.c \
	  ./my_strcmp.c \
	  ./strtol.c \
	  ./utils.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
