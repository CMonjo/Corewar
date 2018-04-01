/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

int swap_byte(int x)
{
	int y = 0;

	y += (x & 0x000000FF) << 24;
	y += (x & 0x0000FF00) << 8;
	y += (x & 0x00FF0000) >> 8;
	y += (x & 0xFF000000) >> 24;
	return (y);
}

int verif_champ(champion_t *champ, corewar_t *structure)
{
	if (structure->champ_live[champ->registre[1]] == -1)
		return (1);
	if (champ->cycle > 0)
		return (1);
	return (0);
}

void champ_turn(champion_t *champ, corewar_t *structure)
{
	int check = verif_champ(champ, structure);

	if (check == 0) {
		champ_action((int)structure->map[champ->pc], champ, structure);
	}
}

void end_cycle(corewar_t *structure)
{
	champion_t *save = structure->head;

	while (save != NULL) {
		save->cycle -= 1;
		save = save->next;
	}
	for (int i = 0; i != structure->number_champ; i++) {
		structure->champ_live[i] += -1;
		if (structure->champ_live[i] == 0) {
			structure->champ_live[i] = -1;
		}
	}
	structure->nbr_cycle += 1;
}

int main(int argc, char **argv)
{
	corewar_t *structure = malloc(sizeof(corewar_t));
	champion_t *save = NULL;
	int tmp = verif_ac(argc, argv);

	if (tmp > 4 || tmp < 2)
		return (84);
	init(structure, tmp + 1, argv);
	place_champ(structure);
	which_loop(save, structure, argv, argc);
	return (0);
}
