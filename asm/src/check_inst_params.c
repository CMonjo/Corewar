/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** Main file
*/

#include "../include/main.h"

void register_error(asm_t *cor)
{
	error_display(cor);
	my_putstr(": Invalid register number.\n");
	exit(84);
}

void check_direct_prog_size(asm_t *cor, char *line, int instruction)
{
	if (line[1] == ':' ||
	my_strcmp(op_tab[instruction].name, "sti") == 0 ||
	my_strcmp(op_tab[instruction].name, "ldi") == 0 ||
	my_strcmp(op_tab[instruction].name, "lldi") == 0 ||
	my_strcmp(op_tab[instruction].name, "fork") == 0 ||
	my_strcmp(op_tab[instruction].name, "lfork") == 0 ||
	my_strcmp(op_tab[instruction].name, "zjmp") == 0)
		cor->size += 2;
	else
		cor->size += 4;
}

int parameters_register(asm_t *cor, char *line, int value)
{
	int reg = 0;

	if (line[0] == 'r') {
		if (my_str_isnum(line += 1) == 0)
			register_error(cor);
		reg = my_getnbr(line);
		line -= 1;
		if (reg > REG_NUMBER || reg <= 0)
			register_error(cor);
		value = 1;
		cor->size += 1;
	}
	return (value);
}

int parameters_verification(asm_t *cor, char *line, int instruction)
{
	int value = 0;

	value = parameters_register(cor, line, value);
	if (value == 0 && line[0] == '%') {
		if (line[1] != ':' && my_str_isnum(line) == 0) {
			error_display(cor);
			my_putstr(": The argument given");
			my_putstr(" to the instruction is invalid.\n");
			exit(84);
		}
		value = 2;
		check_direct_prog_size(cor, line, instruction);
	}
	else if (value == 0 && my_str_isnum(line) == 1) {
		value = 4;
		cor->size += 2;
	}
	return (value);
}

void check_parameters(asm_t *cor, char **line, int instruction, int nb_params)
{
	if (my_strcmp(op_tab[instruction].name, "live") == 0 ||
	my_strcmp(op_tab[instruction].name, "zjmp") == 0 ||
	my_strcmp(op_tab[instruction].name, "fork") == 0||
	my_strcmp(op_tab[instruction].name, "lfork") == 0)
		cor->size += 1;
	else
		cor->size += 2;
	for (int i = 0, value = 0; i != nb_params; i++, value = 0) {
		value = parameters_verification(cor, line[i], instruction);
		if (value > op_tab[instruction].type[i] || value <= 0) {
			error_display(cor);
			my_putstr(": The argument given");
			my_putstr(" to the instruction is invalid.\n");
			exit(84);
		}
	}
}
