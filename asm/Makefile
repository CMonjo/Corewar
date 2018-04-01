##
## EPITECH PROJECT, 2017
## Project Corewar ASM
## File description:
## Build asm binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/

LIB	=	-L lib/ -ltools

SRC	=	src/main.c			\
		src/file_management.c		\
		src/check_file.c		\
		src/header_fill.c		\
		src/op.c			\
		src/parsing_tools.c		\
		src/check_inst_params.c		\
		src/error_handling.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/tools/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/tools/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/tools/

re: fclean all
