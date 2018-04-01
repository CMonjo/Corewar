/*
** EPITECH PROJECT, 2017
** Project
** File description:
** .h
*/

#ifndef corewar
	#define corewar
	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <time.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <SFML/Graphics.h>
	#include <SFML/Audio.h>
	#include "op.h"

	typedef struct champion_s {
		int cycle;
		int carry;
		int pc;
		char *name;
		int size_code;
		char *code_champ;
		int *registre;
		struct champion_s *next;
	} champion_t;

	typedef struct ptr_s {
		char balise;
		void(*callback)();
	} ptr_t;

	typedef struct corewar_s {
		unsigned char *map;
		int number_champ;
		int live;
		int nbr_cycle;
		int *champ_live;
		champion_t *head;
		ptr_t *aop;
		int win;
	} corewar_t;

	typedef struct window_s {
		sfRenderWindow *window;
		sfVideoMode mode;
		sfSprite *sprite;
		sfTexture *texture;
		sfEvent event;
		sfClock *clock;
		sfTime time;
		float seconds;
		sfText *t_text;
		sfFont *f_text;
	} window_t;

	typedef struct text_s {
		sfText *text;
		sfFont *font;
	} text_t;

	typedef struct graph_s {
		int *vm;
		int *old_vm;
		int champs;
		int *champ_pos;
		long cycles;
		long c_to_die;
	} graph_t;

	window_t *init_window(void);
	void event_gestion(window_t *window);
	void display_vm(window_t *window, graph_t *graph);
	void display_corewar(window_t *window, graph_t *graph, text_t *text);
	graph_t *init_graph(corewar_t *save);
	void color_champ(graph_t *graph);
	void color_pc(graph_t *graph);
	text_t *init_text(void);
	void refresh_vm(graph_t *graph, int reset, corewar_t *);
	char *i_to_a(int nbr);
	char *my_change_base(int nb, int b);
	char *my_reverse_str(char *str);
	void free_corewar(window_t *window, graph_t *graph, text_t *text);
	int champ_order(char **argv);
	void game_loop_graphic(champion_t *save, corewar_t *structure);
	int my_put_nbr(int);
	void my_putchar(char);
	char *my_strcpy(char *);
	int first_code(char *, champion_t *, corewar_t *, int);
	int second_code(char *, champion_t *, corewar_t *, int);
	void put_result(int, char *, champion_t *, corewar_t *);
	void game_loop_dump(champion_t *, corewar_t *, int);
	void which_loop(champion_t *, corewar_t *, char **, int);
	void game_loop_simple(champion_t *, corewar_t *);
	int verif_ac(int, char **);
	int two_bytes_to_int(int, int);
	int four_bytes_to_int(int, int, int, int);
	void verif_win(corewar_t *);
	void func_add(champion_t *, corewar_t *);
	void func_and(champion_t *, corewar_t *);
	void func_fork(champion_t *, corewar_t *);
	void func_ld(champion_t *, corewar_t *);
	void func_ldi(champion_t *, corewar_t *);
	void func_lfork(champion_t *, corewar_t *);
	void func_live(champion_t *, corewar_t *);
	void func_lld(champion_t *, corewar_t *);
	void func_lldi(champion_t *, corewar_t *);
	void func_or(champion_t *, corewar_t *);
	void func_st(champion_t *, corewar_t *);
	void func_sti(champion_t *, corewar_t *);
	void func_sub(champion_t *, corewar_t *);
	void func_xor(champion_t *, corewar_t *);
	void func_zjmp(champion_t *, corewar_t *);
	void func_aff(champion_t *, corewar_t *);
	void champ_action(int, champion_t *, corewar_t *);
	char *my_strdup();
	int my_strcmp(char const *, char const *);
	void place_champ(corewar_t *);
	int display_champ(corewar_t *);
	int my_getnbr(char *);
	int my_strlen(char *);
	int swap_byte(int );
	int my_putstr(char const *);
	void op_and_read_verif(int, int);
	void init_code_champ(corewar_t *, int);
	void init_name_champ(champion_t *, char *);
	int init(corewar_t *, int, char **);
	char *my_strcat(char *, char *);
	char *my_put_base(int, int);
	void display_map(corewar_t *);
	void end_cycle(corewar_t *);
	void champ_turn(champion_t *, corewar_t *);
#endif
