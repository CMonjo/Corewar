/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

int champ_order(char **argv)
{
	int f = 0;

	for (int e = 0;  e < 10 && argv[e] != NULL; e++) {
		for (f = 0; argv[e][f] != '\0'; f++);
		for (;argv[e][f] != '.' && f > 0; f--);
		if (argv[e][f] == '.' && argv[e][f + 1] == 'c') {
			return (e);
		}
	}
	return (0);
}

void which_loop(champion_t *champ, corewar_t *structure, char **argv, int argc)
{
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-' && argv[i][1] == 'd' && argv[i][2] == 'u'
		&& argv[i][3] == 'm' && argv[i][4] == 'p') {
			game_loop_dump(champ, structure,
			my_getnbr(argv[i + 1]));
			i = argc;
			return;
		}
		if (my_strcmp(argv[i], "-g") == 0) {
			game_loop_graphic(champ, structure);
			return;
		}
	}
	game_loop_simple(champ, structure);
}

void game_loop_simple(champion_t *save, corewar_t *structure)
{
	int i = 0;

	while (structure->win != 0) {
		save = structure->head;
		while (save != NULL) {
			if (save->registre[1] == 1) {
		}
			champ_turn(save, structure);
			save = save->next;
		}
		end_cycle(structure);
		verif_win(structure);
		i++;
	}
}

void game_loop_graphic(champion_t *save, corewar_t *structure)
{
	window_t *window = init_window();
	graph_t *graph = init_graph(structure);
	text_t *text = init_text();

	while (sfRenderWindow_isOpen(window->window) && structure->win != 0) {
		save = structure->head;
		while (save != NULL) {
			event_gestion(window);
			champ_turn(save, structure);
			color_pc(graph);
			display_vm(window, graph);
			display_corewar(window, graph, text);
			refresh_vm(graph, 1, structure);
			sfRenderWindow_display(window->window);
			save = save->next;
		}
		end_cycle(structure);
		verif_win(structure);
	}
	free_corewar(window, graph, text);
}

void game_loop_dump(champion_t *save, corewar_t *structure, int cycle)
{
	while (structure->win != 0 && structure->nbr_cycle != cycle) {
		save = structure->head;
		while (save != NULL) {
			champ_turn(save, structure);
			save = save->next;
		}
		end_cycle(structure);
		verif_win(structure);
	}
	display_map(structure);
}
