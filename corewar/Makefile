##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I include/

LIB	=	-L ./lib/my -lmy

SRC	=	src/main.c 		\
		src/init_champ.c 	\
		src/error_and_verif.c	\
		src/put_champ.c		\
		src/array_of_pointers.c \
		src/display_game.c \
		src/action_champ/func_add.c \
		src/action_champ/func_aff.c \
		src/action_champ/func_and.c \
		src/action_champ/func_fork.c \
		src/action_champ/func_ld.c \
		src/action_champ/func_ldi.c \
		src/action_champ/func_lfork.c \
		src/action_champ/func_live.c \
		src/action_champ/func_lld.c \
		src/action_champ/func_lldi.c \
		src/action_champ/func_or.c \
		src/action_champ/func_st.c \
		src/action_champ/func_sti.c \
		src/action_champ/func_sub.c \
		src/action_champ/func_xor.c \
		src/action_champ/func_zjmp.c \
		src/game_loop.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
