/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

int disp_h(void)
{
	my_putstr("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] ");
	my_putstr("[-a load_address] prog_name] ...\n");
	my_putstr("DESCRIPTION\n\t-dump nbr_cycle dumps the memory after the");
	my_putstr(" nbr_cycle execution ");
	my_putstr(" (if the round is't\n\t\talready over) ");
	my_putstr("with the following format: 32 bytes/line in\n");
	my_putstr("\t\thexadecimal (AOBCDEFE1DD3...)\n");
	my_putstr("\t-n prog_number sets the next ");
	my_putstr("program's number. By default");
	my_putstr(", the first free number\n\t\tin the parameter order\n");
	my_putstr("\t-a load_address sets the next ");
	my_putstr("program's loading address.");
	my_putstr(" When no address is\n\t\tspecified, ");
	my_putstr("optimize the addresses so ");
	my_putstr("that the processes are as ");
	my_putstr("far\n\t\taway from each other as ");
	my_putstr("possible. The addresses are MEM_SIZE modulo\n");
	return (84);
}

int my_if(char **av, int j, int i, int c)
{
	if (av[i][j + 1] == 'c' && av[i][j + 2] == 'o' &&
	av[i][j + 3] == 'r')
		c++;
	return (c);
}

int verif_ac(int ac, char **av)
{
	int c = 0;
	int j = 0;

	for (int i = 0; i < ac; i++) {
		if (av[i][0] == '-' && av[i][1] == 'h')
			return (disp_h());
		if ((av[i][0] == '-' && av[i][1] == 'd' &&
		av[i][2] == 'u' && av[i][3] == 'm') && i + 1 == ac)
			return (84);
		else if (av[i][0] != '-') {
			for (;av[i][j] != '\0'; j++);
			for (;av[i][j] != '.' && j > 0; j--);
			c = my_if(av, j, i, c);
			j = 0;
		}
	}
	return (c);
}

void verif_win(corewar_t *structure)
{
	static int winner = 0;
	int dead = 0;
	int live = 0;

	for (int e = 0; e < structure->number_champ; e++) {
		if (structure->champ_live[e] < 1) {
			dead++;
		}
		if (structure->champ_live[e] >= 1) {
			live++;
			winner = e;
		}
	}
	if (live <= 1) {
		structure->win = 0;
		my_putstr("champion ");
		my_put_nbr(winner);
		my_putstr(" won\n");
	}
}

void op_and_read_verif(int rd, int fd)
{
	if (rd < 0 || fd < 0) {
		exit(EXIT_FAILURE);
	}
}
