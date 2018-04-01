/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_or(champion_t *champ, corewar_t *structure)
{
	char *code = my_put_base(structure->map[champ->pc + 1], 2);
	int save = champ->pc;
	int first;
	int second;
	int to_put;

	if (my_strlen(code) == 7) {
		code = my_strcat("0", code);
	}
	first = first_code(code, champ, structure, save);
	second = second_code(code, champ, structure, save);
	to_put = first | second;
	put_result(to_put, code, champ, structure);
	champ->pc += 2;
	champ->pc = champ->pc % MEM_SIZE;
	champ->carry = to_put;
	champ->cycle += 6;
}
