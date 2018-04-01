/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

ptr_t base[17] = {
	{4, &func_add},
	{16, &func_aff},
	{6, &func_and},
	{12, &func_fork},
	{2, &func_ld},
	{10, &func_ldi},
	{15, &func_lfork},
	{1, &func_live},
	{13, &func_lld},
	{14, &func_lldi},
	{7, &func_or},
	{3, &func_st},
	{11, &func_sti},
	{5, &func_sub},
	{8, &func_xor},
	{9, &func_zjmp},
	{0, NULL}
};

void champ_action(int i, champion_t *champ, corewar_t *structure)
{
	for (int j = 0; j < 16; j++) {
		if (i == base[j].balise)
			base[j].callback(champ, structure);
	}
}
