/*
** EPITECH PROJECT, 2017
** match
** File description:
** bonus
*/

#include "time.h"
#include "my.h"

void set_color(window_t *window, graph_t *graph, int i)
{
	sfColor color = (sfColor){100, 100, 100, 150};

	color = (graph->champ_pos[i] >= 1) ? sfRed : color;
	color.a = (graph->champ_pos[i] >= 1) ? 150 : color.a;
	color = (graph->champ_pos[i] >= 3) ? sfBlue : color;
	color.a = (graph->champ_pos[i] >= 3) ? 150 : color.a;
	color = (graph->champ_pos[i] >= 5) ? sfYellow : color;
	color.a = (graph->champ_pos[i] >= 5) ? 150 : color.a;
	color = (graph->champ_pos[i] >= 7) ? sfGreen : color;
	color.a = (graph->champ_pos[i] >= 7) ? 150 : color.a;
	if (window->seconds >= 0.1) {
		color = (graph->champ_pos[i] == 2) ? sfRed : color;
		color = (graph->champ_pos[i] == 4) ? sfBlue : color;
		color = (graph->champ_pos[i] == 6) ? sfYellow : color;
		color = (graph->champ_pos[i] == 8) ? sfGreen : color;
		sfClock_restart(window->clock);
	}
	sfText_setColor(window->t_text, color);
}

void color_pc(graph_t *graph)
{
	static int turn = 0;

	for (int i = 0; i < 6144; i++) {
		if (graph->vm[i] != graph->old_vm[i]) {
			graph->champ_pos[i] = (turn == 1)
			? 2 : graph->champ_pos[i];
			graph->champ_pos[i] = (turn == 2)
			? 4 : graph->champ_pos[i];
			graph->champ_pos[i] = (turn == 3)
			? 6 : graph->champ_pos[i];
			graph->champ_pos[i] = (turn == 4)
			? 8 : graph->champ_pos[i];
		}
	}
	turn ++;
	turn = (turn > graph->champs) ? 0 : turn;
}

void display_vm(window_t *window, graph_t *graph)
{
	sfVector2f pos;
	char *str;

	for (int j = 0; j < 64; j++) {
		for (int i = 0, s = 0, space = 0; i < 96; i++, s++) {
			str = my_change_base(graph->vm[j * 96 + i], 16);
			sfText_setString(window->t_text, str);
			set_color(window, graph, j * 96 + i);
			pos = (sfVector2f){20 + space * 0.93, 30 + j * 13};
			sfText_setPosition(window->t_text, pos);
			sfRenderWindow_drawText(window->window,
			window->t_text, NULL);
			s = (s == 0) ? -1 : s;
			space += (s == 0) ? 10 : 0;
			space += 12;
		}
	}
}

void display_corewar(window_t *window, graph_t *graph, text_t *text)
{
	char *str;

	str = i_to_a(graph->cycles);
	sfText_setString(text[4].text, str);
	free(str);
	str = i_to_a(graph->c_to_die);
	sfText_setString(text[2].text, str);
	free(str);
	for (int i = 0; i < 5 + 2 * graph->champs; i++)
		sfRenderWindow_drawText(window->window, text[i].text, NULL);
	graph->cycles ++;
}
