/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** tile
*/

#include "my.h"
#include "time.h"

void set_window(window_t *window)
{
	window->window = sfRenderWindow_create(window->mode,"Matches",
	sfClose | sfResize, NULL);
	sfRenderWindow_setFramerateLimit(window->window, 60);
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
	sfText_setFont(window->t_text, window->f_text);
	sfText_setCharacterSize(window->t_text, 10);
}

window_t *init_window(void)
{
	window_t *window = malloc(sizeof(window_t));

	window->mode = (sfVideoMode){1600, 900, 32};
	window->texture = sfTexture_createFromFile("./img/bg.jpg", NULL);
	window->sprite = sfSprite_create();
	window->clock = sfClock_create();
	window->time = sfClock_getElapsedTime(window->clock);
	window->seconds = 0;
	window->t_text = sfText_create();
	window->f_text = sfFont_createFromFile("./img/police.ttf");
	set_window(window);
	return (window);
}

graph_t *init_graph(corewar_t *structure)
{
	graph_t *graph = malloc(sizeof(graph_t));

	graph->old_vm = malloc(sizeof(int) * 6144);
	graph->vm = malloc(sizeof(int) * 6144);
	graph->champ_pos = malloc(sizeof(int) * 6144);
	graph->cycles = 0;
	refresh_vm(graph, 0, structure);
	return (graph);
}

text_t new_text(char *txt, sfVector2f pos, int size, sfColor color)
{
	text_t text;

	text.text = sfText_create();
	text.font = sfFont_createFromFile("./img/cookies.ttf");
	sfText_setString(text.text, txt);
	sfText_setPosition(text.text, pos);
	sfText_setColor(text.text, sfBlack);
	sfText_setFont(text.text, text.font);
	sfText_setCharacterSize(text.text, size);
	sfText_setColor(text.text, color);
	return (text);
}

text_t *init_text(void)
{
	text_t *text = malloc(sizeof(text_t) * 13);

	text[0] = new_text("Corewar", (sfVector2f){1200, 25}, 70, sfBlack);
	text[1] = new_text("Cycles to die :",
	(sfVector2f){1120, 650}, 30, sfBlack);
	text[2] = new_text("0", (sfVector2f){1400, 655}, 30, sfBlack);
	text[3] = new_text("Cycles :", (sfVector2f){1120, 725}, 30, sfBlack);
	text[4] = new_text("0", (sfVector2f){1400, 725}, 30, sfBlack);
	text[5] = new_text("Name 1", (sfVector2f){1120, 175}, 40, sfRed);
	text[6] = new_text("Alive", (sfVector2f){1350, 175}, 40, sfBlack);
	text[7] = new_text("Name 2", (sfVector2f){1120, 250}, 40, sfBlue);
	text[8] = new_text("Alive", (sfVector2f){1350, 250}, 40, sfBlack);
	text[9] = new_text("Name 3", (sfVector2f){1120, 325}, 40, sfYellow);
	text[10] = new_text("Alive", (sfVector2f){1350, 325}, 40, sfBlack);
	text[11] = new_text("Name 4", (sfVector2f){1120, 400}, 40, sfGreen);
	text[12] = new_text("Alive", (sfVector2f){1350, 400}, 40, sfBlack);
	return (text);
}
