/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** Error handling file
*/

#include "../include/main.h"

void error_display(asm_t *cor)
{
	my_putstr("asm, ");
	my_putstr(cor->filepath);
	my_putstr(", line ");
	my_put_nbr(cor->line);
}

void error_header(asm_t *cor, int name, int comment)
{
	if (name >= 2) {
		error_display(cor);
		my_putstr(": The name can only be defined once.\n");
		exit(84);
	}
	if (comment >= 2) {
		error_display(cor);
		my_putstr(": The comment can only be defined once.\n");
		exit(84);
	}
}

void error_instructions(asm_t *cor, int number)
{
	error_display(cor);
	if (number == -1) {
		my_putstr(": The argument");
		my_putstr(" given to the instruction is invalid.\n");
	} else
		my_putstr(": Too many arguments given to the instruction.\n");
	exit(84);
}

void error_cote(asm_t *cor, int cote)
{
	if (cote != 2) {
		error_display(cor);
		my_putstr(": Syntax error.\n");
		exit(84);
	}
}

void error_specified_header(asm_t *cor, int value)
{
	error_display(cor);
	if (value == 1)
		my_putstr(": No name specified.\n");
	if (value == 2)
		my_putstr(": No comment specified.\n");
	exit(84);
}
