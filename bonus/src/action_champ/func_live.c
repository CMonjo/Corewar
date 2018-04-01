/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_live(champion_t *champ, corewar_t *structure)
{
	int number = four_bytes_to_int(structure->map[champ->pc + 1],
	structure->map[champ->pc + 2], structure->map[champ->pc + 3],
	structure->map[champ->pc + 4]);

	champ->pc += 5;
	champ->pc = champ->pc % MEM_SIZE;
	if (number <= 0 || number > structure->number_champ) {
	} else {
		structure->champ_live[number] = structure->live;
	}
	number = 0;
	champ->cycle += 10;
}
