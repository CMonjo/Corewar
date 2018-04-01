/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_sub(champion_t *champ, corewar_t *structure)
{
	int n1 = champ->registre[structure->map[champ->pc + 2]];
	int n2 = champ->registre[structure->map[champ->pc + 3]];

	champ->carry = n1 + n2;
	champ->registre[structure->map[champ->pc + 4]] = n2 - n1;
	champ->cycle += 10;
	champ->pc += 4;
	champ->pc = champ->pc % MEM_SIZE;
}
