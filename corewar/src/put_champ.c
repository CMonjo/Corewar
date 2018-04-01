/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void put_champ(corewar_t *structure, champion_t *champ, int start_pos)
{
	for (int i = 0; i != champ->size_code; i++) {
		structure->map[start_pos] = champ->code_champ[i];
		start_pos++;
	}
}

void place_two(corewar_t *structure)
{
	champion_t *save = structure->head;

	put_champ(structure, save, 0);
	save->pc = 0;
	save = save->next;
	put_champ(structure, save, 3072);
	save->pc = 3072;
}

void place_tree(corewar_t *structure)
{
	champion_t *save = structure->head;

	put_champ(structure, save, 0);
	save->pc = 0;
	save = save->next;
	put_champ(structure, save, 2048);
	save->pc = 2048;
	save = save->next;
	put_champ(structure, save, 4096);
	save->pc = 4096;
}

void place_four(corewar_t *structure)
{
	champion_t *save = structure->head;

	put_champ(structure, save, 0);
	save->pc = 0;
	save = save->next;
	put_champ(structure, save, 1536);
	save->pc = 1536;
	save = save->next;
	put_champ(structure, save, 3072);
	save->pc = 3072;
	save = save->next;
	put_champ(structure, save, 4608);
	save->pc = 4608;
}

void place_champ(corewar_t *structure)
{
	if (structure->number_champ == 2) {
		place_two(structure);
	} else if (structure->number_champ == 3) {
		place_tree(structure);
	} else if (structure->number_champ == 4) {
		place_four(structure);
	}

}
