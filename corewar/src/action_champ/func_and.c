/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

int first_code(char *code, champion_t *champ, corewar_t *structure, int save)
{
	int first = 0;

	if (code[0] == '0' && code[1] == '1') {
		first = champ->registre[structure->map[champ->pc + 2]];
		champ->pc += 1;
	} else if (code[0] == '1' && code[1] == '0') {
		first = four_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3], structure->map[champ->pc + 4],
		structure->map[champ->pc + 5]);
		champ->pc += 4;
	} else if (code[0] == '1' && code[1] == '1') {
		first = two_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3]);
		champ->pc += 2;
		first += save;
		first = structure->map[first % MEM_SIZE];
	}
	champ->pc = champ->pc % MEM_SIZE;
	return (first);
}

int second_code(char *code, champion_t *champ, corewar_t *structure, int save)
{
	int second = 0;

	if (code[2] == '0' && code[3] == '1') {
		second = champ->registre[structure->map[champ->pc + 2]];
		champ->pc += 1;
	} else if (code[2] == '1' && code[3] == '0') {
		second = four_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3], structure->map[champ->pc + 4],
		structure->map[champ->pc + 5]);
		champ->pc += 4;
	} else if (code[2] == '1' && code[3] == '1') {
		second = two_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3]);
		champ->pc += 2;
		second += save;
		second = structure->map[second % MEM_SIZE];
	}
	champ->pc = champ->pc % MEM_SIZE;
	return (second);
}

void put_result(int put, char *code, champion_t *champ, corewar_t *structure)
{
	if (code[4] == '1') {
		structure->map[two_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3])] = put;
		champ->pc += 1;
	} else if (code[5] == '1')
		champ->registre[structure->map[champ->pc + 2]] = put;
}

void func_and(champion_t *champ, corewar_t *structure)
{
	char *code = my_put_base(structure->map[champ->pc + 1], 2);
	int save = champ->pc;
	int first;
	int second;
	int to_put;

	if (my_strlen(code) == 7)
		code = my_strcat("0", code);
	first = first_code(code, champ, structure, save);
	second = second_code(code, champ, structure, save);
	to_put = first & second;
	put_result(to_put, code, champ, structure);
	champ->carry = to_put;
	champ->pc += 3;
	champ->pc = champ->pc % MEM_SIZE;
	champ->cycle += 6;
}
