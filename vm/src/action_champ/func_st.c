/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_st(champion_t *champ, corewar_t *structure)
{
	char *binary = my_put_base(structure->map[champ->pc + 1], 2);
	int i = structure->map[champ->pc + 2];
	int j = 0;

	my_strlen(binary) == 7 ? binary = my_strcat("0", binary) : 0;
	if (binary[2] == '1' && binary[3] == '1') {
		j = two_bytes_to_int(structure->map[champ->pc + 3],
		structure->map[champ->pc + 4]);
		structure->map[champ->pc + j % IDX_MOD] = champ->registre[i];
		champ->pc = (champ->pc + 4) % MEM_SIZE;
	} else {
		j = structure->map[champ->pc + 3];
		structure->map[champ->pc + j % IDX_MOD] = champ->registre[i];
		champ->pc = (champ->pc + 4) % MEM_SIZE;
	}
	champ->cycle += 5;
}
