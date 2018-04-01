/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/


#include "my.h"

void put_ld(int to_put, char *code, champion_t *champ, corewar_t *structure)
{
	if (code[2] == '1') {
		structure->map[two_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3])] = to_put;
		champ->pc += 1;
	} else if (code[3] == '1') {
		champ->registre[structure->map[champ->pc + 2]] = to_put;
	}
}

void func_ld(champion_t *champ, corewar_t *structure)
{
	char *code = my_put_base(structure->map[champ->pc + 1], 2);
	int save = champ->pc;
	int away = first_code(code, champ, structure, save);
	int to_load = 0;

	away = away % IDX_MOD;
	to_load = four_bytes_to_int(structure->map[save + away],
	structure->map[save + away + 1],
	structure->map[save + away + 2],
	structure->map[save + away + 3]);
	put_ld(to_load, code, champ, structure);
	champ->cycle += 5;
	champ->pc += 3;
	champ->pc = champ->pc % MEM_SIZE;
}
