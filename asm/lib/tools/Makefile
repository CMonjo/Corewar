##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Library my
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I ../../include/

SRC	=	my_getnbr.c		\
		my_putstr.c		\
		clear_space.c		\
		clear_tab.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_strcat.c		\
		my_str_to_word_array.c	\
		myread.c		\
		my_strcmp.c		\
		my_revstr.c		\
		my_str_isnum.c		\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../libtools.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
