/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void display_map(corewar_t *structure)
{
	char *disp;
	int var = 0;

	for (int i = 0; i != 6144; i++) {
		if (i % 32 == 0) {
			my_putstr("\n");
			var = i / 64;
			my_put_nbr(var);
			my_putstr(":	");
		}
		disp = my_put_base(structure->map[i], 16);
		if (my_strlen(disp) == 2) {
			my_putstr(disp);
		} else {
			my_putstr("0");
			my_putstr(disp);
		}
		my_putstr(" ");
	}
	my_putstr("\n");
}
