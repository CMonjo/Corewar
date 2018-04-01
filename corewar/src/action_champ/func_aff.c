/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_aff(champion_t *champ, corewar_t *structure)
{
	int i = structure->map[champ->pc + 2];

	my_putchar(champ->registre[i]);
	champ->cycle += 2;
	champ->pc += 3;
	champ->pc = champ->pc % MEM_SIZE;
}
