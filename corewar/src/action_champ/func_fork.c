/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void func_fork(champion_t *champ, corewar_t *structure)
{
	champion_t *new = malloc(sizeof(champion_t));

	new->carry = champ->carry;
	new->cycle = 800;
	new->name = my_strcpy(champ->name);
	new->code_champ = my_strcpy(champ->code_champ);
	new->registre = malloc(sizeof(int) * (REG_NUMBER + 1));
	for (int i = 0; i != REG_NUMBER; i++) {
		new->registre[i] = champ->registre[i];
	}
	new->pc = champ->pc + two_bytes_to_int(structure->map[champ->pc + 1],
	structure->map[champ->pc + 2]) % IDX_MOD;
	new->pc = new->pc % 6144;
	new->next = champ->next;
	champ->next = new;
	champ->pc += 3;
	champ->pc = champ->pc % MEM_SIZE;
	champ->cycle += 800;
}
