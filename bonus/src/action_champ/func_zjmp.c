/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_zjmp(champion_t *champ, corewar_t *structure)
{
	int i = two_bytes_to_int(structure->map[champ->pc + 1],
	structure->map[champ->pc + 2]);

	if (champ->carry >= 1)
		champ->pc = (champ->pc + i) % IDX_MOD;
	champ->cycle += 20;
	champ->pc += 3;
	champ->pc = champ->pc % MEM_SIZE;
}
