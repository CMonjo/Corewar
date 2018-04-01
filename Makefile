##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile Corewar - ASM and VM
##

all:
	make -C ./asm/
	make -C ./vm/

clean:
	make clean -C ./asm/
	make clean -C ./vm/

fclean:
	make fclean -C ./asm/
	make fclean -C ./vm/

re : fclean all
