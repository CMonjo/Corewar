##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task 1
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W

SRC	=	my_strcat.c		\
		my_strlen.c		\
		my_putstr.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_str_array.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_revstr.c		\
		my_getnbr.c		\
		my_put_base.c		\
		my_strdup.c		\
		two_bytes_to_int.c	\
		four_bytes_to_int.c	\
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

re: fclean all
