/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void my_else(int k, char *binary, champion_t *champ, corewar_t *structure)
{
	int j = 0;
	int i = structure->map[champ->pc + 2];
	int save = champ->pc;

	if (k == 0 && j == 0) {
		j = two_bytes_to_int(structure->map[champ->pc + 3],
		structure->map[champ->pc + 4]);
		if (binary[4] == '0' && binary[5] == '1') {
 			k = structure->map[champ->pc + 5];
			champ->pc += 6;
		} else {
			k = two_bytes_to_int(structure->map[champ->pc + 5],
			structure->map[champ->pc + 6]);
			champ->pc += 7;
		}
		structure->map[save + (j + k) % IDX_MOD] =
		champ->registre[i];
	}
}

void func_sti(champion_t *champ, corewar_t *structure)
{
	char *binary = my_put_base(structure->map[champ->pc + 1], 2);
	int j = 0;
	int k = 0;
	int i = structure->map[champ->pc + 2];
	int save = champ->pc;

	my_strlen(binary) == 7 ? binary = my_strcat("0", binary) : 0;
	if (binary[2] == '0' && binary[3] == '1') {
		j = structure->map[champ->pc + 3];
		if (binary[4] == '0' && binary[5] == '1')
			k = structure->map[champ->pc + 4];
		else
			k = two_bytes_to_int(structure->map[champ->pc + 4],
			structure->map[champ->pc + 5]);
		champ->pc += binary[4] == '0' && binary[5] == '1' ? 5 : 6;
		structure->map[save + (j + k) % IDX_MOD] =
		champ->registre[i];
	}
	my_else(k, binary, champ, structure);
	champ->pc = champ->pc % MEM_SIZE;
	champ->cycle += 25;
}
