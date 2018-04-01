/*
** EPITECH PROJECT, 2017
** match
** File description:
** bonus
*/

#include "my.h"
#include "time.h"

void free_corewar(window_t *window, graph_t *graph, text_t *text)
{
	sfSprite_destroy(window->sprite);
	sfTexture_destroy(window->texture);
	sfClock_destroy(window->clock);
	sfText_destroy(window->t_text);
	sfFont_destroy(window->f_text);
	free(window);
	free(graph->vm);
	free(graph->old_vm);
	free(graph->champ_pos);
	free(graph);
	for (int i = 0; i < 13; i++) {
		sfText_destroy(text[i].text);
		sfFont_destroy(text[i].font);
	}
	free(text);
}

void refresh_vm_color(graph_t *graph)
{
	for (int i = 0; i < 3072; i++) {
		graph->champ_pos[i] = (graph->vm[i] == 0)
		? 0 : graph->champ_pos[i];
		graph->champ_pos[i] = (graph->vm[i] != 0)
		? 1 : graph->champ_pos[i];

	} for (int i = 3072; i < 6144; i++) {
		graph->champ_pos[i] = (graph->vm[i] == 0)
		? 0 : graph->champ_pos[i];
		graph->champ_pos[i] = (graph->vm[i] != 0)
		? 3 : graph->champ_pos[i];
	}
}

void refresh_vm(graph_t *graph, int reset, corewar_t *structure)
{
	graph->champs = structure->number_champ;
	graph->c_to_die = structure->live;
	if (reset == 0) {
		for (int i = 0; i < 6144; i++) {
			graph->vm[i] = structure->map[i];
			graph->old_vm[i] = structure->map[i];
		}
	} if (reset == 1) {
		for (int i = 0; i < 6144; i++) {
			graph->old_vm[i] = graph->vm[i];
			graph->vm[i] = structure->map[i];
		}
	}
	refresh_vm_color(graph);
}
