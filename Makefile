##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile Corewar - ASM and VM
##

all:
	make -C ./asm/
	make -C ./corewar/

clean:
	make clean -C ./asm/
	make clean -C ./corewar/

fclean:
	make fclean -C ./asm/
	make fclean -C ./corewar/

re : fclean all
