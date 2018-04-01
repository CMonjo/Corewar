/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void init_name_champ(champion_t *champ, char *path)
{
	struct header_s header;
	int fd;
	int rd;

	fd = open(path, O_RDONLY);
	op_and_read_verif(1, fd);
	rd = read(fd, &header, sizeof(header));
	op_and_read_verif(rd, fd);

	champ->size_code = swap_byte(header.prog_size);
	champ->code_champ = malloc(sizeof(char) * (champ->size_code + 1));
	rd = read(fd, champ->code_champ, champ->size_code);
	champ->name = my_strdup(header.prog_name);
	close(fd);
}

void init_champion_chain(corewar_t *structure, char *path, int flag)
{
	structure->head = malloc(sizeof(champion_t));
	structure->head->carry = 0;
	structure->head->cycle = 0;
	init_name_champ(structure->head, path);
	structure->head->next = NULL;
	structure->head->registre = malloc(sizeof(int) * (REG_NUMBER + 1));
	for (int i = 0; i != REG_NUMBER + 1; i++) {
		structure->head->registre[i] = 0;
	}
	structure->head->registre[1] = flag;
}

void add_champion_chain(corewar_t *structure, char *path, int flag)
{
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *save = structure->head;

	new->carry = 0;
	new->cycle = 0;
	init_name_champ(new, path);
	new->next = NULL;
	new->registre = malloc(sizeof(int) * (REG_NUMBER + 1));
	for (int i = 0; i != REG_NUMBER + 1; i++) {
		new->registre[i] = 0;
	}
	new->registre[1] = flag;
	while (save != NULL && save->next != NULL) {
		save = save->next;
	}
	save->next = new;
}

void init_champ_and_verif_path(char **argv, corewar_t *structure)
{
	int f = 0;

	for (int e = 0; e < 10 && argv[e] != NULL; e++) {
		for (f = 0; argv[e][f] != '\0'; f++);
		for (;argv[e][f] != '.' && f > 0; f--);
		if (argv[e][f] == '.' && argv[e][f + 1] == 'c') {
			init_champion_chain(structure, argv[e], 1);
		}
	}
}

int init(corewar_t *structure, int argc, char **argv)
{
	int i = 0;

	init_champ_and_verif_path(argv, structure);
	structure->champ_live = malloc(sizeof(int) * (argc + 1));
	structure->champ_live[0] = CYCLE_TO_DIE;
	structure->number_champ = argc - 1;
	for (int j = champ_order(argv); i < structure->number_champ; j++) {
		structure->champ_live[j] = CYCLE_TO_DIE;
		add_champion_chain(structure, argv[j], j);
		i++;
	}
	structure->live = CYCLE_TO_DIE;
	structure->win = 1;
	structure->nbr_cycle = 0;
	structure->map = malloc(sizeof(unsigned char) * (MEM_SIZE + 1));
	for (i = 0; i != MEM_SIZE + 1; i++)
		structure->map[i] = '\0';
	return (0);
}
